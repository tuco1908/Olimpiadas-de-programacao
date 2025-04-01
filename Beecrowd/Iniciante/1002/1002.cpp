#include <iostream>
#include <iomanip>
int main(void) {
    double r;
    std::cin >> r;
    std::cout << "A=" << std::fixed 
    << std::setprecision(4) <<
    3.14159*r*r << "\n";
    return 0;
}
