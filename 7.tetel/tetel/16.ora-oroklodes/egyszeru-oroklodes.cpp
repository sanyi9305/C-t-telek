#include <iostream>

enum BREED {yorkie,doberman,labrador,juhasz,puli}; // fajták
class Emlosok
{
public:
  //konstruktorok
  Emlosok();
  ~Emlosok();
  //hozzáférő fv-ek
  int getAge() const {return itsAge;}
  int getWeight() const;
  void setAge(int);
  void setWeight(int);
  
  //egyéb tagfüggvények
  void Speak(){std::cout << "Emlos hang" << std::endl;}
  void Sleep(){std::cout << "Alszom!!" << std::endl;}
  
  //változók
protected:
  int itsAge;
  int itsWeight;

};

class Dog :public Emlosok
{
public:
  //konstruktorok
Dog();
~Dog();
//Hozzáférő fv-ek
BREED getBREED() const;
void setBREED(BREED);

//egyéb tagfv-ek
void FarokCsova(){std::cout << "Farok csóválás" << std::endl;}
void Kuncsorgas(){std::cout << "Pitizés" << std::endl;}

protected:
  BREED itsBreed;
  
};
Emlosok::Emlosok()
{
itsAge=1;
itsWeight=5;
std::cout << "emlősök konstruktor**********" << std::endl;
}
Emlosok::~Emlosok()
{
  
 std::cout << "emlősök destruktor**************" << std::endl; 
}

Dog::Dog()
:itsBreed(yorkie)
{

std::cout << "kutya konstruktor*************" << std::endl;
}
Dog::~Dog()
{
  std::cout << "kutya destruktor*************" << std::endl;
  
}

int main()
{
  
  Dog Fido;
  Fido.Kuncsorgas();
  Fido.FarokCsova();
  Fido.Sleep();
  Fido.Speak();
  std::cout << "Fido most: " << Fido.getAge() << "éves \n";
 //Fido.setAge(12);
    //std::cout << "Fido mostmár: " << Fido.getAge() << "éves \n";

  return 0;
}