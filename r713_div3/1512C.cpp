/*
����д��Ҳ̫�����ˣ����������ôд�İ�
first WA :
��������"?"����������˵�һ�ִ������Ǵ���ķ�ʽ��
��Ϊ����̰��ԭ��Ӧ������ƥ����Щ��Ψһ������ԡ�
֮������Լ�������������ƥ���"?"���ٰ���a��b����������ƥ�䡣
second WA :
�����˱߽紦���ϣ���һ�ֲ���Ҫ����������������ֻ�������������������ģ���벿�־ͺ��ˡ�

*/

#include <bits/stdc++.h>
using namespace std;
bool isParl(string& s, int a, int b);
int main()
{
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        string s; cin >> s;
        if(!isParl(s, a, b)){
            cout << "-1" << endl;
        }else {
            cout << s << endl;
        }
    }
    return 0;
}

bool isParl(string& s, int a, int b)
{
    int len = s.length();
    for(int left = 0; left < len / 2; left++){
        int right = len - 1 - left;
        if(left > right) break;
        if(s[left] == '0' && s[right] == '1') return false;
        if(s[left] == '1' && s[right] == '0') return false;
        if(s[left] == '0' || s[right] == '0'){
            if(a <= 0) return false;
            a -= 2;
            if(s[left] == '?') s[left] = '0';
            if(s[right] == '?') s[right] = '0';
            continue;
        }
        if(s[left] == '1' || s[right] == '1'){
            if(b <= 0) return false;
            b -= 2;
            if(s[left] == '?') s[left] = '1';
            if(s[right] == '?') s[right] = '1';
            continue;
        }
    }
    for(int left = 0; left <= len / 2; left++){
        int right = len - 1 - left;
        if(left > right) break;
        if(left == right){
            if(s[left] == '0') a -= 1;
            if(s[left] == '1') b -= 1;
            if(s[left] == '?'){
                if(a > 0){
                    a -= 1; s[left] = '0';
                }else{
                    b -= 1; s[left] = '1';
                }
            }
            continue;
        }
        if(s[left] == '?' && s[right] == '?'){
            if(a >= 2){
                s[left] = '0'; s[right] = '0'; a -= 2;
            }
            else if(b >= 2){
                s[left] = '1'; s[right] = '1'; b -= 2;
            }
            else return false;
        }
    }
    if(!a && !b) return true;
    return false;
}

