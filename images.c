#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "images.h"

struct image {
    // width: n colunas
    // height: n linhas
    // imgmx: final image matrix
    
    int width;
    int height;
    int max_gray_level;
    int** imgmx;
};


void getImageContent(char *fpath, Image** image) {
    FILE *fpgm;
    int dimensions[3];

    char *extension = fpath + strlen(fpath) - 3;

    // verifying if its a pgm file
    if(strcmp(extension, "pgm") == 0) {
        
        // if so, then it tries to the file
        fpgm = fopen(fpath, "r");

        if(fpgm) {

            // unsed line == "P2"
            fgets(extension, 3, fpgm);
            
            // catching the size of the image and the max gray level
            fscanf(fpgm, "%d %d\n %d\n", &dimensions[0], &dimensions[1], &dimensions[2]);

            // if the image can be read, then original_image will be dynamically allocated
            initializeImage(&(*image), dimensions);
            
            // actually reading the pixels, now that all the space we need are allocated in the memory
            for(int i=0; i < (*image)->height; i++) {
                for(int j=0; j < (*image)->width; j++) {
                    fscanf(fpgm, "%d", &(*image)->imgmx[i][j]);
                }
            }

        }
        else {
            printf("Não foi possível realizar a leitura do arquivo informado.\n");
        }

        fclose(fpgm);
    }
    else {
        printf("Tipo de arquivo não suportado.\n");
    }

}

void getImageDimensions(Image** original_image, int *dimensions) {
    dimensions[0] = (*original_image)->width;
    dimensions[1] = (*original_image)->height;
    dimensions[2] = (*original_image)->max_gray_level;
}

void initializeImage(Image** image, int *dimensions) {
    *image = (Image*) malloc(sizeof( Image ));

    (*image)->width = dimensions[0];
    (*image)->height = dimensions[1];
    (*image)->max_gray_level = dimensions[2];

    (*image)->imgmx = malloc((*image)->height * sizeof (int*));
    for (int i=0; i < (*image)->height; i++) {
        (*image)->imgmx[i] = malloc((*image)->width * sizeof (int));
    }
}

void negative(Image** original, Image** copia) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            (*copia)->imgmx[i][j] = 255 - (*original)->imgmx[i][j];
        }
    }
}

void flipping(Image** original, Image** copia) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            (*copia)->imgmx[i][j] = (*original)->imgmx[i][19-j];
            (*copia)->imgmx[i][19-j] = (*original)->imgmx[i][j];
        }
    }
}