#include<cstdio>
#include<iostream>
#include<string>

#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

string findWindow(string str, string patternString){
        int missingMatch = patternString.size();

        if( missingMatch > str.size() or missingMatch == 0 or str.size() == 0 )
                return "";

        unordered_map<char,int> elementCount;
        unordered_map<char, queue< int > > elementOcurrences;

        for (int i=0; i<patternString.size(); i++){
                char c = patternString[i];
                unordered_map<char,int>::iterator it = elementCount.find( c );

                if( it != elementCount.end() )
                        elementCount[c]++;
                else
                        elementCount[c] = 1;
        }
        
        int left=0;
        int bestWindowSize = str.size()-left+2;

        unordered_set<int> removed;
        queue<int> positions;
        for(int i=0; i<str.size(); i++){
                char c = str[i];
                unordered_map<char,int>::iterator it = elementCount.find( c );

                if( it != elementCount.end() ){
                        positions.push(i);
                        elementOcurrences[c].push( i );

                        if( it->second <= 0 ){
                                removed.insert( elementOcurrences[c].front() );
                                elementOcurrences[c].pop();
                        }

                        if( --(it->second) >= 0 ){
                                missingMatch--;
                        }

                        if( missingMatch == 0 ){
                                while( removed.find( positions.front() ) != removed.end() )
                                        positions.pop();

                                int windowSize = positions.back() - positions.front() + 1;
                                if( bestWindowSize > windowSize ){
                                        bestWindowSize = windowSize;
                                        left = positions.front();
                                }
                        }
                }
        }
        return str.substr(left,bestWindowSize);
}

int main(int argc, char *argv[]){
        int len=0;
        cin >> len;

        for( int i=0; i<len; i++){
                string str,patternString;
                cin >> patternString;
                cin >> str;

                cout << findWindow(str,patternString) << "\n";
        }
}
