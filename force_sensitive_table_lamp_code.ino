/*
 Project Name  : FORCE SENSITIVE TABLE LAMP
 Revision Date : 31.12.2021
 Author        : Serkan SEVMEZ
 //-----------------------------------------------------------------------------------------------------------------
 Purpose       : The purpose of the system is to enable you to stand upright thanks to the force sensor placed
                 on the chair and thus to light the table lamp.
 //-----------------------------------------------------------------------------------------------------------------
 System Input  : 
                 1) RP-C18.3-ST : To measure the force that will cause the lamp to light   
                 2) LDR         : To ensure that the lamp lights up according to the ambient light
 System Output :
                 1) LED         : It will act as a table lamp
 //-----------------------------------------------------------------------------------------------------------------
 System Work   : In this study, thanks to the force sensor I placed on the top of the chair, the table lamp will
                 turn on and the table lamp will continue to light as long as the back of our body exerts pressure
                 on the force sensor. In addition, thanks to the light sensor I placed, the table lamp will not 
                 turn on when the ambient light is too much.     
 //-----------------------------------------------------------------------------------------------------------------                 
 */

 //-----------------------------------------------------------------------------------------------------------------

 // DEFINITIONS
int LDR = A0;            // LDR is connected to Analog 0 pin.
int frc = A1;            // RP-C18.3-ST is connected to Analog 1 pin.
int led = 13;            // Led is connected to Digital 13 pin.
int force;               // We define a variable for the force value
int light;               // We define a variable for the light value
//------------------------------------------------------------------------------------------------------------------

// SETUP CODE AREA
 
void setup() 
{
Serial.begin(9600);      // Sets the baud rate for serial data transmission.
pinMode(LDR,INPUT);      // LDR defined as INPUT.
pinMode(led,OUTPUT);     // Led defined as OUTPUT.
pinMode(frc,INPUT);      // Force Sensor defined as INPUT.
}
//-------------------------------------------------------------------------------------------------------------------

// MAIN CODE AREA

void loop() 
{
light=analogRead(LDR);   // We read the light variable with the LDR
Serial.println(light);   // We reflect the read value on the serial communication screen 
delay(50);


force=analogRead(frc);   // We read the force variable with the frc
if(light<700){           // If the light value read is smaller than 700
if(force<1020)           // If the force value read is smaller than 1020
{
 digitalWrite(led,HIGH); // LED light up
}
else                     
{
  digitalWrite(led,LOW); // LED does not light up
}
}
if(light>700){           // If the light value read is greater than 700
  digitalWrite(led,LOW); // LED does not light up
}
Serial.println(force);   // We reflect the read value on the serial communication screen
}
//--------------------------------------------------------------------------------------------------------------------
