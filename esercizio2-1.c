/*
Scrivere una frunzione ricorsiva che, dati due vettori ordinati vet1 e vet2, 
di dimensione r1 ed r2, li fonda, ottenendo il vettore temp, anch'esso orordinato.
Sia il prototipo della funzione 
    int merge(int vet1[],int vet2[],int r1,int r2,int temp[] )
*/
#include <stdio.h>

int merge(int vet1[],int r1,int vet2[],int r2,int temp[] );

int main(){
    int r1 = 4,r2 = 3;
    int vet1[] = {1,2,5,6,7};
    int vet2[] = {4,9,10,11};
    int temp[r1+r2];

    merge(vet1,r1,vet2,r2,temp);

    int i;

    for(i=0;i<r1+r2;i++){
        printf("temp[%d] = %d \n",i,temp[i]);
    }


    return 0;
}

int merge(int vet1[],int r1,int vet2[],int r2,int temp[]){

  if((r1>0) && (r2>0)){//vettori non vuoti
    if(vet1[0] <= vet2[0]){
        temp[0] = vet1[0];
        merge(vet1 +1, r1-1 , vet2,r2,temp+1);
        return r1+r2;
    }else{
        temp[0]=vet2[0];
        merge(vet1,r1,vet2+1,r2-1,temp+1);
        return r1+r2;
    }
  }else if(r2>0){
      temp[0] = vet2[0];
      merge(vet1,r1,vet2+1,r2-1,temp+1);
      return r1+r2;
  }else if(r1>0){
        temp[0] = vet1[0];
        merge(vet1 +1, r1-1 , vet2,r2,temp+1);
        return r1+r2;
  }




}