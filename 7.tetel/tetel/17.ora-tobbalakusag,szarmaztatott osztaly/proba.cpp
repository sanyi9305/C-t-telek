 #include <iostream> 
using namespace std;
class Emlosok
{
  public:
  Emlosok():itsAge(1){cout << "Emlosok konstruktora" <<endl;}
  virtual ~Emlosok(){cout << "Emlosok destruktora" <<endl;}
  Emlosok(const Emlosok &rhs); //másoló konstruktor
  virtual void speak()const {cout << "Emlős hangja" <<endl;}
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

class Cat : public Emlosok

 {

 public:

     Cat() { std::cout << "Cat constructor...\n"; }

     virtual ~Cat() { std::cout << "Cat destructor...\n"; }

     Cat (const Cat &);

     void speak()const { std::cout << "Meow!\n"; }

     virtual Emlosok* Clone() { return new Cat(*this); }

 };

 

 Cat::Cat(const Cat & rhs):

 Emlosok(rhs)

 {

     std::cout << "Cat copy constructor...\n";

 }
 enum ANIMALS { MAMMAL, DOG, CAT};

 const int NumAnimalTypes = 3;

 int main()

 {

     Emlosok *theArray[NumAnimalTypes];

    Emlosok* ptr;

     int choice,i;

     for (i = 0; i<NumAnimalTypes; i++)

     {

         std::cout << "(1)dog (2)cat (3)Mammal: ";

         std::cin >> choice;

         switch (choice)

         {

         case DOG: 

             ptr = new Dog;

             break;

         case CAT: 

             ptr = new Cat;

             break;

         default: 

             ptr = new Emlosok;

             break;

         }

         theArray[i] = ptr;

     }

     Emlosok *OtherArray[NumAnimalTypes];

     for (i=0;i<NumAnimalTypes;i++)

     {

         theArray[i]->speak();

         OtherArray[i] = theArray[i]->Clone();

     }

     for (i=0;i<NumAnimalTypes;i++)

         OtherArray[i]->speak();

     return 0;

 }

