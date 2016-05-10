#include<cstdio>
#include<iostream>

#include<vector>
#include<string>

using namespace std;

class StringTokenizer{
        private:
                int current;
                vector<string> tokens;

        public:
                StringTokenizer(const string str, char delimiter=' '){
                        current = -1;
                        int left=0, right=0;

                        while( left < str.size() ){
                                while(left < str.size() and str[left] == delimiter) left++;

                                right = left;
                                while(right < str.size() and str[right] != delimiter) right++;

                                if( left < str.size() )
                                        tokens.push_back( str.substr(left, right-left) );

                                left = right;
                        }

                }

                string next(){
                        return ++current < tokens.size() ? tokens[current] : "";
                }

                bool has_next(){
                        return (current+1) < tokens.size();
                }

};


int main(){

        StringTokenizer tok("You shall not pass");
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
        
        cout << "------------------------------\n";
        tok =  StringTokenizer("Youshallnotpass");
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
       
        cout << "------------------------------\n";
        tok =  StringTokenizer("     ");
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
        

        cout << "------------------------------\n";
        tok =  StringTokenizer("");
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
        
        cout << "------------------------------\n";
        tok =  StringTokenizer("          You     shall        n o t        pass               ");
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
        
        cout << "------------------------------\n";
        tok =  StringTokenizer("You,shall,not,pass",',');
        while( tok.has_next() ){
                cout <<  "# " << tok.next() << "\n";
        }
}
