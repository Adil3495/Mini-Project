#include <SoftwareSerial.h>  
#include <stdlib.h>
 
int sensor = 0;
String apiKey = "QKV1OV6BV0FLSN8D";

SoftwareSerial ser_mon(10, 11);//connect 10 to Tx and 11 to Rx of esp8366
void setup() {
  
  Serial.begin(115200);//Baud rate
  ser_mon.begin(115200);
  ser_mon.println("AT+RST");//Reset module
  ser_mon.println("AT+CWMODE=3");//Enables the module to act as both "Station" and an "Access Point"
  ser_mon.println("AT+CWJAP=\"<SSID>\",\"<password\"");//Wifi access point
}
void loop(){
//reading 10 values from LM35 to get average
int val = 0;
for(int i = 0; i < 10; i++) {
   val += analogRead(sensor);
  delay(250); 
}
//converting to degree celsius
float temp = val*50.0f/1023.0f;
char buf_temp[16];
 String strTemp = dtostrf(temp, 4, 1, buf_temp); 
Serial.println(strTemp); 
String cmd = "AT+CIPSTART=\"TCP\",\"";
cmd += "184.106.153.149"; // api.thingspeak.com
 cmd += "\",80";
 ser_mon.println(cmd);
if(ser_mon.find("Error")){
  Serial.println("AT+CIPSTART error");
  return; 
}
 // prepare GET string
String getStr = "GET /update?api_key=";
getStr += apiKey; 
getStr +="&field1="; 
getStr += String(strTemp);
getStr += "\r\n\r\n";

 // send data length    
cmd = "AT+CIPSEND=";    
cmd += String(getStr.length());    
ser_mon.println(cmd); 
  if(ser_mon.find(">")){     
 ser_mon.print(getStr);    
} 
 else{      
ser_mon.println("AT+CIPCLOSE");            
Serial.println("AT+CIPCLOSE");    
}
// thingspeak needs 15 sec delay between updates    
delay(16000);

}

