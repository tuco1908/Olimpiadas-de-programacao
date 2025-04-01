#include <iostream>
int main(void) {
    float valor;
    std::cin >> valor;
    int inteiro = valor;
    int virgula = ( valor* 100);
    virgula = virgula % 100;

using std::cout;

cout << "NOTAS:\n";
cout << inteiro/100 << " nota(s) de R$ 100.00\n";
inteiro = inteiro%100;
cout << inteiro/50  << " nota(s) de R$ 50.00\n";
inteiro = inteiro%50;
cout << inteiro/20  << " nota(s) de R$ 20.00\n";
inteiro = inteiro%20;
cout << inteiro/10  << " nota(s) de R$ 10.00\n";
inteiro = inteiro%10;
cout << inteiro/5 << " nota(s) de R$ 5.00\n";
inteiro = inteiro%5;
cout << inteiro/2 << " nota(s) de R$ 2.00\n";

cout << "MOEDAS:\n";
cout << inteiro%2 << " moeda(s) de R$ 1.00\n";
cout << virgula/50  << " moeda(s) de R$ 0.50\n";
virgula = virgula%50;
cout << virgula/25  << " moeda(s) de R$ 0.25\n";
virgula = virgula%25;
cout << virgula/10  << " moeda(s) de R$ 0.10\n";
virgula = virgula%10;
cout << virgula/5  << " moeda(s) de R$ 0.05\n";
cout << virgula%5 << " moeda(s) de R$ 0.01\n";
    return 0;
}
