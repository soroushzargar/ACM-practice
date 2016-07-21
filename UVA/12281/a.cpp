#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <unsigned long long> fibo;
map <unsigned long long , unsigned long long> calced;

unsigned long long calc (unsigned long long a){
    if (calced[a] != 0) return calced[a];
    unsigned long long result = 2000000000;
    for (int i = 0 ; fibo[i] <= a ; i++){
        if (fibo[i] == a) result = 1;
        else {int k =  1 + calc(a - fibo[i]);
        if (k < result)
            result = k;}
    }
    calced[a] = result;
    return result;
}

int main (){
    fibo.push_back(1);
    fibo.push_back(1);
    for (int i = 1 ; fibo[i] < 2000000000 ; i++){
        fibo.push_back(fibo[i] + fibo[i - 1]);
        // cout << fibo[ i+1 ] << endl;
    }

    int test; cin >> test;
    for (int i = 0; i < test; ++i)
    {
        int dim; cin >> dim;
        unsigned long long result = 1;
        for (int i = 0 ; i < dim ; i++){
            int temp; cin >> temp;
            result *= calc(temp);
        }

        cout << "Case " << i+1 <<  ": " << result << endl;
    }

    return 0;
}
