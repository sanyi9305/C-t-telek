#include <iostream>
#include <string>

using namespace std;

struct Pont
{
    int x, y;
};

int main()
{
    string kuka;

    // A mutatók használatán keresztül lehetőség nyílik arra, hogy ne csak a
    // programszövegben felsorolt változók tárolhassanak adatokat, hanem a
    // program futása során az igényeknek megfelelően hozzunk létre és
    // szüntessünk meg adattároló területeket a memóriában. Az ilyen futás
    // közben létrehozott változókat dinamikus változóknak hívjuk.

    // A dinamikus memóriakezelés két alapművelete a dinamikus változó
    // létrehozása és törlése. A létrehozást a new operátor végzi: meg kell neki
    // adni a változó típusát, és egy mutatót ad eredményként. A létrehozást
    // hívják még memóriafoglalásnak is.

    int* imut = new int;
    cout << "imut: " << imut << ", *imut: " << *imut << "\n";

    // Az így létrehozott dinamikus változó a mutatón keresztül ugyanúgy
    // használható, mint bármelyik másik adat.
    cin >> *imut;
    cout << 2 * (*imut + 3) << "\n";

    // Nagyon fontos, hogy ha egy változóra már nincs szükségünk, akkor le kell
    // törölni. A törlést is a mutatón keresztül lehet elvégezni, a delete
    // operátorral. Ezt a műveletet felszabadításnak is hívják.
    delete imut;

    // A létrehozás során kezdőértéket is lehet adni a változónak, a jelölés a
    // következő:
    imut = new int(15);
    cout << "imut: " << imut << ", *imut: " << *imut << "\n";
    delete imut;

    getline(cin, kuka);

    // Dinamikus tömböket is létre lehet hozni. Ilyen esetben szabványos
    // lehetőség van arra, hogy a tömb méretét futási időben határozzuk meg.
    cout << "A tömb mérete? ";
    int n;
    cin >> n;

    // Ilyenkor is a new operátort használjuk a létrehozásra
    int* itomb = new int[n];

    // Láttuk, hogy a mutatókat tömbként is lehet használni, így a dinamikus
    // tömbök használata során semmi nem változik.
    for (int i=0; i<n; ++i)
        itomb[i] = i+1;

    cout << "itomb[i] = i+1;\n";
    for (int i=0; i<n; ++i)
        cout << " " << itomb[i];

    // A dinamikusan lefoglalt tömböket másképp kell letörölni, mint a sima
    // változókat: a delete operátornak a delete[ ] alakú változatát kell
    // használni.
    delete[] itomb;

    getline(cin, kuka);

    // Rekordok használata során előkerül egy hasznos jelölés, a -> operátor.
    // Ezzel egy mutatón keresztül elérhető rekord egy mezőjét lehet lekérdezni.

    Pont *pt = new Pont;
    
    // "pt" a mutató, ami a rekordra mutat. "*pt" adja vissza a rekordot,
    // "(*pt).x" a rekord "x" nevű mezője.
    (*pt).x = 1;
    
    // Pontosan ugyanezt jelenti a -> operátor is, ami így egy hasznos
    // rövidítés.
    pt->y = 2;

    cout << '(' << pt->x << ',' << pt->y << ")\n";

    delete pt;

    return 0;
}
