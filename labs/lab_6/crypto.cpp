#include <cmath>
#include <iostream>
using namespace std;

 string encrypt(string input, string code_bn[], int code_bn_length) {
    int k = 0;

    int code_bn_int[code_bn_length];
    int sigma;
    for (int i = 0; i < code_bn_length; i++){
        sigma = 0;
        for (int j = 0; j < code_bn[i].length(); j++){
            sigma+=(int)code_bn[i][j];
        }
        code_bn_int[i] = sigma % 256;
    }

    string encrypted_text;
    int input_int[input.length()];
    for (int i=0; i < input.length(); i++){
        input_int[i] = ((int)input[i] + code_bn_int[i%code_bn_length]) % 256;
        encrypted_text+=(char)input_int[i];
    }

    return encrypted_text;
}

string decrypt(string input, string code_bn[], int code_bn_length) {
   int k = 0;

   int code_bn_int[code_bn_length];
   int sigma;
   for (int i = 0; i < code_bn_length; i++){
       sigma = 0;
       for (int j = 0; j < code_bn[i].length(); j++){
           sigma+=(int)code_bn[i][j];
       }
       code_bn_int[i] = sigma % 256;
   }

   string decrypted_text;
   int input_int[input.length()];
   for (int i=0; i < input.length(); i++){
       input_int[i] = ((int)input[i] - code_bn_int[i%code_bn_length]) % 256;
       decrypted_text+=(char)input_int[i];
   }

   return decrypted_text;
}

int main(int argc, char const *argv[]) {
    string code_blocknote[] = {"Pater ", "noster ", "qui ", "in ", "celis ", "es, ", "sanctificetur ", "nomen ", "tuum, ", "veniat ", "regnum ", "tuum, ", "fiat ", "voluntas ", "tua"};
    int key_len = sizeof(code_blocknote)/sizeof(code_blocknote[0]);
    string input_text = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    string message = encrypt(input_text, code_blocknote, key_len);
    string decr = decrypt(message, code_blocknote, key_len);
    cout << input_text << endl << endl;
    cout << message << endl << endl;
    cout << decr << endl;
    return 0;
}
