#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool dominate (int graphSize , vector <vector <int> > adjMat , int domin , int vertex){

    if (domin == vertex) return true;
    if (domin == 0) return true;

    stack <int> DFS;
    vector <int> visited (graphSize , 0);

    DFS.push(0);
    visited [0] = 1;
    while (!DFS.empty()){
        int current = DFS.top();
        visited [current] = 1;
        DFS.pop();
        for (int i = 0 ; i < graphSize ; i++){
            if (visited[i] == 0 && i != domin && adjMat[current][i] == 1){
                DFS.push(i);
            }
        }
    }

    if (visited[vertex] == 1) return false;
    return true;

}

int main (){
    ios::sync_with_stdio(false);

    int testcase;
    cin >> testcase;
    for (int t = 0 ; t < testcase ; t++){
        int graphSize; cin >> graphSize;
        vector <vector <int > > adjMat(graphSize , vector <int> (graphSize , 0));
        for (int i = 0 ; i < graphSize ; i++){for (int j = 0 ; j < graphSize ; j++){cin >> adjMat[i][j];}}

        cout << "Case " << t + 1 << ":" << endl;

        for (int i = 0 ; i < graphSize ; i++){
            cout << '+';
            for (int j = 0 ; j < 2 * graphSize - 1 ; j++) cout << '-';
            cout << '+' << endl;

            cout << '|';
            for (int j = 0 ; j < graphSize  ; j++){
                if (dominate (graphSize  , adjMat , i , j)) cout << 'Y' << '|';
                else cout << 'N' << '|';
            }
            cout << endl;
        }

        cout << '+';
        for (int j = 0 ; j < 2 * graphSize - 1 ; j++) cout << '-';
        cout << '+' << endl;

    }

    return 0;
}
