

#include <LiquidCrystal.h>

int seconds = 0;
int const LED_RED =13;
int const FAN1 =9;
int sensor_value;
float temperature;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(FAN1, OUTPUT);
  Serial.begin(9600);
  
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
 
  // Print a message to the LCD.
  
}

void loop()
{
 sensor_value=analogRead(A0); 
  Serial.println("sensor value: ");
  Serial.println(sensor_value);
  delay(2000);
  temperature=(sensor_value * (500.0 / 1023.0))-50.0;
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("C");
  
  digitalWrite(LED_RED, LOW);
  digitalWrite(FAN1,LOW);
  
  if (temperature <= 10){
    lcd_1.display();
    lcd_1.print("Temperatura: ");
    lcd_1.setCursor(0, 1);
    lcd_1.print(temperature);
    delay(500);
    lcd_1.clear();
    delay(500);
    
  
  }
  else if (temperature > 10 && temperature <= 25){
    
   lcd_1.noDisplay();             // Apaga la pantalla LCD
   digitalWrite(10, LOW);  // Apaga el motor
  delay(500);
  }
  else{
    
  lcd_1.display();
     lcd_1.print("Temperatura: ");
    lcd_1.setCursor(0, 1);
    lcd_1.print(temperature);
    delay(500);	  
  digitalWrite(10, HIGH); // Enciende motor
    delay(1000);
  
  }
  
  
 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):

  // print the number of seconds since reset:
  
   // Wait for 1000 millisecond(s)
 
  
  
  
}