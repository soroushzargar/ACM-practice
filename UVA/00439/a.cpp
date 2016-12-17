#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main (){
    string src , dest;
    while (cin >> src >> dest){
        int src_i = src[0] - 'a';
        int src_j = src[1] - '1';

        int dest_i = dest[0] - 'a';
        int dest_j = dest[1] - '1';

        queue <pair <int , int> > dfs;
        vector <vector <int> > visited (8 , vector <int> (8 , 0));
        dfs.push (pair <int , int> (src_i , src_j));
        while (!dfs.empty()){
            pair <int , int> current = dfs.front();
            dfs.pop();

            if (current.first == dest_i && current.second == dest_j) break;

            vector <pair <int , int> > avail;
            avail.push_back(pair <int , int> (current.first + 2, current.second + 1));
            avail.push_back(pair <int , int> (current.first + 1, current.second + 2));
            avail.push_back(pair <int , int> (current.first - 2, current.second - 1));
            avail.push_back(pair <int , int> (current.first - 1, current.second - 2));
            avail.push_back(pair <int , int> (current.first + 2, current.second - 1));
            avail.push_back(pair <int , int> (current.first + 1, current.second - 2));
            avail.push_back(pair <int , int> (current.first - 2, current.second + 1));
            avail.push_back(pair <int , int> (current.first - 1, current.second + 2));
            for (int i = 0 ; i < avail.size() ; i++){
                if (avail[i].first < 0 || avail[i].first >= 8) continue;
                if (avail[i].second < 0 || avail[i].second >= 8) continue;
                if (visited[avail[i].first][avail[i].second]) continue;
                visited[avail[i].first][avail[i].second] = 1 + visited[current.first][current.second];
                dfs.push(avail[i]);
            }
        }
        cout << "To get from " << src << " to " << dest << " takes " << visited[dest_i][dest_j] << " knight moves." << endl;
        
    }
    return 0;
}
