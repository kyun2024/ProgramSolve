#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    char a,b;
    double score=0;
    cin >> a;
    if(a=='F'){
        cout << "0.0" << endl;
        return 0;
    }
    cin >> b;
    if(a=='A'){
        score += 4;
    }
    else if(a=='B'){
        score += 3;
    }
    else if(a=='C'){
        score += 2;
    }
    else if(a=='D'){
        score +=1 ;
    }
    if(b == '+'){
        score += 0.3;
    }
    else if(b == '-'){
        score -= 0.3;
    }
    cout << fixed << setprecision(1) << score << endl;
    return 0;
}