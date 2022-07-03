#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


const char EN [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char en [] = "abcdefghijklmnopqrstuvwxyz";
const char num [] = "1234567890"; // добавить символов


struct Group{
    int group_num;
};


struct Student{
    char fa[32]; // фамилия
    char im[32]; // имя
    char ot[32]; // отчество
    char address[32]; // адрес
    int mark; // оценка студента
    Group group; // дата учета
};

// Функция сортировки прямым выбором
void selectionSort(Student *student, int size){
    int m;
    Student r;
    for (int i = 0; i < size-1; i++){
        m = i;
        for (int j = i + 1; j < size; j++)
            if (student[j].group.group_num < student[m].group.group_num) m = j;
        r = student[m];
        student[m] = student[i];
        student[i] = r;
    }
}

// Функция сортировки QuickSort
void quickSort(Student *&student, int size){
    int i=0, j=size-1, x;
    Student r;
    int L=0; int R=size;
    x = student[(L+R)/2].group.group_num;
    while (i <= j) {
        while (student[i].group.group_num<x) i++;
        while (student[j].group.group_num>x) j--;
        if (i <= j){
            r = student[i];
            student[i] = student[j];
            student[j] = r;
            i++;
            j--;
        }
    }
}

// бинарный поиск в отсортированном массиве
int binSearch(const Student *student, int amount, Group key){
    int L=0; int R=amount-1;
    while(L<=R){
        int m = (L+R)/2;
        if (student[m].group.group_num==key.group_num) return m;
        if (student[m].group.group_num<key.group_num) L=m+1;
        if (student[m].group.group_num>key.group_num) R=m-1;
    }
    return -1;
}

// бинарный поиск в отсортированном массиве
int binSearch(const Student *student, int amount, char *fa, char *im, char *ot, int group){ // возвращает идекс искомого человека
    int L=0; int R=amount-1;
    while(L<=R){
        int m = (L+R)/2;
        if(student[m].group.group_num == group){
            if(strcmp(student[m].fa, fa)==0){
                if(strcmp(student[m].ot, ot)==0){
                    if(strcmp(student[m].im, im)==0) return m;
                    else printf("Ошибка! Такого имени нет!");
                }
                else printf("Ошибка! Такого отчества нет!");
            }
            else printf("Ошибка! Такой фамилии нет!");
        }
        else printf("Ошибка! Такой группы нет!");
        if (student[m].group.group_num<group) L=m+1;
        if (student[m].group.group_num>group) R=m-1;
    }
    return -1;
}

// линейный поиск
int linSearch(Student *student, int size, int group){
    for (int i=0; i<size; i++){
        if (student[i].group.group_num == group) return i;
    }
    return -1;
}


void push_back(Student *&student, int &size, int count=1){
    Student *newArr = new Student[size+count];
    
    for(int i=0; i<size; i++) newArr[i] = student[i];
    
    puts("");
    for(int i=0; i<count; i++){
        printf("Фамилия: "); cin >> newArr[size].fa;
        printf("Имя: "); cin >> newArr[size].im;
        printf("Отчество: "); cin >> newArr[size].ot;
        printf("Адрес: "); cin >> newArr[size].address;
        printf("Оценка: "); cin >> newArr[size].mark;
        
        
        printf("Номер группы: ");
        cin >> newArr[size].group.group_num;
        
        puts("");
    }
    
    size += count;
    
    delete [] student;
    
    student = newArr;
}


void push_back(Student *&student, Student st, int &size, int count=1){
    Student *newArr = new Student[size+count];
    
    for(int i=0; i<size; i++) newArr[i] = student[i];
    
    puts("");
    for(int i=0; i<count; i++){
        newArr[i] = st;
        
        cin.get(); // считывает из потока Enter который пользователь нажимает после ввода даты
        puts("");
    }
    
    size += count;
    
    delete [] student;
    
    student = newArr;
}


void pop(Student *student, int &size, int pos){
    for(int i=pos-1; i<size-1; i++) student[i] = student[i+1];
    size--;
}


Student* deleteElem(Student *student, int &length, int var){
    int count = 0;
    for(int i=0; i<length; i++)
        if(i == var){
            Student tmp = student[count];
            student[count] = student[i]; //удаляемые элементы переместим в начало массива
            student[i] = tmp;
            count++; //посчитает количество повторений удаляемого элемента
        }
    
    length = length - count; //определим длину нового массива
    Student *result = new Student[length];
    for(int i=0; i<length; i++)
        result[i] = student[i+count];
    
    return result;
}


void strChecker(char *str, int length){
    bool success=true;
    int i=0;
    
    while(success){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cin >> str;
         while(i<strlen(str)){
            if (strchr(num, str[i])){
                printf("Вы ввели символы! Повторите ввод: ");
                break;
            }
            else if (!strchr(en, str[i]) && !strchr(EN, str[i])){
                printf("Приветствуется только ввод на латинице! Повторите ввод: ");
                break;
            }
            else{
                success = false;
                cout << "Введите значения строки: ";
                
            }
            i++;
        }
    }
    puts("");
}


void print(Student *Obj, int amount){
    cout << "№\t\t" << "Фамилия\t\t\t" << "Имя\t\t\t" << "Отчество\t\t" << "Адрес\t\t" << "Оценка\t\t" << "Номер группы\t\t" << endl;
    cout << "==============================================================================================" << endl;
    for (int i=0; i<amount; i++){
        cout << i + 1 << "\t\t" << Obj[i].fa << "\t\t" << Obj[i].im
            << "\t\t" << Obj[i].ot << "\t\t" << Obj[i].address << "\t"
            << Obj[i].mark << "\t\t" << Obj[i].group.group_num << "\t\t" << endl;
    }
    puts("");
}


int save(char const *filename, struct Student *student, int n){
    FILE *fp=nullptr;
    char *c=nullptr;
 
    // число записываемых байтов
    int size=n*sizeof(Student);
     
    if ((fp=fopen(filename, "wb"))==NULL){
        perror("Ошибка открытия файла!");
        return 1;
    }
    // записываем количество структур
    c = (char*)&n;
    for (int i=0; i<sizeof(int); i++){
        putc(*c++, fp);
    }
 
    // посимвольно записываем в файл все структуры
    c = (char*)student;
    for (int i=0; i<size; i++){
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}

// загрузка из файла массива структур
int load(char const *filename){
    FILE *fp=nullptr;
    char *c=nullptr;
    int m=sizeof(int);
    int n, i;
 
    // выделяем блок память размером sizeof(int) для количества данных
    int *pti = (int*)malloc(m); // возвращает указатель на начало блока
 
    if ((fp=fopen(filename, "r"))==NULL){
        perror("Ошибка открытия файла!");
        return 1;
    }
    // считываем количество структур
    c = (char*)pti;
    while (m>0){
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;
 
    // выделяем память для считанного массива структур
    Student *student = (Student*)malloc(n*sizeof(Student));
    c = (char*)student;
    // после записи считываем посимвольно из файла
    while ((i=getc(fp))!=EOF){
        *c = i;
        c++;
    }
    // перебор загруженных элементов и вывод на консоль
    printf("\n%d количество лиц\n\n", n);
    
    cout << "№\t\t" << "Фамилия\t\t\t" << "Имя\t\t\t" << "Отчество\t\t" << "Адрес\t\t" << "Оценка\t\t" << "Номер группы\t\t" << endl;
    cout << "==============================================================================================" << endl;
    for (int k=0; k<n; k++){
        cout << k + 1 << "\t\t" << (student+k)->fa << "\t\t" << (student+k)->im
            << "\t\t" << (student+k)->ot << "\t\t" << (student+k)->address << "\t"
            << (student+k)->mark << "\t\t" << (student+k)->group.group_num << "\t\t" << endl;
    }
 
    free(pti);
    free(student);
    fclose(fp);
    return 0;
}


void print(int len, int var){
    while(len){
        if(var==0) cout << MAGENTA << "*" << RESET;
        else if(var==1) cout << BLUE << "*" << RESET;
        else if(var==2) cout << RED << "*" << RESET;
        else if(var==3) cout << YELLOW << "*" << RESET;
        len--;
    }
    return;
}


bool checkGroup(int group){
    bool flag=false;
    if(group > 0 && group < 5) return true;
    else printf("Номер группы не может быть отрицательным! Повторите ввод: ");
    
    return flag;
}


int main() {
    setlocale(LC_ALL, "Rus");
    
    char const *mainlist= "/Users/timocruz/Desktop/БГУИР/ОАиП/результирующее/результирующее/main.txt"; // главный файл
    char const *deltelist= "/Users/timocruz/Desktop/БГУИР/ОАиП/результирующее/результирующее/delete.txt"; // список отчисленных
    
    int amount=0, delamount=0; // количество лиц
    Student *delstudents = new Student[delamount];
    Student *students = new Student[amount];
    int var;
    bool variable=false;
    int temp=0;
    
    do{
        if(temp==0){
            printf("1 - добавление\n0 - выход\nВведите значение: ");
            cin >> var;
            puts("");
        }
        else{
            printf("1 - создание нового списка\n2 - сортировка быстрым\n3 - сортировка выборкой\n4 - бинарный поиск\n5 - добавление элемента в список\n6 - удаление определенного элемента(отчисление)\n7 - удаление определенного элемента(восстановление)\n8 - редактирование данных о студенте\n9 - график успеваемости групп\n0 - выход\nВведите значение: ");
            cin >> var;
            puts("");
        }
        
        switch(var){
            case 1:{ // создание нового списка
                printf("Введите количество студентов поступивших в этом году: ");
                
                bool success = true;
                while(success){
                    cin >> amount;
                    if (!cin.good()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        printf("Вы ввели не число! Повторите ввод: ");
                    }
                    else if(cin.good() && amount<0){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        printf("Длина списка не может быть отрицательной или равным нулю! Повторите ввод: ");
                    }
                    else
                        success = false;
                    puts("");
                }
                
                for(int i=0; i<amount; i++){
                    printf("Фамилия: "); cin >> students[i].fa;
                    printf("Имя: "); cin >> students[i].im;
                    printf("Отчество: "); cin >> students[i].ot;
                    printf("Адрес: "); cin >> students[i].address;
                    printf("Оценка: "); cin >> students[i].mark; // сделать проверку оценки на легитимность 0<=m<=10
                    
                    bool flag=false;
                    while(!flag){
                        printf("Номер группы: ");
                        cin >> students[i].group.group_num;
                        flag=checkGroup(students[i].group.group_num);
                    }
                    
                    cin.get(); // считывает из потока Enter который пользователь нажимает после ввода даты
                    cout << endl;
                }
                
                
                save(mainlist, students, amount);
                load(mainlist);
                
                puts("");
                break;
            }
                
            case 2:{ // сортировка быстрым методом
                quickSort(students, amount);
                print(students, amount);
                break;
            }
                
            case 3:{ // сортировка выборкой
                selectionSort(students, amount);
                print(students, amount);
                break;
            }

            case 4:{ // бинарный поиск
                quickSort(students, amount);
                
                Group group;
                printf("Введите номер группы для поиска: ");
                cin >> group.group_num;
                
                int t;
                t = binSearch(students, amount, group);
                
                if(t!=-1) printf("\nИндекс искомой группы: %d\n", t);
                else printf("Такая группа отсутствует в списке");
                break;
            }
                
            case 5:{ // добавление элемента в список
                push_back(students, amount);
                
                save(mainlist, students, amount);
                load(mainlist);
                break;
            }
                
            case 6:{ // удаление элементов
                int group;
                printf("Введите номер группы для поиска: ");
                cin >> group;
                
                // поиск нужного человека по фамилии
                char *fa = new char[32];
                char *ot = new char[32];
                char *im = new char[32];
               
                printf("Введите фамилию искомого человека: "); cin >> fa;
                printf("Введите отчество искомого человека: "); cin >> ot;
                printf("Имя искомого человека: "); cin >> im;
                
                quickSort(students, amount);
                int gindex = binSearch(students, amount, fa, im, ot, group); // идекс нужной группы
                
                if(gindex != -1){
                    push_back(delstudents, students[gindex], delamount); // добавление удаляемого элемента
                    save(deltelist, delstudents, delamount);
                    load(deltelist);
                    print(delstudents, delamount);
                    
                    students = deleteElem(students, amount, gindex); // удаление из основного файла
                    save(mainlist, students, amount);
                    load(mainlist);
                    puts("");
                }
                else printf("Ученик не найден!\n");
                
                delete [] fa;
                delete [] im;
                delete [] ot;
                break;
            }
            
            case 7:{ // добавление в main.txt from delete.txt
                int group;
                printf("Введите номер группы для поиска: ");
                cin >> group;
                
                // поиск нужного человека по фамилии
                char *fa = new char[32];
                char *ot = new char[32];
                char *im = new char[32];
               
                printf("Введите фамилию искомого человека: "); cin >> fa;
                printf("Введите отчество искомого человека: "); cin >> ot;
                printf("Имя искомого человека: "); cin >> im;
                
                quickSort(students, amount);
                int gindex = binSearch(delstudents, delamount, fa, im, ot, group); // идекс нужной группы
                
                if(gindex != -1){
                    push_back(students, delstudents[gindex], delamount); // добавление удаляемого элемента
                    save(mainlist, students, amount);
                    load(mainlist);
                    print(students, amount);
                    
                    students = deleteElem(delstudents, delamount, gindex); // удаление из основного файла
                    save(deltelist, delstudents, delamount);
                    load(deltelist);
                    puts("");
                }
                else printf("Ученик не найден!\n");
                
                delete [] fa;
                delete [] im;
                delete [] ot;
                break;
            }
             
            case 8:{ // редактирование данных о студенте
                int group;
                printf("Введите номер группы для поиска: ");
                cin >> group;
                
                // поиск нужного человека по фамилии
                char *fa = new char[32];
                char *ot = new char[32];
                char *im = new char[32];
               
                printf("Введите фамилию искомого человека: "); cin >> fa;
                printf("Введите отчество искомого человека: "); cin >> ot;
                printf("Имя искомого человека: "); cin >> im;
                
                quickSort(students, amount);
                int gindex = binSearch(students, amount, fa, im, ot, group); // идекс нужной группы
                puts("");
                printf("Введите новые данные: ");
                puts("");
                
                if(gindex != -1){
                    int t_group=0;
                    char *t_fa= new char[32];
                    char *t_ot = new char[32];
                    char *t_im = new char[32];
                    char *t_address = new char[32];
                    int t_mark=0;
                    
                    printf("Фамилия: "); cin >> t_fa;
                    cout << t_fa<<endl;
                    printf("Имя: "); cin >> t_im;
                    cout << t_im<<endl;
                    printf("Отчество: "); cin >> t_ot;
                    cout << t_ot<<endl;
                    printf("Адрес: "); cin >> t_address;
                    cout << t_address<<endl;
                    printf("Оценка: "); cin >> t_mark; // сделать проверку оценки на легитимность 0<=m<=10
                    cout << t_mark<<endl;
                    
                    bool flag=false;
                    while(!flag){
                        printf("Номер группы: ");
                        cin >> t_group;
                        flag=checkGroup(t_group);
                    }
                    
                    strcpy(students[gindex].fa, t_fa);
                    strcpy(students[gindex].ot, t_ot);
                    strcpy(students[gindex].im, t_im);
                    strcpy(students[gindex].address, t_address);
                    students[gindex].group.group_num = t_group;
                    students[gindex].mark = t_mark;
                    
                    save(mainlist, students, amount);
                    load(mainlist);
                    print(students, amount);
                    
                    delete[] t_fa;
                    delete [] t_im;
                    delete [] t_ot;
                    delete[] t_address;
                }
                else printf("Ученик не найден!\n");
                
                
                delete [] fa;
                delete [] im;
                delete [] ot;
                break;
            }
                
            case 9:{ // график успеваемости
                quickSort(students, amount);
                
                int t=0;
                int *st = new int[t];
                int *marks = new int[t];
                
                for(int i=0; i<amount; i++){
                    if(students[i].group.group_num == 1){
                        marks[0] += students[i].mark;
                        st[0] += 1;
                    }
                    else if(students[i].group.group_num == 2){
                        marks[1] += students[i].mark;
                        st[1] += 1;
                    }
                    else if(students[i].group.group_num == 3){
                        marks[2] += students[i].mark;
                        st[2] += 1;
                    }
                    else if(students[i].group.group_num == 4){
                        marks[3] += students[i].mark;
                        st[3] += 1;
                    }
                }
                
                printf("График среднего балла групп:\n");
                for(int i=0; i<4; i++){
                    if(i==0){
                        printf("1ая группа: ");
                        print(marks[0]*10, 0);
                        puts("");
                    }
                    else if(i == 1){
                        printf("2ая группа: ");
                        print(marks[1]*10, 1);
                        puts("");
                    }
                    else if(i == 2){
                        printf("3ая группа: ");
                        print(marks[2]*10, 2);
                        puts("");
                    }
                    else if(i == 3){
                        printf("4ая группа: ");
                        print(marks[3]*10, 3);
                        puts("");
                    }
                }
                puts("");
                delete [] st;
                delete [] marks;
                break;
            }
                
            case 0:{ // выход из цикла
                variable = true;
                break;
            }
        }
        
        
        temp+=1;
    }while(!variable);
    
    delete [] students;
    delete [] delstudents;
    return 0;
}
