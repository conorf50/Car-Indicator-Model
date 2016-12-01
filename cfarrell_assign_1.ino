/*
Automotive Software Concepts - I.O.T Year 2
///////////////////////////////////////////////////////////////////
Author - Conor Farrell    /////////////////////////////////////////
Date - 30 November 2016   /////////////////////////////////////////
///////////////////////////////////////////////////////////////////



Car Indicator Demonstrator

(see circuit in report)
This circuit models the indicators in the average
car. The system has three inputs and three outputs.

The three inputs and a brief description of their functions:
* Left Button - Flashes the left indicator when held
* Right Button - Flashes the right indicator when held
* Hazard Switch - Flashes both indicators and the Hazard Light when
  activated, regardless of the states of the other buttons 

The three outputs are as follows:
* LEFT_IND - left indicator
* RIGHT_IND - right indicator
* HAZARD - hazard light
*/


//MAIN PROGRAMME - THE START
void setup() {
  /*
  These should remain the same for the 
  duration of the programme
  */
  const int LEFT_IND;   
  const int RIGHT_IND;
  const int HAZARD;

/*These are our outputs
Left Indicator = Pin 5
Right Indicator = Pin 3
Hazard Light = Pin 4
*/
pinMode(4, OUTPUT);    
pinMode(5, OUTPUT);    
pinMode(3, OUTPUT);   

/* INPUT_PULLUP enables the ATMega's Internal Pull-Up Resistor for each
pin. This requires that the swithes be inverted so that the LEDs will blink 
when the switches are pressed */
pinMode(12, INPUT_PULLUP);      // Left Indicator
pinMode(11, INPUT_PULLUP);      // Hazard Switch
pinMode(10, INPUT_PULLUP);      // Right Indicator



}
//simplar to while(true) this loops infinitely
void loop() {

int LEFT_IND = 5;   //pins being initalised
int RIGHT_IND = 3;
int HAZARD = 4;

int time = 500;     //Let's define delay time variable here to make life 
//easier

bool leftState = digitalRead(12);  // store current state of pin 12
bool rightState = digitalRead(10);  // store current state of pin 10
bool hazardState = digitalRead(11);  // store current state of pin 11


/*
The internal resistor inverts the logic of the buttons
so instead of testing for the booleans, we test for the 
inverse of them.

++++++NOTE++++++
We check if the hazard switch is on first since that is the most 
inportant condition
*/
if(!hazardState == HIGH){ 
  digitalWrite(LEFT_IND,LOW);
  digitalWrite(HAZARD,HIGH);
  digitalWrite(RIGHT_IND,LOW);


  delay(time);

  digitalWrite(LEFT_IND,HIGH);
  digitalWrite(HAZARD,LOW);
  digitalWrite(RIGHT_IND,HIGH);
  delay(time);
}
else if(!leftState == HIGH){
  digitalWrite(LEFT_IND,LOW);
  delay(time);
  digitalWrite(LEFT_IND,HIGH);
  delay(time);
}

else if(!rightState == HIGH){
  digitalWrite(RIGHT_IND,LOW);
  delay(time);
  digitalWrite(RIGHT_IND,HIGH);
  delay(time);
} 
/*default condition when eveything is false
Once again the inverted logic requires that the LEDs
are set to HIGH instead of LOW
*/
else{
  digitalWrite(LEFT_IND,HIGH);
// digitalWrite(HAZARD,LOW);
  digitalWrite(RIGHT_IND,HIGH);
}

}



//some code that was not implemented in the final submission
// void flash(int pinNumber){
//    digitalWrite(pinNumber,HIGH);
//    delay(1000);
//    digitalWrite(pinNumber,LOW);
//  }

