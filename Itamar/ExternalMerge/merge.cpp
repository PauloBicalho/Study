#include<iostream>
#include<vector>

using namespace std;

int chunkSize = 2;

void push_all(vector<int>&dest,const vector<int>&source, int start){
        int i = start;
        while( i++ < source.size() ){
                dest.push_back( source[i-1] );
        }

}


vector<int> memoryMergeSort(const vector<int>& v, int l, int r ){
        if( l == r ){
                return vector<int>(1,v[l]);
        }

        int mid = l + ( (r-l) / 2 );
        
        vector<int> left  = memoryMergeSort(v,l,mid);
        vector<int> right = memoryMergeSort(v,mid+1,r);

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

class Io{
        public:
                vector<string> fnames;
                stringCurrentName;
                
                Io(){}
                
                void write( vector<int> values ){

                }

};

int main(){
        scanf("%d",&chunkSize);

        int v;
        vector<int> values = new vector<int>();
        while( scanf("%d",&v) != EOF ){
                values.append(v);

                if( values.size() == chunkSize ){
                        write( memoryMergeSort(values,0,v.size()-1 ) );
                        delete values;
                        values = new vector<int>();
                }
        }


       vector<int> o = mergeSort(v,0,v.size()-1);
       for( int i=0; i<o.size(); i++ )
               cout << o[i] << " ";
       cout << "\n";

}
