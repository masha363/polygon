#include <iostream>
#include <vector>
#include <cassert>
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

// Функция для проверки правильности сортировки
void testBubbleSort() {
    // 1. Лучший случай (массив уже отсортирован)
    vector<int> bestCase = {1, 2, 3, 4, 5, 6, 7};
    bubbleSort(bestCase);
    for (size_t i = 1; i < bestCase.size(); ++i) {
        assert(bestCase[i - 1] <= bestCase[i]);
    }
    cout << "Best case passed!" << endl;

    // 2. Средний случай (случайный массив)
    vector<int> averageCase = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(averageCase);
    for (size_t i = 1; i < averageCase.size(); ++i) {
        assert(averageCase[i - 1] <= averageCase[i]);
    }
    cout << "Average case passed!" << endl;

    // 3. Худший случай (массив отсортирован в обратном порядке)
    vector<int> worstCase = {90, 64, 34, 25, 22, 12, 11};
    bubbleSort(worstCase);
    for (size_t i = 1; i < worstCase.size(); ++i) {
        assert(worstCase[i - 1] <= worstCase[i]);
    }
    cout << "Worst case passed!" << endl;
}

int main() {
    // Запуск тестов
    testBubbleSort();
    return 0;
}

