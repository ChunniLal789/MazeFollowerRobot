
// the setup function runs once when you press reset or power the board
int LEFT_M1 = 5;
int LEFT_M2 = 6;
int RIGHT_M1 = 9;
int RIGHT_M2 = 10;

int IR_SENSOR_E_L= 2;   // EXTREME LEFT SENSOR
int IR_SENSOR1_L = 3;   // SENSOR AT LEFT OF MIDDLE ONE

int IR_SENSOR = 4;      // MIDDLE SENSOR

int IR_SENSOR1_R = 11;  // SENSOR AT RIGHT OF MIDDLE ONE
int IR_SENSOR_E_R = 12; // EXTREME RIGHT SENSOR

void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEFT_M1 , OUTPUT);
  pinMode(LEFT_M2 , OUTPUT);
  pinMode(RIGHT_M1, OUTPUT);
  pinMode(RIGHT_M2, OUTPUT);
  pinMode(IR_SENSOR_E_L, INPUT);
  pinMode(IR_SENSOR1_L, INPUT);
  pinMode(IR_SENSOR, INPUT);
  pinMode(IR_SENSOR1_R, INPUT);
  pinMode(IR_SENSOR_E_L, INPUT);
  Serial.begin(9600);
}

void loop() {
    int SEN_VAL = digitalRead(IR_SENSOR);
    int S1_L_VAL = digitalRead(IR_SENSOR1_L);
    int S1_R_VAL = digitalRead(IR_SENSOR1_R);
    int E_L_VAL = digitalRead(IR_SENSOR_E_L);
    int E_R_VAL = digitalRead(IR_SENSOR_E_R);
    
    if(SEN_VAL == 0 && S1_L_VAL == 0 && S1_R_VAL == 0 && E_L_VAL == 0 && E_R_VAL == 0){
    analogWrite(LEFT_M1, 0); 
    analogWrite(LEFT_M2, 120);
    analogWrite(RIGHT_M1, 120);
    analogWrite(RIGHT_M2, 0);
    delay(200);
    }
    else if(SEN_VAL == 1 && S1_L_VAL == 1 && S1_R_VAL == 1 && E_L_VAL == 1 && E_R_VAL == 1){
    analogWrite(LEFT_M1, 100);
    analogWrite(LEFT_M2, 0);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 150);
    }
    else if(SEN_VAL == 0 && S1_L_VAL == 1 && S1_R_VAL == 0 && E_L_VAL == 0 && E_R_VAL == 0){
    // SLIGHTLY OFF TRACK
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 50);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 100);
    }
    else if(SEN_VAL == 0 && S1_L_VAL == 0 && S1_R_VAL == 0 && E_L_VAL == 1 && E_R_VAL == 0){
    // SLIGHTLY OFF TRACK
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 30);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 100);
    }
    else if(SEN_VAL == 0 && S1_L_VAL == 0 && S1_R_VAL == 1 && E_L_VAL == 0 && E_R_VAL == 0){
    // SLIGHTLY OFF TRACK
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 100);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 50);
    }
    else if(SEN_VAL == 0 && S1_L_VAL == 0 && S1_R_VAL == 0 && E_L_VAL == 0 && E_R_VAL == 1){
    // SLIGHTLY OFF TRACK
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 100);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 30);
    }
    else if(SEN_VAL == 1 && S1_L_VAL == 1 && S1_R_VAL ==0  && E_L_VAL == 0 && E_R_VAL == 0){
    // CURVED PATH
    analogWrite(LEFT_M1, 100);
    analogWrite(LEFT_M2, 0);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 180);
    }
    else if(SEN_VAL == 1 && S1_L_VAL == 0 && S1_R_VAL == 1 && E_L_VAL == 0 && E_R_VAL == 0){
    // CURVED PATH
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 180);
    analogWrite(RIGHT_M1, 100);
    analogWrite(RIGHT_M2, 0);
    }
    else if((SEN_VAL == 1 && S1_L_VAL == 1 && S1_R_VAL == 0 && E_L_VAL == 1 && E_R_VAL == 0) || 
      (SEN_VAL == 1 && S1_L_VAL == 1 && S1_R_VAL == 1 && E_L_VAL == 1 && E_R_VAL == 0) || (SEN_VAL == 0 && S1_L_VAL == 1 && S1_R_VAL == 0 && E_L_VAL == 1 && E_R_VAL == 0)){
    analogWrite(LEFT_M1, 80);
    analogWrite(LEFT_M2, 0);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 150);
    }
    else if(SEN_VAL == 1 && S1_L_VAL == 0 && S1_R_VAL == 1 && E_L_VAL == 0 && E_R_VAL ==1 ){
      if(SEN_VAL == 1 && S1_L_VAL == 0 && S1_R_VAL == 0 && E_L_VAL == 0 && E_R_VAL ==0){
        analogWrite(LEFT_M1, 0);
        analogWrite(LEFT_M2, 100);
        analogWrite(RIGHT_M1, 0);
        analogWrite(RIGHT_M2, 100);
      }
     else{
        analogWrite(LEFT_M1, 0);
        analogWrite(LEFT_M2, 250);
        analogWrite(RIGHT_M1, 150);
        analogWrite(RIGHT_M2, 0);
      }
    }
    else{
    analogWrite(LEFT_M1, 0);
    analogWrite(LEFT_M2, 180);
    analogWrite(RIGHT_M1, 0);
    analogWrite(RIGHT_M2, 180);
    }

}
