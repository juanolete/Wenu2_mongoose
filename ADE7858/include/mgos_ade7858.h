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
#define CHECKSUM_32 0xE51F //Checksum verification.
#define VNOM_24 0xE520
#define PHSTATUS_16 0xE600 //Phase peak register
#define ANGLE0_16 0xE601 //Delay between Phase A voltage and Phase C voltage.
#define ANGLE1_16 0xE602 //Delay between Phase B voltage and Phase C voltage.
#define ANGLE2_16 0xE603 //Delay between Phase A voltage and Phase B voltage.
#define PERIOD_16 0xE607 //Network line period
#define PHNOLOAD_16 0xE608 //Phase no load register
#define LINECYC_16 0xE60C //Line cycle accumulation mode count
#define ZXTOUT_16 0xE60D //Zero-crossing timeout count

//For configuration
#define STATUS0_32 0xE502 //Interrupt Status Register 0.
#define STATUS1_32 0xE503 //Interrupt Status Register 1.
#define OILVL_24 0xE507 //Overcurrent threshold.
#define OVLVL_24 0xE508 //Overvoltage threshold.
#define SAGLVL_24 0xE509 //Voltage SAG level threshold. 
#define MASK0_32 0xE50A //Interrupt Enable Register 0.
#define MASK1_32 0xE50A //Interrupt Enable Register 1.
#define COMPMODE_16 0xE60E //Computation-mode register.
#define Gain_16 0xE60F //PGA gains at ADC inputs.
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
#define LCYCMODE_8 0xE702 //Line accumulation mode behavior
#define PEAKCYC_8 0xE703 //Peak detection half line cycles
#define SAGCYC_8 0xE704 //SAG detectition half line cycles
#define CFCYC_8 0xE705
#define HSDC_CFG_8 0xE706 //HSDC configuratio register
#define CONFIG2_8 0xEC01 //Configuration register used during PSM1.

//DSP Data Memory RAM registers
#define AIGAIN_24 0x4380 //Phase A current gain adjust
#define AVGAIN_24 0x4381 //Phase A voltage gain adjust
#define BIGAIN_24 0x4382 //Phase B current gain adjust
#define BVGAIN_24 0x4383 //Phase B voltage gain adjust
#define CIGAIN_24 0x4384 //Phase C current gain adjust
#define CVGAIN_24 0x4385 //Phase C voltage gain adjust
#define NIGAIN_24 0x4386 //Neutral current gain adjust

#define AIRMSOS_24 0x4387 //Phase A current rms offset
#define AVRMSOS_24 0x4388 //Phase A voltage rms offset
#define BIRMSOS_24 0x4389 //Phase B current rms offset
#define BVRMSOS_24 0x438A //Phase B voltage rms offset
#define CIRMSOS_24 0x438B //Phase C current rms offset
#define CVRMSOS_24 0x438C //Phase C voltage rms offset

#define AVAGAIN_24 0x438E //Phase A apparent power gain adjust
#define BVAGAIN_24 0x438F //Phase B apparent power gain adjust
#define CVAGAIN_24 0x4390 //Phase C apparent power gain adjust
#define AWGAIN_24 0x4391 //Phase A total active power gain adjust
#define AWATTOS_24 0x4392 //Phase A total active power offset adjust.
#define BWGAIN_24 0x4393 //Phase B total active power gain adjust
#define BWATTOS_24 0x4394 //Phase B total active power offset adjust.
#define CWGAIN_24 0x4395 //Phase C total active power gain adjust
#define CWATTOS_24 0x4396 //Phase C total active power offset adjust.
#define AVARGAIN_24 0x4397 //Phase A total reactive power gain adjust
#define AVAROS_24 0x4398 //Phase A total reactive power offset adjust
#define BVARGAIN_24 0x4399 //Phase B total reactive power gain adjust
#define BVAROS_24 0x439A //Phase B total reactive power offset adjust
#define CVARGAIN_24 0x439B //Phase C total reactive power gain adjust
#define CVAROS_24 0x439C //Phase C total reactive power offset adjust
#define AFWGAIN_24 0x439D //Phase A fundamental active power gain adjust. 
#define AFWATTOS_24 0x439E //Phase A fundamental active power offset adjust.
#define VATHR1_24 0x43A9
#define VATHR0_24 0x43AA
#define WTHR1_24 0x43AB
#define WTHR0_24 0x43AC
#define VARTHR1_24 0x43AD
#define VARTHR0_24 0x43AE
#define VANOLOAD_24 0x43B0 //No load threshold in the apparent power datapath.
#define APNOLOAD_24 0x43B1 //No load threshold in the total/fundamental active power datapath. 
#define DICOEFF_24 0x43B5 
#define HPFDIS_24 0x43B6
#define Run_16 0xE228

/*
struct mgos_ade7858_event_data{
    bool interrupt;
};

typedef void (*mgos_ade7858_event_t)(struct mgos_ade7858_event_data *);
*/

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