#include <iostream>
#include <string>
using namespace std ;

int main() {
    int N;
    cin >> N; 

   string result; 
    for (int i = 1; i <= N; ++i) {
        if (i % 3 == 0) {
            result += 'x';
        } else {
            result += 'o'; 
        }
    }

    cout << result << endl; 

    return 0;
}
