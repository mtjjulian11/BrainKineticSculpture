
#define CONSTRAIN_HIGH 1000000
#define CONSTRAIN_LOW 10000
#define NUM_READINGS 5

// ---------------------- Libraries ------------------------
#include <Brain.h>
//-----------------------  Objects ------------------------
Brain brain(Serial);
// ------------------------ Variables ----------------------

//Holds Delta signal value (sum)
unsigned long Ddata[NUM_READINGS];
unsigned long THdata[NUM_READINGS];
unsigned long LAdata[NUM_READINGS];
unsigned long HAdata[NUM_READINGS];
unsigned long LBdata[NUM_READINGS];
unsigned long HBdata[NUM_READINGS];
unsigned long LGdata[NUM_READINGS];
unsigned long MGdata[NUM_READINGS];

byte Ddata_idx;
byte THdata_idx;
byte LAdata_idx;
byte HAdata_idx;
byte LBdata_idx;
byte HBdata_idx;
byte LGdata_idx;
byte MGdata_idx;

unsigned long Ddata_avg;
unsigned long THdata_avg;
unsigned long LAdata_avg;
unsigned long HAdata_avg;
unsigned long LBdata_avg;
unsigned long HBdata_avg;
unsigned long LGdata_avg;
unsigned long MGdata_avg;




void setup() {
  // Start the hardware serial.
  Serial.begin(9600);

  //Obtenemos los 5 primeros valores
  for (int i = 0; i < NUM_READINGS; i++) {
    while (!brain.update()) {}

    Ddata[i] = brain.readDelta();
    THdata[i] = brain.readTheta();
    LAdata[i] = brain.readLowAlpha();
    HAdata[i] = brain.readHighAlpha();
    LBdata[i] = brain.readLowBeta();
    HBdata[i] = brain.readHighBeta();
    LGdata[i] = brain.readLowGamma();
    MGdata[i] = brain.readMidGamma();

    
    Ddata_avg = Ddata_avg + Ddata[i];
    THdata_avg = THdata_avg + THdata[i];
    LAdata_avg = LAdata_avg + LAdata[i];
    HAdata_avg = HAdata_avg + HAdata[i];
    LBdata_avg = LBdata_avg + LBdata[i];
    HBdata_avg = HBdata_avg + HBdata[i];
    LGdata_avg = LGdata_avg + LGdata[i];
    MGdata_avg = MGdata_avg + MGdata[i];
    
  }
  
  Ddata_idx = NUM_READINGS;
  THdata_idx = NUM_READINGS;
  LAdata_idx = NUM_READINGS;
  HAdata_idx = NUM_READINGS;
  LBdata_idx = NUM_READINGS;
  HBdata_idx = NUM_READINGS;
  LGdata_idx = NUM_READINGS;
  MGdata_idx = NUM_READINGS;
  
}


//------------------------------------- LOOP ------------------------------------------


void loop() {

  if (brain.update()) {
    if ((Ddata_idx == NUM_READINGS) && (THdata_idx == NUM_READINGS) && (LAdata_idx == NUM_READINGS) && 
    (HAdata_idx == NUM_READINGS) && (LBdata == NUM_READINGS) && (HBdata_idx == NUM_READINGS) && (LGdata_idx == NUM_READINGS) &&
    (MGdata_idx == NUM_READINGS)) {
      
  Ddata_idx = 0;
  THdata_idx = 0;
  LAdata_idx = 0;
  HAdata_idx = 0;
  LBdata_idx = 0;
  HBdata_idx = 0;
  LGdata_idx = 0;
  MGdata_idx = 0;
    }
    
    Ddata[Ddata_idx] = brain.readDelta();
    Ddata_idx++;
    
    THdata[THdata_idx] = brain.readTheta();
    THdata_idx++;
    
    LAdata[LAdata_idx] = brain.readLowAlpha();
    LAdata_idx++;

    HAdata[HAdata_idx] = brain.readHighAlpha();
    HAdata_idx++;

    LBdata[LBdata_idx] = brain.readLowBeta();
    LBdata_idx++;

    HBdata[HBdata_idx] = brain.readHighBeta();
    HBdata_idx++;

    LGdata[LGdata_idx] = brain.readLowGamma();
    LGdata_idx++;

    MGdata[MGdata_idx] = brain.readMidGamma();
    MGdata_idx++;

    
    //calculamos el promedio de las medias móviles
    Ddata_avg = 0;
    THdata_avg = 0;
    LAdata_avg = 0;
    HAdata_avg = 0;
    LBdata_avg = 0;
    HBdata_avg = 0;
    LGdata_avg = 0;
    MGdata_avg = 0;
    
  
    for (int i = 0; i < NUM_READINGS; i++) {
      Ddata_avg += Ddata[i];
      THdata_avg +=  THdata[i];
      LAdata_avg +=  LAdata[i];
      HAdata_avg +=  HAdata[i];
      LBdata_avg +=  LBdata[i];
      HBdata_avg +=  HBdata[i];
      LGdata_avg +=  LGdata[i];
      MGdata_avg +=  MGdata[i];
    }
           
   
    Serial.print(constrain((Ddata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((THdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((LAdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((HAdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((LBdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((HBdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.print(constrain((LGdata_avg / NUM_READINGS), 500, 999999));
    Serial.print(" , ");
    Serial.println(constrain((MGdata_avg / NUM_READINGS), 500, 999999));
    
    
  }





  /*
    Ddata_avg = 0;

    //For de adquisición de datos
    for (int i = 0; i < NUM_READINGS; i++) {
    while (!brain.update()) {}
    //Serial.println(brain.readErrors());
    //Serial.println(brain.readCSV());
    Ddata[i] = brain.readDelta();
    Ddata_avg = Ddata_avg + Ddata[i];

    Bdata[i] = brain.readBeta();
    Bdata_avg = Bdata_avg + Bdata[i];

    }

    //For de impresión de datos y promedios
    //Serial.print("------>>>>> Los valores leídos en loop son: ");
    //for (int i = 0; i < NUM_READINGS; i++) {
    //  Serial.print(Ddata[i]);
    //  Serial.print(" ");
    //}
    Serial.print("El promedio es Delta es de ");
    Serial.println(Ddata_avg / NUM_READINGS);

    Serial.print("El prmedio de Beta es de ");
    Serial.println(Bdata_avg / NUM_READINGS);
  */

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
