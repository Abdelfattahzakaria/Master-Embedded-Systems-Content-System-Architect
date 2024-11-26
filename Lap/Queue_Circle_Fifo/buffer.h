/*
 *   Topic   :                                                   Queue CFIFO Mechanism
 *   File    :                                                   __BUFFER_H__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "datatype.h"

typedef struct
{
	Element_Type *base;
    Element_Type *head;
    Element_Type *tail;
    vuint32_t length;
    vuint32_t count;
}Buffer_CFIFO_t;
typedef enum
{
	BUFFER_NULL ,
	BUFFER_EMPTY ,
	BUFFER_FULL ,
	BUFFER_SUCCESS ,
	BUFFER_Condition_NOT_Occured
}Buffer_CFIFO_Status_t;



Buffer_CFIFO_Status_t Buffer_CFifo_Is_Null                     (Buffer_CFIFO_t *Buffer_Tracer);
Buffer_CFIFO_Status_t Buffer_Is_Null                           (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *Buffer);
Buffer_CFIFO_Status_t Buffer_CFifo_Is_Empty                    (Buffer_CFIFO_t *Buffer_Tracer);
Buffer_CFIFO_Status_t Buffer_CFifo_Is_Full                     (Buffer_CFIFO_t *Buffer_Tracer);

Buffer_CFIFO_Status_t Buffer_CFifo_Init                        (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *Buffer , vuint32_t size);
Buffer_CFIFO_Status_t Buffer_CFifo_Enqueue                     (Buffer_CFIFO_t *Buffer_Tracer , Element_Type item);
Buffer_CFIFO_Status_t Buffer_CFifo_Dequeue                     (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *item);
Buffer_CFIFO_Status_t Buffer_CFifo_Display                     (Buffer_CFIFO_t *Buffer_Tracer);



#endif



