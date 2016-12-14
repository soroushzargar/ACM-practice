#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
    int test; cin >> test;
    while (test--){
        string a;
        cin >> a;
        int prev = 0;
        int result = 0;
        for (int i = 0 ; i < a.size() ; i++){
            if (a[i] == 'X') prev = 0;
            else prev ++;
            result += prev;
        }
        cout << result << endl;
    }
    return 0;
}
