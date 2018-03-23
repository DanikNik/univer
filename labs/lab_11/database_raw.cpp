#include "lib.h"
//using namespace std;


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
    sort(competitors, comp_quantity);

    fill_db("comp_database", competitors, date, comp_quantity);


    cout << "\n\n\n";
    ifstream file("comp_database");
    string str;
    while(getline(file, str)){
        cout << str << '\n';
    }

    return 0;
}
