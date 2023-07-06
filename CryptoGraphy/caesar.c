#include<stdio.h>
#include<stdlib.h>

void encrypt(char plainText[], int key){
  int i=0;
  while(plainText[i]!='\0'){
      plainText[i]=(plainText[i]-'a' + key)%26+'a';
      i++;
  }      
  printf("\nEncrypted Text is: %s",plainText);
}

void decrypt(char cipherText[], int key){
  int i=0;
  while(cipherText[i]!='\0'){
      cipherText[i]=(cipherText[i]-'a' - key +26)%26 +'a';
      i++;
  }      
  printf("\nEncrypted Text is: %s",cipherText);
}

int main(){
    
  while(1){
    printf("\n\n#########CHOOSE THE FOLLOWING########\n");
    printf("1. Encrypt    2.Decrypt     3.Exit\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
      case 1: char plainText[100];
              printf("Enter the plain text to encrypt: ");
              scanf("%s",plainText);
            
              int key;
              printf("\nEnter the key size:");
              scanf("%d",&key);

              encrypt(plainText, key);
              break;
      
      case 2: char cipherText[100];
              printf("Enter the cipher text to decrypt: ");
              scanf("%s",cipherText);
            
              printf("\nEnter the key size:");
              scanf("%d",&key);

              decrypt(plainText, key);
              break;

      case 3: printf("\nGoodBye");
              exit(0); 
              break;

      default: printf("\n Enter the correct Number dude!\n");
    } 
  } 
  return 0;
}
