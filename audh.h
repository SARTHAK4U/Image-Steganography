#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    long long size;
} MP3File;

MP3File *readMP3(const char *filename)
{

    char *buffer;

    FILE *pFile = fopen(filename, "rb");

    // obtain file size
    fseek(pFile, 0, SEEK_END); //moves pointer to the end of file
    
    long lSize = ftell(pFile); //ftell -> distance from the begining (net size)
    
    rewind(pFile); // rewind -> taking pointer back to start

    buffer = (char *)malloc(sizeof(char) * lSize);
    
    size_t result = fread(buffer, 1, lSize, pFile); // 1- >this is the size in bytes of each element to be read.
    //lsize->This is the number of elements, each one with a size of size bytes (1 bytes).

    MP3File *newFile = (MP3File *)malloc(sizeof(MP3File));
    newFile->data = buffer;
    newFile->size = lSize;

    fclose(pFile);

    return newFile;
}

void writeMP3(const char *filename, char *data, size_t size)
{

    FILE *file = fopen(filename, "wb");
    fwrite(data, 1, size, file);
    fclose(file);
}
