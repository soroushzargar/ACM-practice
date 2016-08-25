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

double dist (double xa , double ya , double xb , double yb){
	double result = 0;
	result = sqrt(pow(xa - xb , 2) + pow(ya - yb , 2));
	return result;
}

int main() {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int test = 0 ; test <tc ; test++){
		double xa , xb , ya , yb;
		cin >> xa >> ya >> xb >> yb;

		cout << fixed << setprecision(3) << dist (xa , ya , xb , yb) + dist (xa , -ya , -xb , yb) << endl;
	}

	return 0;
}
