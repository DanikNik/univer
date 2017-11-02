#include <cmath>
#include <iostream>
#include <map>
using namespace std;

string encrypt(string input, string code_bn[], int code_bn_length) {
    long int code_bn_int[code_bn_length];
    long int sigma;
    for (int i = 0; i < code_bn_length; i++){
        sigma = 0;
        for (int j = 0; j < code_bn[i].length(); j++){
            sigma+=(long int)code_bn[i][j];
        }
        code_bn_int[i] = sigma % 256;
    }

    string encrypted_text;
    long int input_int[input.length()];
    for (int i=0; i < input.length(); i++){
        input_int[i] = ((long int)input[i] + code_bn_int[i%code_bn_length]) % 256;
        encrypted_text+=(char)input_int[i];
    }

    return encrypted_text;
}

string decrypt(string input, string code_bn[], int code_bn_length) {
   long int code_bn_int[code_bn_length];
   long int sigma;
   for (int i = 0; i < code_bn_length; i++){
       sigma = 0;
       for (int j = 0; j < code_bn[i].length(); j++){
           sigma+=(long int)code_bn[i][j];
       }
       code_bn_int[i] = sigma % 256;
   }

   string decrypted_text;
   long int input_int[input.length()];
   for (int i=0; i < input.length(); i++){
       input_int[i] = ((long int)input[i] - code_bn_int[i%code_bn_length]) % 256;
       decrypted_text+=(char)input_int[i];
   }

   return decrypted_text;
}

int** calc_freq(string virgin_text, string encoded_text){
    int** freq_table = new int* [256];
    for (size_t i = 0; i < 256; i++) {
        freq_table[i] = new int [256];
    }
    for (size_t i = 0; i < 256; i++) {
        for (size_t j = 0; j < 256; j++) {
            freq_table[i][j] = 0;
        }
    }
    for (size_t i = 0; i < virgin_text.length(); i++) {
        int inSym = (int)virgin_text[i];
        int outSym = (int)encoded_text[i];
        freq_table[inSym][outSym]+=1;
    }

    return freq_table;
}

//bool isIn(int array[], int elem, int size){
//    for (size_t i = 0; i < count; i++) {
        /* code */
//    }
//}


int main(int argc, char const *argv[]) {
    string code_blocknote[] = {"abcde", "fghij", "klmnop", "qrstu", "vwxyz"};
    int key_len = sizeof(code_blocknote)/sizeof(code_blocknote[0]);
    string input_text = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.!!!!!!!!!!!!!!!!!!!!";
    string message = encrypt(input_text, code_blocknote, key_len);
    string decr = decrypt(message, code_blocknote, key_len);
    cout << input_text << endl << endl;
    cout << message << endl << endl;
    cout << decr << endl;
    //int* input_text_set;
    //for (size_t i = 0; i < input_text.length(); i++) {
    //    if
    //}
    int** table = calc_freq(input_text, message);
    for (int i = 0; i < input_text.length(); i++) {
        char symbol = input_text[i];
        cout << symbol<< ":";
        for (int j = 0; j < 256; j++) {
            if (table[(int)symbol][j] != 0){
                cout << "\t" << "x" << table[(int)symbol][j] << " to " << (char)j<< " " << j << endl;
            }
        }
        cout << endl;
    }
    return 0;
}



// СЛУЧАЙНЫЕ СОВПАДЕНИЯ СВЕРТОК В ОТЧЕТ
