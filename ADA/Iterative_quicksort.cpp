#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void quicksort(vector<int>& arr) {
    vector<pair<int, int>> s;
    s.push_back({0, arr.size()});

    while (!s.empty()) {
        auto p = s.back();
        s.pop_back();

        int left = p.first;
        int right = p.second;

        if (right - left <= 1) {
            continue;
        }

        int pivot = left + (right - left) / 2;
        swap(arr[pivot], arr[right - 1]);

        int store = left;
        for (int i = left; i < right - 1; i++) {
            if (arr[i] < arr[right - 1]) {
                swap(arr[i], arr[store]);
                store++;
            }
        }

        swap(arr[right - 1], arr[store]);

        s.push_back({left, store});
        s.push_back({store + 1, right});
    }
}

int main() {
    vector<int> arr = {5, 12, 7, 1, 13, 2, 23, 11, 18};

    auto start = high_resolution_clock::now();
    quicksort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}