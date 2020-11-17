#include <iostream>
#include <vector>

using namespace std;

int v[100001];
int memo_max[262144];
int memo_min[262144];

int find_s, find_e;
int bit_max(int i){
    int s,e;
    int f_n = (i&-i);
    s = i/(f_n*2)*f_n+1;
    e = s+f_n-1;
    if(find_s>e || find_e<s)return 0;
    //cout << i << " " << f_n << " " << s << " " << e << " " << v[memo_max[i]] << endl;
    if(find_s<=s && e <= find_e)return memo_max[i];
    int left_i, right_i;
    left_i = bit_max(i-f_n/2);
    right_i = bit_max(i+f_n/2);
    //cout << i << " " << left_i << " " << right_i << endl;
    if(left_i == 0 && right_i == 0){
        // ??? what
        return 0;
    }
    else if(left_i == 0){
        return right_i;
    }
    else if(right_i == 0){
        return left_i;
    }
    else{
        if(v[left_i]>v[right_i]){
            return left_i;
        }
        else{
            return right_i;
        }
    }
}

int bit_min(int i){
    int s,e;
    int f_n = (i&-i);
    s = i/(f_n*2)*f_n+1;
    e = s+f_n-1;
    if(find_s>e || find_e<s)return 0;
    //cout << i << " " << f_n << " " << s << " " << e << " " << v[memo_max[i]] << endl;
    if(find_s<=s && e <= find_e)return memo_min[i];
    int left_i, right_i;
    left_i = bit_min(i-f_n/2);
    right_i = bit_min(i+f_n/2);
    //cout << i << " " << left_i << " " << right_i << endl;
    if(left_i == 0 && right_i == 0){
        // ??? what
        return 0;
    }
    else if(left_i == 0){
        return right_i;
    }
    else if(right_i == 0){
        return left_i;
    }
    else{
        if(v[left_i]<v[right_i]){
            return left_i;
        }
        else{
            return right_i;
        }
    }
}

unsigned int height(int i){
    i |= (i>>1);
    i |= (i>>2);
    i |= (i>>4);
    i |= (i>>8);
    i |= (i>>16);
    return i - (((unsigned int)i)>>1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    int i,x,f_n;
    cin >> n >> k;
    int h=height(n)*2;
    //cout << h << endl;
    for(i=1;i<=n;i++){
        cin >> v[i];
        x = 2*i-1;
        while(x<2*h){
            
            if(memo_max[x]==0)
            {
                memo_max[x]=i;
            }
            else{
                if(v[memo_max[x]]<v[i]){
                    memo_max[x]=i;
                }
            }
            if(x==h)break;
            f_n = (x&-x);
            if((x&(2*f_n))==0){
                x = x+f_n;
            }
            else{
                x = x-f_n;
            }
        }
        x = 2*i-1;
        while(x<2*h){
            if(memo_min[x]==0){
                memo_min[x]=i;
            }
            else{
                if(v[memo_min[x]]>v[i]){
                    memo_min[x]=i;
                }
            }
            if(x==h)break;
            f_n = (x&-x);
            if((x&(2*f_n))==0){
                x = x+f_n;
            }
            else{
                x = x-f_n;
            }
        }
    }
    // for(i=1;i<2*h;i++){
    //     cout << memo_max[i] << " ";
    // }
    // cout << endl;
    // for(i=1;i<2*h;i++){
    //     cout << memo_min[i] << " ";
    // }
    // cout << endl;
    for(i=1;i<=k;i++){
        cin >> find_s >> find_e;
        cout << v[bit_min(h)] << " " << v[bit_max(h)] << '\n';
    }
    return 0;
}