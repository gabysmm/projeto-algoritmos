#include <iostream>
#include "array.hpp"
using namespace std; 

int main(){
  array_d listad;
  int tam;
  cin >> tam;
  int x;
  for (int i = 0; i < tam; i++) {
    cin >> x;
    listad.push_back(x);
  }

  listad.push_front(1);
  listad.push_front(2);
  listad.push_back(3);
  listad.push_back(4);

//PRINT
  for(unsigned int i = 0; i < listad.size(); i++){
    cout << listad.get_at(i);
  }
  
  return 0;
}