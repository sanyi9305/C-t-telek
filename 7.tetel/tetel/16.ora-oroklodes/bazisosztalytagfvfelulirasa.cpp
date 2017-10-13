#include <iostream>
#include <iostream>

enum BREED {yorkie,doberman,labrador,juhasz,puli}; // fajták
class Emlosok
{
public:
  //konstruktorok
  Emlosok();
  Emlosok(int age);
  ~Emlosok();
  //hozzáférő fv-ek
  int getAge() const {return itsAge;}
  int getWeight() const{return itsWeight;}
  void setAge(int);
  void setWeight(int);
  
  //egyéb tagfüggvények
  void Speak(){std::cout << "Emlos hang" << std::endl;}
  void Sleep(){std::cout << "Alszom!!" << std::endl;}
  void MOVE()const {std::cout  << "Emlős előre 2\n";}
void MOVE(int distance)const{std::cout << "Emlős megy előre: " << distance << std::endl;}
  
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
Dog(int age);
Dog(int age,int weight);
Dog(int age, BREED breed);
Dog(int age,int weight,BREED breed);
~Dog();

//Hozzáférő fv-ek
BREED getBREED() const;
void setBREED(BREED);

//egyéb tagfv-ek

void Speak(){std::cout << "vau-vau" << std::endl;}// emlősök speak fv felülírása
void FarokCsova(){std::cout << "Farok csóválás" << std::endl;}
void Kuncsorgas(){std::cout << "Pitizés" << std::endl;}
void MOVE() const {std::cout <<"kutya Hátra 3\n";} 
protected:
  BREED itsBreed;
  
};

class Cat:public Emlosok
{
public:
Cat(){std::cout << "Macska konstruktor\n" ;}; 
~Cat(){std::cout << "Macska destruktor\n" ;};
void Speak(){std::cout << "miauu-miauu" << std::endl;} // emlősök speak fv felülírása
 
};
Emlosok::Emlosok()
{
itsAge=1;
itsWeight=5;
std::cout << "emlősök konstruktor**********" << std::endl;
}
Emlosok::Emlosok(int age)
{
itsAge=age;
itsWeight=5;
std::cout << "emlősök (int) konstruktor**********" << std::endl;
}

Emlosok::~Emlosok()
{
  
 std::cout << "emlősök destruktor**************" << std::endl; 
}

Dog::Dog():Emlosok(),itsBreed(yorkie)
{
std::cout << "kutya konstruktor*************" << std::endl;
}

Dog::Dog(int age):Emlosok(age),itsBreed(yorkie)
{
std::cout << "kutya (int) konstruktor*************" << std::endl;

}
Dog::Dog(int age, int weight): Emlosok(age),itsBreed(yorkie)
{
itsWeight=weight;
std::cout << "kutya(int,int) konstruktor*************" << std::endl;

}

Dog::Dog(int age, int weight, BREED breed): Emlosok(age),itsBreed(breed)
{
itsWeight=weight;
std::cout << "kutya(int,int,breed) konstruktor*************" << std::endl;

}
Dog::Dog(int age, BREED breed): Emlosok(age),itsBreed(breed)
{

std::cout << "kutya(int breed) konstruktor*************" << std::endl;

}
Dog::~Dog()
{
  std::cout << "kutya destruktor*************" << std::endl;
  
}
/*main()
{
  Emlosok Allatka;
  Dog Fido;
  Cat Cirmi;
  Allatka.Speak(); // bűzisosztály fv felülírása 1
  Fido.Speak();
  Cirmi.Speak();
  
}*/
main()
{
  Emlosok Allatka;
  Dog Fido;
  
  Allatka.MOVE();
  Allatka.MOVE(3);
  Fido.MOVE();
}