/*
DSP Shield Mode FIR Load Example
Loads an FIR filter from the SD Card
*/

//order of library invocation matters here. All three are required to use the DSP Shield.
//This is inherent to the Arduino IDE.
#include <SPI.h>
#include <mailbox.h>
#include <DSPShield.h>

void setup() {
  DSPShield.init(); //initialize
  
  DSPShield.startLoopback(); //start shield audio loopback
  
  /*load a band stop filter from the SD Card. 
  
  For a band / notch filter:
  DSPShield.setFIRFilter(channel to use, filter type, filter order, filter cutoff1, filter cutoff2);
  For a low / high filter:
  DSPShield.setFIRFilter(channel to use, filter type, filter order, filter cutoff);
  
  channel options:
  channels are CHAN_LEFT, CHAN_RIGHT, CHAN_BOTH
  
  type options:
  LOW_PASS, HIGH_PASS, BAND_PASS, BAND_STOP
  
  order options:
  tap settings are 41, 101, 201, 511
  
  cutoff options:
  For filters with two cutoffs, use two parameters. For single paramter filters (LOW_PASS and HIGH_PASS) use one cutoff parameter
  Increments are 1Hz steps from 10Hz to 20000Hz
  
  */
  DSPShield.setFIRFilter(CHAN_BOTH, LOW_PASS, 201, 3000);
}

void loop() {}

