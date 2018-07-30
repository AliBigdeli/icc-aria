/*  سنسور دما و رطوبت
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/ZeVpNs
*/
//آماده سازی و اضافه کردن کتابخانه های مربوط به پلتفرم
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// محل قرار گیری کد حویت در ماژول
char auth[] = "YourAuthToken";


// اطلاعات وای فای به همراه آدرس سرور برای اتصال ماژول
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
char server[] = "YourServerIP";

//defining the preneeds
#define DHTPIN 4       //   D2
#define DHTTYPE DHT11   // DHT 22, AM2302, AM2321//  
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void setup()
{
  // راه اندازی کنسول دیباگ برای خطایابی
  Serial.begin(115200);
  // راه اندازی اتصالات با استفاده از اطلاعات داده شده از قبل
  // در صورت وارد نکردن آدرس سرور به صورت پیشفرض به اینترنت متصل می شود
  Blynk.begin(auth, ssid, pass,server);
// Blynk.begin(auth, ssid, pass,server,8080);// برای کسانی که از سرور نسخه 0.30 به بالا استفاده می کنند
 
}

void loop()
{
  //راه اندازی ماژول و اتصال دائم به سرور و تبادل اطلاعات
  Blynk.run();
  temp_hu();
}
void temp_hu() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("humidity is: ");
  Serial.print(h);
  Serial.println("temp is: ");
  Serial.print(t);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, t);
  delay(1000);
/*
  if (h > 50) {
    Blynk.notify(String("Humidity has reached: ") + h + String("%"));
  }

  if (t > 27) {
    Blynk.notify(String("Temp has reached: ") + t + String("%"));
  }
*/
}
