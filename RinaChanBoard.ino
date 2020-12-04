#include <ezButton.h>
#include <FastLED.h>
#include <array>
#define NUM_LEDS 256 //4*8*8 BOARDS
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0]))) //why this works as a def micro but not a function, I do not know.
CRGB leds[NUM_LEDS];

int EYES_BLINK[] = {33,29,28,27,26,230,221,220,219,218,/*99,100,101,102,103,162,163,164,92,155,84,85,86,87,146,147*/};
int EYES_CONTENT[] = {30,125,124,27,220,187,186,217};
int EYES_SMILE[] = {46,34,35,29,28,125,124,114,115,233,228,229,219,218,187,186,180,181};
int EYES_UWU[] {47,46,34,35,27,125,124,112,113,183,182,187,186,220,228,229,233,232};
int EYES_O[] {34,35,30,29,27,126,125,124,123,114,115,228,229,220,218,217,188,187,186,185,180,181};

int MOUTH_CONTENT[] = {93,83,75,74,73,72,141,140,148,154};
int MOUTH_SMILE[] = {91,90,89,88,84,74,73,72,141,147,157,156};
int MOUTH_UWU[] {84,74,73,72,141,147};
int MOUTH_O[] {105,104,101,162,91,156,85,146,73,72};

int eyeSelect = 0;
int eyeCurrent = 0;
int mouthSelect = 0;
int mouthCurrent = 0;

int eyeButtonState = 0;
int mouthButtonState = 0;
int confirmButtonState = 0;
int eyeButtonLastState = 0;
int mouthButtonLastState = 0;
int confirmButtonLastState = 0;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
bool blinking = false;

//Consts. Customize these according to the pins your buttons and LED data are on, how sensitive to deboundce your buttons are,
//and how long you want Rina to go between blink (and how long those blinks should last!)
const unsigned long blinkPeriod = 5000;  //the value is a number of milliseconds
const unsigned long blinkLength = 500;
const int eyePin = 3;
const int mouthPin = 5;
const int confirmPin = 6; // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int debounceTime = 50;

ezButton eyeButton(eyePin);
ezButton mouthButton(mouthPin);
ezButton confirmButton(confirmPin);

//the boards zigzag
//layout is like this:
//15,14,13,12,11,10,9,8
//0,1,2,3,4,5,6,7
//with all the labels on the board rightside up.
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 7>(leds, NUM_LEDS);
  pinMode(ledPin, OUTPUT);    
  eyeButton.setDebounceTime(debounceTime);
  mouthButton.setDebounceTime(debounceTime);
  confirmButton.setDebounceTime(debounceTime);  
  updateFace();
  startMillis = millis(); 
}

void clearFace() {
  for (int i = 0; i < NUM_LEDS ; i++) {
    leds[i] = CRGB::Black ;
  }
}

void lightFace(int face[]) {
  int length = 0;
}

void lightFace(int face[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    leds[face[i]] = CRGB::DeepPink;
    leds[face[i]].fadeLightBy(32);
  }
  FastLED.show();
}

void updateEyes(){
  switch(eyeCurrent){    
    case 1:
      changeFace(EYES_SMILE, ARRAY_SIZE(EYES_SMILE));
      break;
    case 2:
      changeFace(EYES_UWU, ARRAY_SIZE(EYES_UWU));
      break;
    case 3:
      changeFace(EYES_O, ARRAY_SIZE(EYES_O));
      break;
    default:
      changeFace(EYES_CONTENT, ARRAY_SIZE(EYES_CONTENT));
      break;
  }
  delay(25);
}
void updateMouth(){
  switch(mouthCurrent){    
    case 1:
      changeFace(MOUTH_SMILE, ARRAY_SIZE(MOUTH_SMILE));
      break;
    case 2:
      changeFace(MOUTH_UWU, ARRAY_SIZE(MOUTH_UWU));
      break;  
    case 3:
      changeFace(MOUTH_O, ARRAY_SIZE(MOUTH_O));
      break;
    default:
      changeFace(MOUTH_CONTENT, ARRAY_SIZE(MOUTH_CONTENT));
      break;
  }
  delay(25);
}

void updateFace(){
  clearFace();
  updateEyes();
  updateMouth();  
}

void changeFace(int face[], int faceSize) {
  lightFace(face, faceSize);
}

void loop() {
  eyeButton.loop();
  mouthButton.loop();
  confirmButton.loop();
  eyeButtonState = eyeButton.getState();
  mouthButtonState = mouthButton.getState();
  confirmButtonState = confirmButton.getState();
  
  if (eyeButtonLastState != eyeButtonState){
    if (eyeButtonState == HIGH){
      eyeSelect++;
    }
    eyeButtonLastState = eyeButtonState;
  }
  if (mouthButtonLastState != mouthButtonState){
    if (mouthButtonState == HIGH){
      mouthSelect++;
    }
    mouthButtonLastState = mouthButtonState;
  }

  if (confirmButtonLastState != confirmButtonState){  
    if (confirmButtonState == HIGH){
      eyeCurrent = eyeSelect;
      mouthCurrent = mouthSelect;
      eyeSelect = 0;
      mouthSelect = 0;
      updateFace();
    }
    confirmButtonLastState = confirmButtonState;
    startMillis = millis(); 
  } else {
    //only blink if we haven't just changed.
    currentMillis = millis(); 
    if (blinking) {
      if (currentMillis - startMillis >= blinkLength){
        updateFace();
        startMillis = currentMillis;
        blinking = false;
      }
    } else if (currentMillis - startMillis >= blinkPeriod)
    {
      clearFace();
      changeFace(EYES_BLINK, ARRAY_SIZE(EYES_BLINK));
      delay(25);
      updateMouth(); //keep mouth in place!
      startMillis = currentMillis;
      blinking = true;
    }
  }
}
