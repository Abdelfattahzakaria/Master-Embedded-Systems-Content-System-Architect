/*
 *   Topic   :                                                   Stack LIFO Mechanism
 *   File    :                                                   __BUFFER_H__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "datatype.h"

typedef struct
{
	vuint32_t *base;
    vuint32_t *head;
    vuint32_t length;
    vuint32_t count;
}Buffer_LIFO_t;
typedef enum
{
	BUFFER_NULL ,
	BUFFER_EMPTY ,
	BUFFER_FULL ,
	BUFFER_SUCCESS ,
	BUFFER_Condition_NOT_Occured
}Buffer_LIFO_Status_t;



Buffer_LIFO_Status_t Buffer_Lifo_Is_Null                     (Buffer_LIFO_t *Buffer_Tracer);
Buffer_LIFO_Status_t Buffer_Is_Null                          (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *Buffer);
Buffer_LIFO_Status_t Buffer_Lifo_Is_Empty                    (Buffer_LIFO_t *Buffer_Tracer);
Buffer_LIFO_Status_t Buffer_Lifo_Is_Full                     (Buffer_LIFO_t *Buffer_Tracer);

Buffer_LIFO_Status_t Buffer_Lifo_Init                        (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *Buffer , vuint32_t size);
Buffer_LIFO_Status_t Buffer_Lifo_Add                         (Buffer_LIFO_t *Buffer_Tracer , vuint32_t item);
Buffer_LIFO_Status_t Buffer_Lifo_Get                         (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *item);


#endif



