#include <bits/stdc++.h>
using namespace std;


//msg = abead
//key = nekl
//answer = neknd

string solve(string msg,string key){
    string ans ="";

    map<char,char>mp;
    for(int i=0;i<key.size();i++){
        if( mp.find(msg[i]) == mp.end() ){
            mp[msg[i]] = key[i];
        }else{
            continue;
        }
    }

    for(int i=0;i<msg.size();i++){
        if( mp.find(msg[i]) != mp.end()  ){
            ans+= mp[msg[i]];
        }else{
            ans += msg[i];
        }
    }

    return ans;
}

int main()
{
    string msg,key;
    cout << "Enter Msg" << endl;
    cin>>msg;
    cout<<"Enter Key"<<endl;
    cin>>key;

    string ans = solve(msg,key);
    cout<<ans<<endl;
    return 0;
}
