#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;

bool backtrack(int idx, int current) {
    if (current == k) return true;
    if (idx == n || current > k) return false;

    // Берём элемент a[idx]
    if (backtrack(idx + 1, current + a[idx])) return true;
    // Не берём элемент a[idx]
    if (backtrack(idx + 1, current)) return true;

    return false;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (backtrack(0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
