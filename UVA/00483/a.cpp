#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main (){
    string a;
    while (getline(cin ,a)){
        stringstream ss;
        ss << a;
        string temp;
        bool first = true;
        while (ss>>temp){

            if (first) first = false;
            else cout << " ";
            for (int i = temp.length() - 1 ; i >= 0; i--) cout << temp[i];
            
        }cout << endl;
    }
    return 0;
}
