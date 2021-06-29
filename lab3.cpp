#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int basicLevel() {
    //Начальный уровень Введите массив символов из 15 элементов. Подсчитать количество гласных русских букв.
    char vowels[7] = {"aeuoyi"};
    char symbols[15] = "";
    int sum = 0;
    cout << "Enter symbols\n";
    cin.getline(symbols, 15);
    for (int i = 0; i < strlen(symbols); i++) {
        for (int j = 0; j < strlen(symbols); j++) {
            if (symbols[j] == vowels[i]) {
                sum++;
            }
        }
    }
    cout << sum << " vowels";
};


int middleLevel() {
//        Средний уровень Дан массив символов, содержащий текст, заканчивающийся точкой. Вывести на экран слова, содержащие три буквы .
    char sentence[100], word[50];
    cout<<"Enter array: \n";
    cin.getline(sentence, 100);
    stringstream words(sentence);
    while (words >> word)
    {
        if (strlen(word) == 3)
            cout << word << "\n";
    };
}

int hardLevel() {
    //Высокий уровень. Введите массив символов из 20 элементов, состоящий из строчных букв и пробелов. Определить слово, которое начинается и заканчивается на одну и ту же букву.
//    char s;
    char elements[20] = "";
    cout<<"Enter array: \n";
    cin.getline(elements, 15);
    stringstream words(elements);
    for (string i; words >> i;)
        if (i[0] == i[i.length() - 1])
            cout<<"\nyour word: " << i << "\n";
}

int main() {
    middleLevel();
}



