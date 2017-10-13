#include <iostream>
using namespace std;
enum COLOR {Red,Green,Blue,Yellow,White,Black,Brown};
class Animal
{
public:
  Animal(int );
  virtual ~Animal(){cout << "Anumal destruktor...\n";}
  virtual int GetAge() const {return itsAge;}
  virtual void SetAge(int age){itsAge=age;}
  virtual void Sleep() const =0;
  virtual void Eat() const = 0;
  virtual void Reproduce() const = 0;
  virtual void Move() const = 0;
  virtual void  Speak() const = 0;
private:
  int itsAge;
};

Animal::Animal(int age):itsAge(age){cout << "animal konstruktor...\n";}//animal konstruktor

class Mammal:public Animal
{
public:
Mammal(int age):Animal(age){cout << "Mammal konstruktor...\n";}
virtual ~Mammal(){};
void Reproduce() const {cout <<"Emlősök Szaporodása...\n";}
};

class Fish:public Animal
{
public:
Fish(int age):Animal(age){{cout << "Halak konstruktora...\n";}}
virtual ~Fish(){cout << "Destruktora...\n";};
  
  virtual void Sleep() const {cout << "Halak alvási szokása...\n";}
  virtual void Eat() const{cout << "Halak evési szokása...\n";}
  virtual void Reproduce() const {cout << "Halak ikrázási szokása...\n";}
  virtual void Move() const {cout << "Halak úszása...\n";};
  virtual void Speak() const {}
};
class Horse:public Mammal
{
public:
Horse(int age,COLOR color):Mammal(age),itsColor(color){cout << "Lovak konstruktora...\n";}
virtual ~Horse(){cout << "Lovak Destruktora...\n";}
virtual void Sleep() const {cout << "lovak Állva alszanak...\n";}
virtual void Eat() const {cout << "Lovak evési szokása...\n";}
virtual void Move() const {cout << "A ló futni szokott...\n";}
virtual void Speak() const {cout << "Nyihahaaa...\n";}
virtual COLOR GetColor(){return itsColor;}

protected:
  COLOR itsColor;
};

class Dog:public Mammal
{
public:
Dog(int age,COLOR color):Mammal(age),itsColor(color){cout << "Dog Konstruktor...\n";}
virtual ~Dog(){cout << "Dog destruktor...\n";}
virtual void Sleep() const {cout << "Kutyák fekve alszanak...\n";}
virtual void Eat() const {cout << "Kutyák evési szokása...\n";}
virtual void Move() const {cout << "A kutya futni szokott...\n";}
virtual void Speak() const {cout << "vau vau...\n";}
protected:
  COLOR itsColor;
  
};

main()
{
  int valasz;
  Animal *pAnimal=0;
  bool fquit=false;
  while(1)
  {
    cout << "(1)Kutya\t(2)Ló\t(3)Hal\t(0)Kilépés: ";
    cin>>valasz;
    switch (valasz)
    {
      case 1 : pAnimal=new Dog(5,Brown);break;
      case 2 : pAnimal=new Horse(4,Black);break;
      case 3 : pAnimal=new Fish(5);break;
      default : fquit=true;break;
    }
    if(fquit)
      break;
  cout << pAnimal->GetAge() << "éves\n"  
  pAnimal->Speak();
  pAnimal->Eat();
  pAnimal->Reproduce();
  pAnimal->Move();
  pAnimal->Sleep();
  delete pAnimal;
  cout << "\n";
  
  
  }
 return 0; 
}