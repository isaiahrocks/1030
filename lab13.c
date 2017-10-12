/*
Author: Miguel Martinez
Date: 4/22/13
Purpose: This program reads in strings from the command line and exceutes 1 of 2 functions
Email: MiguelMartinez7@my.unt.edu
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*function prototypes*/
void reverse(char *ptr);
void create_string(char **argv, int argc);

int main(int argc, char *argv[])
{
	/*header*/
	printf("Class: CSCE 1030\nName: Miguel Martinez\nEUID: mim0031\nEmail: MiguelMartinez7@my.unt.edu\n\n");

	/*tests if there is only one command (./a.out)*/
	if(argc < 2)
	{
		printf("\nYou did not pass any commands into the program.\n");
	}
	else if(argc == 3 && strcmp(argv[1], "reverse") == 0)
	{
		/*This checks if the second command inputted is "reverse", if it is it calls reverse function*/
		reverse(argv[2]);
	}
	else
	{
		/*This happens if there are more than a total of 3 arguments/commands*/
		create_string(argv,argc);
	}
	
	return 0;
}

/*This function gets the ptr of argv[2], steps up through it, then steps down through it while printing the characters so that it prints the string backwards*/
void reverse(char *ptr)
{
	int i, strlg;
	strlg = strlen(ptr)-1;

	/*stepping up w/o printing*/
	for(i = strlg; i > 0; i--)
	{
		*ptr++;
	}
	/*going backwards through string while printing*/
	for(i = strlg; i >= 0; i--)
	{
		printf("%c", *ptr);
		*ptr--;
	}
	printf("\n");
	return;	
}


/*This function gets the argv (the strings) and argc (the number of arguments) and puts it into one big allocation of memory and prints the latter to the screen*/
void create_string(char *argv[], int argc)
{
	int i;
	/*allocations of memory used with malloc/calloc*/
	char *big,*pf;

	/*this is the bigger allocation of memory that is used to store all strings*/
	big = calloc(200,1);
	for(i = 1; i < argc; i++)
	{
		/*This is equal to the exact value of the current argv*/
		pf = malloc((strlen(argv[i])) + 1);
		/*copies current argv to the pf memory allocation*/
		strcpy(pf, argv[i]);
		/*adds a space to end of string*/
		strcat(pf, " ");
		/*adds current pf string to big*/
		strcat(big,pf);
		/*frees the string that is currently held in pf so that it can be reused with the next argv*/
		free(pf);
	}
	/*prints the master string to the screen*/
	printf("%s", big);
	/*free memory*/
	printf("\n");
	free(big);
	
	return;
}	
