/*
 *   Topic   :                                                   Stack LIFO Mechanism
 *   File    :                                                   __BUFFER_C__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#include "buffer.h"


Buffer_LIFO_Status_t Buffer_Lifo_Is_Null                      (Buffer_LIFO_t *Buffer_Tracer)
{
	if(!Buffer_Tracer->base || !Buffer_Tracer->head)
		return BUFFER_NULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_LIFO_Status_t Buffer_Is_Null                          (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *Buffer)
{
	if(!Buffer_Tracer || !Buffer)
		return BUFFER_NULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_LIFO_Status_t Buffer_Lifo_Is_Empty                     (Buffer_LIFO_t *Buffer_Tracer)
{
	if(Buffer_Tracer->count == 0)
		return BUFFER_EMPTY;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_LIFO_Status_t Buffer_Lifo_Is_Full                      (Buffer_LIFO_t *Buffer_Tracer)
{
	if(Buffer_Tracer->count == Buffer_Tracer->length)
		return BUFFER_FULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_LIFO_Status_t Buffer_Lifo_Init                         (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *Buffer , vuint32_t size)
{
	if(Buffer_Is_Null(Buffer_Tracer , Buffer) == BUFFER_NULL)
		return BUFFER_NULL;

	Buffer_Tracer->base= Buffer;
	Buffer_Tracer->head= Buffer;
	Buffer_Tracer->length= size;
	Buffer_Tracer->count= 0;

	return BUFFER_SUCCESS;
}


Buffer_LIFO_Status_t Buffer_Lifo_Add                         (Buffer_LIFO_t *Buffer_Tracer , vuint32_t item)
{
	if(Buffer_Lifo_Is_Null(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	if(Buffer_Lifo_Is_Full(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	*(Buffer_Tracer->head++)= item;
	Buffer_Tracer->count++;

	return BUFFER_SUCCESS;
}


Buffer_LIFO_Status_t Buffer_Lifo_Get                         (Buffer_LIFO_t *Buffer_Tracer , vuint32_t *item)
{
	if(Buffer_Lifo_Is_Null(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	if(Buffer_Lifo_Is_Empty(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	Buffer_Tracer->head--;
	*item= *(Buffer_Tracer->head);
	Buffer_Tracer->count--;

	return BUFFER_SUCCESS;
}



