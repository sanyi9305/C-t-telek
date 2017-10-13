
 #include <iostream>

 enum { kIsSmaller, kIsLarger, kIsSame};

 
 

 class Data
 {
 public:
     Data(int val):myValue(val){}
     ~Data()
     {
         std::cout << " Data törlése!...Értéke:  ";
         std::cout << myValue << "\n";
     }
     int Compare(const Data &);				   //összehasonlítja a két objektumot és meghatározza a poziciót
     void Show() { std::cout << myValue << std::endl; }    //objektum értéke
 private:
     int myValue;
 };

 //a listában elfoglalt hely megállapítása
 int Data::Compare(const Data & theOtherObject)
 {
     if (myValue < theOtherObject.myValue)
         return kIsSmaller;
     if (myValue > theOtherObject.myValue)
         return kIsLarger;
     else
         return kIsSame;
 }


 class Cat
 {
 public:
     Cat(int age): myAge(age){}
     ~Cat()
     {
         std::cout << "Töröljük a  " << myAge
             << " éves macskát.\n";
     }
     int Compare(const Cat &);
     void Show()
     {
         std::cout << "Ez a macska  " << myAge
             << " éves\n";
     }
 private:
     int myAge;
 };


 int Cat::Compare(const Cat & theOtherCat)
 {
     if (myAge < theOtherCat.myAge)
         return kIsSmaller;
     if (myAge > theOtherCat.myAge)
         return kIsLarger;
     else
         return kIsSame;
 }


 //Lista absztrakt adattípusa:
 template <class T>
 class Node
 {
 public:
     Node(){}
     virtual ~Node(){}
     virtual Node * Insert(T * theObject)=0;
     virtual void Show() = 0;
 private:
 };

 template <class T>
 class InternalNode: public Node<T>
 {
 public:
     InternalNode(T * theObject, Node<T> * next);
     virtual ~InternalNode(){ delete myNext; delete myObject; }
     virtual Node<T> * Insert(T * theObject);
     virtual void Show() 					
     {
         myObject->Show(); myNext->Show();
     }
 private:
     T * myObject;  // az adott objektum
     Node<T> * myNext;    // következő tárolőelemre mutató mutató
 };

 
 template <class T>
 InternalNode<T>::InternalNode(T * theObject, Node<T> * next):
 myObject(theObject),myNext(next)
 {
 }

 //listába szúrás
 template <class T>
 Node<T> * InternalNode<T>::Insert(T * theObject)
 {
     
     int result = myObject->Compare(*theObject);

     switch(result)
     {
    
     case kIsSame:        //tovább megy arra amelyik nagyobb 
     case kIsLarger:    // ez elé megy
         {
             InternalNode<T> * ObjectNode =
             new InternalNode<T>(theObject, this);
             return ObjectNode;
         }
     
     case kIsSmaller:
         myNext = myNext->Insert(theObject);   //továbbadja a következő elemhez
         return this;
     }
     return this;  
 }


 //farok:
 template <class T>
 class TailNode : public Node<T>
 {
 public:
     TailNode(){}
     virtual ~TailNode(){}
     virtual Node<T> * Insert(T * theObject);
     virtual void Show() { }
 private:
 };

 template <class T>
 Node<T> * TailNode<T>::Insert(T * theObject)
 {
     InternalNode<T> * ObjectNode =
         new InternalNode<T>(theObject, this);
     return ObjectNode;
 }

 //fej adatot nem tartalmaz csaka  lista első elemére mutat
 template <class T>
 class HeadNode : public Node<T>
 {
 public:
     HeadNode();
     virtual ~HeadNode() { delete myNext; }
     virtual Node<T> * Insert(T * theObject);
     virtual void Show() { myNext->Show(); }
 private:
     Node<T> * myNext;
 };

 //a fej létrehozza a farkat is
 template <class T>
 HeadNode<T>::HeadNode()
 {
     myNext = new TailNode<T>;
 }

 //kezdőelem egyből továbbítja az új objektumot
 template <class T>
 Node<T> * HeadNode<T>::Insert(T * theObject)
 {
     myNext = myNext->Insert(theObject);
     return this;
 }

 //maga a lista elkészítése
 template <class T>
 class LinkedList
 {
 public:
     LinkedList();
     ~LinkedList() { delete myHead; }
     void Insert(T * theObject);
     void ShowAll() { myHead->Show(); }
 private:
     HeadNode<T> * myHead;
 };

 
 template <class T>
 LinkedList<T>::LinkedList()
 {
     myHead = new HeadNode<T>;
 }


 template <class T>
 void LinkedList<T>::Insert(T * pObject)
 {
     myHead->Insert(pObject);
 }

 void myFunction(LinkedList<Cat>& ListOfCats);
 void myOtherFunction(LinkedList<Data>& ListOfData);


 int main()
 {
     LinkedList<Cat>  ListOfCats;
     LinkedList<Data> ListOfData;

     myFunction(ListOfCats);
     myOtherFunction(ListOfData);

     // nListalemek kiratása
     std::cout << "\n";
     ListOfCats.ShowAll();
     std::cout << "\n";
     ListOfData.ShowAll();
     std::cout << "\n ************ \n\n";
     return 0;  // a listák törlődése
 }

 void myFunction(LinkedList<Cat>& ListOfCats)
 {
     Cat * pCat;
     int val;

    //értékek bekérése majd a listába tétele
     for (;;)
     {
         std::cout << "\nHány éves a macskád (0-továbblépés): ";
         std::cin >> val;
         if (!val)
             break;
         pCat = new Cat(val);
         ListOfCats.Insert(pCat);
     }

 }

 void myOtherFunction(LinkedList<Data>& ListOfData)
 {
     Data * pData;
     int val;

     for (;;)
     {
         std::cout << "\nAdj meg adatokat:  (0-kilépés): ";
         std::cin >> val;
         if (!val)
             break;
         pData = new Data(val);
         ListOfData.Insert(pData);
     }

 }
