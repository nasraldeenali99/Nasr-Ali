// #include <iostream>
// #include <cctype>
// using namespace std ;

// int main() {
//     string input;
//     cin >> input;

//     string result;
//     for (char A : input) {
       
//         if (isupper(A)) {
//             A = tolower(A);
//         }

     
//         if (A != 'a' && A != 'e' && A != 'i' && A != 'o' && A != 'u' && A != 'y') {
//             result += '.';
//             result += A;
//         }
//     }

//     cout << result << endl;

//     return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long x;
    cin >> x;

    // Convert the number to a string for easier manipulation
    string str_x = to_string(x);

    // Invert the digits
    for (char& c : str_x) {
        c = min(c, '9' - c); // Replace with the smaller of c and 9-c
    }

    // Remove leading zeros
    str_x.erase(0, min(str_x.find_first_not_of('0'), str_x.size() - 1));

    cout << str_x << endl;

    return 0;
}

