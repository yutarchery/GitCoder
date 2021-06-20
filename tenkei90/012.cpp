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

struct UnionFind{
  int N, par[int(4e6 + 5)] = {};

  int root(int node){
    if (par[node] == 0) return par[node] = node;
    if (par[node] == node) return node;
    return par[node] = root(par[node]);
  }

  void unite(int node1, int node2){
    int root1 = root(node1), root2 = root(node2);
    par[root1] = root2;
  }

  bool same(int node1, int node2){
    return root(node1) == root(node2);
  }
};


int H, W, Q;
bool used[2005][2005];
int di[4] = {0, 1, 0, -1}, dj[4] = {-1, 0, 1, 0};
UnionFind unionFind;

int query1(){
  int R, C; cin >> R >> C;
  used[R][C] = true;
  unionFind.root((R - 1) * W + C);
  for (int k = 0; k < 4; k++){
    int I = R + di[k], J = C + dj[k];
    if (!used[I][J]) continue;
    unionFind.unite((R - 1) * W + C, (I - 1) * W + J);
  }
  return 0;
}

int query2(){
  int Ra, Ca, Rb, Cb;
  cin >> Ra >> Ca >> Rb >> Cb;
  if (!used[Ra][Ca] || !used[Rb][Cb]) {
    No();
    return 0;
  }
  if (unionFind.same((Ra - 1) * W + Ca, (Rb - 1) * W + Cb)) Yes();
  else No();
  return 0;
}


int main(){
  cin >> H >> W >> Q;
  for (int i = 0; i < Q; i++){
    int t; cin >> t;
    if (t == 1) query1();
    else query2();
  }

  return 0;
}