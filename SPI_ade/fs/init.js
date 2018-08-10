load('api_sys.js');
load('api_timer.js');
load('api_wifi.js');
load('api_config.js');
load('api_spi.js');

let number = '0000';
let spi = SPI.get();

print('.');
print('.');
print('.');
print('.');
print('.');
print('.');
print('.');
print('INICIO DE PROGRAMA');
print('.');
print('.');
print('.');
print('.');
print('.');
print('.');
print('.');


print(spi);

let param = {
  cs: 0,
  mode:0,
  freq: 0,
  hd: {
    tx_data: "data",
    dummylen: 1,
    rx_len: 3,
  },
  fd: {
    tx_data: "data"
  }
};

/*
Timer.set(1000, Timer.REPEAT, function() {
  let result = SPI.runTransaction(spi, param);
  if (result){
    print('Msg 1: ' + param.hd.tx_data);
    print('Msg 2: ' + param.fd.tx_data);
    print('Recibido: ' + result);
  } else {
    print('Error');
  }
},null);
*/

/*
Cfg.set({aws: {thing_name: 'Wenu2'}});
Cfg.set({device: {id: 'wenu'+number}});
Cfg.set({wifi: {ap: {ssid: Cfg.get('device.id'), pass: 'wenu5855'}}});
*/

/*
Timer.set(10000, Timer.REPEAT, function() {
  print('>> Starting scan...');
  Wifi.scan(function(results) {
    if (results === undefined) {
      print('!! Scan error');
      return;
    } else {
      print('++ Scan finished,', results.length, 'results:');
    }
    for (let i = 0; i < results.length; i++) {
      print(' ', JSON.stringify(results[i]));
    }
    print('..', Sys.free_ram());
  });
}, null);
*/