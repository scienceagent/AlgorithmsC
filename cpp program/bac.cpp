#include <iostream>
int m, a, b, c;
int main()
{
    a = 3;
    b = 2;
    c = 9;
    if (a * a == b || a * a == c)
        m = a;
    if (b * b == c || b * b == a)
        m = b;
    if (c * c == a || c * c == b)
        m = c;
    std::cout << m;
    return 0;
}

#include <iostream>
int a = -2, b = -4, c;
char z;
int main()
{
    if (a * b > 0)
    {
        c = (a + b) / 2;
        if (c > 0)
            z = 'R';
        else
            z = 'L';
    }
    else
    {
        c = -(a * b);
        if (c < 10)
            z = 'S';
        else
            z = 'B';
    }
    std::cout << z;
    return 0;
}

#include <iostream>
using namespace std;
int i = 0;
int main()
{
    int n = 10;
    while (i < n)
    {
        cout << i + n << ' ';
        i++;
        n--;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = 1; i < n; i++)
        cout << "#";
    return 0;
}