#include "mgos_Adafruit_SHT31.h" 

Adafruit_SHT31 *mgos_Adafruit_SHT_create(); {
  return new Adafruit_SHT31();
}

void mgos_SHT31_close(Adafruit_SHT31 *SHT) {
  if (SHT != nullptr) {
    delete SHT;
    SHT = nullptr;
  }
}

bool mgos_Adafruit_SHT31_begin(Adafruit_SHT31 *SHT, int i2caddr) {
if (SHT == nullptr) return 0;
  return SHT->begin(i2caddr);
}

double mgos_SHT31_readTemperature(Adafruit_SHT31 *SHT)
{
	if (SHT == nullptr) return 0;
    return SHT -> readTemperature();
}
double mgos_SHT31_readHumidity (Adafruit_SHT31 *SHT)
{
	if (SHT == nullptr) return 0;
    return SHT -> readHumidity();
}