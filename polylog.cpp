#include <iostream>
#include <algorithm>
#include <ginac/ginac.h>
//#include <boost>


class Parameter {
private:
  double m0,mH;

public:
  Parameter(double mass0, double massH): m0{mass0}, mH{massH} {} 

  double y0() {return m0*m0/mH/mH;}
  double x0() {return std::sqrt(1-4*y0())/(std::sqrt(1-4*y0())+1);}
  
};





class Polylog {
private:
  double x;
  GiNaC::symbol z;

public:
  Polylog(double x0): x{x0} {}

  GiNaC::ex HPLON10() {return -GiNaC::log(x)*GiNaC::Li(2, 0-x);}
  GiNaC::ex HPLO10(GiNaC::symbol z) {return GiNaC::log(z)*GiNaC::Li(2,0-z)-2*GiNaC::Li(3,z);}
  //GiNaC::ex test(GiNaC::symbol z) {return GiNaC::sin(z);}
  GiNaC::ex HPL100() {return -0.5*GiNaC::log(1-x)*GiNaC::pow(GiNaC::log(x),2)-GiNaC::log(x)*GiNaC::Li(2,x)+GiNaC::Li(3,x);}
  GiNaC::ex HPLO100() {return GiNaC::integral(z,0,x,HPLO10(z)/z).evalf();}

};


int main()
{
  Parameter p1 {1,2};
  Polylog p2 {3.4};
  GiNaC::symbol z;

  std::cout << p1.x0() << "\n" << p2.HPLO10(z) << "\n" << p2.HPLO100() << std::endl;

  return 0;
}
