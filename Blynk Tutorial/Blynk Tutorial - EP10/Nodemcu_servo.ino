/*  پروژه راه اندازی Servo motor
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/Xkh5sG
*/
//آماده سازی و اضافه کردن کتابخانه های مربوط به پلتفرم
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
// محل قرار گیری کد حویت در ماژول
char auth[] = "YourAuthToken";


// اطلاعات وای فای به همراه آدرس سرور برای اتصال ماژول
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
char server[] = "YourServerIP";

Servo servo;


BLYNK_WRITE(V1) {
 servo.write(param.asInt());
}
void setup()
{
  // راه اندازی کنسول دیباگ برای خطایابی
  Serial.begin(115200);
  // راه اندازی اتصالات با استفاده از اطلاعات داده شده از قبل
  // در صورت وارد نکردن آدرس سرور به صورت پیشفرض به اینترنت متصل می شود
  Blynk.begin(auth, ssid, pass,server);
// Blynk.begin(auth, ssid, pass,server,8080);// برای کسانی که از سرور نسخه 0.30 به بالا استفاده می کنند
  servo.attach(15); // 15 means D8 pin of ESP8266
}

void loop()
{
  //راه اندازی ماژول و اتصال دائم به سرور و تبادل اطلاعات
  Blynk.run();
}