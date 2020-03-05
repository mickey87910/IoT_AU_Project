//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> 
#include <DHT.h>

//Access point credentials
const char* ssid = "DHT_wifi";
const char* pwd = "";
const String host = "https://lac.asia.edu.tw";//輸入ip
const char* fingerprint ="93 AE 95 E0 4A 1F 4B 73 8F 81 DF 0B 9B 2C AF EC BB 5E 3B 6E";
DHT dht(2,DHT11);

void setup() 
{
  dht.begin();
  Serial.begin(115200); //initialise the serial communication
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println("successed");
}
 
void loop()
{
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  set_DHT_status(temp,humi);
} 
void set_DHT_status(float val,float val2)
{
  HTTPClient http;
  //http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String url = host+"/dht_php/update_temp_humi.php?temp="+String(val)+"&humi="+String(val2);
  Serial.println("REQUEST");
  Serial.println(url);
  http.begin(url,fingerprint);
  //GET method
  int httpCode = http.GET();
  Serial.println(httpCode);
  http.end();
  delay(1200000); //20 MINUTES
}
