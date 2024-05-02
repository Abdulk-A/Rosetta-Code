
#include <iostream>
#include <string>

using namespace std;

void encode(string &s, int cc){
     for(int i = 0; i < s.length(); i++){
        if(isupper(s[i]) && s[i] + cc > 90) s[i] = 65 + ((s[i] + cc) % 90);
        else if(islower(s[i]) && s[i] + cc > 122) s[i] = 97 + ((s[i] + cc) % 122);
        else s[i] = s[i] + cc;
    }

}

int main() {

    string s; int cc;


    cout << "Please enter something to decode: ";
    getline(cin, s);

    cout << "Please enter number: ";
    cin >> cc;

    encode(s, (cc % 25));

    cout << s << endl;

    return 0;
}
