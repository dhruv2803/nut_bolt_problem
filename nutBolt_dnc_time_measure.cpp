#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int partition(vector<int> &a, int pivot, int l, int u) // this function divide array into 2 parts and set actual place of pivot element
{
    int j = l;
    for (int i = l; i < u; i++)
    {
        if (a[i] < pivot)
        {
            swap(a[i], a[j]);
            j++;
        }
        if (a[i] == pivot)
        {
            swap(a[i], a[u]);
            i--;
        }
    }
    swap(a[j], a[u]);
    return j;
}

void nutBoltMatch(vector<int> &nuts, vector<int> &bolts, int l, int u)
{
    if (l < u)
    {
        int pivot = partition(nuts, bolts[u], l, u); //taking last element of bolt array as pivot for nuts array
        partition(bolts, nuts[pivot], l, u); //taking pivot element of nut array as pivot for bolt array
        nutBoltMatch(nuts, bolts, l, pivot - 1); //repeating same process for left side of arrays
        nutBoltMatch(nuts, bolts, pivot + 1, u); //repeating same process for right side of arrays
    }
}
int main()
{

    for (int k = 1; k < 6; k++)
    {
        ifstream fin;
        fin.open("InputBolts"+to_string(k)+".txt");
        vector<int> nuts, bolts;
        int temp;
        while (!fin.eof())
        {
            fin >> temp;
            bolts.push_back(temp);
        }
        fin.close();
        fin.open("InputNutsavg"+to_string(k)+".txt");
        while (!fin.eof())
        {
            fin >> temp;
            nuts.push_back(temp);
        }
        fin.close();
        int n = nuts.size() - 1;
        auto t1 = std::chrono::high_resolution_clock::now();
        nutBoltMatch(nuts, bolts, 0, n - 1);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto durationavg = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); //Mearusing time for avg case files

        fin.open("InputBolts"+to_string(k)+".txt");
        vector<int> nuts, bolts;
        int temp;
        while (!fin.eof())
        {
            fin >> temp;
            bolts.push_back(temp);
        }
        fin.close();
        fin.open("InputNutsworst"+to_string(k)+".txt");
        while (!fin.eof())
        {
            fin >> temp;
            nuts.push_back(temp);
        }
        fin.close();
        int n = nuts.size() - 1;
        t1 = std::chrono::high_resolution_clock::now();
        nutBoltMatch(nuts, bolts, 0, n - 1);
        t2 = std::chrono::high_resolution_clock::now();
        auto durationworst = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); //Measuring time for worst case files
        ofstream fout;
        fout.open("TimeMeasureDNC.csv",ios_base::app);
        fout << n+1 << ", " << durationavg << ", " << durationworst << "\n";
        cout << k << " file complete" << endl;
        fout.close();
    }

    
    return 0;
}