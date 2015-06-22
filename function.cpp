#include <iostream>
#include <cmath>
#include <complex>
#include <ctime> //for seeding the random number with time
#include <cstdlib> 
#include <functional>

using namespace std;

complex<double> PolyLog(complex<double> z, int N, int Accu)
{
  complex<double> Sum(0,0);
  for(auto i=1; i<=Accu; i++)
    {
      Sum = Sum + pow(z,i)/complex<double>(pow(i,N),0);
    }
  return Sum;
}



complex<double> MonteCarlo(complex<double> (func)(complex<double>), double Start, double End, int Number)
{
  srand(time(NULL));
  double u;
  complex<double> fs(0,0);

  for (auto i=0; i<=Number; i++)
    {
      u = 1.0*rand()/(RAND_MAX);
      complex<double> v(Start + (End-Start)*u,0);
      fs = fs + func(v);
      
    }

  return fs*(complex<double>(End,0)-complex<double>(Start,0))/complex<double>(Number,0);
  
}

complex<double> Afunction(complex<double> a)
{
  return log(a);
}

complex<double> Dilog(complex<double> z)
{
  return MonteCarlo(Afunction,1,z.real(),1000);
}

complex<double> Trilog(complex<double> z)
{
  return MonteCarlo(Dilog,1,z.real(),1000);
}

// monte[f[x_],a_,b_,n_], dilog[monte[log[x],0,x_,100]]

double Function1(double a)
{
  return log(a);
}


double Function2(double func)
{
  double a = 3.14;
  double answer = func + a;
  return answer;
}


int main()
{
  double b = 2.0;
  double Func1 = Function2(Function1(b));
  complex<double> answer = PolyLog(complex<double>(3,0),3,1000);

  cout << answer << endl;
  return 0;
}
