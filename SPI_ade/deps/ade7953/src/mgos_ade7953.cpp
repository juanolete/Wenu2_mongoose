#include "mgos_ade7953.h"

ADE7953 *mgos_ade7953_create(int SS, int SPI_freq){
    return new ADE7953(int SS, int SPI_freq);
}

void mgos_ade7953_close(ADE7953 *ADE){
    if (ADE != nullptr) {
        delete ADE;
        ADE = nullptr;
    }
}

void mgos_ade7953_initialize(ADE7953 *ADE){
    return ADE->initialize();
}

double mgos_ade7953_getPowerFactorA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getPowerFactorA();
}

double mgos_ade7953_getPeriod(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getPeriod();
}

long mgos_ade7953_getInstVoltage(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getInstVoltage();
}

double mgos_ade7953_getVrms(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getVrms();
}

long mgos_ade7953_getInstCurrentA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getInstCurrentA();
}

double mgos_ade7953_getIrmsA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getIrmsA();
}

long mgos_ade7953_getVpeak(ADE7953 *ADE){
    if (ADE ==  nullptr) return 0;
        return ADE -> getVpeak();
}

long mgos_ade7953_getIpeakA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getIpeakA();
}
	
long mgos_ade7953_getActiveEnergyA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getActiveEnergyA();
}

long mgos_ade7953_getReactiveEnergyA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getReactiveEnergyA();
}

long mgos_ade7953_getApparentEnergyA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getApparentEnergyA();
}

dobule mgos_ade7953_getInstApparentPowerA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getInstApparentPowerA();
}

double mgos_ade7953_getInstActivePowerA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getInstActivePowerA();
}

double mgos_ade7953_getInstReactivePowerA(ADE7953 *ADE){
    if (ADE == nullptr) return 0;
        return ADE -> getInstReactivePowerA();
}

double mgos_ade7953_decimalize(ADE7953 *ADE, long input, double factor, double offset){
    return ADE -> decimalize(input, factor, offset);
}