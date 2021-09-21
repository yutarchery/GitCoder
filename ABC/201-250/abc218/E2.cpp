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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

struct UnionFind{
  int n;
  int parent[int(2e5 + 5)];

  void init(){
    for (int i = 1; i <= n; i++) parent[i] = i;
  }

  int root(int u){
    int ans = parent[u];
    while (ans != parent[ans]){
      ans = parent[ans];
    }
    return parent[u] = ans;
  }

  void merge(int u, int v){
    int parentU = root(u), parentV = root(v);
    parent[u] = parentV;
    parent[v] = parentV;
    parent[parentU] = parentV;
  }

  bool isSame(int u, int v){
    return root(u) == root(v);
  }

};

int n, m;
vector <pair<ll, Pii> > graph;
ll ans = 0;

int main(){
  cin >> n >> m;
  UnionFind unionFind;
  unionFind.n = n;
  unionFind.init();

  for (int i = 0; i < m; i++){
    int a, b; ll c;
    cin >> a >> b >> c;

    if (c <= 0){
      unionFind.merge(a, b);
    }else{
      graph.push_back({c, {a, b}});
      ans += c;
    }
  }
  sort(graph.begin(), graph.end());

  for (pair<ll, Pii> p : graph){
    ll c = p.fi;
    int a = p.se.fi, b = p.se.se;

    if (!unionFind.isSame(a, b)){
      ans -= c;
      unionFind.merge(a, b);
    }
  }
  cout << ans << endl;

  return 0;
}