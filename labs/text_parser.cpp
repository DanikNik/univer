#include <iostream>
#include <string.h>
#define str_max_size 80
using namespace std;


void get_sorted_array(char ** words, int word_counter){
    char * cur = new char [str_max_size];
    for(int i = 0; i < word_counter - 1; i++)
        for(int j = i + 1; j < word_counter; j++)
            if(strcmp(words[i], words[j]) > 0)
            {
                strcpy(cur, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], cur);
            }
}


int main(){
// т.к. максимальная длина текста 80, выделяем место еще под возможный символ терминатора
    char * mystr = new char[str_max_size + 1];
    size_t i = 0;

// reading and filtering string input
    cout << "[>] Enter your string: ";
    char sym;
    bool first_spaces = true;

    do{
        sym = getchar();
        if (first_spaces == true){
            if (sym != ' '){
                first_spaces = false;
                mystr[i] = sym;
                i++;
            }
        }
        else{
            if (islower(sym) or isspace(sym) or sym == '.'){
                if (sym == ' ' and mystr[i-1] == ' ') {
                    continue;
                }
                else if (sym == '.' and mystr[i-1] == ' '){
                    mystr[i-1] = '.';
                    break;
                }
                else {
                    mystr[i] = sym;
                    i++;
                }
            }
        }
    }while(sym!='.');

    mystr[i] = '\0';
    size_t str_len = i; //чтобы точку не учитывать))))


// counting words
    int word_counter = 0;
    if (mystr[0] !=' ') word_counter++;
    for (size_t i = 0; i < str_len - 1; i++) {
        if (mystr[i] == ' '){
            if (mystr[i+1] != ' '){
                word_counter++;
            }
        }
    }


// counting max word length
    int current_word_len = 0, max_word_len = 0;
    i = 0;
    while (mystr[i] != '\0') {
        while (mystr[i] != ' ' and mystr[i] != '.') {
            current_word_len++;
            i++;
        }
        if (current_word_len > max_word_len) {
            max_word_len = current_word_len;
        }
        current_word_len = 0;
        i++;
    }

// initing words array
    char ** words = new char * [word_counter];
    for (size_t i = 0; i < word_counter; i++) {
        words[i] = new char [max_word_len];
    }

// writing words to array
    int j = 0;
    size_t current_word = 0;
    for (size_t i = 0; i < str_len - 1; i++) {
        if (mystr[i] == ' '){
            current_word++;
            j = 0;
            continue;
        }
        words[current_word][j] = mystr[i];
        j++;
    }

// print sorted array
    get_sorted_array(words, word_counter);
    cout << "[+] sorted word order: \n";
    char * output = new char [81];
    for(int i = 0; i < word_counter; i++){
        strcat(output, words[i]);
        strcat(output, " ");
    }
    cout << output << '\n';
    return 0;
}
