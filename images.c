#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

struct pgm_image getImageContent(char *fpath) {
    char ftype[3];
    FILE *fpgm;
    struct pgm_image image;

    fpgm = fopen(fpath, "r");

    if(fpgm) {
        // verifying if its a pgm file
        fgets(ftype, 3, fpgm);
        if(strcmp(ftype, "P2") == 0) {

            // if so, then catch the size of the image and the max gray level
            fscanf(fpgm, "%d %d\n %d\n", &image.width, &image.height, &image.max_gray_level);

            // dinaamically allocating the matrix => source code: CELES, Waldemar (Introducao a Estrutura de Dados com Tecnicas de Programacao em C - pg 109)
            image.imgmx = malloc(image.height * sizeof (int*));
            for (int i=0; i < image.height; i++) {
                image.imgmx[i] = malloc(image.width * sizeof (int));
            }

            // actually reading the pixels, now that all the space we need are allocated in the memmory
            for(int i=0; i < image.height; i++) {
                for(int j=0; j < image.width; j++) {
                    fscanf(fpgm, "%d", &image.imgmx[i][j]);
                }
            }

        }
    }
    else {
        printf("Não foi possível realizar a leitura do arquivo informado.\n");
    }

    fclose(fpgm);
    return image;
}