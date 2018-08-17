#include "ADE7953.h"

#ifdef __cplusplus
extern "C"
{
#endif

ADE7953 *mgos_ade7953_create();
void    mgos_ade7953_close(ADE7953 *ADE);
void    mgos_ade7953_initialize(ADE7953 *ADE);
double  mgos_ade7953_getPowerFactorA(ADE7953 *ADE);
double  mgos_ade7953_getPeriod(ADE7953 *ADE);
long    mgos_ade7953_getInstVoltage(ADE7953 *ADE);
double  mgos_ade7953_getVrms(ADE7953 *ADE);
long    mgos_ade7953_getInstCurrentA(ADE7953 *ADE);
double  mgos_ade7953_getIrmsA(ADE7953 *ADE);
long    mgos_ade7953_getVpeak(ADE7953 *ADE);
long    mgos_ade7953_getIpeakA(ADE7953 *ADE);
long    mgos_ade7953_getActiveEnergyA(ADE7953 *ADE);
long    mgos_ade7953_getReactiveEnergyA(ADE7953 *ADE);
long    mgos_ade7953_getApparentEnergyA(ADE7953 *ADE);
dobule  mgos_ade7953_getInstApparentPowerA(ADE7953 *ADE);
double  mgos_ade7953_getInstActivePowerA(ADE7953 *ADE);
double  mgos_ade7953_getInstReactivePowerA(ADE7953 *ADE);
double  mgos_ade7953_decimalize(ADE7953 *ADE, long input, double factor, double offset);

#ifdef __cplusplus
}
#endif  /* __cplusplus */