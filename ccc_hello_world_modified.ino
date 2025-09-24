//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with 
// Pixy and Arduino.  This program simply prints the detected object blocks 
// (including color codes) through the serial console.  It uses the Arduino's 
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//
  
#include <Pixy2.h>

// This is the main Pixy object 
Pixy2 pixy;
// LED pins connected to Arduino
int redLed = 4;  
int greenLed = 5;  
int blueLed = 6;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;
int sigRed = 1; // signature 1 is red objects
int sigGreen= 2; // signature 2 is green objects
int sigBlue = 3; //signature 3 is blue


void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT);  
  pixy.init();
}

void loop()
{ 

  
  int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
      pixy.ccc.blocks[i].m_signature;
      Serial.print(pixy.ccc.blocks[i].m_signature);
      delay(1000);
    }
  }  
uint16_t blocks;

  while (1)
  {

    blocks = pixy.ccc.getBlocks();

    if ( blocks)
    {
      for (int i = 0; i< blocks;i++)
      {
        if (pixy.ccc.blocks[i].m_signature  == sigRed)
        {
          digitalWrite(redLed, HIGH); // Turn RED LED ON 
          digitalWrite(greenLed, LOW);  
          digitalWrite(blueLed, LOW);  
          Serial.println("red");
        }
      else if (pixy.ccc.blocks[i].m_signature  == sigBlue)
        {
          digitalWrite(redLed, LOW);  
          digitalWrite(greenLed, LOW);  
          digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
          Serial.println("blue");
        }
       else if (pixy.ccc.blocks[i].m_signature  == sigGreen)
        {
          digitalWrite(redLed, LOW);  
          digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
          digitalWrite(blueLed, LOW);  
          Serial.println("green");
        }
  delay(300);
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  digitalWrite(blueLed, LOW);
    }// end for
      

  }// end if(blocks)
  delay(50); // dont poll thge pixy too fast
  }// end while

}

