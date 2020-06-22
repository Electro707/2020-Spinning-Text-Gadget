#include <Servo.h>
#include <LiquidCrystal.h>

#define TIMER2_COUNTS 1
#define LCD_COUNTS 200

#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 10
#define LCD_D5 11
#define LCD_D6 12
#define LCD_D7 13

#define LED_PIN PD3
#define SERVO_PIN A0
//#define SERVO_PIN PC0

#define LCD_PRINT_AND_CLEAR(_DATA) lcd.clear(); lcd.print(_DATA);
#define LCD_PRINT_ON_NL(_DATA) lcd.setCursor(0, 1); lcd.print(_DATA);

Servo myservo;
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int servo_angle;
int servo_dir;
int tim2_counter;
int lcd_counter;
int lcd_state;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  myservo.attach(SERVO_PIN);
  myservo.write(90);
  lcd.begin(16, 2);
  lcd.clear();
  
  servo_angle = 0;
  tim2_counter = 0;
  lcd_counter = -1;
  lcd_state = 0;
  servo_dir = 0;

  // Set up update timer
  TCCR2B = 0b111; // Set divider to CLK/1024
  TIMSK2 = 0x01; // Set time interrupt
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

ISR(TIMER2_OVF_vect){
  //tim2_counter++;
  //if(tim2_counter == TIMER2_COUNTS){
   // tim2_counter = 0;
    
    if(servo_dir == 0){
      servo_angle++;
      if(servo_angle >= 140+20){
        servo_dir = 1;
      }
    }
    else{
      servo_angle--;
      if(servo_angle <= 5-20){
        servo_dir = 0;
      }
    }
    if(servo_angle > 5 && servo_angle < 140){
      myservo.write(servo_angle);
    }
  //}
  
  lcd_counter++;
  if(lcd_counter == LCD_COUNTS){
    lcd_counter = 0;
    
    lcd_state++;
    switch(lcd_state){
      case 0:
        LCD_PRINT_AND_CLEAR("Congratulations");
        LCD_PRINT_ON_NL("Class of 2020!");
        break;
      case 1:
        LCD_PRINT_AND_CLEAR("You survived !");
        break;
      case 2:
        LCD_PRINT_AND_CLEAR("Have a wonderful");
        LCD_PRINT_ON_NL("Summer!");
        lcd_state = -1;
        break;
    }
  }
}
  
