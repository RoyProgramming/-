#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//Инициализация векторов
int IniTVector(int length, double* vector)
{
    for (size_t i = 0; i < length; i++)
    {
        cout << "Enter a number for the vector: ";
        cin >> vector[i];
    }

    return 0;
}

//Вычисление скалярного произведения
int ScalarMult(double result, double* vectorA, double* vectorB)
{
    for (size_t i = 0; i < 2; i++)
    {
        result += vectorA[i] * vectorB[i];
    }

    cout << "Scalar result: " << result << endl;

    return 0;
}

int main(void)
{
    int length = 0;

    cout << "Enter the number of vectors: ";
    cin >> length;

    //Выделение памяти с помощью malloc
    double* vectorA = (double*)malloc(length * sizeof(double));
    double* vectorB = (double*)malloc(length * sizeof(double));

    double result = 0;

    clock_t start = clock();

    //Инициализация векторов
    cout << endl << "Vector A: " << endl;
    IniTVector(length, vectorA);

    cout << endl << "Vector B: " << endl;
    IniTVector(length, vectorB);


    ScalarMult(result, vectorA, vectorB);//Вычисление скалярного произведения

    //Освобождение памяти
    free(vectorA);
    free(vectorB);

    //Переводим в секунды
    clock_t endResult = clock();
    double seconds = (double)(endResult - start) / CLOCKS_PER_SEC;

    cout << endl << "Time is the end: " << seconds;
    return 0;
}

