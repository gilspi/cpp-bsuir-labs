#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>


const char EN [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char en [] = "abcdefghijklmnopqrstuvwxyz";
const char num [] = "1234567890"; // добавить символов

struct queue{
    queue *prev, *next;
    int data;
} *begin, *end, *begin2, *end2, *t, *t1, *b1, *b2, *e1, *e2;


typedef void (*tdinsert)(queue **, int);
typedef void (*tdinsertend)(queue **, int);
typedef void (*tdcreate)(queue **, queue **, int);


void create(queue **b, queue **e, int data){
    t = new queue;
    t->data = data;
    t->next = t->prev = nullptr;
    *b = *e = t;
}


void insert_begin(queue **b, int data){
    t = new queue;
    t->data = data;
    t->prev = nullptr;
    t->next = *b;
    (*b)->prev = t;
    *b = t;
}


void insert_end(queue **e, int data){
    t1 = new queue;
    t1->data = data;
    t1->next = nullptr;
    t1->prev = *e;
    (*e)->next = t1;
    *e = t1;
}


void output_begin(queue *t){
    printf("Элементы очереди СНАЧАЛА: ");
    while(t != nullptr){
        printf("%i ", t->data);
        t = t->next;
    }
    puts("");
}


void output_end(queue *t1){
    printf("Элементы очереди С КОНЦА: ");
    while(t1 != nullptr){
        printf("%i ", t1->data);
        t1 = t1->prev;
    }
    puts("");
}


void del(queue **q) {
    while(*q != nullptr){
        t = *q;
        *q = (*q)->next;
        delete t;
    }
}


void chooses(queue **b, queue **e, queue **b1, queue **e1, queue **b2, queue **e2, tdinsert insert_begin, tdinsertend insert_end, tdcreate create, std::string cond="b"){
    
    do{
        
        if (cond == "b"){
            if ((*b)->data >= 0){
                if (*b1 == nullptr && *e1 == nullptr) create(b1, e1, (*b)->data);
                else insert_begin(b1, (*b)->data);
            }
            else{
                if (*b2 == nullptr && *e2 == nullptr) create(b2, e2, (*b)->data);
                else insert_begin(b2, (*b)->data);
            }
            *b = (*b)->next;
        }
        else{
            if ((*e)->data >= 0){
                if (*b1 == nullptr && *e1 == nullptr) create(b1, e1, (*e)->data);
                else insert_end(e1, (*e)->data);
            }
            else{
                if (*b2 == nullptr && *e2 == nullptr) create(b2, e2, (*e)->data);
                else insert_end(e2, (*e)->data);
            }
            *e = (*e)->prev;
        }
    }while (*b != nullptr && *e != nullptr);
}


int main() {
    srand(time(nullptr));
    
    int num, data;
    bool success = true;
    
    printf("Длина стека: ");
    while(success){
        std::cin >> num;
        if (!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Вы ввели не число! Повторите ввод: ");
        }
        else
            success = false;
        puts("");
    }
    
    for (int i=0; i<num; i++){
        data = rand() % 100 - 50;
        
        if (begin == nullptr && end == nullptr) create(&begin, &end, data);
        else insert_begin(&begin, data);
    }
    
    output_begin(begin);
    
    for (int i=0; i<num; i++){
        data = rand() % 100 - 50;
        
        if (begin2 == nullptr && end2 == nullptr) create(&begin2, &end2, data);
        else insert_end(&end2, data);
    }
    output_end(end);
    
    puts("");
    std::string cond;
    printf("Введите условие для разделения очереди(b/e): ");
    std::cin >> cond;

    if (cond == "b") chooses(&begin, &end, &b1, &e1, &b2, &e2, &insert_begin, &insert_end, &create, cond);
    if (cond == "e") chooses(&begin2, &end2, &b1, &e1, &b2, &e2, &insert_begin, &insert_end, &create, cond);
    
    if (cond == "b"){
        output_begin(b1);
        output_begin(b2);
    }
    if (cond == "e"){
        output_end(e1);
        output_end(e2);
    }
    
    return 0;
}
