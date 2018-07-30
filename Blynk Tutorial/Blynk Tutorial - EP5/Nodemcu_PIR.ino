/* پروژه ساخت دزدیگر با سنسور تشخیص حرکت
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/8xXDB8
*/
//آماده سازی و اضافه کردن کتابخانه های مربوط به پلتفرم
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// محل قرار گیری کد حویت در ماژول
char auth[] = "YourAuthToken";


// اطلاعات وای فای به همراه آدرس سرور برای اتصال ماژول
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
char server[] = "YourServerIP";

#define pirPin 2
int pirValue;
BlynkTimer timer;

//تابع تشخیص تغییر در سنسور تشخیص حرکت
void getPirValue()
{
  pirVaue = digitalRead(pirPin); // خواندن مقدار از پایه مشخص شده
  if(value == HIGH){ //اگر مقدار ورودی 1 یا مثبت بود
  Blynk.virtualWrite(1,"motion detected"); // چاپ کردن مقدار خروجی در صفحه گوشی
  }
  else{ // در غیر اینصورت
  Blynk.virtualWrite(1,"Normal");
  }
}

void setup()
{
  // راه اندازی کنسول دیباگ برای خطایابی
  Serial.begin(115200);
  // راه اندازی اتصالات با استفاده از اطلاعات داده شده از قبل
  // در صورت وارد نکردن آدرس سرور به صورت پیشفرض به اینترنت متصل می شود
  Blynk.begin(auth, ssid, pass,server);
// Blynk.begin(auth, ssid, pass,server,8080);// برای کسانی که از سرور نسخه 0.30 به بالا استفاده می کنند
  pinmode(pirPin,INPUT); // فعال سازی پایه به عنوان دریافت کننده یا ورودی
  timer,setInterval(1000L,getPirValue);
}

void loop()
{
  //راه اندازی ماژول و اتصال دائم به سرور و تبادل اطلاعات
  Blynk.run();
}