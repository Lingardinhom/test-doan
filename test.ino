#include <WiFi.h>
#include <WebServer.h>
#include <EEPROM.h>
#include "html1.h"
WebServer webserver(80);
//NHIỆT ĐỘ VÀ ĐỘ ẨM========//
#include <DHT.h>
#define chandht 25
#define loaidht DHT11
DHT dht(chandht,loaidht);

float nhietdo;
float doam;
//==========AP info=======================//
char* ssid_ap = "Nha kinh";
char* pass_ap = "12345678";
IPAddress ip_ap(192,168,4,1);
IPAddress gateway_ap(192,168,4,1);
IPAddress subnet_ap(255,255,255,0);
String statusD1="1",statusD2="1",statusD3="1",statusD4="1";
String ssid;
String pass;
// Assign output variables to GPIO pins

//=========Biến chứa mã HTLM Website==//

//=========================================//
void setup() {
#define D1  2
  #define D2  4
#define D3  5
#define D4  12
  Serial.begin(115200);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  pinMode(chandht,INPUT);
    dht.begin();
  
  EEPROM.begin(512);       //Khởi tạo bộ nhớ EEPROM
  delay(10);
  
  if(read_EEPROM()){
    checkConnection();
  }else{
    WiFi.disconnect();
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip_ap, gateway_ap, subnet_ap);
    WiFi.softAP(ssid_ap,pass_ap,1,false);
    Serial.println("Soft Access Point mode!");
    Serial.print("Please connect to");
    Serial.println(ssid_ap);
    Serial.print("Web Server IP Address: ");
    Serial.println(ip_ap);
  }
  webserver.on("/",mainpage);
  webserver.on("/docnhietdo",docdulieunhietdo);
  webserver.on("/docdoam",docdulieudoam);
  webserver.on("/getSTATUSD",get_STATUSD);
  webserver.on("/D1on",D1_on);
  webserver.on("/D1off",D1_off);
  webserver.on("/D2on",D2_on);
  webserver.on("/D2off",D2_off);
  webserver.on("/D3on",D3_on);
  webserver.on("/D3off",D3_off);
  webserver.on("/D4on",D4_on);
  webserver.on("/D4off",D4_off);
  webserver.on("/Allon",All_on);
  webserver.on("/Alloff",All_off);
  webserver.on("/getIP",get_IP);
  webserver.on("/writeEEPROM",write_EEPROM);
  webserver.on("/restartESP",restart_ESP);
  webserver.on("/clearEEPROM",clear_EEPROM);
   webserver.on("/tudong1",tudong);
  webserver.begin();
}
void loop() {
  webserver.handleClient();
}

//==========Chương trình con=================//
void mainpage(){
  String s = FPSTR(MainPage);
  webserver.send(200,"text/html",s);
}
void get_STATUSD(){
  if(digitalRead(D1)==0){
    statusD1 = "0";
  }else{
    statusD1 = "1";
  }
  if(digitalRead(D2)==0){
    statusD2 = "0";
  }else{
    statusD2 = "1";
  }
  if(digitalRead(D3)==0){
    statusD3 = "0";
  }else{
    statusD3 = "1";
  }
  if(digitalRead(D4)==0){
    statusD4 = "0";
  }else{
    statusD4 = "1";
  }
  String s = "{\"D1\": \""+ statusD1 +"\"," +
              "\"D2\": \""+ statusD2 + "\"," +
              "\"D3\": \""+ statusD3 + "\"," +
              "\"D4\": \""+ statusD4 +"\"}";
  webserver.send(200,"application/json",s);
}
//--------------Điều khiển chân D1----------------
void D1_on(){
  digitalWrite(D1,HIGH);
  get_STATUSD();
}
void D1_off(){
  digitalWrite(D1,LOW);
  get_STATUSD();
}
//--------------Điều khiển chân D2----------------
void D2_on(){
  digitalWrite(D2,HIGH);
  get_STATUSD();
}
void D2_off(){
  digitalWrite(D2,LOW);
  get_STATUSD();
}
//--------------Điều khiển chân D3----------------
void D3_on(){
  digitalWrite(D3,HIGH);
  get_STATUSD();
}
void D3_off(){
  digitalWrite(D3,LOW);
  get_STATUSD();
}
//--------------Điều khiển chân D4----------------
void D4_on(){
  digitalWrite(D4,HIGH);
  get_STATUSD();
}
void D4_off(){
  digitalWrite(D4,LOW);
  get_STATUSD();
}
//--------------Điều khiển chân D----------------
void All_off(){
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  get_STATUSD();
}
void All_on(){
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  get_STATUSD();
}

void get_IP(){
  String s = WiFi.localIP().toString();
  webserver.send(200,"text/html", s);
}
boolean read_EEPROM(){
  Serial.println("Reading EEPROM...");
  if(EEPROM.read(0)!=0){
    ssid = "";
    pass = "";
    for (int i=0; i<32; ++i){
      ssid += char(EEPROM.read(i));
    }
    Serial.print("SSID: ");
    Serial.println(ssid);
    for (int i=32; i<96; ++i){
      pass += char(EEPROM.read(i));
    }
    Serial.print("PASSWORD: ");
    Serial.println(pass);
    ssid = ssid.c_str();
    pass = pass.c_str();
    return true;
  }else{
    Serial.println("Data wifi not found!");
    return false;
  }
}
//---------------SETUP WIFI------------------------------
void checkConnection() {
  Serial.println();
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.print("Check connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid.c_str(),pass.c_str());
  int count=0;
  while(count < 50){
    if(WiFi.status() == WL_CONNECTED){
      Serial.println();
      Serial.print("Connected to ");
      Serial.println(ssid);
      Serial.print("Web Server IP Address: ");
      Serial.println(WiFi.localIP());
      return;
    }
    delay(200);
    Serial.print(".");
    count++;
  }
  Serial.println("Timed out.");
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip_ap, gateway_ap, subnet_ap);
  WiFi.softAP(ssid_ap,pass_ap,1,false);
  Serial.println("Soft Access Point mode!");
  Serial.print("Please connect to");
  Serial.println(ssid_ap);
  Serial.print("Web Server IP Address: ");
  Serial.println(ip_ap);
}
void write_EEPROM(){
  ssid = webserver.arg("ssid");
  pass = webserver.arg("pass");
  Serial.println("Clear EEPROM!");
  for (int i = 0; i < 96; ++i) {
    EEPROM.write(i, 0);           
    delay(10);
  }
  for (int i = 0; i < ssid.length(); ++i) {
    EEPROM.write(i, ssid[i]);
  }
  for (int i = 0; i < pass.length(); ++i) {
    EEPROM.write(32 + i, pass[i]);
  }
  EEPROM.commit();
  Serial.println("Writed to EEPROM!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("PASS: ");
  Serial.println(pass);
  String s = "Wifi configuration saved!";
  webserver.send(200, "text/html", s);
}
void restart_ESP(){
  ESP.restart();
}
void clear_EEPROM(){
  Serial.println("Clear EEPROM!");
  for (int i = 0; i < 512; ++i) {
    EEPROM.write(i, 0);           
    delay(10);
  }
  EEPROM.commit();
  String s = "Device has been reset!";
  webserver.send(200,"text/html", s);
}
//----------NHIET DO VA DO AM
void docdulieunhietdo(){
  nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo)){
    webserver.send(200,"text/plane","Cảm biến không hoạt động");
  }else{
    webserver.send(200,"text/plane",snhietdo);
  }
}

void docdulieudoam(){
  doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam)){
    webserver.send(200,"text/plane","Cảm biến không hoạt động");
  }else{
    webserver.send(200,"text/plane",sdoam);
  }
}
void tudong(){ 
  digitalWrite(D1,HIGH);
  get_STATUSD();
  delay (2000);
  
  
}
