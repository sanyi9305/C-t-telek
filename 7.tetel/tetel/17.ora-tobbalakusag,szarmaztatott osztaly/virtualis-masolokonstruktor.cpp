#include <iostream> 
using namespace std;
class Emlosok
{
  public:
  Emlosok():itsAge(1){cout << "Emlosok konstruktora" <<endl;}
  virtual ~Emlosok(){cout << "Emlosok destruktora" <<endl;}
  Emlosok(const Emlosok &rhs); //másoló konstruktor
  virtual void speak() const {cout << "Emlős hangja" <<endl;}
  virtual Emlosok* Clone(){return new Emlosok(*this);}
  int GetAge()const {return itsAge;}
  
protected:
  int itsAge;
};

Emlosok::Emlosok(const Emlosok& rhs):itsAge(rhs.GetAge())
{
cout << "Emlosok másoló konstruktora" <<endl;
}

class Dog:public Emlosok
{
public:
Dog(){cout << "Kutya konstruktora" <<endl;}
virtual ~Dog(){cout << "Kutya destruktora" <<endl;}
Dog(const Dog&rhs);					//másoló konstruktor
void speak() const {cout << "Woof woof" <<endl;}
virtual Emlosok* Clone(){return new Dog(*this);}
};

Dog::Dog(const Dog& rhs):Emlosok(rhs)
{
cout << "Kutya másoló konstruktora" <<endl;
}


class Cat:public Emlosok
{
public:
Cat(){cout << "Cica konstruktora" <<endl;}
virtual ~Cat(){cout << "Cica destruktora" <<endl;}
Cat(const Cat&rhs);					//másoló konstruktor
void speak() const {cout << "meow meow" <<endl;}
virtual Emlosok*Clone(){return new Cat(*this);}
};

Cat::Cat(const Cat& rhs):Emlosok(rhs)
{
cout << "Cica másoló konstruktora" <<endl;
}

enum ANIMALS{EMLOS,DOG,CAT};
const int numanimalTypes =3;

main()
{
  Emlosok *tomb[numanimalTypes];
  Emlosok *ptr;
  int valasz,i;
  
  for(i=0;i<numanimalTypes;i++)
  {
    cout << "1 kutya  2 macska  3 emlős" << endl;
    cin>>valasz;
    switch(valasz)
    {
      case DOG: ptr=new Dog;break;
      case CAT: ptr= new Cat;break;
      default: ptr=new Emlosok;break;
    }
    tomb[i]=ptr;
  }
  
  Emlosok *masiktomb[numanimalTypes];
  
  for(i=0;i<numanimalTypes;i++)
  {
    tomb[i]->speak();
    masiktomb[i]=tomb[i]->Clone();
  }
  
  for(i=0;i<numanimalTypes;i++)
    masiktomb[i]->speak();
  return 0;
}
