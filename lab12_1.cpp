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

void stat(const double Array[], int size, double Ans[]){
    double sum = 0,min,max,sumexpo = 0,sumgeo = 1, sumharmonic = 0,std;
    max = Array[0];
    min = Array[0];

    for(int i = 0; i< size ; i++){
        sum+=Array[i];
        sumexpo += pow(Array[i],2);
        sumgeo = sumgeo*Array[i];
        sumharmonic = sumharmonic + (1/Array[i]);
        if(max < Array[i]){
            max = Array[i];
        }
        if(min > Array[i]){
            min = Array[i];
        }
    }

    std = (sumexpo/size) - pow((sum/size),2);
    Ans[0] = sum/size;  //Arithmetric Mean
    Ans[1] = sqrt(std);  //Standard Deviation
    Ans[2] = pow(sumgeo,(1.0/size)); // Geometric Mean
    Ans[3] = size/sumharmonic; // Harmonic Mean
    Ans[4] = max;
    Ans[5] = min;
}
