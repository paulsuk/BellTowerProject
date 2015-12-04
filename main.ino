#include "pitches.h"

// set pin numbers:
#define buttonPin1 3     // the number of the pushbutton pin
#define buttonPin2 5     // the number of the pushbutton pin
#define buttonPin3 6     // the number of the pushbutton pin       

#define SpeakerPin1 8     // the number of the pushbutton pin

#define echoPin 12 // Ultrasound signal pin
#define trigPin 13 


// variables will change:
int button1 = LOW;        // variable for reading the pushbutton status
int button2 = LOW;        // variable for reading the pushbutton status
int button3 = LOW;        // variable for reading the pushbutton status
unsigned long x = 0;         // variable for reading the pushbutton status

// Writing the Melodies

  int deck_len = 68;
  int deck[] = {
    NG4, NF4, NE4, ND4, NC4, ND4, NE4, NC4, ND4, NE4, NF4, ND4, NE4, ND4, NC4, NB3, NC4,
    NG4, NF4, NE4, ND4, NC4, ND4, NE4, NC4, ND4, NE4, NF4, ND4, NE4, ND4, NC4, NB3, NC4,
    ND4, NE4, NF4, ND4, NE4, NF4, NG4, ND4, NE4, NF4, NG4, NA4, NB4, NC5, NB4, NA4, NG4,
    NG4, NF4, NE4, ND4, NC4, ND4, NE4, NC4, NA4, NA4, NA4, NA4, NG4, NF4, NE4, ND4, NC4
  };
  int deck_dur[] = {
    3, 8, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8, 3, 8, 4, 4, 2,
    3, 8, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8, 3, 8, 4, 4, 2,
    3, 8, 4, 4, 3, 8, 4, 4, 8, 8, 4, 8, 8, 4, 4, 4, 2,
    3, 8, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8, 3, 8, 4, 4, 2
  };
  
  int snow_len = 65;
  int snow[] = {
    NG4, NG4, NG5, NG5, NF5, NE5, ND5, NC5, NG4,
    NG4, NG4, ND5, NC5, ND5, NC5, NB4, NG4,
    NA4, NA5, NA5, NG5, NF5, NE5, ND5,
    NB5, NA5, NG5, NG5, NF5, NE5, NE5, ND5, NC5,
    NG4, NG5, NG5, NF5, NE5, ND5, NC5, NG4,
    NG4, NG4, ND5, NC5, ND5, NC5, NB4, NG4,
    NA4, NA5, NA5, NG5, NF5, NE5, ND5,
    NB5, NA5, NG5, NG5, NF5, NE5, NE5, ND5, NC5
  };
  int snow_dur[] = {
    8, 8, 8, 8, 4, 4, 4, 4, 2,
    8, 8, 3, 8, 3, 8, 4, 2, 
    4, 8, 8, 4, 4, 4, 1.5,
    8, 8, 4, 8, 8, 4, 8, 8, 1.8,
    4, 8, 8, 4, 4, 4, 4, 2,
    8, 8, 3, 8, 3, 8, 4, 2, 
    4, 8, 8, 4, 4, 4, 2,
    8, 8, 4, 8, 8, 4, 8, 8, 1.8
  };

  int jingle_len = 111;
  int jingle[] = {
    NG4, NG4, NG4, NE5, ND5, NC5, NG4, NG4, NG4, NG4, NE5, ND5, NC5, NA4, 0, NA4, NB4, NF5, NE5, ND5, NB4, 0, NB4, NG5, NG5, NF5, ND5, NE5,
    NG4, NG4, NG4, NE5, ND5, NC5, NG4, NG4, NG4, NG4, NE5, ND5, NC5, NA4, 0, NA4, NB4, NF5, NE5, ND5, NG5, NG5, NG5, NG5, NA5, NG5, NF5, ND5, NC5,
    NG5, NE5, NE5, NE5, NE5, NE5, NE5, NE5, NG5, NC5, ND5, NE5, 0, NF5, NF5, NF5, NF5, NF5, NE5, NE5, NE5, NE5, NE5, ND5, ND5, NE5, ND5,
    NG5, NE5, NE5, NE5, NE5, NE5, NE5, NE5, NG5, NC5, ND5, NE5, 0, NF5, NF5, NF5, NF5, NF5, NE5,NE5 , NE5, NE5, NG5, NG5, NF5, ND5, NC5
  };
   
  int jingle_dur[] = { 
    8, 8, 4, 4, 4, 4, 1.9, 8, 8, 4, 4, 4, 4, 1.9, 8, 8, 4, 4, 4, 4, 1.9, 8, 8, 4, 4, 4, 4, 1.6, //28
    8, 8, 4, 4, 4, 4, 1.9, 8, 8, 4, 4, 4, 4, 1.9, 8, 8, 4, 4, 4, 4, 4, 4, 3, 8, 4, 4, 4, 4, 1.8, //29
    4, 4, 4, 2, 4, 4, 2, 4, 4, 3, 8, 1.8, 4, 4, 4, 3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 2,    //27
    2, 4, 4, 2, 4, 4, 2, 4, 4, 3, 8, 1.8, 4, 4, 4, 3, 8, 4, 4, 4, 8, 8, 4, 4, 4, 4, 1.5  //27
  };

  int cena_len = 12;
  int cena[] = {
    0, NG5, NAS5, NF5, 0, NG5,  
    0, NAS5, NA5, NF5, 0, NG5    
  };
  int cena_dur[] = {
    9, 4.5, 5.5, 5.5, 9, 1,
    9, 4.5, 5.5, 5.5, 9, 1  
  };

  
  
void setup() {
  // initialize the LED pin as an output:
  pinMode(SpeakerPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
};

int activate() {
  button1 = digitalRead(buttonPin1);
  button2 = digitalRead(buttonPin2);
  button3 = digitalRead(buttonPin3);
  x = ping();
  int temp = 0;
  if (button1 == HIGH) {
    temp = 1;
  }
  
  else if (button2 == HIGH) {
    temp = 2;
  }

  else if (button3 == HIGH){
    temp = 3;
  }
  else if ( x < 5){
    temp = 4;
  };
  return temp;
}

void loop() {
  // read the state of the pushbutton value: 
  int temp1 = activate();
  switch(temp1){
    case 1:
      let_it_snow();
      break;
    case 2:
      deck_the_halls();
      break;
    case 3:
      jingle_bells();
      break;
    case 4:
      the_time_is_now();
    default:
      delay(50);
      break;
  }
  delay(50);
};


void deck_the_halls(){
  for (int thisNote = 0; thisNote < deck_len; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / deck_dur[thisNote];
      tone(SpeakerPin1, deck[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(SpeakerPin1);
  };
};


void let_it_snow(){
  for (int thisNote = 0; thisNote < snow_len; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / snow_dur[thisNote];
      tone(SpeakerPin1, snow[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(SpeakerPin1);
  };
};

void jingle_bells(){
  for (int thisNote = 0; thisNote < jingle_len; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / jingle_dur[thisNote];
      tone(SpeakerPin1, jingle[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(SpeakerPin1);
  };
};

void the_time_is_now(){
  for (int thisNote = 0; thisNote < cena_len; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / cena_dur[thisNote];
      tone(SpeakerPin1, cena[thisNote], noteDuration);
        
      // to distinguish the notes, set a minimum time between them.
      int pauseBetweenNotes = noteDuration * 1.2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(SpeakerPin1);
  };
};


unsigned long ping(){
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
};
  
