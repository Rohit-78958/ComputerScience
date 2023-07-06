#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char plainText[], char key[]){
  int i=0;
  while(plainText[i]!='\0'){
      plainText[i]=(plainText[i]-'a'+ key[i]-'a')%26+'a';
      i++;
  }      
  printf("\nEncrypted Text is: %s",plainText);
}

void decrypt(char cipherText[], char key[]){
  int i=0;
  while(cipherText[i]!='\0'){
      cipherText[i]=((cipherText[i] - key[i]) + 26)%26 +'a';
      i++;
  }      
  printf("\nDecrypted Text is: %s",cipherText);
}

int main(){
  char plainText[100],key[100], cipherText[100];
  int choice;
  while(1){
    printf("\n\n######### VIGENERE CIPHER::CHOOSE THE FOLLOWING ########\n");
    printf("1. Encrypt    2.Decrypt     3.Exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1: 
              printf("Enter the plain text to encrypt: ");
              scanf("%s",plainText);
            
              printf("\nEnter the key:");
              scanf("%s",key);

              //making key same size as plain text
              int len=strlen(key), i=0, p_size=strlen(plainText);
              char newkey[100];
              while(i != p_size){
                  newkey[i]=key[i%len];
                  i++;
              }  
              printf("\nThe new key is:%s",newkey);
              encrypt(plainText, newkey);
              break;
      
      case 2: 
              printf("Enter the cipher text to decrypt: ");
              scanf("%s",cipherText);
              
              printf("\nEnter the key:");
              scanf("%s",key);

              //making key same size as plain text
              len=strlen(key), i=0;
              while(i != p_size){
                  newkey[i]=key[i%len];
                  i++;
              }  
              printf("\nThe new key is:%s",newkey);
              
              decrypt(cipherText, newkey);
              break;

      case 3: printf("\nGoodBye");
              exit(0); 
              break;

      default: printf("\n Enter the correct Number dude!\n");
    } 
  } 
  return 0;
}
