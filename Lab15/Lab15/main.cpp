#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define eps 1e-3


double const A=-2;
double const B=3;


typedef double (*pointFunc)(double);


double f(double x){
    return 4*x-7*sin(x);
}


double M_middleRectangle(pointFunc F, int n){
    double Res=0;
    double h=(B-A)/n;
    for(double x=A+h/2; x<=B; x+=h) Res+=(*F)(x);
    return Res*h;
}
 

int main(){
    int n, i, k;;
    double delta = 5.0, I1, I2, h, g, integral;
    
    bool flag=false;
    while(!flag){
        printf("Введите количество точек разбиения: ");
        scanf("%d",&n);
        
        int var;
        printf("1-считаем\n2-считаем с точностью\n3-выход\nзначение: ");
        scanf("%d", &var);
        
        switch(var){
            case 1:{
                std::cout << M_middleRectangle(f, n) << std::endl;
                break;
            }
                
            case 2:{
                while(fabs(delta) > eps){
                    I1 = 0;
                    I2 = 0;
                    h = (B - A)/n;
                    for(i = 1; i <= n; i++)
                        I1 += h*f(A + h*(i - 0.5));
                        
                    g = (B - A)/(2*n);
                    for(k = 1; k <= 2*n; k++)
                        I2 += g*f(A + g*(k - 0.5));
                    
                    delta = I2 - I1;
                    n *= 2;
                    
                    integral = I2;
                }
                std::cout << integral << std::endl;
                break;
            }
                
            case 3:{
                flag=true;
                break;
            }
        }
    }
    
    return 0;
}
