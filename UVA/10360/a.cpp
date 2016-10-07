#include <iostream>
#include <vector>

using namespace std;

int main (){
    int testcases; cin >> testcases;

    while (testcases--){
        int diff; cin >> diff;
        int n; cin >> n;
        vector <vector <int> > manhattan (1025 , vector <int> (1025 , 0));
        while (n--){
            int x , y , cnt; cin >> x >> y >> cnt;
            // manhattan[x][y] += cnt;
            for (int i = max (0 , x - diff) ; i <= min (x + diff , 1024) ; i++){
                for (int j = max (0 , y - diff) ; j <= min(y + diff , 1024 ); j++){
                    manhattan[i][j] += cnt;
                }
            }
        }
        pair <int , int> argmax;
        int maxx = 0;

        for (int i = 0 ; i < 1025 ; i++)
        for (int j = 0 ; j < 1025 ; j++){
                if (manhattan[i][j] > maxx){
                    argmax = make_pair(i, j);
                    maxx = manhattan[i][j];
                }
        }
        cout << argmax.first << " " << argmax.second << " " << maxx << endl;

    }

    return 0;
}
