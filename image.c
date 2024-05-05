/*
Name: Rahul Bokka and Lorena
Date: 04 May 2024
Purpose: To be able to take an image and edit it per user's preference such as dim, brighten, rotate
*/


#include <stdio.h>

#define IMAGENAME 100
#define MAX_ROWS 100
#define MAX_COLUMNS 100

int displaymenu();
void loadimage();

int main (){
int 2Darray[MAX_ROWS][MAX_COLUMNS];

    int choicefinal;
    do{
        choicefinal = displaymenu();
        loadimage(choicefinal);

    }while(choicefinal != 0);
    
    if(choicefinal == 0){

        printf("\nGoodbye!\n");

    }

    return 0;    


}

int displaymenu(){

int choice; 

    printf("**ERINSTAGRAM**\n");
    printf("1. Load Image\n");
    printf("2. Display image\n");
    printf("3. Edit image\n");
    printf("0. Exit\n");
    printf("\nChoose from one of the options above: ");
    scanf("%d", &choice);


    return choice;


}

void loadimage(int choicefinal){
    if(choicefinal == 1){

        char imagename[IMAGENAME];
        printf("What is the name of the image file? ");
        scanf("%s", imagename);
            
        FILE *image;

        image = fopen(imagename, "r");

        if(image == NULL){
                
            printf("Could not find an image with that filename.\n");
            
        }

        else{

            fclose(image);
            printf("\nImage successfully loaded!\n\n");

            }
        }

}
        
void displayimage(int choicefinal){

    if(choicefinal == 2){
        
    }



}
