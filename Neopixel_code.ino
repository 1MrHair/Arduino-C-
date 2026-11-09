#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS      5 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 2; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int looop = 1;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  looop = looop + 1;
  for (int i=0; i < 255; i++){
    if(looop == 2){redColor = i;}
    if(looop == 3){greenColor = i; redColor--;}
    if(looop == 4){blueColor = i; greenColor--;}
    
    for (int i=0; i < NUMPIXELS; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

      // This sends the updated pixel color to the hardware.
      pixels.show();

      // Delay for a period of time (in milliseconds).
      delay(delayval);
    }
    Serial.println(looop);
  }
  
}

// setColor()
// picks random values to set for RGB
void setColor(int x,int y,int z){
  redColor = x;
  greenColor = y;
  blueColor = z;
}
