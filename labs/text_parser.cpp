#include <iostream>
#include <stdio.h>
#define str_max_size 80
using namespace std;


void append(char * array_to_increase, char elem){
    int origin_size = sizeof(array_to_increase)/sizeof(array_to_increase[0]);
    cout << array_to_increase << endl;
    char *temp = new char [origin_size + 1];
    for (size_t i = 0; i < origin_size; i++) {
        temp[i] = array_to_increase[i];
    }
    temp[origin_size + 1] = elem;
    //вот здесь переопределение памяти для массива array_to_increase
    //т.е. определение для то же указателя памяти origin_size + 1 вместо origin_size
    delete [] array_to_increase;
    array_to_increase = new char [origin_size + 1];
    for (size_t i = 0; i < origin_size + 1; i++) {
        array_to_increase[i] = temp [i];
    }
}


int main(){
    static char * mystr = new char[80];   //т.к. максимальная длина текста 80, выделяем место еще под возможный символ терминатора
    size_t i = 0;

    char sym;
    do{
        sym = getchar();
        if (islower(sym) or isspace(sym) or sym == '.'){
            append(mystr, sym);
            i++;
        }
    }while(sym!='.');

    // mystr[i] = '\0';
    size_t str_len = i - 1; //чтобы точку не учитывать))))

    int word_counter = 0;
    for (size_t i = 0; i < str_len; i++) {
        if (mystr[i] == ' '){
            if (mystr[i+1] != ' '){
                word_counter+=1;
            }
        }
    }

    for (i = 0; i < str_len; i++){
        cout << mystr[i];
    }
    cout << '\n';
    return 0;
}
