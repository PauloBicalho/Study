#include<cstdio>
#include<iostream>
#include<string>

#include<unordered_map>

using namespace std;

string checkWindows(string str,int windowSize, unordered_map<char,int>pattern,int forMatch){
        string res;

        //check the first window
        for( int i=0; i<windowSize; i++ ){
                unordered_map<char,int>::iterator it = pattern.find(str[i]);
                res.push_back(str[i]);

                if( it != pattern.end() ){
                        if( --it->second >= 0 )
                                forMatch--;
                }

        }
        
        //pattern found in the first window
        if( forMatch <= 0 )
                return res;
        
        unordered_map<char,int>::iterator it;
        for(int i=windowSize; i<str.size(); i++){
                
                //remove the first character from the previous window
                res.erase(0,1);
                it = pattern.find( str[i-windowSize] );

                if( it != pattern.end() ){
                        if( ++it->second > 0)
                                forMatch++;
                }

                //add the current charactere into the new window
                res.push_back(str[i]);
                it = pattern.find(str[i]);

                if( it != pattern.end()  ){
                        if( --it->second >= 0 )
                                forMatch--;
                        
                        if( forMatch == 0 )
                                return res;
                }
                
        }

        return "";
}

string binarySearch(string str,unordered_map<char,int> pattern, int patternSize){
        int left = patternSize-1;
        int right = str.size();

        //if pattern not present in the entire string
        string window = checkWindows(str, right, pattern, patternSize);
        if( window.size() == 0 )
                return "";

        while( right - left > 1 ){
                int mid = left + ( (right - left)/2 );

                window = checkWindows(str, mid, pattern, patternSize);
                        
                if( window.size() > 0 )
                        right = mid;
                else
                        left = mid;
        }

        return checkWindows(str, right, pattern, patternSize);
}

string findWindow(string str, string patternString){
        int patternSize = patternString.size();

        if( patternSize > str.size() or patternSize == 0 or str.size() == 0 )
                return "";

        unordered_map<char,int> pattern;
        for (int i=0; i<patternSize; i++){
                char c = patternString[i];

                unordered_map<char,int>::iterator it = pattern.find( c );

                if( it != pattern.end() )
                        pattern[c]++;
                else
                        pattern[c] = 1;
        }


        return binarySearch(str,pattern,patternSize);
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
