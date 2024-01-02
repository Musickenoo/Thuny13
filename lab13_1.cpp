#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum=0,s1=0,s2=1,s3 = 0,Max=A[0],Min=A[0];
    for(int i = 0 ; i < N ; i++){
        sum += A[i] ;
        s2 *= A[i];
        s3 += 1/A[i];
        if(A[i]>Max) Max = A[i];
        if(A[i]<Min) Min = A[i];
    }
    B[0] = sum/N ;
    for(int j = 0;j<N;j++){
        s1 += pow(A[j]-(sum/N),2);
    }
    B[1] = sqrt(s1/N);
    B[2] = exp(log(s2) / N);
    B[3] = N/s3;
    B[4] = Max;
    B[5] = Min;

}