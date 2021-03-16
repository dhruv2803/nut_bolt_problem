#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Please enter the number of pairs of botls and pairs : ";
    cin >> n;
    vector<char> nuts, bolts;
    cout << "PLEASE ENTER SIZES OF ALL N NUTS : "
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        nuts.push_back(temp);
    }
    cout << "PLEASE ENTER SIZES OF ALL N BOLTS : "
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        bolts.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nuts[i]==bolts[j])
            {
                swap(bolts[i],bolts[j]);
            } 
        }
        
    }
    cout << "NUTS  : " ;
    for(auto x:a)
        cout << x << ' ';
    cout << endl << "BOLTS : ";
    for(auto x:b)
        cout << x << ' ';
    cout << endl;
    return 0;
    
}
