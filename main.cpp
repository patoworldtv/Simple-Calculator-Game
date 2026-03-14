#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateNumber(int difficulty) {
    if (difficulty == 1) return rand() % 10 + 1;       // 1–10
    if (difficulty == 2) return rand() % 50 + 1;       // 1–50
    return rand() % 100 + 1;                           // 1–100
}

char randomOperator() {
    int op = rand() % 4;
    if (op == 0) return '+';
    if (op == 1) return '-';
    if (op == 2) return '*';
    return '/';
}

int main() {
    srand(time(0));

    cout << "=== SIMPLE CALCULATOR GAME ===\n";

    int score = 0;

    while (true) {
        int difficulty;
        cout << "\nChoose difficulty:\n";
        cout << "1. Easy\n2. Medium\n3. Hard\n";
        cout << "Enter choice (1-3): ";
        cin >> difficulty;

        if (difficulty < 1 || difficulty > 3) {
            cout << "Invalid difficulty.\n";
            continue;
        }

        int num1 = generateNumber(difficulty);
        int num2 = generateNumber(difficulty);
        char op = randomOperator();

        // Avoid division by zero
        if (op == '/' && num2 == 0) num2 = 1;

        double correctAnswer;

        switch (op) {
            case '+': correctAnswer = num1 + num2; break;
            case '-': correctAnswer = num1 - num2; break;
            case '*': correctAnswer = num1 * num2; break;
            case '/': correctAnswer = (double)num1 / num2; break;
        }

        cout << "\nSolve: " << num1 << " " << op << " " << num2 << " = ";
        double playerAnswer;
        cin >> playerAnswer;

        if (abs(playerAnswer - correctAnswer) < 0.001) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << correctAnswer << "\n";
        }

        char again;
        cout << "\nPlay another round? (y/n): ";
        cin >> again;

        if (again != 'y' && again != 'Y') {
            cout << "\nFinal Score: " << score << "\n";
            cout << "Thanks for playing!\n";
            break;
        }
    }

    return 0;
}
