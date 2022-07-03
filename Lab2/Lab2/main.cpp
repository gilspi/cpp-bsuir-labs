//
//  main.cpp
//  Lab2
//
//  Created by Nikita Akhremchyk on 22.09.21.
//

#include <iostream>
#include "math.h"
#include "stdlib.h"

int main(){
    
    setlocale(LC_ALL, "Russian");
    
    double x, y, func, ans;
    int variable;
    
    
    std::cout << "Введите значение x: ";
    std::cin >> x;
    
    std::cout << "Введите значение y: ";
    std::cin >> y;
    
    std::cout << "Выберите функцию: 1 - sinh(x), 2 - pow(x, 2), 3 - exp(x): ";
    std::cin >> variable;
    
    switch(variable){
        case 1:
            func = sinh(x);
            break;
        case 2:
            func = pow(x, 2);
            break;
        case 3:
            func = exp(x);
            break;
        default:
            std::cout << "Вы не выбрали функцию!\n";
            return 1;
    }
    
    if (x * y > 0){
        ans = pow(func + y, 2) - sqrt(fabs(func * y));
    }
    
    else if (x * y < 0) {
        ans = pow(func + y, 2) + sqrt(fabs(func + y));
    }
    
    else {
        ans = pow(func + y, 2) + 1;
    }
    
    std::cout << "Ответ: " << ans << std::endl;
    return 0;
}
