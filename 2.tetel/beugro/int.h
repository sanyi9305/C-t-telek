#ifndef INT__H
#define INT__H

#include <iostream>
#include <utility>

class Int
{
public:
    Int(int n = 0) : ertek(new int (n)) {
        std::cout << "-- Int ctor "
                  << *ertek << " " << this << " " << ertek << std::endl;
    }
    Int(const Int &n) : ertek(new int) {
        *ertek = * (n.ertek);
        std::cout << "-- Int masolo ctor "
                  << *ertek << " " << this << " " << ertek << std::endl;
	std:: cout<< *(n.ertek) << " " << this << " " << n.ertek << std::endl;
    }
    Int(Int && n) : ertek(n.ertek) {
        n.ertek = nullptr;
        std::cout << "-- Int mozgato ctor "
                  << *ertek << " " << this << " " << ertek << std::endl;
    }
    ~Int() {
        std::cout << "-- Int dtor "
                  << this << " " << ertek << std::endl;

        delete ertek;
    };


    Int &operator= (const Int &n);
    Int &operator= (Int && n);

    int getVal() const {
        return *ertek;
    }

    friend std::ostream &operator<< (std::ostream &os, const Int &n);

private:
    int *ertek;
};

#endif
