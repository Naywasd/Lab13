#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0;
    double sumpower = 0;
    double geo = 1;
    double harmo = 0;
    double Max = A[0];
    double Min = A[0];
    
    for (int i = 0; i < N; i++){
        sum += A[i];
        sumpower += A[i]*A[i];
        geo *= A[i];
        harmo += 1.0/A[i];
        
        if(A[i] > Max) Max = A[i];
        if(A[i] < Min) Min = A[i];
    }
    
    B[0] = sum/N;
    B[1] = sqrt(sumpower/N - B[0]*B[0]);
    B[2] = pow(geo,1.0/N);
    B[3] = N/harmo;
    B[4] = Max;
    B[5] = Min;
}
