#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

// Функция для сортировки массива с использованием пузырьковой сортировки
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Внешний цикл проходит по всем элементам массива
    for (int i = 0; i < n - 1; ++i) {
        // Флаг, чтобы проверить, были ли перестановки
        bool swapped = false;

        // Внутренний цикл для сравнения соседних элементов
        // После каждого прохода можно игнорировать последний отсортированный элемент
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Меняем элементы местами
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Если в текущем проходе не было перестановок, значит массив отсортирован
        if (!swapped) {
            break;
        }
    }
}

vector<int> readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        exit(1);
    }

    vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }

    return data;
}

void Test() {
    // Инициализация векторов без использования списков инициализации
    vector<int> good_test;
    for (int i = 1; i <= 19; ++i) {
        good_test.push_back(i);
    }
    vector<int> ans_good;
    for (int i = 1; i <= 19; ++i) {
        ans_good.push_back(i);
    }
    bubbleSort(good_test);
    assert(good_test == ans_good);
    cout << "the first test is completed" << endl;

    vector<int> mean_test;
    for (int i = 7; i <= 20; ++i) {
        mean_test.push_back(i);
    }
    vector<int> ans_mean;
    for (int i = 1; i <= 20; ++i) {
        ans_mean.push_back(i);
    }
    bubbleSort(mean_test);
    assert(mean_test == ans_mean);
    cout << "the second test is completed" << endl;

    vector<int> bad_test;
    for (int i = 19; i >= 0; --i) {
        bad_test.push_back(i);
    }
    vector<int> ans_bad;
    for (int i = 0; i <= 19; ++i) {
        ans_bad.push_back(i);
    }
    bubbleSort(bad_test);
    assert(bad_test == ans_bad);
    cout << "the third test is completed" << endl;
}

void Test_time(const vector<string>& filenames) {
    for (const string& filename : filenames) {
        vector<int> data = readFile(filename);

        auto start = chrono::high_resolution_clock::now();
        bubbleSort(data);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> time = end - start;

        cout << "the length of the array " << data.size() << ", sorting time = " << time.count() << " seconds" << endl;
    }
}

int main() {
    Test();

    vector<string> filenames = {
        "file1.txt", "file2.txt", "file3.txt", "file4.txt",
        "file5.txt", "file6.txt", "file7.txt", "file8.txt",
        "file9.txt", "file10.txt", "file11.txt", "file12.txt",
        "file13.txt", "file14.txt", "file15.txt", "file16.txt"
    };
    Test_time(filenames);

    return 0;
}
