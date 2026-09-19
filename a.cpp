#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        const int MAX_SIZE = 100;

        int n;
        cout << "Введите размер массива: ";

        if (!(cin >> n)) {
            throw runtime_error("Размер массива должен быть целым числом.");
        }

        if (n <= 0 || n > MAX_SIZE) {
            throw runtime_error("Размер массива должен быть от 1 до 100.");
        }

        double arr[MAX_SIZE];

        cout << "Введите элементы массива: ";
        for (int i = 0; i < n; i++) {
            if (!(cin >> arr[i])) {
                throw runtime_error("Не удалось считать элемент массива.");
            }
        }

        double mode = 0.0;
        int maxCount = 0;
        bool foundNonZero = false;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0.0) {
                continue;
            }

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                }
            }

            if (count > maxCount) {
                maxCount = count;
                mode = arr[i];
                foundNonZero = true;
            }
        }

        if (!foundNonZero) {
            cout << "Все элементы массива равны нулю. Замену выполнить невозможно." << endl;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0.0) {
                arr[i] = mode;
            }
        }

        cout << "Результат: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
