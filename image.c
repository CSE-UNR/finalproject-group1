/*
Name: Rahul Bokka and Lorena
Date: 04 May 2024
Purpose: To be able to take an image and edit it per user's preference such as dim, brighten, rotate
*/


#include <stdio.h>

#define IMAGENAME 100
#define MAX_ROWS 999
#define MAX_COLUMNS 999

int displaymenu();
void loadimage();
void dimImage(int rows, int columns, int inputarrayhere[][columns]);
void brightenImage(int rows, int columns, int inputarrayhere[][columns]);
void cropImage(int* inputrows, int* inputcolumns, int newCstart, int newCend, int newRstart, int newRend, int inputarrayhere[][*inputcolumns]);
void saveFile(char filename, int rows, int columns, int newarrayhere[][columns]);
//void loadImage(FILE* in, int* returnrows, int* returncolumns);

int main (){
int imagearray[MAX_ROWS][MAX_COLUMNS];
int* imagerows, *imagecolumns;

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
//int* imagerows, *imagecolumns;
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
        //loadImage(imagename, &imagerows, &imagecolumns);

            fclose(image);
            printf("\nImage successfully loaded!\n\n");

            }
        }

}

/* void loadImage(FILE* in, int* returnrows, int* returncolumns){
	int check, check2 = 0, checkchar = 0;
	int character = 0;
		while(fscanf(fin, "%d", &check) == 1){
			check2++;
			// make check2 into a pointer
		}
		for(int i = 0; i<check2; i++){
			while(fscanf(fin, " %d", &character) == 1){
				checkchar++;
				//make checkchar into a pointer
			}
		}
	}
		*/
        
void displayimage(int choicefinal){

    if(choicefinal == 2){
        
    }



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
	
	//displayimage(rows, columns, inputarrayhere);
	
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		fgets(str, IMAGENAME, stdin);
		//saveFile(str, rows, columns, inputarrayhere);
	}

}

void brightenImage(int rows, int columns, int inputarrayhere[][columns]){
	char answer;
	char str[IMAGENAME];
	for(int rowi=0; rowi<rows; rowi++){
		for(int coli=0; coli<columns; coli++){
			if(inputarrayhere[rowi][coli] < 5){
				inputarrayhere[rowi][coli]++;
			}
		}
	}
	
	//displayimage(rows, columns, inputarrayhere);
	
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		fgets(str, IMAGENAME, stdin);
		//saveFile(str, rows, columns, inputarrayhere);
	}

}

void cropImage(int* inputrows, int*inputcolumns, int newCstart, int newCend, int newRstart, int newRend, int inputarrayhere[][*inputcolumns]){
	char answer;
	char str[IMAGENAME];
	
	for(int rowi = 0; rowi < *inputrows; rowi++){
		for(int coli = 0; coli < newCend; coli++){
			inputarrayhere[rowi][coli] = inputarrayhere[rowi][newCstart - 1];
		}
	}
	
	for(int coli = 0; coli < newCend; coli++){
		for(int rowi = 0; rowi < newRend; rowi++){
			inputarrayhere[rowi][coli] = inputarrayhere[newRstart - 1][coli];
		}
	}
	
	//displayimage(inputrows, inputcolumns, inputarrayhere);
	
	printf("\nWould you like to save the file? (y/n)" );
	scanf(" %c", &answer);
	
	if(answer == 'y' || answer == 'Y'){
		printf("\nWhat do you want to name the image file? (include the extension) ");
		fgets(str, IMAGENAME, stdin);
		//saveFile(str, rows, columns, inputarrayhere);
	}
}

void saveFile(char filename, int rows, int columns, int newarrayhere[][columns]){}
