//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
 
//Access point credentials
const char* ssid = "Pixel_2039";
const char* pwd = "00000000";
const char* host = "http://120.108.111.85";
String get_host = "http://120.108.111.85";
int gpio_0 = 0;
int gpio_1 = 0;
int into = 0;
int out = 0;
int total_num = 0;
WiFiServer server(80);  // open port 80 for server connection
 
void setup() 
{
  Serial.begin(115200); //initialise the serial communication
  delay(20);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  WiFi.begin(ssid, pwd);
 
   
  //starting the server
  server.begin();
  set_device_status("num",total_num);//初始化人數
}
 
void loop()
{
  //進出門增減人數
  into = digitalRead(2);
  out = digitalRead(3);
  get_device_status("Homemode_state",1);
  if(into==1){
    total_num+=1;
    set_device_status("num",total_num);
  }else if(out==1){
    total_num-=1;
    set_device_status("num",total_num);
  }
  //
  
  //開啟WebServer藉網頁控制LED
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  while(!client.available()){
    delay(1);
  }
  String req = client.readStringUntil('\r');
  client.flush();
  if(req.indexOf("/gpio_0/0") != -1){
    gpio_0 = 0;
  }else if (req.indexOf("/gpio_0/1") != -1){
    gpio_0 = 1;
  }else if (req.indexOf("/gpio_1/0") != -1){
    gpio_1 = 0;
  }else if (req.indexOf("/gpio_1/1") != -1){
    gpio_1 = 1;
  }else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  digitalWrite(0, gpio_0);
  digitalWrite(1, gpio_1);
  client.flush();
  String s = "HTTP/1.1 200 OK";
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
  //
} 
void set_device_status(String device_name,int num)
  {
        WiFiClient client = server.available();
        HTTPClient http;
        String url = get_host+"/~Iot/Arduino_upload.php?"+device_name+"="+String(num);
        http.begin(url);
        //GET method
        int httpCode = http.GET();
        http.end();
        delay(1000);
  }
void get_device_status(String device_name,int gpio)
  {
        WiFiClient client = server.available();
        HTTPClient http;
        String url = get_host+"/~Iot/Arduino_state.php?device="+device_name;
        http.begin(url);
        //GET method
        int httpCode = http.GET();
        delay(100);
        String str = http.getString();
        if(str=="1")
        {
          digitalWrite(gpio,HIGH);
        }
        else
        {
          digitalWrite(gpio,LOW);
        }
        http.end();
        delay(300);
  }
