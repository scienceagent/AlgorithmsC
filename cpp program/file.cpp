#include <iostream>
#include <string.h>
using namespace std;
char s[50];
int n;
int qq(char t[50])
{
    int i, q, b = 1;
    q = strlen(t);
    while (i < q && b)
        if (t[i] >= '0' && t[i] <= '9')
        {
            q = i;
            b = 0;
        }
        else
            i++;
    return q;
}
void cc()
{
    int k;
    for (k = 0; k < n; k++)
        s[k] = '*';
}
int main()
{
    strcpy(s, "cazb52dx7");
    n = qq(s);
    cc();
    cout << s << "\n";
    cout << n << "\n";
}