#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {

    string s;
    int count = 0;
    int max = 0;
    string maxStr;
    string lastStr;
    while (cin >> s) {
        if (s == "break") {
            break;
        }
        if (lastStr == s) {
            count ++;
        } else {
            if (count > max) {
                max = count;
                maxStr = lastStr;
            }
            count = 0;
            lastStr = s;
        }
    }
    if (max > 0) {
        cout << maxStr + " count = " << max + 1 << endl;
    }

    return 0;
}
