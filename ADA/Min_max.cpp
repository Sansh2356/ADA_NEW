#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findMinMax(vector<int>& arr, int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    } else {
        int mid = low + (high - low) / 2;

        auto left = findMinMax(arr, low, mid);
        auto right = findMinMax(arr, mid + 1, high);

        int mini = min(left.first, right.first);
        int maxi = max(left.second, right.second);

        return {mini, maxi};
    }
}

int main() {
    vector<int> arr = {1, 5, 2, 8, 3, 9, 4, 7, 6};

    auto result = findMinMax(arr, 0, arr.size() - 1);

    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}