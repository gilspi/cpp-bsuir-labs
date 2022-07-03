#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


//const char RU [] = "АБВГДЭЕЖЗЫИКЛМНОПРСТУФХЦЧШЩЬЪЮЯЁ";
//const char ru [] = "aбвгдеёжзыиклмнопрстуфхцчшщьъюяё";
const char EN [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char en [] = "abcdefghijklmnopqrstuvwxyz";
const char num [] = "1234567890"; // добавить символов


void strChecker(char *str, bool success, int i, int length){
    while(success){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> str[i];
        
        if (strchr(num, str[i])){
            printf("Вы ввели символы! Повторите ввод: ");
        }
        else if (!strchr(en, str[i]) && !strchr(EN, str[i])){
            printf("Приветствуется только ввод на латинице! Повторите ввод: ");
        }
        else{
            success = false;
            cout << "Введите значения строки:";
        }
        puts("");
    }
}


void fillStr(char *str, int length){
    cout << "Введите значение исходной строки:\n";
    bool success = true;

    for (int i=0; i<length; i++){
        strChecker(str, success, i, length);
    }
}


void printStr(char *str, int length){
    printf("Ваша строка: ");
    for (int i=0; i<length; i++)
        printf("%c", str[i]);
    puts("");
}


// 1ая - открытие, закрытие и запись
void writeToFile(FILE *f, char const path[], char const text[]){
    f = fopen(path, "w"); // a+ -- дописывает или создает
    
    if (f == NULL) perror("Ошибка открытия файла");
    else{
        for (int i=0; i<strlen(text); i++) fprintf(f, "%c", text[i]);
        fclose(f);
    }
}

// 2ая - открытие, чтение и закрытие
void readFile(FILE *f, const char path[], char *buffer, int length){
    f = fopen(path, "r");
    
    if (f == NULL) perror("Ошибка открытия файла");
    else{
        printf("Информация с файла: ");
        while(!feof(f)){
            if (fgets(buffer, 218, f) != NULL)
                
                printf("%s", buffer);
        }
        fclose(f);
        puts("");
    }
}


// шифрует
void encrypts(char *str, int length){
    int i=0;
    while(i<length){
        bool success = true;
        int j=0;
        while(success){
            if (strchr(EN, str[i])){
                if(str[i] == EN[j]){
                    if (str[i] == 'Z') str[i] = 'A';
                    else str[i] = EN[j+1];
                    success = false;
                }
            }
            else{
                if(str[i] == en[j]){
                    if (str[i] == 'z') str[i] = 'a';
                    else str[i] = en[j+1];
                    success = false;
                }
            }
            j++;
        }
        i++;
    }
}


// расшифровывает
void decryp(char *str, int length){
    int i=0;
    while(i<length){
        bool success = true;
        int j=0;
        while(success){
            if (strchr(EN, str[i])){
                if(str[i] == EN[j]){
                    if (str[i] == 'A') str[i] = 'Z';
                    else str[i] = EN[j-1];
                    success = false;
                }
            }
            else{
                if(str[i] == en[j]){
                    if (str[i] == 'a') str[i] = 'z';
                    else str[i] = en[j-1];
                    success = false;
                }
            }
            j++;
        }
        i++;
    }
}


int main() {
    setlocale(LC_ALL, "Rus");
    
    int length = 10;
    bool success = true;
    
    printf("Введите длину строки: ");
    while(success){
        cin >> length;
        if (!cin.good()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printf("Вы ввели не число! Повторите ввод: ");
        }
        else
            success = false;
        puts("");
    }
    
    char *str = new char[length];
    
    fillStr(str, length);
    printStr(str, length);
    
    
    FILE *f = nullptr;
    char path[] = "/Users/timocruz/Desktop/БГУИР/ОАиП/Lab8/Lab8/Lab8/file.txt";
    
    char *buffer = new char[length];
    writeToFile(f, path, str); // запись в файл
    
    readFile(f, path, buffer, length); // считывание с файла
    
    encrypts(buffer, length);
    printf("Результат шифрования: %s\n", buffer);
    
    decryp(buffer, length);
    printf("Результат расшифровки: %s\n", buffer);
    
    delete [] str;
    return 0;
}
