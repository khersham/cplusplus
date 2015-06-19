#include <iostream>

class complex{
private:
  double re, im;

public:
  complex(double r, double i): re{r}, im{i} {}
  complex(double r): re{r}, im{0} {}
  complex(): re{0}, im{0} {}

  double real() const {return re;}
  void real(double d) {re=d;}
  double imag() const {return im;}
  void imag(double d) {im=d;}

  complex& operator+=(complex z) {re+=z.re, im+=z.im; return *this;}


};

complex operator+(complex a, complex b) {return a+=b;}

int main()
{
  complex a {2.3, 4.9};
  complex b {4.8, 2.1};

  complex c = a + b;
  complex d = a+=b;

  std::cout << c.real() << "+I" << c.imag() << std::endl;
  std::cout << d.real() << "+I" << d.imag() << std::endl;

  return 0;
}
