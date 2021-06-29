/* Базовый уровень Вариант 7. Поля структуры: Фамилия Группа Физика Информатика История, 
Определить средний бал оценок по физике, количество студентов с оценкой 5 по информатике и вывести сведения о них.*/

#include <iostream>

using namespace std;


struct Marks {
    int physics;
    int informatics;
    int history;

    bool isCorrect() {
        bool value = false;
        if ((physics <= 5 && physics > 0) && (informatics <= 5 && informatics > 0) && (history <= 5 && history > 0))
            value = true;
        return value;
    }
};

struct Student {
    char surname[56];
    char group[32];
    Marks progress;
};

int basicLevel_7variant() {

    int studentsPhysics;
    int studentsInformatics;

    int N = 2;
    Student group[N];

    for (int i = 0; i < N; i++) {
        do {
            cout << "\nInput marks: ";
            cout << "\nInput physics: ";
            cin.ignore(cin.rdbuf()->in_avail());
            cin >> group[i].progress.physics;

            cout << "\nInput informatics: ";
            cin.ignore(cin.rdbuf()->in_avail());
            cin >> group[i].progress.informatics;

            cout << "\nInput history: ";
            cin.ignore(cin.rdbuf()->in_avail());
            cin >> group[i].progress.history;
        } while (!group[i].progress.isCorrect());

        cout << "\nInput surname: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> group[i].surname;

        cout << "\nInput group: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin >> group[i].group;
        cin.clear();
        studentsPhysics += group[i].progress.physics;
        if (group[i].progress.informatics == 5) studentsInformatics++;

    }
    cout << "\nnumber of students with a grade of 5 in computer science is " << studentsInformatics;
    cout << "\nAverage score in physics " << studentsPhysics / N;
    for (int i = 0; i < N; i++) {
        if (group[i].progress.informatics == 5)
            cout << "\n surname " << group[i].surname;
        cout << "\n group " << group[i].group;
        cout << "\n informatics " << group[i].progress.informatics;
        cout << "\n physics " << group[i].progress.physics;
        cout << "\n history " << group[i].progress.history;
    }
}


struct Employee {
    char surname;
    char name;
    char patronymic;
    char salary;
    char position;
    char gender;
    int date;
    int experience = 2021 - date;

    bool dateIsCorrect() {
        bool value = false;
        if (date < 2021 && 2000 > date)
            value = true;
        return date;
    }
};

// Средний уровень Вариант 7. Поля структуры: Фамилия Имя Отчество Должность Пол Дата приема на работу, Определить средний стаж работы и вывести все сведения о сотрудниках, стаж которых выше среднего.

int middleLevel_7variant() {
    int experience;
    int N = 4;
    Employee workers[N];

    for (int i = 0; i <= N; i++) {
        do {
            cout << "\n enter year";
            cin >> workers[i].date;
        } while (!workers[i].dateIsCorrect());
        cout << "\n enter surname";
        cin >> workers[i].surname;
        cout << "\n enter name";
        cin >> workers[i].name;
        cout << "\n enter patronymic";
        cin >> workers[i].patronymic;
        cout << "\n enter salary";
        cin >> workers[i].salary;
        cout << "\n enter position";
        cin >> workers[i].position;
        cout << "\n enter gender";
        cin >> workers[i].gender;
        experience += workers[i].experience;
    }
    int middleExperience = experience / N;
    for (int i = 0; i <= N; i++) {
        if (workers[i].experience < middleExperience) {
            cout << "\nsurname " << workers[i].surname;
            cout << "\nname " << workers[i].name;
            cout << "\npatronymic " << workers[i].patronymic;
            cout << "\nsalary " << workers[i].salary;
            cout << "\nposition " << workers[i].position;
            cout << "\ngender " << workers[i].gender;
            cout << "\nexperience " << workers[i].experience;



        }
    }
}

int main() {
    basicLevel_7variant();
    middleLevel_7variant();
}
