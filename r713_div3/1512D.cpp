/*
一开始题意没读懂，这反映了我读(英文)题能力还有待加强!
*/
#include <bits/stdc++.h>
using namespace std;

void print(vector<int64_t>& vec, int idx1, int idx2){
    int sz = vec.size();
    for(int i = 0; i < sz; i++){
        if(i == idx1 || i == idx2)continue;
        printf("%lld ", vec[i]);
    }
    printf("\n");
}

int main()
{
    int t; cin >> t;
    while(t--){
        vector<int64_t>b;
        int n; cin >> n; n += 2;
        int64_t tot = 0;
        for(int i = 0; i < n; i++){
            int64_t num; cin >> num;
            b.push_back(num);
            tot += num;
        }
        sort(b.begin(), b.end());
        //b[n - 1] is 'x'
        if((tot - b[n - 1]) == b[n - 2] * 2){
            print(b, n - 2, n - 1);
            continue;
        }
        //b[n - 1] isn't 'x', then enumerate 'x' in [0,n - 1)
        bool ok = false;
        for(int i = 0; i < n - 1; i++){
            if(tot - b[i] != b[n - 1] * 2)continue;
            print(b, i, n - 1);
            ok = true;
            break;
        }
        if(!ok) cout << "-1\n";
     }
    return 0;
}
