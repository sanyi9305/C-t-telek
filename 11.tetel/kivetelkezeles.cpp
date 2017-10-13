 // Listing 24.1 throwing exceptions
 #include <iostream>
#include <map>

 const int DefaultSize = 10;

 // kivétel osztály definiálása
 class xBoundary
 {
 public:
     xBoundary() {}
     ~xBoundary() {}
 private:
 };

 class Array
 {
 public:
     // konstruktorok
     Array(int itsSize = DefaultSize);
     Array(const Array &rhs);
     ~Array() { delete [] pType;}

     // operátoraim
     Array& operator=(const Array&);
     int& operator[](int offSet);
     const int& operator[](int offSet) const;

     // függvényeim
     int GetitsSize() const { return itsSize; }

     // barátfv
     friend std::ostream& operator<< (std::ostream&, const Array&);

 private:
     int *pType;
     int  itsSize;
 };


 Array::Array(int size):
 itsSize(size)
 {
     pType = new int[size];
     for (int i = 0; i<size; i++)
         pType[i] = 0;
 }


 Array& Array::operator=(const Array &rhs)
 {
     if (this == &rhs)
         return *this;
     delete [] pType;
     itsSize = rhs.GetitsSize();
     pType = new int[itsSize];
     for (int i = 0; i<itsSize; i++)
         pType[i] = rhs[i];
     return *this;
 }

 Array::Array(const Array &rhs)
 {
     itsSize = rhs.GetitsSize();
     pType = new int[itsSize];
     for (int i = 0; i<itsSize; i++)
         pType[i] = rhs[i];
 }


 int& Array::operator[](int offSet)
 {
     int size = GetitsSize();
     if (offSet >= 0 && offSet < size)
         return pType[offSet];
     throw xBoundary();
     return pType[offSet]; 
 }


 const int& Array::operator[](int offSet) const
 {
     int mysize = GetitsSize();
     if (offSet >= 0 && offSet < mysize)
         return pType[offSet];
     throw xBoundary();
     return pType[offSet]; 
 }

 std::ostream& operator<< (std::ostream& output,
                           const Array& theArray)
 {
     for (int i = 0; i<theArray.GetitsSize(); i++)
         output << "[" << i << "] " << theArray[i] << std::endl;
     return output;
 }

 int main()
 {
     Array intArray(99);
     try
     {
         for (int j = 0; j<100 ; j++)
         {
             intArray[j] = j;
             std::cout << "bemenő adat[" << j
                 << "] ok..." << std::endl;
         }
     }
     catch (xBoundary)
     {
         std::cout << "A bemenő adatot nem sikerült feldolgozni!\n";
     }
     std::cout << "Done.\n";
     return 0;
 }