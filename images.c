#include <stdio.h>


int** readImageFile(char *fpath, FILE *img) {
    char ftype[3];
    // width: n colunas
    // height: n linhas
    int width, height, gray_max;
    // final image matrix
    int** imgmx;

    img = fopen(fpath, "r");

    // verifying if its a pgm file
    fgets(ftype, 3, img);
    if(strcmp(ftype, "P2") == 0) {

        // if so, then catch the size of the image and the max gray level
        fscanf(img, "%d %d\n %d\n", &width, &height, &gray_max);

        // dinaamically allocating the matrix => source code: CELES, Waldemar (Introducao a Estrutura de Dados com Tecnicas de Programacao em C - pg 109)
        imgmx = malloc(height * sizeof (int*));
        for (int i=0; i < height; i++) {
            imgmx[i] = malloc(width * sizeof (int));
        }

        // actually reading the pixels, now that all the space we need are allocated in the memmory
        for(int i=0; i < height; i++) {
            for(int j=0; j < width; j++) {
                fscanf(img, "%d", &imgmx[i][j]);
            }
        }

    }

    fclose(img);
    return imgmx;
}