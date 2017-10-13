#include <iostream>

using namespace std;

class Shape
{
public:
  Shape(){}
  virtual ~Shape(){}
  virtual long GetArea()=0;		//hiba
  virtual long GetPerim()=0;
  virtual void Draw()=0;
private:
};
void Shape::Draw()
{
cout << "Elvont kirajzolási algoritmus\n";
}

class Circle: public Shape
{
public:
Circle(int radius):itsRadius(radius){}
~Circle(){}
long int GetArea(){return 3*itsRadius*itsRadius;}
long int GetPerim(){return 9*itsRadius;}
  void Draw();
private:
  int itsRadius;
  int itsCircumReference;
};
void Circle::Draw()
{
{cout << "kör kirajzolása" << endl;}
Shape::Draw();
}

class Rectangle: public Shape  //téglalap
{
public:
Rectangle(int len, int width ):itsLength(len),itsWidth(width){}
virtual ~Rectangle(){}
virtual long GetArea() {return itsLength*itsWidth;}
virtual long GetPerim() {return 2*itsLength+2*itsWidth;}
virtual int GetLength() {return itsLength;}
virtual int GetWidth() {return itsWidth;}
virtual void Draw();
private:
  int itsLength;
  int itsWidth;
};

void Rectangle::Draw()
{
for(int i=0;i<itsLength;i++)
{
  for(int j=0;j<itsWidth;j++)
    cout <<"x";

  cout << "\n";
}
Shape::Draw();
}

class Square: public Rectangle
{
public:
  Square(int len);
Square(int len, int width);
~Square(){}
long GetPerim(){return 4*GetLength();}
};

Square::Square(int len): Rectangle(len, len)
{

}
Square::Square(int len, int width): Rectangle(len, width)
{
if(GetLength()!=GetWidth())
  cout <<" ez nem négyzet" << endl;
}

main()
{
  int valasz;
  bool fquit=false;
  Shape *sp;
  
  while(1)
  {
    cout << "(1)Kör\t(2)Téglalap\t(3)Négyzet\t(0)Kilépés: ";
    cin>>valasz;
    switch (valasz)
    {
      case 1 : sp=new Circle(5);break;
      case 2 : sp=new Rectangle(4,6);break;
      case 3 : sp=new Square(5);break;
      default : fquit=true;break;
    }
    if(fquit)
      break;
  
  sp->Draw();
  cout << "\n";
  }
  return 0;
}