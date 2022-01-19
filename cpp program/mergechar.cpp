#include <iostream>
using namespace std;
int x[20], n;
//***************************************************
void sortare(int st, int dr, char x[20])
{
    int aux;
    if (x[st] > x[dr])
    {
        aux = x[st];
        x[st] = x[dr];
        x[dr] = aux;
    }
}
//***************************************************
void interclasare(int st, int dr, int m, char x[20])
{
    int b[20], i, j, k;
    i = st;
    j = m + 1;
    k = 1;
    while (i <= m && j <= dr)
        if (x[i] <= x[j])
        {
            b[k] = x[i];
            i++;
            k++;
        }
        else
        {
            b[k] = x[j];
            j++;
            k++;
        }
    if (i <= m)
        for (j = i; j <= m; j++)
        {
            b[k] = x[j];
            k++;
        }
    else
        for (i = j; i <= dr; i++)
        {
            b[k] = x[i];
            k++;
        }
    k = 1;
    for (i = st; i <= dr; i++)
    {
        x[i] = b[k];
        k++;
    }
}
//***************************************************
void divimp(int st, int dr, char x[20])
{
    int m;
    if ((dr - st) <= 1)
        sortare(st, dr, x);
    else
    {
        m = (st + dr) / 2;
        divimp(st, m, x);
        divimp(m + 1, dr, x);
        interclasare(st, dr, m, x);
    }
}
// Funcția de afișare a masivului unidimensional
void afisareMasiv(char x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}
// Programul principal
int main()
{
    int i;
    char x[] = {'h', 'b', 'h', 'z', 'z', 'z', 't', 'q', 'a', 'n', 'a', 'q', 't', 'm'};
    int n = sizeof(x) / sizeof(x[0]);
    cout << "Masivul unidimensional este: \n\t";
    afisareMasiv(x, n);
    cout << "Masivul unidimensional sortat ascendent este: \n\t";
    divimp(0, n - 1, x);
    afisareMasiv(x, n);
}