//讀取感應器的接腳
int outside_sensor = 12;
int inside_sensor = 13;
//

//LED亮燈的接腳
int outside_LED = 8;
int inside_LED = 7;
//

//全域變數
int outside_val = 0;    
int inside_val = 0;
int pre_inside_val =0;
int pre_outside_val =0;
String result = "";
int RGB_val = 0;
//

//傳輸給ESP8266的接腳
int send_into = A0;
int send_out = A1;
//

//ESP8266傳輸給Arduino的接腳
int RGB_from_ESP = A2;
//

//RGB色溫燈的接腳及HomeMode顏色
#define LEDR 11
#define LEDG 10
#define LEDB 9
int r = 255;
int g = 255;
int b = 255;
//
void setup()
{
   Serial.begin(9600);    //設置傳輸鮑率為9600，這裡要跟軟體設置相一致
   pinMode(outside_sensor, INPUT);        //設定sensor接脚為輸入狀態
   pinMode(inside_sensor, INPUT); 
   pinMode(outside_LED,OUTPUT);
   pinMode(inside_LED,OUTPUT);
   pinMode(send_into,OUTPUT);
   pinMode(send_out,OUTPUT);
   pinMode(RGB_from_ESP,INPUT);
   pinMode(LEDR, OUTPUT);
   pinMode(LEDG, OUTPUT);
   pinMode(LEDB, OUTPUT);
}

void loop()
{
   inside_val = digitalRead(inside_sensor);    //讀傳感器信息
   outside_val = digitalRead(outside_sensor);
   RGB_val = digitalRead(RGB_from_ESP);
   Serial.println(RGB_val);
   result="";
   if(RGB_val == 1){
      analogWrite(LEDR,r);
      analogWrite(LEDG,g);
      analogWrite(LEDB,b);
   }else{
      analogWrite(LEDR,0);
      analogWrite(LEDG,0);
      analogWrite(LEDB,0);
   }
   if(inside_val== HIGH)
   {
    digitalWrite(inside_LED,HIGH);
    pre_inside_val = 1;
    Serial.println("內側有人經過");
    if(pre_outside_val == 1){
      Serial.println("入門"); 
      pre_outside_val = 0;
      pre_inside_val = 0;
      result="入門";
    }
   }
   else
   {
    digitalWrite(inside_LED,LOW);
    pre_inside_val = 0;
    Serial.println("內側無人或人靜止不動"); 
   }
   if( outside_val== HIGH)
   {
    digitalWrite(outside_LED,HIGH);
    pre_outside_val = 1;
    Serial.println("外側有人經過");
    if(pre_inside_val == 1){
      pre_inside_val = 0;
       pre_outside_val = 0;
       result="外出";
      Serial.println("外出");
    }
   }
   else
   {
    digitalWrite(outside_LED,LOW);
    pre_outside_val = 0;
    Serial.println("外側無人或人靜止不動"); 
   }
   if (result!=""){
      digitalWrite(outside_LED,LOW);
      digitalWrite(inside_LED,LOW);
      if(result == "入門"){
          digitalWrite(send_into,HIGH);
          delay(1);
          digitalWrite(send_into,LOW);
      }
      else if (result=="外出"){
          digitalWrite(send_out,HIGH);
          delay(1);
          digitalWrite(send_out,LOW);
      }
      pre_outside_val = 0;
      pre_inside_val = 0;
      delay(5000);
   }
   delay(1000);
}
