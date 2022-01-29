#include <iomanip>
#include <iostream>
using namespace std;
int a[] = {10, 21, 21, 32, 48, 32, 12, 46};
int n = sizeof(a) / sizeof(a[0]);
// Functie pentru a obtine valoarea maxima din a[]
int ValoareMax(int a[], int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
int maxim = ValoareMax(a, n); // Gasim numarul maxim
// Functia care face numararea sortarilor din a[] in functie de cifra reprezentata de
void CountingSortDesc(int a[], int n, int exp)
{
    int b[n], i, num1[10] = {0}, m = 0;
    // cout << "\nAfisam suma cumulativa: " << endl;
    for (i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];
    while (m / exp > 0)
    {
        int bucket[10] = {0};
        for (i = 0; i < n; i++)
            bucket[9 - a[i] / exp % 10]++; // changed this line
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--)
            b[--bucket[9 - a[i] / exp % 10]] = a[i]; // changed this line
        for (i = 0; i < n; i++)
        {
            a[i] = b[i]; // changed this line
        }
        exp *= 10;
    }
}
// Funcția ascendent
void CountingSortAsc(int a[], int n, int exp)
{
    int b[n], i, num1[10] = {0};
    // cout << "\nAfisam suma cumulativa: " << endl;
    for (i = 0; i < n; i++)
        num1[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
    {
        num1[i] += num1[i - 1];
        // cout << setw(5) << num1[i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        b[num1[(a[i] / exp) % 10] - 1] = a[i];
        num1[(a[i] / exp) % 10]--;
    }
    cout << endl;
    // Copiaem array-ul b[] în a[], astfel incat a[] sa contina acum numere sortate in
    for (i = 0; i < n; i++)
        a[i] = b[i];
}
// Functia Radix Sort Asc
void RadixSortAscendent(int a[], int n)
{
    // Efectuam CountingSort pentru fiecare cifra și retinem ca in loc sa trecem
    for (int exp = 1; maxim / exp > 0; exp *= 10)
        CountingSortAsc(a, n, exp);
}
// Funcția Radix Sort
void RadixSortDescendent(int a[], int n)
{
    // Efectuam CountingSort pentru fiecare cifra și retinem ca in loc sa trecem
    for (int exp = 1; maxim / exp > 0; exp *= 10)
        CountingSortDesc(a, n, exp);
}
// Afisarea datelor array-ului
void AfisareArray(int a[])
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}
int main()
{
    cout << "Array-ul inainte de sortare: \n";
    AfisareArray(a);
    RadixSortDescendent(a, n);
    cout << "\nElementele sortate descendent prin RadixSort: \n";
    AfisareArray(a);

    RadixSortAscendent(a, n);
    cout << "\nElementele sortate ascendent prin RadixSort: \n";
    AfisareArray(a);
}