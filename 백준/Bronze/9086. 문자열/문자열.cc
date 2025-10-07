#include <stdio.h>

int main(void) {
  int test=0,count[10]={0};
  char munja[1000];
  scanf("%d",&test);
  for(int i=0;i<test;i++){
    scanf("%s",munja);
   
    for(int p=0; p<1000;p++){
      if((munja[p]<65)||(munja[p]>122))
        break;
      count[i]++;      
    }
    
    printf("%c%c\n",munja[0],munja[count[i]-1]);
  }
  return 0;
}