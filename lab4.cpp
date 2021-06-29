#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;


int basicLevel() {
//Определить, есть ли в заданной строке символ цифра. Вывести сообщение об этом
    string symbols;
    cin >> symbols;
    int count;
    for (int i = 0; i < symbols.size(); i++) {
        if (symbols[i] >= '0' && symbols[i] <= '9') {
            count++;
            return 0;
        }
        cout << count;
    }


    return 0;
}


int middleLevel() {

    //В заданной строке вставить перед каждым символом «!» символ «,»
    string firstString;
    getline(cin, firstString);
    int count = 0;
    for (int i = 0; i < firstString.length(); i++) {
        if (firstString[i] == '!') {
            count++;
        }
    }
    string secondString;
    secondString.resize(firstString.length() + count);
    for (int i = 0, k = 0; i < firstString.length(); i++, k++) {
        if (firstString[i] != '!') {
            secondString[k] = firstString[i];
        } else {
            secondString[k] = ',';
            secondString[++k] = '!';
        }
    }
    cout << secondString << endl;

}

int hardLevel() {
    string symbols;
    getline(cin, symbols);
    string s = "";
    for (int i = 0; i < symbols.size(); i++)

        if (s[s.find(symbols[i])] == symbols[i]);
        else
            s += symbols[i];
    cout << "Number of different characters: " << s.size() << endl;
}

int main() {
    basicLevel();
}


