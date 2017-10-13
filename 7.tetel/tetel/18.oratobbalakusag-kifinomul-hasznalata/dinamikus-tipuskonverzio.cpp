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
virtual ~Cat(){cout <<" Macska destruktor\n";}
void Speak(){cout <<"MIAUU\n";};
void Dorombol(){cout <<" rrrrrrrrrrr\n";}
  
};
class Dog:public Emlosok
{
public:
Dog(){cout <<" Kutya konstruktor \n";}
virtual ~Dog(){cout <<" Kutya destruktor\n";}
void Speak(){cout <<"Vauu\n";};

  
};

main()
{
  const int Emlosszam=3;
  Emlosok *emlostomb[Emlosszam];
  Emlosok *pemlosok;
  int i,valasz;
  for(i=0;i<Emlosszam;i++)
  {
    cout << "(1)kutya\t (2)macska: ";
    cin >> valasz;
    if(valasz==1)
      pemlosok=new Dog;
    else
      pemlosok=new Cat;
    
    emlostomb[i]=pemlosok;
    }
    cout << "\n";
   for(i=0;i<Emlosszam;i++)
    {
      emlostomb[i]->Speak();
      Cat *prealCat= dynamic_cast<Cat*>(emlostomb[i]);
      //if(prealCat)
	prealCat->Dorombol();
     // else
	//cout << "Hú ha nem macska\n";
    delete emlostomb[i];
   cout << "\n";
    }
  return 0;
  
}