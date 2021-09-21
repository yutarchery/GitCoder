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

int n, m;
vector <Pli> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
ll ans = 0;
priority_queue <Pli, vector<Pli>, greater<Pli> > pque;

int solve(int start){
  for (Pli p : graph[start]){
    pque.push(p);
  }
  visited[start] = true;

  while (!pque.empty()){
    Pli p = pque.top(); pque.pop();
    if (p.fi <= 0) ans -= p.fi;
    if (visited[p.se]) continue;

    visited[p.se] = true;
    if (p.fi > 0) ans -= p.fi;

    for (Pli next : graph[p.se]){
      if (!visited[next.se]){
        pque.push(next);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b; ll c;
    cin >> a >> b >> c;

    if (a == b){
      if (c >= 0) ans += c;
    }else{
      graph[a].push_back({c, b});
      graph[b].push_back({c, a});
      ans += c;
    }
  }
  solve(1);

  return 0;
}