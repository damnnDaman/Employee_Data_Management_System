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

void readContacts(char *fileName)
{
  FILE *file; // Opening file
  file = fopen(fileName, "r+");

  // Check if file opened successfully
  if (file == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  // Read data from file
  Contact data;

  int empid;

  char *fname = malloc(sizeof(char) * MAX_VALUE);
  char *lname = malloc(sizeof(char) * MAX_VALUE);
  char *email = malloc(sizeof(char) * MAX_VALUE);

  // to see how many bytes of Data is already present
  fseek(file, -1, SEEK_END);
  int endOfFile = ftell(file);

  if (endOfFile == 0)
  {
    printf("File is empty\n\n");
  }

  fseek(file, 0, SEEK_SET);
  while (fread(&data, sizeof(Contact), 1, file))

  {

    printf("\n************************************************************\n");

    //----Seeking, Reading and printing with different statement for each data--

    fseek(file, data.empIdPosn, SEEK_SET);
    fread(&empid, sizeof(int), 1, file);
    printf("Employee id: %d\n", empid);

    fseek(file, data.firstNamePosn, SEEK_SET);
    fread(fname, sizeof(char) * ((data.lastNamePosn - data.firstNamePosn)), 1, file);
    printf("First Name: %s\n", fname);

    fseek(file, data.lastNamePosn, SEEK_SET);
    fread(lname, sizeof(char) * ((data.emailPosn - data.lastNamePosn)), 1, file);
    printf("Last Name: %s\n", lname);

    fseek(file, data.emailPosn, SEEK_SET);
    fread(email, sizeof(char) * (data.next - data.emailPosn), 1, file);
    printf("Email: %s\n", email);

    printf("************************************************************\n");

    // passing the cursor to next structure---
    fseek(file, data.next, SEEK_SET);
  }

  free(fname);
  free(lname);
  free(email);

  fclose(file);
}
