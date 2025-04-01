#include <iostream>
#include <iomanip>
int main(void){
    float a, b;
    std::cin >> a >> b;
    std::cout << "MEDIA = " << std::fixed << 
    std::setprecision(5) << (3.5*a + 7.5*b)/11 << "\n";
    return 0;
}
