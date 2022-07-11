

#include <dht.h> //download library here: 
//https://www.arduino.cc/reference/en/libraries/dhtlib/
//download the latest version, 0.1.35

#include <LiquidCrystal.h> //LCD library

LiquidCrystal LCD(2,3,4,5,6,7); 

dht DHT; //Instance of DHT library

#define DHT11_PIN A0 //Temp/Humidity is analog, use correct pin

void setup(){
  //set up LCD and Serial port
  Serial.begin(9600);
  LCD.begin(16,2);
  
}

void loop(){
  //DHT11 Sensor is used
  int chk = DHT.read11(DHT11_PIN);
  
  Serial.print("Temperature = ");
  double temp = DHT.temperature; //In degC
  
  temp = (((temp*9)/5)+32); //convert to F because America
  Serial.println(temp);     //display Temp in Serial monitor
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);//out of 100%
  delay(1000);

  //display temp/humidity on LCD

  LCD.setCursor(0,0);
  LCD.print("Temp: ");
  LCD.print(temp);
  LCD.setCursor(0,1);
  LCD.print("Humidity: ");
  LCD.print(DHT.humidity);
}
