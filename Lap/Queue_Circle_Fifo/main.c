/*
 *   Topic   :                                                   Queue CFIFO Mechanism
 *   File    :                                                   __MAIN_C__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#include <stdio.h>
#include "buffer.h"


int main(void)
{
	Element_Type urt_buffer[5];
	Buffer_CFIFO_t urt_buffer_tracer;

	if(Buffer_CFifo_Init(&urt_buffer_tracer , urt_buffer , 5) != BUFFER_SUCCESS)
	{
		printf("Buffer Init Failed\n");
		return 0;
	}


	printf("Buffer Init Successfully\n");


	for(Element_Type i= 0; i <= 4; i++)
	{
		if(Buffer_CFifo_Enqueue(&urt_buffer_tracer , i + 1) == BUFFER_SUCCESS)
			printf("Item: %u Is Added Successfully\n" , i + 1);
	}


	Element_Type item;
	for(vuint8_t i= 0; i <= 2; i++)
	{

		if(Buffer_CFifo_Dequeue(&urt_buffer_tracer , &item) == BUFFER_SUCCESS)
			printf("Dequeue Operation Number %d Value Is: %u Is\n" , i + 1 , item);
	}


	if(Buffer_CFifo_Display(&urt_buffer_tracer) == BUFFER_SUCCESS)
		printf("Successfully Buffer Items Is Displayed Using FIFO Mechanism\n");

	return 0;
}





