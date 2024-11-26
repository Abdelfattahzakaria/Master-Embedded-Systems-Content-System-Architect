/*
 *   Topic   :                                                     State Machine Single Block
 *   File    :                                                     __MAIN_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


#include "ca.h"


void setup(void)
{
	/*Init All Drivers*/
	/*Init IRQ*/
	/*Init Hal Drivers*/
	/*Init Block*/

	/*Set State Pointer For Each Block: Initial State OR Startup|poweron State*/
	Ptr_CA_State= State(CA_Waiting);

	return;
}

int main(void)
{
	/*Init Essential Components*/
	setup();

	/*Start Infinte Runing*/
	vuint32_t i; 
	while(True)
	{
		Ptr_CA_State();
		
		for(i= 0; i <= 15000; i++);
			
		Ptr_CA_State();
		
	}

	return 0;
}


 

       