#include <stdio.h>
#include <string.h>

// option menu
void showMenu() {
   printf("\nEscolha uma das opções abaixo:\n");
   printf("1. Selecionar o caminho da imagem\n");
   printf("2. Aplicar filtro sobre imagem\n");
   printf("0. Fechar o programa\n");
}

// option choosing logic
void getUserOption(int *op) {

   printf("OP: ");
   scanf("%d", op);
   
   while(*op < 0 || *op > 3) {
      printf("Opção inválida. OP: ");
      scanf("%d", op);
   }
}

// image choosing logic
void getImagePath(char *fpath) {

   // in case the user has alredy chosen an image
   if(strlen(fpath) != 0) {
      char op;

      // do you want to keep that?
      printf("\nJá existe uma imagem selecionada para a execução do programa.\n");
      printf("Imagem armazenada: pgm/%s.\n", fpath);
      printf("Deseja manter a imagem atual? [s|n]: ");
      scanf(" %c", &op);

      // case you dont, change it
      if(op == 'n') {
         printf("\nCaminho da imagem: pgm/");
         scanf("%s", fpath);
      }
   } 
   else {
      // first choosing
      printf("\nCaminho da imagem: pgm/");
      scanf("%s", fpath);
   }

   
   // strcat("pgm/", fpath);
}

int main() {

   // variable declaration
   int op;
   char fpath[35];
   
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
            printf("OP 2\n");
         default:
            break;
      }

      // setting things up again
      showMenu();
      getUserOption(&op);

   }

   return 0;
}