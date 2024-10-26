#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
#include <LiquidCrystal.h>
const int rs =8, en =9, d4 =10, d5 =11, d6 =12, d7 =13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int led=5;
int vval;
#define relay A0
void setup()
{
  mySerial.begin(9600);
   Serial.begin(9600);
   Wire.begin();
   pinMode(relay,OUTPUT);
   digitalWrite(relay,1);
   pinMode(led,OUTPUT);
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);
  // For Wemos / Lolin D1 Mini Pro and the Ambient Light shield use Wire.begin(D2, D1);
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
//  accel.begin();
  lcd.begin(16, 2);  
  lcd.print("  WELCOME");
  lcd.setCursor(0,1);
  lcd.print("INITIALIZING");
  delay(1000);
  lcd.clear();
  lcd.print("INITIALIZED");
  
}
void loop()
{  
  int  vval=read_voltage();
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Light: "+ String(lux));
 lcd.setCursor(0,1);
 lcd.print("VOL:"+String(vval));
  delay(500);
 if(lux<1000)
 {
  digitalWrite(led,HIGH);
  digitalWrite(relay,LOW);
 }
 else
 {
  digitalWrite(led,LOW);
  digitalWrite(relay,HIGH);
 }
 if(vval<100)
 {
  send_sms(1);
 }
}
int read_voltage()
{
int voltage;
double sensorValue1 = 0;
double sensorValue2 = 0;
int crosscount = 0;
int climb_flag = 0;
int val[100];
int max_v = 0;
double VmaxD = 0;
double VeffD = 0;
double Veff = 0;
  
   for ( int i = 0; i < 100; i++ ) {
    sensorValue1 = analogRead(A3);
    if (analogRead(A1) > 511) {
      val[i] = sensorValue1;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }

  if(Veff<85)
  Veff=85;
voltage=Veff-85;
VmaxD = 0;
return voltage;
}
  void send_sms(int k)
  {
   //read_gps();
    
mySerial.println("Sending SMS...");
mySerial.println("AT");    
delay(1000);  
mySerial.println("ATE0");    
delay(1000);  
mySerial.println("AT+CMGF=1");    
delay(1000);  
mySerial.print("AT+CMGS=\"8499940254\"\r\n");
delay(1000);
if(k==1)
mySerial.print("STREET LIGHT FAULT DETECTED AT KOVVADA ARCH");
delay(500);
mySerial.print(char(26));
delay(2000); 
  }
