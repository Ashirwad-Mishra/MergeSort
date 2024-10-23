#include <stdio.h>

void merge(int A[],int start , int mid , int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int B[n1];
    int C[n2];
    for (int i = 0 ; i < n1 ; i++)
        {
            B[i] = A[start + i];
        }
    for (int j = 0 ; j < n1 ; j++)
        {
            C[j] = A[mid + 1 + j];
        }
    
    int i = 0;
    int j = 0 ; 
    int k = start ; 
    while (i<n1 && j < n2)
        {
            if (B[i]<=C[j])
            {
                A[k] = B[i];
                i++;
            }
            else if (B[i]>C[j])
            {
                A[k] = C[j];
                j++;
            }
            k++;
        }
    if (i < n1)
    {
        A[k] = B[i] ;
        i++;
        k++;
    }
    if (j < n2)
    {
        A[k] = C[j] ;
        k++;
        j++;
    }
}
void sort(int A[],int start,int end)
{
    if (start < end)
    {
        int mid = start + (-start + end)/2;
        sort(A,start , mid);
        sort(A,mid+1,end);
        merge(A,start,mid,end);
    }
}
void printA(int A[],int n)
{
    for (int i = 0 ; i < n ; i ++)
        {
            printf("%d ",A[i]);
        }
}
int main() {
    int A[10] = {12,67,34,67,23,98,45,78,56,89};
    printf("\nThe Given Arraay: ");
    printA(A,10);
    sort(A,0,9);
    printf("\nThe sorted array: ");
    printA(A,10);
    return 0;
}
