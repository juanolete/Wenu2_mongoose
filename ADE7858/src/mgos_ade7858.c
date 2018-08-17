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
static uint32_t ade7858_spi_read_register(uint16_t reg) {
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
static void ade7858_spi_write_register(uint16_t reg, uint32_t val){
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

static void ade7858_spi_write_init(void){
  struct mgos_spi *spi = mgos_spi_get_global();
  if (!spi) {
    LOG(LL_ERROR, ("Cannot get global SPI bus"));
    return;
  }
  struct mgos_spi_txn txn = {
    .cs = mgos_sys_config_get_ade7858_cs_index(),
    .mode = 3,
    .freq = SPI_freq,
  }
  uint16_t reg = 0xEBFF;
  uint8_t reg0 = 0xFF & reg;
  uint8_t reg1 = 0xFF & (reg >> 8);
  uint8_t val = 0xF;

  uint8_t tx_data[4] = {write, reg1, reg0, val};

  txn.hd.tx_data = &tx_data;
  txn.hd.tx_len = 1;
  txn.hd.dummy_len = 0;
  txn.hd.rx_len    = 0;
    if (!mgos_spi_run_txn(spi, false, &txn)) {
    LOG(LL_ERROR, ("SPI transaction failed"));
    return;
  }
}

//init
bool mgos_ade7858_init(void){
  mgos_gpio_set_mode(mgos_sys_config_get_ade7858_rst_pin(), MGOS_GPIO_MODE_OUTPUT);
  /*
  mgos_gpio_set_mode(mgos_sys_config_get_ade7858_irq_pin(), MGOS_GPIO_MODE_INPUT);
  mgos_gpio_set_pull(mgos_sys_config_get_ade7858_irq_pin(), MGOS_GPIO_PULL_UP);
  mgos_gpio_set_int_handler(mgos_sys_config_get_ade7858_irq_pin()), MGOS_GPIO_INT_EDGE_NEG, ade7858_irq, NULL);
  mgos_gpio_enable_int(mgos_sys_config_get_ade7858_irq_pin());
  */
  ade7858_spi_write_init();
  mgos_msleep(100);
  ade7858_spi_write_init();
  mgos_msleep(100);
  ade7858_spi_write_init();

  //CONFIGURAR


}


//get Phase A Voltage RMS
//get Phase A Current RMS
//get Phase A Active Energy
//get Phase A Reactive Energy
//get Phase A Apparent Energy
//get Phase A Peak Current
//get Phase A Peak Voltage

bool mgos_empty_init(void) {
  return true;
}
