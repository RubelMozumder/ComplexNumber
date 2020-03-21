#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>    
using namespace std;
    
complex<double> f(double phi){
    return tan(complex<double>(1,1)*phi);
};  
    
int main(){
    
    const int N = 100;
    const double phi_init = -1.0*M_PI;
    const double phi_end = M_PI;
    const double d_phi = (phi_end-phi_init)/(double)(N-1);
    complex<double> z[N];
    double phi;
    
    string file = "data_1b.txt";
    ofstream out(file);
    
    for (int j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      z[j]= f(phi);
    }
    
    for (int j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      
      out<<phi<<"\t"<<real(z[j])<<"\t"<<imag(z[j])<<"\t"<<abs(z[j])<<endl;    
    }
    return 0;
};  
    
