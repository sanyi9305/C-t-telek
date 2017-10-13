#include <iostream>
#include <cstdlib>
using namespace std;

struct termek
{
string nev;
int suly;
float ar;
} ;

void kiir(termek mit)
{
cout <<"\nTermek neve: " <<mit.nev;
cout <<"\nSu'lya:      " <<mit.suly;
cout <<"\nA'ra:        " <<mit.ar;
}

int main ()
{
termek alma;
termek banan, dinnye;
system("cls");
alma.nev="Alma";
alma.suly=20;
alma.ar=147;
banan.nev="Bana'n";
banan.suly=14;
banan.ar=350;  
dinnye.nev="Dinnye";
dinnye.suly=4;
dinnye.ar=99.9;
kiir(alma);
kiir(banan);
kiir(dinnye);
return 0;
}
