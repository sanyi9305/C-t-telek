 //Listing 17.1 Using virtual methods
 #include <iostream>
using namespace std;
 class Foo
 {
 public:
     void fvFoo(){}
     virtual void Speak(){cout << "Ős osztály beli vagyok" << endl;}


 };

 class Bar : public Foo
 {
 public:
    void fvBar(){}
    void Speak(){cout << "Gyerek osztály vagyok" << endl;}
 };

 int main()
 {
   Bar *ptr;
   int v;
   
   cout << "Gyereket(1) vagy Őst(2) akarsz?" << endl;
   cin >> v;
   switch(v)
   {
     case 1: ptr=new Bar;break;
     case 2: ptr=new Foo;break;
     default: cout << "nem jó szam" << endl;
   }
  
   ptr->Speak();
     return 0;
 }