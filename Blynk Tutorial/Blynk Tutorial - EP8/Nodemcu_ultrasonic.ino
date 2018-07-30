/*  ultrasonic project
 *  کنترل ارتباطات هوشمند آریا
 *  آموزش های برنامه نویسی در حوزه هوشمند سازی iot و همچنین مباحث هوش مصنوعی 
 *  همچنین فروشگاهی از تجهیزات بروز توسعه علمی و هوشمند سازی 
 *  
 *  site: www.icc-aria.ir
 *  telegram: http://t.me/icc_aria 
 *  instagram: http://instagram.com/icc_aria
 *  soroush: http://sapp.ir/icc_aria
 *  webpage: https://goo.gl/W6VjEn
*/

//آماده سازی و اضافه کردن کتابخانه های مربوط به پلتفرم
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// محل قرار گیری کد حویت در ماژول
char auth[] = "YourAuthToken";

//defining the preneeds
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;


// اطلاعات وای فای به همراه آدرس سرور برای اتصال ماژول
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
char server[] = "YourServerIP";

void setup()
{
  // راه اندازی کنسول دیباگ برای خطایابی
  Serial.begin(115200);
  // راه اندازی اتصالات با استفاده از اطلاعات داده شده از قبل
  // در صورت وارد نکردن آدرس سرور به صورت پیشفرض به اینترنت متصل می شود
  Blynk.begin(auth, ssid, pass,server);
// Blynk.begin(auth, ssid, pass,server,8080);// برای کسانی که از سرور نسخه 0.30 به بالا استفاده می کنند
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
}

void loop()
{
  //راه اندازی ماژول و اتصال دائم به سرور و تبادل اطلاعات
  Blynk.run();
  ultra_sens();
}
void ultra_sens() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Blynk.virtualWrite(1, distance);
  delay(500);
}

