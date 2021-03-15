#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> a,b;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i]==b[j])
            {
                swap(b[i],b[j]);
            }
            
        }
        
    }
    for(auto x:a)
    cout << x << ' ';
    cout << endl;
    for(auto x:b)
    cout << x << ' ';
    return 0;
    
}