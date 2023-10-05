// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string input ,key;
    getline(cin,input);
    cin>>key;
    int len = input.size();
    int key_len = key.size();
    // cout<<len<<" "<<key_len<<endl;
    int k = 0;
    
    string res = "";
    for(int i = 0;i < len; i++){
        if(input[i] == ' ') continue;
        int new_ch = ((int)(tolower(input[i])  + key[k] - 'a' - 'a'))%26;
        char ch = (char)('a' + new_ch);
        res = res + ch;
        k = (k + 1)%key_len;
    }
    cout<<res<<endl;
    return 0;
}