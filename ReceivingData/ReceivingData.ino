#include <LiquidCrystal.h>
const int rs = 12,en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const long int sensorPin=A0;
int sensorValue=0;
String data="";
String answer="";
int val=0;
int count=0;
int thres=0;
# define thres 16300

int binaryASCII(String s){
    int ans=0;
    for(int i=0;i<=7;i++){
        ans+=s[i]-48;
        ans*=2;
    }
    return ans/2;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  sensorValue=analogRead(sensorPin);  // Reading the sensor value
  sensorValue*=100;                   // Multiplying by 100 to get a bigger range
//  Serial.println(sensorValue);
  delay(100);
  if(sensorValue > thres){              // Starts when first High value detected
    lcd.setCursor(0,0);
    while(1){
      val = analogRead(sensorPin);
      val *=100;
      if(val > thres){
        data += '1';                  // Taking the binary input
        delay(100);
      } else{
        data += '0';
        delay(100);
      };
      if(data.length()==8){   // Checking the length
        int Data=binaryASCII(data);   // Converting binary from string to int then to decimal
        answer=answer+(char)(Data);   // Converting from decimal to string
        lcd.print(answer);            // Printing in LCD
        Serial.print((char)Data);     // Printing in Serial Monitor
        data="";                      // Resetting the string to null
        break;                        // Breaking the while loop
      }
    }
   }
}
