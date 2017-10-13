#include <iostream>
using namespace std;


class Counter
{
public:
  Counter();
  Counter(int initialValue);
  ~Counter(){};
  int getVal()const {return itsVal;}
  void setVal(int x){itsVal=x;}
  Counter operator+(const Counter&);
  Counter operator-(const Counter&);
  
private:
  int itsVal;
  
  
};


Counter::Counter(int initialValue):itsVal(initialValue)
{

}
Counter::Counter():itsVal(0)
{}
Counter Counter::operator+(const Counter &rhs)
{
cout<<"+ operator meghívása\n";
return itsVal+rhs.getVal();
}

Counter Counter::operator-(const Counter &rhs)
{
return itsVal-rhs.getVal();
}


main()
{
  Counter a(2),b(4),c;
  cout << "a: " << a.getVal() << "\nb: " << b.getVal() << endl;
 // c=a+b;             c.getVal()
  cout << "a+b: " << (a+b).getVal()<<endl;
  int j=3,k=2;
  cout <<" j+ k: " << j+k<<endl;
  c=a-b;
  cout << "a-b(2-4): " << c.getVal() << endl;
  c= b-a;
    cout << "b-a(4-2): " << c.getVal()<< endl;

  
  return 0;
}
