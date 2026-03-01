#include <iostream>
#include <vector>
using namespace std;

long long mergeCount(vector<int>& arr, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long cnt = 0;
    cnt += mergeCount(arr, l, mid);
    cnt += mergeCount(arr, mid, r);

    vector<int> tmp;
    int i = l, j = mid;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            cnt += (mid - i);
            tmp.push_back(arr[j++]);
        }
    }
    while (i < mid) tmp.push_back(arr[i++]);
    while (j < r)   tmp.push_back(arr[j++]);
    for (int k = l; k < r; k++) arr[k] = tmp[k - l];
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << mergeCount(a, 0, n) << endl;
    return 0;
}
