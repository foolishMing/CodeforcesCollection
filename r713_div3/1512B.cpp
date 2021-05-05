/*
感觉我写的方法比较麻烦
*/
#include <bits/stdc++.h>
using namespace std;

char ch[401][401];
void print(int x2, int y2, int x3, int y3, int n);
int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>>vec;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            for(int j = 0; j < n; j++){
                ch[i][j] = s[j];
                if(s[j] == '*'){
                    vec.push_back(pair<int,int>(i,j));
                }
            }
        }
        int x0 = vec[0].first, y0 = vec[0].second;
        int x1 = vec[1].first, y1 = vec[1].second;
        //line
        if(x0 == x1){
            if(x0 == 0){
                print(x0 + 1, y0, x1 + 1, y1, n);
            }else{
                print(x0 - 1, y0, x1 - 1, y1, n);
            }
            continue;
        }
        if(y0 == y1){
            if(y0 == 0){
                print(x0, y0 + 1, x1, y1 + 1, n);
            }else{
                print(x0, y0 - 1, x1, y1 - 1, n);
            }
            continue;
        }
        //diagonal, left to right
        if(y0 < y1){
            print(x1, y0, x0, y1, n);
            continue;
        }
        //diagonal, right to left
        print(x0, y1, x1, y0, n);
    }
    return 0;
}
void print(int x2, int y2, int x3, int y3, int n)
{
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(i == x2 && j == y2){
            ch[i][j] = '*';
        }else if(i == x3 && j == y3){
            ch[i][j] = '*';
        }
        printf("%c", ch[i][j]);
        if(j == (n - 1)) cout << endl;
    }
}
