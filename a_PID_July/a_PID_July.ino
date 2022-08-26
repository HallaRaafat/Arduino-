#include <FlexiTimer2.h>
#include <Servo.h>
#include <PID_v1.h>

volatile double counterX=0,counterY= 0;
volatile double SetpointX=0,SetpointY=0,OutputX=0,OutputY=0;
double ErrorX =0,ErrorY=0,DeadBW_X=5,DeadBW_Y=5;
#define Enc_A_X 3 // int 1 GREEENNNN
#define Enc_B_X 12   

#define Enc_A_Y 2 // int 0 // GREEEN 
#define Enc_B_Y 15


#define StepX  18 //int5  - uno 2
#define DirX   28 // UNO 5 

#define StepY  19 //4 UNO 3 
#define DirY   26 // UNO 6 



#define PWMY 11 // ENABLE A 
#define In1 10
#define In2 9

#define PWMX 6 // ENABLE B
#define In3 8
#define In4 7

#define LimitZ    13  // Pull up if ==0 then Triggered 
#define Servo_Out 4 // pwm for servo
#define Servo_In  14 // from 13 Uno

#define LimitX 32
#define LimitY 30 


float KpX=5,KiX=0.02,KdX=0.001;

float KpY=5,KiY=0.0,KdY=0;

int Servo_i=0;
int PWMX_Value=0;
int PWMY_Value=0;


float pos=0;

Servo ServoZ ;


PID PID_X(&counterX, &OutputX, &SetpointX, KpX, KiX, KdX, DIRECT);
PID PID_Y(&counterY, &OutputY, &SetpointY, KpY, KiY, KdY, DIRECT);

  /*   ForwardY(120);    
     if (pos!= counterY)
     {
       Serial.print("pos Y :");
       Serial.println(counterY);
      }
      */

void setup() {
  Serial.begin(9600);

  
  TCCR1B = TCCR1B & 0b11111000 | 1;//noise
  pinMode(Enc_A_X,INPUT_PULLUP);
  pinMode(Enc_B_X,INPUT_PULLUP);

  pinMode(Enc_A_Y,INPUT_PULLUP);
  pinMode(Enc_B_Y,INPUT_PULLUP);

  
  pinMode(PWMY,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  
  pinMode(PWMX,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);

pinMode(LimitZ ,INPUT_PULLUP);
pinMode(StepX,INPUT_PULLUP);
pinMode(DirX,INPUT_PULLUP);

pinMode(LimitX ,INPUT_PULLUP);
pinMode(LimitY ,INPUT_PULLUP);

pinMode(StepY,INPUT_PULLUP);  
pinMode(DirY,INPUT_PULLUP);  

 digitalWrite(PWMY,0);
 digitalWrite(In1,0);
 digitalWrite(In2,0);
  
 digitalWrite(PWMX,0);
 digitalWrite(In3,0);
 digitalWrite(In4,0);
 
 attachInterrupt(1,readEncoderX,CHANGE);
 attachInterrupt(0,readEncoderY,CHANGE);
 
 attachInterrupt(4,StepsY,RISING);
 attachInterrupt(5,StepsX,RISING);
 
  
 ServoZ.attach(Servo_Out);

  // Outpout PWM limits
  PID_X.SetOutputLimits(-255,255);
  PID_Y.SetOutputLimits(-255,255);
  
  // Compute output every 1ms
  PID_X.SetSampleTime(1);
  PID_Y.SetSampleTime(1);
  
  // Setup PID mode
  PID_X.SetMode(AUTOMATIC);
  PID_Y.SetMode(AUTOMATIC);
  
 FlexiTimer2::set(1, 1.0/1000, doPID);
 FlexiTimer2::start();
//SetpointY=720;
}
void loop() {
 // interrupts();
  Servo_On();
    ErrorX= SetpointX-counterX;
    ErrorY= SetpointY-counterY;

     Serial.print("pos Y :");
     Serial.println(counterY);  
    // Serial.print("outputt X :");
     Serial.println(OutputY);
 
        }
        
