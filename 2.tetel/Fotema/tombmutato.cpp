#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kuka;

    // Természetesen a tömbök elemeinek is van címe, ezeket is lehet mutatók
    // értékeként használni. Ilyenkor még annak is van értelme, hogy
    // megvizsgáljuk, melyik mutató kisebb, mint a másik.

    int it[5] = {5, 4, 3, 2, 1};
    int *ip = &it[1];
    int *mut = &it[3];

    cout << "\n*ip: " << *ip << ", *mut: " << *mut << ", ip < mut: ";
    // A kisebb indexű elem címe kisebb, mint a nagyobb indexűé, így az it
    // mutató értéke kisebb, mint a mut mutatóé
    if (it < mut)
        cout << "igaz\n";
    else
        cout << "hamis\n";

    cout << "\n*mut = 9;\n";

    // A tömb 4. elemét változtatja meg ez az értékadás
    *mut = 9;

    cout << "   it:";
    for (int n=0; n<5; ++n)
        cout << " " << it[n];
    cout << "\n";

    getline(cin, kuka);

    // A primitív tömbök lényegében mutatók segítségével működnek, a [ ]
    // operátor csak egy jelölés, ami egy mutató-műveletet takar. Ugyanezt az
    // operátort lehet használni mutatókra is.
    
    int szamok[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    // Az m mutató a szamok tömb második elemére fog mutatni. A [ ] operátor
    // használatával az ott kezdődő résztömböt érhetjük el.
    int *m = &szamok[2];

    cout << "\n*m: " << *m << ", m[0]: " << m[0] << ", m[4]: " << m[3] << "\n";

    // Természetesen az értékadás is működik ezzel a jelöléssel
    cout << "\nm[i] += i;\n";
    for (int n=1; n<5; ++n)
        m[n] += n;

    cout << "   szamok:";
    for (int n=1; n<8; ++n)
        cout << " " << szamok[n];
    cout << "\n";

    return 0;
}
