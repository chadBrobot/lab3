 //Arduino PWM Speed Control：
int lm_pin = 5;   //PWM on M2
int lm_dir = 4;   //direction control on M2
int rm_pin = 6;   //PWM for M1
int rm_dir = 7;   //direction control for M1 

/*left turn sppeds*/
//int l_speed = 128; 
//int r_speed = 100;
/*right turn sppeds*/
int l_speed = 89; 
int r_speed = 78;
int goFor = 2100;

//encoders for wheel turn counting
int l_enc = 20; 
int r_enc = 21;

volatile byte state = LOW;
/*
unsigned long previousMillis = 0;    
unsigned long startMillis = millis();    
int count = 0;
const long interval2 = 1500; */

void setup() {
    pinMode(lm_dir, OUTPUT);
    pinMode(rm_dir, OUTPUT);
    pinMode(l_enc, INPUT);
    //pinMode(r_enc, INPUT);
    Serial.begin(9600);
    volatile byte state = LOW;
    attachInterrupt(digitalPinToInterrupt(l_enc), blink, RISING);
    
    //previousMillis = 0; 
    //startMillis = millis();
    //count = 0;
    //delay(3000); //to get set up   
}

void release(int motor){
  analogWrite(motor, 0);
  }

void forward(int motor_dir, int motor_pin, int speedy){
  digitalWrite(motor_dir,HIGH);
  analogWrite(motor_pin, speedy);
  }

void backward(int motor_dir, int motor_pin, int speedy){
  digitalWrite(motor_dir,LOW);
  analogWrite(motor_pin, speedy);
  }

void left90(){
  //the 90 degree turn to the left
  int l_speed90 = 128; 
  int r_speed90 = 100;
  forward(rm_dir, rm_pin, r_speed90);
  backward(lm_dir, lm_pin, l_speed90);
  delay(435);
  backward(rm_dir, rm_pin, r_speed90);
  forward(lm_dir, lm_pin, l_speed90);
  delay(40);
  release(lm_pin);
  release(rm_pin);
  delay(2000);
  }

void right90(){
  int l_speed90 = 117; 
  int r_speed90 = 98;
  //the 90 degree turn to the right
  backward(rm_dir, rm_pin, r_speed90);
  forward(lm_dir, lm_pin, l_speed90);
  delay(455);
  forward(rm_dir, rm_pin, r_speed90);
  backward(lm_dir, lm_pin, l_speed90);
  delay(40);
  release(lm_pin);
  release(rm_pin);
  delay(2000);
}

void blink(){
  Serial.println(state);
  if(state  == LOW){
    state = HIGH;
    Serial.println(state);
  }
  else{
    state = LOW;
    Serial.println(state);
  }
}

void loop(){
  //digitalRead(l_enc);
  //unsigned long currentMillis = millis(); 
  int x=digitalRead(l_enc);
  delay(20);
  Serial.println(x);
  /*
  if (currentMillis - startMillis <= interval) {
    Serial.println(currentMillis - startMillis);
  forward(lm_dir, lm_pin, l_speed);
  forward(rm_dir, rm_pin, r_speed);
  int x = digitalRead(line); 
   if (currentMillis - previousMillis >= interval2) {
    previousMillis = currentMillis;
  
  }*/
}
  
