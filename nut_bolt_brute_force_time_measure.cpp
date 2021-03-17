#include <bits/stdc++.h>
using namespace std;

void nutBoltMatch(vector<int> &a,vector<int> &b,int n)
{
    for(int i=0;i<n;i++) //taking elements from nuts
    {
        for(int j=i;j<n;j++) //taking elements from bolts
        {
            if (a[i]==b[j]) //compareing each nut to each bolt
            {
                swap(b[i],b[j]);
            }
            
        }
    }
}

int main()
{
    for (int k = 1; k < 7; k++)
    {
        ifstream fin;
        fin.open("InputNutsavg" + to_string(k) + ".txt");
        vector<int> nuts, bolts;
        while(!fin.eof())
        {
            int temp;
            fin >> temp;
            nuts.push_back(temp);
        }
        fin.close();

        fin.open("InputBolts"+to_string(k)+".txt");
        while(!fin.eof())
        {
            int temp;
            fin >> temp;
            bolts.push_back(temp);
        }
        fin.close();
        int n = nuts.size();
        auto t1 = std::chrono::high_resolution_clock::now();
        nutBoltMatch(nuts,bolts,n);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto durationavg = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); //calculating time

        nuts.clear();
        bolts.clear();
        fin.open("InputNutsworst" + to_string(k) + ".txt");

        while(!fin.eof())
        {
            int temp;
            fin >> temp;
            nuts.push_back(temp);
        }
        fin.close();

        fin.open("InputBolts"+to_string(k)+".txt");
        while(!fin.eof())
        {
            int temp;
            fin >> temp;
            bolts.push_back(temp);
        }
        fin.close();
        t1 = std::chrono::high_resolution_clock::now();
        nutBoltMatch(nuts,bolts,n);
        t2 = std::chrono::high_resolution_clock::now();
        auto durationworst = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); //calculating time
        
        ofstream fout;
        fout.open("TimeMeasureBruteForce.csv",ios_base::app);
        fout << n << ", " << durationavg << ", " << durationworst << "\n";
        fout.close();
    }
    return 0;
}