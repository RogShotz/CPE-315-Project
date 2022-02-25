#include <filesystem> // for checking if file exists
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <cstring>

#define man "\nusage [programname] [imagefile] [copies]\n\nimage/outputfile\n\tmust be in .bmp\n\ncopies\n\tmust be positive\n\n"

using namespace std;

struct BITMAPFILEHEADER
{
    short bfType;      // specifies the file type
    int bfSize;        // specifies the size in BYTEs of the bitmap file
    short bfReserved1; // reserved; must be 0
    short bfReserved2; // reserved; must be 0
    int bfOffBits;     // species the offset in BYTEs from the bitmapfileheader to the bitmap bits
};
struct BITMAPINFOHEADER
{
    int biSize;          // specifies the number of BYTEs required by the struct
    int biWidth;         // specifies width in pixels
    int biHeight;        // species height in pixels
    short biPlanes;      // specifies the number of color planes, must be 1
    short biBitCount;    // specifies the number of bit per pixel
    int biCompression;   // spcifies the type of compression
    int biSizeImage;     // size of image in BYTEs
    int biXPelsPerMeter; // number of pixels per meter in x axis
    int biYPelsPerMeter; // number of pixels per meter in y axis
    int biClrUsed;       // number of colors used by th ebitmap
    int biClrImportant;  // number of colors that are important
};

typedef unsigned char BYTE;

struct BMP
{
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    BYTE *idata;
    int trueWidth;
};

BMP BMPRead(char fName[]); // for reading into file
void BMPWrite(BMP bmp, char fName[]);
BYTE getColor(BMP bmp, int color, int x, int y); // get color at pixel, 1 = b, 2 = g, 3 = r

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\nINVALID NUMBER OF ARGS\n%s", man);
        return 0;
    }

    if (!filesystem::exists(argv[1]))
    {
        printf("\nFILE %s DOES NOT EXIST\n%s", argv[1], man);
        return 0;
    }

    char *fName[] = {argv[1]};

    BMP iBMP = BMPRead(*fName);

    /* BYTE tempColor; // for scrolling through the colors

    for (int x = 0; x < oBMP.bih.biWidth; x++)
    {
        for (int y = 0; y < oBMP.bih.biHeight; y++)
        {
            for (int i = 1; i < 4; i++)
            {
                tempColor = getColor(iBMP, i, x, y);
                oBMP.idata[x * 3 + y * oBMP.trueWidth + i] = (BYTE)tempColor;
            }
        }
    }*/

    chdir("./files");

    char oName[100] = "hellos.bmp";

    printf("success\n");

    BMPWrite(iBMP, oName);

    // dynamically de-allocate
    delete[] iBMP.idata;

    return 0;
}

BMP BMPRead(char fName[])
{
    BMP bmp;

    FILE *file = fopen(fName, "rb");

    fread(&bmp.bfh.bfType, sizeof(short), 1, file);
    fread(&bmp.bfh.bfSize, sizeof(int), 1, file);
    fread(&bmp.bfh.bfReserved1, sizeof(short), 1, file);
    fread(&bmp.bfh.bfReserved2, sizeof(short), 1, file);
    fread(&bmp.bfh.bfOffBits, sizeof(int), 1, file);

    fread(&bmp.bih, sizeof(bmp.bih), 1, file);

    int size = bmp.bih.biSizeImage;
    bmp.idata = new BYTE[size];

    bmp.trueWidth = size / bmp.bih.biHeight;

    fread(bmp.idata, size, 1, file);
    fclose(file);
    return bmp;
}

void BMPWrite(BMP bmp, char fName[])
{
    FILE *file = fopen(fName, "wb");

    fwrite(&bmp.bfh.bfType, sizeof(short), 1, file);
    fwrite(&bmp.bfh.bfSize, sizeof(int), 1, file);
    fwrite(&bmp.bfh.bfReserved1, sizeof(short), 1, file);
    fwrite(&bmp.bfh.bfReserved2, sizeof(short), 1, file);
    fwrite(&bmp.bfh.bfOffBits, sizeof(int), 1, file);

    fwrite(&bmp.bih, sizeof(bmp.bih), 1, file);

    fwrite(bmp.idata, bmp.bih.biSizeImage, 1, file);

    fclose(file);
}

BYTE getColor(BMP bmp, int color, int x, int y)
{
    return bmp.idata[(x * 3 + y * bmp.trueWidth + color)];
}