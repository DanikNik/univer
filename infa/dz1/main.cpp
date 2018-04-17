#include "class.h"

int main(int argc, char const *argv[]) {
    MyClass obj1 = MyClass(1, 2, "obj1");
    MyClass obj2 = MyClass(3, 4, "obj2");
    MyClass obj_sum = obj1 + obj2;
    cout << obj_sum << endl;   
    return 0;
}
