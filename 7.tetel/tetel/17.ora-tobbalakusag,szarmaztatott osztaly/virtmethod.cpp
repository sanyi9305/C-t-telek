 //Listing 17.1 Using virtual methods
 #include <iostream>

 class Mammal
 {
 public:
     Mammal():itsAge(1) { std::cout << "Mammal constructor...\n"; }
     ~Mammal() { std::cout << "Mammal destructor...\n"; }
     void Move() const { std::cout << "Mammal move one step\n"; }
     virtual void Speak() const { std::cout << "Mammal speak!\n"; }

 protected:
     int itsAge;
 };

 class Dog : public Mammal
 {
 public:
     Dog() { std::cout << "Dog constructor...\n"; }
     ~Dog() { std::cout << "Dog destructor...\n"; }
     void WagTail() { std::cout << "Wagging Tail...\n"; }
  void Speak()const { std::cout << "Woof!\n"; }                  // We now get the base class method!
     void Move()const { std::cout << "Dog moves 5 steps...\n"; }
 };

 int main()
 {
     Mammal *pDog = new Dog;
     pDog->Move();
     pDog->Speak();
     return 0;
 }