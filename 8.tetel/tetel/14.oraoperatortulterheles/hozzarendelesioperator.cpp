#include <iostream>
using namespace std;



class CAT
{
public:
 CAT();
  int getAge() const{return *itsAge;}
  int getWeight()const {return *itsWeight;}
  void setAge(int age){*itsAge=age;}
  CAT operator=(const CAT &){}   //hozzárendelés
 bool operator==(const CAT &);   // megvizsgálja egyenlő 
  
private:
  int *itsAge;
  int *itsWeight;
};

CAT::CAT()
{
  itsAge =new int;
  itsWeight= new int;
  *itsAge= 5;
  *itsAge =9;
  
}
CAT CAT::operator=(const CAT&rhs)
{
  if(this==&rhs)
  return *this;
  else
    {
  /*delete itsAge;
  delete itsWeight;
  itsAge =new int;
  itsWeight= new int;*/
  *itsAge=rhs.getAge();
  *itsWeight=rhs.getWeight();
  return *this;
    }
}
bool CAT::operator==(const CAT & rhs)
{
  cout << "-------------- ==operator hívása ----------------------"<<endl;
  int seged=*itsAge;
if(*itsAge==rhs.getAge()){
  cout << "egyenlő" <<endl;
  return false;}
else
    cout << "nem egyenlő" <<endl;

  return false;
 
}

main()
{
  
  CAT Cirmi;
  cout << " Cirmi: " << Cirmi.getAge() << " éves" << endl;
  CAT Hopihe;
  cout << "Hopihe: " << Hopihe.getAge() << " éves" << endl;
  cout << "Cirmi legyen 3 éves" << endl;
  Cirmi.setAge(3);
    cout << " Cirmi: " << Cirmi.getAge() << " éves" << endl;
      cout << "Hopihe: " << Hopihe.getAge() << " éves" << endl;
      cout << "másoljuk át Cirmit hópihébe:" << endl;
      Hopihe=Cirmi;
            cout << "Hopihe: " << Hopihe.getAge() << " éves" << endl;
	   Hopihe.setAge(55);
	    cout <<"\n\n Hopihe: "<< Hopihe.getAge() << "\t Cirmi: " << Cirmi.getAge() << endl;
	    Cirmi==Hopihe;
	


return 0;

}