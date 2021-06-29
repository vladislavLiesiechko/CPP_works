#include <iostream>
#include <random>
#include <vector>
#include <iterator>

using namespace std;

/*Вариант 7 - базовый уровень
Создать линейный однонаправленный список из вещественных чисел. Удалить из списка элемент по его номеру в односвязном списке.*/



struct List
{
    int inf;
    List* next;
};

void task (List*& head, int pos)
{

    if (pos == 0)
    {
        List* tmp = head;

        head = head->next;

        delete tmp;
    }
    else {
        List* tmp = head;

        for (int i = 0; i < pos; ++i)
            tmp = tmp->next;

        List* before = head;

        while (before->next != tmp)
            before = before->next;

        before->next = tmp->next;

        delete tmp;
    }
}
int main()
{
    void task();
}