#include <iostream>
// A primitív tömb használatához nem kell külön fejlécfájl

using namespace std;

int main()
{
    string kuka;

    // * Tömb deklarációja: a változó neve előtt a tömb alaptípusa, a név után
    // szögletes zárójelek között az elemek száma
    int szamok[3];

    // * Alapművelet: adott sorszámú elem elérése a [ ] (szögletes zárójel)
    // operátor használatával
    szamok[0] = 1;           // Az elemeket mindig 0-tól indexeljük
    szamok[1] = 2;           // A [ ] operátor eredménye balérték, így értéket
    szamok[2] = 3;           // is lehet adni egy ilyen kifejezésnek

    cout << "szamok[]:\n "
        << szamok[0] << " " << szamok[1] << " " << szamok[2] << "\n";

    getline(cin, kuka);


    // Indexelésre tetszőleges egész értéket adó kifejezést lehet használni,
    // gyakori az indexváltozó használata (pl. ciklusban)

    for (int i=0; i<3; ++i)
        szamok[i] *= i+1;

    cout << "szamok[i] *= i+1:\n";
    for (int i=0; i<3; ++i)
        cout << " " << szamok[i];
    cout << "\n";

    getline (cin, kuka);

    // * A tömb méreteként csak olyan kifejezést szabad megadni, aminek az értéke
    // a program futtatása nélkül (azaz fordítási időben) kiszámítható.
    
    int szamok2[5+3*2];

    // Néhány fordítóprogram támogatja azt is, hogy változót adjunk meg
    // tömbméretként, a szabványban viszont ez nincs benne, ezért a következő
    // kódrészletet nem minden fordító tudja lefordítani:

    /*
    cout << "Az nsz tömb mérete: ";
    int n;
    cin >> n;
    int nsz[n];    // A szabvány nem tartalmazza ezt a lehetőséget
    for (int i=0; i<n; ++i)
        nsz[i] = 3*i+2;

    cout << "nsz[i] = 3*i+2:\n";
    for (int i=0; i<n; ++i)
        cout << " " << nsz[i];
    cout << "\n";

    getline(cin, kuka); getline(cin, kuka);
    */

    // * A primitív tömbnek kezdőértéket is lehet adni: az elemeket kapcsos
    // zárójelek között, vesszőkkel elválasztva kell felsorolni
    int primek[8] = {2, 3, 5, 7 ,11, 13, 17, 19};

    cout << "primek[]:\n";
    for (int i=0; i<8; ++i)
        cout << " " << primek[i];
    cout << "\n";

    getline(cin, kuka);

    // Lehet kevesebb elemet megadni, mint a tömb mérete, ekkor a kimaradó
    // elemek értéke 0 lesz
    int nullak[5] = { };

    cout << "nullak[]:\n";
    for (int i=0; i<5; ++i)
        cout << " " << nullak[i];
    cout << "\n";

    // A méretnél több elem megadása hibás
    // int hibas[3] = {1, 2, 3, 4, 5};

    return 0;
}
