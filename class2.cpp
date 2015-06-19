#include <iostream>
#include <initializer_list>
#include <algorithm>


class Vector{
private:
  double* elem;
  int sz;

public:
  //Vector(int s): elem{new double[s]}, sz{s} 
  //{
  //  for(auto i=0; i != s ; ++i)
  //    elem[i]=0;
  //} 

  Vector(std::initializer_list<double> lst): elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
  {
    std::copy(lst.begin(),lst.end(),elem);
  }
  
  ~Vector() {delete[] elem;}

  double& operator[](int i){return elem[i];}
  int size() const {return sz;}
};


int main()
{
  Vector v1 {1,2,3,4,5};

  for(auto i=0; i!=v1.size(); ++i)
    std::cout << v1[i] << "\n";

  return 0;
}
