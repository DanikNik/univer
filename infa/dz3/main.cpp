#include "class.h"

int main(){
    DinArr<int> stack = DinArr<int>();
    stack.push(10);
    stack.push(20);
    cout << stack;
    cout << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}
