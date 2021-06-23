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

int N, M, Q;
Pii WV[55];
int X[55];

int solve(){
  int L, R; cin >> L >> R;
  priority_queue <int, vector<int>, greater<int> > bag;
  for (int i = 1; i < L; i++) bag.push(X[i]);
  for (int i = R + 1; i <= M; i++) bag.push(X[i]);
  priority_queue <int> value;

  int ans = 0, nowIndex = 0;
  while (!bag.empty()){
    int B = bag.top(); bag.pop();
    for (int i = nowIndex; i < N; i++){
      if (WV[i].fi <= B){
        nowIndex++;
        value.push(WV[i].se);
      }
    }
    if (value.empty()) continue;
    ans += value.top(); value.pop();
  }
  cout << ans << endl;
  return 0;
}

int main(){
  cin >> N >> M >> Q;
  for (int i = 0; i < N; i++){
    cin >> WV[i].fi >> WV[i].se;
  }
  sort(WV, WV + N);
  for (int i = 1; i <= M; i++) cin >> X[i];
  for (int i = 0; i < Q; i++) solve();

  return 0;
}