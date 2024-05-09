#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string x;
    cin >> x;

    bool leadingZero = true;
    for (char& c : x) {
        if (c != '9' && leadingZero) {
            leadingZero = false;
        }
        if (leadingZero && c == '0') {
            continue;
        }
        c = min(c, '9' - c);
    }

    cout << x << endl;

    return 0;
}
