#include <iostream>

using namespace std;

int main (){
    int a , b;
    while (cin >> a >> b){
        int carry = 0;
        int c = 0;
        if (a == b && b == 0) return 0;

        while (a != 0 || b != 0){
            if (a % 10 + b % 10 >= 10){
                carry++;
                c = a % 10 + b % 10 % 10
            }

        }

    }

    return 0;
}
