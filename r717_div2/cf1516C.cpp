/*
rating��1700
status�����������˼·�����AC
replay:
0��good array�������黮��Ϊ������a��b��sum(a) == sum(b)
1���ж�һ�������Ƿ�Ϊgood array��
һ��ʼû�뵽�ñ�������,��ʵ��������ôС���������ǿ���ö��sumֵ�ġ�
2������ȥ������Ԫ�أ�ʹ�������޷���Ϊgood array��
����������뵽���ȥ��һ���������ɡ�
���ȫΪż������ȥ��һ�����������ӵ�ż�����ɡ�
���ݷ�Χ�޶��˲�����0�����Բ��ÿ���ȫ0�������������
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
