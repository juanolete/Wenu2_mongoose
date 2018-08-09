load('api_sys.js');
load('api_timer.js');
load('api_wifi.js');
load('api_config.js');

let number = '0000';

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