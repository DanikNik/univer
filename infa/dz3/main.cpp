#include "class.h"

int main(){
    Stack<int> stack = Stack<int>();
    stack.push(10);
    stack.push(20);
    stack.push(300);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}
