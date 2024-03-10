/* 
  Student Name: Daman  Kumar
  Student ID: 1306900
  Due Date: 8th-march, Friday, 2023 
  Course: CIS*2500 
 
  I have exclusive control over this submission via my password. 
  By including this header comment, I certify that: 
   1) I have read and understood the policy on academic integrity. 
   2) I have completed Moodle's module on academic integrity. 
   3) I have achieved at least 80% on the academic integrity quiz 
  I assert that this work is my own. I have appropriate acknowledged 
  any and all material that I have used, be it directly quoted or 
  paraphrased. Furthermore, I certify that this assignment was written 
  by me in its entirety. 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>


#define MAX_VALUE 150
typedef struct contact
{
  long empIdPosn;
  long firstNamePosn;
  long lastNamePosn;
  long emailPosn;
  long next;
} Contact;

void createContacts (char * fileName);

void readContacts (char * fileName);

int searchContacts (char * fileName, int keyId);
