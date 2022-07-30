#include <iostream>
#include <vector>

using namespace std;

/*
题目描述
依次向栈存入6、1、2、3，当存入6、1、2时，栈底至栈顶依次为6、1、2；当存入3时，
3=2+1,3、2、1全部出栈，重新入栈元素6(6=2*3)，此时栈中有元素6；因为6=6，所
以两个6全部出栈，存入12，最终栈中只剩一个元素12。
输入描述：
使用单个空格隔开的正整数的字符串，如"5 6 7 8"，左边的数字先入栈，输入的正整
数个数为x,1<=x<=1000。
输出描述
最终栈中存留的元素值，元素值使用空格隔开，如"8 7 6 5"，
栈顶数字在左边。
输入
5 10 20 50 85 1
输chu
1 170
*/


int main(){
    vector<int> v;
    int temp;
    while(cin>>temp){
        v.push_back(temp);
        if(cin.get() == '\n') break;
    }
    vector<int> res;
    for(auto item : v){
        res.push_back(item);
        int len = res.size();
        int sum = 0;
        for(int i = len - 2; i>=0; i--){
            sum += res[i];
            if(sum < item){
                continue;
            }
            else if(sum == item){
                item = 2*item;
                if(i>0 && res[i-1]==item){
                    sum = 0; //需要置0
                    continue;
                }
                else{
                    res.erase(res.begin()+i,res.end());
                    res.push_back(item);
                    break;
                }
            }
            else break;
        }
    }
    cout << "results:" << endl;
    for(int i = res.size()-1; i>=0; i--) cout << res[i] << ' ';
    cout << endl;

    return 0;
}