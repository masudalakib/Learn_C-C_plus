#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Question {
    int marks;
    int time;
    int id;
};

bool compare(Question q1, Question q2) {
    return q1.marks * 1.0 / q1.time > q2.marks * 1.0 / q2.time;
}

void maximizeMarks(vector<Question>& questions, int totalMarks, int totalTime) {
    sort(questions.begin(), questions.end(), compare);

    int currentMarks = 0;
    int currentTime = 0;
    vector<int> selectedQuestions;

    for (int i = 0; i < questions.size(); i++) {
        if (currentTime + questions[i].time <= totalTime) {
            currentMarks += questions[i].marks;
            currentTime += questions[i].time;
            selectedQuestions.push_back(questions[i].id);
        }
    }

    cout << "Maximum marks: " << currentMarks << endl;
    cout << "Selected questions: ";
    for (int i = 0; i < selectedQuestions.size(); i++) {
        cout << "ques " << selectedQuestions[i] << " ";
    }
    cout << endl;
}

int main() {
    int totalMarks, totalTime, numQuestions;
    cout << "Enter the total marks, total time, and number of questions: ";
    cin >> totalMarks >> totalTime >> numQuestions;

    vector<Question> questions(numQuestions);
    cout << "Enter the marks and time for each question:\n";
    for (int i = 0; i < numQuestions; i++) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].id = i + 1;
    }

    maximizeMarks(questions, totalMarks, totalTime);

    return 0;
}
