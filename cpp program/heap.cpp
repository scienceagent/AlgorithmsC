#include <iostream>
using namespace std;
//*****************************************************************
void heapify(int X[], int n, int i)
{
    int maxim = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // Dacă copilul lăsat este mai mare decât rădăcina
    if (l < n && X[l] < X[maxim])
        maxim = l;
    // Dacă copilul potrivit este mai mare decât cel mai mare până acum
    if (r < n && X[r] < X[maxim])
        maxim = r;
    // Dacă cel mai mare nu este rădăcină
    if (maxim != i)
    {
        swap(X[i], X[maxim]); // interschimb
        // Aplicăm recursiv heapify pentru sub-arborele afectat
        heapify(X, n, maxim);
    }
}
//*****************************************************************
void heapSort(int X[], int n)
{
    // Construiți heap (rearanjați masivul)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(X, n, i);
    // Extrageți unul câte unul, un element din heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Mutați rădăcina curentă la sfârit
        swap(X[0], X[i]);
        // Apelați max heapify pe heap-ul redus
        heapify(X, i, 0);
    }
}
// Funcția de afișare a masivului unidimensional
void afisareMasiv(int X[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << " ";
    }
    cout << "\n";
}
// Programul principal
int main()
{
    int X[] = {100, 80, 30, 90, 40, 50, 70};
    int n = sizeof(X) / sizeof(X[0]);
    cout << "Masivul unidimensional este: \n\t";
    afisareMasiv(X, n);
    heapSort(X, n);
    cout << "Masivul unidimensional sortat ascendent este: \n\t";
    afisareMasiv(X, n);
}