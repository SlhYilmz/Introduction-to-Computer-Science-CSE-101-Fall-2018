#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person{
	char numara[200];
	char isim[200];
	char soyisim[200];
	char mail[200];	
} Person;

//List of functions before the main()
void printPersons(Person* Kisiler , int size);
void personWrite(FILE *fp,Person *Kisiler , int size);
Person* PersonRead(Person *Kisiler , int *size  , FILE *filePointer );
void PersonSorter(Person *Kisiler, int size);

int main () {
	FILE *filePointer;
	Person *persons;
	int size = 0;
	
	persons = PersonRead(persons , &size , filePointer);
	
//	printPersons(persons , size);	// To check if the sorting is done or not; is not what it really prints to the file.
	
//	personWrite(filePointer , persons , size);

	PersonSorter(persons, size);
return 0;
}

Person* PersonRead(Person *Kisiler , int *size  , FILE *filePointer ){
		
	char word[50];
	char tempWord[50] = "";
    int i;
	char currentChar;
	int count = 0;
	int index = 0;
	
	filePointer = fopen("disorderedPeople.txt","r");
	
	if(filePointer == NULL){
		printf("File not found\n");
		return NULL;
	}
	
	while( (currentChar = fgetc(filePointer)) != EOF ){
		
		if(currentChar == '\n'){
			(*size)++;
		}
		
	}
	fclose(filePointer);
	
	filePointer = fopen("disorderedPeople.txt","r");
	
	Kisiler = (Person *)malloc(sizeof(Person) * (*size));
	

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
		//	printf("numara %s \n", Kisiler[i].numara);   --> Debugger to check if it reads it correctly
		}
		else if(mailFlag == 1) {
			strcpy(Kisiler[index].mail, word);
			count++;
		//	printf("mail %s \n", Kisiler[i].mail);   --> Debugger to check if it reads it correctly
		}
		else if(countUpper == strlen(word)) {
			strcpy(Kisiler[index].soyisim, word);
			count++;
		//	printf("soyisim %s \n", Kisiler[i].soyisim);   --> Debugger to check if it reads it correctly
		}
		else {
			strcpy(Kisiler[index].isim, word);
			count++;
		//	printf("isim %s \n", Kisiler[i].isim);   --> Debugger to check if it reads it correctly 			
		} 	
		if(count == 4){
			index++;
			count = 0;
		}
		strcpy(word , tempWord);
	}
	fclose(filePointer);
	
	return Kisiler;
}

void printPersons(Person* Kisiler , int size){
	
	int i = 0;
	
	if(size == 0){
		printf("Person size is 0\n");
		return;
	}
	for(i = 0 ; i < size ; i++)
		printf("name: %s		surname: %s		 mail: %s	id:%s \n" , Kisiler[i].isim , Kisiler[i].soyisim , Kisiler[i].mail , Kisiler[i].numara);
}

void personWrite(FILE *fp, Person *Kisiler , int size){
	
	int i ;
	fp = fopen("ordered_list_as_given.txt" , "w");
	
	
	for(i = 0 ; i < size ; i++){
		
		fprintf( fp , "%s , %s , %s , %s \n", Kisiler[i].isim , Kisiler[i].soyisim , Kisiler[i].mail , Kisiler[i].numara);
	}
	fclose(fp);
}


void PersonSorter(Person *Kisiler, int size){

	char value;
	int i, j;
	char temp[size];
	printf("Choose a sorting metric:");
	printf("For Name, write 'n' or 'N'");
	printf("For Surname, write 's' or 'S'");
	printf("For Mail, write 'm' or 'M'");
	printf("For ID, write 'i' or 'I'");

	scanf("%c", &value);	

		if(value == 'n' || value == 'N'){
			for(i=0 ; i < size ; i++){
				for(j = i+1 ; j < size ; j++){
					
					if (strcmp(Kisiler[i].soyisim, Kisiler[j].soyisim) > 0){
						
						strcpy(temp, Kisiler[i].soyisim);
						strcpy(Kisiler[i].soyisim, Kisiler[j].soyisim);
						strcpy(Kisiler[j].soyisim, temp);
						
					}
				
				}
				
			}
			
			printf("After sorting string is \n");
			
			for (i = 0; i < size ; i++){
				printf("%s ", Kisiler[i].isim);
			}
			
		}/*
		else if (value == 's' || value == 'S'){
			
		}
		else if (value == 'm' || value == 'M'){
			
		}
		else(value == 'i' || value == 'I'){
						
		}
		*/
}

