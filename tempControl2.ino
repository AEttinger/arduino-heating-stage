#include <PID_v1.h>

#define SERIESRESISTOR 10000
#define NUMSAMPLES 5
#define TSETMIN 30
#define TSETMAX 45
#define THERMISTOR_1 A0
#define THERMISTOR_2 A1
#define POTPIN_1 A2
#define POTPIN_2 A3
#define MOSFET_1 5
#define MOSFET_2 6


// thermistor table
int samples[NUMSAMPLES];
int temp[105] = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5};
int res[105] = {699,720,741,764,787,811,836,862,888,916,945,974,1005,1037,1070,1105,1141,1178,1216,1256,1298,1341,1385,1432,1480,1530,1582,1637,1693,1752,1813,1876,1942,2011,2082,2157,2234,2315,2399,2487,2579,2674,2773,2877,2985,3098,3216,3339,3467,3601,3741,3887,4040,4200,4367,4542,4724,4916,5116,5325,5544,5774,6014,6266,6530,6807,7097,7402,7721,8056,8408,8777,9165,9572,10000,10450,10923,11420,11943,12493,13073,13682,14324,15001,15714,16465,17257,18092,18973,19903,20885,21921,23016,24172,25395,26687,28054,29500,31031,32651,34366,36184,38110,40151,42317};


// potentiometer reading
int pot_1, pot_2;

// variables for pid adaptive tuning
double tempset_1, tempset_2, temp_1, temp_2, output_1, output_2; 

// values for pid tuning agg = aggressive mode, cons = conservative mode
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

// specify links for peltier control
PID peltier_1_PID(&temp_1, &output_1, &tempset_1, consKp, consKi, consKd, DIRECT);
PID peltier_2_PID(&temp_2, &output_2, &tempset_2, consKp, consKi, consKd, DIRECT);

void setup(void) {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  analogReference(EXTERNAL);

  // initialize 
  tempset_1 = getSetpoint(POTPIN_1);
  tempset_2 = getSetpoint(POTPIN_2);

  // for testing without potentiometer
  // tempset_1 = 32;
  // tempset_2 = 32;
  
  temp_1 = getTemp(THERMISTOR_1);
  temp_2 = getTemp(THERMISTOR_2);

  peltier_1_PID.SetMode(AUTOMATIC);
  peltier_2_PID.SetMode(AUTOMATIC);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read input (temperature)
  temp_1 = getTemp(THERMISTOR_1);
  temp_2 = getTemp(THERMISTOR_2);

  // read setpoint (potentiometer) - comment out for testing without potentiometer
  tempset_1 = getSetpoint(POTPIN_1);
  tempset_2 = getSetpoint(POTPIN_2);

  // get potentiometer values - for testing
  int pot_a2 = analogRead(POTPIN_1);
  int pot_a3 = analogRead(POTPIN_2);
  /*
  Serial.print("Read value Pot A2 = ");
  Serial.println(pot_a2);
  
  Serial.print("Setpoint Pot A2 = ");
  Serial.println(tempset_1);
  
  Serial.print("Read value Pot A3 = ");
  Serial.println(pot_a3);

  Serial.print("Setpoint Pot A3 = ");
  Serial.println(tempset_2); 
  */

  // set parameters for peltier 1
  double gap_1 = abs(tempset_1 - temp_1); 

  if(gap_1 < 3){
    peltier_1_PID.SetTunings(consKp, consKi, consKd);
  } else {
    peltier_1_PID.SetTunings(aggKp, aggKi, aggKd);
  }
  peltier_1_PID.Compute();

  //set parameters for peltier 2
  double gap_2 = abs(tempset_2 - temp_2);

  if(gap_2 < 3){
    peltier_2_PID.SetTunings(consKp, consKi, consKd);
  } else {
    peltier_2_PID.SetTunings(aggKp, aggKi, aggKd);
  }
  peltier_2_PID.Compute();
  
  analogWrite(MOSFET_1, output_1);
  analogWrite(MOSFET_2, output_2);
  
  /*
  Serial.print("Temperature 1 ");
  Serial.println(temp_1);

  Serial.print("Temperature 2 ");
  Serial.println(temp_2);
  */

  delay(1000);
  
}

double getTemp(int Thermistor) {
  uint8_t i;
  float average;
  int current_temp;
  
  for(i=0; i<NUMSAMPLES; i++) {
    samples[i] = analogRead(Thermistor);
    delay(10);
  }
  
  average = 0;

  for(i=0; i<NUMSAMPLES; i++) {
    average += samples[i];
  }

  average /= NUMSAMPLES;

  //Serial.print("Average analog reading ");
  //Serial.println(average);

  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;

  //Serial.print("Thermistor resistance ");
  //Serial.println(average);

  int r = 104;
  int l = 0;
  int m;

  while(l<=r) {    
    m = int(floor(float(r + l)/2));

      if((r-m < 2) && (m-l < 2)) {
        if((abs(float(res[m]) - average) < abs(float(res[l]) - average)) && (abs(float(res[m]) - average) < abs(float(res[r]) - average))) {
          current_temp = temp[m];
        } else if(abs(float(res[l]) - average) < abs(float(res[r]) - average)) {
          current_temp = temp[l];
        } else {
          current_temp = temp[r];
        }
        break;
    }

    if(float(res[m]) > average) {
      r = m - 1;
    } else if(float(res[m]) < average) {
      l = m + 1;
    } 
     
  }

  return current_temp;
}

double getSetpoint(int Potentiometer) {
  int potval;
  double setpoint;
  
  potval = analogRead(Potentiometer);
  setpoint = TSETMIN + (double(potval) / 1023 * (TSETMAX - TSETMIN));
  return setpoint;
}


