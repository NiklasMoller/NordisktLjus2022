// Include the Neopixel library
#include <Adafruit_NeoPixel.h>

//------------- NEOPIXEL --------------------
// Declare and initialise global GPIO pin constant for Neopixel ring
const byte neoPin = 11;

// Declare and initialise global constant for number of pixels
const byte neoPixels = 24;

// Declare and initialise variable for Neopixel brightness
byte neoBright = 100;

// Create new Neopixel ring object
Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB);

//------------- DISTANCE SENSOR --------------------
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

void setup() {
  //------------- NEOPIXEL
    // Initialise the ring
  ring.begin();
  ring.setBrightness(neoBright); 
  ring.show();

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  //Buttons
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  //DISYANCE SENSOR
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  

  //NEOPIXEL
  // put your main code here, to run repeatedly:
  // Turn on pixels
  for(int i = 0; i < neoPixels; i++){   
    ring.setPixelColor(i, ring.Color(0,255,0));
    ring.show();
    delay(distance);
  }

  // Turn off pixels
  for(int i = 0; i < neoPixels; i++){
    ring.setPixelColor(i, ring.Color(0,0,0));
    ring.show();
    delay(distance);
  }

/*
  int redButton = digitalRead(4);
  int greenButton = digitalRead(5);
  int blueButton = digitalRead(6);


  if (redButton == HIGH) {
    Serial.println("RED BUTTON PRESSED");
  } else {
    Serial.println("RED BUTTON NOT PRESSED");
  }
*/
}
