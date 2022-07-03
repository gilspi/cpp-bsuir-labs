#include <iostream>

#define STR_LENGHT 255 // Максимальная длина строки

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    char str[STR_LENGHT];
    int counter=0, count=0;
    
    std::cout << "Введите строку: ";
    std::cin.getline(str, STR_LENGHT, '\n');
    
    std::cout << "Ваша строка: " << str << std::endl;
    
    int len = strlen(str);
    
    for (int i = 0; i < len+1; i++){
        if (!(str[i]==' ') && !(str[i]=='\0'))
            counter ++;
        else
        {
            if (counter==5)
                count ++;
            counter = 0;
        }
    }
    
    std::cout << "Количество групп с 5ью символами: " << count << std::endl;
    return 0;
}
