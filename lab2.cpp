#include <iostream>
#include <sstream>
#include <strstream>

using namespace std;

//Вариант 7 «Военнослужащий»:фамилия; имя; отчество; домашний адрес (почтовый индекс, страна, область, район,город,улица,дом,квартира);национальность;датарождения (год, месяц число); должность; звание.

struct Date {
    short day;
    short month;
    short year;

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
    short postIndex;
    char country[56];
    char region[56];
    char district[56];
    char city[56];
    char street[56];
    short house;
    short flat;

};

struct Soldier {
    char name[32];
    char surname[32];
    char middleName[32];
    Location address;
    char nationality[32];
    Date birthday;
    char position[32];
    char rank[32];


};


//Вариант 7 «Военнослужащий»:фамилия; имя; отчество; домашний адрес (почтовый индекс, страна, область, район,город,улица,дом,квартира);национальность;датарождения (год, месяц число); должность; звание.


int main() {
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
            cin >> soldier[i].birthday.day;
            cin >> soldier[i].birthday.month;
            cin >> soldier[i].birthday.year;
        } while (!soldier[i].birthday.isCorrect());

    }

    for (int i = 0; i < N; i++) {
        cout << "\nName: " << soldier[i].name;
        cout << "\nsurname: " <<  soldier[i].surname;
        cout << "\nmiddle name: " << soldier[i].middleName;
        cout << "\npost index: " << soldier[i].address.postIndex;
        cout << "\ncountry: " << soldier[i].address.country;
        cout << "\nregion: " << soldier[i].address.region;
        cout << "\ndistrict: " << soldier[i].address.district;
        cout << "\ncity: " << soldier[i].address.city;
        cout << "\nstreet: " << soldier[i].address.street;
        cout << "\nhouse: " << soldier[i].address.house;
        cout << "\nflat: " << soldier[i].address.flat;
        cout << "\nnationality: " << soldier[i].nationality;
        cout << "\nday: " << soldier[i].birthday.day;
        cout << "\nmonth: " << soldier[i].birthday.month;
        cout << "\nyear: " << soldier[i].birthday.year;
    }
}



