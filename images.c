/*
Name: Rahul Bokka and Lorena Rocha
Date: 04 May 2024
Purpose: To be able to take an image and edit it per user's preference such as dim, brighten, rotate
*/


#include <stdio.h>

#define IMAGENAME 100
#define MAX_ROWS 999
#define MAX_COLUMNS 999

int displaymenu();
void displayimage(int rows, int columns, int inputarrayhere[][columns]);
void dimImage(int rows, int columns, int inputarrayhere[][columns]);
void brightenImage(int inputrows, int inputcolumns, int inputarrayhere[][inputcolumns]);
void cropImage(int inputrows, int inputcolumns, int inputarrayhere[][inputcolumns]);
void saveFile(char filename[], int rows, int columns, int newarrayhere[][columns]);
void loadImage(FILE* fin, int* colPtr, int* rowPtr, int inputarrayhere[][MAX_COLUMNS]);
int editImage();

int main (){
int imagearray[MAX_ROWS][MAX_COLUMNS];
int imagerows, imagecolumns, editchoice;
FILE* fptr;
char imagename[IMAGENAME];

    int choicefinal;
    do{
        choicefinal = displaymenu();
        
	switch(choicefinal){
		case 1:
		
		printf("What is the name of the image file? (include the extension) ");
       		scanf("%s", imagename);
       		
		fptr = fopen(imagename, "r");
		if(fptr == NULL){
			printf("Could not open file!\n\n");
		}
		
		else{
			loadImage(fptr, &imagecolumns, &imagerows, imagearray);
			fclose(fptr);
			printf("Image successfully loaded!\n");
		}
		
		break;
		
		case 2:
		fptr = fopen(imagename, "r");
		if(fptr == NULL){
		printf("Can't open file.\n");
		}
		else{
		displayimage(imagerows, imagecolumns, imagearray);
		fclose(fptr);
		}
		break;
		
		case 3:

       		fptr = fopen(imagename, "r");
		if(fptr == NULL){
		    printf("Sorry, no image to edit.\n");
         	}
        
       		else{
            
		   editchoice = editImage();

		   switch(editchoice){
				case 1:
				
				cropImage(imagerows, imagecolumns, imagearray);
               
				break;
				case 2:
               			
               			dimImage(imagerows, imagecolumns, imagearray);
               
				break;
				case 3:
				
				brightenImage(imagerows, imagecolumns, imagearray);
				break;
		  }
		  fclose(fptr);
	       }
		break;
	}
	
    }while(choicefinal != 0);
    
    if(choicefinal == 0){

        printf("\nGoodbye!\n");

    }

    return 0;    

}

int displaymenu(){

int choice; 

    printf("\n**ERINSTAGRAM**\n");
    printf("1. Load Image\n");
    printf("2. Display image\n");
    printf("3. Edit image\n");
    printf("0. Exit\n");
    printf("\nChoose from one of the options above: ");
    scanf("%d", &choice);
    
    return choice;

}

void loadImage(FILE* fin, int* colPtr, int* rowPtr, int inputarrayhere[][MAX_COLUMNS]){
	int rows = 0, cols = 0;
	char temp;
	
	while(fscanf(fin, "%c", &temp) == 1){
		if(temp == '\n'){
			rows++;
			cols = 0;
		}
		else if(temp != ' '){
			inputarrayhere[rows][cols] = temp;
			cols++;
		}
	}
	
	*colPtr = cols+1;
	*rowPtr = rows;
}
        
void displayimage(int imagerows, int imagecolumns, int inputarrayhere[][MAX_COLUMNS]){
    for(int row = 0; row < imagerows; row++){
        for(int col = 0; col < imagecolumns; col++){
        	switch(inputarrayhere[row][col]){
        		case 0:
        		printf(" ");
        		break;
        		
        		case 1:
        		printf(".");
        		break;
        		
        		case 2:
        		printf("o");
        		break;
        		
        		case 3:
        		printf("O");
        		break;
        		
        		case 4:
        		printf("0");
        		break;
        	}
        if(col == imagecolumns-1){
    	printf("\n");
    }
    } 
    }   
    }

int editImage(){
	int choice;

	printf("\n**EDITING**\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	printf("0. Return to main menu\n");
	printf("Choose from one of the options above: ");
	
	scanf("%d", &choice);

	return choice;	
}




void dimImage(int rows, int columns, int inputarrayhere[][columns]){
	char answer;
	char str[IMAGENAME];
	for(int rowi=0; rowi<rows; rowi++){
		for(int coli=0; coli<columns; coli++){
			if(inputarrayhere[rowi][coli] > 0){
				inputarrayhere[rowi][coli]--;
			}
		}
	}
	
	displayimage(rows, columns, inputarrayhere);
	
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		fgets(str, IMAGENAME, stdin);
		saveFile(str, rows, columns, inputarrayhere);
	}

}

void brightenImage(int inputrows, int inputcolumns, int inputarrayhere[][inputcolumns]){
	char answer;
	char str[IMAGENAME];
	for(int rowi=0; rowi < inputrows; rowi++){
		for(int coli=0; coli < inputcolumns; coli++){
			if(inputarrayhere[rowi][coli] < 5){
				inputarrayhere[rowi][coli]++;
			}
		}
	}
	displayimage(inputrows, inputcolumns, inputarrayhere);
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		fgets(str, IMAGENAME, stdin);
		saveFile(str, inputrows, inputcolumns, inputarrayhere);
	}

}

void cropImage(int inputrows, int inputcolumns, int inputarrayhere[][inputcolumns]){
	int newCstart, newCend, newRstart, newRend;
	char answer;
	char str[IMAGENAME];

	printf("\n1 x %d", inputcolumns);
	displayimage(inputrows, inputcolumns, inputarrayhere);
	printf("\n%d", inputrows);
	printf("\nThe image you want to crop is %d x %d.\nThe rows and columns start at 1 on the upper left-hand side.\n\nWhich column do you want to be the new left side? ", inputrows, inputcolumns);
	scanf("%d", &newCstart);
	printf("\nWhich column do you want to be the new right side? ");
	scanf("%d", &newCend);
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newRstart);
	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newRend);
	
	for(int rowi = 0; rowi < inputrows; rowi++){
		for(int coli = 0; coli < newCend; coli++){
			inputarrayhere[rowi][coli] = inputarrayhere[rowi][newCstart - 1];
		}
	}
	
	for(int coli = 0; coli < newCend; coli++){
		for(int rowi = 0; rowi < newRend; rowi++){
			inputarrayhere[rowi][coli] = inputarrayhere[newRstart - 1][coli];
		}
	}
	
	displayimage(inputrows, inputcolumns, inputarrayhere);
	
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		scanf("%s", str);
		saveFile(str, newRend, newCend, inputarrayhere);
	}
}

void saveFile(char filename[], int inputrows, int inputcolumns, int newarrayhere[][inputcolumns]){
	FILE* fptr;
	fptr = fopen("filename", "w");
	for(int rowi = 0; rowi < inputrows; rowi++){
		for(int coli = 0; coli < inputcolumns; coli++){
			fprintf(fptr, "%d", newarrayhere[rowi][coli]);
		}
	}
	fclose(fptr);
}
