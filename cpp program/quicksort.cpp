#include <iostream>
using namespace std;
// Sortare ascendentă
int ShellSortAscendent(int a[], int n)
{
    for (int dec = n / 2; dec > 0; dec /= 2)
    { // dec = decajal
        for (int i = dec; i < n; i += 1)
        {
            int j, temp = a[i]; // temporar
            for (j = i; j >= dec && a[j - dec] < temp; j -= dec)
                a[j] = a[j - dec];

            a[j] = temp;
        }
    }
}
// Funcția care schimbă două elemente
void schimb(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// Partiția tabloului folosind ultimul element ca pivot
int partitionare(int X[], char start, char finish)
{
    int pivot = X[finish]; // pivot
    int i = (start - 1);
    for (int j = start; j <= finish - 1; j++)
    {
        // Dacă elementul curent este mai mare decât pivotul, creștem elementul start. Schimbăm
        if (X[j] <= pivot)
        {
            i++;
            schimb(&X[i], &X[j]);
        }
    }
    schimb(&X[i + 1], &X[finish]);
    return (i + 1);
}
// Algoritmul quickSort descendent
void QuickSortDescendent(int X[], int start, int finish)
{
    if (start < finish)
    {
        // Partișionarea masivului
        int pivot = partitionare(X, start, finish);
        // Sortăm masivul secundar independent
        QuickSortDescendent(X, start, pivot - 1);
        QuickSortDescendent(X, pivot + 1, finish);
    }
}
// Afișarea la ecran a array-ului unidimensional
void AfisareArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
// Programul principal
int main()
{
    // Vectorul de numere întregi declarat implicit
    int a[] = {45, 23, 53, 43, 18, 24, 8, 95, 101}, i;
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Array-ul inainte de sortare: \n";
    AfisareArray(a, n);
    // Aplicăm functia pentru sortarea ascendentă
    ShellSortAscendent(a, n);
    cout << "\n\nShellSort descendent:\nArray-ul sortat: ";
    AfisareArray(a, n);
    cout << endl;
    // Aplicăm functia pentru sortarea deascendentă
    QuickSortDescendent(a, 0, n - 1);
    cout << "\nQuickSort ascendent:\nArray-ul sortat: ";
    AfisareArray(a, n);
}