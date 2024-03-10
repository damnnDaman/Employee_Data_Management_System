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
#include "../include/givenA2.h"

int searchContacts(char *fileName, int keyId)
{

  FILE *file = fopen(fileName, "rb");

  Contact data;     // Contact is the tydefe-ed struct


  int empid;
  char *fname = malloc(sizeof(char) * MAX_VALUE);
  char *lname = malloc(sizeof(char) * MAX_VALUE);
  char *email = malloc(sizeof(char) * MAX_VALUE);

  fseek(file, 0, SEEK_END);
  int endOfFile = ftell(file);
  
  // checking is the file is empty or not

  if (endOfFile == 0)
  {
    printf("File is empty\n\n");
  }

  fseek(file, 0, SEEK_SET);
  // data is sequential
  while (fread(&data, sizeof(Contact), 1, file))
  {
    
    //seperate seek and read function for separate datas using the position 

    fseek(file, data.empIdPosn, SEEK_SET);
    fread(&empid, sizeof(int), 1, file);


      // the below subtracted value is to get the string length of the first name
    fseek(file, data.firstNamePosn, SEEK_SET);
    fread(fname, sizeof(char) * ((data.lastNamePosn - data.firstNamePosn)), 1, file);

    fseek(file, data.lastNamePosn, SEEK_SET);
    fread(lname, sizeof(char) * ((data.emailPosn - data.lastNamePosn)), 1, file);

    fseek(file, data.emailPosn, SEEK_SET);
    fread(email, sizeof(char) * (data.next - data.emailPosn - data.empIdPosn), 1, file);
  

    //-----matching the employee id with employee id entered by user------------------------
    if (empid == keyId)
    {
    printf("\n************************************************************\n");
   
    printf("Employee id: %d\n", empid);
    printf("First Name: %s\n", fname);
    printf("Last Name: %s\n", lname);
    printf("Email: %s\n", email);

    printf("************************************************************\n");

    return 1;

    break;
    
    }

    // else statement will pass the current pointer to the next employee data------------------------
    else{

      fseek(file, data.next, SEEK_SET);
      
    }
    
  }

  //------Free-ing memory--------

  free(fname);
  free(lname);
  free(email);

  fclose(file);
  

  return 0;
}