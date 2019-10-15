#define LED_PIN 8 //定義LED PIN為8

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);//設定PIN 8為輸出模式
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);//PIN 8輸出為HIGH,LED點亮
  delay(500);//延時500ms
  digitalWrite(LED_PIN, LOW);//PIN 8輸出為LOW,LED熄滅
  delay(500);//延時500ms
}
