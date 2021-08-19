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

int n;
pair<ll, Pii> wuv[int(1e5 + 5)];
ll ans = 0;

struct UnionFind{
  int n;
  int par[int(1e5 + 5)];
  ll cnt[int(1e5 + 5)];
  
  void init(){
    for (int i = 1; i <= n; i++){
      par[i] = i;
      cnt[i] = 1;
    }
  }

  int findParent(int node){
    int parent = par[node];
    while (parent != par[parent]){
      parent = par[parent];
    }
    return par[node] = parent;
  }

  void unite(int u, int v, ll w){
    int uParent = findParent(u);
    int vParent = findParent(v);

    ans += w * cnt[uParent] * cnt[vParent];

    cnt[uParent] += cnt[vParent];
    par[vParent] = uParent;
  }
};

int main(){
  cin >> n;
  for (int i = 0; i < n - 1; i++){
    int u, v; ll w; 
    cin >> u >> v >> w;
    wuv[i].fi = w;
    wuv[i].se = {u, v};
  }
  sort(wuv, wuv + n - 1);

  UnionFind unionFind;
  unionFind.n = n;
  unionFind.init();
  for (int i = 0; i < n - 1; i++){
    int u = wuv[i].se.fi, v = wuv[i].se.se;
    ll w = wuv[i].fi;
    unionFind.unite(u, v, w);
  }
  cout << ans << endl;

  return 0;
}