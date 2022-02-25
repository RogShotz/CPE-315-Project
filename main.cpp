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
        return;
    }
    FILE *iFile = fopen(inputFile, "r");

    char ch; // buffer
    char oName[100];

    for (int i = 0; i < copies; i++)
    {
        int fileSuffix = rand() % copies; // Find random number in range 0 <-> copies

        strcpy(oName, inputFile);
        strcat(oName, (char *)('0' + fileSuffix)); // output file name

        FILE *oFile = fopen(oName, "w");

        while ((ch = fgetc(iFile)) != EOF)
        {
            fputc(ch, oFile);
        }

        fclose(oFile);
    }

    return;
}