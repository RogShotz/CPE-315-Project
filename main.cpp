#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Not enough arguments.\n");
        return 1;
    }

    string inputFile(argv[1]);

    if (&inputFile == NULL)
    {
        printf("Input file argument invalid.\n");
        return 1;
    }

    int numCopies = atoi(argv[2]);

    if (&numCopies == NULL)
    {
        printf("Copy count argument invalid.\n");
        return 1;
    }

    int c = chdir("files");
    if (c != 0)
    {
        return 1;
    }

    string fileExt = ".sus";

    for (int i = 0; i < numCopies; i++)
    {
        int fileSuffix = rand() % 100; // Find random number in range 0 <-> 99

        string temp = inputFile + to_string(fileSuffix) + fileExt;
        char fileName[temp.length()];
        strcpy(fileName, temp.c_str());

        // Create the file and close it
        FILE *f = fopen(fileName, "wb");
        fclose(f);
    }
    
    // 

    return 0;
}