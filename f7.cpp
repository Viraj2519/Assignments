// f7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#pragma warning(disable: 4996) //
int main(void)
{
    const unsigned short kBinaryData[] = { 26946, 24942, 31090,
    25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
    unsigned short binary;
    FILE* filePointer;
    FILE* binaryPointer;
    // Open the file for reading and appending. 
    // If it doesn't exist, create it.
    filePointer = fopen("myTextFile.txt", "w");
  

    // Write data to the file using fprintf
    fprintf(filePointer, "%s %s %s %d\n", "This", "is", "line", 1);
    fprintf(filePointer, "%s %s %s %d\n", "This", "is", "line", 2);

    binaryPointer = fopen("myEvenDataList.data", "wb");
    for (int i = 0; i < sizeof(kBinaryData)/ sizeof(kBinaryData[0]); i++) {
        
        if(kBinaryData[i]%2==0){
            fwrite(&kBinaryData[i],sizeof(unsigned short) , 1, binaryPointer);
        }
    }

  
    
}