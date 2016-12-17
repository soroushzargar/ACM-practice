#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main (){
    int m ,n;
    while (cin >> m >> n){
        if (m == n && n == 0) return 0;
        vector <vector <int> > map (m , vector <int> (n , 0));

        int deps = 0;
        for (int i = 0 ; i < m ; i++) for (int j = 0 ; j < n ; j++){
            char temp; cin >> temp; if (temp == '@'){
                map[i][j] = 1;
            }
        }
        stack <pair <int , int> > dfs;
        int cc = 0;
        vector <vector <int> > visited (m , vector <int> (n , 0));
        while (true){
            if (dfs.empty()){
                //cerr << "CHECKING" << endl;
                bool continuee = false;
                for (int i = 0 ; i < m && ! continuee; i++)
                    for (int j = 0 ; j < n && !continuee ; j++){
                    if ((!visited[i][j]) && map[i][j]){
                        dfs.push(pair <int , int> (i ,  j));
                        //visited[i][j] = true;
                        continuee = true;
                        cc++;
                        break;
                    }if (continuee) break;
                }
                if (!continuee) break;
            }
            pair <int , int> current = dfs.top();
            dfs.pop();
            visited[current.first][current.second] = cc;
            vector <pair < int , int > > avail;
            avail.push_back(pair <int , int> (current.first -1 , current.second));
            avail.push_back(pair <int , int> (current.first +1 , current.second));
            avail.push_back(pair <int , int> (current.first , current.second -1));
            avail.push_back(pair <int , int> (current.first , current.second +1));
            avail.push_back(pair <int , int> (current.first -1, current.second -1));
            avail.push_back(pair <int , int> (current.first -1, current.second +1));
            avail.push_back(pair <int , int> (current.first +1, current.second -1));
            avail.push_back(pair <int , int> (current.first +1, current.second +1));

            for (int i = 0 ; i < avail.size() ; i++){
                if (avail[i].first >= 0 && avail[i].first < m &&
                    avail[i].second >= 0 && avail[i].second < n){
                        if (map[avail[i].first][avail[i].second] &&
                            (!visited[avail[i].first][avail[i].second])){
                                dfs.push (avail[i]);
                                visited[avail[i].first][avail[i].second] = cc;
                            }
                    }
            }
            //cerr << "visiteds ====================" << endl;
            //for (int i =0 ; i  < m ; i++){
            //    for (int j =0 ; j < n ; j++) //cerr << visited[i][j];
                //cerr << endl;
            //}
        }
        cout << cc << endl;
    }
    return 0;
}
