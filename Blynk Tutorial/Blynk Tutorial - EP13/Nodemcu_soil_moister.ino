/* راه اندازی سنسور رطوبت خاک
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/R12p2h
*/
//آماده سازی کتابخانه های مورد نیاز
#define BLYNK_PRINT Serial
#include "ESP8266WiFi.h"
#include "BlynkSimpleEsp8266.h"

// محل قرار گیری کد حویت در ماژول
char auth[] = "YourAuthToken";


// اطلاعات وای فای به همراه آدرس سرور برای اتصال ماژول
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
char server[] = "YourServerIP";

// مشخص کردن پین اندازه گیری برای سنسور
int sensor_pin = A0; 

//پین هایی که برای اتصال به آردینو نیاز است
int output_value ; 
#define connectionLED 5
BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
 // Blynk.begin(auth, ssid, pass, server); // کسانی که از سرور 29 و قبل استفاده می کنند
  Blynk.begin(auth, ssid, pass, server,8080); // کسانی که از سرور 30 و به بعد استفاده می کنند
  timer.setInterval(1000L, soil); // چکاب تابع به میزان مدت زمان تعیین شده
  pinMode(connectionLED,OUTPUT);
}

void loop()
{
  checkConnection();
  Blynk.run();
  timer.run();
  
}
//تابع اندازه گیری رطوبت
void soil() {
output_value= analogRead(sensor_pin);
  output_value = map(output_value,1024,400,0,100); //برابر گذاری مقادیر
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println("%");
  Blynk.virtualWrite(1,output_value);
}

void checkConnection() {
  if (! Blynk.connected()) {
    digitalWrite(connectionLED, LOW);
    Blynk.connect();
  }
  else {
    digitalWrite(connectionLED, HIGH);
  }
}



