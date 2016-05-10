#include <string>
#include <unordered_map>
#include <iostream>
#include <cassert>

using namespace std;

typedef unordered_map<char, int> myHash;

bool moveRight(const string& source, myHash& hmiss, int& right, int &miss)
{
    if( miss == 0 ) { return true;}  
    while(++right < source.size() ){
        auto im = hmiss.find(source[right]);
        if(im != hmiss.end()){
            --(im->second);
            if(im->second >= 0) {
                --miss;
                if(miss == 0){ return true;}
            }
        }
    }

    return false;
}

void moveLeft(const string& source, myHash& hmiss, int& left, int &miss){

    while(++left < source.size()){
        auto im = hmiss.find(source[left-1]);
        if(im != hmiss.end()){
            ++(im->second);
            if(im->second > 0) {
                ++miss;
                if(miss > 0){
                    break;
                }
            }
        }

    }
}

pair<int, int> windowMatch(const string& source, const string& pattern){

    pair<int, int> pm(-1, -1);
    if(source.size() < pattern.size() || source.empty()){
        return pm;
    }
    myHash hmiss;
    for(char s : pattern){    
        auto it = hmiss.find(s);
        if(it == hmiss.end()){
            hmiss.insert(pair<int,int>(s, 1)); //guarda as chaves do padrao

        }else{
            ++(it->second);
        }

     }
    
    int minp = source.size()+1;

    int right = -1;
    int left = 0;
    int miss = pattern.size();

    while(left < source.size() - pattern.size()){
        if(moveRight(source, hmiss, right, miss)){
            moveLeft(source, hmiss, left, miss);
            if(minp > right - left + 2){
                minp = right - left + 2;
                pm.first = left - 1;
                pm.second = right;
            }
        }else{
            break;

        }

    }

    return pm;
}

int main(int argc, char *argv[]){
       int len=0;
       cin >> len;

       for( int i=0; i<len; i++){
               string str,patternString;
               cin >> patternString;
               cin >> str;
                
               pair<int,int> t =  windowMatch(str, patternString);
               cout << str.substr(t.first, t.second-t.first+1) << "\n";
       }

}
