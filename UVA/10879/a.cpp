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

int main() {
	ios::sync_with_stdio(false);

	int n; cin >> n;
	for (int test = 0; test < n; ++test)
	{
		int num; cin >> num;
		ii one(0 , 0); ii two(0 , 0);
		for (int i = 2 ; i < sqrt ((double)num) ; i++){
			if (!(num % i)){
				if (!one.first) {one = ii (i , num/i);}
				else if (!two.first){two = ii (i , num/i);
					cout << "Case #"<<test + 1<<": "<<num<<" = "<<one.first<<" * "<<one.second<<" = "<<two.first<<" * "<<two.second<< endl;
				}
			}
		}
	}

	return 0;
}
