#include <stdio.h>

// 素数
#define N 2999

int A[N];


// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

void sort(int A[],int n){
 int q,i;
for(q = n;q>1;q--){
      for(i=1;i<q;i++){
      if(A[i]<A[i-1]){
         swap(A+i,A+i-1);
      }
      }
    }
}

int quick_select(int A[], int n, int k){
  int i, j, r,  x, pivot;
  int B[N];
      if (n <= 5){
           sort(A,n);
         return A[k];
   }
    else{
    for(i=0;i*5<n-5;i++){
     sort(A+i*5,5);
     B[i] =A[i*5+2];
      }
          if (n-5*i > 0){
        sort(A+i*5,n-5*i);
        B[i] = A[i*5+(n-5*i)/2];
        }
      pivot = quick_select(B,(n+4)/5,n/10);
      for(i = j = x=0; i < n-x; i++){
       if(A[i] < pivot){
        swap(A+i, A+j);
        j++; 
       }
       else if(A[i] > pivot){
           swap(A+i,A+n-x-1);
        x++;
        i--;
       }
       }
       
     r = j;
    if (r < k && n-x > k){
        return pivot;
        }
        else{ 
        if(n-x <= k) {
         return quick_select(A+n-x,x,k-n+x); 
         }
        else{
           return  quick_select(A,r,k); 
           }
         }
    }
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
  //    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
