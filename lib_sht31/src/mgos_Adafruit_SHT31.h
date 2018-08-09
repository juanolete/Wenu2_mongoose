#include "Adafruit_SHT31.h"

#ifdef __cplusplus
extern "C"
{
#endif

Adafruit_SHT31 *mgos_Adafruit_SHT_create();

void mgos_SHT31_close(Adafruit_SHT31 *SHT);

bool mgos_Adafruit_SHT31_begin(Adafruit_SHT31 *SHT, int i2caddr);

double mgos_SHT31_readTemperature(Adafruit_SHT31 *SHT);

double mgos_SHT31_readHumidity (Adafruit_SHT31 *SHT);

#ifdef __cplusplus
}
#endif  /* __cplusplus */