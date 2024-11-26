/*
 *   Topic   :                                                   Queue CFIFO Mechanism
 *   File    :                                                   __BUFFER_C__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#include "buffer.h"


Buffer_CFIFO_Status_t Buffer_CFifo_Is_Null                     (Buffer_CFIFO_t *Buffer_Tracer)
{
	if(!Buffer_Tracer->base || !Buffer_Tracer->head || !Buffer_Tracer->tail)
		return BUFFER_NULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_CFIFO_Status_t Buffer_Is_Null                          (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *Buffer)
{
	if(!Buffer_Tracer || !Buffer)
		return BUFFER_NULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Is_Empty                    (Buffer_CFIFO_t *Buffer_Tracer)
{
	if(Buffer_Tracer->count == 0)
		return BUFFER_EMPTY;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Is_Full                     (Buffer_CFIFO_t *Buffer_Tracer)
{
	if(Buffer_Tracer->count == Buffer_Tracer->length)
		return BUFFER_FULL;

	return BUFFER_Condition_NOT_Occured;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Init                        (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *Buffer , vuint32_t size)
{
	if(Buffer_Is_Null(Buffer_Tracer , Buffer) == BUFFER_NULL)
		return BUFFER_NULL;

	Buffer_Tracer->base= Buffer;
	Buffer_Tracer->head= Buffer;
	Buffer_Tracer->tail= Buffer;
	Buffer_Tracer->length= size;
	Buffer_Tracer->count= 0;

	return BUFFER_SUCCESS;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Enqueue                     (Buffer_CFIFO_t *Buffer_Tracer , Element_Type item)
{
	if(Buffer_CFifo_Is_Null(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	if(Buffer_CFifo_Is_Full(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	*(Buffer_Tracer->head)= item;
	Buffer_Tracer->count++;

	if(Buffer_Tracer->head == (Buffer_Tracer->base + (Buffer_Tracer->length * sizeof(Element_Type))))
		Buffer_Tracer->head= Buffer_Tracer->base;
	else
		Buffer_Tracer->head++;

	return BUFFER_SUCCESS;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Dequeue                     (Buffer_CFIFO_t *Buffer_Tracer , Element_Type *item)
{
	if(Buffer_CFifo_Is_Null(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	if(Buffer_CFifo_Is_Empty(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	*item= *(Buffer_Tracer->tail);
	Buffer_Tracer->count--;

	if(Buffer_Tracer->head == (Buffer_Tracer->base + (Buffer_Tracer->length * sizeof(Element_Type))))
		Buffer_Tracer->tail= Buffer_Tracer->base;
	else
		Buffer_Tracer->tail++;

	return BUFFER_SUCCESS;
}


Buffer_CFIFO_Status_t Buffer_CFifo_Display                     (Buffer_CFIFO_t *Buffer_Tracer)
{
	if(Buffer_CFifo_Is_Null(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	if(Buffer_CFifo_Is_Empty(Buffer_Tracer) == BUFFER_NULL)
		return BUFFER_NULL;

	Element_Type *item= Buffer_Tracer->tail;
    for(vuint8_t i= 0; i < Buffer_Tracer->count; i++)
		printf("item number %d: %u\n" , i + 1 , *item++);

    return 	BUFFER_SUCCESS;
}





