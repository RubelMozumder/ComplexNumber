#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <time.h>    
using namespace std;
      
    
int main(){
    
    const int N = 100;
    const double phi_init = 0.0;
    const double phi_end = 2*M_PI;
    const double d_phi = (phi_end-phi_init)/(double)(N-1);
    complex<double> z[N];
    double phi;
    suseconds_t start, end;//Time variable in Microsecond
    start = clock();
    
    string file = "data_1a_without_omp.txt";
    ofstream out(file);
    
    for (int j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      z[j]= {cos(phi),sin(phi)} ;
    }
    
    for (int j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      
      out<<phi<<"\t"<<real(z[j])<<"\t"<<imag(z[j])<<"\t"<<abs(z[j])<<endl;    
    }
    end = clock();
    double execu_time = (end - start);
    cout<<"\n\nTime without OpenMP  "<<execu_time<<" microsecond"<<endl;
    return 0;
    
}; 
    
