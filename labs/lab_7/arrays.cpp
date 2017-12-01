#include <iostream>
using namespace std;
#define N10 10
#define N20 20
#define N40 40


void swap(int* item_arr, int index_1, int index_2){
    int bubble = item_arr[index_1];
    item_arr[index_1] = item_arr[index_2];
    item_arr[index_2] = bubble;
}
void insert(int* item_arr, int index_inserting_at, int index_inserting_from){
    int temp = item_arr[index_inserting_from];
    for (int current = index_inserting_from; current > index_inserting_at; current--)
    {
        item_arr[current] = item_arr[current-1];
    }

    item_arr[index_inserting_at] = temp;
}
int* sort_bubble(int unsorted_arr[], int arr_len, int& b_comp, int& b_swaps) {
    b_comp, b_swaps = 0;
    int *array_for_sorting_bubble = new int [arr_len];

    for (size_t i = 0; i < arr_len; i++) {
        array_for_sorting_bubble[i] = unsorted_arr[i];
    }

    bool flag;
    for (size_t a = 0; a < arr_len; a++) {
        flag = false;
        for (size_t i = 0; i < arr_len-a-1; i++) {
            b_comp += 1;
            if (array_for_sorting_bubble[i] > array_for_sorting_bubble[i+1]){
                b_swaps += 1;
                flag = true;
                swap(array_for_sorting_bubble, i, i+1);
            }
        }
        if (flag == false){break;}
    }

    return array_for_sorting_bubble;
}
int* sort_insert(int unsorted_arr[], int arr_len, int& i_comp, int& i_swaps) {
    i_comp, i_swaps = 0;
    int *array_for_sorting_insert = new int [arr_len];
    for (size_t i = 0; i < arr_len; i++) {
        array_for_sorting_insert[i] = unsorted_arr[i];
    }
    for (size_t i = 0; i < arr_len; i++) {
        for (size_t j = 0; j < i; j++) {
            i_comp+=1;
            if (array_for_sorting_insert[i] < array_for_sorting_insert[j]){
                i_swaps+=1;
                insert(array_for_sorting_insert, j, i);
                break;
            }
        }
    }
    return array_for_sorting_insert;
}
int* sort(int unsorted_arr[], int arr_len) {
    int *array_for_sorting = new int [arr_len];
    for (size_t i = 0; i < arr_len; i++) {
        array_for_sorting[i] = unsorted_arr[i];
    }
    for (size_t i = 0; i < arr_len; i++) {
        for (size_t j = 0; j < i; j++) {
            if (array_for_sorting[i] < array_for_sorting[j]){
                insert(array_for_sorting, j, i);
                break;
            }
        }
    }
    return array_for_sorting;
}
void inline print_array(int *array_for_printing, int arr_size, string state){
    int bubble_swaps = 0;
    int bubble_comp = 0;
    int insert_swaps = 0;
    int insert_comp = 0;

    int *array_bubble_print = sort_bubble(array_for_printing, arr_size, bubble_comp, bubble_swaps);
    int *array_insert_print = sort_insert(array_for_printing, arr_size, insert_comp, insert_swaps);

    cout << "[*] Sample array ["<< arr_size<< "] " << state <<": ";
    for (size_t i = 0; i < arr_size; i++) {
        cout << array_for_printing[i] << ' ';
    }
    cout << endl;

    cout << "\t[+] Bubble ["<< arr_size<< "] " << state <<": ";
    for (size_t i = 0; i < arr_size; i++) {
        cout << array_bubble_print[i] << ' ';
    }
    cout << endl;
    cout << "\t\tb_comps: " << bubble_comp << " b_swaps: " << bubble_swaps << endl;

    cout << "\t[+] Inserts ["<< arr_size<< "] " << state <<": ";
    for (size_t i = 0; i < arr_size; i++) {
        cout << array_insert_print[i] << ' ';
    }
    cout << endl;
    cout << "\t\ti_comps: " << insert_comp << " i_swaps :" << insert_swaps << "\n\n\n";
}

int main(int argc, char const *argv[]) {

    int arr_size = N40;
    int default_array[arr_size];
    for (size_t i = 0; i < arr_size; i++) {
        default_array[i] = rand()%100;
    }

    print_array(default_array, N10, "shuffled");
    print_array(default_array, N20, "shuffled");
    print_array(default_array, N40, "shuffled");

    int *sorted_array = sort(default_array, N40);

    print_array(sorted_array, N10, "pre-sorted");
    print_array(sorted_array, N20, "pre-sorted");
    print_array(sorted_array, N40, "pre-sorted");

    int reversed_array[arr_size];
    for (size_t i = 0; i < arr_size; i++) {
        reversed_array[i] = sorted_array[arr_size - i];
    }

    print_array(reversed_array, N10, "reversed");
    print_array(reversed_array, N20, "reversed");
    print_array(reversed_array, N40, "reversed");

    return 0;
}
