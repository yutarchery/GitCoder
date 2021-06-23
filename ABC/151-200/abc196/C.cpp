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

ll N;
int ans = 0;

int dig(ll num){
  int res = 0;
  while (num > 0){
    res++;
    num /= 10;
  }
  return res;
}

bool check(ll num){
  int D = dig(num);
  ll res = num;
  for (int i = 0; i < D; i++){
    num *= 10;
  }
  res += num;
  return res <= N;
}

int main(){
  cin >> N;
  while (check(ans + 1)){
    ans++;
  }

  cout << ans << endl;

  return 0;
}