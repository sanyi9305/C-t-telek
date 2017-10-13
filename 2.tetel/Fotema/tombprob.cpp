
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// A következő problémák merülnek fel, ha nem fix számú adatot szeretnénk
// tömbökben tárolni:
//   - egy primitív tömb mérete nem változtatható
//   - nem tudjuk lekérdezni, mekkora a tömb
// Egy egyszerű módszer ezek áthidalására a következő. Tegyük fel, hogy az
// adataink számára tudunk adni egy elfogadható felső korlátot. Minden esetben
// használjunk egy akkora tömböt, amibe elfér ennyi elem. A tömböt azonban nem
// muszáj teljesen feltölteni: tegyünk a tömb mellé még egy egész számot is, ami
// azt tárolja, hogy hány elemet tettünk a tömbbe. A tömböt és a méretét tároló
// változót érdemes lehet összekapcsolni egy struktúrába. Fontos, hogy a tömbnek
// mindig az elejét töltsük fel: ha lyukakat hagyunk benne, azoknak a helyéről
// semmilyen információnk nem lesz.

// Ha feltesszük, hogy van egy korlátja az adataink számának, akkor erre a
// korlátra sok helyen lehet szükség a programban. _Mindig_ adjunk ennek a
// korlátnak egy nevet, magát a számot sose használjuk! Ha valamiért meg kell
// emelni a korlátot, ezzel a módszerrel csak egy helyen kell módosítani a
// programot.
const int MaxJegySzam = 10;

// A struktúrában megtalálható a jegyek száma, és egy MaxJegySzam elemű tömb,
// aminek az első "jegyszam" darab eleme tartalmazza a jegyeket.
struct Jegyek
{
    string nev;
    int jegyszam;
    int jegy[MaxJegySzam];
};

// A beolvasó művelet figyel arra, hogy ne töltse túl a jegyeket tartalmazó
// tömböt. Enélkül komoly hibákra lehetne számítani a programban.
void beolvas(istream& is, Jegyek& sor)
{
    char kuka;
    is >> ws;
    getline(is, sor.nev, ',');
    is >> sor.jegyszam >> kuka;
    if (sor.jegyszam > MaxJegySzam)
    {
        cerr << sor.nev << ": túl sok jegy!\n";
        sor.jegyszam = 0;
        string maradek;
        getline(is, maradek);
    }
    else
    {
        for (int i=0; i<sor.jegyszam; ++i)
            is >> sor.jegy[i];
    }
}

// A főprogram kiírja a fájlban található hallgatók tanulmányi átlagát.
int main()
{
    ifstream f("jegyek.txt");
    Jegyek jegyek;

    // Előreolvasásos ciklussal végigmegy a fájl sorain
    beolvas(f, jegyek);
    while (f.good())
    {
        // Minden sorra kiszámolja a jegyek összegét
        double osszeg = 0;   // Azért double, hogy az osztásnál ne kerekítsen
        for (int i=0; i<jegyek.jegyszam; ++i)
            osszeg += jegyek.jegy[i];

        // Kiírja az átlagot
        cout << jegyek.nev << " átlaga: " << (osszeg/jegyek.jegyszam) << "\n";

        beolvas(f, jegyek);
    }

    return 0;
}
