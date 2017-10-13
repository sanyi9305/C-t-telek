#include <iostream>
#include <string>

using namespace std;

struct adatok
{
  string name;
  string szin;
  int age;
  unsigned short int lives;
  float weight;
  
};
class CAT
{
  public:
  CAT(){itsAge=1,itsWeight=5;} //alapértelmezett konstruktor
  ~CAT(); //destruktor
  int getAge() const {return itsAge;}
  int getWeight() const {return itsWeight;}
  void setAge(int age){itsAge=age;}
  
private:
  int itsAge,itsWeight;
  
};

CAT::~CAT()
{
  cout << "Destruktor meghívasa" <<endl;
  
}
main()
{
  CAT *Family=new CAT[10];
  int i;
  CAT *pCAT;
  
  
 /* for (i=0;i<10;i++)
  { pCAT=new CAT;
  pCAT->setAge(2*i+1);
  Family[i]=*pCAT;
 delete pCAT;*/
 for(i=0;i<10;i++)
  {
   Family[i].setAge(2*i+1);
   
  }
   
  
  
  for (i=0;i<10;i++)
  
    cout << "#" << i+1 << " Cica: "<< Family[i].getAge()<< " éves" << endl;
    delete [] Family;
  adatok a;
  adatok b={"Hopihe","fekete",3,9,6.25};
  a.name="Jani";
  a.age=3;
  a.szin="barna";
  cout << "structurában lévő cica neve: " << a.name << endl;
  cout << "structurában lévő cica színe: " << a.szin << endl; 
  cout << "structurában lévő cica kora: " << a.age << endl;
  
  
 cout << "\nstructurában lévő cica neve: " << b.name << endl;
  cout << "structurában lévő cica színe: " << b.szin << endl; 
  cout << "structurában lévő cica kora: " << b.age << endl;
  cout << "structurában lévő cica hátralévő élete: " << b.lives << endl;
  cout << "structurában lévő cica súlya: " << b.weight << endl; 

 
  return 0;
}