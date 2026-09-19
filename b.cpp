#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool isLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}

bool isValidFirstBotChar(char c) {
    return isLatinLetter(c) || c == '_';
}

bool isValidBotChar(char c) {
    return isLatinLetter(c) ||
           (c >= '0' && c <= '9') ||
           c == '_';
}

int main() {
    try {
        const int MAX_BOTS = 100;

        string text;
        cout << "Введите текст: ";

        if (!getline(cin, text)) {
            throw runtime_error("Не удалось прочитать текст.");
        }

        string bots[MAX_BOTS];
        int botCount = 0;

        int i = 0;

        while (i < static_cast<int>(text.size())) {
            if (text[i] == '@') {
                int j = i + 1;

                if (j < static_cast<int>(text.size()) &&
                    isValidFirstBotChar(text[j])) {

                    string bot = "@";

                    while (j < static_cast<int>(text.size()) &&
                           isValidBotChar(text[j])) {
                        bot += text[j];
                        j++;
                    }

                    if (botCount < MAX_BOTS) {
                        bots[botCount] = bot;
                        botCount++;
                    } else {
                        throw runtime_error("Найдено слишком много адресов ботов.");
                    }

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

            for (int i = 0; i < botCount; i++) {
                cout << bots[i] << endl;
            }
        }
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
