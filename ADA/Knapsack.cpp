#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compareWeight(Item a, Item b) {
    return a.weight < b.weight;
}

bool compareProfit(Item a, Item b) {
    return a.profit > b.profit;
}

bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareWeight);

    double totalProfit = 0.0;
    for (auto& item : items) {
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalProfit += item.profit;
        } else {
            totalProfit += item.profit * (double)capacity / item.weight;
            capacity = 0;
            break;
        }
    }

    return totalProfit;
}

double fractionalKnapsackProfit(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareProfit);

    vector<Item> items2;
    for (auto& item : items) {
        Item newItem = item;
        newItem.weight = 1;
        newItem.profit = (double)item.profit / item.weight;
        items2.push_back(newItem);
    }

    return fractionalKnapsack(items2, capacity);
}

double fractionalKnapsackRatio(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareRatio);

    double totalProfit = 0.0;
    for (auto& item : items) {
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalProfit += item.profit;
        } else {
            totalProfit += item.profit * (double)capacity / item.weight;
            capacity = 0;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    double totalProfit1 = fractionalKnapsack(items, capacity);
    cout << "Sort by weight: " << totalProfit1 << endl;

    double totalProfit2 = fractionalKnapsackProfit(items, capacity);
    cout << "Sort by profit: " << totalProfit2 << endl;

    double totalProfit3 = fractionalKnapsackRatio(items, capacity);
    cout << "Sort by weight and profit: " << totalProfit3 << endl;

    if (totalProfit1 >= totalProfit2 && totalProfit1 >= totalProfit3) {
        cout << "Sort by weight is the most optimized." << endl;
    } else if (totalProfit2 >= totalProfit1 && totalProfit2 >= totalProfit3) {
        cout << "Sort by profit is the most optimized." << endl;
    } else {
        cout << "Sort by weight and profit is the most optimized." << endl;
    }

    return 0;
}