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

int main(int argc, char *argv[])
{
    int choice;
    char ansr[5];
   
    //-----------First stage--------------------
    do
    {
        printf("Do you wish to enter a new contact (Yes or No)?:");
        scanf("%s", ansr);

        if ((strcmp(ansr, "yes") == 0) || (strcmp(ansr, "Yes") == 0) || (strcmp(ansr, "YES") == 0))
        {
            createContacts(argv[1]);
            
        }
    } while (strcmp(ansr, "No") != 0);


    //----------Second stage------------------
    do
    {
        printf("Enter a choice :\n1 to print, 2 to search, 3 to create more, -1 to exit : ");
        scanf("%d", &choice);

        if (choice == 3)
        {
            do
            {
                printf("Do you wish to enter a new contact (Yes or No)?:");
                scanf("%s", ansr);

                if ((strcmp(ansr, "yes") == 0) || (strcmp(ansr, "Yes") == 0) || (strcmp(ansr, "YES") == 0))     //condition to see if it is yes
                {

                    createContacts(argv[1]);        //------will create contact
                }

                if (strcmp(ansr, "No") == 0)
                {
                    break;
                }

            } while (strcmp(ansr, "No") != 0);
        }


        //Printitng all Data
        if (choice == 1) 
        {
            printf("Printing Employee records saved on file:\n");
            readContacts(argv[1]);
        }

        if (choice == 2)
        {
            int keyId;
            do
            {
                printf("Enter the id to search: ");
                scanf("%d", &keyId);

            } while ((keyId > 9999 || keyId < 1));                  // Validating Employee id

            int ret = searchContacts(argv[1], keyId);               // ret is the return value from the function
            if (ret == 0)
            {
                printf("No match found. \n");
            }
           
        }
    
    }while (choice != -1);

    printf("\nExiting....\n\n");
    exit(1);


    return 0;
}