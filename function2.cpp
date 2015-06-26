#include <iostream>
#include <cmath>
#include <complex>
#include <ctime> //for seeding the random number with time
#include <cstdlib> 
#include <functional>
#include <vector>

using namespace std;

complex<double> operator+(complex<double> a, double b){return {a.real()+b, a.imag()};}
complex<double> operator-(complex<double> a, double b){return {a.real()-b, a.imag()};}

auto Function1 = [](double b, double c){return b+c;};

auto Function2 = [](double func(double, double), double d){return func(d,d) + d;};

auto Fun1 = [](double a){return log(a);};

//Template for monte carlo, can receive type T function, automatic conversion of type to complex in function itself
template<typename T, typename Vec>
T MonteCarlo(T func(T, Vec), Vec V , double Start, double End, double N){
  srand(time(NULL));
  double u;
  T finalsum{0.0};

  for (auto i=0; i<=N; i++)
    {
      u = 1.0*rand()/(RAND_MAX);
      T Value{Start + (End-Start)*u}; //I admit that this is dirty, but this should convert any type to T
      finalsum = finalsum + func(Value,V);
      
    }
  return finalsum*(End-Start)/N;
}

//auto Dilog = [](double z){return MonteCarlo(Fun1,1,z,1000);};

//template<typename T, typename Vec>
complex<double> GeneralLog(complex<double> y, vector<double> V)
{
  return pow(abs(log(y)),V[0]-1.0)/(1.0-V[1]*y);
}

//auto Trilog = [](double z){return GeneralLog(2,3,z);};

auto Test1 = [](double z){return z;};
auto Test2 = [](double z, double (func)(double)){
  double a = 10.0;
  return func(a) + z;
};
auto Test3 = [](double z){return Test2(2,Test1);};

int main()
{
  vector<double> Vec{4.0,2.0};

  //double answer = MonteCarlo(Trilog,0,1,100);
  //complex<double> answer = GeneralLog(9.0,Vec);
  complex<double> answer = MonteCarlo(GeneralLog,Vec,1.0,3.0,10000);
  complex<double> answer2 = complex<double>{1.0};
  cout << answer << answer2 << endl;
  return 0;
}
