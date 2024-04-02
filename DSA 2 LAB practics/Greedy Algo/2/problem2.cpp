
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
  int start_time;
  int finish_time;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
  return a1.finish_time < a2.finish_time; // Sort by finish time (ascending)
}

vector<Activity> sa(const vector<Activity>& activ) {
  int n = activ.size();
  vector<Activity> sA;

  // Sort activities by finish time
  vector<Activity> sorted(activ);
  sort(sorted.begin(), sorted.end(), compareActivities);

  // Select activities greedily
  int ls = 0;
  for (int i = 1; i < n; ++i) {
    if (sorted[i].start_time >= sorted[ls].finish_time) {
      sA.push_back(sorted[i]);
      ls = i;
    }
  }

  return sA;
}

int main() {
  int n;
  cout << "Enter the number of activities: ";
  cin >> n;

  vector<Activity> activ(n);
  cout << "Enter start and finish times for each activity:\n";
  for (int i = 0; i < n; ++i) {
    cin >> activ[i].start_time >> activ[i].finish_time;
  }

  vector<Activity> sA = sa(activ);

  cout << "Selected activities:\n";
  for (const Activity& activity : sA) {
    cout << "Start time: " << activity.start_time << ", Finish time: " << activity.finish_time << endl;
  }

  return 0;
}
