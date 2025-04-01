#include <iostream>
#include <iomanip>
int main(void) {
    int a, b;
    float c;
    std::cin >> a >> b >> c;
    std::cout << "NUMBER = " << a <<"\n";
    std::cout << "SALARY = U$ " << std::fixed << 
                    std::setprecision(2) << b*c << "\n";
    return 0;
}
