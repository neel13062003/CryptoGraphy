    // Online C++ compiler to run C++ program online
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string str;
        getline(cin,str);
    
        int n ;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];

        int row_len = str.size()/n;
        int k=0;
        vector<vector<char>>matrix(row_len,vector<char>(n,'.'));
        for(int i=0;i<row_len;i++){
            for(int j=0;j<n;j++){
                if(isspace(str[k])){
                    j--;
                    k++;
                    continue;
                }
                if(k == str.size()) break;
                matrix[i][j] = str[k];
                k++;
            }
        }

        string ans= "";
        for(int i=0;i<n;i++){
            int colindex = vec[i] - 1;
            for(int j=0;j<row_len;j++){
                if(matrix[j][colindex] == '.') break;
                ans += matrix[j][colindex];
            }
        }
        cout<<ans<<endl;
        return 0;
    }