#include <iostream>
using namespace std;

// Objects of this class are partially filled arrays of ints.
class PFArrayI
{
public:
    PFArrayI(); // Initializes with a capacity of 50.
    PFArrayI(int capacityValue);
    PFArrayI(const PFArrayI& pfaObject);
    ~PFArrayI();

    // Precondition : The array is not full.
    // Postcondition : The element has been added.
    void addElement(int element);
    
    // Returns true if the array is full, false otherwise.
    bool full() const { return (used == capacity); }

    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    
    // Empties the array.
    void emptyArray() { used = 0; }
    
    // Read and change access to elements 0 through numberUsed -1.
    int& operator[] (int index);
    
    PFArrayI& operator= (const PFArrayI& rightside);

private:
    int *a; // For an array of ints
    int capacity;   // For the size of the array
    int used;   // For the number of array positions currently in use
};

int main(){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayI temp(cap);
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    int next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    return 0;
}

PFArrayI::PFArrayI() : capacity(50) ,used(0) 
{
    a = new int[capacity];
}

PFArrayI::PFArrayI(int size) : capacity(size), used(0)
{
    a = new int[capacity];
}

PFArrayI::PFArrayI(const PFArrayI& pfaObject) 
    : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new int[capacity];
    for (int i = 0; i < used; i++){
        a[i]=pfaObject.a[i];
    }
}

void PFArrayI::addElement(int element)
{
    if (used >= capacity)
    {
        cout << "Attaemp to exceed capacity in PFArrayI" << "\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

int& PFArrayI::operator[](int index){
    if(index >= used){
        cout << "Illegal index" << "\n";
        exit(0);
    }
    return a[index];
}

PFArrayI& PFArrayI::operator =(const PFArrayI& rightside)
{
    if(capacity != rightside.capacity){
        delete [] a; 
        a = new int[rightside.capacity];
       }
       capacity = rightside.capacity;
       used = rightside.used;
       for (int i = 0; i < capacity; i++){
           a[i] = rightside.a[i];
       }
       return *this;
}
PFArrayI::~PFArrayI(){
    delete []a;
}