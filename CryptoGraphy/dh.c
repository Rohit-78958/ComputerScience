#include<stdio.h>
#include<math.h>

int compute(int a, int b, int c){
  return fmod(pow(a,b),c);
}

int main(){
  int alpha=5, q=23;
  int a,b;
  printf("\n enter private key of a:");
  scanf("%d",&a);
  printf("\n enter private key of b:");
  scanf("%d",&b);
  int A = compute(alpha,a,q);
  printf("\nThe public of a:%d",A);
  int B = compute(alpha,b,q);
  printf("\nThe public of a:%d",B);
  int ka = compute(B,a,q); 
  int kb = compute(A,b,q);
  printf("\nSecret key Ka=%d & Kb=%d",ka,kb);
  return 0;
}
