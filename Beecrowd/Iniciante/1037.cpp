#include <iostream>

using namespace std;

int main(void){
    float val;
    cin >> val;

   if ( val >= 0 and val <= 25) {
    cout << "Intervalo [0,25]\n";
   }

   else if (val > 25 and val <= 50) {
    cout << "Intervalo (25,50]\n";
   }

   else if (val > 50 and val <= 75) {
    cout << "Intervalo (50,75]\n";
   }

   else if (val > 75 and val <= 100)
   {
    cout << "Intervalo (75,100]\n";
   }
   
   else
   cout << "Fora de intervalo\n";

   return 0;
}
