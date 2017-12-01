#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct competitor{
    string surname; //фамилия
    string name;    //имя
    string sec_name;//отчество
    string birth_date;
    int * birth_date_arr; //дата рождения - выделить память int [3]
    string sex; //male, female;
    int results[4]; //результаты по каждому из 4 соревнований
    int sum; // суммарный результат

};

int * get_date(){
    string compet_date;
    string delimiter = ".";
    int * date = new int [3];
    cin >> compet_date;


    size_t pos = 0;
    string current_date_part;
    int current = 0;
    while ((pos = compet_date.find(delimiter)) != string::npos) {
        current_date_part = compet_date.substr(0, pos);
        date[current] = stoi(current_date_part);
        current++;
        compet_date.erase(0, pos + delimiter.length());
    }
    date[current] = stoi(compet_date);

    return date;
}

bool is_date_correct(int * date){
    if (date[3] > 0)
}
int main() {
    setlocale(LC_ALL, "rus");
    string competitions[5] = {"comp1", "comp2", "comp3", "comp4_m", "comp4_f"};

    cout << "[>] Enter competition date: ";
    int * date = get_date();

    cout << "[>] Enter competitors quantity: ";
    int comp_quantity;
    cin >> comp_quantity;

    competitor competitors[comp_quantity];
    for (size_t i = 0; i < comp_quantity; i++) {
        cout << "--------COMPETITOR " << i << "--------\n";
        cout << "Name: ";
        cin >> competitors[i].name;
        cout << "Surname: ";
        cin >> competitors[i].surname;
        cout << "Second name: ";
        cin >> competitors[i].sec_name;
        cout << "Birth date: ";
        competitors[i].birth_date_arr = get_date();
        competitors[i].birth_date = to_string(competitors[i].birth_date_arr[0]);
        for (size_t q = 1; q < 3; q++) {
            competitors[i].birth_date += ".";
            competitors[i].birth_date += to_string(competitors[i].birth_date_arr[q]);
        }
        cout << "Sex: ";
        cin >> competitors[i].sex;
        cout << "Results: ";
        competitors[i].sum = 0;
        for (size_t j = 0; j < 4; j++) {
            cin >> competitors[i].results[j];
            competitors[i].sum += competitors[i].results[j];
        }
    }


    ofstream fout;
    fout.open("database.db");
    fout << "Competitions date: " << date[0] << '.' << date[1] <<'.'<<date[2]<<'\n';
    for (size_t i = 0; i < comp_quantity; i++) {
        fout << "--------COMPETITOR " << i << "--------\n";
        fout << "Name: " << competitors[i].name << '\n';
        fout << "Surname: " << competitors[i].surname << '\n';
        fout << "Second name: " << competitors[i].sec_name << '\n';
        fout << "Birth date: " << competitors[i].birth_date << '\n';
        fout << "Sex: " << competitors[i].sex << '\n';
        fout << "Results:\n";
        for (size_t j = 0; j < 4; j++) {
            if (j == 3){
                if (competitors[i].sex == "male") fout << '\t' <<competitions[j] << "\t" << competitors[i].results[j] << '\n';
                else fout << '\t' <<competitions[j+1] << '\t' << competitors[i].results[j] << '\n';
            }
            else fout << '\t' <<competitions[j] << '\t' << competitors[i].results[j] << '\n';
        }
        fout << "Sum: " << competitors[i].sum << "\n--------COMPETITOR " << i << "--------\n";
    }
    fout.close();
    return 0;
}
