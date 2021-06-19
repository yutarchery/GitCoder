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

int N, M, ans;
vector <int> Graph[2005];

bool visited[2005];
int solve(int start){
  visited[start] = true;
  queue <int> que; que.push(start);
  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int next : Graph[Q]){
      if (visited[next]) continue;
      visited[next] = true;
      que.push(next);
    }
  }
  for (int i = 1; i <= N; i++){
    if (visited[i]){
      ans++;
      visited[i] = false;
    }
  }
  return 0;
}

int main(){ 
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    Graph[A].push_back(B);
  }
  for (int i = 1; i <= N; i++){
    solve(i);
  }
  cout << ans << endl;

  return 0;
}