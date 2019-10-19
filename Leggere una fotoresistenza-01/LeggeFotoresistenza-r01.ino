// Programma per la definizione della condizione di Giorno/Notte attraverso la lettura
// di una fotoresistena collegata ad un ingresso analogico

//La condizione iniziale è che sia Notte.

// Il programma comprende il modulo per la comunicazione seriale dei valori letti.
// Il modulo si attiva e disattiva con il flag Monitor che ammette i valori true e false

#define Monitor false

//Ricordate che nella definizione delle costanti non va messo il segno uguale fra 
//il nome simbolico e il valore e non va messo il punto e virgola a fine riga

// Il valore assegnato alla costante Tp1 è 0
//perchè io ho usato per le prove l'ingresso analogico 0 
#define Tp1 0 
#define LEDNotte 13
#define LEDGiorno 10

//Associo ad una costante la velocità di comunicazione della porta seriale
#define  VelocitaPortaSeriale 9600

//Ritardo fra una lettura e la successiva espresso in millesimi di secondo
#define ADCDelay 500

int ADCCount = 0; //Creo e inizializzo la variabile di appoggio per la lettura dell'ADC

#define SogliaGiornoNotte 100
#define SogliaNotteGiorno 150
byte GiornoNotte = 0;//0 = NOTTE - 1 = GIORNO

void setup()
{
  pinMode(LEDNotte, OUTPUT);
  digitalWrite(LEDNotte, HIGH);
  pinMode(LEDGiorno, OUTPUT);
  if (Monitor == true)
  {
    Serial.begin(VelocitaPortaSeriale);
  }
//Per semplificare il programma ho scelto di omettere il controllo della seriale
}

void loop()
{
  ADCCount = analogRead(Tp1); //leggo il Tp1 e metto il risultato in ADCCount
  if (GiornoNotte==1 & ADCCount < SogliaGiornoNotte)
  {
    GiornoNotte = 0;//è diventato NOTTE
    digitalWrite(LEDNotte, HIGH);
    digitalWrite(LEDGiorno, LOW);
  }
  if (GiornoNotte==0 & ADCCount > SogliaNotteGiorno)
  {
    GiornoNotte = 1;
    digitalWrite(LEDNotte, LOW);
    digitalWrite(LEDGiorno, HIGH);
  }
  
  if(Monitor == true)
  {
    Serial.print("Lettura in COUNT ");//mando sulla seriale l'inizio della riga 
    Serial.println(ADCCount);//mando sulla seriale il valore letto e vado a capo
  }

  delay(ADCDelay);//aspetto prima di ripetere il ciclo
}
