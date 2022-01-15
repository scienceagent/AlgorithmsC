// C++ program to sort given array
// of string stored in a file
#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

// Driver Code
int main()
{
    int n, i, j;

    // File pointer to open file
    FILE *f;

    // fopen() for creating of a file
    f = fopen("file.txt", "w");

    // Input number of strings
    // to be inserted in file
    cout << "input nr of line: ";
    cin >> n;

    vector<int> name(n);

    cout << "input content of file :  \n";
    // Insert the strings into file
    for (i = 0; i < n; i++)
    {

        // Insert names in file
        cin >> name[i];

        // Writing into the file
        fprintf(f, "%s", name[i]);
    }

    // Close the file
    fclose(f);

    // Reopening in read mode
    f = fopen("file.txt", "r");

    // Check does file exist or not
    if (f == NULL)
    {
        cout << "File doesn't exist!";
        return 0;
    }

    // Read the file until it
    // encounters end of line
    while (!feof(f))
    {
        fscanf(f, "%s", name[i]);
        i++;
    }
    n = i - 1;

    // Sort the strings
    sort(name.begin(), name.end());

    // Insert the strings into file
    // after sorting
    for (i = 0; i < n; i++)
    {

        // Write into the file
        fprintf(f, "%s", name[i]);
    }

    // Print the sorted names
    for (i = 0; i < n; i++)
    {
        cout << name[i] << '\n';
    }

    return 0;
}