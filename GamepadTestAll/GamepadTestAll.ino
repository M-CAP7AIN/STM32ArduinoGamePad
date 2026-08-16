#include <Gamepad.h>

void setup()
{
  // مقداردهی اولیه نویز آنالوگ برای واقعی‌تر شدن اعداد رندوم
  randomSeed(analogRead(A0));

  gamepad.setPollingInterval(1);
  gamepad.begin();

  gamepad.releaseAllButtons();
  gamepad.setHat(8); // حالت خنثی Hat Switch
  gamepad.setAxes(0, 0, 0, 0, 0, 0);
  gamepad.sendReport();
}

void loop()
{
  // ۱. انتخاب رندوم یک دکمه از بین ۲۰ دکمه (۰ تا ۱۹)
  uint8_t randomButton = random(0, 20);
  gamepad.press(randomButton);

  // ۲. انتخاب رندوم D-Pad / Hat Switch (مقادیر ۰ تا ۷ جهت‌ها و ۸ حالت خاموش)
  uint8_t randomHat = random(0, 9);
  gamepad.setHat(randomHat);

  // ۳. مقداردهی رندوم به ۶ محور آنالوگ (محدوده استاندارد -32768 تا 32767)
  int16_t randomX  = random(-32768, 32767);
  int16_t randomY  = random(-32768, 32767);
  int16_t randomRx = random(-32768, 32767);
  int16_t randomRy = random(-32768, 32767);
  int16_t randomZ  = random(-32768, 32767);
  int16_t randomRz = random(-32768, 32767);

  gamepad.setX(randomX);
  gamepad.setY(randomY);
  gamepad.setRx(randomRx);
  gamepad.setRy(randomRy);
  gamepad.setZ(randomZ);
  gamepad.setRz(randomRz);

  // ارسال وضعیت فعال
  gamepad.sendReport();
  delay(150); // زمان فعال ماندن دکمه/محور

  // ۴. ریست کردن همه وضعیت‌ها به حالت پیش‌فرض (خاموش)
  gamepad.releaseAllButtons();
  gamepad.setHat(8);
  gamepad.setAxes(0, 0, 0, 0, 0, 0);

  // ارسال وضعیت غیرفعال
  gamepad.sendReport();
  delay(200); // فاصله تا تست رندوم بعدی
}