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

main()
{
  Emlos *tomb[5];
  Emlos *ptr;
  int valasz,i;
  for(i=0;i<5;i++)
  {
    cout << "1 kutya  2 macska  3 ló  4 malac" << endl;
    cin>>valasz;
    switch(valasz)
    {
      case 1: ptr=new kutya;break;
      case 2: ptr= new macska;break;
      case 3: ptr=new lo;break;
      case 4: ptr=new malac;break;
      default: ptr=new Emlos;break;
    }
    tomb[i]=ptr;
  }
  for(i=0;i<5;i++)
    tomb[i]->speak();
  return 0;
}