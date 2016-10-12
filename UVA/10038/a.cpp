#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){
    int n , temp;
    while (cin >> n){
        bool valid = true;
        vector <int> diff (n , 0);
        int bc_n = n;
        int oldvalue; cin >> oldvalue; n--;
        while (n--){
            int temp; cin >> temp;
            if (abs(temp - oldvalue) >= bc_n) valid = false;
            else diff[abs(temp - oldvalue)]++;
            oldvalue = temp;
        }
        for (int i = 1 ; i < bc_n ; i++) if (diff[i] == 0){valid = false; break;}
        if (valid) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }

    return 0;
}
