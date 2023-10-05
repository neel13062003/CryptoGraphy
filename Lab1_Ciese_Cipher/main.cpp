#include <bits/stdc++.h>
using namespace std;

string solve(int n,string s){
    string ans="";

    for(int i=0;i<s.size();i++){
        if( (s[i]-'a' -n) >=0){
            ans += (s[i]-'a'-n) +'a';
        }else{
            ans += 'z'+1 + (s[i]-'a'-n);
        }
    }
    return ans;
}

int main()
{
    string s;
    int n;
    cout << "Enter String" << endl;
    cin>>s;
    cout<<"Enter Key"<<endl;
    cin>>n;
    string ans = solve(n, s);
    cout<<ans<<endl;
    return 0;
}
