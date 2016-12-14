#include <iostream>
#include <string>

using namespace std;

int main (){
    char a; string s;
    while (cin >> a >> s){
        if (a == '0' && s == "0") return 0;
        string result; bool leading = true;
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == a) continue;
            if (s[i] == '0' && leading) continue;
            else {
                leading = false;
                result += s[i];
            }
        }
        if (result.size() == 0) result = "0";
        cout << result << endl;
    }
}
