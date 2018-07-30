/*  پروژه اتصال آردینو از طریق کابل USB به Blynk
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/1ofUaG
*/
//آماده سازی پیش نیازها و کتابخانه های دیباگ و سریال
#define BLYNK_PRINT DebugSerial
#include "SoftwareSerial.h"
#include "BlynkSimpleStream.h"

// مشخص کردن پین های ارتباطی با آردینو
SoftwareSerial DebugSerial(2, 3);



// محل قرار دادن کد تایید حویت
char auth[] = "YourAuthToken";


void setup()
{
  //آماده سازی کنسول دیباگ یا رفع اشکال
  DebugSerial.begin(9600);
  //شروع سریال و خروجی ها در سرعت مشخص شده
  Serial.begin(9600);
  //کد اتصال به سرور بلینک که در اینجا سریال و تایید حویت قرار می گیرد
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
}

