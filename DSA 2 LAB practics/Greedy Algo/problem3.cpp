#include <iostream>

using namespace std;

int makeChange(int n) {
  int coins = 0;
  int denominations[] = {25, 10, 5, 1}; // Denominations (Quarters, Dimes, Nickels, Pennies)

  for (int i = 0; i < 4; ++i) {
    coins += n / denominations[i]; // Get the maximum number of coins for each denomination
    n %= denominations[i]; // Update remaining amount after using that denomination
  }

  return coins;
}

int main() {
  int n;
  cout << "Enter the amount (cents): ";
  cin >> n;

  int coins = makeChange(n);
  cout << "Total coins: " << coins << endl;

  // Print details of each coin used (optional)
  for (int i = 0; i < 4; ++i) {
    int count = coins / (25 / (i + 1)); // Calculate the number of coins used for each denomination
    coins %= (25 / (i + 1));
    if (count > 0) {
      cout << count << " " << (25 / (i + 1)) << " cents --- " << count << endl;
    }
  }

  return 0;
}










/*


#include <iostream>
#include <vector>

using namespace std;

int makeChange(int n, const vector<int>& denominations) {
  int coins = 0;

  for (int i = 0; i < denominations.size(); ++i) {
    coins += n / denominations[i]; // Get the maximum number of coins for each denomination
    n %= denominations[i]; // Update remaining amount after using that denomination
  }

  return coins;
}

int main() {
  int n, d;
  cout << "Enter the amount (cents): ";
  cin >> n;
  cout << "Enter the number of denominations (d): ";
  cin >> d;

  vector<int> denominations(d);
  cout << "Enter the denominations (increasing order): ";
  for (int i = 0; i < d; ++i) {
    cin >> denominations[i];
  }

  int coins = makeChange(n, denominations);
  cout << "Total coins: " << coins << endl;

  // Print details of each coin used (optional)
  for (int i = 0; i < d; ++i) {
    int count = coins / denominations[d - i - 1]; // Calculate the number of coins used for each denomination
    coins %= denominations[d - i - 1];
    if (count > 0) {
      cout << count << " " << denominations[d - i - 1] << " cents --- " << count << endl;
    }
  }

  return 0;
}

*/
