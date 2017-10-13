#include <iostream>

using namespace std;

class Emlos
{
public:
  Emlos(){itsage=1;}
  ~Emlos(){}
  virtual void speak(){cout << "emlős hang\n";}
protected:
  int itsage;
};

class kutya:public Emlos
{public:
  void speak(){cout << "kutya hang\n";}
};
class macska:public Emlos
{public:
  void speak(){cout << "macska hang\n";}
};
class lo:public Emlos
{public:
  void speak(){cout << "lo hang\n";}
};
class malac:public Emlos
{public:
  void speak(){cout << "malac hang\n";}
};
void Ertekfv(Emlos);
void mutatofv(Emlos*);
void referenciafv(Emlos&);

main()
{
  Emlos *ptr=0;
  int valasz;
  while(1)
  {
    bool fquit=false;
    cout << "1 kutya  2 macska  3 ló  4 malac  0 kilépés" << endl;
    cin>>valasz;
    switch(valasz)
    {
      case 0: fquit=true;break;
      case 1: ptr=new kutya;break;
      case 2: ptr= new macska;break;
      case 3: ptr=new lo;break;
      case 4: ptr=new malac;break;
      default: ptr=new Emlos;break;
    }
    if(fquit)
      break;
    mutatofv(ptr);
    referenciafv(*ptr);
    Ertekfv(*ptr);
  }
  return 0;
 }
 
void Ertekfv(Emlos emlosertek)
{
emlosertek.speak();
}
void mutatofv(Emlos*pemlos)
{
pemlos->speak();
}
void referenciafv(Emlos&remlos)
{
remlos.speak();
}
