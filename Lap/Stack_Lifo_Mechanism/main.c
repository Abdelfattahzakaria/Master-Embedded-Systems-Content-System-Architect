/*
 *   Topic   :                                                   Stack LIFO Mechanism
 *   File    :                                                   __MAIN_C__
 *   Author  :                                                   abdelfattahzakariaelbadry@gmail.com
*/

#include <stdio.h>
#include "buffer.h"


int main(void)
{
	vuint32_t urt_buffer[5];
	Buffer_LIFO_t urt_buffer_tracer;

	if(Buffer_Lifo_Init(&urt_buffer_tracer , urt_buffer , 5) != BUFFER_SUCCESS)
	{
		printf("Buffer Init Failed\n");
		return 0;
	}


	printf("Buffer Init Successfully\n");


	for(unsigned char i= 0; i <= 4; i++)
	{
		if(Buffer_Lifo_Add(&urt_buffer_tracer , i + 1) == BUFFER_SUCCESS)
			printf("Item: %d Is Added Successfully\n" , i + 1);
	}


	vuint32_t item;
	for(unsigned char i= 0; i <= 4; i++)
	{

		if(Buffer_Lifo_Get(&urt_buffer_tracer , &item) == BUFFER_SUCCESS)
			printf("Pop Operation Number %d Value Is: %u Is\n" , i + 1 , item);
	}
}




       