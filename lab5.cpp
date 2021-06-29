#include <iostream>
#include <sstream>
#include <strstream>
#include <fstream>
#include <string>

using namespace std;

/*Вариант 7 базовый уровень*
«Военнослужащий»:фамилия; имя; отчество; домашний адрес (почтовый индекс, страна, область, район,
 город, улица, дом, квартира); национальность; дата рождения (год, месяц число); должность; звание.
 Вывести данные про военнослужащих в звании “лейтенант”.
 */

struct Date {
    int day;
    int month;
    int year;

    bool isCorrect();
};

bool Date::isCorrect() {
    bool result = false;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if ((day <= 31) && (day > 0))
                result = true;
            break;
        }

        case 4:
        case 6:
        case 9:
        case 11: {
            if ((day <= 30) && (day > 0))
                result = true;
            break;
        }

        case 2: {
            if (year % 4 != 0) {
                if ((day <= 28) && (day > 0))
                    result = true;
            } else if (year % 400 == 0) {
                if ((day <= 29) && (day > 0))
                    result = true;
            } else if ((year % 100 == 0) && (year % 400 != 0)) {
                if ((day == 28) && (day > 0))
                    result = true;
            } else if ((year % 4 == 0) && (year % 100 != 0))
                if ((day <= 29) && (day > 0))
                    result = true;
            break;
        }

        default:
            result = false;
    }
    if (year > 2002) { result = false; }

    return result;
}

struct Location {
    int postIndex;
    char country[56];
    char region[56];
    char district[56];
    char city[56];
    char street[56];
    char house[56];
    char flat[56];

};

struct Soldier {
    char name[56];
    char surname[56];
    char middleName[56];
    Location address;
    char nationality[56];
    Date birthday;
    char position[56];
    char rank[32];


};


int main() {
    ifstream inf("text.txt");

    if (!inf) {
        cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
        exit(1);
    }


    while (inf) {
        string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }


    int N;
    cout << "How many soldiers do you need to add?\n";
    cin >> N;
    Soldier *soldier = new Soldier[N];

    for (int i = 0; i < N; i++) {
        cout << "\nEnter name: ";
        cin >> soldier[i].name;
        cout << "\nEnter surname: ";
        cin >> soldier[i].surname;
        cout << "\nEnter middle name: ";
        cin >> soldier[i].middleName;
        cout << "\nEnter post index: ";
        cin >> soldier[i].address.postIndex;
        cout << "\nEnter country: ";
        cin >> soldier[i].address.country;
        cout << "\nEnter nationality: ";
        cin >> soldier[i].nationality;
        cout << "\nEnter region: ";
        cin >> soldier[i].address.region;
        cout << "\nEnter district: ";
        cin >> soldier[i].address.district;
        cout << "\nEnter city: ";
        cin >> soldier[i].address.city;
        cout << "\nEnter street: ";
        cin >> soldier[i].address.street;
        cout << "\nEnter house: ";
        cin >> soldier[i].address.house;
        cout << "\nEnter flat: ";
        cin >> soldier[i].address.flat;
        cout << "\nEnter rank: ";
        cin >> soldier[i].rank;
        cout << "\nEnter position: ";
        cin >> soldier[i].position;
        do {
            cout << "\nEnter day: ";
            cin >> soldier[i].birthday.day;
            cout << "\nEnter month: ";
            cin >> soldier[i].birthday.month;
            cout << "\nEnter year: ";
            cin >> soldier[i].birthday.year;
        } while (!soldier[i].birthday.isCorrect());
    }

    ofstream lines("text.txt");

    if (!lines) {
        cerr << "Sorry, text.txt could not be opened for writing!\n";
        exit(1);
    }
    string lieutenant = "lieutenant";

    for (int i = 0; i < N; i++) {
        if (soldier[i].rank == lieutenant)
            lines << "\nName: " << soldier[i].name;
        lines << "\nsurname: " << soldier[i].surname;
        lines << "\nmiddle name: " << soldier[i].middleName;
        lines << "\npost index: " << soldier[i].address.postIndex;
        lines << "\ncountry: " << soldier[i].address.country;
        lines << "\nregion: " << soldier[i].address.region;
        lines << "\ndistrict: " << soldier[i].address.district;
        lines << "\ncity: " << soldier[i].address.city;
        lines << "\nstreet: " << soldier[i].address.street;
        lines << "\nhouse: " << soldier[i].address.house;
        lines << "\nflat: " << soldier[i].address.flat;
        lines << "\nnationality: " << soldier[i].nationality;
        lines << "\nrank: " << soldier[i].rank;
        lines << "\nEnter " << soldier[i].position;
        lines << "\nday: " << soldier[i].birthday.day;
        lines << "\nmonth: " << soldier[i].birthday.month;
        lines << "\nyear: " << soldier[i].birthday.year;
    }
    lines.close();
}

int middleLevel() {
    double firstNumber, secondNumber, difference;
    ifstream numbers("numbers.txt");
    if(!numbers) {
        cerr << "There is no file \n";
        return 1;
    }
    numbers >> firstNumber >> secondNumber;
    if(!numbers) {
        cerr << "error\n";
        return 1;
    }
    do numbers >> secondNumber; while(numbers);
    difference = firstNumber - secondNumber;
    cout << difference << "\n";
    return 0;
}
