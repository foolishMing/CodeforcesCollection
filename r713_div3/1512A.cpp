#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int a[maxn];

int main()
{
    int t; cin >> t;
    while(t--){
        memset(a, 0, sizeof a);
        int first,second,n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        first = a[1], second = a[2];
        for(int i = 3; i <= n; i++){
            int num = a[i];
            if(first == second && first == num)continue;
            if(first == second){
                cout << i << endl;
                break;
            }
            if(first == num){
                cout << 2 << endl;
                break;
            }
            cout << 1 << endl;
            break;
        }
    }
    return 0;
}
