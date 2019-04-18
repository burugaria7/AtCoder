#include <iostream>
#include <vector>
#include <string>
using namespace std;

int start,end_,kiroku;


int search_Zero(string str){
    kiroku = 0;
    int max = 0;
    start = 0;
    end_ = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            kiroku++;
        }else{
            if(max<=kiroku){
                max = kiroku;
                end_ = i;
                start = i+1;
            }
            kiroku = 0;
        }
    }
    return max;
}
int search_Ichi(string str){
    kiroku = 0;
    int max = 0;
    start = 0;
    end_ = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='1'){
            kiroku++;
        }else{
            if(max<=kiroku){
                max = kiroku;
                end_ = i;
                start = i+1;
            }
            kiroku = 0;
        }
        
    }
    return max;
}

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    int n,k;
    int max_;

    cin >> n >> k >> str;

    for(int i = 0; i < k;i++){//mere
        if((k-i)%2==0){
            max_ = search_Zero(str);
            str.replace(start-1,end_,"1");
        }else{
            max_ = search_Ichi(str);
            str.replace(start-1,end_,"0");
        }
        cout <<str<<endl;
    }
    
    int aa = search_Ichi(str);
    int bb = search_Zero(str);

    if(aa>bb){
        cout << bb;
    }else{
        cout <<aa;
    }

    //cout << str << endl;
    //cout << kiroku;


    return 0;
}