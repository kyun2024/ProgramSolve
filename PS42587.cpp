#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    //For Sorted List
    vector<int> sv(priorities);
    sort(sv.begin(),sv.end(),[](const int& a,const int& b){return a>b;});
    int answer = 0;
    int i=0;
    //priorities를 계속 돌면서 출력 순서와 맞으면 출력함
    for(i=0;;i=(i+1)%priorities.size()){
        //출력하는 조건
        if(priorities[i]==sv[answer]){
            answer+=1;
            //출력한 문서가 우리가 찾는 위치에 있던 문서면 끝
            if(i==location)break;
        }
    }
    return answer;
}