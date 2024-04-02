#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Question {
  int marks;
  int time;
  double efficiency; // Marks per minute (efficiency)
};

bool compareQuestions(Question a, Question b) {
  return a.efficiency > b.efficiency; // Sort by efficiency (descending)
}

int maximizeMarks(const vector<Question>& questions, int totalTime) {
  int n = questions.size();
  vector<Question> sortedQuestions(questions);
  sort(sortedQuestions.begin(), sortedQuestions.end(), compareQuestions);

  int remainingTime = totalTime;
  int totalMarks = 0;

  for (int i = 0; i < n && remainingTime > 0; ++i) {
    int timeTaken = min(remainingTime, sortedQuestions[i].time);
    double marksScored = (double)timeTaken / sortedQuestions[i].time * sortedQuestions[i].marks;

    totalMarks += marksScored;
    remainingTime -= timeTaken;
  }

  return totalMarks;
}

int main() {
  int M, T, N;
  cout << "Enter total marks (M): ";
  cin >> M;
  cout << "Enter total time (minutes, T): ";
  cin >> T;
  cout << "Enter number of questions (N): ";
  cin >> N;

  vector<Question> questions(N);
  cout << "Enter marks :\n";
  for (int i = 0; i < N; ++i) {
    cin >> questions[i].marks >> questions[i].time;
    questions[i].efficiency = (double)questions[i].marks / questions[i].time;
  }

  // Solve for individual
  int individualMarks = maximizeMarks(questions, T);
  cout << "Maximum marks achievable alone: " << individualMarks << endl;

  // Solve for group (assuming friend has the same efficiency)
  int groupTime = T * 2;  // Double the time for two people
  int groupMarks = maximizeMarks(questions, groupTime);
  cout << "Maximum marks achievable with a friend: " << groupMarks << endl;

  return 0;
}
