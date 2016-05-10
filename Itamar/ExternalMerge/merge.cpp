#include<iostream>
#include<vector>

using namespace std;

int max = 2;


void push_all(vector<int>&dest,const vector<int>&source, int start){
        int i = start;
        while( i++ < source.size() ){
                dest.push_back( source[i-1] );
        }

}


vector<int> mergeSort(const vector<int>& v, int l, int r ){
        if( l == r ){
                return vector<int>(1,v[l]);
        }

        int mid = l + ( (r-l) / 2 );
        
        vector<int> left  = mergeSort(v,l,mid);
        vector<int> right = mergeSort(v,mid+1,r);

        vector<int> ret;
        int lIndex = 0;
        int rIndex = 0;

        for( int i=0; i<r-l+1; i++ ){

                if( left[lIndex] <= right[rIndex] ){
                        ret.push_back( left[lIndex++] );
                        if( lIndex == left.size() ){
                                push_all(ret,right,rIndex);
                                break;
                        }
                } else{
                        ret.push_back( right[rIndex++] );
                        if( rIndex == right.size() ){
                                push_all(ret,left,lIndex);
                                break;
                        }
                }
        }

        for( int i=0; i<ret.size(); i++ )
                cout << ret[i] << " ";
        cout << "\n";
        return ret;
}

int main(){
       vector<int> v;
       v.push_back(0);
       v.push_back(5);
       v.push_back(3);
       v.push_back(1);
       v.push_back(2);
       v.push_back(4);
       v.push_back(7);

       vector<int> o = mergeSort(v,0,v.size()-1);
       for( int i=0; i<o.size(); i++ )
               cout << o[i] << " ";
       cout << "\n";

}
