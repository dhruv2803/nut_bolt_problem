#include <bits/stdc++.h>
using namespace std;

int partition(vector<char> &a, char pivot, int l, int u)
{
    int i = l;
    for (int j = l; j <= u - 1; j++)
    {
        if (a[j] < pivot)
        {
            char temp = a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
        else if (a[j] == pivot)
        {
            char temp = a[j];
            a[j]=a[u];
            a[u]=temp;
            j--;
        }
    }
    char temp = a[i];
    a[i]=a[u];
    a[u]=temp;
    return i;
}

void nutBoltMatch(vector<char> &a, vector<char> &b, int l, int u)
{
    if (l < u)
    {
        int pivot = partition(a, b[u], l, u);
        partition(b, a[pivot], l, u);
        nutBoltMatch(a, b, l, pivot - 1);
        nutBoltMatch(a, b, pivot + 1, u);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> a, b;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        b.push_back(temp);
    }
    nutBoltMatch(a, b, 0, n - 1);
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
    for (auto x : b)
        cout << x << ' ';
    cout << endl;
    return 0;
}