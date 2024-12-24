#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <chrono>
#include <sstream>
#include <string>
using namespace std;
// Функция для сортировки массива с использованием сортировки выбором
void selectionSort(vector<int>& arr) {
int n = arr.size();
// Внешний цикл: для каждого элемента массива
for (int i = 0; i < n - 1; ++i) {
    // Ищем минимальный элемент в неотсортированной части массива
    int minIndex = i;
    
    // Внутренний цикл: поиск минимального элемента
    for (int j = i + 1; j < n; ++j) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    // Меняем местами минимальный элемент с текущим элементом
    if (minIndex != i) {
        swap(arr[i], arr[minIndex]);
    }
}
}
// Проверка, что массив отсортирован
bool isSorted(const vector<int>& arr) {
for (size_t i = 1; i < arr.size(); ++i) {
if (arr[i - 1] > arr[i]) {
return false;
}
}
return true;
}
// Функция для чтения данных из файла
vector<int> readFile(const string& filename) {
ifstream file(filename);
vector<int> data;
int value;
while (file >> value) {
data.push_back(value);
}
return data;
}
// Функция тестирования сортировки выбором
void Test() {
vector<int> good_test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
vector<int> ans_good = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
selectionSort(good_test);
assert(good_test == ans_good);
cout << "Selection sort: the first test is completed" << endl;
vector<int> mean_test = { 7, 2, 9, 4, 10, 1, 3, 8, 5, 6, 12, 15, 11, 13, 14, 20, 18, 17, 19, 16 };
vector<int> ans_mean = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
selectionSort(mean_test);
assert(mean_test == ans_mean);
cout << "Selection sort: the second test is completed" << endl;

vector<int> bad_test = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
vector<int> ans_bad = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
selectionSort(bad_test);
assert(bad_test == ans_bad);
cout << "Selection sort: the third test is completed" << endl;
}
// Функция для замера времени сортировки
void Test_time(const vector<string>& filenames) {
for (size_t i = 0; i < filenames.size(); i++) {
vector<int> data = readFile(filenames[i]);
    auto start = chrono::high_resolution_clock::now();
    selectionSort(data);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> time = end - start;

    cout << "Selection sort: length of the array " << data.size() << ", sorting time = " << time.count() << " seconds" << endl;
}
}
int main() {
// Тестирование сортировки выбором
Test();
vector<string> filenames = {
    "/Users/golubevamaria/Desktop/test_sort/file1.txt", "/Users/golubevamaria/Desktop/test_sort/file2.txt", 
    "/Users/golubevamaria/Desktop/test_sort/file3.txt", "/Users/golubevamaria/Desktop/test_sort/file4.txt",
    "/Users/golubevamaria/Desktop/test_sort/file5.txt", "/Users/golubevamaria/Desktop/test_sort/file6.txt", 
    "/Users/golubevamaria/Desktop/test_sort/file7.txt", "/Users/golubevamaria/Desktop/test_sort/file8.txt",
    "/Users/golubevamaria/Desktop/test_sort/file9.txt", "/Users/golubevamaria/Desktop/test_sort/file10.txt", 
    "/Users/golubevamaria/Desktop/test_sort/file11.txt", "/Users/golubevamaria/Desktop/test_sort/file12.txt",
    "/Users/golubevamaria/Desktop/test_sort/file13.txt", "/Users/golubevamaria/Desktop/test_sort/file14.txt", 
    "/Users/golubevamaria/Desktop/test_sort/file15.txt", "/Users/golubevamaria/Desktop/test_sort/file16.txt"
};
Test_time(filenames);

// Генерация файлов для box_plot_10e4 и box_plot_10e5
vector<string> box_plot_10e4;
vector<string> box_plot_10e5;
for (int i = 0; i < 50; i++) {
    ostringstream oss;
    oss << "/Users/golubevamaria/Desktop/file_boxplot_10e4/file_" << i << ".txt";
    box_plot_10e4.push_back(oss.str());
}

for (int i = 0; i < 50; i++) {
    ostringstream oss;
    oss << "/Users/golubevamaria/Desktop/file_boxplot_10e5/file_" << i << ".txt";
    box_plot_10e5.push_back(oss.str());
}
Test_time(box_plot_10e4);
Test_time(box_plot_10e5);

// Пример сортировки с выводом
vector<int> arr = { 3, 2, 4, 1 };

cout << "Selection sort: the original array: ";
for (int num : arr) {
    cout << num << " ";
}
cout << endl;

selectionSort(arr);

cout << "Selection sort: the sorted array: ";
for (int num : arr) {
    cout << num << " ";
}
cout << endl;

return 0;
