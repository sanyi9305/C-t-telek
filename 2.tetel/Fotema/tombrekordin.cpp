#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// A Jegyek struktúrában a fix méretű tömböt lecseréljük egy mutatóra. A mutató
// egy dinamikus tömbre fog mutatni, amit a program futása során kell majd
// lefoglalnunk - és felszabadítanunk is. A tömb méretét, ami most megegyezik a
// jegyek számával, továbbra is el kell tárolni.
struct Jegyek
{
    string nev;
    int jegyszam;
    int* jegyek;
};

// A beolvasó alprogram tartalmaz egy teljesen új elemet. Függvényként írjuk meg
// a beolvasást, ami dinamikusan hozza létre a beolvasott rekordot. Ha vége
// van a fájlnak, azt úgy jelzi, hogy nullpointert ad eredményként. Ez egy
// gyakran alkalmazott technika egy kivételes helyzet jelzésére.
Jegyek* beolvas(istream& is)
{
    char kuka;
    string nev;

    // Megpróbálunk beolvasni egy nevet; ha nem sikerül, akkor vége a fájlnak,
    // és nullpointert adunk eredményként.
    is >> ws;
    getline(is, nev, ',');
    if (!is.good())
        return 0;

    // Ha sikerült, akkor be lehet olvasni az egész sort, de előbb létrehozzuk
    // dinamikusan a rekordot, és eltároljuk az előbb beolvasott nevet.
    Jegyek* j = new Jegyek;
    j->nev = nev;

    // A sorban a második adat a jegyek száma, egy ekkora méretű tömböt hozunk
    // létre.
    is >> j->jegyszam >> kuka;
    j->jegyek = new int[j->jegyszam];

    // Ha megvan a tömb, akkor eltároluk benne a sorban található jegyeket.
    for (int i=0; i < j->jegyszam; ++i)
        is >> j->jegyek[i];

    // Eredményként a létrehozott rekordra mutató pointert adjuk vissza.
    return j;
}

// A "beolvas" függvénnyel létrehozott rekordokat ki kell törölni a memóriából,
// ezt azonban nem lehet megtenni egy sima "delete" művelettel. A beolvasás
// során két memóriafoglalás történt: egyszer a rekordnak, egyszer a tömbnek.
// Mindkét memóriaterületet fel kell szabadítanunk. Hogy véletlenül se felejtsük
// el egyiket se, érdemes erre készíteni egy eljárást.
void torol(Jegyek* j)
{
    delete[] j->jegyek;
    delete j;
}

// A főprogram kiírja a fájlban található hallgatók tanulmányi átlagát.
int main()
{
    ifstream f("jegyek.txt");
    Jegyek* jegyek;

    // Előreolvasásos ciklussal végigmegy a fájl sorain
    jegyek = beolvas(f);
    // Akkor van vége a fájlnak, ha a beolvasó eljárás nullpointert ad vissza
    while (jegyek != 0)
    {
        // Minden sorra kiszámolja a jegyek összegét
        double osszeg = 0;   // Azért double, hogy az osztásnál ne kerekítsen
        for (int i=0; i<jegyek->jegyszam; ++i)
            osszeg += jegyek->jegyek[i];

        // Kiírja az átlagot
        cout << jegyek->nev << " átlaga: " << (osszeg/jegyek->jegyszam) << "\n";

        // FONTOS! Ha a törlő eljárást itt nem hívnánk meg, akkor a következő
        // művelet felülírná a dinamikus rekordra mutató pointert, de nem
        // szabadítaná fel a neki lefoglalt memóriát!
        torol(jegyek);

        jegyek = beolvas(f);
    }

    return 0;
}
