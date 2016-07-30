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
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;

const int inf = 1e9;

bool covers (vi word , vi alph){
	for (int i = 0 ; i < alph.size() ; i++){
		if (alph[i] < word[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);

	vector <string> dict;
	vector <vi> alpha;
	while (true){
		string temp; cin >> temp; if (temp == "#") break;
		dict.push_back(temp);
		alpha.push_back(vi ('z' - 'a' + 1 , 0));
		for (int i = 0 ; i < temp.size() ; i++){
			alpha.back()[temp[i] - 'a']++;
		}
	}
	cin.get();
	while (true){
		string line; getline (cin , line);
		stringstream ss; ss << line;
		vector <int> alphaset ('z' - 'a' + 1);
		char tmp;
		while (ss >> tmp){
			if (tmp == '#') return 0;
			alphaset[tmp - 'a']++;
		}
		int res = 0;
		for (int i = 0 ; i < alpha.size() ; i++){
			if (covers(alpha[i], alphaset)) res++;
		}
		cout << res << endl;

	}


	return 0;
}
