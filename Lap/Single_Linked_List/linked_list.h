/*
 *   Topic   :                                                     Single Linked List
 *   File    :                                                     __LINKED_LIST_H__
 *   Author  :                                                     abdelfattahzakariaelbadry@gmail.com
*/


#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define  DPrintf(...)                                          {printf(__VA_ARGS__);\
																fflush(stdin);fflush(stdout);}

typedef struct
{
	vuint32_t id;
	vuint8_t name[50];
	vfloat32_t height;
}SStudent_Data_t;

struct SStudent
{
	SStudent_Data_t student;
	struct SStudent *ptr_next;
};
typedef struct SStudent                                         SStudent_t;


void     add_new_student                                            ();
void     fill_student_record                                        (SStudent_t *ptr_new_student);
void     view_all_students                                          ();
vuint8_t delete_all_students                                        ();
vuint8_t delete_student                                             ();
void     get_index_info                                             ();
void     get_list_length_iter                                       ();
void     get_list_length_recs                                       ();
void     reverse_list                                               ();



#endif




