#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <time.h>    

using namespace std;
      
    
int main(){
    
    
    complex<double> z_0(2,2), one(1,0), three(3,0), change, z_n;
    double d_change = 0.000001;
    int N = int(2/d_change);
    double esp = 1e-10;
    
    for(int i=0; i<2*N; i++){
        int count = 0;
        z_n = {0,0};
        z_n = z_0 - (z_0*z_0*z_0 - one)/(z_0*z_0)*three;
        complex <double> increm = (z_n - z_0);
 
        while(abs(increm)>esp){
            //cout<<"while loop"<<abs(increm)<<endl;
            increm = z_n;
//            cout<<"# "<<real(z_n)<<"\t"<<imag(z_n)<<endl;
            complex<double> nomina =(z_n*z_n*z_n - one);
            complex<double> denom = (z_n*z_n)*three;
            z_n -= nomina/denom;
            increm = z_n - increm;
            count++;
        }
        
        cout<<real(z_0)<<"\t"<<imag(z_0)<<"\t"<<count<<endl;
        change =  {(i%2)*d_change, ((i+1)%2)*d_change};
        z_0 -= change;
        
    };
/*one{3,0};
cout<<real(one)<<imag(one)<<endl;
one = {55,99};
cout<<real(one)<<imag(one)<<endl;
one = {100,222};
cout<<real(one)<<imag(one)<<endl;    
*/
    
    
    return 0;
};  
