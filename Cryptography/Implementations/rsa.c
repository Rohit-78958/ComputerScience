#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double coprime(double totient){
  for(double i=2;i<totient;i++)
    if(fmod(totient,i)!=0) return i;
}

double compute(double a, double b, double c){
  return fmod(pow(a,b),c);
}


int main(){
  int p=3, q=7;
  double n = p*q, totient = (p-1)*(q-1);
  printf("n=%lf totient = %lf",n,totient);
  double e = coprime(totient);
  int i=1;
  double d;
  while(1){
    d = (1+(i*totient))/e;
    double d1 = (1+(i*totient))/e;
    if(ceil(d1) - d == 0) break;
    i++;
  }
  printf("\ne = %lf  i=%d  d=%lf",e,i,d);
  
  double msg;
  int choice;
  while(1){
    printf("\n\n######### RSA::CHOOSE THE FOLLOWING ########\n");
    printf("1. Encrypt    2.Decrypt     3.Exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1: 
              printf("Enter the message to encrypt: ");
              scanf("%lf",&msg);

              double encrypt = compute(msg, e, n);
              printf("\nEncrypted message:%lf",encrypt);
              break;
      
      case 2: 
              printf("Enter the message to decrypt: ");
              scanf("%lf",&msg);

              double decrypt = compute(msg, d, n);
              printf("\nEncrypted message:%lf",decrypt);
              break;

      case 3: printf("\nGoodBye");
              exit(0); 
              break;

      default: printf("\n Enter the correct Number dude!\n");
    } 
  } 
  return 0;
}
