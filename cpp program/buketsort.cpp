#include <iomanip>
#include <iostream>
using namespace std;
#define INTERVAL 10 // Capacitatea fiecarei cupe
int a[] = {42, 14, 32, 33, 17, 37, 19, 47, 51, 85};
int n = sizeof(a) / sizeof(a[0]), nCupe = n - 1;
// Structura nodului unei liste liniare simple
struct Node
{
    int data;
    struct Node *next;
};
// Crearea indecsilor pentru cupe
int BucketIndex(int valoare)
{
    return valoare / INTERVAL;
}
void AfisareCupe(struct Node *list)
{
    struct Node *curent = list;
    while (curent)
    {
        cout << setw(3) << curent->data;
        curent = curent->next;
    }
}
// Functia de a sorta elementele din fiecare cupa
struct Node *InsertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0)
    {
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0)
    {
        struct Node *ptr;
        if (nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }
        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data < k->data)
                break;
        }
        if (ptr->next != 0)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}
// Functia de sortare ascendenta
void BucketSort(int a[])
{
    int i, j;
    struct Node **cupe;
    // Cream cupe si alocam dimensiunea memoriei
    cupe = (struct Node **)malloc(sizeof(struct Node *) * nCupe);
    // Initializam cupele cu 0, goale
    for (i = 0; i < n; ++i)
    {
        cupe[i] = NULL;
    }
    // Umplem cupele cu elementele respective
    for (i = 0; i < n; ++i)
    {
        struct Node *current;
        int pos = BucketIndex(a[i]);
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = a[i];
        current->next = cupe[pos];
        cupe[pos] = current;
    }
    // Afisam cupele impreuna cu elementele lor
    cout << "\nSortarea datelor pe cupe: " << endl;
    for (i = 0; i < nCupe; i++)
    {
        cout << "\tCupa[" << i << "]: ";
        AfisareCupe(cupe[i]);
        cout << endl;
    }
    // Sortam elementele din fiecare cupa
    for (i = 0; i < nCupe; ++i)
    {
        cupe[i] = InsertionSort(cupe[i]);
    }
    cout << "\n\nCupele dupa sortare: " << endl;
    for (i = 0; i < nCupe; i++)
    {
        cout << "\tCupa[" << i << "]: ";
        AfisareCupe(cupe[i]);
        cout << endl;
    }
    // Fixam elementele sortate in array
    for (j = 0, i = 0; i < nCupe; ++i)
    {
        struct Node *node;
        node = cupe[i];
        while (node)
        {
            a[j++] = node->data;
            node = node->next;
        }
    }
    for (i = 0; i < nCupe; ++i)
    {
        struct Node *node;
        node = cupe[i];
        while (node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
        }
    }
}
// Afisarea datelor array-ului
void AfisareArray(int a[])
{
    for (int i = 9; i >= 0; i--)
    {
        cout << setw(3) << a[i];
    }
    cout << endl;
}
// Programul principal
int main()
{
    cout << "Array-ul inainte de sortare: \n";
    AfisareArray(a);
    BucketSort(a);
    cout << "\nBucketSort descendent:\nArray-ul sortat descendent: ";
    AfisareArray(a);
}