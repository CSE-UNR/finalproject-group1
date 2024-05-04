/*
Name: Rahul Bokka and Lorena
Date: 04 May 2024
Purpose: To be able to take an image and edit it per user's preference such as dim, brighten, rotate
*/


#include <stdio.h>

#define IMAGENAME 100
#define FILE_NAME "lebron.jpg"

int main (){


    printf("**ERINSTAGRAM**\n");
    printf("1. Load Image\n");
    printf("2. Display image\n");
    printf("3. Edit image\n");
    printf("0. Exit\n");
    printf("\nChoose from one of the options above: ");
    scanf("%d", &choice);

    if(choice == 1){

        char imagename[IMAGENAME];
        printf("What is the name of the image file? ");
        scanf("%s", imagename);
        printf("%s",imagename);
        
    }



}


