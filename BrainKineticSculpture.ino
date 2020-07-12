
#define CONSTRAIN_HIGH 3000000
#define CONSTRAIN_LOW 1000

#define NUM_READINGS 10

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


unsigned long Ddata_prom;
unsigned long THdata_prom;
unsigned long LAdata_prom;
unsigned long HAdata_prom;
unsigned long LBdata_prom;
unsigned long HBdata_prom;
unsigned long LGdata_prom;
unsigned long MGdata_prom;

unsigned long Ddata_Map;
unsigned long THdata_Map;
unsigned long LAdata_Map;
unsigned long HAdata_Map;
unsigned long LBdata_Map;
unsigned long HBdata_Map;
unsigned long LGdata_Map;
unsigned long MGdata_Map;


unsigned long Ddata_Map2;
unsigned long THdata_Map2;
unsigned long LAdata_Map2;
unsigned long HAdata_Map2;
unsigned long LBdata_Map2;
unsigned long HBdata_Map2;
unsigned long LGdata_Map2;
unsigned long MGdata_Map2;

unsigned long Ddata_New;
unsigned long THdata_New;
unsigned long LAdata_New;
unsigned long HAdata_New;
unsigned long LBdata_New;
unsigned long HBdata_New;
unsigned long LGdata_New;
unsigned long MGdata_New;

unsigned long New_Ddata_prom[NUM_READINGS];
unsigned long New_THdata_prom[NUM_READINGS];
unsigned long New_LAdata_prom[NUM_READINGS];
unsigned long New_HAdata_prom[NUM_READINGS];
unsigned long New_LBdata_prom[NUM_READINGS];
unsigned long New_HBdata_prom[NUM_READINGS];
unsigned long New_LGdata_prom[NUM_READINGS];
unsigned long New_MGdata_prom[NUM_READINGS];

unsigned long Ddata_Min = 0xFFFFFFFF;
unsigned long THdata_Min = 0xFFFFFFFF;
unsigned long LAdata_Min = 0xFFFFFFFF;
unsigned long HAdata_Min = 0xFFFFFFFF;
unsigned long LBdata_Min = 0xFFFFFFFF;
unsigned long HBdata_Min = 0xFFFFFFFF;
unsigned long LGdata_Min = 0xFFFFFFFF;
unsigned long MGdata_Min = 0xFFFFFFFF;


unsigned long Ddata_Max = 0;
unsigned long THdata_Max = 0;
unsigned long LAdata_Max = 0;
unsigned long HAdata_Max = 0;
unsigned long LBdata_Max = 0;
unsigned long HBdata_Max = 0;
unsigned long LGdata_Max = 0;
unsigned long MGdata_Max = 0;

unsigned long Ddata_Min2 = 0xFFFFFFFF;
unsigned long THdata_Min2 = 0xFFFFFFFF;
unsigned long LAdata_Min2 = 0xFFFFFFFF;
unsigned long HAdata_Min2 = 0xFFFFFFFF;
unsigned long LBdata_Min2 = 0xFFFFFFFF;
unsigned long HBdata_Min2 = 0xFFFFFFFF;
unsigned long LGdata_Min2 = 0xFFFFFFFF;
unsigned long MGdata_Min2 = 0xFFFFFFFF;


unsigned long Ddata_Max2 = 0;
unsigned long THdata_Max2 = 0;
unsigned long LAdata_Max2 = 0;
unsigned long HAdata_Max2 = 0;
unsigned long LBdata_Max2 = 0;
unsigned long HBdata_Max2 = 0;
unsigned long LGdata_Max2 = 0;
unsigned long MGdata_Max2 = 0;

int counterD;
int counterTH;
int counterLA;
int counterHA;
int counterLB;
int counterHB;
int counterLG;
int counterMG;

//------------------------------------- SETUP ------------------------------------------

void setup() {
  // Start the hardware serial.
  Serial.begin(9600);

}


//------------------------------------- LOOP ------------------------------------------

void loop() {
  float positions[8];



  if (brain.update()) {

    Ddata_idx = 0;
    THdata_idx = 0;
    LAdata_idx = 0;
    HAdata_idx = 0;
    LBdata_idx = 0;
    HBdata_idx = 0;
    LGdata_idx = 0;
    MGdata_idx = 0;

    if (Ddata_idx == NUM_READINGS ) {
      Ddata_idx = 0;

    }
    if ( THdata_idx == NUM_READINGS) {
      THdata_idx = 0;

    }
    if (LAdata_idx == NUM_READINGS) {
      LAdata_idx = 0;

    }
    if (HAdata_idx == NUM_READINGS) {
      HAdata_idx = 0;

    }
    if (LBdata == NUM_READINGS) {
      LBdata_idx = 0;

    }
    if (HBdata_idx == NUM_READINGS) {
      HBdata_idx = 0;

    }
    if (LGdata_idx == NUM_READINGS) {
      LGdata_idx = 0;

    }
    if (MGdata_idx == NUM_READINGS) {
      MGdata_idx = 0;

    }

    Ddata[Ddata_idx] = brain.readDelta();
    THdata[THdata_idx] = brain.readTheta();
    LAdata[LAdata_idx] = brain.readLowAlpha();
    HAdata[HAdata_idx] = brain.readHighAlpha();
    LBdata[LBdata_idx] = brain.readLowBeta();
    HBdata[HBdata_idx] = brain.readHighBeta();
    LGdata[LGdata_idx] = brain.readLowGamma();
    MGdata[MGdata_idx] = brain.readMidGamma();


    if (Ddata[Ddata_idx] < Ddata_Min) Ddata_Min = Ddata[Ddata_idx];
    if (Ddata[Ddata_idx] > Ddata_Max) Ddata_Max = Ddata[Ddata_idx];
    Ddata_Min = constrain (Ddata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    Ddata_Max = constrain (Ddata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);

    if (THdata[THdata_idx] < THdata_Min) THdata_Min = THdata[THdata_idx];
    if (THdata[THdata_idx] > THdata_Max) THdata_Max = THdata[THdata_idx];
    THdata_Min = constrain (THdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    THdata_Max = constrain (THdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);


    if (LAdata[LAdata_idx] < LAdata_Min) LAdata_Min = LAdata[LAdata_idx];
    if (LAdata[LAdata_idx] > LAdata_Max) LAdata_Max = LAdata[LAdata_idx];
    LAdata_Min = constrain (LAdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    LAdata_Max = constrain (LAdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);


    if (HAdata[HAdata_idx] < HAdata_Min) HAdata_Min = HAdata[HAdata_idx];
    if (HAdata[HAdata_idx] > HAdata_Max) HAdata_Max = HAdata[HAdata_idx];
    HAdata_Min = constrain (HAdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    HAdata_Max = constrain (HAdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);


    if (LBdata[LBdata_idx] < LBdata_Min) LBdata_Min = LBdata[LBdata_idx];
    if (LBdata[LBdata_idx] > LBdata_Max) LBdata_Max = LBdata[LBdata_idx];
    LBdata_Min = constrain (LBdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    LBdata_Max = constrain (LBdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);


    if (HBdata[HBdata_idx] < HBdata_Min) HBdata_Min = HBdata[HBdata_idx];
    if (HBdata[HBdata_idx] > HBdata_Max) HBdata_Max = HBdata[HBdata_idx];
    HBdata_Min = constrain (HBdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    HBdata_Max = constrain (HBdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);

    if (LGdata[LGdata_idx] < LGdata_Min) LGdata_Min = LGdata[LGdata_idx];
    if (LGdata[LGdata_idx] > LGdata_Max) LGdata_Max = LGdata[LGdata_idx];
    LGdata_Min = constrain (LGdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    LGdata_Max = constrain (LGdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);


    if (MGdata[MGdata_idx] < MGdata_Min) MGdata_Min = MGdata[MGdata_idx];
    if (MGdata[MGdata_idx] > MGdata_Max) MGdata_Max = MGdata[MGdata_idx];
    MGdata_Min = constrain (MGdata_Min, CONSTRAIN_LOW, CONSTRAIN_HIGH);
    MGdata_Max = constrain (MGdata_Max, CONSTRAIN_LOW, CONSTRAIN_HIGH);

    Ddata_idx++;
    THdata_idx++;
    LAdata_idx++;
    HAdata_idx++;
    LBdata_idx++;
    HBdata_idx++;
    LGdata_idx++;
    MGdata_idx++;

    Ddata_avg = 0;
    THdata_avg = 0;
    LAdata_avg = 0;
    HAdata_avg = 0;
    LBdata_avg = 0;
    HBdata_avg = 0;
    LGdata_avg = 0;
    MGdata_avg = 0;

    for (int i = 0; i < NUM_READINGS; i++) {
      Ddata_avg += New_Ddata_prom[i];
      THdata_avg += New_THdata_prom[i];
      LAdata_avg +=  New_LAdata_prom[i];
      HAdata_avg +=  New_HAdata_prom[i];
      LBdata_avg +=  New_LBdata_prom[i];
      HBdata_avg +=  New_HBdata_prom[i];
      LGdata_avg +=  New_LGdata_prom[i];
      MGdata_avg +=  New_MGdata_prom[i];
    }

    Ddata_prom = Ddata_avg / NUM_READINGS;
    THdata_prom = THdata_avg / NUM_READINGS;
    LAdata_prom = LAdata_avg / NUM_READINGS;
    HAdata_prom = HAdata_avg / NUM_READINGS;
    LBdata_prom = LBdata_avg / NUM_READINGS;
    HBdata_prom = HBdata_avg / NUM_READINGS;
    LGdata_prom = LGdata_avg / NUM_READINGS;
    MGdata_prom = MGdata_avg / NUM_READINGS;


    Ddata_New  = brain.readDelta();
    THdata_New = brain.readTheta();
    LAdata_New = brain.readLowAlpha();
    HAdata_New = brain.readHighAlpha();
    LBdata_New = brain.readLowBeta();
    HBdata_New = brain.readHighBeta();
    LGdata_New = brain.readLowGamma();
    MGdata_New = brain.readMidGamma();


    Ddata_Map = map(Ddata_New, Ddata_Min, Ddata_Max, 100, 1000);
    THdata_Map = map(THdata_New, THdata_Min, THdata_Max, 100, 1000);
    LAdata_Map = map(LAdata_New, LAdata_Min, LAdata_Max, 100, 1000);
    HAdata_Map = map(HAdata_New, HAdata_Min, HAdata_Max, 100, 1000);
    LBdata_Map = map(LBdata_New, LBdata_Min, LBdata_Max, 100, 1000);
    HBdata_Map = map(HBdata_New, HBdata_Min, HBdata_Max, 100, 1000);
    LGdata_Map = map(LGdata_New, LGdata_Min, LGdata_Max, 100, 1000);
    MGdata_Map = map(MGdata_New, MGdata_Min, MGdata_Max, 100, 1000);

    Ddata_Map = constrain(Ddata_Map, 100, 1000);
    THdata_Map = constrain(THdata_Map, 100, 1000);
    LAdata_Map = constrain(LAdata_Map, 100, 1000);
    HAdata_Map = constrain(HAdata_Map, 100, 1000);
    LBdata_Map = constrain(LBdata_Map, 100, 1000);
    HBdata_Map = constrain(HBdata_Map, 100, 1000);
    LGdata_Map = constrain(LGdata_Map, 100, 1000);
    MGdata_Map = constrain(MGdata_Map, 100, 1000);

    if (Ddata_Map < Ddata_Min2) Ddata_Min2 = Ddata_Map;
    if (Ddata_Map > Ddata_Max2) Ddata_Max2 = Ddata_Map;
    if (Ddata_Max2 > 1000 ) Ddata_Max2 = 0;
    if (Ddata_Min2 < 10 ) Ddata_Min = 0xFFFFFFFF;

    if (THdata_Map < THdata_Min2) THdata_Min2 = THdata_Map;
    if (THdata_Map > THdata_Max2) THdata_Max2 = THdata_Map;
    if (THdata_Max2 > 1000 ) THdata_Max2 = 0;
    if (THdata_Min2 < 10 ) THdata_Min = 0xFFFFFFFF;

    if (LAdata_Map < LAdata_Min2) LAdata_Min2 = LAdata_Map;
    if (LAdata_Map > LAdata_Max2) LAdata_Max2 = LAdata_Map;
    if (LAdata_Max2 > 1000 ) LAdata_Max2 = 0;
    if (LAdata_Min2 < 10 ) LAdata_Min = 0xFFFFFFFF;

    if (HAdata_Map < HAdata_Min2) HAdata_Min2 = HAdata_Map;
    if (HAdata_Map > HAdata_Max2) HAdata_Max2 = HAdata_Map;
    if (HAdata_Max2 > 1000 ) HAdata_Max2 = 0;
    if (HAdata_Min2 < 10 ) HAdata_Min = 0xFFFFFFFF;

    if (LBdata_Map < LBdata_Min2) LBdata_Min2 = LBdata_Map;
    if (LBdata_Map > LBdata_Max2) LBdata_Max2 = LBdata_Map;
    if (LBdata_Max2 > 1000 ) LBdata_Max2 = 0;
    if (LBdata_Min2 < 10 ) LBdata_Min = 0xFFFFFFFF;

    if (HBdata_Map < HBdata_Min2) HBdata_Min2 = HBdata_Map;
    if (HBdata_Map > HBdata_Max2) HBdata_Max2 = HBdata_Map;
    if (HBdata_Max2 > 1000 ) HBdata_Max2 = 0;
    if (HBdata_Min2 < 10 ) HBdata_Min = 0xFFFFFFFF;


    if (LGdata_Map < LGdata_Min2) LGdata_Min2 = LGdata_Map;
    if (LGdata_Map > LGdata_Max2) LGdata_Max2 = LGdata_Map;
    if (LGdata_Max2 > 1000 ) LGdata_Max2 = 0;
    if (LGdata_Min2 < 10 ) LGdata_Min = 0xFFFFFFFF;

    if (MGdata_Map < MGdata_Min2) MGdata_Min2 = MGdata_Map;
    if (MGdata_Map > MGdata_Max2) MGdata_Max2 = MGdata_Map;
    if (MGdata_Max2 > 1000 ) MGdata_Max2 = 0;
    if (MGdata_Min2 < 10 ) MGdata_Min = 0xFFFFFFFF;


    Ddata_Map2 = map(Ddata_Map, Ddata_Min2, Ddata_Max2, 10, 100);
    positions[0] = Ddata_Map2;

    THdata_Map2 = map(THdata_Map, THdata_Min2, THdata_Max2, 100, 19000);
    positions[1] = THdata_Map2;
    
      LAdata_Map2 = map(LAdata_Map, LAdata_Min2, LAdata_Max2, 100, 19000);
    positions[2] = LAdata_Map2;
    
      HAdata_Map2 = map(HAdata_Map, HAdata_Min2, HAdata_Max2, 100, 19000);
    positions[3] = HAdata_Map2;
      
      LBdata_Map2 = map(LBdata_Map, LBdata_Min2, LBdata_Max2, 100, 19000);
    positions[4] = LBdata_Map2;
      
      HBdata_Map2 = map(HBdata_Map, HBdata_Min2, HBdata_Max2, 100, 19000);
    positions[5] = HBdata_Map2;
      
      LGdata_Map2 = map(LGdata_Map, LGdata_Min2, LGdata_Max2, 100, 19000);
    positions[6] = LGdata_Map2;
      
      MGdata_Map2 = map(MGdata_Map, MGdata_Min2, MGdata_Max2, 100, 19000);
    positions[7] = MGdata_Map2;

    for (int i=0; i<8; i++){
      Serial.print("Enviando a la posicion: ");
      Serial.println(positions[i]);
      delay(1000);
    }


    New_Ddata_prom[Ddata_idx] = Ddata_Map2;
    New_THdata_prom[THdata_idx] = THdata_Map2;
    New_LAdata_prom[LAdata_idx] = LAdata_Map2;
    New_HAdata_prom[HAdata_idx] = HAdata_Map2;
    New_LBdata_prom[LBdata_idx] = LBdata_Map2;
    New_HBdata_prom[HBdata_idx] = HBdata_Map2;
    New_LGdata_prom[LGdata_idx] = LGdata_Map2;
    New_MGdata_prom[MGdata_idx] = MGdata_Map2;


    Serial.print(brain.readSignalQuality());
    Serial.print(" - ");

    Serial.print(brain.readMeditation());
    Serial.print(" - ");

    Serial.print(brain.readAttention());
    Serial.print(" - ");

    Serial.print(Ddata_Map2);
    Serial.print(",");

    Serial.print(Ddata_prom);
    Serial.print(" - ");

    Serial.print(THdata_Map2);
    Serial.print(",");
    Serial.print(THdata_prom);
    Serial.print(" - ");

    Serial.print(LAdata_Map2);
    Serial.print(",");
    Serial.print(LAdata_prom);
    Serial.print(" - ");

    Serial.print(HAdata_Map2);
    Serial.print(",");
    Serial.print(HAdata_prom);
    Serial.print("  -  ");

    Serial.print(LBdata_Map2);
    Serial.print(",");
    Serial.print(LBdata_prom);
    Serial.print("  -  ");

    Serial.print(HBdata_Map2);
    Serial.print(",");
    Serial.print(HBdata_prom);
    Serial.print("  -  ");

    Serial.print(LGdata_Map2);
    Serial.print(",");
    Serial.print(LGdata_prom);
    Serial.print("  -  ");

    Serial.print(MGdata_Map2);
    Serial.print(",");
    Serial.println(MGdata_prom);




  }


}
