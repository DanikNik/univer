#include <iostream>
using namespace std;

bool str_eq(char * str1, char * str2){
    bool flag = true;
    int i = 0;
    while (str1[i] != '\0' or str2[i] != '\0'){
        if (str1[i] != str2[i]){
            flag = false;
        }
        i++;
    }
    return flag;
}

int main() {
    char * text = new char [81];
    char ch;
    int i = 0;
    bool start = false;
    do {
        ch = getchar();
        if (start == false){
            if (!isspace(ch)){
                start = true;
                if(islower(ch) or isspace(ch)){
                    text[i] = ch;
                    i++;
                }
            }
        }
        else{
            if(islower(ch) or isspace(ch)){
                text[i] = ch;
                i++;
            }
        }
    } while(ch != '.');
    text[i] = '\0';
    int str_len = i;

    int w_c= 0;
    if(islower(text[0])){
        w_c++;
    }

    for (int i = 0; i < str_len-1; i++){
        if (isspace(text[i]) and !isspace(text[i+1])){
            w_c++;
        }
    }

    char ** w = new char * [w_c];
    for (int i = 0; i < w_c; i++) {
        w[i] = new char [81];
    }
    int cur = 0;
    int j = 0;
    for (int i = 0; i < str_len; i++) {
        if (!isspace(text[i]) and text[i] != '\0'){
            w[cur][j] = text[i];
            j++;
        }
        else if (isspace(text[i])){
            if (!isspace(text[i+1])){
                w[cur][j] = '\0';
                cur++;
                j = 0;
            }
        }
    }

    if (w[w_c-1] == ""  or w[w_c-1] == " ") {
        w_c = w_c - 1;
    }

    char * last_word = new char [81];
    last_word = w[w_c-1];
    for (int i = 0; i < w_c; i++) {
        if (str_eq(w[i], last_word) == false) {
            j = 0;
            do {
                cout << w[i][j];
                j++;
            } while(w[i][j+1] != '\0');
            cout << endl;

        }
    }

    return 0;
}
