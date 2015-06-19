#include <iostream>
#include <vector>

class Shape {
public:
 virtual Point center() const =0;
 virtual void move(Point to) =0;

 virtual void draw() const =0;
 virtual void rotate(int angle) =0;

 virtual ~Shape() {}

};

void rotate_all(vector<Shape*>& v, int angle)
{
  for (auto p: v)
    p->rotate(angle);

}

class Circle: public Shape{
private:
  Point x;
  int r;

public:
  Circle(Point p, int rr);

  Point center() const {return x;}
  void move(Point to) {x = to;}
  void draw() const;
  void rotate(int) {}

};


int main()
{

  return 0;
}


