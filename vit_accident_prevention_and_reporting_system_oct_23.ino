#include <LiquidCrystal.h>
const int rs =8, en =9, d4 =10, d5 =11, d6 =12, d7 =13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pingPin =A5; // Trigger Pin of Ultrasonic Sensor
const int echoPin =A4; // Echo Pin of Ultrasonic Sensor
long duration;
int distance;
#include "DHT.h"
#define DHTPIN A0 
#define DHTTYPE DHT11 
DHT dht(DHTPIN,DHTTYPE);
#define alc A2 
#define stb  3   // connect normal push button (it acts as a start button)
#define motor 4
#define motor1 5
#define motor2 6
#define motor3 7
#define bz 2
#define hst A1
int ebs=A3;
int i=0;
#include <TinyGPS.h>
TinyGPS gps;
float flat=0, flon=0;
int gval=0;
void read_gps()
{
    bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available())
    {
      char c = Serial.read();
      if (gps.encode(c)) 
        newData = true;
    }
  }

  if (newData)
  {

    unsigned long age;
    gps.f_get_position(&flat,&flon,&age);

  }
}
int aval;
void setup()
{ 
  lcd.begin(16,2);
  Serial.begin(9600);
   dht.begin();
  pinMode(pingPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);  
  lcd.print("  WELCOME");
  lcd.setCursor(0,1);
  lcd.print("INITIALIZING");
  do
  {
  aval=analogRead(alc);
   lcd.setCursor(13,1);
  lcd.print("    ");
  lcd.setCursor(13,1);
  lcd.print(aval); 
  }while(aval>750);
  lcd.clear();
  pinMode(ebs,INPUT);
  pinMode(stb,INPUT_PULLUP);
  pinMode(bz,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(alc,INPUT);  
  pinMode(hst,INPUT_PULLUP);
 digitalWrite(motor,1);
digitalWrite(motor1,0);
digitalWrite(motor2,1);
digitalWrite(motor3,0); 
 // digitalWrite(bz,0);
 // digitalWrite(motor,0);
}
void loop()
{  
 lcd.clear();
int gval=analogRead(alc);
int ebval=digitalRead(ebs);
int t = dht.readTemperature();
int h=dht.readHumidity();   
 digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("A:" + String(gval) + " D:"+ String(distance) + " T:" + String(t));
 lcd.setCursor(0,1);
 lcd.print("H:" + String(hst) + " E:"+ String(ebval) + " C:" + String(i));  
if(ebval==1)
    {
      i++;
    }
    else
    {
      i=0;
    }

    delay(100);
    if(i==2)
    {
    digitalWrite(bz,1);
    delay(300);
    digitalWrite(bz,0);
    }

    if(i==3)
    {
     digitalWrite(bz,1);
     delay(300);
    digitalWrite(bz,0);
    }
   if(i>4)
    {
    digitalWrite(bz,1);
    digitalWrite(motor,0);
    digitalWrite(motor1,0);
    digitalWrite(motor2,0);
    digitalWrite(motor3,0);
    lcd.clear();
    lcd.print("DRIVER SLEEPING");
 Serial.println("https://www.google.com/maps/search/?api=1&query=" + String(16.4963)+ "," + String(80.5007) +"^0");
    digitalWrite(bz,0);
   // while(1);
    } 
   if(distance<20)
   {
    digitalWrite(bz,1);
    delay(1000);
    digitalWrite(bz,0);
   }
    if(gval>500)
      {
      lcd.clear();
      lcd.print("Driver alcoholic ");
      lcd.setCursor(0,1);
      lcd.print("VEHICLE STOPPED");
      digitalWrite(bz,1);
      digitalWrite(motor,0);
      digitalWrite(motor1,0);
      digitalWrite(motor2,0);
      digitalWrite(motor3,0);
      Serial.println("https://www.google.com/maps/search/?api=1&query=" + String(16.4963)+ "," + String(80.5007) +"^0");
    //  while(1);
}
if(digitalRead(hst)==0)
{
      lcd.clear();
      lcd.print("Accident occured");
        digitalWrite(bz,1);
      digitalWrite(motor,0);
      digitalWrite(motor1,0);
      digitalWrite(motor2,0);
      digitalWrite(motor3,0);
 Serial.println("https://www.google.com/maps/search/?api=1&query=" + String(16.4963)+ "," + String(80.5007) +"^0");
     // while(1); 
  }
}
