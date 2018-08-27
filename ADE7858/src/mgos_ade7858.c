#include "mgos.h"
#include "mgos_spi.h"
#include "mgos_ade7858.h"

const uint8_t read = 0x01;  //This value tells the ADE7858 that data is to be read from the requested register.
const uint8_t write = 0x00; //This value tells the ADE7858 that data is to be write to the requested register.
const int SPI_freq = 1000000; //Communicate with the ADE7858 at 1 MHz frequency.

/*
static mgos_ade7858_event_t s_event_handler = NULL;
struct mgos_ade7858_event_data interrupt;

void mgos_ade7858_set_handler(mgos_ade7858_event_t handler){
  s_event_handler = handler;
}

static void ade7858_irq(){
  return;
}
*/

//read register
uint8_t ade7858_spi_read_register_8(uint16_t reg) {
  struct mgos_spi *spi = mgos_spi_get_global();
  if (!spi) {
    LOG(LL_ERROR,("Cannot get global SPI bus"));
    return 0;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 =  0xFF & (reg >> 8);
  uint8_t tx_data[3] = {read, reg1, reg0};
  uint32_t rx_data;

  struct mgos_spi_txn txn = {
    .cs = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_len    = 3;
  txn.hd.tx_data   = &tx_data;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 1;
  txn.hd.rx_data   = &rx_data;
  if(!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return 0;
  }
  return rx_data;
}
uint16_t ade7858_spi_read_register_16(uint16_t reg) {
  struct mgos_spi *spi = mgos_spi_get_global();
  if (!spi) {
    LOG(LL_ERROR,("Cannot get global SPI bus"));
    return 0;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 =  0xFF & (reg >> 8);
  uint8_t tx_data[3] = {read, reg1, reg0};
  uint32_t rx_data;

  struct mgos_spi_txn txn = {
    .cs = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_len    = 3;
  txn.hd.tx_data   = &tx_data;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 2;
  txn.hd.rx_data   = &rx_data;
  if(!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return 0;
  }
  return rx_data;
}
uint32_t ade7858_spi_read_register_32(uint16_t reg) {
  struct mgos_spi *spi = mgos_spi_get_global();
  if (!spi) {
    LOG(LL_ERROR,("Cannot get global SPI bus"));
    return 0;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 =  0xFF & (reg >> 8);
  uint8_t tx_data[3] = {read, reg1, reg0};
  uint32_t rx_data;

  struct mgos_spi_txn txn = {
    .cs = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_len    = 3;
  txn.hd.tx_data   = &tx_data;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 4;
  txn.hd.rx_data   = &rx_data;
  if(!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return 0;
  }
  return rx_data;
}

//write register
void ade7858_spi_write_register_8(uint16_t reg, uint8_t val){
  struct mgos_spi *spi = mgos_spi_get_global();

  if (!spi) {
    LOG(LL_ERROR, ("Cannot get global SPI bus"));
    return;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 = 0xFF & (reg >> 8);  

  uint8_t tx_data[7] = {write, reg1, reg0, val};

  struct mgos_spi_txn txn = {
    .cs   = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_data   = &tx_data;
  txn.hd.tx_len    = 4;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 0;
  if (!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return;
  }
}
void ade7858_spi_write_register_16(uint16_t reg, uint16_t val){
  struct mgos_spi *spi = mgos_spi_get_global();

  if (!spi) {
    LOG(LL_ERROR, ("Cannot get global SPI bus"));
    return;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 = 0xFF & (reg >> 8);  
  uint8_t val0 = 0xFF & val;
  uint8_t val1 = 0xFF & (val >> 8);
  uint8_t tx_data[7] = {write, reg1, reg0, val1, val0};

  struct mgos_spi_txn txn = {
    .cs   = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_data   = &tx_data;
  txn.hd.tx_len    = 5;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 0;
  if (!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return;
  }
}
void ade7858_spi_write_register_32(uint16_t reg, uint32_t val){
  struct mgos_spi *spi = mgos_spi_get_global();

  if (!spi) {
    LOG(LL_ERROR, ("Cannot get global SPI bus"));
    return;
  }

  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 = 0xFF & (reg >> 8);  
  uint8_t val0 = 0xFF & val;
  uint8_t val1 = 0xFF & (val >> 8);
  uint8_t val2 = 0xFF & (val >> 16);
  uint8_t val3 = 0xFF & (val >> 24);
  uint8_t tx_data[7] = {write, reg1, reg0, val3, val2, val1, val0};

  struct mgos_spi_txn txn = {
    .cs   = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  };
  txn.hd.tx_data   = &tx_data;
  txn.hd.tx_len    = 7;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 0;
  if (!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return;
  }
}

void ade7858_spi_write_init(void){
  ade7858_spi_write_register_8(0xEBFF, 0xFF);
  mgos_msleep(100);
  ade7858_spi_write_register_8(0xEBFF, 0xFF);
  mgos_msleep(100);
  ade7858_spi_write_register_8(0xEBFF, 0xFF);
  mgos_msleep(100);
}

long b24tolong(uint32_t val){
  if (val & 0x00800000){
     return (long)(0xFF000000 | val)
  } else {
    return (long)val;
  }
}

//For Phase A measure
long mgos_ade7858_getAVoltage(void){
  return b24tolong(ade7858_spi_read_register_32(AVRMS_24));
}
long mgos_ade7858_getACurrent(void){
  return b24tolong(ade7858_spi_read_register_32(AIRMS_24));
}
long mgos_ade7858_getAActiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(AWATTHR_32));
}
long mgos_ade7858_getAReactiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(AVARHR_32));
}
long mgos_ade7858_getAAparentEnergy(void){
  return (long)(ade7858_spi_read_register_32(AVAHR_32));
}

//For Phase B measure
long mgos_ade7858_getBVoltage(void){
  return b24tolong(ade7858_spi_read_register_32(BVRMS_24));
}
long mgos_ade7858_getBCurrent(void){
  return b24tolong(ade7858_spi_read_register_32(BIRMS_24));
}
long mgos_ade7858_getBActiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(BWATTHR_32));
}
long mgos_ade7858_getBReactiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(BVARHR_32));
}
long mgos_ade7858_getBAparentEnergy(void){
  return (long)(ade7858_spi_read_register_32(BVAHR_32));
}

//For Phase C measure
long mgos_ade7858_getCVoltage(void){
  return b24tolong(ade7858_spi_read_register_32(CVRMS_24));
}
long mgos_ade7858_getCCurrent(void){
  return b24tolong(ade7858_spi_read_register_32(CIRMS_24));
}
long mgos_ade7858_getCActiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(CWATTHR_32));
}
long mgos_ade7858_getCReactiveEnergy(void){
  return (long)(ade7858_spi_read_register_32(CVARHR_32));
}
long mgos_ade7858_getCAparentEnergy(void){
  return (long)(ade7858_spi_read_register_32(CVAHR_32));
}

//init
void mgos_ade7858_init(void){
  mgos_gpio_set_mode(mgos_sys_config_get_ade7858_rst_pin(), MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_set_mode(mgos_sys_config_get_ade7858_irq_pin(), MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_pull(mgos_sys_config_get_ade7858_irq_pin(), MGOS_GPIO_PULL_UP);
  /*
  mgos_gpio_set_int_handler(mgos_sys_config_get_ade7858_irq_pin()), MGOS_GPIO_INT_EDGE_NEG, ade7858_irq, NULL);
  mgos_gpio_enable_int(mgos_sys_config_get_ade7858_irq_pin());
  */
  ade7858_spi_write_init();
  ade7858_spi_write_register_8(CONFIG2_8, 0xF0);
  while (mgos_gpio_read(mgos_sys_config_get_ade7858_irq_pin())); //wait for !IRQ1 pin to set LOW
  ade7858_spi_write_register_32(STATUS1_32, 0x00000000);
  ade7858_spi_write_register_32(STATUS0_32, 0x00200000);
  
  //Iniciar Gain registers
  ade7858_spi_write_register_32(AIGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(BIGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(CIGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AVGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(BVGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(CVGAIN_24, 0x00000001);
  ade7858_spi_write_register_16(Gain_16, 0x0000);
  ade7858_spi_write_register_32(AVAGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(BVAGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(CVAGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AWGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(BWGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(CWGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AVARGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(BVARGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(CVARGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AFWGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AFWGAIN_24, 0x00000001);
  ade7858_spi_write_register_32(AFWGAIN_24, 0x00000001);

  //Iniciate all RAM registers
  ade7858_spi_read_register_32(WTHR0_24, 0x007FFFFF); //max value
  ade7858_spi_read_register_32(WTHR1_24, 0x007FFFFF); //max value
  ade7858_spi_read_register_32(VARTHR0_24,0x007FFFFF); //max value
  ade7858_spi_read_register_32(VARTHR1_24,0x007FFFFF); //max value
  ade7858_spi_read_register_32(VATHR0_24,0x007FFFFF); //max value
  ade7858_spi_read_register_32(VATHR1_24,0x007FFFFF);  //max value
  ade7858_spi_write_register_16(CF1DEN_16, 0x03E8); //CF1DEN = d1000
  ade7858_spi_write_register_16(CF2DEN_16, 0x03E8); //CF2DEN = d1000
  ade7858_spi_write_register_16(CF3DEN_16, 0x03E8); //CF3DEN = d1000
  ade7858_spi_write_register_32(VNOM_24, 0x00001A4F); //VNOM = d6735
  //Write protection
  ade7858_spi_write_register_8(0xE7FE, 0xAD);
  ade7858_spi_write_register_8(0xE7E3, 0x80);
  //DSP run = 1
  ade7858_spi_write_register_16(Run_16, 0x0001);

  //First read, to clear registers
  long WATTHR = mgos_ade7858_getAActiveEnergy();
  WATTHR = mgos_ade7858_getBActiveEnergy();
  WATTHR = mgos_ade7858_getCActiveEnergy();

  long VARHR = mgos_ade7858_getAAparentEnergy();
  VARHR = mgos_ade7858_getBAparentEnergy();
  VAHR = mgos_ade7858_getCReactiveEnergy(); 

  long VAHR = mgos_ade7858_getAReactiveEnergy();
  VAHR = mgos_ade7858_getBReactiveEnergy();
  VARHR = mgos_ade7858_getCAparentEnergy();
  
  //clear bits 9, 10, 11 to 0 de CFMODE register
}