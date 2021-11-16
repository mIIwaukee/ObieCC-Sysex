/*

Adds CC messages to sysex params for Oberheim Matrix 6/6r/1000 Control

*/

#include <MIDI.h>
// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

// how many parameters are we controling
#define PCOUNT 99
#define MIDICHANNEL 5

// set this control to a high number to begin
byte control_map[127] = {0xFF};
byte val_map[PCOUNT] = {0x7F};
byte val = 0;
float multiplier = 0;

void HandleControlChange (byte channel, byte number, byte value){   
if (channel =5){  
  if (control_map[number] != 0xFF){
    multiplier = (val_map[control_map[number]]/127.0);
     val = multiplier * value;
    // if the multiplier is too low, just pass  he value.
    if (multiplier<.1) {
         val = value;
    }

   
    byte msg[] = { 0xF0, 0x10, 0x06, 0x06, control_map[number], val, 0XF7 };
    MIDI.sendSysEx(7,msg,true);
      // 0x10 - Oberheim MFG ID  // 0x06 - Message Type  // 0x06 - Byte Channel (going off Oberheim Spec)

    // Quick 20ms Delay
    delay(25);
  }     
}}

void setup() {

  // setup mappings
  // (0-127 - 0x7F)
  // (0-63 = 0x3f)
  // (0-31 = 0x1f)
  // (0-3 = 3)

// DC01
    // 00 DC01 Freq // (0-63)
    control_map[0x00] = 0x00;
    val_map[0x00] = 0x3f;

    // 02 Sync // (0, 1, 2, 3)
    control_map[0x02] = 0x02;
    val_map[0x02] = 0x03;

   // 03 DC01 Pulse Width	 // (0-63)
    control_map[0x03] = 0x03;
    val_map[0x03] = 0x3f;

    // 04 PW Mod By LFO 2	 // (0-63)
    control_map[0x04] = 0x04;
    val_map[0x04] = 0x3f;

   // 05 DC01 Wave Shape	 // (0-63)
    control_map[0x05] = 0x05;
    val_map[0x05] = 0x3f;

   // 06 DC01 Wave Type	 // (Off, Pulse, Wave, Both)
    control_map[0x06] = 0x06;
    val_map[0x06] = 0x03;

// DC02
    // 10 DC02 Freq // (0-63)
    control_map[0x0A] = 0x0A;
    val_map[0x0A] = 0x3f;

   // 12 DC02 Detune // (0-31)
    control_map[0x0C] = 0x0C;
    val_map[0x0C] = 0x1f;

   // 13 DC02 Pulse Width	 // (0-63)
    control_map[0x0D] = 0x0D;
    val_map[0x0D] = 0x3f;

   // 15 DC02 Wave Shape	 // (0-63)
    control_map[0x0F] = 0x0F;
    val_map[0x0F] = 0x3f;

   // 16 DC02 Wave Type	 // (Off, Pulse, Wave, Both, Noise)
    control_map[0x10] = 0x10;
    val_map[0x10] = 0x04;

// VCF/VCA/FM

    // 20 DCO MIX  // ((0-63)
    control_map[0x14] = 0x14;
    val_map[0x14] = 0x3f;

    // 21 Frequency  // (0-127)
    control_map[0x15] = 0x15;
    val_map[0x15] = 0x7F;

    // 22 Frequency Mod By ENV 1  //( 0-63)
    control_map[0x16] = 0x16;
    val_map[0x16] = 0x3f;

    // 24 Resonance  // (0-63)
    control_map[0x18] = 0x18;
    val_map[0x18] = 0x3f;

    // 29 VCA2 Mod By ENV 2	// (0-63)
    control_map[0x1D] = 0x1D;
    val_map[0x1D] = 0x3f;

    // 30 VCF FM Amount	// (0-63)
    control_map[0x1E] = 0x1E;
    val_map[0x1E] = 0x3f;

// ENV1 - VCF

    // 51 Attack  // (0-63)
    control_map[0x33] = 0x33;
    val_map[0x33] = 0x3f;

    // 52 Delay  // (0-63)
    control_map[0x34] = 0x34;
    val_map[0x34] = 0x3f;

    // 53 Sustain  // (0-63)
    control_map[0x35] = 0x35;
    val_map[0x35] = 0x3f;

    // 54 Release  // (0-63)
    control_map[0x36] = 0x36;
    val_map[0x36] = 0x3f;  

// ENV2 - VCA

    // 61 Attack  // (0-63)
    control_map[0x3D] = 0x3D;
    val_map[0x3D] = 0x3f;

    // 62 Delay  // (0-63)
    control_map[0x3E] = 0x3E;
    val_map[0x3E] = 0x3f;

    // 63 Sustain  // (0-63)
    control_map[0x3F] = 0x3F;
    val_map[0x3F] = 0x3f;

    // 64 Release  // (0-63)
    control_map[0x40] = 0x40;
    val_map[0x40] = 0x3f;  

// ENV3 - FM / MOD

    // 71 Attack  // (0-63)
    control_map[0x47] = 0x47;
    val_map[0x47] = 0x3f;

    // 72 Delay  // (0-63)
    control_map[0x48] = 0x48;
    val_map[0x48] = 0x3f;

    // 73 Sustain  // (0-63)
    control_map[0x49] = 0x49;
    val_map[0x49] = 0x3f;

    // 74 Release  // (0-63)
    control_map[0x4A] = 0x4A;
    val_map[0x4A] = 0x3f;  
  
// LFO1 - DC0 Freq Mod

    // 80 Speed  // (0-63)
    control_map[0x50] = 0x50;
    val_map[0x50] = 0x3f;

    // 82 Waveform  // (0-7) // (Triangle [Tri], Up or Positive Sawtooth [UpSaw], Down or Negative Sawtooth [DnSaw], Square Wave [Squar], Random Modulation [Randm], Noise Modulation [Noise], Sampled Modulation [Sampl])
    control_map[0x52] = 0x52;
    val_map[0x52] = 0x06;

// LFO2 - DC0 Freq Mod

    // 90 Speed  // (0-63)
    control_map[0x5A] = 0x5A;
    val_map[0x5A] = 0x3f;

    // 92 Waveform  // (0-7) // (Triangle [Tri], Up or Positive Sawtooth [UpSaw], Down or Negative Sawtooth [DnSaw], Square Wave [Squar], Random Modulation [Randm], Noise Modulation [Noise], Sampled Modulation [Sampl])
    control_map[0x5C] = 0x5C;
    val_map[0x5C] = 0x06;

  MIDI.begin(MIDICHANNEL); // Listen to channel 5
 // MIDI.turnThruOff();
  MIDI.setThruFilterMode(5);

  byte msg[] = { 0xF0, 0x10, 0x06, 0x05, 0XF7 };  // GO TO Quick EDIT MODE
  MIDI.sendSysEx(5,msg,true);
  MIDI.setHandleControlChange(HandleControlChange); 

}

void loop() {
    //filter on channel 5
  MIDI.read(MIDICHANNEL);

}
