// ________________ Указатели и обработка строк ________________

// указатель на массив символов
char str1[] = "Text"; // массив str1 = { 'T', 'e', 'x', 't', '\0' }
char *p1;

// способ 1 - имя строки есть указателем на первый символ строки
p1 = str1; // указатель p1 указывает на str1

// способ 2
p1 = &str1[0];

//доступ к символу строки через указатель
*p1 = 'N';     // str1 = "Next" - работает
*(p1+3) = '!'; // str1 = "Nex!"










// _____________________________ Перечисления (enum) ______________________________


enum COLOR{              //Перечисление объявляется как и структура, назвали перечисление COLOR
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    LIGHT_BLUE,
    BLUE,
    VIOLETTE
};
 
 
int main(){
	COLOR color;	 //color - объект данного перечисления, можно добавлять новые объекты через запятую
}










// __________________________ Файлы.  ______________________________

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    char buff[50]; // буфер промежуточного хранения считываемого из файла текста
    ifstream fin("cppstudio.doc"); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)
 
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
    fin >> buff; // считали первое слово из файла
    cout << buff << endl; // напечатали это слово
 
    fin.getline(buff, 50); // считали строку из файла
    fin.close(); // закрываем файл
    cout << buff << endl; // напечатали эту строку
    }
    system("pause");
    return 0;
}










// ___________________________ Методы поиска ________________________________

 
int sequentialSearch(int arr[], int n, int x) { // полседовательный поиск
    for (int i = 0; i < n; i++) { 
        if (arr[i] == x) 
            return i; 
    } 
    return -1; 
} 

 
int binarySearch(int arr[], int l, int r, int x) { // бинарный поиск
    while (l <= r) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        else if (arr[mid] < x) 
            l = mid + 1; 
        else 
            r = mid - 1; 
    } 
    return -1; 
} 
// (по заранее отсортированному в порядке возрастания массиву) каждую итерацию берёт половину значений










// ___________________________ Методы сортировки ________________________________

void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]); 
            } 
        } 
} 

void selectionSort(int arr[], int n) {  // сортировка выбором
    for (int i = 0; i < n - 1; i++) { 
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
        swap(arr[min_idx], arr[i]); 
    } 
} 
// две зоны (готовая и исходная, каждую итерацию вставляем минимальное число из исход. в начало готов)
 
 
void insertionSort(int arr[], int n) { // сортировка вставками
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
}
// используя бинарный поиск каждую итерацию берём первое значение из исход и подставляем на своё место в готов
 
// ______________________ Отличия языка Си и С++. ______________________

/*
C - процедурный язык программирования, а C++ является объекто-ориентированным языком
*/










// ______________________ Стек, очередь, дек ______________________

/*
Стек - наверх положили, сверху достали
Очередь - вниз положили, сверху достали
Дэк - можно и положить и достать с любого конца
*/
