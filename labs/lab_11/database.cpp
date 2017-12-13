#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
#define min_age 6569
#define max_age 23725
using namespace std;


double get_day(int * date){
    int day = date[0], month = date[1], year = date[2];
    int a = floor((14 - month)/12);
    int y = year + 4800 - a;
    int m = month + 12*a - 3;
    int jdn = day + floor((153 * m + 2)/5) + 365 * y + floor(y / 4) - floor(y / 100) + floor(y / 400) - 32045;
    return jdn;
}

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

bool check_set(competitor * competitors, competitor comp, int len){
    for (size_t i = 0; i < len; i++) {
        if (comp.surname == competitors[i].surname and
            comp.name == competitors[i].name and
            comp.sec_name == competitors[i].sec_name and
            comp.birth_date == competitors[i].birth_date and
            comp.sex == competitors[i].sex){
                cout << "[!] This competitor is already in database!!!\n";
                return true;
            }
    }
    return false;
}

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
    int febr = 28;
    if (date[2] > 0){
        if (date[1] > 0 and date[1] <= 12) {
            if (date[2] % 4 == 0){febr = 29;}
            switch (date[1]){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if (date[0] > 0 and date[0] <= 31){
                        return true;
                    }
                    break;
                case 2:
                    if (date[0] > 0 and date[0] <= febr) {
                        return true;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (date[0] > 0 and date[0] <= 30) {
                        return true;
                    }
                    break;
            }
        }
    }
    cout << "[-] date incorrect !!!\n";
    return false;
}

competitor * get_competitors(int comp_quantity, int * comp_date){
    competitor * competitors = new competitor [comp_quantity];
    for (size_t i = 0; i < comp_quantity; i++) {
        cout << "--------COMPETITOR " << i << "--------\n";
        do {
            cout << "Name: ";
            cin >> competitors[i].name;
            cout << "Surname: ";
            cin >> competitors[i].surname;
            cout << "Second name: ";
            cin >> competitors[i].sec_name;
            do{
                cout << "Birth date: ";
                competitors[i].birth_date_arr = get_date();
            }while (get_day(comp_date) - get_day(competitors[i].birth_date_arr) < min_age);
            competitors[i].birth_date = to_string(competitors[i].birth_date_arr[0]);
            for (size_t q = 1; q < 3; q++) {
                competitors[i].birth_date += ".";
                competitors[i].birth_date += to_string(competitors[i].birth_date_arr[q]);
            }
            cout << "Sex: ";
            cin >> competitors[i].sex;
        } while (check_set(competitors, competitors[i], i) == true);
        cout << "Results: ";
        competitors[i].sum = 0;
        for (size_t j = 0; j < 4; j++) {
            cin >> competitors[i].results[j];
            competitors[i].sum += competitors[i].results[j];
        }
    }
    return competitors;
}

void fill_db(string filename, competitor * competitors, int * date, int comp_quantity){
    string competitions[5] = {"comp1", "comp2", "comp3", "comp4_m", "comp4_f"};
    ofstream fout;
    fout.open(filename);
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
}

int main() {
    setlocale(LC_ALL, "rus");

    int * date;
    do{
        cout << "[>] Enter competition date: ";
        date = get_date();
    }while (is_date_correct(date) == false);

    int comp_quantity;
    do{
        cout << "[>] Enter competitors quantity: ";
        cin >> comp_quantity;
    }while(comp_quantity <= 0);

    competitor * competitors = get_competitors(comp_quantity, date);

    fill_db("comp_database", competitors, date, comp_quantity);

    return 0;
}
