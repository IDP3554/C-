#include <iostream>
using namespace std;

int main() {
    try {
        int n;
        cout << "Введите размер массива: ";
        cin >> n;
        if (n <= 0) throw runtime_error("Размер должен быть положительным");

        double arr[100];
        cout << "Введите элементы: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        double mode = 0;
        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0.0) continue;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) count++;
            }
            if (count > maxCount) {
                maxCount = count;
                mode = arr[i];
            }
        }

        if (mode == 0.0) {
            cout << "Все элементы нулевые, замена невозможна." << endl;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0.0) arr[i] = mode;
        }

        cout << "Результат: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;

    } catch (exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
