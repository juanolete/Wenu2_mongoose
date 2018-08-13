let ADE7953 = {
    _create: ffi('void *mgos_ade7953_create(void)'),
    _close: ffi('void mgos_ade7953_close(void *)'),
    _initialize: ffi('void mgos_ade7953_initialize(void *)'),
    _getPowerFactorA: ffi('double mgos_ade7953_getPowerFactorA(void *)'),
    _getPeriod: ffi('double mgos_ade7953_getPeriod(void *);'),
    _getInstVoltage: ffi('long mgos_ade7953_getInstVoltage(void *)'),
    _getVrms: ffi('double mgos_ade7953_getVrms(void *)'),
    _getInstCurrentA: ffi('long mgos_ade7953_getInstCurrentA(void *)'),
    _getIrmsA: ffi('double mgos_ade7953_getIrmsA(void *)'),
    _getVpeak: ffi('long mgos_ade7953_getVpeak(void *)'),
    _getIpeakA: ffi('long mgos_ade7953_getIpeakA(void *)'),
    _getActiveEnergyA: ffi('long mgos_ade7953_getActiveEnergyA(void *)'),
    _getReactiveEnergyA: ffi('long mgos_ade7953_getReactiveEnergyA(void *)'),
    _getApparentEnergyA: ffi('long mgos_ade7953_getApparentEnergyA(void *)'),
    _getInstApparentPowerA: ffi('dobule mgos_ade7953_getInstApparentPowerA(void *)'),
    _getInstActivePowerA: ffi('double mgos_ade7953_getInstActivePowerA(void *)'),
    _getInstReactivePowerA: ffi('double mgos_ade7953_getInstReactivePowerA(void *)'),
    _decimalize: ffi('double  mgos_ade7953_decimalize(void *, long, double, double)'),


    // ## **`ADE7953.create()`**
    // Create an instance of ADE7953 power meter, wich has the methods described
    // below.
    //
    // Example:
    // ```javascript
    // load("api_ade7953.js");
    // let myADE = ADE7953.create();
    // ```
    create: function() {
        let obj = Object.create(ADE7953._proto);
        obj.ade = ADE7953._create();
        return obj;
    },

    _proto: {
        //## **`myADE.clase()`**
        // Close an ADE7953 instance; no other methods can be called on this instance
        // after calling `close()`.
        // Return value: none
        close: function() {
            return ADE7953._close(this.ade);
        },

        // ## **`ADE7953.initialize()`**
        // Initiate SPI communication.
        // Return value: none.
        initialize: function() {
            return ADE7953._initialize(this.ade);
        },

        getPowerFactorA: function() {
            return ADE7953._getPowerFactorA(this.ade);
        },

        getPeriod: function() {
            return ADE7953._getPeriod(this.ade);
        },

        getInstVoltage: function() {
            return ADE7953._getInstVoltage(this.ade);
        },

        getVrms: function () {
            return ADE7953._getVrms(this.ade);
        },

        getInstCurrentA: function() {
            return ADE7953._getInstCurrentA(this.ade);
        },

        getIrmsA: function() {
            return ADE7953._getIrmsA(this.ade);
        },

        getVpeak: function() {
            return ADE7953._getVpeak(this.ade);
        },

        getIpeakA: function() {
            return ADE7953._geetIpeakA(this.ade);
        },


        getActiveEnergyA: function() {
            return ADE7953._getActiveEnergyA(this.ade);
        },

        getReactiveEnergyA: function() {
            return ADE7953._getReactiveEnergyA(this.ade);
        },

        getApparentEnergyA: function() {
            return ADE7953._getApparentEnergyA(this.ade);
        },

        getInstApparentPowerA: function() {
            return ADE7953._getInstApparentPowerA(this.ade);
        },

        getInstActivePowerA: function() {
            return ADE7953._getInstActivePowerA(this.ade);
        },


        getInstReactivePowerA: function() {
            return ADE7953._getInstReactivePowerA(this.ade);
        },

        decimalize: function(input, factor, offset) {
            return ADE7953._decimalize(this.ade, input, factor, offset);
        },
    },
}