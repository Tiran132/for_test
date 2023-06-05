#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

struct City {
    int index;
    string name;
    int popularity;
};


void printCities(City * cities, int n) {
    for (int i = 0; i < n; i++) {
        City c = cities[i];
        cout << c.index << " " << c.name << " : " << c.popularity << "\n";
    }
}


void writeCities  (City * cities, int n) {
    ofstream out("out.txt");
    
    for (int i = 0; i < n; i++) {
        City c = cities[i];
        out << c.index << " " << c.name << " " << c.popularity << "\n";
    }
    
    out.close();
}


void readCities (City * cities, int n) {
    ifstream in("in.txt");
    
    int i = 0, index, p;
    string line;
    
    while (in >> index >> line >> p) {
        cities[i].index = index;    
        cities[i].name = line;
        cities[i].popularity = p;
        i++;
    }
    
    in.close();
}


void sortCities(City * cities, int n) {
    for (int i = 1; i < n; i ++) {
        City key = cities[i];
        int j = i - 1;
        while (j >= 0 && cities[j].popularity > key.popularity) {
            cities[j + 1] = cities[j];
            j--;
        }
        cities[j + 1] = key;
    }
}


void findCity(City * cities, int n, int minPop) {
    for (int i = 0; i < n; i ++) {
        City c = cities[i];
        if (c.popularity >= minPop){
            cout << "\n====\n";
            cout << c.index << " " << c.name << " " << c.popularity << "\n";
            break;
        }
    }
}


int main() { 
    setlocale( LC_ALL,"Russian" ); 
    const int n = 5;
    City cities[n];
    
    readCities(cities, n);
    printCities(cities, n);
    sortCities(cities, n);
    findCity(cities, n, 10000);
    writeCities(cities, n);
    

    return 0; 
}



/*

Разработать хранилище массива  данных в файле

структура:
инекс
название города
количество населения

прочитать 5 элементов
вывести все города
отсортировать методом вставок по кол-ву населения
вывести индекс первого города с населением > 10000 чел

записать города в новый файл

*/
