#include <iostream>

int main(int argc, const char * argv[]) {
    
    setlocale(LC_ALL, "Russian");
    
    int k, counter=0;
    std::cout << "Введите значение длину массива: "; std::cin >> k;
    
    char* arr = new char [k] {};
    char* brr = new char [k] {};
    
    std::cout << "Ваш массив символов: ";
    for (int i=0; i<k; i++)
        std::cin >> arr[i];
    
    for (int i=0; i<k; i++){
        if (isdigit(arr[i])){
            brr[counter] = arr[i];
            counter ++;
        }
    }

    for (int i=0; i<k; i++){
        if (isalpha(arr[i])){
            brr[counter] = arr[i];
            counter ++;
        }
    }
    
    std::cout << "После преобразований: ";
    for (int i=0; i<k; i++)
        std::cout << brr[i];
    
    std::cout << std::endl;
    
    delete [] arr;
    delete [] brr;

    return 0;
}
