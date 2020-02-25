# IoT_AU_Project
亞洲大學動物中心溫濕度感測之物聯網專題
# Introduction
本次專案將溫濕度感測器連結Arduino、ESP8266，對固定IP的伺服器傳送動物中心當前的「溫度」、「濕度」。並且利用React-Native，同時開發Android、IOS的APP。APP將可以即時取得動物中心的溫濕度、查看歷史溫濕度資料，以及即時推播溫濕度異常之訊息提醒使用者。
當固定IP接收到資料，將會更新MySQL資料庫中的最新溫濕度，以及儲存於歷史資料中。
