#include <iostream>
#include <string>

using namespace std;

int main(){
    string in_st, out_st;
    cin >> in_st;
    if(in_st[0]>='4'){
        out_st += '0'+(bool)((in_st[0]-'0')&4);
        out_st += '0'+(bool)((in_st[0]-'0')&2);
        out_st += '0'+(bool)((in_st[0]-'0')&1);
    }
    else if(in_st[0]>='2'){
        out_st += '0'+(bool)((in_st[0]-'0')&2);
        out_st += '0'+(bool)((in_st[0]-'0')&1);
    }
    else{
        out_st += '0'+(bool)((in_st[0]-'0')&1);
    }
    for(int i=1;i<in_st.length();i++){
        out_st += '0'+(bool)((in_st[i]-'0')&4);
        out_st += '0'+(bool)((in_st[i]-'0')&2);
        out_st += '0'+(bool)((in_st[i]-'0')&1);
    }
    cout << out_st << endl;
    return 0;
}