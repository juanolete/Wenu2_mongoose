#ifndef __ADE7858_
#define __ADE7858_

//REGISTERS

//For reading phase current and voltage
#define AIRMS_24 0x43C0 //Phase A current rms value.
#define AVRMS_24 0x43C1 //Phase A voltage rms value.
#define BIRMS_24 0x43C2 //Phase B current rms value.
#define BVRMS_24 0x43C3 //Phase B voltage rms value.
#define CIRMS_24 0x43C4 //Phase C current rms value.
#define CVRMS_24 0x43C5 //Phase C voltage rms value.

//For reading energy 
#define AWATTHR_32 0xE400 //Phase A total active energy accumulation.
#define BWATTHR_32 0xE401 //Phase B total active energy accumulation.
#define CWATTHR_32 0xE402 //Phase C total active energy accumulation.
#define AVARHR_32 0xE406 //Phase A total reactive energy accumulation.
#define BVARHR_32 0xE407 //Phase B total reactive energy accumulation
#define CVARHR_32 0xE408 //Phase C total reactive energy accumulation
#define AVAHR_32 0xE40C //Phase A apparent energy accumulation.
#define BVAHR_32 0xE40D //Phase B apparent energy accumulation.
#define CVAHR_32 0xE40E //Phase C apparent energy accumulation.

//For reading power quality
#define IPEAK_32 0xE500 //Current peak register.
#define VPEAK_32 0xE501 //Voltage peak register.

#define IAWV_24 0xE50C //Instantaneous value of Phase A current.
#define IBWV_24 0xE50D //Instantaneous value of Phase B current.
#define ICWV_24 0xE50E //Instantaneous value of Phase C current. 
#define VAWV_24 0xE510 //Instantaneous value of Phase A voltage.
#define VBWV_24 0xE511 //Instantaneous value of Phase B voltage.
#define VCWV_24 0xE512 //Instantaneous value of Phase C voltage.
#define AWATT_24 0xE513 //Instantaneous value of Phase A total active power.
#define BWATT_24 0xE514 //Instantaneous value of Phase B total active power.
#define CWATT_24 0xE515 //Instantaneous value of Phase C total active power.
#define AVAR_24 0xE516 //Instantaneous value of Phase A total reactive power.
#define BVAR_24 0xE517 //Instantaneous value of Phase B total reactive power.
#define CVAR_24 0xE518 //Instantaneous value of Phase C total reactive power.
#define AVA_24 0xE519 //Instantaneous value of Phase A apparent power.
#define BVA_24 0xE51A //Instantaneous value of Phase B apparent power.
#define CVA_24 0xE51B //Instantaneous value of Phase C apparent power.
#define ANGLE0_16 0xE601 //Delay between Phase A voltage and Phase C voltage.
#define ANGLE1_16 0xE602 //Delay between Phase B voltage and Phase C voltage.
#define ANGLE2_16 0xE603 //Delay between Phase A voltage and Phase B voltage.

//For configuration
#define STATUS0_32 0xE502 //Interrupt Status Register 0.
#define STATUS1_32 0xE503 //Interrupt Status Register 1.
#define MASK0_32 0xE50A //Interrupt Enable Register 0.
#define MASK1_32 0xE50A //Interrupt Enable Register 1.
#define COMPMODE_16 0xE60E //Computation-mode register.
#define GAIN_16 0xE60F //PGA gains at ADC inputs.
#define CFMODE_16 0xE610 //CFx configuration register.
#define CF1DEN_16 0xE611 //CF1 denominator.
#define CF2DEN_16 0xE612 //CF2 denominator.
#define CF3DEN_16 0xE613 //CF3 denominator.
#define APHCAL_10 0xE614 //Phase calibration of Phase A.
#define BPHCAL_10 0xE615 //Phase calibration of Phase B.
#define CPHCAL_10 0xE616 //Phase calibration of Phase C.
#define PHSIGN_16 0xE617 //Power sign register.
#define CONFIG_16 0xE618 //ADE7878 configuration register.
#define MMODE_8 0xE700 //Measurement mode register.
#define ACCMODE_8 0xE701 //Accumulation mode register.
#define CONFIG2_8 0xEC01 //Configuration register used during PSM1.

//funciones

//init

//get Phase A Voltage RMS
//get Phase A Current RMS
//get Phase A Active Energy
//get Phase A Reactive Energy
//get Phase A Apparent Energy
//get Phase A Peak Current
//get Phase A Peak Voltage

#endif // __ADE7858_