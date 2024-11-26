/*
 *   Topic   :                                                     State Machine Single Block
 *   File    :                                                     __SATE_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


/*
 *   State Header File Aims To Build Smart Function Prototypes For Serveral Useable Function Names
*/


#ifndef __SATE_H__
#define __SATE_H__


#define State_define(_StateFunc_)                                 void ST_##_StateFunc_()

/*Alias Name To Diserable Function Name Only To Be Able To Assigin It To A Ptr Func*/
#define State(_StateFunc_)                                        ST_##_StateFunc_


#endif






