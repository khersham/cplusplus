#include <iostream>

struct Vector
{
   int sz;
   double* elem;
};
  
void vector_init(Vector& v, int s)
{
   v.elem = new double[s];
   v.sz = s;

}

double read_and_sum(int s)
{

  Vector v;
  vector_init(v,s);
  for(auto i=0; i!=s; ++i)
    cin >>v.elem[i];

  double sum;
  for(auto i=0; i!=s; ++i)
    sum +=v.elem[i];

  return sum;

}

int main()
{



 return 0;

}
