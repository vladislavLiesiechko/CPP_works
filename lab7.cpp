#define _CRT_SECURE_NO_WARNINGS
#include <stdafx.h>
#include <iostream>
#include <string>
using namespace std;

/*Вариант 7 базовый уровень*
Создать стек, информационными полями
 которого являются: фамилия и средний бал студента.
 Добавить в стек сведения о новом студенте. Организовать
 просмотр данных стека.*/


class Stack
{
private:
    string* stck;
    int ts;
    int sz;

public:
    Stack(int size)
    {
        sz = size;
        stck = new string[2 * sz];
        ts = 0;
    }

    ~Stack() {
        delete[]stck;
    }

    void push(string itm)
    {
        if (ts == 2 * sz)
            cout << "Stack is full!" << endl;
        else stck[ts++] = itm;
    }

    string pop() {
        if (ts < 0) {
            cout << "Stack isn't loaded!" << endl;
            return 0;
        }
        else return stck[--ts];
    }
};

int main() {
    setlocale(0, "rus");
    cout << "Stack size: ";
    int n;
    cin >> n;
    Stack mystck1(n);
    string st;


    for (int i = 0; i < n; i++)
    {
        cout << "Enter last name: ";
        cin >> st;
        mystck1.push(st);
        cout << "Enter Age : ";
        cin >> st;
        mystck1.push(st);
    }
    for (int i = 0; i < n; i++)
        cout << "Last Name of student is" << mystck1.pop() << " His age " << mystck1.pop() << endl;


    cin.get();
    cin.get();
    return 0;
}