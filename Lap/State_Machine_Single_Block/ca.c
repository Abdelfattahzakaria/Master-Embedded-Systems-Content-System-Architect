/*
 *   Topic   :                                                     State Machine Single Block
 *   File    :                                                     __CA_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/*ca.c: Implementation Of ca.h Prototype Functions*/


#include "ca.h"


/*Define Global Useable Variables: With Static Feature To Avoid Override Or Multi Definiation With Other Files*/
static vuint32_t CA_Spead= 0;
static vuint32_t CA_Distance= 0;
static vuint32_t CA_Threshold= 30;


/*A Pointer To A Function State_define With Ability To Be Callable In Other Files: void ST_##_StateFunc_() -->> ST_##_StateFunc: ST_0 , ST_1*/
/*Definiation: */
void (*Ptr_CA_State) (void);


int US_Generate_Random_Distance(vuint32_t beg , vuint32_t end)
{
	return ((rand() % (end - beg + 1)) + 1);
}


State_define(CA_Waiting)
{
	/*Assign State Id OR Name To Enum Object: */
	CA_State_Id= CA_Waiting;

	/*State Action: Disable Motor Enable Signal*/
	CA_Spead= 0;

	/*State Check To The Decision Making Condition*/
	/*a: Read Sensors Reads: Distance*/
	CA_Distance= US_Generate_Random_Distance(45 , 90);
	/*b: Decision Making*/
	(CA_Distance <= CA_Threshold)? (Ptr_CA_State= State(CA_Waiting)): (Ptr_CA_State= State(CA_Driving));

	printf("Waiting State: distance= %u \tspeed= %u\n" , CA_Distance , CA_Spead);

	return;
}


State_define(CA_Driving)
{
	/*Assign State Id OR Name To Enum Object: */
	CA_State_Id= CA_Driving;

	/*State Action: Disable Motor Enable Signal*/
	CA_Spead= 45;

	/*State Check To The Decision Making Condition*/
	/*a: Read Sensors Reads: Distance*/
	CA_Distance= US_Generate_Random_Distance(45 , 90);
	/*b: Decision Making*/
	(CA_Distance <= CA_Threshold)? (Ptr_CA_State= State(CA_Waiting)): (Ptr_CA_State= State(CA_Driving));

	printf("Driving State: distance= %u \tspeed= %u\n" , CA_Distance , CA_Spead);

	return;
}




