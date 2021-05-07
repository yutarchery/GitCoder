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

int N, K;
ll L, A[int(1e5 + 5)];

bool Check(ll now){
  int cnt = 0, before = 0;
  for (int i = 1; i <= N; i++){
    if (A[i] - A[before] >= now) {
      cnt++; before = i;
    }

    if (cnt == K){
      if (A[N + 1] - A[before] >= now) return true;
      else return false;
    }
  }

  return false;
}

int main(){
  cin >> N >> L;
  cin >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  A[N + 1] = L;

  ll ansL = 0, ansR = L;
  while (ansR - ansL > 1){
    ll mid = (ansL + ansR) / 2;

    if (Check(mid)) ansL = mid;
    else ansR = mid;
  }

  cout << ansL << endl;

  return 0;
}