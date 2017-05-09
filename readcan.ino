#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("CAN Read - Testing receival of CAN Bus message");  
  delay(1000);
  
  if(Canbus.init(CANSPEED_500))  
    Serial.println("CAN Init ok");
  else
    Serial.println("Can't init CAN");
    
  delay(1000);
}

void loop(){

  tCAN message;
if (mcp2515_check_message()) 
	{
    if (mcp2515_get_message(&message)) 
	{
        
               
               Serial1.print("ID: ");
               Serial1.print(message.id,HEX);
               Serial1.print(", ");
               Serial1.print("Data: ");
               Serial1.print(message.header.length,DEC);
               for(int i=0;i<message.header.length;i++) 
                {	
                  Serial1.print(message.data[i],HEX);
                  Serial1.print(" ");
                  
                }
               Serial1.println("");
            
           }}

}
