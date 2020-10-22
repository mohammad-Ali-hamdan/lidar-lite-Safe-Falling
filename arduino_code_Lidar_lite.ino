/*------------------------------------------------------------------------------

  LIDARLite Arduino Library


  This example shows how to read distance from a LIDAR-Lite connected over the
  PWM interface.

  Connections:
  LIDAR-Lite 5 Vdc (red) to Arduino 5v
  LIDAR-Lite Ground (black) to Arduino GND
  LIDAR-Lite Mode control  to Arduino digital input (pin 4) through a 1 KOhm resistor

  680uF capacitor (+) to Arduino 5v
  680uF capacitor (-) to Arduino GND


lider_lite 250 reading per second
------------------------------------------------------------------------------*/

unsigned long pulseWidth;
int counter=0;
void setup()
{

  pinMode(27, OUTPUT); // Set pin 27 (PPC4) as trigger pin
  digitalWrite(27, LOW); // Set trigger LOW for continuous read

  pinMode(4, INPUT); // Set pin 4 (PD2) as monitor pin
}

void loop()
{
  pulseWidth = pulseIn(4, HIGH); // Count how long the pulse is high in microseconds

  // If we get a reading that isn't zero, Correct reading
  if(pulseWidth != 0)
  {
    pulseWidth = pulseWidth / 10; // 10usec = 1 cm of distance

    if (pulseWidth <=3500) //distance is less than or equal 35 meters
    {
      counter++;
      if(counter == 5)  // 5 readings more less than or equal 35 meters 
      {
         digitalWrite(27, HIGH); // Trigger high
         counter =0;
      }
    }
    else
      {
        counter = 0;
      }
    
  }
  
}
