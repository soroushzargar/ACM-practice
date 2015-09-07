#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);

    int k;
    while (cin >> k){
        int divX; cin >> divX;
        int divY; cin >> divY;

        while (k--){
            int x; cin >> x;
            int y; cin >> y;
                 if (x > divX && y > divY) cout << "NE" << endl;
            else if (x > divX && y < divY) cout << "SE" << endl;
            else if (x < divX && y > divY) cout << "NO" << endl;
            else if (x < divX && y < divY) cout << "SO" << endl;

            else cout << "divisa" << endl;
        }

    }

    return 0;
}
