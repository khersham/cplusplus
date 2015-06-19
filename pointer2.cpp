#include <iostream>
#include <stdexcept>


class Vector{
public:
  Vector(int s){ 
    if(s<0)
      throw std::length_error{};
    elem {new double[s]}; 
    sz {s};
  }
  
  double& operator[](int i) {
    if (i<0 || size()<=i)
      throw std::out_of_range{"Vector::operator[]"};
    return elem[i];}
  int size() {return sz;}

private:
  double* elem;
  int sz;

};

int main()
{
  
  Vector vec(6);

  try{
    vec[vec.size()]=7;
  }
  catch(out_of_range){
    std::cout<<"Out of range"<< endl; 
  }

  return 0;

}
