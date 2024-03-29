/*
* FILE: f8.cpp
* PROJECT: SENG1000 - Focused Assignment 8
* PROGRAMMER: Virajsinh Dharmendrasinh Solanki
* FIRST VERSION: 2024-03-29
* DESCRIPTION: This program takes command arguments
*			   and uses them to create a file accordingly
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 21
#pragma warning(disable:4996) 

struct MyData {
	int howMany;
	char theText[MAX_SIZE];
	char directoryPath[MAX_SIZE];
	char filename[MAX_SIZE];
};
// initialized the structure

int main(int argc, char** argv) {
	if (argc != 5) {
		printf("invalid amount of arguments please enter exactly 4 arguments.");
		return 0;
		//if the user does not enter all the arguments it will quit the program
	}
	struct MyData myArgs;
	// structure data type initialized
	myArgs.howMany = atoi(argv[1]);
	strncpy(myArgs.theText, argv[2], sizeof(myArgs.theText) - 1);
	strncpy(myArgs.directoryPath, argv[3], sizeof(myArgs.directoryPath) - 1);
	strncpy(myArgs.filename, argv[4], sizeof(myArgs.filename) - 1);
	// passed the values from the commands to each of the fields
	FILE* file;
	char nameAndPath[MAX_SIZE * 2];// to make sure both name and file path is collected in this string
	sprintf(nameAndPath, "%s/%s", myArgs.directoryPath, myArgs.filename);
	// passed the value of directory and file name to the string with a backslash according to the requirements
	file = fopen(nameAndPath, "w");
	// open the file 
	if (!file) {
		printf("unable to create a the file");
		return 0;
		// if th file is not created it will show the error and exit the code
	}
	for (int i = 0; i < myArgs.howMany; i++) {
		fprintf(file, "%s\n", myArgs.theText);
		/* if the file is created successfully then this will put the string
		 passed in argument 3 number of time argument 1 in the file */
	}
	fclose(file);
	//closes the file
	printf("file has been successfully created at the specified destination");
	// to make sure user knows that the file has been created
	return 0;
}

