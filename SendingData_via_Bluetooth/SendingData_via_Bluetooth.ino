String data = "";  
//int led1 = 9;
//int led2 = 10;
int led3 = 11;

void setup()   
{  
    Serial.begin(9600);  
//    pinMode(led1, OUTPUT);
//    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}  
  
void loop()   
{  
    Serial.println("Enter the data for tranfer - ");  
    while (Serial.available() == 0){}  
    data = Serial.readString();
    Serial.println("-------------------------");
    Serial.println("Data To Be Transferred:" + data);    
    for(int i=0; i<data.length() - 1; i++){
        char myChar = data.charAt(i);
        for(int i=7; i>=0; i--){
            byte bytes = bitRead(myChar,i);
            Serial.print(bytes, BIN);
            Serial.println("");
            if(bytes == 0){
//                analogWrite(led1, 127);
//                analogWrite(led2, 127);
                analogWrite(led3, 80);
                delay(10);
//                analogWrite(led1, 0);
//                analogWrite(led2, 0);
                analogWrite(led3, 0);
            } else{
//                analogWrite(led1, 255);
//                analogWrite(led2, 255);
                analogWrite(led3, 255);
                delay(10);
//                analogWrite(led1, 0);
//                analogWrite(led2, 0);
                analogWrite(led3, 0);
                
            }
//            digitalWrite(led, bytes);
//            delay(1000);
        }
        Serial.println("");
        Serial.println("");
    }
}
