# Projekt_VU_meter

<h2> Opis projektu </h2>

Układ ma za zadanie zapalać poszczególne diody - od zielonych do czerwonych, w zależności od wykrytego poziomu sgnału audio z wyjścia laptopa.

Ma to na celu pokazanie poziomu wysterownia sygnału jaki mamy na wyjściu jack 3,5mm w laptopie. Dzieki tej informacji jesteśmy w stanie tak dopasować sygnał wyjściowy, aby podany sygnał adudio np. na pramap wzmacniacza nie był przesterowany co zapobiegnie dalszemu zniekształceniu. sygnału.

<h2> Wykaz elementów </h2>

<ul>
<li> 1x  płyta testowa (umażliwijąca budawanie układu) </li>
<li> 12x 5mm LED </li>
<li> 12x 100 ohm rezystorów </li>
<li> 1x  Arduino UNO/nano </li>
<li> 1x  3.5mm przewód jack </li>
<li> 1x  10k potencjometr </li>
<li> 1x  rozdzielacz audio (opcjonalnie) </li>
<li> kabelki połączeniowe </li>
</ul>
<h2> Zdjęcia wykonanego układu </h2>

![20210109_183951](https://user-images.githubusercontent.com/75728467/104597755-02522680-5676-11eb-8acb-8ece2e487958.jpg)
![20210109_183957](https://user-images.githubusercontent.com/75728467/104597774-09793480-5676-11eb-9966-06defcba2363.jpg)
![20210109_184009](https://user-images.githubusercontent.com/75728467/104597777-0bdb8e80-5676-11eb-9504-1d598935cb39.jpg)

<h2> Kod programu wraz z opisem</h2>

```

int music = A0; // podanie sygnału analogowwego (muzyki) z laptopa na wejście A0 w płytce arduino
int output,a;
int potval=A1; // podanie wartości potencjometru na wejście A1 płytki arduino
int number_of_led[12] = { 2,3,4,5,6,7,8,9,10,11,12,13}; //przypisanie diod do wyjść z płytki arduino
void setup()
{
for (a = 0; a < 12; a++)
  pinMode(number_of_led[a], OUTPUT); //podanie wartości poszczególnych diod led i przypisanie do poszczególnych wyjść
}

void loop()
{
potval=analogRead(A1); // odczytanie wartości z potencjometru
output = analogRead(music); // odczyt muzyki z wejścia układu
potval=map (potval,0,1024,5,40); // przypisanie wartości sygnału audio na wyjście układu
output = output/potval;   

  if (output == 0) 
   {
   for(a = 0; a < 12; a++)
     {
     digitalWrite(number_of_led[a], LOW); // określernie stanu niskiego
     }
  }
  
  else
  {
   for (a = 0; a < output; a++)
    {
     digitalWrite(number_of_led[a], HIGH); // określenie stanu wysokiego
    }
    
    for(a = a; a < 12; a++) 
     {
      digitalWrite(number_of_led[a], LOW); // określenie stanu nieskiego kiedy sygnał nie jest podawany na wejście
    
     }
  }
}

```
<h2> Film </h2>

Poniżej zamieszczam link do swojego dysku google, gdzie znaduję się krótki filmik przedstawiajacy działanie mojego układu.

https://drive.google.com/file/d/1g1DYNkjh7ZzsLNGmBUaozhyz18oAGui6/view?usp=sharing

<h2> Podsumowanie </h2>

Realizując powyższy układ jesteśmy w stanie kontrolować poziom wyjściowy sygnału wyjściowego ze źródła. Umożliwia nam to jego odpowieniednie dopsowanie do danego urządzenia, aby uniknąć podawania zbyt niskiego lub wysokiego poziomu sygnału.
Unikamy również przesterowywania sygnału tzn. zjawiska (jeśli sygnał mu ulegnie) zniekształcenia sygnału, co po podaniu go np. na wzmacniacz audio spowoduje wzmocnienie zniekształóceń, co będzie dl nas słyszalne.
Kolory diod nie zostały dobrane przypadkowao - zielone pokazują prawidłową wartość sygnału - bezpieczną dla urządzeń wejściowych. Żółte diody to wartości graniczne - sygnał jest an granicy zniekształcenia oraz diody czerwone - zapalające się wtedy kiedy wartość sygnału jest zbyt wysoka i kiedy ulega on zniekształceniu.
