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

ll sum(ll a, ll b){
  ll ans = 1;
  for (ll i = 1; i <= a; i++){
    ans *= b + i;
    ans /= i;
  }
  return ans;
}

ll A, B, K;
string S;

int solve(ll a, ll b, ll rest){
  if (a == 0 && b == 0){
    cout << S << endl;
    return 0;
  }
  if (a == 0){
    S += 'b';
    solve(a, b - 1, rest);
    return 0;
  }
  if (b == 0){
    S += 'a';
    solve(a - 1, b, rest);
    return 0;
  }

  if (rest > sum(a - 1, b)){
    S += 'b';
    solve(a, b - 1, rest - sum(a - 1, b));
  }else{
    S += 'a';
    solve(a - 1, b, rest);
  }
  return 0;
}

int main(){
  cin >> A >> B >> K;
  solve(A, B, K);

  return 0;
}