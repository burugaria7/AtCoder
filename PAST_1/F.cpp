#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <cctype>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

//vector<vector<int>> data(3, vector<int>(4));


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    vector<string> tango;

    int flag = 0;

    int mojisu = 0;

    rep(i,str.size()){
        mojisu++;

        if(isupper(str.substr(i,1).c_str()[0]))flag++;

        if(flag==2){
            tango.push_back(str.substr(i+1-mojisu,mojisu));
            mojisu = 0;
            flag = 0;
        }
    }

    for(auto a:tango){
        cout << a <<" ";
    }

    cout <<""<<endl;


    std::sort(tango.begin(), tango.end(), [](const std::string& a, const std::string& b) {
       for (int i = 0 ; i < std::min(a.size(), b.size()) ; i++) {
         const auto a_char = std::tolower(a[i]);
         const auto b_char = std::tolower(b[i]);
         if (a_char != b_char) {
           return a_char < b_char;
         }
       }
       return a.size() < b.size();
     });

    for(auto a:tango){
        cout << a <<" ";
    }





    return 0;
}