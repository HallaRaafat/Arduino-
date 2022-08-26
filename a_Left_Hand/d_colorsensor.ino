void colorsensor () { // Calibration Color sensor for different speed 
     //Red
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(Out, LOW);

  R= map(frequency, 25,72,255,0);
  delay(50);

  //Green
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  frequency = pulseIn(Out, LOW);

  G = map(frequency, 30,90,255,0);

 
 
  delay(50);
//Blue
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 
  frequency = pulseIn(Out, LOW);

  B= map(frequency, 25,70,255,0);
  delay(50);
  
if (G>B && G>R)
 { if (G>0)mspeed=120; 
  else if (G<0) mspeed=160; }


  
else if (R>G && R>B)
mspeed=80;

else 

mspeed=80;





}
