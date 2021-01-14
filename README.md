# Projekt_VU_meter

<h2> Opis projektu </h2>

Układ ma za zadanie zapalać poszczególne diody - od zielonych do czerwonych, w zależności od wykrytego poziomu sgnału audio z wyjścia laptopa.

Ma to na celu pokazanie poziomu wysterownia sygnału jaki mamy na wyjściu jack 3,5mm w laptopie. Dzieki tej informacji jesteśmy w stanie tak dopasować sygnał wyjściowy, aby podany sygnał adudio np. na pramap wzmacniacza nie był przesterowany co zapobiegnie dalszemu zniekształceniu. sygnału.

Things needed to make this LED vu meter using arduino:-

<ul>


<li> 1x  breadboard </li>
<li> 12x 5mm LEDs </li>
<li> 12x 100 ohm resistors </li>
<li> 1x  Arduino UNO/nano </li>
<li> 1x  3.5mm headphone jack </li>
<li> 1x  10k potentiometer </li>
<li> 1x  audio splitter (optional) </li>
<li> breadboard connector </li>
</ul>

![Tekst Alternatywny](D:\Studia\Technika_Mikroprocesorowa\V_semestr\Projekt_VU_Meter\20210109_183951.jpg "Opcjonalny tytul")

```

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

```

Poniżej zamieszczam link do swojego dysku google, gdzie znaduję się krótki filmik przedstawiajacy działanie mojego układu.

https://drive.google.com/drive/folders/1gcG673Rvffiad0akWI7Ypqfu3KhraC6r?usp=sharing
