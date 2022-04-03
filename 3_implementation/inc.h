/**
 * @file Student_DataBase_management_system.h
 * @author 
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _STUDENT_DATABASE_MANAGEMENT_SYSTEM.H_
#define __STUDENT_DATABASE_MANAGEMENT_SYSTEM.H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 * @brief structure for Student Record
 * 
 */
typedef struct library
{
    char roll_no[10];
    char student_name[20];
    char student_class[20];
    char student_percentage[10];
    char mobileno[10];
}student;

/**
 * @brief return type for funtions for unit testing
 * 
 */

typedef enum test_values {
    pass = 1,
    fail = 0
}test_values;

/**
 * @brief function to find a student by its roll_no
 * @param id 
 * @return test_values 
 */
test_values searchbook(int roll_no);

/**
 * @brief function to add new students to the student data base
 * 
 * @return test_values 
 */
test_values addition(int roll_no,char name[],char class [],char percentage[],char mobileno[]);

/**
 * @brief funtion to denote discarded students
 * 
 * @param roll_no
 * @return test_values 
 */
test_values deletebook(int id);

/**
 * @brief function to view all the students records
 * 
 * @return test_values 
 */

#endif
