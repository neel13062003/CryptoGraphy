// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

string getCipherKey(string plainText, string key)
{
    int m = key.length();
    int n = plainText.length();
    if (n * n != m)
    {
        cout << "Saale dhang se input dalde :) !";
        return "Error Occured ! Bro";
    }

    vector<vector<int>> vt(n, vector<int>(n, 0));

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vt[i][j] = key[k] - 'a';
            k++;
        }
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int x1 = vt[i][j];           // from key
            int x2 = plainText[j] - 'a'; // from plainText
            ans += (x1 * x2);
        }
        res.push_back((ans) % 26);
    }
    string result;
    for (int i = 0; i < n; i++)
    {
        result += (char)(res[i] + 'a');
    }
    return result;
}

int main()
{
    // Write C++ code here

    string plainText, key;

    cin >> plainText >> key;

    cout << getCipherKey(plainText, key);

    return 0;
}