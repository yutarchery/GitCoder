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

int n, m, k[int(2e5 + 5)];
bool deleted[int(2e5 + 5)];
vector <int> a[int(2e5 + 5)];
vector <Pii> location[int(2e5 + 5)];

int main(){
  cin >> n >> m;
  for (int i = 1; i <= m; i++){
    cin >> k[i];
    for (int j = 0; j < k[i]; j++){
      int color; cin >> color;
      a[i].push_back(color);
      location[color].push_back({i, j});
    }
    k[i]--;
  }

  queue <int> que;

  for (int color = 1; color <= n; color++){
    bool flag = true;
    for (Pii p : location[color]){
      int i = p.fi, j = p.se;
      flag &= k[i] == j;
    }

    if (flag){
      deleted[color] = true;
      for (Pii p : location[color]){
        int i = p.fi, j = p.se;
        k[i]--;
        if (k[i] >= 0){
          que.push(a[i][k[i]]);
        }
      }
    }
  }

  while (!que.empty()){
    int color = que.front(); que.pop();

    if (deleted[color]) continue;

    bool flag = true;
    for (Pii p : location[color]){
      int i = p.fi, j = p.se;
      flag &= k[i] == j;
    }

    if (flag){
      deleted[color] = true;
      for (Pii p : location[color]){
        int i = p.fi, j = p.se;
        k[i]--;
        if (k[i] >= 0){
          que.push(a[i][k[i]]);
        }
      }
    }
  }
  
  bool ans = true;
  for (int i = 1; i <= n; i++) ans &= deleted[i];
  
  if (ans) Yes();
  else No();

  return 0;
}