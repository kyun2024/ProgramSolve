#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//For Sort
struct gp{
    string genre;
    int plays;
    int idx;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    //For Sort
    vector<gp> v;
    vector<int> answer;
    //Dictionary
    map<string,int> M;
    //Get Genres Plays
    for(int i=0;i<genres.size();i++){
        if(M.find(genres[i])==M.end()){
            M.insert({genres[i],0});
        }
        M[genres[i]]+=plays[i];
    }
    //For Sort
    v.resize(genres.size());
    for(int i=0;i<v.size();i++){
        v[i]={genres[i],plays[i],i};
    }
    //Sort
    sort(v.begin(),v.end(),[&M](const gp &i,const gp &j){
        if(i.genre.compare(j.genre)==0){
            if(i.plays==j.plays){
                return i.idx<j.idx;
            }
            return i.plays>j.plays;
        }
        return M[i.genre]>M[j.genre];
    });
    //첫번째 원소는 무조건 저장
    answer.push_back(v[0].idx);
    if(v.size()>=2 && v[1].genre.compare(v[0].genre)==0){
        //같은 장르면 저장
        answer.push_back(v[1].idx);
    }
    //i+1의 원소를 삽입 - 장르가 다르면 넣는다
    for(int i=0;i<v.size()-1;i++){
        if(v[i].genre.compare(v[i+1].genre)!=0){
            answer.push_back(v[i+1].idx);
            //2개씩 넣을 수 있으니 조건 확인 후 넣는다
            if(i+2<v.size() && v[i+2].genre.compare(v[i+1].genre)==0){
                answer.push_back(v[i+2].idx);
            }
        }
    }
    return answer;
}