
#define CONSTRAIN_HIGH 3000000
#define CONSTRAIN_LOW 1000
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

unsigned long Ddata_Min = CONSTRAIN_HIGH;
unsigned long THdata_Min = CONSTRAIN_HIGH;
unsigned long LAdata_Min = CONSTRAIN_HIGH;
unsigned long HAdata_Min = CONSTRAIN_HIGH;
unsigned long LBdata_Min = CONSTRAIN_HIGH;
unsigned long HBdata_Min = CONSTRAIN_HIGH;
unsigned long LGdata_Min = CONSTRAIN_HIGH;
unsigned long MGdata_Min = CONSTRAIN_HIGH;


unsigned long Ddata_Max = CONSTRAIN_LOW;
unsigned long THdata_Max = CONSTRAIN_LOW;
unsigned long LAdata_Max = CONSTRAIN_LOW;
unsigned long HAdata_Max = CONSTRAIN_LOW;
unsigned long LBdata_Max = CONSTRAIN_LOW;
unsigned long HBdata_Max = CONSTRAIN_LOW;
unsigned long LGdata_Max = CONSTRAIN_LOW;
unsigned long MGdata_Max = CONSTRAIN_LOW;

int counterD;
int counterTH;
int counterLA;
int counterHA;
int counterLB;
int counterHB;
int counterLG;
int counterMG;

int minimum = 0;

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


    //Actualizamos mínimo y máximo de Delta y constreñimos
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




    Ddata_prom = Ddata_avg / NUM_READINGS;
    THdata_prom = THdata_avg / NUM_READINGS;
    LAdata_prom = LAdata_avg / NUM_READINGS;
    HAdata_prom = HAdata_avg / NUM_READINGS;
    LBdata_prom = LBdata_avg / NUM_READINGS;
    HBdata_prom = HBdata_avg / NUM_READINGS;
    LGdata_prom = LGdata_avg / NUM_READINGS;
    MGdata_prom = MGdata_avg / NUM_READINGS;



    Ddata_Map = map(Ddata_prom, Ddata_Min, Ddata_Max, 0, 10);
    THdata_Map = map(THdata_prom, THdata_Min, THdata_Max, 0, 10);
    LAdata_Map = map(LAdata_prom, LAdata_Min, LAdata_Max, 0, 10);
    HAdata_Map = map(HAdata_prom, HAdata_Min, HAdata_Max, 0, 10);
    LBdata_Map = map(LBdata_prom, LBdata_Min, LBdata_Max, 0, 10);
    HBdata_Map = map(HBdata_prom, HBdata_Min, HBdata_Max, 0, 10);
    LGdata_Map = map(LGdata_prom, LGdata_Min, LGdata_Max, 0, 10);
    MGdata_Map = map(MGdata_prom, MGdata_Min, MGdata_Max, 0, 10);



    Counter();


    Serial.print(Ddata_Map);
    Serial.print(" , ");
    Serial.print(Ddata_Min);
    Serial.print(" , ");
    Serial.print(Ddata_Max);
    Serial.print(" - ");
    Serial.print(THdata_Map);
    Serial.print(" , ");
    Serial.print(THdata_Min);
    Serial.print(" , ");
    Serial.print(THdata_Max);
    Serial.print(" - ");
    Serial.print(LAdata_Map);
    Serial.print(" , ");
    Serial.print(LAdata_Min);
    Serial.print(" , ");
    Serial.print(LAdata_Max);
    Serial.print(" - ");
    Serial.print(HAdata_Map);
    Serial.print(" , ");
    Serial.print(HAdata_Min);
    Serial.print(" , ");
    Serial.print(HAdata_Max);
    Serial.print(" - ");
    Serial.print(LBdata_Map);
    Serial.print(" , ");
    Serial.print(LBdata_Min);
    Serial.print(" , ");
    Serial.print(LBdata_Max);
    Serial.print(" - ");
    Serial.print(HBdata_Map);
    Serial.print(" , ");
    Serial.print(HBdata_Min);
    Serial.print(" , ");
    Serial.print(HBdata_Max);
    Serial.print(" - ");
    Serial.print(LGdata_Map);
    Serial.print(" , ");
    Serial.print(LGdata_Min);
    Serial.print(" , ");
    Serial.print(LGdata_Max);
    Serial.print(" - ");
    Serial.print(MGdata_Map);
    Serial.print(" , ");
    Serial.print(MGdata_Min);
    Serial.print(" , ");
    Serial.println(MGdata_Max);
    
        
    //    Serial.print(Ddata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterD);
    //    Serial.print(" , ");
    //    Serial.print(THdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterTH);
    //    Serial.print(" , ");
    //    Serial.print(LAdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterLA);
    //    Serial.print(" , ");
    //    Serial.print(HAdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterHA);
    //    Serial.print(" , ");
    //    Serial.print(LBdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterLB);
    //    Serial.print(" , ");
    //    Serial.print(HBdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterHB);
    //    Serial.print(" , ");
    //    Serial.print(LGdata_Map);
    //    Serial.print(" , ");
    //    Serial.print(counterLG);
    //    Serial.print(" , ");
    //    Serial.print(MGdata_Map);
    //    Serial.print(" , ");
    //    Serial.println(counterMG);



    Ddata_New = Ddata_Map;
    THdata_New = THdata_Map;
    LAdata_New = LAdata_Map;
    HAdata_New = HAdata_Map ;
    LBdata_New = LBdata_Map;
    HBdata_New = HBdata_Map;
    LGdata_New = LGdata_Map ;
    MGdata_New = MGdata_Map;


    //
    //New_Ddata_prom = Ddata_prom;
    //New_THdata_prom = THdata_prom;
    //New_LAdata_prom = LAdata_prom;
    //New_HAdata_prom = HAdata_prom;
    //New_LBdata_prom = LBdata_prom;
    //New_HBdata_prom = HBdata_prom;
    //New_LGdata_prom = LGdata_prom;
    //New_MGdata_prom = MGdata_prom;


  }


}



int Counter() {
  if (Ddata_Map < Ddata_New) counterD = 1;
  else if (Ddata_Map > Ddata_New) counterD = 2;

  if (THdata_Map < THdata_New) counterTH = 1;
  else if (THdata_Map > THdata_New) counterTH = 2;

  if (LAdata_Map < LAdata_New) counterLA = 1;
  else if (LAdata_Map > LAdata_New) counterLA = 2;

  if (HAdata_Map < HAdata_New) counterHA = 1;
  else if (HAdata_Map > HAdata_New) counterHA = 2;

  if (LBdata_Map < LBdata_New) counterLB = 1;
  else if (LBdata_Map > LBdata_New) counterLB = 2;

  if (HBdata_Map < HBdata_New) counterHB = 1;
  else if (HBdata_Map > HBdata_New) counterHB = 2;

  if (LGdata_Map < LGdata_New) counterLG = 1;
  else if (LGdata_Map > LGdata_New) counterLG = 2;

  if (MGdata_Map < MGdata_New) counterMG = 1;
  else if (MGdata_Map > MGdata_New) counterMG = 2;
}
