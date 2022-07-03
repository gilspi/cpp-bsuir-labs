#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>




struct spisk {
    spisk* prev, * next;
    int data;
} *begin, *begin2, *end, *end2, * t, * t1, * b1, * b2, * e1, * e2;


typedef void (*tdinsert)(spisk**, int);
typedef void (*tdinsertend)(spisk**, int);
typedef void (*tdcreate)(spisk**, spisk**, int);


void create(spisk** b, spisk** e, int data) {
    t = new spisk;
    t->data = data;
    t->next = t->prev = nullptr;
    *b = *e = t;
}


void insert_begin(spisk** b, int data) {
    t = new spisk;
    t->data = data;
    t->prev = nullptr;
    t->next = *b;
    (*b)->prev = t;
    *b = t;
}


void insert_end(spisk** e, int data) {
    t1 = new spisk;
    t1->data = data;
    t1->next = nullptr;
    t1->prev = *e;
    (*e)->next = t1;
    *e = t1;
}


void output_begin(spisk* t) {
    printf("Элементы очереди СНАЧАЛА: ");
    while (t != nullptr) {
        printf("%i ", t->data);
        t = t->next;
    }
    puts("");
}


void output_end(spisk* t1) {
    printf("Элементы очереди С КОНЦА: ");
    while (t1 != nullptr) {
        printf("%i ", t1->data);
        t1 = t1->prev;
    }
    puts("");
}


void del(spisk** q) {
    while (*q != nullptr) {
        t = *q;
        *q = (*q)->next;
        delete t;
    }
}


void chooses(spisk** b, spisk** e, spisk** b1, spisk** e1, spisk** b2, spisk** e2,
    tdinsert insert_begin, tdinsertend insert_end, tdcreate create, std::string cond = "b") {

    do{
        if (cond == "b") {
            if ((*b)->data >= 0) {
                if (*b1 == nullptr && *e1 == nullptr) create(b1, e1, (*b)->data);
                else insert_begin(b1, (*b)->data);
            }
            else {
                if (*b2 == nullptr && *e2 == nullptr) create(b2, e2, (*b)->data);
                else insert_begin(b2, (*b)->data);
            }
            *b = (*b)->next;
        }
        else {
            if ((*e)->data >= 0) {
                if (*b1 == nullptr && *e1 == nullptr) create(b1, e1, (*e)->data);
                else insert_end(e1, (*e)->data);
            }
            else {
                if (*b2 == nullptr && *e2 == nullptr) create(b2, e2, (*e)->data);
                else insert_end(e2, (*e)->data);
            }
            *e = (*e)->prev;
        }
    } while (*b != nullptr && *e != nullptr);
}


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    int num, data;
    bool success = true;

    printf("Длина стека: ");
    while (success) {
        std::cin >> num;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Вы ввели не число! Повторите ввод: ");
        }
        else
            success = false;
        puts("");
    }
    printf("Выберите:\n1 - Заполнение в ручную\n2 - Заполнение случайно\nЗначение: ");
    puts("");
    int var;
    std::cin >> var;
    switch(var){
        case 1:{
            for (int i = 0; i < num; i++) {
                std::cout << "Значение = ";
                std::cin >> data;
                if (begin == nullptr && end == nullptr) create(&begin, &end, data);
                else insert_begin(&begin, data);
            }
            break;
        }
        case 2:{
            for (int i = 0; i < num; i++) {
                data = (rand() % 100);
                if (begin == nullptr && end == nullptr) create(&begin, &end, data);
                else insert_begin(&begin, data);
            }
            break;
        }
    }
    
    output_begin(begin);
    output_end(end);
    puts("");

    return 0;
}
