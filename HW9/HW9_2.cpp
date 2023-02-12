#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE* Read=fopen("R.txt","r");
  FILE* Write=fopen("Report.txt","w"); 
  char Name[4][20], Date[20];
  float Index[3];
  fscanf(Read,"%s %s %s", Name[0],Name[1],Name[2]);  
  fscanf(Read,"%s %s %s %s", Name[0],Name[1],Name[2],Name[3]);
  double Profit=0;   
  double Avg=0,PreAvg=0; 
  double BuyCost;  
  double MAArray[5];  
  int  Buy=0, ArrayPtr=0, Count=0;
  fprintf(Write, "%s %s %s %s %s\n", "????", "?????", "?????????", "?l?q", "????");
  while(fscanf(Read,"%s %f %f %f",Date,&Index[0],&Index[1],&Index[2])!=EOF){
    MAArray[ArrayPtr]=Index[0];
	ArrayPtr=(ArrayPtr+1)%5;
	Count=Count+1;    
    if(Count<5) continue;
	PreAvg=Avg;
	Avg=0;
	for(int i=0;i<5;i++){ 
    Avg=Avg+MAArray[i];
    }
	Avg=Avg/5;
	if(Count==5) continue;
	if((Buy==0)&&(Avg<=PreAvg)&&(Index[0]<=Avg)){
	 BuyCost=Index[0];
	 Buy=-1;
	}
	if((Buy==-1)&&(Avg>=PreAvg)&&(Index[0]>=Avg)){
	 Profit=Profit+(BuyCost - Index[0]);
	 Buy=0;
	}
	fprintf(Write, "%s %f %f %f %d\n", Date, Index[0], Avg, Profit, Buy);
  }
   if(Buy==-1){
	  Profit=Profit+(BuyCost - Index[0]);
    fprintf(Write,"????: %f",Profit);
   }
  fclose(Write);
  fclose(Read);

system("pause");
return 0;
}