#include <stdio.h>
#include <stdlib.h>

//Represents a pixel in colored image
typedef struct{
    unsigned char r,g,b; //ASCII BASED ENCODING
} PPMpixel;

//Represents a colored PPM image
typedef struct{
    int width,height;
    PPMpixel *data; // array of pixels
} PPMimg;

//Represents a Pixel in monochrome image
//monochrome -> variations in light to create image
typedef struct{
    unsigned char i;
} PPMpixelM;

//Represents a monochrome ppm image
typedef struct{
    int width,height;
    PPMpixelM *data;//array of pixels
} PPMimgM;


PPMimg* readPPM(const char *filename)
{
    FILE *fp = fopen(filename,"rb");
    char buf[16];
    
    fgets(buf,sizeof(buf),fp);
     //fgets stops on new line therefore this part  will just read version
	 //reading data from the stream into buffer array
    

    char c = getc(fp);
    while (c == '#') {
    while (getc(fp) != '\n') ;
         c = getc(fp);
    }
    ungetc(c,fp);
//#Created by %s\n    -> to store this section of decrypt algorithm

    unsigned int width,height,rgb_comp_color;
    fscanf(fp,"%d %d",&width,&height);
    fscanf(fp,"%d",&rgb_comp_color);

    while (fgetc(fp) != '\n');//ensures successful read of w,h,color_comp
    
    
    PPMpixel *data = (PPMpixel*)malloc(width*height*sizeof(PPMpixel));

    fread(data,sizeof(PPMpixel),width*height,fp);

    PPMimg *img = (PPMimg*)malloc(sizeof(PPMimg));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

void writePPM(char *file_name, unsigned char *data,
                       unsigned int width, unsigned int height,
                       unsigned int channels) {
  FILE *handle = fopen(file_name, "w");
  if (channels == 1) {
    fprintf(handle, "P5\n");
  } else {
    fprintf(handle, "P6\n");
  }
  fprintf(handle, "#Created by %s\n", __FILE__);
  fprintf(handle, "%d %d\n", width, height);
  fprintf(handle, "255\n");

  fwrite(data, width * channels * sizeof(unsigned char), height, handle);

  fflush(handle);
  fclose(handle);
}

unsigned char* ppmTochar(PPMpixel* img,int width,int height)
{
    unsigned char* image = (unsigned char*)malloc(width*height*3);

    int i,n=width*height,k=0;
    for(i=0;i<n;i++){
        image[k++]=img[i].r;
        image[k++]=img[i].g;
        image[k++]=img[i].b;
    }
    return image;
}

unsigned char* ppmTocharM(PPMpixelM* img,int width,int height)
{
    unsigned char *image = (unsigned char*)malloc(width*height);

    int i,n=width*height,k=0;
    for(i=0;i<n;i++){
        image[k++]=img[i].i;
    }
    return image;
}
    
