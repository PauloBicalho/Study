#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;


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

        return ret;
}

class NamesGenerator{
        public:
                string currentName;
                int currentIndex;
                
                NamesGenerator(){
                        currentName= "a";
                        currentName[0]--;
                        currentIndex=0;
                }
                
                string next(){
                        if( currentName[0] >= 'z' ){
                                int i=1;
                                for(; i<currentName.size(); i++ ){
                                        if( currentName[i] < 'z' ){
                                                currentName[i]++;
                                                break;
                                        }
                                }
                                for( int j=0; j<i; j++)
                                        currentName[j] =  'a';
                                if( i == currentName.size() )
                                        currentName.push_back('a');
                        } else
                                currentName[0]++;

                        return currentName;
                }

};

void externalMerge( vector<string> &fnames, int chunkSize, NamesGenerator &ng ){
        
        int it = 0;
        int left = fnames.size() - it;

        while( left > 1 ){
                int limit = min(chunkSize,left);

                vector<FILE *> files;
                vector<bool> emptyFile;
                for(int i=0; i<limit; i++,it++){
                        files.push_back( fopen(fnames[it].c_str(),"r") );
                        emptyFile.push_back( false );
                }
                
                string fname = ng.next();
                fnames.push_back(fname);

                priority_queue< pair<int,int> > heap;

                int v;
                for( int i=0; i<limit; i++){
                        fscanf(files[i],"%d", &v);
                        heap.push( make_pair(-1*v,i) );
                }

                FILE *mergedFile = fopen(fname.c_str(),"w");
                int removedFiles = 0;
                while( removedFiles < limit  ){
                        pair<int,int> min = heap.top();
                        heap.pop();

                        fprintf(mergedFile,"%d ",-1 *min.first);
                        
                        fscanf(files[min.second], "%d", &v);
                        if( feof(files[min.second]) ){
                                if( not emptyFile[min.second] ){
                                        emptyFile[min.second] = true;
                                        removedFiles++;
                                }
                        }
                        else
                                heap.push( make_pair(-1 * v,min.second ) );

                }
                fclose(mergedFile);
                
                cout << "# " << fnames.size() << " - " << it << " - " << fnames[it] << "\n";

                left = fnames.size() - it;

        }

}

int main(){
        int chunkSize;
        scanf("%d",&chunkSize);

        NamesGenerator ng;
        vector<string> fnames;
        
        int v;
        vector<int> *values = new vector<int>();
        while( scanf("%d",&v) != EOF ){
                values->push_back(v);

                if( values->size() == chunkSize ){
                        vector<int> orderedValues = memoryMergeSort(*values,0,values->size()-1 );

                        string fname = ng.next();
                        cout << fname << "\n";
                        FILE *fout = fopen(fname.c_str(),"w");
                        fnames.push_back( fname );

                        for( int i=0; i<orderedValues.size(); i++ )
                                fprintf(fout, "%d ", orderedValues[i] );

                        fclose(fout); 
                        delete values;
                        values = new vector<int>();
                }
        }

        if( values->size() > 0 ){
                vector<int> orderedValues = memoryMergeSort(*values,0,values->size()-1 );

                string fname = ng.next();
                cout << fname << "-\n";
                FILE *fout = fopen(fname.c_str(),"w");
                fnames.push_back( fname );

                for( int i=0; i<orderedValues.size(); i++ )
                        fprintf(fout, "%d ", orderedValues[i] );

                fclose(fout); 
                delete values;
        }

        externalMerge( fnames, chunkSize, ng );
}
