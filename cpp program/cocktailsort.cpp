#include <iostream>
using namespace std;
// Functia de sortare ascendenta
void CocktailSort(int a[], int n)
{
    bool Schimbat = true;
    int s = 0, d = n - 1;
    while (Schimbat)
    {
        // resetați semnalizatorul schimbat la intrarea în buclă, deoarece ar putea fi
        Schimbat = false;
        // bucla de la stânga la dreapta la fel ca BubbleSort
        for (int i = s; i < d; ++i)
        {
            if (a[i] < a[i + 1])
            { // ascendent
                // swap inseamna interschimbare
                swap(a[i], a[i + 1]);
                Schimbat = true;
            }
        }
        // dacă nu s-a mutat nimic, atunci este sortat.
        if (!Schimbat)
            break;
        // în caz contrar, resetam semnalizatorul schimbat astfel încât să poată fi

        Schimbat = false;
        // mutați punctul final înapoi cu unul, deoarece elementul de la sfârșit se
        --d;
        // de la dreapta la stânga, făcând aceeași comparație ca în etapa anterioară
        for (int i = d - 1; i >= s; --i)
        {
            if (a[i] < a[i + 1])
            { // ascendent
                swap(a[i], a[i + 1]);
                Schimbat = true;
            }
        }
        ++s;
    }
}
int DecalajNou(int d)
{
    d = (d * 10) / 13; // d inseamna decalajul
    if (d == 9 || d == 10)
        d = 11;
    if (d < 1)
        d = 1;
    return d;
}
// Functia de sortare descendenta
void CombSortDescendent(int a[], int n)
{
    int d = n, temp, i;
    for (;;)
    {
        d = DecalajNou(d);
        int Schimbat = 0;
        for (i = 0; i < n - d; i++)
        {
            if (a[i] > a[i + d])
            { // descendent
                temp = a[i];
                a[i] = a[i + d];
                a[i + d] = temp;
                Schimbat = 1;
            }
        }
        if (d == 1 && !Schimbat)
            break;
    }
}
// Afisarea array-ului
void AfisareArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// Programul principal
int main()
{
    int a[] = {5, 1, 4, 2, 8, 0, 2, 7, 3, 4, 6}, n = sizeof(a) / sizeof(a[0]);
    cout << "Array-ul initial pentru sortare:\n";
    AfisareArray(a, n);
    CocktailSort(a, n);
    cout << "\nCocktailSort:\nArray-ul sortat ascendent:\n\t";
    AfisareArray(a, n);
    CombSortDescendent(a, n);
    cout << "\nCombSort:\nArray-ul sortat descendent:\n\t";
    AfisareArray(a, n);
}