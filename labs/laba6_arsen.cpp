#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//кодовый блокнот и определение ключевой длины
	string  blocknote[] = { "это", "мой", "кодовый", "болкнот", "всем", "сосать" };
	int keylen = sizeof(blocknote) / sizeof(blocknote[0]);
	cout << keylen << "\n\n";

	//заполняю заготовку для хранения численных сверток кодового блокнота нулями
	unsigned int note[keylen];
	for (int i = 0; i < keylen; i++) {
		note[i] = 0;
	}

	//заполняю свертку блокнота нужными значениями
	int c, word_len = 0;
	for (int i = 0; i < keylen; i++)
	{
		word_len = blocknote[i].length();
		for (int j = 0; j < word_len; j++)
		{
			c = (int)blocknote[i][j];
			note[i] += c;
		}
		note[i] %= 256;

	}

	//получаем исходный текст и сразу же определяем ее длину
	cout << "Vvedite frazu:   ";
	string inctext;
	getline(cin, inctext);
	int len = inctext.length();

	//здесь будем хранить наши экскременты от процесса шифровки и дешифровки
	string coded[2]; //elem 0 - coded[0], elem 1 - decoded

	cout << "Zakodirovannaya fraza:";
	for (int i = 0; i < len; i++)
	{
		coded[0] += (inctext[i] + note[(i % keylen)]) % 256;
		cout << coded[0][i];
	}

	cout << endl << "Ishodnaya fraza:  ";
	for (int i = 0; i < len; i++)
	{
		coded[1] += coded[0][i] - note[(i % keylen)];
		cout << coded[1][i];
	}
	cout << endl;

	//создадим сет из букв которые встречаются в нашей исходной строке
	string myset = "";
    int text_len = inctext.length();
    for (int i = 0; i < len; i++) {
        int set_len = myset.length();
        bool is_in_text = false;
        for (int j = 0; j < set_len; j++) {
            if (inctext[i] == myset[j]){
                is_in_text = true;
            }
        }
        if(is_in_text == false){
            myset += inctext[i];
        }
    }

	//вот тут мы сделаем подсчет статистики
	int statistics[256][256];
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			statistics[i][j] = 0;
		}
	}
	for (int i = 0; i < inctext.length(); i++)
	{
		statistics[((int)inctext[i] + 256) % 256][((int)coded[0][i] + 256) % 256] += 1;
	}


	//а вот тут выведем все это дело
	for (int i = 0; i < myset.length(); i++) {
        int symbol = ((int)myset[i] + 256) % 256;
        cout <<"Simvol s kodom " << symbol << " zakodirovan v:";
        for (int j = 0; j < 256; j++) {
            if (statistics[symbol][j] != 0){
                cout << "\n\tsimvol s kodom " << j << ' ' << statistics[symbol][j] << " raz(a)"<< endl;
            }
        }
        cout << endl;
    }
	//system("pause");
	return 0;
}
