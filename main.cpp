#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem> // for file exists

void fCopy(char inputFile[], int copies);

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Not enough arguments.\n");
        return 1;
    }

    if (!filesystem::exists(argv[1]))
    {
        printf("File does not exist.\n");
        return 1;
    }

    char *inputFile[100] = {argv[1]};

    if (!(atoi(argv[2]) >= 0))
    {
        printf("Not a valid copy amount.\n");
        return 1;
    }

    fCopy(*inputFile, atoi(argv[2]));
}

void fCopy(char inputFile[], int copies)
{
    int c = chdir("./files");
    if (c != 0)
    {
        fprintf(stderr, "No folder to hold files");
        exit(1);
    }
    char oName[100];

    for (int i = 0; i < copies; i++)
    {
        int fileSuffix = i; //append the copy number

        strcpy(oName, inputFile);
        strcat(oName, (char *)('0' + fileSuffix)); // output file name

        filesystem::copy_file(inputFile, oName);

    }

    return;
}