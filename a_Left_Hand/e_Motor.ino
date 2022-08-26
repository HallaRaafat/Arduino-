void S_Left ()

   {
    digitalWrite (In2,LOW);
    digitalWrite (In1,LOW); 
    digitalWrite (In4,LOW);
    digitalWrite (In3,HIGH); 
    analogWrite (enA,0)  ;
    analogWrite (enB, RotSpeed)  ;   }
    
  void S_Right ()
  
{ 
  
  
  digitalWrite (In4,LOW);
    digitalWrite (In3,LOW); 
    digitalWrite (In2,LOW);
    digitalWrite (In1,HIGH); 
    analogWrite (enB,0)  ;
    analogWrite (enA, RotSpeed)  ;  }
  


void Left ()
{
  
    digitalWrite (In2,HIGH);
    digitalWrite (In1,LOW); 
    digitalWrite (In4,LOW);
    digitalWrite (In3,HIGH); 
    analogWrite (enA,RotSpeed)  ;
    analogWrite (enB, RotSpeed)  ;}
void STR ()
{
  colorsensor();
 
   digitalWrite (In1,HIGH);
    digitalWrite (In2,LOW); 
    digitalWrite (In3,HIGH);
    digitalWrite (In4,LOW); 
    analogWrite (enA,mspeed)  ;
    analogWrite (enB, mspeed)  ;
    }

    void Return ()
{
 
   digitalWrite (In1,LOW);
    digitalWrite (In2,HIGH); 
    digitalWrite (In3,HIGH);
    digitalWrite (In4,LOW); 
    analogWrite (enA,RotSpeed)  ;
    analogWrite (enB, RotSpeed)  ;   }
void Right ()
{ 
  //Serial.println("R");
  digitalWrite (In1,HIGH);
    digitalWrite (In2,LOW); 
    digitalWrite (In3,LOW);
    digitalWrite (In4,HIGH); 
    analogWrite (enA,RotSpeed+n)  ;
    analogWrite (enB, RotSpeed+n)  ;}
void Back ()
{
  digitalWrite (In2,HIGH);
    digitalWrite (In1,LOW); 
    digitalWrite (In4,HIGH);
    digitalWrite (In3,LOW); 
    analogWrite (enA,RotSpeed)  ;
    analogWrite (enB, RotSpeed)  ;
  }
void STP ()
{  
   digitalWrite (In1,LOW);
    digitalWrite (In2,LOW); 
    digitalWrite (In3,LOW);
    digitalWrite (In4,LOW); 
    analogWrite (enA,0)  ;
    analogWrite (enB, 0)  ; 
  }
