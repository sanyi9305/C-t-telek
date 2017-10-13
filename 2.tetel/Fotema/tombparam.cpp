#include <iostream>
#include <string>

using namespace std;

// A primitív tömböknek nincs olyan műveletük, ami lemásolná őket, ezért a tömb
// típusú paraméterek átadása mutatóként történik. Ezt azt jelenti, hogy ha a
// függvényen belül módosítjuk a tömb tartalmát, akkor az hatással van az
// átadott tömb értékére is.

void cserel(int tomb[])
{
    int a = tomb[0];
    tomb[0] = tomb[1];    // Az eljárás hibásan fog működni, ha 2-nél rövidebb
    tomb[1] = a;          // tömbbel hívjuk meg, és erre nem figyelmeztet senki!
}

// A függvénynek nincs információja a tömb méretéről. Ezt a problémát úgy lehet
// megoldani, hogy átadjuk paraméterként a tömb elemszámát. Arról továbbra sem
// kapunk figyelmeztetést, ha ezt a paramétert hibásan adjuk meg!

double osszead(double sz[], int darab)
{
    double osszeg = 0;
    for (int i=0; i<darab; ++i)
        osszeg += sz[i];
    return osszeg;
}

int main()
{
    string kuka;

    // A cserélő alprogram használata

    int szamok[5] = {1,2,3,4,5};
    
    cout << "Csere előtt:";
    for (int i=0; i<5; ++i)
        cout << " " << szamok[i];
    cout << "\n";

    // Ilyenkor automatikusan a tömb első elemére mutató pointert kapja meg az
    // eljárás
    cserel(szamok);

    // Tetszőleges mutatót meg lehet adni, például olyat, ami a tömb végére
    // mutat
    cserel(&szamok[3]);
    
    cout << "Cserék után:";
    for (int i=0; i<5; ++i)
        cout << " " << szamok[i];
    cout << "\n";

    getline(cin, kuka);

    // Az összegző alprogram használata

    double tortek[5] = {0.5, 1.3, 4.6, 5.2, 8.4};

    cout << "Összeg (5): " << osszead(tortek, 5) << "\n";
    
    // Ha hibásan adjuk meg a méretet, arról csak a futtatás során kapunk
    // valamilyen jelzést, például egy rossz eredményt. Ha módosítanánk is a
    // tömb értékét, rosszabb hiba is történhetne.

    cout << "Összeg (25): " << osszead(tortek, 25) << "\n";

    return 0;
}
