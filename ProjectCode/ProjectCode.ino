
#include <LiquidCrystal.h> //LCD kütüphanesi
///Değişkenler 
int temp;
int T_Sensor = A3;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;  
int LDRpin=A2;
int isik;
int ledpin=8;
//int templed=6;
int levelpin=A4;
int seviye;
int levelpump=9;
int levelout=6;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    //moisture 
    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
    //pinMode(9,OUTPUT);
    //LCD
    lcd.setCursor(0,0);
    
    lcd.setCursor(0,1);
    
    delay(1000);
    ////LDR
    Serial.begin(9600); 
    pinMode(LDRpin,INPUT);
    pinMode(ledpin,OUTPUT);
    ///temp
    pinMode(T_Sensor,INPUT);
    //pinMode(templed,OUTPUT);
    ///level
    pinMode(levelpin,INPUT);
    //pinMode(levelpump,OUTPUT);
    //pinMode(levelout,OUTPUT);
}

void loop()
{
  ///LCD
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("SCKL:");
  lcd.setCursor(5,0);
  lcd.print(cel);
  lcd.setCursor(7,0);
  lcd.print("*C");
  ///NEM SENSÖRÜ
 
  int nem = analogRead(M_Sensor); //Nem Sensörü

 if (nem> 700)   //Kuru Toprak
  { 
        lcd.setCursor(11,0);
        lcd.print("KURU");
        lcd.setCursor(11,1);
        lcd.print("TOPR");
       
    }
 
     else if (nem > 300 && nem<=700) //Nemli Toprak
    { 
      lcd.setCursor(11,0);
     lcd.print("NEMLI");
     lcd.setCursor(11,1);
     lcd.print("TOPRAK");
         
    }
    else if (nem<=300) //Islak Toprak
    { 
      lcd.setCursor(11,0);
     lcd.print("ISLAK");
     lcd.setCursor(11,1);
     lcd.print("TOPRAK");
         
    }
    delay (1000);

 

  /////LDR
  isik = analogRead(LDRpin);
  Serial.print("ISIK = ");
  Serial.println(isik);
  if (isik>800){
  digitalWrite(ledpin,HIGH);
  delay(10);
  }
  else {
  digitalWrite(ledpin,LOW);
  delay(10);
  }
  //SICAKLIK SENSÖRÜ
  val = analogRead(T_Sensor); //Sıcaklık Sensörü 
  int mv = ( val/1024.0)*5000; 
  cel = mv/10;
  /////SIVI SEVİYESİ SENSÖRÜ 
 seviye=analogRead(levelpin);
  Serial.print("SU SEVIYESI: ");
  Serial.println(seviye);
  if (seviye<=200){
    Serial.println("UYARI! DEPO SEVIYESI DUSUK ");
    delay(5);}
    else if (seviye>200 && seviye<=500){
    Serial.println("UYARI! DEPO SEVIYESI RISKLI DURUMDA ");
    delay(5);}
    else if (seviye>500 && seviye<=800){
    Serial.println("DEPO SEVIYESI IYI DURUMDA ");
    delay(5);}
    else if (seviye>=800){
    Serial.println("DEPO SEVIYESI MUKEMMEL DURUMDA ");

    }
    
  }
  
  
    
  
