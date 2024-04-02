#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item item1, Item item2) {
    //return i1.v*1.0/i1.w>i2.v*1.0/i2.w;
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)remainingWeight / item.weight * item.value;
            break;
        }
    }

    return totalValue;
}




int main() {
    int n;
    cout << "Enter Item Number: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Capacity of the knapsack: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(capacity, items);
    cout << "Maximum profit: " << maxProfit << std::endl;

    return 0;
}

