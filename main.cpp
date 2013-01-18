//ver. 1.0 23.06.12 14:55 by Alexeenko Vsevolod
#include <iostream>
#include <cmath>
#define s 10

using namespace std;
int find(int *, int, int, int);
int finds(int *, int, int, int);

int main()
{
    int mass[s]={1,2,2,3,3,3,4,5,6,6}, n;
    for (int i(0); i<s; i++)
    {
        cout << " " << mass[i];
    }
    cout << "\nEnter a number" << endl;
    cin >> n;
    n = finds(mass, n, 0, s);
    if (n == (-1))
        cout << "Not fuond" << endl;
    else
        cout << "Num elem = " << n << endl;
    return 0;
}

int find (int *m, int n, int a, int b)
{
    if ((m[a] > n) || (m[b - 1] < n))
    n= (-1);
    else
    n = find(m, n, a, b);
    return n;
}

int finds(int *m, int n, int a, int b)
{
    int size(b-a), i;
    if (size == 0)
        i = a;
    else
        i = ceil((size/2))+a;

    if (m[i] != n)
{
            if (size == 0)
                i = (-1);
        else
                if (m[i] > n)
                {
                    b = i-1;
                    i=finds(m, n, a, b);
                }
        else
                {
                    a = i+1;
                    i=finds(m, n, a, b);
                }
        }
    else
    {
       while (m[i-1] == m[i])
           i--;
    }
    return i;
}
