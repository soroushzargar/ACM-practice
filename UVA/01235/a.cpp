#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii , int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

int distance (string a , string b){
	// cerr << a << " " << b << endl;
	int result = 0;
	for (int i = 0 ; i < 4 ; i++){

		result += min (10 - abs(b[i] - a[i]) , abs(b[i] - a[i]));

		// cerr <<" result : " << result << endl;
	} return result;
}

vi par;

int find(int i){
	if (par[i] == i) return i;
	return par[i] = find(par[i]);
}

void join (int i , int j){
	par [find (i)] = find(j);
}

// bool comp (pair <ii , int>a , pair <ii , int> b){ return a.second < b.second;}
class comp{public: bool operator() (pair <ii , int>a , pair <ii , int> b){ return a.second > b.second;}};

int main() {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	while (tc--){
		int keycount; cin >> keycount;
		vector <string> keys;

		priority_queue <pair <ii , int>  , vector <iii> , comp> edges;

		for (int i = 0; i < keycount; ++i)
		{
			string temp; cin >> temp;

			for (int j = 0 ; j < keys.size() ; j++){
				edges.push(make_pair (make_pair (j, i) , distance(keys[j], temp)));
			}

			keys.push_back(temp);
		}
		int mst = 0;
		par.clear ();

		for (int i = 0 ; i < keys.size(); i++ ) par.push_back(i);

		while (!edges.empty()){
			pair <ii , int> current = edges.top();
			edges.pop();
			if (find (current.first.first) != find(current.first.second)){
				mst += current.second; join(current.first.first , current.first.second);
			}
		}

		int mindist = distance ("0000" ,  keys[0]);

		for (int i = 0 ; i <keys.size() ; i++) if (distance ("0000" , keys[i]) < mindist) mindist = distance ("0000" , keys[i]);

		cout << mindist + mst << endl;
	}

	return 0;
}
