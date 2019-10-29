#include <stdio.h>

int binarySearch(int v[],int Temporary[], int key, int lenght){
   
    int limPre = 0;
    int limPos = lenght-1;
    int middle, aux;
   
    while(limPre <= limPos){
        middle = (limPre+limPos)/2;
        aux = Temporary[middle];
   
        if(  v[aux] < key)
            limPre = middle+1;
        else
            limPos = middle-1;           
    }
   
    return limPre;   
}

int main(){
    int i =0;
    int v[100000],Results[100000], Temporary[100000];
    int len=0;
   
    while(scanf("%d", &v[i]) == 1){
       
        if(    i == 0){
            Temporary[0] = 0;   
        }
        else if(v[i] < v[Temporary[0]]){
            Temporary[0] = i;
        }
        else if( v[i] > v[Temporary[len]]){
            len++;
            Temporary[len] = i;
            Results[Temporary[len]] = Temporary[len-1];
        }else{
            int index = binarySearch(v,Temporary,v[i],len); 
            Temporary[index] = i;  
            Results[Temporary[index]] = Temporary[index-1];
        }   
           
        i++;   
    }
   
    int index = Temporary[len];
    printf("%d\n-\n", len+1);
    int FinalSolution[len+1];
   
    for(int i=0;i<=len;i++){
        FinalSolution[i] = v[index];
        index = Results[index];   
    }
    len++;

    while(len--){
        printf("%d\n", FinalSolution[len]);
    }
   
}
