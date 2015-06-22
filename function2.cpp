#include <iostream>
#include <cmath>
#include <complex>
#include <ctime> //for seeding the random number with time
#include <cstdlib> 
#include <functional>

using namespace std;

auto Function1 = [](double b, double c){return b+c;};

auto Function2 = [](double func(double, double), double d){return func(d,d) + d;};

auto Fun1 = [](double a){return log(a);};

auto MonteCarlo = [](double func(double), double Start, double End, int N){
  srand(time(NULL));
  double u;
  double fs{0};

  for (auto i=0; i<=N; i++)
    {
      u = 1.0*rand()/(RAND_MAX);
      double v{Start + (End-Start)*u};
      fs = fs + func(v);
      
    }
  return fs*(End-Start)/N;
};

auto Dilog = [](double z){return MonteCarlo(Fun1,1,z,1000);};

auto Trilog = [](double z){return MonteCarlo(Dilog,1,z,100000);};

auto Test1 = [](double z){return z;};
auto Test2 = [](double z, double (func)(double)){
  double a = 10.0;
  return func(a) + z;
};
auto Test3 = [](double z){return Test2(2,Test1);};

int main()
{
  //double answer = Trilog(9);
  double answer2 = Test3(2);
  cout << answer2 << endl;
  return 0;
}
