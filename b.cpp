#include <iostream>
#include <string>
using namespace std;

int main() {
    try {
        string text;
        cout << "Введите текст: " << endl;
        getline(cin, text);

        string bots[100];
        int botCount = 0;

        int i = 0;
        while (i < (int)text.size()) {
            if (text[i] == '@') {
                int j = i + 1;
                char first = (j < (int)text.size()) ? text[j] : ' ';

                bool firstOk = (first >= 'a' && first <= 'z')
                            || (first >= 'A' && first <= 'Z')
                            || first == '_';

                if (firstOk) {
                    string bot = "@";
                    while (j < (int)text.size()) {
                        char c = text[j];
                        bool valid = (c >= 'a' && c <= 'z')
                                  || (c >= 'A' && c <= 'Z')
                                  || (c >= '0' && c <= '9')
                                  || c == '_';
                        if (!valid) break;
                        bot += c;   
                        j++;
                    }
                    bots[botCount++] = bot;
                    i = j;
                    continue;
                }
            }
            i++;
        }

        if (botCount == 0) {
            cout << "Боты не найдены." << endl;
        } else {
            cout << "Найденные боты (" << botCount << "):" << endl;
            for (int k = 0; k < botCount; k++) {
                cout << "  " << bots[k] << endl;
            }
        }

    } catch (exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;
}