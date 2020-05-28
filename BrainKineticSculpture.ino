
#define CONSTRAIN_HIGH 1000000
#define CONSTRAIN_LOW 10000
#define NUM_READINGS 5

// ---------------------- Libraries ------------------------
#include <Brain.h>
//-----------------------  Objects ------------------------
Brain brain(Serial);
// ------------------------ Variables ----------------------

//Holds Delta signal value (sum)
int Ddata[NUM_READINGS];
byte Ddata_ptr;



void setup() {
  // Start the hardware serial.
  Serial.begin(9600);

  for (int i = 0; i < NUM_READINGS; i++) {
    if (brain.update()) {
      Ddata[i] = brain.readDelta();
    }
  }
  Serial.print("Los valores leídos en setup son: ");
  for (int i = 0; i < NUM_READINGS; i++) {
    Serial.print(Ddata[i]);
    Serial.print(" ");
  }
  Serial.println();
}


//------------------------------------- LOOP ------------------------------------------

void loop() {

  for (int i = 0; i < NUM_READINGS; i++) {
    if (brain.update()) {
      Serial.println(brain.readErrors());
      Serial.println(brain.readCSV());
      Ddata[i] = brain.readDelta();
    }
  }
  Serial.print("------>>>>> Los valores leídos en setup son: ");
  for (int i = 0; i < NUM_READINGS; i++) {
    Serial.print(Ddata[i]);
    Serial.print(" ");
  }
  Serial.println();


  /*
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"


    if (brain.update()) {
      for (int i = 0; i < NUM_READINGS; i++) {
        Ddata[i] = brain.readDelta();
      }
    }








    // ------------------------------- Intereaction

    if (brain.readDelta() > SP_1) &&  (brain.readTheta() > SP_1) {



    }
    // --------- Constrain readings

    ConD = constrain(brain.readDelta(), Min, Max);
    ConTH = constrain(brain.readTheta(), Min, Max);
    ConLA = constrain(brain.readLowAlpha(), Min, Max);
    ConHA = constrain(brain.readHighAlpha(), Min, Max);
    ConLB = constrain(brain.readLowBeta(), Min, Max);
    ConHB = constrain(brain.readHighBeta(), Min, Max);
    ConLG = constrain(brain.readLowGamma(), Min, Max);
    ConMG = constrain(brain.readMidGamma(), Min, Max);



    MapConD = map(ConD, Min, Max, 10.0, 1000.0);
    MapConTH = map(ConTH, Min, Max, 10.0, 1000.0);
    MapConLA = map(ConLA, Min, Max, 10.0, 1000.0);
    MapConHA = map(ConHA, Min, Max, 10.0, 1000.0);
    MapConLB = map(ConLB, Min, Max, 10.0, 1000.0);
    MapConHB = map(ConHB, Min, Max, 10.0, 1000.0);
    MapConLG = map(ConLG, Min, Max, 10.0, 1000.0);
    MapConMG = map(ConMG, Min, Max, 10.0, 1000.0);

    // ----------------------------   Mid Values For graph ------------





    // ----------------------  Mid Vlues for Delta
    SumDdata = OldDdata + MapConD;
    GlobalDdata = SumDdata / Counter;
    // ----------------------  Mid Vlues for Theta
    SumTHdata = OldTHdata + MapConTH;
    GlobalTHdata = SumTHdata / Counter;
    // ----------------------  Mid Vlues for LowAlpha
    SumLAdata = OldLAdata  + MapConLA ;
    GlobalLAdata = SumLAdata / Counter;
    // ----------------------  Mid Vlues for HighAlpha
    SumHAdata = OldHAdata  + MapConHA ;
    GlobalHAdata = SumHAdata / Counter;
    // ----------------------  Mid Vlues for LowBeta
    SumLBdata = OldLBdata  + MapConLB ;
    GlobalLBdata = SumLBdata / Counter;
    // ----------------------  Mid Vlues for HighBetaelta
    SumHBdata = OldHBdata  + MapConHB ;
    GlobalHBdata = SumHBdata / Counter;
    // ----------------------  Mid Vlues for LowGamma
    SumLGdata = OldLGdata  + MapConLG ;
    GlobalLGdata = SumLGdata / Counter;
    // ----------------------  Mid Vlues for Delta
    SumMGdata = OldMGdata  + MapConMG ;
    GlobalMGdata = SumMGdata / Counter;


    // -----------------------  Print Values


    Serial.print(GlobalDdata);
    Serial.print(",");
    //delay(500);

    Serial.print(GlobalTHdata);
    Serial.print(",");
    //delay(500);

    Serial.print( GlobalLAdata);
    Serial.print(",");
    //delay(500);

    Serial.print(GlobalHAdata);
    Serial.print(",");
    //delay(500);

    Serial.print(GlobalLBdata);
    Serial.print(",");
    //delay(500);

    Serial.print(GlobalHBdata);
    Serial.print(",");
    //delay(500);

    Serial.print(GlobalLGdata);
    Serial.print(",");
    //delay(500);

    Serial.println(GlobalMGdata);
    //delay(500);


    //    delay(1000);
    //    Serial.print(GlobalDdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalTHdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalLAdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalHAdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalLBdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalHBdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.print(GlobalLGdata);
    //    Serial.print("  ,  ");
    //    delay(1000);
    //    Serial.println(GlobalMGdata);
    //    delay(1000);
    //

    //    Serial.print(Counter);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalDdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalTHdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalLAdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalHAdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalLBdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalHBdata);
    //    Serial.print("  ,  ");
    //    Serial.print(GlobalLGdata);
    //    Serial.print("  ,  ");
    //    Serial.println(GlobalMGdata);


    // -----------------------   Storing The sum of the values

    OldDdata = SumDdata;
    OldTHdata = SumTHdata;
    OldLAdata = SumLAdata;
    OldHAdata = SumHAdata;
    OldLBdata = SumLBdata;
    OldHBdata = SumHBdata;
    OldLGdata = SumLGdata;
    OldMGdata = SumMGdata;

    // -------------------------  Restart Avarege counter
    //     This part of the code is intended to generate an avareg value of the brian
    //     wave. It lets us guaranty accuracy if we go with the radar model were the values are
    //     will update every 10 sec.


    if (Counter >= Break) {
      Counter = 0;
      OldDdata = MapConD;
      OldTHdata = MapConTH;
      OldLAdata = MapConLA;
      OldHAdata = MapConHA;
      OldLBdata = MapConLB;
      OldHBdata = MapConHB;
      OldLGdata = MapConLG;
      OldMGdata = MapConMG;
    }
    }
    //
    //    Serial.println(Counter);
    //    Serial.print("  ,  ");
    //    delay(1000);
  */
}
