#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    unsigned long long s , d;

    while (cin >> s >> d){
        unsigned long long res = 0;

        while (res < d){
            res += s;
            s++;
        } cout << s - 1 << endl;

    }


    return 0;
}
