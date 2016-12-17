#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main (){
    ios::sync_with_stdio(false);

    int n;
    vector <int> numbers;
    while (cin >> n){
        numbers.insert(lower_bound(numbers.begin(), numbers.end(), n) , n);
        if (numbers.size() % 2) cout << numbers[numbers.size() / 2];
        else cout << (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1])/2;
        cout << endl;
    }

    return 0;
}
