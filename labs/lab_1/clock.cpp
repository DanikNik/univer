#include <iostream>
using namespace std;

int print_time(int hours, int minutes){

    if (hours == 12 and minutes == 0){
        cout << "Полдень" << endl;
        return 0;
    }
    else if(hours == 0 and minutes == 0){
        cout << "Полночь" << endl;
        return 0;
    }
    else{
        if(hours <= 12){
            cout << hours;
        }
        else if(hours > 12 && hours <= 23){
            cout << hours % 12;
        }
        cout << " час";
        int un_hours = hours % 12;

        if(un_hours >= 2 and un_hours <= 4){cout << "а";}
        else if(un_hours == 1){cout <<"";}
        else{cout << "ов";}


        if (minutes == 0){
            if(hours < 4){cout << "ночи ровно" << endl; return 0;}
            else if(hours >= 4 and hours < 12){cout << "утра ровно" << endl; return 0;}
            else if(hours >= 12 and hours < 16){cout << "дня ровно" << endl; return 0;}
            else if(hours >= 16 and hours <= 23){cout << "вечера ровно" << endl; return 0;}
        }
        else{
            cout << ' ' << minutes << " минут";
            int un_minutes = minutes % 10;

            if(un_minutes >=1 and un_minutes <=4){
                if(!(minutes >= 11 and minutes <= 14)){
                    if(un_minutes == 1){cout << "а";}
                    else{cout << "ы";}
                }
            }

            if(hours < 4){cout << " ночи" << endl; return 0;}
            else if(hours >= 4 and hours < 12){cout << " утра" << endl; return 0;}
            else if(hours >= 12 and hours < 16){cout << " дня" << endl; return 0;}
            else if(hours >= 16 and hours <= 23){cout << " вечера" << endl; return 0;}
        }
    }
}

int main(){
  int hours, minutes;
  bool hours_correct = 0;
  bool minutes_correct = 0;

  while (hours_correct == 0) {
    cout << "[?] Enter hours: ";
    cin >> hours;
    if(hours >= 0 and hours <= 23){
        hours_correct = 1;
    }
    else{
        cout << "[-] hours incorrect!!!" << endl;
    }
  }

  while (minutes_correct == 0) {
    cout << "[?] Enter minutes: ";
    cin >> minutes;
    if(minutes >= 0 and minutes <= 59){
        minutes_correct = 1;
    }
    else{
        cout << "[-] minutes incorrect!!!" << endl;;
    }
  }


  print_time(hours, minutes);
  return 0;
}
