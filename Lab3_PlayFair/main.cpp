#include <iostream>
#include <vector>
#include <utility>
using namespace std;

string solve(vector<vector<char>>& vec, string msg) {
    int n = vec.size();
    int m = vec[0].size();

    string ans = "";
    vector<pair<char, char>> vec1; // parts of what we write
    vector<pair<char, char>> ans1; // parts of what we encrypt

    char bogus = 'Z';
    for (int i = 0; i < msg.size() - 1; i++) {
        if (msg[i + 1] != msg[i]) {
            vec1.push_back({ msg[i], msg[i + 1] });
            i++;
        } else if (msg[i + 1] == msg[i]) {
            vec1.push_back({ msg[i], bogus });
            i++;
        } else {
            vec1.push_back({ msg[i], bogus });
        }
    }
    int msg_size = msg.size();
    if(msg_size%2 !=0) vec1.push_back({msg[msg_size-1],'Z'});

    for (int i = 0; i < vec1.size(); i++) {
        char first = vec1[i].first;
        char second = vec1[i].second;

        pair<int, int> first_index, second_index;
        for (int j = 0; j < vec.size(); j++) {
            for (int k = 0; k < vec[j].size(); k++) {
                if (vec[j][k] == first) first_index = { j,k };
                if (vec[j][k] == second) second_index = { j,k };
            }
        }

        //ROW SAME
        if (second_index.first == first_index.first && second_index.second != first_index.second) {
            if (second_index.second == n - 1) {
                ans1.push_back({ vec[first_index.first][(first_index.second + 1) % m], vec[second_index.first][0] });
            } else {
                ans1.push_back({ vec[first_index.first][(first_index.second + 1) % m], vec[second_index.first][(second_index.second + 1) % m] });
            }
         //COLUMN SAME
        } else if (second_index.first != first_index.first && second_index.second == first_index.second) {
            if (second_index.first == m - 1) {
                ans1.push_back({ vec[(first_index.first + 1) % n][first_index.second], vec[0][second_index.second] });
            } else {
                ans1.push_back({ vec[(first_index.first + 1) % n][first_index.second], vec[(second_index.first + 1) % n][second_index.second] });
            }
            //BOTH DIFF
        } else {
            ans1.push_back({ vec[first_index.first][second_index.second], vec[second_index.first][first_index.second] });
        }
    }

     //convert pair into final answer
    for (int i = 0; i < ans1.size(); i++) {
        ans += ans1[i].first;
        ans += ans1[i].second;
    }

    return ans;
}

int main() {
    vector<vector<char>> vec = {
        { 'F', 'G', 'H', 'I', 'J' },
        { 'A', 'B', 'C', 'D', 'E' },
        { 'V', 'W', 'X', 'Y', 'Z' },
        { 'K', 'L', 'M', 'N', 'O' },
        { 'T', 'S', 'R', 'Q', 'P' }
    };

    string msg;
    cout << "Enter Message: ";
    cin >> msg;
    string ans = solve(vec, msg);
    cout << "Encrypted Message: " << ans << endl;

    return 0;
}

/*Sample Test Case

Input =  BD
Output = CE


Input =  LS
Output = SG

Input =  WN
Output = YL
*/
/*

F G H I J
A B C D E
V W X Y Z
K L M N O
T S R Q P

*/
