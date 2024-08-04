#include <iostream>
#include <chrono>
#include "array.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    array_d l1;
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    auto beg = std::chrono::high_resolution_clock::now();
    unsigned int m;
    std::cin >> m;
    unsigned int removed = 0, not_removed = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        if (l1.remove_at(x))
            removed++;
        else
            not_removed++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to remove " << m << " element(s)\n";
    std::cerr << "[DEBUG] removed " << removed << " element(s)\n";
    std::cerr << "[DEBUG] not removed " << not_removed << " element(s)\n";
    if (not (l1.size() == n - removed) or (not_removed + removed != m)) {
        std::cerr << "[ERROR] check remove_at method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << removed << " remove_at success : "
        << elapsed.count() << std::endl;
    return 0;
}