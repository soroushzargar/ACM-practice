#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main (){
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n){
        if (n == 0) return 0;
        long long cst = 0;
        long long fnl = 0;
        for (int i = 0 ; i < n ; i++){
            long long temp; cin >> temp;
            cst += temp;
            fnl += abs(cst);
        }
        cout << fnl << endl;
    }

    return 0;
}
