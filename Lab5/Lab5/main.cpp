//
//  main.cpp
//  Lab4
//
//  Created by Nikita Akhremchyk on 24.09.21.
//

#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество колонок: ";
    std::cin >> cols;
    std::cout << std::endl;
    
    int **arr = new int* [rows], *b = new int [cols];
    bool flag;
    
    for (int i=0; i<rows; i++)
        arr[i] = new int [cols];
    
     // заполнение массива
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            std::cin >> arr[i][j];
        }
    }
    
    std::cout << "\nМатрица:\n";
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            std::cout << " " << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    for (int i=0; i<cols; i++){
        flag = true;
        for(int j=0; j<rows; j++){
            if (arr[j][i]!=0)
                flag = false;
        }
        if (flag)
            b[i] = 0;
        else
            b[i] = 1;
    }
    
    for (int i=0; i<cols; i++)
        std::cout << b[i] << " ";
    
    std::cout << std::endl;
    
    for (int i=0; i<rows; i++)
        delete [] arr[i];
    
    delete [] arr;
    delete [] b;
    return 0;
}
