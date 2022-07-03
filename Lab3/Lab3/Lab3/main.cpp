//
//  main.cpp
//  Lab3
//
//  Created by Nikita Akhremchyk on 24.09.21.
//

#include <iostream>
#include "math.h"
#include "stdlib.h"


long double factorial(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * factorial(N - 1); // рекурсия.
}

int main() {
    
    double a = 0.1, b = 1.0, sum = 0.0, h=0.1, func_y = 0.0;
    int N = 160;
    
    while(a <= b){
        for (int n=0; n<=N; n++){
            long double _factorial = factorial(2*n+1);
            sum += pow(-1, n)*pow(a, 2*n+1)/_factorial;
        }
        func_y += sin(a);
        
        std::cout << "при a = " << a;
        std::cout << "  при b = " << b;
        std::cout << "  сумма = " << sum;
        std::cout << "  sin = " << func_y << std::endl;
        
        a += h;
    }
    return 0;
}

