#include <iostream>
using namespace std;


class Counter
{
public:
  Counter();
  ~Counter(){};
  int getVal() const {return itsVal;}
  int setVal(int x) {itsVal=x;}
  int Increment(){++itsVal;}
  const Counter& operator++(); // prefix növelés
  const Counter operator++(int); //postfix növelés
private:
int itsVal;
  
};
Counter::Counter():
itsVal(0)
{}

const Counter& Counter::operator++() // **prefix**ha egy objektumbeli változót ++i operátorral 
				     //használunk ez hívódik meg
{
++itsVal;
return *this;
}
const Counter Counter::operator++(int)// **postfix**ha egy objektumbeli változót i++ operátorral 
				     //használunk ez hívódik meg
{
Counter temp=*this;
itsVal++;
return temp;
}

main()
{
  
/*Counter i;
cout<< "az i értéke: "<< i.getVal() << endl;
i.Increment();
cout<< "az i értéke: "<< i.getVal() << endl;
++i;							//prefix növelés
cout<< "az i értéke: "<< i.getVal() << endl;

Counter a=++i;
cout<< "az i értéke: "<< i.getVal();
cout<< "\taz a értéke: "<< a.getVal() << endl;*/
							      //postfix növelés
							      
Counter i;
cout<< "az i értéke: "<< i.getVal() << endl;
i++;
cout<< "az i értéke: "<< i.getVal() << endl;
Counter a=i++;
cout<< "az a értéke: "<< a.getVal() << endl;
cout<< "az i értéke: "<< i.getVal() << endl;



return 0;  
}