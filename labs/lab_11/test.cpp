#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int x;
    std::cin >> x;
    switch (x) {
        case 1:
        case 2:
        case 3:
        cout << 1 << '\n';
        break;

        case 4:
        case 5:
        case 6:
        cout << 0 << '\n';
        break;
    }
    return 0;
}
