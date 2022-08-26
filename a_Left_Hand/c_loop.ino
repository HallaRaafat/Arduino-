void loop()
{ 

if (digitalRead(LT)==0) // Reads left 
 {
  if (((digitalRead(LT)==0)&&(digitalRead(SL)==0)&&(digitalRead(M)==0)&&(digitalRead(SR)==0)))
       {delay (200); // move a little longer 
       if ((digitalRead(LT)==0)&&(digitalRead(SL)==0)&&(digitalRead(M)==0)&&(digitalRead(SR)==0))
      {
        Serial.println("S");  
        STP();       // I moved and still read black in all of them then i reached final 
        }
       else
       {Serial.println("L");
        Left ();}      // means I was in T position so turn left 
       }
       else{ 
                  
    Serial.println("L");
        Left ();}
  }
 
 
else if (digitalRead(LT)==1)  // If left sensor reads white continue straight as long as the middle is black 
  { 
         if (digitalRead(M)==0)
            { 
             {Serial.println("F");
              STR();}
             }

            
    else if ((digitalRead(SL)==0))
              S_Left();                       /// the middle reads white ! then i deviated 
    else if( (digitalRead(SR)==0)||(digitalRead(M)==0))
              S_Right();          
    else   if  ((digitalRead(LT)==1)&&(digitalRead(SL)==1)&&(digitalRead(M)==1)&&(digitalRead(SR)==1))
    {
      
      if  ((digitalRead(LT)==1)&&(digitalRead(SL)==1)&&(digitalRead(M)==1)&&(digitalRead(SR)==1))
    {  do{
      Serial.println("R");
      Right();} while ((digitalRead(LT)==1)&&(digitalRead(SL)==1)&&(digitalRead(M)==1)&&(digitalRead(SR)==1));
    }
     }

  }

  


}
