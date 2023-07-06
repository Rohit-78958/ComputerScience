#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char plainText[], int depth){
  int p_size = strlen(plainText);
  char matrix[depth][p_size];
  for(int row=0;row<depth;row++){
    for(int col=0;col<p_size;col++) matrix[row][col]='_';
  }
  
  int row=0,k=-1;
  for(int col=0;col<p_size;col++){
    matrix[row][col]=plainText[col];

    if(row==0 || row==depth-1) k*=-1;
    row=row+k;
  }
  
  printf("\nThe encrypted text is: ");
  for(int row=0;row<depth;row++){
    for(int col=0;col<p_size;col++) 
      if(matrix[row][col] != '_') printf("%c",matrix[row][col]);
  }
}

void decrypt(char cipherText[], int depth){
  int p_size = strlen(cipherText);
  char matrix[depth][p_size];
  for(int row=0;row<depth;row++){
    for(int col=0;col<p_size;col++) matrix[row][col]='_';
  }
  
  int row=0,k=-1;
  for(int col=0;col<p_size;col++){
    matrix[row][col]='*';

    if(row==0 || row==depth-1) k*=-1;
    row=row+k;
  }
  
  int j=0;
  for(int row=0;row<depth;row++){
    for(int col=0;col<p_size;col++) 
      if(matrix[row][col] == '*') matrix[row][col]=cipherText[j++];
  }
  
  row=0,k=-1;
  printf("\nThe decrypted text is: ");
  for(int col=0;col<p_size;col++){
    printf("%c",matrix[row][col]);

    if(row==0 || row==depth-1) k*=-1;
    row=row+k;
  }
}


int main(){
  char plainText[100], cipherText[100];
  int depth;
  int choice;
  while(1){
    printf("\n\n######### RAILFENCE CIPHER::CHOOSE THE FOLLOWING ########\n");
    printf("1. Encrypt    2.Decrypt     3.Exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1: 
              printf("Enter the plain text to encrypt: ");
              scanf("%s",plainText);
            
              printf("\nEnter the depth:");
              scanf("%d",&depth);

              encrypt(plainText, depth);
              break;
      
      case 2: 
              printf("Enter the cipher text to decrypt: ");
              scanf("%s",cipherText);
              
              printf("\nEnter the key:");
              scanf("%d",&depth);
              
              decrypt(cipherText, depth);
              break;

      case 3: printf("\nGoodBye");
              exit(0); 
              break;

      default: printf("\n Enter the correct Number dude!\n");
    } 
  } 
  return 0;
}
