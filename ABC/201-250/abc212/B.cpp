#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

string s;

bool check(){
  bool same = true;
  for (int i = 1; i < 4; i++){
    if (s[i - 1] != s[i]) same = false;
  }

  bool order = true;
  for (int i = 0; i < 3; i++){
    if (s[i] + 1 != s[i + 1]){
      if (s[i] != '9' || s[i + 1] != '0'){
        order = false;
      }
    }
  }
  return same || order;
}

int main(){
  cin >> s;
  if (check()){
    cout << "Weak" << endl;
  }else{
    cout << "Strong" << endl;
  }


  return 0;
}