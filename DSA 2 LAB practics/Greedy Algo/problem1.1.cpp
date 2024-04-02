#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int value;
    int weight;
};

bool compareItems(const Item& a, const Item& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].name >> items[i].value >> items[i].weight;
    }

    int k;
    cin >> k;

    vector<int> capacities(k);
    for (int i = 0; i < k; ++i) {
        cin >> capacities[i];
    }

    sort(items.begin(), items.end(), compareItems);

    vector<bool> itemTaken(n, false);
    int thievesCount = 0;

    for (int i = 0; i < k; ++i) {
        cout << "Thief " << i + 1 << " profit: ";

        double thiefProfit = 0.0;
        for (int j = 0; j < n; ++j) {
            if (!itemTaken[j] && items[j].weight <= capacities[i]) {
                cout << "Taking " << items[j].name << ": " << items[j].weight << " kg " << items[j].value << " taka" << endl;
                capacities[i] -= items[j].weight;
                thiefProfit += items[j].value;
                itemTaken[j] = true;
            }
        }


        cout << "Thief " << i + 1 << " profit: " << thiefProfit << " taka" << endl;

        if (thiefProfit > 0) {
            thievesCount++;
        }
    }

    cout << "Total " << thievesCount << " thieves stole from the warehouse." << endl;

    cout << "Still following items are left" << endl;
    for (int i = 0; i < n; ++i) {
        if (!itemTaken[i]) {
            cout << items[i].name << " " << items[i].weight << " kg " << items[i].value << " taka" << endl;
        }
    }

    return 0;
}
