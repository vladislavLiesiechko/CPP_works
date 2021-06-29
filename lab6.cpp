#include <iostream>
#include <string>
#include <cstdio>


using namespace std;

/* Вариант 7x - средний уровень
Создать бинарный файл с информацией о наличии компьютеров
 для продажи: название компьютера; частота процессора; объем оперативной памяти;
 объем жесткого диска; тип монитора; размер монитора; цена. Определить компьютер с
 наибольшейпроизводительностью:с наибольшей скоростью процессора при объеме оперативнои
 ̆ памяти не менее 2 Гбайт и напечатать его характеристики. */

struct Catalog {
    char computer[255];
    char monitorSize[255];
    char monitorType[255];
    double frequencyCPU;
    int sizeRAM;
    int sizeHDD;
    int price;


};

int task_10() {
    int N;
    cout << "\nEnter number of computers\n";
    cin >> N;
    Catalog *catalog = new Catalog[N];
    char path[] = "lab.bin";

    for (int i = 0; i < N; i++) {
        cout << "Enter name of computer: ";

        cin>>catalog[i].computer;


        cout << "\nEnter size of monitor : ";
        cin >> catalog[i].monitorSize;

        cout << "\nEnter type of monitor : ";
        cin>>catalog[i].monitorType;

        cout << "\nEnter frequency of CPU: ";
        cin >> catalog[i].frequencyCPU;

        cout << "\nEnter size of RAM: ";
        cin >> catalog[i].sizeRAM;

        cout << "\nEnter size of HDD: ";
        cin >> catalog[i].sizeHDD;

        cout << "\nEnter price: ";
        cin >> catalog[i].price;

    }
    FILE *f_out, *f_in;
    f_out = fopen(path, "wb");
    fwrite(catalog, sizeof(Catalog), N, f_out);
    fclose(f_out);

    delete[] catalog;
    catalog = nullptr;

    Catalog *restoredLab = new Catalog[N];
    f_in = fopen(path, "rb");
    fread(restoredLab, sizeof(Catalog), N, f_in);
    fclose(f_in);
    for (int i = 0; i < N; i++) {
        if (restoredLab[i].sizeRAM >= 2 && restoredLab[i].frequencyCPU > 2.4) {
            cout << "\nName: ";
            cout << restoredLab[i].computer;
            cout << "\nMonitor size: ";
            cout << restoredLab[i].monitorSize << "inch";
            cout << "\nMonitor type: ";
            cout << restoredLab[i].monitorType;
            cout << "\nfrequency of CPU: ";
            cout << restoredLab[i].frequencyCPU << " ghz";
            cout << "\nsize of RAM: ";
            cout << restoredLab[i].sizeRAM<<"GB";
            cout << "\nsize of HDD: ";
            cout << restoredLab[i].sizeHDD<<"GB";
            cout << "\nPrice: ";
            cout << "$"<<restoredLab[i].price;
        }
    }


}


int main() {
    task_10();
}
