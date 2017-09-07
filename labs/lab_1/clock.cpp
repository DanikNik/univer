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


        if(hours % 12== 1){cout << " час ";}
        else if(hours % 12 == 2 || hours % 12 == 3 || hours % 12 == 4){cout << " часа ";}
        else{cout << " часов ";}


        if (minutes == 0){
            if(hours < 6){cout << "ночи ровно" << endl; return 0;}
            else if(hours >= 6 and hours < 12){cout << "утра ровно" << endl; return 0;}
            else if(hours >= 12 and hours < 18){cout << "дня ровно" << endl; return 0;}
            else if(hours >= 18 and hours <= 23){cout << "вечера ровно" << endl; return 0;}
        }
        else{
            cout << minutes;
            int minuta[5] = {1, 21, 31, 41, 51};
            int minuty[15] = {2, 3, 4, 22, 23, 24, 32, 33, 34, 42, 43, 44, 52, 53, 54};
            bool in_minuta = 0;
            bool in_minuty = 0;
            for(int i=0; i<5; i++){
                if(minutes == minuta[i]){
                    in_minuta = 1;
                    break;
                }
            }
            for(int i=0; i<15; i++){
                if(minutes == minuty[i]){
                    in_minuty = 1;
                    break;
                }
            }

            if(in_minuta == 1){
                cout << " минута";
            }
            else if(in_minuty == 1){
                cout << " минуты";
            }
            else{
                cout << " минут";
            }

            if(hours < 6){cout << " ночи" << endl; return 0;}
            else if(hours >= 6 and hours < 12){cout << " утра" << endl; return 0;}
            else if(hours >= 12 and hours < 18){cout << " дня" << endl; return 0;}
            else if(hours >= 18 and hours <= 23){cout << " вечера" << endl; return 0;}
        }
    }
}

int main(){
  int hours, minutes;
  bool is_correct = false;
  while (is_correct == false) {
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    if ((0 <= hours) && (hours <= 23) && (0 <= minutes) && (minutes <= 59)) {
      is_correct = true;
    }
    else{
      cout << "NEPRAVIL'NO BLIN!" << endl;
    }
  }
  print_time(hours, minutes);
  return 0;
}
