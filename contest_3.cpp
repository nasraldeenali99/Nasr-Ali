#include <iostream>
using namespace std ;

int main() {
    long long contest ;
    cin >> contest ;

    while (contest != 1) {
        cout << contest<< " ";
        if (contest% 2 == 0) {
            contest /= 2;
        } else {
            contest = 3 * contest + 1;
        }
    }
    cout << 1 << endl;

    return 0;
}
