#include <iostream>
#include<string.h>

using namespace std;

int main(){
  double average[3];
  for(int i=0; i< 3; i++){
      average[i] = 0;
  }
  FILE* Read=fopen("ReadTest.txt","r");
  FILE* Write=fopen("Average.txt","w"); 
  char Name[4][20], Date[20];
  float Index[3];
  fscanf(Read,"%s %s %s %s", Name[0],Name[1],Name[2],Name[3]);
  printf("%7s %7s %7s %9s\n", Name[0],Name[1],Name[2],Name[3]);
  fprintf(Write, "%7s %7s %7s %9s\n", Name[1],Name[2],Name[3], Name[0], "Average");
  while(fscanf(Read,"%s %f %f %f",Date,&Index[0],&Index[1],&Index[2])!=EOF)
  {
   printf("%7s %7.2f %7.2f %7.2f\n",Date,Index[0],Index[1],Index[2]);
   average[0] = average[0] + Index[0];
   average[1] = average[1] + Index[1];
   average[2] = average[2] + Index[2];
   fprintf(Write, "%f %f %f %s\n", Index[0],Index[1],Index[2],Date);
  } 
  average[0] = average[0] / 4;
  average[1] = average[1] / 4;
  average[2] = average[2] / 4;
  fprintf(Write, "%f %f %f %s\n", average[0],average[1],average[2], "Average");
  fclose(Write);
  fclose(Read);
}