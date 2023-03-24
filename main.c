#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "images.h"
#include "images.c"

// option menu
void showMenu() {
   printf("\n----------------------------------------");
   printf("\nEscolha uma das opções abaixo:\n");
   printf("1. Selecionar o caminho da imagem\n");
   printf("2. Aplicar filtro sobre imagem\n");
   printf("0. Fechar o programa\n");
}

void showFilterMenu() {
   printf("\n1. Negativo\n");
   printf("2. Espelhamento\n");
   printf("3. Borramento\n");
   printf("4. Brightening\n");
   printf("0. Cancelar\n");
}

// option choosing logic
void getUserOption(int *op) {
   printf("OP: ");
   scanf("%d", op);
}

// image choosing logic ** it is in the main file bc of relative path: not applied for other contexts
void getImagePath(char* fpath) {

   // in case the user has alredy chosen an image
   if(strlen(fpath) != 0) {
      char op;

      // do you want to keep that?
      printf("\nJá existe uma imagem selecionada para a execução do programa.\n");
      printf("Imagem armazenada: %s.\n", fpath);
      printf("Deseja manter a imagem atual? [s|n]: ");
      scanf(" %c", &op);

      // case you dont, change it
      if(op == 'n') {
         printf("\nCaminho da imagem: ");
         scanf("%s", fpath);
      }
   } 
   else {
      // first choosing
      printf("\nCaminho da imagem: ");
      scanf("%s", fpath);
   }
   
}

// filter choosing logic
void applyFilter(Image** original_image, Image** final_image) {
   
   int filtro;
   int dimensions[3];

   // verifying if it really has something to apply a filter
   if(original_image != NULL) {

      // choose filter
      showFilterMenu();
      getUserOption(&filtro);

      // initialize a new image to store the result
      getImageDimensions(original_image, dimensions);
      initializeImage(final_image, dimensions);

      // c) o programa aplica o filtro escolhido armazenando numa imagem resultado
      // apply the filter
      switch (filtro)
      {
      case 1:
         printf("Negativo\n");
         negative(original_image, final_image);
         break;
      case 2:
         printf("Espelhamento\n");
         flipping(original_image, final_image);
         break;
      case 3:
         printf("Borramento\n");
         // blurring(original_image, final_image);
         break;
      case 4:
         printf("Brightening\n");
         // brightening(original_image, final_image);
         break;
      default:
         break;
      }

   }

   
}


int main() {

   // variable declaration
   int op;
   char fpath[35];
   Image* original_image = NULL;
   Image* final_image = NULL;
   FILE *pgm_result;
   
   // setting things up
   printf("Bem vindo ao MyPhotoshop!\n\n");
   showMenu();
   getUserOption(&op);
      
   while(op != 0) {

      // processing what the user wants
      switch (op)
      {
         case 1:
            getImagePath(fpath);
            break;
         case 2:
            if(strlen(fpath) == 0 ) {
               printf("Opção inválida. Selecione uma imagem.");
            }
            else {
                if(original_image == NULL) {
                  // the has not been read yeat | or have a error
                  getImageContent(fpath, &original_image);
               }
               
               //  EXCLUIR DEPOIS apenas imprimindo a matriz
               for(int i=0; i < 20; i++) {
                  for(int j=0; j < 20; j++) {
                        printf("%d ", original_image->imgmx[i][j]);
                  }
                  printf("\n");
               }

               printf("\n");

               applyFilter(&original_image, &final_image);

               //  EXCLUIR DEPOIS apenas imprimindo a matriz
               for(int i=0; i < 20; i++) {
                  for(int j=0; j < 20; j++) {
                        printf("%d ", final_image->imgmx[i][j]);
                  }
                  printf("\n");
               }

            }
         default:
            break;
      }

      // setting things up again
      showMenu();
      getUserOption(&op);

   }

   return 0;
}