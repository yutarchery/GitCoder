#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

class ABC165F {
public:
private:
  int n;
  int scores[int(2e5 + 5)];
  vector<vector<int>> graph;
  int answers[int(2e5 + 5)];
  int lisArray[int(2e5 + 5)];
  const int maxScore = int(1e9 + 5);

public:
  void solve() {
    this->prepare();
    this->calculateAnswer(1, 0);
    this->display();
    return;
  }

private:
  void prepare() {
    cin >> this->n;
    for (int i = 1; i <= n; i++) {
      cin >> this->scores[i];
    }

    this->graph.resize(this->n + 1);
    for (int i = 1; i < this->n; i++) {
      int u, v;
      cin >> u >> v;
      this->graph[u].push_back(v);
      this->graph[v].push_back(u);
    }

    fill(this->lisArray + 1, this->lisArray + this->n + 2, this->maxScore);
    return;
  }

  void calculateAnswer(int currentNode, int beforeNodeAnswer) {
    int currentLisIndex = this->searchLisIndex(this->scores[currentNode]);
    int beforeLisScore = this->lisArray[currentLisIndex];
    this->answers[currentNode] = max(currentLisIndex, beforeNodeAnswer);
    this->lisArray[currentLisIndex] = this->scores[currentNode];

    for (int nextNode : this->graph[currentNode]) {
      if (this->answers[nextNode] == 0) {
        this->calculateAnswer(nextNode, this->answers[currentNode]);
      }
    }

    this->lisArray[currentLisIndex] = beforeLisScore;
    return;
  }

  int searchLisIndex(int score) {
    int l = 0, r = this->n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (lisArray[mid] < score) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return r;
  }

  void display() {
    for (int i = 1; i <= n; i++) {
      cout << this->answers[i] << endl;
    }
    return;
  }
};

int main() {
  ABC165F abc165F;
  abc165F.solve();

  return 0;
}