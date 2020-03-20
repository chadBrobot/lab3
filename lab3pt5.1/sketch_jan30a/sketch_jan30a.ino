 //Arduino PWM Speed Control：
//Authors: Jack Casey Campbell and Breann Thiessen
#define lm_pin 5   //PWM on M2
#define lm_dir 4   //direction control on M2
#define rm_pin 6   //PWM for M1
#define rm_dir 7   //direction control for M1 

/*left turn sppeds*/
//#define l_speed 128
//#defineint r_speed 100
/*right turn sppeds*/
//#define l_speed 255
#define r_speed 255


//encoders for wheel turn counting
#define l_enc 44
#define r_enc 45

int oldx = digitalRead(r_enc); 
unsigned long previousMillis = 0;    
unsigned long startMillis = millis();

long interval = 5000;     
int count = 0;

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

void setup() {
    pinMode(lm_dir, OUTPUT);
    pinMode(rm_dir, OUTPUT);
    pinMode(l_enc, INPUT);
    pinMode(r_enc, INPUT);
    Serial.begin(115200); 

}

void loop() {
unsigned long currentMillis = millis();  
int x = digitalRead(r_enc);
if (currentMillis - startMillis <= interval) {
  
   forward(rm_dir, rm_pin, r_speed);
   //forward(lm_dir, lm_pin, l_speed);   
    
      if(x != oldx){
        if(x == 1){
          count++; 
          Serial.println(count); 
          }
          oldx = x;    
        }
          
 }
//}
else {

  release(lm_pin);
  release(rm_pin);
   
  while(1){ }
  }
}
