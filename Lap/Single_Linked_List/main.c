/*
 *   Topic   :                                                     Single Linked List
 *   File    :                                                     __MAIN_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/

#include "linked_list.h"

int main(void)
{
	vuint8_t option;

	while(True)
	{
		DPrintf("\n==========================================================");
		DPrintf("\n\tChoose One From The Following Options:");
		DPrintf("\n 1: Add New Student");
		DPrintf("\n 2: Delete Student");
		DPrintf("\n 3: View Students");
		DPrintf("\n 4: Delete All");
		DPrintf("\n 5: Get Index Data");
		DPrintf("\n 6: Get Students Number Iteratively");
		DPrintf("\n 7: Get Students Number Recursively");
		DPrintf("\n 8: Reverse List");
		DPrintf("\nEnter Option Number: ");
		scanf("%u" , &option);
		DPrintf("\n==========================================================");

		switch(option)
		{
			case 1:
			{
				add_new_student();
                break;
			}
			case 2:
			{
				delete_student();
                break;
			}
			case 3:
			{
				view_all_students();
                break;
			}
			case 4:
			{
				delete_all_students();
                break;
			}
			case 5:
			{
				get_index_info();
                break;
			}
			case 6:
			{
				get_list_length_iter();
                break;
			}
			case 7:
			{
				get_list_length_recs();
                break;
			}
			case 8:
			{
				reverse_list();
                break;
			}
            default:
			{
				DPrintf("\nWrong Option");
				break;
			}
		}
	}

	return 0;
}





        