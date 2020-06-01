
#define CONSTRAIN_HIGH 100
#define CONSTRAIN_LOW 10
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
    if( THdata_idx == NUM_READINGS){
       THdata_idx = 0;
       }
    if(LAdata_idx == NUM_READINGS){
       LAdata_idx=0;
      } 
    if (HAdata_idx == NUM_READINGS){
       HAdata_idx = 0;
      }
    if(LBdata == NUM_READINGS){
      LBdata_idx=0;
      }
    if(HBdata_idx == NUM_READINGS){
      HBdata_idx =0;
      }
    if(LGdata_idx == NUM_READINGS){
      LGdata_idx = 0;
      }
    if(MGdata_idx == NUM_READINGS){
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
           
   
    Serial.print(constrain((Ddata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((THdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((LAdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((HAdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((LBdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((HBdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.print(constrain((LGdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    Serial.print(" , ");
    Serial.println(constrain((MGdata_avg / NUM_READINGS), CONSTRAIN_LOW, CONSTRAIN_HIGH));
    
     }


}
