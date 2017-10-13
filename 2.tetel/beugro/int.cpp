#include "int.h"

Int &Int::operator= (const Int &n)
{
    int *ujertek = new int ();

    *ujertek = * (n.ertek);
    delete
    ertek;

    ertek = ujertek;

    std::cout << "-- Int masolo ertekadas "
              << *ertek << " " << this << " " << ertek << std::endl;

    return *this;
}

Int &Int::operator= (Int && n)
{
    std::swap(ertek, n.ertek);

    std::cout << "-- Int mozgato ertekadas "
              << *ertek << " " << this << " " << ertek << std::endl;

    return *this;
}

std::ostream &
operator<< (std::ostream &os, const Int &n)
{
    os << * (n.ertek);
    return os;
}
