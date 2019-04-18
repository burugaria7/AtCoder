#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

/*struct foo{
        int num;
        char str;
};*/

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,q;

    cin >> n >> q;

    vector<int> num_(n,1);
    vector<char> str_;
    char s[n];
    
    
    cin >> s;

    for(int i = 0;i<n;i++){
        str_.push_back(s[i]);
    }
    

    char tmp,tmpp;

    for(int i =0;i<q;i++){ //命令の回数Q回だけぶんまわす
        cin >> tmp >> tmpp;
        for(int l=0;l<n;l++){//l体目のゴーレムの位置を操作
            if(str_[l] == tmp){//l個目の要素の床が命令対象の床かどうか？
                if(tmpp == 'L'){//L
                    if(num_[l]>0){
                        
                        if(l != 0){//一番左じゃなかったら実行
                            num_[l-1] += num_[l];
                        }
                        num_[l] =0;
                    }
                }else{//R
                    if(num_[l]>0){
                        if(l != n-1){//一番右じゃなかったら実行
                            num_[l+1] += num_[l];
                        }
                        num_[l] =0;
                    }
                }
            }
        }
    }

    int ans = 0;

    
    ans = accumulate(num_.begin(), num_.end(), 0);
    
    cout << ans;
    return 0;
}