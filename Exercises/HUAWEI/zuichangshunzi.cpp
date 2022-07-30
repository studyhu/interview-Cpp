#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <time.h>

using namespace std;

/*
最多12张牌（3-A）。
输入1：手上已经有的牌
输入2：已经出过的牌（包括对手出的和自己出的牌）
输出：对手可能构成的最长的顺子（如果有相同长度的顺子，输出牌面最大的那一个），如果无法构成顺子，则输出NO-CHAIN

eg:
输入：3-3-3-3-4-4-5-5-6-7-8-9-10-J-Q-K-A
            4-5-6-7-8-8-8
输出：9-10-J-Q-K-A
输入：3-3-3-3-8-8-8-8
            K-K-K-K
输出：NO-CHAIN
*/

vector<string> pai = {"3","4","5","6","7","8","9","10","J","Q","K","A"};

void stringSplit(string str, const char split, vector<string>& v){
    istringstream iss(str);
    string token;
    while (getline(iss, token, split)){
        v.push_back(token);
    }
}

void maxChain(vector<string>& v1, vector<string>& v2){
    map<string, int> m;
    for(auto item : v1) m[item]++;
    for(auto item : v2) m[item]++;
    int maxLen = 0;
    int pos;
    for(int len = 5; len<13; len++){ //遍历长度
        for(int i = 0; i< 13-len; i++){ //遍历起始位置
            bool ok = true;
            for(int j = 0; j<len; j++){
                if(m[pai[j+i]]>=4){
                    ok = false;
                    break;
                }
            }
            if(ok){
                maxLen = len;
                pos = i;
            }
        }
    }
    if(maxLen==0) cout<<"NO-CHAIN"<<endl;
    else{
        for(int i = 0; i<maxLen; i++){
            if(i != maxLen-1) cout << pai[pos+i] << '-';
            else cout << pai[pos+i] << endl;
        }
    }
}

void maxChain_dp(vector<string>& v1, vector<string>& v2){
    map<string, int> m;
    for(auto item : v1) m[item]++;
    for(auto item : v2) m[item]++;
    int arr[2] = {0,0}; // 起始位置, 最大长度
    vector<vector<int>> dp(13,vector<int>(13,0));
    for(int i = 1; i<13; i++){
        for(int j = i; j<13; j++){
            if(m[pai[j-1]]>=4){
                i = j;
                break;
            }
            else{
                dp[i][j] = dp[i][j-1]+1;
                if(dp[i][j]>arr[1]){
                    arr[1] = dp[i][j];
                    arr[0] = i;
                }
            }
        }
    }
    if(arr[1]<5) cout<<"NO-CHAIN"<<endl;
    else{
        for(int i = 0; i<arr[1]; i++){
            if(i != arr[1]-1) cout << pai[arr[0]-1+i] << '-';
            else cout << pai[arr[0]-1+i] << endl;
        }
    }
}

int main(){
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<string> v1;
    vector<string> v2;
    stringSplit(s1, '-', v1);
    stringSplit(s2, '-', v2);

    clock_t start,end;//定义clock_t变量
    start = clock();//开始时间
    maxChain_dp(v1,v2);
    end = clock();//结束时间
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;//输出时间（单位：ｓ）
    return 0;
}