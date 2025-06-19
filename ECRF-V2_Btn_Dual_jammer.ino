#include "ELECHOUSE_CC1101_SRC_DRV.h"

// ===============================
// ===============================
// Settings MODULE 1
// ===============================

#define MOD1_GDO0           2       // (2-39) GPIO sortie TX module 2. 
#define MOD1_FREQ           433.92  // [MHz](300-348, 387-464, 779-928) Here you can set your basic frequency. The lib calculates the frequency automatically (default = 433.92).The cc1101 can: 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from datasheet.
#define MOD1_MODULATION     2       // set modulation mode. 0 = 2-FSK, 1 = GFSK, 2 = ASK/OOK, 3 = 4-FSK, 4 = MSK.
#define MOD1_DEVIATION      47.60  // [kHz] Déviation fréquence (1.58-380.85). Set the Frequency deviation in kHz. Value from 1.58 to 380.85. Default is 47.60 kHz
#define MOD1_CHANNEL        0       // [0-255] Set the Channelnumber from 0 to 255. Default is cahnnel 0
#define MOD1_CHSP           199.95  // [kHz] (25.39-405.45). The channel spacing is multiplied by the channel number CHAN and added to the base frequency in kHz. Value from 25.39 to 405.45. Default is 199.95 kHz.
#define MOD1_RXBW           812.50  // [kHz] (58.03-812.50). Set the Receive Bandwidth in kHz. Value from 58.03 to 812.50. Default is 812.50 kHz.
#define MOD1_DRATE          99.97    // [kBaud] (0.02-1621.83). Set the Data Rate in kBaud. Value from 0.02 to 1621.83. Default is 99.97 kBaud
#define MOD1_PA             12      // [dBm] Set TxPower. The following settings are possible depending on the frequency band.  (-30  -20  -15  -10  -6    0    5    7    10   11   12) Default is max! 
#define MOD1_SYNCMODE       0       // Combined sync-word qualifier mode. 0 = No preamble/sync. 1 = 16 sync word bits detected. 2 = 16/16 sync word bits detected. 3 = 30/32 sync word bits detected. 4 = No preamble/sync, carrier-sense above threshold. 5 = 15/16 + carrier-sense above threshold. 6 = 16/16 + carrier-sense above threshold. 7 = 30/32 + carrier-sense above threshold.
#define MOD1_SYNCWORD_H     211     // [0-255] Sync word haut. Must be the same for the transmitter and receiver. (Syncword high, Syncword low)
#define MOD1_SYNCWORD_L     145     // [0-255] Set sync word. Must be the same for the transmitter and receiver. (Syncword high, Syncword low)
#define MOD1_ADRCHK         0       // [0-3] Controls address check configuration of received packages. 0 = No address check. 1 = Address check, no broadcast. 2 = Address check and 0 (0x00) broadcast. 3 = Address check and 0 (0x00) and 255 (0xFF) broadcast.
#define MOD1_ADDR           0       // [0-255] Address used for packet filtration. Optional broadcast addresses are 0 (0x00) and 255 (0xFF).
#define MOD1_WHITEDATA      0       // [0/1] Turn data whitening on / off. 0 = Whitening off. 1 = Whitening on.
#define MOD1_PKTFORMAT      2       // [0-3] Format of RX and TX data. 0 = Normal mode, use FIFOs for RX and TX. 1 = Synchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins. 2 = Random TX mode; sends random data using PN9 generator. Used for test. Works as normal mode, setting 0 (00), in RX. 3 = Asynchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins.
#define MOD1_LENGTHCONFIG   2       // [0-3] 0 = Fixed packet length mode. 1 = Variable packet length mode. 2 = Infinite packet length mode. 3 = Reserved
#define MOD1_PACKETLENGTH   0       // [0-255] Indicates the packet length when fixed packet length mode is enabled. If variable packet length mode is used, this value indicates the maximum packet length allowed.
#define MOD1_CRC            0       // [0/1] 1 = CRC calculation in TX and CRC check in RX enabled. 0 = CRC disabled for TX and RX.
#define MOD1_CRC_AF         0       // [0/1] Enable automatic flush of RX FIFO when CRC is not OK. This requires that only one packet is in the RXIFIFO and that packet length is limited to the RX FIFO size.
#define MOD1_DCFILTEROFF    1       // [0/1] Disable digital DC blocking filter before demodulator. Only for data rates ≤ 250 kBaud The recommended IF frequency changes when the DC blocking is disabled. 1 = Disable (current optimized). 0 = Enable (better sensitivity)
#define MOD1_MANCHESTER     0       // [0/1] Enables Manchester encoding/decoding. 0 = Disable. 1 = Enable
#define MOD1_FEC            0       // [0/1] Enable Forward Error Correction (FEC) with interleaving for packet payload (Only supported for fixed packet length mode. 0 = Disable. 1 = Enable
#define MOD1_PRE            0       // [0-7] Sets the minimum number of preamble bytes to be transmitted. Values: 0 : 2, 1 : 3, 2 : 4, 3 : 6, 4 : 8, 5 : 12, 6 : 16, 7 : 24
#define MOD1_PQT            0       // [0-7] Preamble quality estimator threshold. The preamble quality estimator increases an internal counter by one each time a bit is received that is different from the previous bit, and decreases the counter by 8 each time a bit is received that is the same as the last bit. A threshold of 4∙PQT for this counter is used to gate sync word detection. When PQT=0 a sync word is always accepted
#define MOD1_APPENDSTATUS   0       // [0/1] When enabled, two status bytes will be appended to the payload of the packet. The status bytes contain RSSI and LQI values, as well as CRC OK.
#define MOD1_CCMODE         1       // [0/1] set config for internal transmission mode. (don't touch)


// ===============================
// Settings MODULE 2
// ===============================
#define MOD2_GDO0           25      // (2-39) GPIO sortie TX module 2
#define MOD1_FREQ           433.92  // [MHz](300-348, 387-464, 779-928) Here you can set your basic frequency. The lib calculates the frequency automatically (default = 433.92).The cc1101 can: 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from datasheet.
#define MOD1_MODULATION     2       // set modulation mode. 0 = 2-FSK, 1 = GFSK, 2 = ASK/OOK, 3 = 4-FSK, 4 = MSK.
#define MOD1_DEVIATION      47.60  // [kHz] Déviation fréquence (1.58-380.85). Set the Frequency deviation in kHz. Value from 1.58 to 380.85. Default is 47.60 kHz
#define MOD1_CHANNEL        0       // [0-255] Set the Channelnumber from 0 to 255. Default is cahnnel 0
#define MOD1_CHSP           199.95  // [kHz] (25.39-405.45). The channel spacing is multiplied by the channel number CHAN and added to the base frequency in kHz. Value from 25.39 to 405.45. Default is 199.95 kHz.
#define MOD1_RXBW           812.50  // [kHz] (58.03-812.50). Set the Receive Bandwidth in kHz. Value from 58.03 to 812.50. Default is 812.50 kHz.
#define MOD1_DRATE          99.97    // [kBaud] (0.02-1621.83). Set the Data Rate in kBaud. Value from 0.02 to 1621.83. Default is 99.97 kBaud
#define MOD1_PA             12      // [dBm] Set TxPower. The following settings are possible depending on the frequency band.  (-30  -20  -15  -10  -6    0    5    7    10   11   12) Default is max! 
#define MOD1_SYNCMODE       0       // Combined sync-word qualifier mode. 0 = No preamble/sync. 1 = 16 sync word bits detected. 2 = 16/16 sync word bits detected. 3 = 30/32 sync word bits detected. 4 = No preamble/sync, carrier-sense above threshold. 5 = 15/16 + carrier-sense above threshold. 6 = 16/16 + carrier-sense above threshold. 7 = 30/32 + carrier-sense above threshold.
#define MOD1_SYNCWORD_H     211     // [0-255] Sync word haut. Must be the same for the transmitter and receiver. (Syncword high, Syncword low)
#define MOD1_SYNCWORD_L     145     // [0-255] Set sync word. Must be the same for the transmitter and receiver. (Syncword high, Syncword low)
#define MOD1_ADRCHK         0       // [0-3] Controls address check configuration of received packages. 0 = No address check. 1 = Address check, no broadcast. 2 = Address check and 0 (0x00) broadcast. 3 = Address check and 0 (0x00) and 255 (0xFF) broadcast.
#define MOD1_ADDR           0       // [0-255] Address used for packet filtration. Optional broadcast addresses are 0 (0x00) and 255 (0xFF).
#define MOD1_WHITEDATA      0       // [0/1] Turn data whitening on / off. 0 = Whitening off. 1 = Whitening on.
#define MOD1_PKTFORMAT      2       // [0-3] Format of RX and TX data. 0 = Normal mode, use FIFOs for RX and TX. 1 = Synchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins. 2 = Random TX mode; sends random data using PN9 generator. Used for test. Works as normal mode, setting 0 (00), in RX. 3 = Asynchronous serial mode, Data in on GDO0 and data out on either of the GDOx pins.
#define MOD1_LENGTHCONFIG   2       // [0-3] 0 = Fixed packet length mode. 1 = Variable packet length mode. 2 = Infinite packet length mode. 3 = Reserved
#define MOD1_PACKETLENGTH   0       // [0-255] Indicates the packet length when fixed packet length mode is enabled. If variable packet length mode is used, this value indicates the maximum packet length allowed.
#define MOD1_CRC            0       // [0/1] 1 = CRC calculation in TX and CRC check in RX enabled. 0 = CRC disabled for TX and RX.
#define MOD1_CRC_AF         0       // [0/1] Enable automatic flush of RX FIFO when CRC is not OK. This requires that only one packet is in the RXIFIFO and that packet length is limited to the RX FIFO size.
#define MOD1_DCFILTEROFF    1       // [0/1] Disable digital DC blocking filter before demodulator. Only for data rates ≤ 250 kBaud The recommended IF frequency changes when the DC blocking is disabled. 1 = Disable (current optimized). 0 = Enable (better sensitivity)
#define MOD1_MANCHESTER     0       // [0/1] Enables Manchester encoding/decoding. 0 = Disable. 1 = Enable
#define MOD1_FEC            0       // [0/1] Enable Forward Error Correction (FEC) with interleaving for packet payload (Only supported for fixed packet length mode. 0 = Disable. 1 = Enable
#define MOD1_PRE            0       // [0-7] Sets the minimum number of preamble bytes to be transmitted. Values: 0 : 2, 1 : 3, 2 : 4, 3 : 6, 4 : 8, 5 : 12, 6 : 16, 7 : 24
#define MOD1_PQT            0       // [0-7] Preamble quality estimator threshold. The preamble quality estimator increases an internal counter by one each time a bit is received that is different from the previous bit, and decreases the counter by 8 each time a bit is received that is the same as the last bit. A threshold of 4∙PQT for this counter is used to gate sync word detection. When PQT=0 a sync word is always accepted
#define MOD1_APPENDSTATUS   0       // [0/1] When enabled, two status bytes will be appended to the payload of the packet. The status bytes contain RSSI and LQI values, as well as CRC OK.
#define MOD1_CCMODE         1       // [0/1] set config for internal transmission mode. (don't touch)

// ===============================
// BOUTONS ET LED
// ===============================
const int push1 = 34;      // Bouton 1 (démarrage)
const int push2 = 35;      // Bouton 2 (arrêt)
const int led = 32;        // LED statut

bool jammingActive = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

// Duty cycle (modifiable)
const int HIGH_TIME_US = 100; // µs, durée HIGH (100% duty cycle: mettre LOW_TIME_US à 0)
const int LOW_TIME_US  = 100;   // µs, durée LOW (0 pour 100% duty cycle)

void setup() {
  // Configuration boutons et LED
  pinMode(push1, INPUT_PULLUP);
  pinMode(push2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // SPI pour les deux modules
  ELECHOUSE_cc1101.addSpiPin(14, 12, 13, 5, 0);
  ELECHOUSE_cc1101.addSpiPin(14, 12, 13, 27, 1);

  // --- Module 1 ---
  ELECHOUSE_cc1101.setModul(0);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setGDO0(MOD1_GDO0);
  ELECHOUSE_cc1101.setCCMode(MOD1_CCMODE);
  ELECHOUSE_cc1101.setModulation(MOD1_MODULATION);
  ELECHOUSE_cc1101.setMHZ(MOD1_FREQ);
  ELECHOUSE_cc1101.setDeviation(MOD1_DEVIATION);
  ELECHOUSE_cc1101.setChannel(MOD1_CHANNEL);
  ELECHOUSE_cc1101.setChsp(MOD1_CHSP);
  ELECHOUSE_cc1101.setRxBW(MOD1_RXBW);
  ELECHOUSE_cc1101.setDRate(MOD1_DRATE);
  ELECHOUSE_cc1101.setPA(MOD1_PA);
  ELECHOUSE_cc1101.setSyncMode(MOD1_SYNCMODE);
  ELECHOUSE_cc1101.setSyncWord(MOD1_SYNCWORD_H, MOD1_SYNCWORD_L);
  ELECHOUSE_cc1101.setAdrChk(MOD1_ADRCHK);
  ELECHOUSE_cc1101.setAddr(MOD1_ADDR);
  ELECHOUSE_cc1101.setWhiteData(MOD1_WHITEDATA);
  ELECHOUSE_cc1101.setPktFormat(MOD1_PKTFORMAT);
  ELECHOUSE_cc1101.setLengthConfig(MOD1_LENGTHCONFIG);
  ELECHOUSE_cc1101.setPacketLength(MOD1_PACKETLENGTH);
  ELECHOUSE_cc1101.setCrc(MOD1_CRC);
  ELECHOUSE_cc1101.setCRC_AF(MOD1_CRC_AF);
  ELECHOUSE_cc1101.setDcFilterOff(MOD1_DCFILTEROFF);
  ELECHOUSE_cc1101.setManchester(MOD1_MANCHESTER);
  ELECHOUSE_cc1101.setFEC(MOD1_FEC);
  ELECHOUSE_cc1101.setPRE(MOD1_PRE);
  ELECHOUSE_cc1101.setPQT(MOD1_PQT);
  ELECHOUSE_cc1101.setAppendStatus(MOD1_APPENDSTATUS);
  pinMode(MOD1_GDO0, OUTPUT);
  digitalWrite(MOD1_GDO0, LOW);
  ELECHOUSE_cc1101.setSidle(); // Modules inactifs au démarrage

  // --- Module 2 ---
  ELECHOUSE_cc1101.setModul(1);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setGDO0(MOD2_GDO0);
  ELECHOUSE_cc1101.setCCMode(MOD2_CCMODE);
  ELECHOUSE_cc1101.setModulation(MOD2_MODULATION);
  ELECHOUSE_cc1101.setMHZ(MOD2_FREQ);
  ELECHOUSE_cc1101.setDeviation(MOD2_DEVIATION);
  ELECHOUSE_cc1101.setChannel(MOD2_CHANNEL);
  ELECHOUSE_cc1101.setChsp(MOD2_CHSP);
  ELECHOUSE_cc1101.setRxBW(MOD2_RXBW);
  ELECHOUSE_cc1101.setDRate(MOD2_DRATE);
  ELECHOUSE_cc1101.setPA(MOD2_PA);
  ELECHOUSE_cc1101.setSyncMode(MOD2_SYNCMODE);
  ELECHOUSE_cc1101.setSyncWord(MOD2_SYNCWORD_H, MOD2_SYNCWORD_L);
  ELECHOUSE_cc1101.setAdrChk(MOD2_ADRCHK);
  ELECHOUSE_cc1101.setAddr(MOD2_ADDR);
  ELECHOUSE_cc1101.setWhiteData(MOD2_WHITEDATA);
  ELECHOUSE_cc1101.setPktFormat(MOD2_PKTFORMAT);
  ELECHOUSE_cc1101.setLengthConfig(MOD2_LENGTHCONFIG);
  ELECHOUSE_cc1101.setPacketLength(MOD2_PACKETLENGTH);
  ELECHOUSE_cc1101.setCrc(MOD2_CRC);
  ELECHOUSE_cc1101.setCRC_AF(MOD2_CRC_AF);
  ELECHOUSE_cc1101.setDcFilterOff(MOD2_DCFILTEROFF);
  ELECHOUSE_cc1101.setManchester(MOD2_MANCHESTER);
  ELECHOUSE_cc1101.setFEC(MOD2_FEC);
  ELECHOUSE_cc1101.setPRE(MOD2_PRE);
  ELECHOUSE_cc1101.setPQT(MOD2_PQT);
  ELECHOUSE_cc1101.setAppendStatus(MOD2_APPENDSTATUS);
  pinMode(MOD2_GDO0, OUTPUT);
  digitalWrite(MOD2_GDO0, LOW);
  ELECHOUSE_cc1101.setSidle(); // Modules inactifs au démarrage
}

void loop() {
  // Gestion antirebond boutons
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Bouton 1 pressé : démarrer le jam
    if (digitalRead(push1) == LOW && !jammingActive) {
      jammingActive = true;
      digitalWrite(led, LOW);
      // Activer les modules en émission
      ELECHOUSE_cc1101.setModul(0);
      ELECHOUSE_cc1101.SetTx();
      ELECHOUSE_cc1101.setModul(1);
      ELECHOUSE_cc1101.SetTx();
      lastDebounceTime = millis();
    }
    // Bouton 2 pressé : arrêter le jam
    if (digitalRead(push2) == LOW && jammingActive) {
      jammingActive = false;
      digitalWrite(led, HIGH);
      // Désactiver les modules et mettre sorties à LOW
      ELECHOUSE_cc1101.setModul(0);
      ELECHOUSE_cc1101.setSidle();
      digitalWrite(MOD1_GDO0, LOW);
      ELECHOUSE_cc1101.setModul(1);
      ELECHOUSE_cc1101.setSidle();
      digitalWrite(MOD2_GDO0, LOW);
      lastDebounceTime = millis();
    }
  }

  // Jamming actif uniquement si demandé
  if (jammingActive) {
    // Module 1 : signal carré duty cycle paramétrable
    digitalWrite(MOD1_GDO0, HIGH);
    if (HIGH_TIME_US > 0) delayMicroseconds(HIGH_TIME_US);
    digitalWrite(MOD1_GDO0, LOW);
    if (LOW_TIME_US > 0) delayMicroseconds(LOW_TIME_US);

    // Module 2 : signal carré ou Random TX selon configuration
    digitalWrite(MOD2_GDO0, HIGH);
    if (HIGH_TIME_US > 0) delayMicroseconds(HIGH_TIME_US);
    digitalWrite(MOD2_GDO0, LOW);
    if (LOW_TIME_US > 0) delayMicroseconds(LOW_TIME_US);
  } else {
    // Sécurité : modules toujours en veille et sorties à LOW
    ELECHOUSE_cc1101.setModul(0);
    ELECHOUSE_cc1101.setSidle();
    digitalWrite(MOD1_GDO0, LOW);
    ELECHOUSE_cc1101.setModul(1);
    ELECHOUSE_cc1101.setSidle();
    digitalWrite(MOD2_GDO0, LOW);
  }
}
