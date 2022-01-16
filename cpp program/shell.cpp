#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

// shellsort ascendent
int shellSort(string arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            string temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].compare(temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void swap(string *a, string *b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

int partition(string arr[], int low, int high)
{
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// quicksort descendent
void quickSort(string arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ifstream in;
    in.open("quicksort.in");
    ofstream out;
    out.open("quicksort.out");
    string arr[20];
    int n = 0;
    while (in >> arr[n])
        n++;
    in.close();
    cout << "Array-ul inainte de sortare: ";
    print(arr, n);
    cout << "\n";
    shellSort(arr, n);
    cout << "Shell Sortat ascendent: ";
    print(arr, n);
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Quick sortat descendent: ";
    print(arr, n);

    return 0;
}