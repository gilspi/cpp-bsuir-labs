#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;


string def (int num, int const p){
    string res0 = "", res = "";
    
    if (p>1 && p<10){
        do{
            res0 = to_string(num%p) + res0;
            num/=p;
        }
        while (num>0);
        res += res0;
    }
    
    else if (p==1){
        for (int i=0; i < num; i++) res0 += "0";
        res += res0;
    }
    else res = "Основание системы счисления p должно быть больше 0 и меньше 10";


    return res;
}

string recursive(int n, int const p){
    if (n == 0) return "";
    return recursive(n/p, p) + to_string(n%p);
}


int intChecker(bool success, string arg="no"){
    int num=0;
    while(success){
        cin >> num;
        if (!cin.good()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Вы ввели не число! Повторите ввод: ");
        }
        else if ((num > 10 || num < 0) && arg == "yes"){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Вы ввели неверные данные! Повторите ввод: ");
        }
        else
            success = false;
        puts("");
    }
    return num;
}


int main(int argc, const char * argv[]) {
    int num, p;
    
    bool success = true;
    
    string v;
    bool flag=false;
    while(!flag){
        printf("Введите число: ");
        num = intChecker(success);
        printf("Введите систему счисления: ");
        p = intChecker(success, "yes");
        printf("n=%i\np=%i\n\n", num, p);
        
        printf("ВЫБЕРИТЕ РЕЖИМ\n1 - РЕКУРСИВНЫЙ МЕТОД\n2 - ЛИНЕЙНЫЙ МЕТОД\nВведите значение: ");
        int n;
        cin >> n;
        switch(n){
            case 1:{
                v = recursive(num, p);
                
                printf("\nЧисло n=%i в системе счисления p=%i равно ", n, p);
                printf("%s\n", &v);
                break;
            }
            case 2:{
                v = def(num, p);
                
                printf("\nЧисло n=%i в системе счисления p=%i равно ", n, p);
                printf("%s\n", &v);
                break;
            }
                
            case 0:{
                flag = true;
            }
        }
    }
    return 0;
}
