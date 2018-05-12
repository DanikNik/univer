#include "class.h"

int main(int argc, char const *argv[]) {
    MyClass obj1 = MyClass(1, 2, "obj1");
    MyClass obj2 = MyClass(3, 4, "obj2");
    cout << boolalpha << (obj1 < obj2) << '\t' << (obj1 > obj2) << endl;
    MyClass ob1 = obj1 + 2;
    MyClass ob2 = obj1 - obj2;
    cout << ob1 << endl;
    cout << ob2 << endl;
    return 0;
}
