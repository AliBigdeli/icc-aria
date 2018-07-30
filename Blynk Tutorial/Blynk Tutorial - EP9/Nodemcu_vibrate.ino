/*  راه اندازی سنسور لرزش
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/5JGNrx
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

#define vibPin 13 //تعیین پایه ورودی 

void setup()
{
  // راه اندازی کنسول دیباگ برای خطایابی
  Serial.begin(115200);
  // راه اندازی اتصالات با استفاده از اطلاعات داده شده از قبل
  // در صورت وارد نکردن آدرس سرور به صورت پیشفرض به اینترنت متصل می شود
  Blynk.begin(auth, ssid, pass,server);
// Blynk.begin(auth, ssid, pass,server,8080);// برای کسانی که از سرور نسخه 0.30 به بالا استفاده می کنند
  pinMode(vibPin,INPUT); //آماده سازی پایه مورد نظر به عنوان ورودی
 
}

void loop()
{
  //راه اندازی ماژول و اتصال دائم به سرور و تبادل اطلاعات
  Blynk.run();
  vib_sens();  
}
long TP_init(){
  delay(10);
  long measurement=pulseIn (vibPin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}

void vib_sens() {
  long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
  Blynk.virtualWrite(V1,measurement);
  delay(30);
}

