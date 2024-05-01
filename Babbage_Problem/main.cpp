#include <iostream>
#include <string>
using namespace std;

//99,736
//25264
//269,696

int main() {

    int res = -1;
    string val = "269696";
    string res_val;

    for(long long i = 99735; i >= 0; i--) {
        long long mult = i * i;
        res_val = to_string(mult);

        if(res_val.length() < 6) {
            res = -1;
            break;
        }
        res_val = res_val.substr(res_val.length() - 6, 6);

        if(res_val == val) {
            res = i;
            break;
        }

    }
    cout << res << endl;

    return 0;
}