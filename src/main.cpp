#include <Arduino.h>


const int blueLedPin = 13;
const int yellowLedPin = 11;
const int greenLedPin = 10;
const int redLedPin = 9;

const int blueButtonPin = 7;
const int yellowButtonPin = 6;
const int greenButtonPin = 5;
const int redButtonPin = 4;

const int maxSize = 100;
int lightPatternArr[maxSize];
int roundNumber = 0;

void addValue(){
  int randInt = random(0, 4);
  lightPatternArr[roundNumber] = randInt;
}

void lightPatternFlash(){
  for (int i = 0; i < roundNumber + 1; i++){
    if (lightPatternArr[i] == 0){
      digitalWrite(blueLedPin, HIGH);
      delay(500);
      digitalWrite(blueLedPin, LOW);
      delay(500);
    }
    else if (lightPatternArr[i] == 1){
      digitalWrite(yellowLedPin, HIGH);
      delay(500);
      digitalWrite(yellowLedPin, HIGH);
      delay(500);
    }
    else if (lightPatternArr[i] == 2){
      digitalWrite(greenLedPin, HIGH);
      delay(500);
      digitalWrite(greenLedPin, HIGH);
      delay(500);
    }
    else {
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, HIGH);
      delay(500);
    }
  }
}

void incorrectButtonInput(){
  for(int i = 0; i < 4; i++){
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenButtonPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    delay(250);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenButtonPin, LOW);
    digitalWrite(redLedPin, LOW);
    delay(250);
  };
}

void userButtonPattern(){
  for (int i = 0; i < roundNumber + 1; i++){
    int currentLightFlash = lightPatternArr[i];
    if (digitalRead(blueButtonPin) == HIGH){
      if (currentLightFlash == 0){
        break;
      }
      else{
        incorrectButtonInput();
        
      }
      break;
    }
    else if (digitalRead(yellowButtonPin) == HIGH){
      if (currentLightFlash == 1){
        break;
      }
      else{
        //LOSE FUNCTION
      }
      break;
    } 
    else if (digitalRead(greenButtonPin) == HIGH){
      if (currentLightFlash == 2){
        break;
      }
      else{
        //LOSE FUNCTION
      }
      break;
    }
    else{
      if (currentLightFlash == 3){
        break;
      }
      else{
        //LOSE FUNCTION
      }
      break;
    }
  }
}


void setup() {
  pinMode(yellowLedPin, OUTPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(redButtonPin, INPUT);

  randomSeed(analogRead(3));

}

void loop() {

  addValue();
  lightPatternFlash();

  roundNumber += 1;
}





