#include <iostream>
void MERGE(int* A,int p,int q,int r){ 
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i=0; i<n1; i++)
        L[i] = A[p+i];
    for(int j=0; j<n2; j++)
        R[j] = A[q+1+j];
    int i = 0;
    int j = 0;
    for(int n=p; n<=r; n++){
       if(L[i]<=R[j]&&i<n1){
           A[n] = L[i];
           i++;
       }
       else if(R[j]<=L[i]&&j<n2){
           A[n] = R[j];
           j++;
       }
       else if(i==n1){
           A[n] = R[j];
           j++;
       }
       else if(j==n2){
           A[n] = L[i];
           i++;
       }
    }
    delete [] L;
    delete [] R;
}

void MERGE_SORT(int* A,int p,int r){
    if(p<r){
        int q = (int)(p+r)/2;
        MERGE_SORT(A,p,q);
        MERGE_SORT(A,q+1,r);
        MERGE(A,p,q,r);
    }
}


int main()
{
    /* code */
    int list[] = {1,8,6,5,4,2,3,11,32,54};
    MERGE_SORT(list,0,9);
    for(int i=0;i<10;i++)
        std::cout << list[i]<<" ";
    getchar();
    return 0;
}