#include <iostream>
#include <Windows.h>
using namespace std;
void matrix43();
void matrix68();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    do
    {
        cout << "Номер завдання(0 для виходу):";
        cin >> menu;
        switch (menu)
        { // перемикання між завданнями
        case 1:
            matrix43();
            break; // Завдання 1
        case 2:
            matrix68();
            break; // Завдання 2

        }
    } while (menu);
    system("pause");
    return 0;
}
void input_matrix(int* matrix[], int rows, int cols)
{
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// функція виведення масиву
void print_matrix(int* matrix[], int rows, int cols) {
    cout << "Матриця розміру " << rows << " x " << cols << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int countColumnsDescending(int** matrix, int rows, int cols) {
    int count = 0;

    for (int j = 0; j < cols; ++j) {
        bool descending = true;
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][j] > matrix[i - 1][j]) {
                descending = false;
                break;
            }
        }
        if (descending) {
            count++;
        }
    }

    return count;
}
void matrix43()
{

    int M, N;

    // Зчитуємо розміри матриці
    cout << "Введіть кількість рядків (M): ";
    cin >> M;
    cout << "Введіть кількість стовпців (N): ";
    cin >> N;

    // Створюємо матрицю розміру M x N
    int** matrix = new int* [M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    input_matrix(matrix, M, N);
    // Знаходимо кількість стовпців з елементами, що впорядковані за спаданням
    int count = countColumnsDescending(matrix, M, N);
    cout << "Кількість стовпців з елементами, що впорядковані за спаданням: " << count << endl;

    // Звільняємо виділену пам'ять
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

}
void insertZeroRow(int**& matrix, int& M, int N, int K) {
    // Зберігаємо початковий розмір матриці
    int originalM = M;

    // Збільшуємо розмір матриці на один рядок
    M++;
    // Переносимо рядки від K до M на один рядок вниз
    for (int i = M - 1; i >= K; --i) {
        matrix[i] = matrix[i - 1];
    }

    // Вставляємо рядок з нулів перед рядком з номером K
    matrix[K - 1] = new int[N]();
}
void matrix68()
{
    int M, N, K;

    // Зчитуємо розміри матриці та номер рядка K
    cout << "Введіть кількість рядків (M): ";
    cin >> M;
    cout << "Введіть кількість стовпців (N): ";
    cin >> N;
    cout << "Введіть номер рядка для вставки (1 ≤ K ≤ M): ";
    cin >> K;

    int** matrix = new int* [M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    // Введення та виведення матриці
    input_matrix(matrix, M, N);
    print_matrix(matrix, M, N);

    // Викликаємо функцію для вставки рядка з нулів перед рядком з номером K
    insertZeroRow(matrix, M, N, K);
    print_matrix(matrix, M, N);
}