
#include <iostream>
#include <string>

using namespace std;

void encode(string &s, int cc){
     for(int i = 0; i < s.length(); i++){
        if(s[i] >= 65 && s[i] <= 90 && s[i] + cc > 90) s[i] = 64 + (cc - ('Z' - s[i]));
        else if(s[i] >= 97 && s[i] <= 122 && s[i] + cc > 122) s[i] = 96 + (cc - ('z' - s[i]));
        else s[i] = s[i] + cc;
    }

}

int main() {

    string s; int cc;


    cout << "Please enter something to decode: ";
    getline(cin, s);

    cout << "Please enter number: ";
    cin >> cc;

    encode(s, cc % 26);

    cout << s << endl;

    return 0;
}

