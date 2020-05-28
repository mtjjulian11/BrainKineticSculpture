

// ---------------------- Libraries ------------------------
#include <Brain.h>
//-----------------------  Objects ------------------------
Brain brain(Serial);
// ------------------------ Variables ----------------------

float Ddata;
float THdata;
float LAdata;
float HAdata;
float LBdata;
float HBdata;
float LGdata;
float MGdata;


int Counter = 0;

// ----------------------- Avarage Variables


float OldDdata = 0;
float OldTHdata = 0;
float OldLAdata = 0;
float OldHAdata = 0;
float OldLBdata = 0;
float OldHBdata = 0;
float OldLGdata = 0;
float OldMGdata = 0;

float SumDdata;
float SumTHdata;
float SumLAdata;
float SumHAdata;
float SumLBdata;
float SumHBdata;
float SumLGdata;
float SumMGdata;

float GlobalDdata;
float GlobalTHdata;
float GlobalLAdata;
float GlobalHAdata;
float GlobalLBdata;
float GlobalHBdata;
float GlobalLGdata;
float GlobalMGdata;

// -------------------------------- Constrain values and maping variable

float ConD;
float ConTH;
float ConLA;
float ConHA;
float ConLB;
float ConHB;
float ConLG;
float ConMG;

float MapConD;
float MapConTH;
float MapConLA;
float MapConHA;
float MapConLB;
float MapConHB;
float MapConLG;
float MapConMG;




float Max = 1000000.00;
float Min = 10000.00;
int Break = 5;


// -------------------------------  Spectrum Variable

float SP_1 = 1500000.0;
float SP_2 =  900000.0;
float SP_3 =  700000.0;
float SP_4 =  400000.0;
float SP_5 =  100000.0;
float SP_6 =    1000.0;



//----------------------------------  SETUP ----------------------------------



void setup() {
  // Start the hardware serial.
  Serial.begin(9600);

//---------------------------  First Run onf the system

  if (brain.update()) {

   // Counter++;

    Ddata = brain.readDelta();

    THdata = brain.readTheta();

    HAdata = brain.readHighAlpha();

    LAdata = brain.readLowAlpha();

    HBdata = brain.readHighBeta();

    LBdata = brain.readLowBeta();

    LGdata = brain.readLowGamma();

    MGdata = brain.readMidGamma();;
    

// --------- Constrain readings
 
 ConD= constrain(brain.readDelta(), Min,Max);
 ConTH = constrain(brain.readTheta(), Min,Max);
 ConLA = constrain(brain.readLowAlpha(), Min,Max);
 ConHA = constrain(brain.readHighAlpha(), Min,Max);
 ConLB = constrain(brain.readLowBeta(), Min,Max);
 ConHB = constrain(brain.readHighBeta(), Min,Max);
 ConLG = constrain(brain.readLowGamma(), Min, Max);
 ConMG = constrain(brain.readMidGamma(), Min,Max);


 
MapConD= map(ConD,Min,Max,10.0,1000.0);
MapConTH= map(ConTH,Min,Max,10.0,1000.0);
MapConLA= map(ConLA,Min,Max,10.0,1000.0);
MapConHA= map(ConHA,Min,Max,10.0,1000.0);
MapConLB= map(ConLB,Min,Max,10.0,1000.0);
MapConHB= map(ConHB,Min,Max,10.0,1000.0);
MapConLG= map(ConLG,Min,Max,10.0,1000.0);
MapConMG= map(ConMG,Min,Max,10.0,1000.0);


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

// -----------------------   Storing The sum of the values

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


//------------------------------------- LOOP ------------------------------------------

void loop() {

  // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
  // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"

  if (brain.update()) {

    Counter++;
float Random = random(0.0, 100000.00);

    Ddata = brain.readDelta();
   
    THdata = brain.readTheta();

    HAdata = brain.readHighAlpha();

    LAdata = brain.readLowAlpha();

    HBdata = brain.readHighBeta();

    LBdata = brain.readLowBeta();

    LGdata = brain.readLowGamma();

    MGdata = brain.readMidGamma();;




// ------------------------------- Intereaction

if(brain.readDelta()> SP_1) &&  (brain.readTheta()> SP_1){
  

  
}
// --------- Constrain readings
 
 ConD= constrain(brain.readDelta(), Min,Max);
 ConTH = constrain(brain.readTheta(), Min,Max);
 ConLA = constrain(brain.readLowAlpha(), Min,Max);
 ConHA = constrain(brain.readHighAlpha(), Min,Max);
 ConLB = constrain(brain.readLowBeta(), Min,Max);
 ConHB = constrain(brain.readHighBeta(), Min,Max);
 ConLG = constrain(brain.readLowGamma(), Min, Max);
 ConMG = constrain(brain.readMidGamma(), Min,Max);


 
MapConD= map(ConD,Min,Max,10.0,1000.0);
MapConTH= map(ConTH,Min,Max,10.0,1000.0);
MapConLA= map(ConLA,Min,Max,10.0,1000.0);
MapConHA= map(ConHA,Min,Max,10.0,1000.0);
MapConLB= map(ConLB,Min,Max,10.0,1000.0);
MapConHB= map(ConHB,Min,Max,10.0,1000.0);
MapConLG= map(ConLG,Min,Max,10.0,1000.0);
MapConMG= map(ConMG,Min,Max,10.0,1000.0);
 
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
    
}
