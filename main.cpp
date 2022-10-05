#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "time.h"
#include <fstream>
#include <string>
using namespace std;

double go(string path, double** a, double** b, double** c, int N)
{
    a = new double* [N];
    //cout << "Ввод элементов первой матрицы..." << endl;
    for (int i = 0; i < N; i++)
    {
        a[i] = new double[N];
        for (int j = 0; j < N; j++)
        {
            a[i][j] = rand() % 10;
        }
    }
    ofstream fout;
    fout.open(path + "A.txt");
    //fout << N << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) //запись элементов первой матрицы
            fout << a[i][j] << ' ';
        fout << '\n';
    }
    fout.close();
    //cout << "comlete write file A.txt!\n";





    ifstream fin;
    fin.open(path + "A.txt");
    //fin >> Na;
    double** A = new double* [N];
    //int Af[N][N];
    //cout << "new A: \n";
    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N];
        for (int j = 0; j < N; j++) //чтение элементов первой матрицы
        {
            fin >> A[i][j];
            //cout << Af[i][j] << ' ';
        }
        //cout << "\n";
    }
    fin.close();



    b = new double* [N];
    //cout << "Ввод элементов второй матрицы..." << endl;
    for (int i = 0; i < N; i++)
    {
        b[i] = new double[N];
        for (int j = 0; j < N; j++)
        {
            b[i][j] = rand() % 10;
        }
    }

    fout.open(path + "B.txt");
    //fout << N << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) //запись элементов второй матрицы
            fout << b[i][j] << ' ';
        fout << '\n';

    }
    fout.close();
    //cout << "comlete write file B.txt!\n";


    fin.open(path + "B.txt");
    //int Bf[N][N];
    double** B = new double* [N];
    //cout << "new B: \n";
    for (int i = 0; i < N; i++)
    {
        B[i] = new double[N];
        for (int j = 0; j < N; j++) //чтение элементов второй матрицы
        {
            fin >> B[i][j];
        }
    }
    fin.close();
    //cout << "complete read files!\n";


    // Умножение матриц
    c = new double* [N];
    size_t count = 0;
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        //cout << count++;
        c[i] = new double[N];
        for (int j = 0; j < N; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < N; k++)
                c[i][j] += A[i][k] * B[k][j];
        }
    }
    double result_time = double(clock() - start) / CLOCKS_PER_SEC;
    //cout << endl << "Calculation time:" << result_time << " seconds" << endl;
    // Вывод матрицы произведения
    //cout << "Матрица произведения посчитана!" << endl;
    fout.open(path + "C.txt");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) //запись элементов
            fout << c[i][j] << ' ';
        fout << '\n';
    }
    fout.close();

    return result_time;
}

int main()
{
    int N = 500;
    double** a = NULL, ** b = NULL, ** c = NULL;
    system("chcp 1251");
    system("cls");

    ofstream fiout;
    fiout.open("log.txt");
    for (int i = 0; i < 9; i++)
    {
        string path = "matrix/" + to_string(N) + "/";
        fiout << N;
        fiout << '\n';
        fiout << "Calculation time for " << N << '*' << N << " matrix = " << go(path, a, b, c , N) << " seconds\n";
        N += 250;
        cout << i+1 << endl;
    }
    

    fiout.close();

    return 0;
}