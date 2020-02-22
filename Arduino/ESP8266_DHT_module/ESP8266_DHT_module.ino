//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
#include <DHT.h>

//Access point credentials
const char* ssid = "";
const char* pwd = "";
const String host = "http://";//輸入ip
DHT dht(2,DHT11);
WiFiServer server(80);  // open port 80 for server connection
 
void setup() 
{
  dht.begin();
  Serial.begin(115200); //initialise the serial communication
  delay(20);
  WiFi.begin(ssid, pwd);
  //starting the server
  server.begin();
}
 
void loop()
{
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  set_DHT_status(temp,humi);
} 
void set_DHT_status(float val,float val2)
{
  WiFiClient client = server.available();
  HTTPClient http;
  String url = host+"/animal_center/update_temp_humi.php?temp="+String(val)+"&humi="+String(val2);
  http.begin(url);
  //GET method
  int httpCode = http.GET();
  http.end();
  delay(1200000); //20 MINUTES
}
