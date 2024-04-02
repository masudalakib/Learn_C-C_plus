#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    int id;
};

bool compare(Item item1, Item item2) {
    return item1.value * 1.0 / item1.weight > item2.value * 1.0 / item2.weight;
}

double fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), compare);

    double cap_left = W;
    double profit = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (cap_left <= 0) break;

        int vi = items[i].value;
        int wi = items[i].weight;

        double fraction = min(1.0, cap_left / wi);
        cap_left -= fraction * wi;
        profit += fraction * vi;

        if (fraction > 0) {
            printf("item %d: %.1f kg %.1f taka\n", items[i].id, fraction * wi, fraction * vi);
        }
    }

    return profit;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].id = i + 1;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    double maxProfit = fractionalKnapsack(items, W);

    cout << "Profit: " << maxProfit << " taka" << endl;

    return 0;
}
