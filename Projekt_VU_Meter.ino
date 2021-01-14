
int music = A0;
int output,a;
int potval=A1;
int number_of_led[12] = { 2,3,4,5,6,7,8,9,10,11,12,13};
void setup()
{
for (a = 0; a < 12; a++)  
  pinMode(number_of_led[a], OUTPUT);
}

void loop()
{
potval=analogRead(A1);
output = analogRead(music);
potval=map (potval,0,1024,5,40);
output = output/potval;   

  if (output == 0) 
   {
   for(a = 0; a < 12; a++)
     {
     digitalWrite(number_of_led[a], LOW);
     }
  }
  
  else
  {
   for (a = 0; a < output; a++)
    {
     digitalWrite(number_of_led[a], HIGH);
    }
    
    for(a = a; a < 12; a++) 
     {
      digitalWrite(number_of_led[a], LOW);
    
     }
  }
}
