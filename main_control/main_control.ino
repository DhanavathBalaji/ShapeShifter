#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "pO12NYR6Z_-55sGVxCJUDe8GRDpqA_m6";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Dragonknight";
char pass[] = "shivalik";

Servo servo1,servo2;

void cradle() {
//you begin your own personal code for servo here
  int pos=0;
 // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos=90);    
    // tell servo to go to position in variable 'pos'
//your personal code for servo should end here
}
void stopper() {
  int a; 
  servo1.write(a=0);
  }
  void asc() {
    int b=180;
      servo2.write(b);
      
  }
  void desc(){
    int b1=0;
      servo2.write(b1);
      
     }


BLYNK_WRITE(V3) 
{
  int pinValue = param.asInt();
  if (pinValue != 1) {    // if Button sends 1
    cradle();             // start the function cradle
    Blynk.run(); // Run rest of show in-between waiting for this loop to repeat or quit.
    /*int pinValue = 0;  // Set V3 status to 0 to quit, unless button is still pushed (as per below)
    Blynk.syncVirtual(V3); // ...Then force BLYNK_WRITE(V3) function check of button status to determine if repeating or done.
  }*/
  }else
{
  stopper();
  }
}
BLYNK_WRITE(V4) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {    // if Button sends 1
    asc();             // start the function cradle
    Blynk.run(); // Run rest of show in-between waiting for this loop to repeat or quit.
    /*int pinValue = 0;  // Set V3 status to 0 to quit, unless button is still pushed (as per below)
    Blynk.syncVirtual(V3); // ...Then force BLYNK_WRITE(V3) function check of button status to determine if repeating or done.
  }*/
  }else
{
  desc();
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  servo1.attach(4); //attaches servo to pin 4 (D2 on node mcu)
  servo2.attach(5);
}

void loop()
{
  Blynk.run();
}
