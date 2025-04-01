#include <iostream>
#include <iomanip>
#include <string>
int main(void) {
    std::string nome;
    float x, y;
    std::cin >> nome >> x >> y;
    std::cout << "TOTAL = R$ " << std::fixed <<
        std::setprecision(2) << x + (y*0.15) << "\n";
    return 0;
}
