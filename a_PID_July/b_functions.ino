 void readEncoderX ()
{
  if (digitalRead(Enc_A_X)==HIGH)
       { if (digitalRead(Enc_B_X)==HIGH) counterX++;
            else counterX--;
       }
  else {
    if (digitalRead(Enc_A_X)==LOW)
        { if (digitalRead(Enc_B_X)==HIGH) counterX--;
            else counterX++;
        }
      }
  
  
  
 }

 void readEncoderY ()
{
  if (digitalRead(Enc_A_Y)==HIGH)
       { if (digitalRead(Enc_B_Y)==HIGH) counterY++;
            else counterY--;
       }
  else {
    if (digitalRead(Enc_A_Y)==LOW)
        { if (digitalRead(Enc_B_Y)==HIGH) counterY--;
            else counterY++;
        }
      }
  
  
  
 }

 void StepsX ()
{
 
       if (digitalRead(DirX)==HIGH) SetpointX--;
            else SetpointX++;
 }

 void StepsY ()
{
      if (digitalRead(DirY)==HIGH) SetpointY--;
            else SetpointY++;

 }

  
 
 
 
 void Servo_On()
  { // 13 UNO gives High when down so because of pull up when the limitz== 1 aka not touched then keep servo down one step extra 
    if (digitalRead(Servo_In)==1)
     {
      while (digitalRead(LimitZ)!=0) // =0 trig !0 do
          { 
            ServoZ.write(Servo_i);
            Servo_i++;
            delay(10);
            
           }
      
       ServoZ.write(Servo_i);
      }
   else { Servo_i=0;
          ServoZ.write(Servo_i);
    
        }
      
   }


  void ForwardX(int s)
    {
     digitalWrite(In4,HIGH);
     digitalWrite(In3,LOW);
     analogWrite(PWMX,s);
    }

  void BackwardX(int s)
  {

    digitalWrite(In3,HIGH);
     digitalWrite(In4,LOW);
     analogWrite(PWMX,s);
    
    }
  void StopX()
  {digitalWrite(In2,LOW);
     digitalWrite(In1,LOW);
     analogWrite(PWMX,0);}


  void ForwardY(int s)
    {digitalWrite(In1,HIGH);
     digitalWrite(In2,LOW);
     analogWrite(PWMY,s);
     
    }

  void BackwardY(int s)
  {digitalWrite(In2,HIGH);
     digitalWrite(In1,LOW);
     analogWrite(PWMY,s);
    
    
    }
  void StopY()
  {digitalWrite(In2,LOW);
     digitalWrite(In1,LOW);
     analogWrite(PWMY,0);}


 void doPID ()
 {
  
   interrupts();
   
  PID_X.Compute();
  PID_Y.Compute();
  
  if (abs(ErrorX) < DeadBW_X) // If the motor X is in position within the deadband width (acceptable error)
    {
     StopX(); // Turn off the X motor
    }
  else
    {
        if (OutputX>0)
            ForwardX(abs(int(OutputX)));

        else 
            BackwardX(abs(int(OutputX)));
      
    }
  if (abs(ErrorY) < DeadBW_Y) // If the motor Y is in position within the deadband width (acceptable error)
    {
      StopY(); // Turn off the Y motor
    }
  else
    {   
      if (OutputY>0)
            ForwardY(abs(int(OutputY)));

        else 
            BackwardY(abs(int(OutputY)));
     
    }

  
  
  
  
   
  
  
  
  }
