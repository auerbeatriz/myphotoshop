#include <stdio.h>
#include <string.h>
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

// image choosing logic
void getImagePath(char *fpath) {

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
void applyFilter(char *fpath, FILE *img_result) {

   // TO DO: SAVE THE RESULT IN A NEW VARIABLE

   int filtro;
   FILE *img;
   int** imgmx;

   imgmx = readImageFile(fpath, img);

   for(int i=0; i < 20; i++) {
      for(int j=0; j < 20; j++) {
            printf("%d ", imgmx[i][j]);
      }
      printf("\n");
   }

   // choose option
   showFilterMenu();
   getUserOption(&filtro);

   // apply the filter
   switch (filtro)
   {
   case 1:
      printf("Negativo\n");
      // negative(*fpath);
      break;
   case 2:
      printf("Espelhamento\n");
      // flipping(*fpath);
      break;
   case 3:
      printf("Borramento\n");
      // blurring(*fpath);
      break;
   case 4:
      printf("Brightening\n");
      // brightening(*fpath);
      break;
   default:
      break;
   }
}


int main() {

   // variable declaration
   int op;
   char fpath[35];
   FILE *img_result;
   
   // setting things up
   printf("Bem vindo ao MyPhotoshop!\n\n");
   showMenu();
   getUserOption(&op);
   
   while(op != 0) {

      // processing what the user wants
      switch (op)
      {
         case 1:
            getImagePath(&fpath);
            // printf("%s\n", fpath);
            break;
         case 2:
            if(strlen(fpath) == 0 )
               printf("Opção inválida. Selecione uma imagem.");
            else
               applyFilter(&fpath, &img_result);   
         default:
            break;
      }

      // setting things up again
      showMenu();
      getUserOption(&op);

   }

   return 0;
}