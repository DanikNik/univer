#include <iostream>
#include <string.h>
using namespace std;

char * append(char * array, char elem){
    int origin_size = strlen(array);
    cout << "[=] origin_size: " << origin_size << endl;
    char * temp = new char [origin_size + 1];
    cout << "   [] temp : " << temp << endl;
    for (size_t i = 0; i < origin_size; i++) {
        temp[i] = array[i];
    }
    temp[origin_size] = elem;
    temp[origin_size + 1] = '\0';
    cout << "   [] array addr0: " << &array << endl;
    delete [] array;
    array = temp;
    cout << "   [] temp : " << &temp << endl;
    cout << "   [] temp : " << temp << endl;
    cout << "   [] array addr1: " << &array;
    return array;
}

int main() {
    // char * abcd = new char [sizeof("abc1")];
    // abcd = strcpy_s("abc1");
    char abcd[] = "abc1alfiuugaufyig";
    char * ab = abcd;
    cout <<"[>] abcd addr: " << abcd << endl;
    std::cout << sizeof(ab) << '\n';
    /*char * abcd_p = &abcd[0];
    cout << "[>] abcd_p : " << &abcd_p[0] << endl;*/
    char a = 'x';
    ab = append(ab, a);
    // std::cout << "[] abcd_p new: " << &abcd_p[0] << '\n';
    cout << ab << endl;
    return 0;
}
