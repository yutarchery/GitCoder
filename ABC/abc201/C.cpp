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

string S;
int used[10];
int ans = 0;

int solve(int dig){
  if (dig == 4){
    for (int i = 0; i < 10; i++){
      if (S[i] == 'o' && used[i] == 0) return 0;
      if (S[i] == 'x' && used[i] > 0) return 0;
    }
    ans++;
    return 0;
  }
  for (int i = 0; i < 10; i++){
    used[i]++;
    solve(dig + 1);
    used[i]--;
  }
  return 0;
}

int main(){
  cin >> S;
  solve(0);
  cout << ans << endl;

  return 0;
}