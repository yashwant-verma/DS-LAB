/*
Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
Find the number(between 1 to N), that is not present in the given array.
*/


#include<stdio.h>

int main(){

    int i,n,arr[50],missNum;
    int sum=0,sum1=0;
    printf("Enter the size of an array ");
    scanf("%d",&n);
    for(i =0 ;i< n-1; i++){
        scanf("%d",&arr[i]);
    }
    
    for(i =0 ;i< n-1; i++){
        sum1+=arr[i];
    }

    sum=(n*(n+1))/2;
    missNum=sum-sum1;

    printf("Missing Number is = %d",missNum);

    return 0;
}