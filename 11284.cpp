#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

char choi[][4]={"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"};

char jung[][4]={"ㅏ","ㅐ","ㅑ","ㅒ","ㅓ","ㅔ","ㅕ","ㅖ","ㅗ","ㅘ","ㅙ","ㅚ","ㅛ","ㅜ","ㅝ","ㅞ","ㅟ","ㅠ","ㅡ","ㅢ","ㅣ"};

char jong[][4]={"","ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"};
ostream& print_uni(ostream& os,int code){
    char c;
    c = 0b1110'0000 + ((0b1111)&(code>>12));
    os << c;
    c = 0b1000'0000 + ((0b0011'1111)&(code>>6));
    os << c;
    c = 0b1000'0000 + ((0b0011'1111)&code);
    os << c;
    return os;
}

int main()
{
    char c1[4],c2[4],c3[4];
    cin.getline(c1,4);
    cin.getline(c2,4);
    cin.getline(c3,4);
    int i,j,k;
    for(i=0;i<19;i++){
        if(strcmp(c1,choi[i])==0)break;
    }
    for(j=0;j<21;j++){
        if(strcmp(c2,jung[j])==0)break;
    }
    for(k=0;k<28;k++){
        if(strcmp(c3,jong[k])==0)break;
    }
    int code = 0xAC00+i*21*28+j*28+k;
    print_uni(cout,code);
    cout << endl;
    return 0;
}