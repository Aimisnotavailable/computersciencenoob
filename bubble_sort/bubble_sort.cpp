#include <iostream>
#include <windows.h>

void bubble_sort(int arr[], int size);

void print_arr(int arr[], int size, int current_layer, int current, int next);

void print_move(int arr[], int current, int next, bool is_swapped);

void print_sorted(int arr[], int current);

void bubble_sort(int arr[], int size){
    
    for(int i = 0; i < size - 1; i++){
        bool swapped = false;
        for(int j = 0; j < size - 1; j++){
            system("cls");
            print_sorted(arr, size);
            print_arr(arr, size, j / 10, j, j+1);
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
            Sleep(200);
            print_move(arr, j+1, j, swapped);
            Sleep(300);
        }
        if(swapped == false)
            break;
    }

}

void print_arr(int arr[], int size, int current_layer, int current, int next){
    for(int i = current_layer * 10; i < ((current_layer + 1) * 10) + 1; i++){
        if(i < size){
            if(i == current || i == next ){
                std::cout << "| " << arr[i] << " |";
                continue;
            }
            std::cout << arr[i] << " " ;
        }
    }
}

void print_sorted(int arr[], int size){
    system("cls");
    std::cout << "Current Sorted Array using bubble sort: ";
    for(int i = 0; i < size ; i++){
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}

void print_move(int arr[], int current, int next, bool is_swapped){
    std::cout << std::endl << arr[current] << " > " << arr[next] << " ?"<< std::endl;
    std::cout << "Status: " << (is_swapped ? "Swapped" : "Not Swapped");
}

int main(){
    int arr[] = {98, 99, 20, 77, 41, 13, 62, 39, 87, 28};
    bubble_sort(arr,  10);
    print_sorted(arr, 10);
}
