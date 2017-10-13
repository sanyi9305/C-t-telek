 #include <iostream>

 /*int main()
 {
     std::cout << "The size of an int is:\t\t";
     std::cout << sizeof(int) << " bytes.\n";
     std::cout << "The size of a short int is:\t";
     std::cout << sizeof(short) << " bytes.\n";
     std::cout << "The size of a long int is:\t";
     std::cout << sizeof(long) << " bytes.\n";
     std::cout << "The size of a char is:\t\t";
     std::cout << sizeof(char) << " bytes.\n";
     std::cout << "The size of a bool is:\t\t";
     std::cout << sizeof(bool) << " bytes.\n";
     std::cout << "The size of a float is:\t\t";
     std::cout << sizeof(float) << " bytes.\n";
     std::cout << "The size of a double is:\t";
     std::cout << sizeof(double) << " bytes.\n";

     std::cout << "The size of an unsigned int is:\t\t";
     std::cout << sizeof(unsigned int) << " bytes.\n";
     std::cout << "The size of an unsigned short int is:\t";
     std::cout << sizeof(unsigned short) << " bytes.\n";
     std::cout << "The size of an unsigned long int is:\t";
     std::cout << sizeof(unsigned long) << " bytes.\n";

     return 0;
 }*/
/*
main(){

unsigned short x=3,y=5;
unsigned int z;
z=x*y;
std::cout<<z << std::endl;
std::cout<<"HEllo" << std::endl;
}*/
typedef unsigned short int USHORT;
main()
{
USHORT Width=5;
USHORT Length;
Length=10;
USHORT Area= Width*Length;
std::cout << "Szélesség: " << Width << std::endl;
std::cout << "Hosszúság:  " << Length << std::endl;
std::cout << "Terület: " << Area << std::endl;
}
