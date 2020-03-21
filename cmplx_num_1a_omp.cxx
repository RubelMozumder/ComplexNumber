#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <omp.h>    

using namespace std;
      
    
int main(){
    
    const int N = 100;
    const double phi_init = 0.0;
    const double phi_end = 2*M_PI;
    const double d_phi = (phi_end-phi_init)/(double)(N-1);
    complex<double> z[N];
    double phi;
    
    string file = "data_1a_with_omp.txt";
    ofstream out(file);
double start = omp_get_wtime()*1e6;    
    int j;

#pragma omp parallel
{   //int thre_num = omp_get_num_threads();
    //int ID = omp_get_thread_num();

    #pragma omp for private(j)
    for (j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      z[j]= {cos(phi),sin(phi)} ;
    }
}
double end = omp_get_wtime()*1e6;
cout<<"Time with OpenMP "<<(end-start)<<" microsecond"<<endl;
    
    for (j=0; j<N; j++)
    {
      phi = phi_init + j*d_phi;
      
      out<<phi<<"\t"<<real(z[j])<<"\t"<<imag(z[j])<<"\t"<<abs(z[j])<<endl;    
    }

    return 0;
    
};  
    
