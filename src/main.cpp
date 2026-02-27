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
      digitalWrite(yellowLedPin, LOW);
      delay(500);
    }
    else if (lightPatternArr[i] == 2){
      digitalWrite(greenLedPin, HIGH);
      delay(500);
      digitalWrite(greenLedPin, LOW);
      delay(500);
    }
    else {
      digitalWrite(redLedPin, HIGH);
      delay(500);
      digitalWrite(redLedPin, LOW);
      delay(500);
    }
  }
}

void incorrectButtonInput(){
  for(int i = 0; i < 4; i++){
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    delay(250);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    delay(250);
  };
}

int userLightFlashed(){
  while(true){
    if(digitalRead(blueButtonPin) == HIGH){
      while(digitalRead(blueButtonPin) == HIGH);
      return 0;
    }
    else if(digitalRead(yellowButtonPin) == HIGH){
      while(digitalRead(yellowButtonPin) == HIGH);
      return 1;
    }
    else if(digitalRead(greenButtonPin) == HIGH){
      while(digitalRead(greenButtonPin) == HIGH);
      return 2;
    }
    else if(digitalRead(redButtonPin) == HIGH){
      while(digitalRead(redButtonPin) == HIGH);
      return 3;
    }
  }
}

void lightUpLed(int buttonPressed){
  if(buttonPressed == 0){
    digitalWrite(blueLedPin, HIGH);
    delay(300);
    digitalWrite(blueLedPin, LOW);
  }
  else if(buttonPressed == 1){
    digitalWrite(yellowLedPin, HIGH);
    delay(300);
    digitalWrite(yellowLedPin, LOW);
  }
  else if(buttonPressed == 2){
    digitalWrite(greenLedPin, HIGH);
    delay(300);
    digitalWrite(greenLedPin, LOW);
  }
  else if(buttonPressed == 3){
    digitalWrite(redLedPin, HIGH);
    delay(300);
    digitalWrite(redLedPin, LOW);
  }
}

void resetGame(){
  incorrectButtonInput();
  roundNumber = -1;
  for(int i = 0; i < maxSize; i++){
    lightPatternArr[i] = 0;
  }
}

void turnOffLed(){
  digitalWrite(blueLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

void userButtonPattern(){
  for(int i = 0; i < roundNumber + 1; i++){
    int buttonPressed = userLightFlashed(); 
    lightUpLed(buttonPressed);

    if(buttonPressed != lightPatternArr[i]){
      resetGame();
      return;
    };
    delay(300);
    turnOffLed();
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
}

void loop() {
  delay(1500);
  addValue();
  lightPatternFlash();
  userButtonPattern();

  roundNumber += 1;
}





