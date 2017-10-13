#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kuka;

    // A mutató típus egy memóriacím tárolására szolgál: azt a helyet "mutatja",
    // ahol egy adat megtalálható a memóriában. A mutatón keresztül kiolvashat-
    // juk és megváltoztathatjuk az adatot. Általában ismerjük az adat típusát,
    // így tetszőleges típusműveletet alkalmazhatunk rá.

    // Mutató típusú változó deklarációja: a sor elejére írjuk az alaptípust,
    // majd minden mutató típusó változó elé teszünk egy csillagot
    int *ip;
    string *sp;

    // Változók címét az & operátorral lehet lekérdezni, ez egy mutatót ad
    // eredményül, pl. int típusú változóra int * típusú mutatót
    int i=1, j=2, k=3;
    cout << "\n&i == " << &i << ", &j == " << &j << ", &k == " << &k << "\n";

    getline(cin, kuka);

    // Azt az értéket, amire a mutató mutat, a * operátorral lehet lekérdezni.
    // Ez az operátor balértéket ad eredményként, tehát nem csak kiolvasni lehet
    // rajta keresztül az adatot, hanem megváltoztatni is.

    cout << "\nmut = &i;\n";
    // Kezdetben az i változó címét tesszük a mut változóba
    int *mut = &i;

    cout << "   i: " << i << ", j: " << j << ", k: " << k
        << ", mut: " << mut << ", *mut: " <<  *mut  << "\n";

    cout << "\nj = j + *mut;\n";

    // A * operátor kérdezi le (most itt) az i értékét
    j = j + *mut;

    cout << "   i: " << i << ", j: " << j << ", k: " << k
        << ", mut: " << mut << ", *mut: " <<  *mut  << "\n";

    cout << "\nmut = &k; *mut = 7;\n";

    // Átállítjuk k-ra a mutatót
    mut = &k;
    // A mutatón keresztül megváltoztatjuk k értékét
    *mut = 7;

    cout << "   i: " << i << ", j: " << j << ", k: " << k
        << ", mut: " << mut << ", *mut: " <<  *mut  << "\n";

    getline(cin, kuka);

    // Két mutató egyenlőségét vizsgálva akkor kapunk igazat, ha ugyanarra a
    // memóriaterületre mutatnak. A címeken található értékeket ilyenkor nem
    // vizsgáljuk.

    // A két mutató két különböző, de azonos értéket tároló változóra mutat
    ip = &i;
    mut = &j;

    i=3;
    j=3;

    cout << "\nip == mut: ";
    // Ilyenkor az összehasonlítás eredménye hamis
    if (ip == mut)
        cout << "igaz\n";
    else
        cout << "hamis\n";
    
    cout << "\nmut = &i;\n";

    // Ha a mutatók ugyanarra a memóriacímre mutatnak...
    mut = &i;
    
    cout << "   ip == mut: ";
    // ... akkor az eredmény igaz
    if (ip == mut)
        cout << "igaz\n";
    else
        cout << "hamis\n";

    getline(cin, kuka);

    // Van egy speciális mutató-érték, az ún. nullpointer. Azt jelezzük ezzel az
    // értékkel, hogy a mutató "nem mutat sehova". Ilyenkor természetesen nem
    // szabad használni rá a * operátort.

    mut = 0;   // A 0 itt nem egész szám, hanem mutató típusú literál

    cout << "\nmut = 0;\n   mut: " << mut << "\n";

    // Ha ki akarom írni, hogy milyen adatra mutat, memóriahibát kapok!
    cout << "   *mut: " << *mut << "\n";

    return 0;
}
