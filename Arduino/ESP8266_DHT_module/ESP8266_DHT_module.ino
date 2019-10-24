//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
#include <DHT.h>

//Access point credentials
const char* ssid = "Pixel_2039";
const char* pwd = "00000000";
const char* host = "http://";//輸入ip
String get_host = "http://";//輸入ip
int curtain_auto_pin = 1;
int curtain_motor_pin = 3;
int gpio_0 = 0;
DHT dht(2,DHT11);
WiFiServer server(80);  // open port 80 for server connection
 
void setup() 
{
  dht.begin();
  Serial.begin(115200); //initialise the serial communication
  delay(20);
  WiFi.begin(ssid, pwd);
  pinMode(curtain_auto_pin,OUTPUT);
  pinMode(curtain_motor_pin,OUTPUT);
   
  //starting the server
  server.begin();
}
 
void loop()
{
  //
    float temp = dht.readTemperature();
    float humi = dht.readHumidity();
    set_DHT_status(temp,humi);
    get_device_status("curtain_state",curtain_motor_pin);
    get_device_status("curtain_auto_state",curtain_auto_pin);
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
  if (req.indexOf("/gpio_0/0") != -1){
    gpio_0 = 0;
  }else if (req.indexOf("/gpio_0/1") != -1){
    gpio_0 = 1;
  
  }else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  client.flush();
  String s = "HTTP/1.1 200 OK";
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
  //
} 
void set_DHT_status(float val,float val2)
  {
        WiFiClient client = server.available();
        HTTPClient http;
        String url = get_host+"/~Iot/Arduino_update_temp_humi.php?temp="+String(val)+"&humi="+String(val2);
        http.begin(url);
        //GET method
        int httpCode = http.GET();
        http.end();
        delay(300);
  }
void get_device_status(String device_name,int gpio)
  {
        WiFiClient client = server.available();
        HTTPClient http;
        String url = get_host+"/~Iot/Arduino_curtain_state.php?device="+device_name;
        http.begin(url);
        //GET method
        int httpCode = http.GET();
        delay(100);
        String str = http.getString();
        if(str=="1")
        {
          digitalWrite(gpio,HIGH);
        }else if(str=="0")
        {
          digitalWrite(gpio,LOW);
        }
        http.end();
        delay(300);
  }
