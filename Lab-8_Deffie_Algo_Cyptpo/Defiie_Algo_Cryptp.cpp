#include <bits/stdc++.h>
using namespace std;
int main(){
    long long P=23,G=9;
    long long a=4,b=3;
    long long x = (long long)pow(G,a)%P;
    long long y = (long long)pow(G,b)%P;

    long long ka =(long long) pow(y,a)%P;
    long long kb =(long long) pow(x,b)%P;

    
    cout<<"Shared Key(A) is: " <<ka<<endl;
    cout<<"Shared Key(B) is: " <<kb<<endl;

    if(ka == kb) cout<<"Our Key Works Both side"<<endl;
    else cout<<"Not worked"<<endl;
}