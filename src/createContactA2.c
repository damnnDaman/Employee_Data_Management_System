/*
  Student Name: Daman Kumar
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
#include "../include/givenA2.h"

void createContacts(char *fileName)
{
  FILE *fptr;
  Contact data;

  fptr = fopen(fileName, "a+");   //(a+ used as mentioned in the A2 document)
 
  int id;
  char *fname = malloc(sizeof(char) * MAX_VALUE);
  char *lname = malloc(sizeof(char) * MAX_VALUE);
  char *email = malloc(sizeof(char) * MAX_VALUE);


  //Prompting user for employee's data
  printf("Employee Id:");
  scanf("%d", &id);

  printf("First Name:");
  scanf("%s", fname);

  printf("Last Name: ");
  scanf("%s", lname);

  printf("Email: ");
  scanf("%s", email);


  // the below logic is used so that if data is already present then the new data will added to its end--

  fseek(fptr, 0, SEEK_END);

  data.empIdPosn = sizeof(Contact)+ ftell(fptr);
  data.firstNamePosn = data.empIdPosn + sizeof(int);
  data.lastNamePosn = data.firstNamePosn + (strlen(fname)+1);
  data.emailPosn = data.lastNamePosn + (strlen(lname) +1 );
  data.next = strlen(email)  + data.emailPosn +1 ;

  //putting structure into
  fwrite(&data,sizeof(Contact), 1, fptr);
  
  //putting actual data into

  fwrite(&id, sizeof(int), 1, fptr);
  fwrite(fname, sizeof(char) * (strlen(fname)+1), 1, fptr);
  fwrite(lname, sizeof(char) * (strlen(lname)+1), 1, fptr);
  fwrite(email, sizeof(char) * (strlen(email)+1), 1, fptr);


  fclose(fptr);
  free(fname);
  free(lname);
  free(email);
}