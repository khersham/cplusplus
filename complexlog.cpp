#include <iostream>
#include <cmath>
#include <complex>
#include <ctime> //for seeding the random number with time
#include <cstdlib> //for random number

using namespace std;

complex<double> MonteCarlo(complex<double>(*func)(complex<double>), double Start, double End, double Number)
{
  srand(time(NULL));
  double u;
  complex<double> x;
  complex<double> fs(0,0);

  for (auto i=0; i<=Number; i++)
    {
      u = 1.0*rand()/(RAND_MAX);
      complex<double> v(Start + (End-Start)*u,0.0);
      fs = fs + func(v);
      
    }

  return fs*(End-Start)/Number;
  
}


complex<double> func (complex<double> x)
{
  //std::complex a = std::complex::log(); 
  return log(complex<double>(1,0)-x)/x;

}


int main ()
{
  complex<double> num1{MonteCarlo(func,0,3,100000.0)};
  complex<double> num2(-2,3);

  cout << num1  << endl;
  
  return 0;
}
