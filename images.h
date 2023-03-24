#pragma once


#ifndef IMAGE_H
#define IMAGE_H

/**
 * tipo de estrutura de imagem baseado em arquivo pgm.
 * 
 * Você pode acessar as seguintes propriedades:
 * int width, height, max_gray_level
 * matrix imgmx
*/
typedef struct image Image;

/**
 * It reads a pgm file from path:fpath and stores it as an Image structure
*/
void getImageContent(char *fpath, Image** image);

/**
 * 
*/
void negative(Image** original, Image** copia);

/**
 * 
*/
void flipping(Image** original, Image** copia);

/**
 * Allocates memory for the image based on it's width and height
 * Stores width, height and max_gray_level on an Image
 * source code: CELES, Waldemar (Introducao a Estrutura de Dados com Tecnicas de Programacao em C - pg 109)
 * 
*/
void initializeImage(Image** image, int *dimensions);

/**
 * Returns an int array with width, height and max_gra_level of an Image
*/
void getImageDimensions(Image** original_image, int *dimensions);

#endif