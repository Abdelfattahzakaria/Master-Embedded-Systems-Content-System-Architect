/*
 *   Topic   :                                                     Single Linked List
 *   File    :                                                     __LINKED_LIST_C__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


#include "linked_list.h"
static SStudent_t *head= NULL;


void add_new_student                                            ()
{
	SStudent_t *ptr_new_student= NULL;

	if(head == NULL)
	{
	    ptr_new_student= (SStudent_t*)malloc(sizeof(SStudent_t));
		ptr_new_student->ptr_next= NULL;
		head= ptr_new_student;
	}
	else
	{
		SStudent_t *ptr_last_student= head;

		while(ptr_last_student->ptr_next){
			ptr_last_student= ptr_last_student->ptr_next;
        }
	    ptr_new_student= (SStudent_t*)malloc(sizeof(SStudent_t));
		ptr_new_student->ptr_next= NULL;
        ptr_last_student->ptr_next= ptr_new_student;
	}

	fill_student_record(ptr_new_student);

	return;
}


void fill_student_record                                        (SStudent_t *ptr_new_student)
{
	vuint8_t temp_text[50];

	DPrintf("\nEnter Student Id: ");
	gets(temp_text);
	ptr_new_student->student.id= atoi(temp_text);

	DPrintf("\nEnter Student Name: ");
	gets(ptr_new_student->student.name);

	DPrintf("\nEnter Student Height: ");
	gets(temp_text);
	ptr_new_student->student.height= atof(temp_text);

	return;
}


vuint8_t delete_student                                             ()
{
	if(head)
	{
		vuint32_t student_id;
		SStudent_t *ptr_selected_student= head , *ptr_previous_student= NULL;

		DPrintf("\nEnter Student Id: ");
		scanf("%u" , &student_id);

		while(ptr_selected_student)
		{
			if(ptr_selected_student->student.id == student_id)
			{
				if(ptr_previous_student)
				{
					ptr_previous_student->ptr_next= ptr_selected_student->ptr_next;
					free(ptr_selected_student);
				}
				else
				{
					head= ptr_selected_student->ptr_next;
					free(ptr_selected_student);
				}

				return 1;
			}

			ptr_previous_student= ptr_selected_student;
			ptr_selected_student= ptr_selected_student->ptr_next;
		}
	}

	DPrintf("\nEmpty List");
	return 0;
}


vuint8_t delete_all_students                                    ()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
	    return 0;
	}

	SStudent_t *ptr_current_student= head;
	while(ptr_current_student)
	{
		SStudent_t *ptr_temp= ptr_current_student;
		ptr_current_student= ptr_current_student->ptr_next;

		free(ptr_temp);
	}

	head= NULL;
	DPrintf("\nAll Students Are Deleted");

	return 1;
}


void view_all_students                                          ()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
        return;
    }

	SStudent_t *ptr_current_student= head;
	vuint32_t count= 1;
	while(ptr_current_student)
	{
		DPrintf("\nStudent Number %u Info:" , count);
		DPrintf("\n\tStudent Id: %u" , ptr_current_student->student.id);
		DPrintf("\n\tStudent Name: %s" , ptr_current_student->student.name);
		DPrintf("\n\tStudent Height: %f" , ptr_current_student->student.height);

		ptr_current_student= ptr_current_student->ptr_next;
		count++;
	}

	return;
}


void     get_index_info                                             ()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
		return;
	}
	
	vuint32_t index; 
	DPrintf("\nEnter Index: "); 
	scanf("%u" , &index); 
	
	if(index <= 0)
	{
		DPrintf("\nInvalid Index");
		return;
	}
	
	vuint32_t count= 1; 
	SStudent_t *ptr_current_student= head;

	while(ptr_current_student)
	{
		if(index == count)
		{
			DPrintf("\nInfo Within Index: %u Are:" , index);
		    DPrintf("\n\tStudent Number %u Info:" , count);
		    DPrintf("\n\t\tStudent Id: %u" , ptr_current_student->student.id);
		    DPrintf("\n\t\tStudent Name: %s" , ptr_current_student->student.name);
		    DPrintf("\n\t\tStudent Height: %f" , ptr_current_student->student.height);
			
			return;
		}
		
		count++; 
		ptr_current_student= ptr_current_student->ptr_next;
	}
	
	DPrintf("\nTarget Index Out Of Range");
	
	return;
}  


void     get_list_length_iter                                            ()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
		return;
	}
	
	vuint32_t count= 0; 
	SStudent_t *ptr_current_student= head; 
	while(ptr_current_student)
	{
		count++; 
		ptr_current_student= ptr_current_student->ptr_next; 
	}
	
	DPrintf("\nTotal Number Of Students Are: %u" , count);
	
	return;
}


vuint32_t     get_recs_count                                           (SStudent_t *ptr_current_student)
{
	if(ptr_current_student == NULL) 
		return 0; 
	return 1 + get_recs_count(ptr_current_student->ptr_next);
}


void get_list_length_recs()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
		return;
	}
	
	SStudent_t *ptr_current_student= head;
	DPrintf("\nTotal Number Of Students Are: %u" , get_recs_count(ptr_current_student));
	
	return;
}  


void     reverse_list                                               ()
{
	if(head == NULL)
	{
		DPrintf("\nEmpty List");
		return;
	}
	
	SStudent_t *ptr_previous_student= head; 
	SStudent_t *ptr_current_student= head->ptr_next; 
	SStudent_t *next;
		
	ptr_previous_student->ptr_next= NULL; 
	while(ptr_current_student)
	{
		next= ptr_current_student->ptr_next;
		ptr_current_student->ptr_next= ptr_previous_student;
		ptr_previous_student= ptr_current_student; 
		ptr_current_student= next;
	}
	
	head= ptr_previous_student; 
	        
	return;
} 



   
 