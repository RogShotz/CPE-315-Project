#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <fstream>

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

    if (fopen(inputFile.c_str(), "r") == NULL)
    {
        printf("Input file cannot be opened.\n");
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

    for (int i = 0; i < numCopies; i++)
    {
        int fileSuffix = rand() % 100; // Find random number in range 0 <-> 99

        size_t t = inputFile.find_last_of(".");
        string outputFile;

        if (t == string::npos)
        {
            outputFile = inputFile + to_string(fileSuffix);
        }
        else
        {
            string stem = inputFile.substr(0, t);
            string ext = inputFile.substr(t, inputFile.length());

            outputFile = stem + to_string(fileSuffix) + ext;
        }

        ifstream src(inputFile, ios::binary);
        ofstream dst(outputFile, ios::binary);

        dst << src.rdbuf();

    }
    
    // 

    return 0;
}