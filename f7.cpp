/*
* FILE: f7.cpp
* PROJECT: SENG1000 - Focused Assignment 7
* PROGRAMMER: Virajsinh Dharmendrasinh Solanki
* FIRST VERSION: 2024-03-21
* DESCRIPTION: This program is used to create two files 
*              one text file and one binary file and it 
*              will write inside it according to the requirements.  
*/

#include <stdio.h>
#pragma warning(disable: 4996) 
int main(void)
{
    const unsigned short kBinaryData[] = { 26946, 24942, 31090,
    25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
    FILE* filePointer;
    FILE* binaryPointer;
    // open the file through the pointer
    filePointer = fopen("myTextFile.txt", "w");

    // Write data to the file using fprintf
    fprintf(filePointer, "%s %s %s %d\n", "This", "is", "line", 1);
    fprintf(filePointer, "%s %s %s %d\n", "This", "is", "line", 2);

    if (filePointer == NULL) {
        //if the file is not created then it will show this error
        printf("error text file named myTextFile file is not created");
        return 0;
    }
    fclose(filePointer);
    binaryPointer = fopen("myEvenDataList.data", "wb");
   // opens the file through the pointer
   
    for (int i = 0; i < sizeof(kBinaryData) / sizeof(kBinaryData[0]); i++) {
        if (kBinaryData[i] % 2 == 0) {
            // this will write all the even numbers in the data file
            fwrite(&kBinaryData[i], sizeof(unsigned short), 1, binaryPointer);
        }   
    }
    
    if (binaryPointer == NULL) {
        printf("error binary file named myEvenDataList.data file is not created");
        //if the file is not created then it will show this error
        return 0;
    }
    fclose(binaryPointer);
}