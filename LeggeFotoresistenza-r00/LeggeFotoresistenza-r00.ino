// Programma per la lettura di una fotoresistena tramite un ingresso analogico

//Ricordate che nella definizione delle costanti non va messo il segno uguale fra 
//il nome simbolico e il valore e non va messo il punto e virgola a fine riga

// Il valore assegnato alla costante Tp1 è 0
//perchè io ho usato per le prove l'ingresso analogico 0 
#define Tp1 0 

//Associo ad una costante la velocità di comunicazione della porta seriale
#define  VelocitaPortaSeriale 9600

//Ritardo fra una lettura e la successiva espresso in millesimi di secondo
#define ADCDelay 500

int ADCCount = 0; //Creo e inizializzo la variabile di appoggio per la lettura dell'ADC

void setup()
{
  Serial.begin(VelocitaPortaSeriale);
//Per semplificare il programma ho scelto di omettere il controllo della seriale
}

void loop()
{
  ADCCount = analogRead(Tp1); //leggo il Tp1 e metto il risultato in ADCCount
  Serial.print("Lettura in COUNT ");//mando sulla seriale l'inizio della riga 
  Serial.println(ADCCount);//mando sulla seriale il valore letto e vado a capo

  delay(ADCDelay);//aspetto prima di ripetere il ciclo
}
