/*
 *   Topic   :                                                     State Machine Single Block
 *   File    :                                                     __CA_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/*Header File For ca.c*/


#ifndef __CA_H__
#define __CA_H__


#include <stdio.h>
#include "datatype.h"
#include "state.h"


enum
{
	CA_Waiting ,
	CA_Driving
}CA_State_Id;


State_define(CA_Waiting);
State_define(CA_Driving);
int US_Generate_Random_Distance(vuint32_t beg , vuint32_t end);

/*A Pointer To A Function State_define With Ability To Be Callable In Other Files: void ST_##_StateFunc_() -->> ST_##_StateFunc: ST_0 , ST_1*/
extern void (*Ptr_CA_State) (void);


#endif



 
