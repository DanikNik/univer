#include <iostream>
using namespace std;

bool sovp(char * str1, char * str2){
    bool flag = true;
    int i = 0;
    do {
        if (str1[i] != str2[i]){
            flag = false;
        }
        i++;
    } while (str1[i] != '\0' or str2[i] != '\0');
    return flag;
}

int main() {
    char stroka[81];
    char bukva;
    int i = 0;
    bool nachalo = false;
    do {
        bukva = getchar();
        if (nachalo == false){
            if (!isspace(bukva)){
                nachalo = true;
                if(islower(bukva) or isspace(bukva)){
                    stroka[i] = bukva;
                    i++;
                }
            }
        }
        else{
            if(islower(bukva) or isspace(bukva)){
                stroka[i] = bukva;
                i++;
            }
        }
    } while (bukva != '.');
    stroka[i] = '\0';
    int str_len = i;

    int slov = 0;
    if(islower(stroka[0])){
        slov++;
    }
    for (int i = 0; i < str_len; i++){
        if (isspace(stroka[i]) and !isspace(stroka[i+1])){
            slov++;
        }
    }

    char slova[slov][81];
    int cur = 0;
    int j = 0;
    for (int i = 0; i < str_len; i++) {
        if (!isspace(stroka[i]) and stroka[i] != '\0'){
            slova[cur][j] = stroka[i];
            j++;
        }
        else if (isspace(stroka[i])){
            if (!isspace(stroka[i+1])){
                slova[cur][j] = '\0';
                cur++;
                j = 0;
            }
        }
    }

    int slov_schet[slov];
    for (int i = 0; i < slov; i++) {
        slov_schet[i] = 0;
    }
    for (int i = 0; i < slov; i++) {
        for (int j = 0; j < slov; j++) {
            if (sovp(slova[i], slova[j])) {
                slov_schet[j]++;
            }
        }
    }
    cout << "----------------" << endl;

    for (int i = 0; i < slov; i++) {
        if (slov_schet[i] == 1){
            cout << slova[i] << endl;
        }
    }
    return 0;
}
