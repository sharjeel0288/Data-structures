#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
   
class array {
  int *p;
  int size;
public:
array(){}
  array(int sz) {
    try {
      p = new int[sz];
    } catch (bad_alloc xa) {
      cout << "Allocation Failure\n";
      exit(EXIT_FAILURE);
    }
    size = sz;
  }
  void setsize(int sz){
      try {
      p = new int[sz];
    } catch (bad_alloc xa) {
      cout << "Allocation Failure\n";
      exit(EXIT_FAILURE);
    }
    size = sz;
  }
  ~array() { delete [] p; }
   
  // copy constructor
  array(const array &a);
   
  void put(int i, int j) {
    if(i>=0 && i<size) p[i] = j;
  }
  int get(int i) {
    return p[i];
  }
};
   
// Copy Constructor
array::array(const array &a) {
  int i;
   
  try {
    p = new int[a.size];
  } catch (bad_alloc xa) {
    cout << "Allocation Failure\n";
    exit(EXIT_FAILURE);
  }
  for(i=0; i<a.size; i++) p[i] = a.p[i];
}
   
int main()
{
    int n;
    cout<<"Enter len : ";
    cin>>n;
  array num[n];
  int i,temp,sum=0;
   
 for (int  i = 0; i < n; i++)
 {
     num[i].setsize(n);
 }
 for (int i = 0; i < n; i++)
 {
     for(int j=0;j<n;j++)
     {
         cout<<"-> ";
         cin>>temp;
         num[i].put(j,temp);
         if(temp==1)
         sum++;
     }
 }
 cout<<"Total ones : "<<sum;
   
  return 0;
}