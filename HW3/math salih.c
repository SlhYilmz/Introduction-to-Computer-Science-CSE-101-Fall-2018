// GTU CSE 101 Homework #3
// Muhammed Salih YILMAZ
// 1801042676
#include<stdio.h>
#include <math.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0


int PrintSelection(int selection){
 printf("Selected Menu item is: ");
 printf("%d\n",selection);
 return 1;
 
}

int DisplayMenu(){
 int selection;
 printf("\e"); // clears screen
 
 printf("%s","WELCOME TO ADDING PROGRAM\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection: ");
 
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
float number1, number2, sum;
char wanttoexit = FALSE;
char c;
int choice;
int orderChoice;
int i,j;
int myArray[100];
int max;
int pivot;
int temp;

// main loop
while(wanttoexit == FALSE){

	// display menu and get result	
	choice = DisplayMenu();
	
	
	if(choice == 1){
				
		printf("%s","Please enter first number: ");
		scanf("%f",&number1);
		printf("%s","Please enter second number: ");
		scanf("%f",&number2);
		sum = number1 + number2;
		printf("\nThe result is: %.3f\n", sum);

		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("%s","Enter numbers for array and 0 for end\n");
		
		for(i=0; i<100; i++){
			scanf("%d", &orderChoice);
			if(orderChoice == 0) break;
			myArray[i] = orderChoice;
			max = i ;
		}
		printf("Numbers are entered... \n");
		printf("Now sorting... ");
		
	    for(i=0; i<=max; i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }
		    
		}
		printf("finished...\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");
	        
		    
		c=getchar();
		c=getchar();
	}
	if(choice == 3){
		
		printf("%s", "Please enter your first number: ");
		scanf("%f", &number1);
		printf("%s", "Please enter your second number: ");
		scanf("%f", &number2);
		
		sum= number1 - number2;
		printf("\nThe result is: %.3f\n", sum);
		
		c=getchar();
		c=getchar();
	}
	if(choice == 4){
		
		printf("%s", "Please enter your first number: ");
		scanf("%f", &number1);
		printf("%s", "Please enter your second number: ");
		scanf("%f", &number2);
		
		sum= number1 / number2;
		printf("\nThe result is: %.3f\n", sum);
		
		c=getchar();
		c=getchar();
	}
	if(choice == 5){
		int number;
		int i = 1;
			
		printf("%s", "Please enter your (integer) number: ");
		scanf("%d", &number);
			
	  	while (number !=0) {
	  		printf("%dx%d", number%10, i);
	  		number /= 10;
		   
        	if (number !=0){
        		printf(" + ");
			} 
         
        	i *= 10;
  		}
  		
  		/* Writing this way, eliminates the problem of "what happens if I type negative numbers" */
  			
  		c=getchar();
		c=getchar();
	}
	if(choice == 6){
		float base, exponent, result=1;
		
		printf("%s", "Please enter the base number: ");
		scanf("%f", &base);
		printf("%s", "Please enter the exponent number: ");
		scanf("%f", &exponent);
		
		if(exponent<0){
			printf("\nYou've entered unsupported value.\n");
		}
		else{
			for(i=0; i<exponent; i++){
			result=result*base;		
			}
			
			printf("\nResult is %.3f", result);
		}
		
		c=getchar();
		c=getchar();
	}
	
	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} // end of while

}
