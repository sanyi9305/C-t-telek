#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Hallgato {
    string nev;
    int beiratkozas;
};

int main()
{
    string kuka;

    // Tetszőleges alaptípust adhatunk egy tömbnek, összetett típusokat is,
    // például stringet

    string napok[7] = {"hétfő", "kedd", "szerda", "csütörtök", "péntek",
        "szombat", "vasárnap"};

    for (int i=0; i<7; ++i)
        cout << i << ".: " << napok[i] << ":\t"
            << napok[i].length() << " karakteres, "
            << napok[i][0] << " betűvel kezdődik\n";

    getline(cin, kuka);

    // Saját típust is felhasználhatunk alaptípusként, például egy struktúrát
    Hallgato hallgatok[3];

    for (int i=0; i<3; ++i)
    {
        cout << i+1 << ". hallgató neve és beiratkozási éve vesszővel elválasztva: ";
        cin >> ws;
        getline(cin, hallgatok[i].nev, ',');
        cin >> hallgatok[i].beiratkozas;
        hallgatok[i].nev[0] = toupper(hallgatok[i].nev[0]);
    }

    for (int i=0; i<3; ++i)
        cout << hallgatok[i].nev << ", " << hallgatok[i].beiratkozas << "\n";

    getline(cin, kuka); getline(cin, kuka);

    // Olyan tömböt is lehet készíteni, aminek az alaptípusa maga is tömb. Ha
    // egy "sima" tömb matematikai megfelelője egy valahány dimenziós vektor,
    // akkor a tömbök tömbje egy mátrixként képzelhető el.

    double matrix[3][5] = {
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.1, 2.2, 2.3, 2.4, 2.5},
        {3.1, 3.2, 3.3, 3.4, 3.5}
    };

    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<5; ++j)
            cout << "   " << matrix[i][j];
        cout << "\n";
    }
}
