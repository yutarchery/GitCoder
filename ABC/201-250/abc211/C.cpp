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

ll dp[int(1e5 + 5)][9];
string s, t = "chokudai";

int main(){
  cin >> s;
  dp[0][0] = 1;

  for (int i = 1; i <= s.length(); i++){
    for (int j = 0; j <= 8; j++){
      dp[i][j] = dp[i - 1][j];
    }

    for (int j = 1; j <= 8; j++){
      if (t[j - 1] == s[i - 1]){
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[s.length()][t.length()] << endl;

  return 0;
}