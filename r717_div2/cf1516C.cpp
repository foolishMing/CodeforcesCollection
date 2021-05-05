/*
rating：1700
status：看题解有了思路后可以AC
replay:
0、good array：将数组划分为子数组a、b，sum(a) == sum(b)
1、判断一个数组是否为good array？
一开始没想到用背包来做,其实数据量这么小，很明显是可以枚举sum值的。
2、至多去掉几个元素，使该数组无法成为good array？
这个很容易想到最多去掉一个奇数即可。
如果全为偶数，则去掉一个具有奇因子的偶数即可。
数据范围限定了不包括0，所以不用考虑全0这种特殊情况。
*/
#include<bits/stdc++.h>
using namespace std;

int a[101];
int bag[200010];

int main(){
    int n, tot = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        tot += a[i];
    }
    if(tot % 2){//can't be good array.
        cout << 0 << endl;
        return 0;
    }
    int sz = tot / 2;
    bag[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sz; j >= a[i]; j--){//if j == bag's size,calculate how many item can be contained.
            bag[j] = max(bag[j - a[i]], bag[j]);
        }
    }
    if(0 == bag[sz]){//can't be good array.
        cout << 0 << endl;
        return 0;
    }
    while(true){
        for(int i = 1; i <= n; i++){
            if(a[i]%2){
                cout << 1 << endl << i << endl;
                return 0;
            }
            else a[i] /= 2;
        }
    }
    return 0;
}
