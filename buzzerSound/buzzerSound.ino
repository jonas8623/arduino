#include "notas.h"

const int sound = 5;
const int ledPin = 6;

// Grade Time
const int semiBrief = 2000; // semibreve - 4 tempos
const int minimum = 1000; // minima - 2 tempos
const int quarterNote = 500; // semiminima - 1 tempo
const int eighthNote = 250; // colcheia - 1/2 tempo
const int sixteenthNote = 125; // semi colcheia - 1/4 tempo

const int pauseSound = 125;
int rhythm = 4;

int music[] = {
    NOTE_C4,NOTE_C4,
    NOTE_D4,NOTE_C4,NOTE_F4,
    NOTE_E4,NOTE_C4,NOTE_C4,
    NOTE_D4,NOTE_C4,NOTE_G4,
    NOTE_F4,NOTE_C4,NOTE_F4,
    NOTE_C5,NOTE_A4,NOTE_F4,
    NOTE_E4,NOTE_D4,NOTE_AS4,NOTE_AS4,
    NOTE_A4,NOTE_F4,NOTE_G4,
    NOTE_F4
  };

int durations[] = {
    sixteenthNote,sixteenthNote,
    semiBrief,semiBrief,semiBrief,
    minimum,sixteenthNote,sixteenthNote,
    semiBrief,semiBrief,semiBrief,
    minimum,sixteenthNote,sixteenthNote,
    semiBrief,semiBrief,semiBrief,
    semiBrief,semiBrief,sixteenthNote,sixteenthNote,
    semiBrief,semiBrief,semiBrief,
    minimum
  };
  
void setup() {
  pinMode(sound, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  happyBirthday();

}

void happyBirthday()
{
  for(int musicalNote = 0; musicalNote <(sizeof(music)/sizeof (int)); musicalNote++) {
    int durationNote = durations[musicalNote]/rhythm;
    tone(sound, music[musicalNote], durationNote);
    delay(durationNote * 1.1);
    noTone(sound);
  }
  delay(5000);
}
