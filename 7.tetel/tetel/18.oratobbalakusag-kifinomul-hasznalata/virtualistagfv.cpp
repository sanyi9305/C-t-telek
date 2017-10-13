#include <iostream>
using namespace std;

class Emlosok
{
public:
  Emlosok():itsAge(1){cout <<"Emlős konstruktor\n";}
  virtual ~Emlosok(){cout <<" Emlos Destruktor\n";}
  virtual void Speak(){cout <<" Emlos hang\n";}
protected:
  int itsAge;
  
};

class Cat:public Emlosok
{
public:
Cat(){cout <<" macska konstruktor \n";}
virtual ~Cat(){cout <<" destruktor\n";}
void Speak(){cout <<"MIAUU\n";};
void Dorombol(){cout <<" rrrrrrrrrrr\n";}
  
};
class Dog:public Emlosok
{
public:
Dog(){cout <<" macska konstruktor \n";}
virtual ~Dog(){cout <<" destruktor\n";}
void Speak(){cout <<"Vauu\n";};

  
};

main()
{
  Emlosok *pCat=new Cat;
  pCat->Speak();
  pCat->Dorombol();
  
  return 0;
  
}