/*
	Muhammed Salih YILMAZ
	1801042676
	Homework 5
	
	There has to be one blank line at the end of disordered list; so in this list of 165 people, there are 166 lines.
	Otherwise function "personRead" will not work properly, resulting in a bad reading.
	This program is designed to work with only four words (or 3 space characters).
	
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
	char numara[200];
	char isim[200];
	char soyisim[200];
	char mail[200];
} Person;

// List of functions before the main()
void printPersonsAsGiven(Person* Kisiler , int size);
Person* personRead(Person *Kisiler , int *size  , FILE *filePointer );
void personSorter(FILE *fp2, Person *KisilerSorted, int size);

int main () {
	FILE *filePointer;
	Person *persons;
	int size = 0;
	
	persons = personRead(persons , &size , filePointer); // This is the first part of the program. It will distinguish the words whether they are names, surnames etc.
	
	printPersonsAsGiven(persons , size);	// Using the data from the function above, it will print the persons in the order of name, surname, mail and id.
	
	personSorter(filePointer, persons, size);	// This function will sort the selected metric by alphabetical order.
												// After that it will print the result on the screen, followed by writing it to the .txt file.
	
return 0;
}

// This is the first part of the program. It will distinguish the words whether they are names, surnames etc.
Person* personRead(Person *Kisiler , int *size  , FILE *filePointer ){
		
	char word[50];
	char tempWord[50] = "";
    int i;
	char currentChar;
	int count = 0;
	int index = 0;
	
	filePointer = fopen("hw4_disordered_people.txt","r");
	
	// If there is no text file with name "disorderedPeople", it'll print a message about it to the screen.
	if(filePointer == NULL){		
		printf("File not found\n");
		return NULL;
	}
	
	// We are dynamically checking the number of rows, which we called "size". This will help with memory management.
	while( (currentChar = fgetc(filePointer)) != EOF ){
	 
		if(currentChar == '\n'){
			(*size)++;
		}
		
	}
	fclose(filePointer);
	
	filePointer = fopen("hw4_disordered_people.txt","r");
	
	Kisiler = (Person *)malloc(sizeof(Person) * (*size));
	
//This loop is for distinguishing the words. We are only checking for id's, surnames and mails.
//There is no need to check the first name, since there are only 4 variables. If we can distinguish 3 of them, we automatically know the last one.
	while(fscanf(filePointer, "%s", word) != EOF) {
    	
		int countDigit = 0, countUpper = 0, mailFlag = 0;
    	
		for(i = 0; i < strlen(word) ; i++) {
	    	if(word[i]>= '0' && word[i]<= '9') {
				countDigit++;
			}
			
			if(word[i] == '@') {
				mailFlag = 1;
			}
			
			if(word[i]>= 'A' && word[i]<= 'Z') {
				countUpper++;
			}
    	}
    				
		if(countDigit == strlen(word)) {
	    	strcpy(Kisiler[index].numara, word);
	    	count++;
		}
		else if(mailFlag == 1) {
			strcpy(Kisiler[index].mail, word);
			count++;
		}
		else if(countUpper == strlen(word)) {
			strcpy(Kisiler[index].soyisim, word);
			count++;
		}
		else {
			strcpy(Kisiler[index].isim, word);
			count++;	
		}
				
	// When the number of words is 4 per row, it will move to the next one.  	
		if(count == 4){
			index++;
			count = 0;
		}
		strcpy(word , tempWord);
	}
	fclose(filePointer);
	
	return Kisiler;
}

//This function is just for control purposes, it will not be what it writes to the text file.
//Prints the given list as what it is, but in an order.
void printPersonsAsGiven(Person* Kisiler , int size){
	
	int i = 0;
	
	// If the list in text file is empty, it will display a message.
	if(size == 0){
		printf("Person size is 0\n");
		return;
	}
	
	// Prints the data in given order. 
	for(i = 0 ; i < size ; i++)
		printf("name: %-20s surname: %-20s	mail: %-20s	id: %-20s" , Kisiler[i].isim , Kisiler[i].soyisim , Kisiler[i].mail , Kisiler[i].numara);
}

// This function is to get the sorting metric from the user, and sort accordinly to that.
// It will sort in alphabecital order, print it on the screen, then write it to a text file with the metric on the first column.
void personSorter(FILE *fp2, Person *KisilerSorted, int size){

	char value;
	int i, j;
	char temp[size];

// This part is giving the choice to the user.
	printf("\n" "Choose a sorting metric:\n");
	printf("For Name, write 'n' or 'N'\n");
	printf("For Surname, write 's' or 'S'\n");
	printf("For Mail, write 'm' or 'M'\n");
	printf("For ID, write 'i' or 'I'\n");

	scanf("%c", &value);	

// There are four if's in here; each one is to check what is selected.
// Each one will do basically the same thing but in the selected order.
// Sorting is done and is put to the struct. This will allow us tho print it and write it.
		if(value == 'n' || value == 'N'){
			for(i=0 ; i < size ; i++){
				for(j = i+1 ; j < size ; j++){
					
					if (strcmp(KisilerSorted[i].isim, KisilerSorted[j].isim) > 0){

						strcpy(temp, KisilerSorted[i].isim);
						strcpy(KisilerSorted[i].isim, KisilerSorted[j].isim);
						strcpy(KisilerSorted[j].isim, temp);		
		
						strcpy(temp, KisilerSorted[i].soyisim);
						strcpy(KisilerSorted[i].soyisim, KisilerSorted[j].soyisim);
						strcpy(KisilerSorted[j].soyisim, temp);
						
						strcpy(temp, KisilerSorted[i].mail);
						strcpy(KisilerSorted[i].mail, KisilerSorted[j].mail);
						strcpy(KisilerSorted[j].mail, temp);						

						strcpy(temp, KisilerSorted[i].numara);
						strcpy(KisilerSorted[i].numara, KisilerSorted[j].numara);
						strcpy(KisilerSorted[j].numara, temp);												
					}
				
				}
				
			}

			// This will print it in screen.			
			printf("\nAfter sorting, the list is: \n");
			for (i = 0; i < size ; i++){
				printf("%-25s %-25s %-25s %-25s\n", KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].mail, KisilerSorted[i].numara);
			}
			
			// This will write it in a text file.
			fp2 = fopen("orderedPeople.txt", "w");

				for (i = 0 ; i < size ; i++){
					fprintf (fp2, "%-25s , %-25s , %-25s , %-25s \n", KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].mail, KisilerSorted[i].numara);
				}
			fclose(fp2);
			
		}
		else if (value == 's' || value == 'S'){
			for(i=0 ; i < size ; i++){
				for(j = i+1 ; j < size ; j++){
					
					if (strcmp(KisilerSorted[i].soyisim, KisilerSorted[j].soyisim) > 0){
						strcpy(temp, KisilerSorted[i].soyisim);
						strcpy(KisilerSorted[i].soyisim, KisilerSorted[j].soyisim);
						strcpy(KisilerSorted[j].soyisim, temp);
						
						strcpy(temp, KisilerSorted[i].isim);
						strcpy(KisilerSorted[i].isim, KisilerSorted[j].isim);
						strcpy(KisilerSorted[j].isim, temp);
						
						strcpy(temp, KisilerSorted[i].mail);
						strcpy(KisilerSorted[i].mail, KisilerSorted[j].mail);
						strcpy(KisilerSorted[j].mail, temp);
																		
						strcpy(temp, KisilerSorted[i].numara);
						strcpy(KisilerSorted[i].numara, KisilerSorted[j].numara);
						strcpy(KisilerSorted[j].numara, temp);
							
					}
				
				}
				
			}
			
			// This will print it in screen.			
			printf("\nAfter sorting, the list is: \n");
			for (i = 0; i < size ; i++){
				printf("%-25s %-25s %-25s %-25s\n", KisilerSorted[i].soyisim, KisilerSorted[i].isim, KisilerSorted[i].mail, KisilerSorted[i].numara);
			}
			
			// This will write it in a text file.			
			fp2 = fopen("orderedPeople.txt", "w");
				for (i = 0 ; i < size ; i++){
					fprintf (fp2, "%-25s , %-25s , %-25s , %-25s \n", KisilerSorted[i].soyisim, KisilerSorted[i].isim, KisilerSorted[i].mail, KisilerSorted[i].numara);
				}
			fclose(fp2);
		}
		else if (value == 'm' || value == 'M'){
			for(i=0 ; i < size ; i++){
				for(j = i+1 ; j < size ; j++){
					
					if (strcmp(KisilerSorted[i].mail, KisilerSorted[j].mail) > 0){

						strcpy(temp, KisilerSorted[i].mail);
						strcpy(KisilerSorted[i].mail, KisilerSorted[j].mail);
						strcpy(KisilerSorted[j].mail, temp);
												
						strcpy(temp, KisilerSorted[i].isim);
						strcpy(KisilerSorted[i].isim, KisilerSorted[j].isim);
						strcpy(KisilerSorted[j].isim, temp);
						
						strcpy(temp, KisilerSorted[i].soyisim);
						strcpy(KisilerSorted[i].soyisim, KisilerSorted[j].soyisim);
						strcpy(KisilerSorted[j].soyisim, temp);

						strcpy(temp, KisilerSorted[i].numara);
						strcpy(KisilerSorted[i].numara, KisilerSorted[j].numara);
						strcpy(KisilerSorted[j].numara, temp);															
					}
				
				}
				
			}
			// This will print it in screen.			
			printf("\nAfter sorting, the list is: \n");	
			for (i = 0; i < size ; i++){
				printf("%-25s %-25s %-25s %-25s\n", KisilerSorted[i].mail, KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].numara);
			}
			
			// This will write it in a text file.			
			fp2 = fopen("orderedPeople.txt", "w");
				for (i = 0 ; i < size ; i++){
					fprintf (fp2, "%-25s , %-25s , %-25s , %-25s \n", KisilerSorted[i].mail, KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].numara);
				}
			fclose(fp2);
			
		}
		else if(value == 'i' || value == 'I'){
			for(i=0 ; i < size ; i++){
				for(j = i+1 ; j < size ; j++){
					
					if (strcmp(KisilerSorted[i].numara, KisilerSorted[j].numara) > 0){

						strcpy(temp, KisilerSorted[i].numara);
						strcpy(KisilerSorted[i].numara, KisilerSorted[j].numara);
						strcpy(KisilerSorted[j].numara, temp);
						
						strcpy(temp, KisilerSorted[i].isim);
						strcpy(KisilerSorted[i].isim, KisilerSorted[j].isim);
						strcpy(KisilerSorted[j].isim, temp);
						
						strcpy(temp, KisilerSorted[i].soyisim);
						strcpy(KisilerSorted[i].soyisim, KisilerSorted[j].soyisim);
						strcpy(KisilerSorted[j].soyisim, temp);	

						strcpy(temp, KisilerSorted[i].mail);
						strcpy(KisilerSorted[i].mail, KisilerSorted[j].mail);
						strcpy(KisilerSorted[j].mail, temp);													
					}
				
				}
				
			}
			
			// This will print it in screen.			
			printf("\nAfter sorting, the list is: \n");
			for (i = 0; i < size ; i++){
				printf("%-25s %-25s %-25s %-25s\n", KisilerSorted[i].numara, KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].mail);
			}
			
			// This will write it in a text file.			
			fp2 = fopen("orderedPeople.txt", "w");
	
				for (i = 0 ; i < size ; i++){
					fprintf (fp2, "%-25s , %-25s , %-25s , %-25s \n", KisilerSorted[i].numara, KisilerSorted[i].isim, KisilerSorted[i].soyisim, KisilerSorted[i].mail);
				}
			fclose(fp2);
		}
		
}
