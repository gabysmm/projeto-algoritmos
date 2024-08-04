#include <bits/stdc++.h>
#include "array_d.hpp"

using namespace std;



int main(){
    array_d lista;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n;i++){
        cin >> x;
        lista.push_back(x);
    }
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n;i++){
        lista.pop_back();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (lista.size() == 0)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
        std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pop front:"
        << elapsed.count() << std::endl;
        std::cout << lista.size()<< "\n";

 return 0;

}