#include <iostream>
#include <iomanip>
int main(void){
    float a, b, c;
    std::cin >> a >> b >> c;
    std::cout << "MEDIA = " << std::fixed << std::setprecision(1) << 
    (2*a + 3*b + 5*c)/10 << "\n";
    return 0;
}
