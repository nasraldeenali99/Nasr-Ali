// #include <iostream>
// #include <unordered_set>
// using namespace std ;

// bool isCharmed(int number) {
//     unordered_set<int> charmedNumbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 777};

//     for (int charmedNum : charmedNumbers)
//     {
//                if (number % charmedNum == 0) 
//             {
//                 return true;
//             }
//     }
//     return false;
// }
// int main() {
//     int x;
//     cin >> x;
//     if (isCharmed(x)) {
//         cout << "YES\n";
//     } else {
//        cout << "NO\n";
//     }
//     return 0;
// }



#include <iostream>
#include <unordered_set>
using namespace std ;

bool isAlmostCharmed(long long number) {
    
    unordered_set<long long > charmedNumbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 777};

    
    for (int charmedNum : charmedNumbers) {
        if (number % charmedNum == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int x;
    cin >> x;

    if (isAlmostCharmed(x)) {
       cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
