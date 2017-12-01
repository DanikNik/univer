#include <cmath>
#include <iostream>
#include <map>
using namespace std;

string encrypt(string input, string code_bn[], int code_bn_length) {
    unsigned int code_bn_int[code_bn_length];
    unsigned int sigma;
    for (int i = 0; i < code_bn_length; i++){
        sigma = 0;
        for (int j = 0; j < code_bn[i].length(); j++){
            sigma+=(unsigned int)code_bn[i][j];
        }
        code_bn_int[i] = sigma % 256;
    }

    string encrypted_text;
    unsigned int input_int[input.length()];
    for (int i=0; i < input.length(); i++){
        input_int[i] = ((unsigned int)input[i] + code_bn_int[i%code_bn_length]) % 256;
        encrypted_text+=(char)input_int[i];
    }

    return encrypted_text;
}

string decrypt(string input, string code_bn[], int code_bn_length) {
   unsigned int code_bn_int[code_bn_length];
   unsigned int sigma;
   for (int i = 0; i < code_bn_length; i++){
       sigma = 0;
       for (int j = 0; j < code_bn[i].length(); j++){
           sigma+=(unsigned int)code_bn[i][j];
       }
       code_bn_int[i] = sigma % 256;
   }

   string decrypted_text;
   unsigned int input_int[input.length()];
   for (int i=0; i < input.length(); i++){
       input_int[i] = ((unsigned int)input[i] - code_bn_int[i%code_bn_length]) % 256;
       decrypted_text+=(char)input_int[i];
   }

   return decrypted_text;
}

string make_set(string input_str){
    string str_set = "";
    int len = input_str.length();
    for (size_t i = 0; i < len; i++) {
        int set_len = str_set.length();
        bool isin = false;
        for (size_t j = 0; j < set_len; j++) {
            if (input_str[i] == str_set[j]){
                isin = true;
            }
        }
        if(isin == false){
            str_set += input_str[i];
        }
    }
    return str_set;
}

int** calc_freq(string virgin_text, string encoded_text){
    int** freq_table = new int* [256];
    for (size_t i = 0; i < 256; i++) {
        freq_table[i] = new int [256];
        for (size_t j = 0; j < 256; j++) {
            freq_table[i][j] = 0;
        }
    }

    for (size_t i = 0; i < virgin_text.length(); i++) {
        int inSym = ((int)virgin_text[i] + 256) % 256;
        int outSym = ((int)encoded_text[i]+256) % 256;
        freq_table[inSym][outSym]+=1;
    }

    return freq_table;
}


int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "rus");
    string code_blocknote[] = {"abcde", "fghij", "klmnop", "qrstu", "vwxyz"};
    int key_len = sizeof(code_blocknote)/sizeof(code_blocknote[0]);

    string input_text;
    cout << "[?] Enter text to encode: ";
    getline(cin, input_text);

    string message = encrypt(input_text, code_blocknote, key_len);
    string decr = decrypt(message, code_blocknote, key_len);

    cout << input_text << endl << endl;
    cout << message << endl << endl;
    cout << decr << endl;

    string char_set = make_set(input_text);

    int** table = calc_freq(input_text, message);
    for (int i = 0; i < char_set.length(); i++) {
        int symbol = ((int)char_set[i] + 256) % 256;
        cout << symbol << ":";
        for (int j = 0; j < 256; j++) {
            if (table[symbol][j] != 0){
                cout << "\t" << "x" << table[symbol][j] << " to " << " " << j << endl;
            }
        }
        cout << endl;
    }
    return 0;
}



// СЛУЧАЙНЫЕ СОВПАДЕНИЯ СВЕРТОК В ОТЧЕТ
