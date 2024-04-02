/*#include<bits/stdc++.h>
using namespace std;
int Sum(int n)
{
    if(n==0)
    {
        return 0;
    }

    int preSum = Sum(n-1);
    return n + preSum;

}


int main()
{
    int n;
    cin>>n;

    cout<<Sum(n)<<endl;

}
*/
/*#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

// 1 + 2 + 3 + ...
int sumSeries1(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumSeries1(n - 1);
}

// 1^2 + 2^2 + 3^2 + ...
int sumSeries2(int n) {
    if (n == 1) {
        return 1;
    }
    return n * n + sumSeries2(n - 1);
}

// 1*3 + 2*5 + 3*7 + ...
int sumSeries3(int n) {
    if (n == 1) {
        return 1 * 3;
    }
    return n * (2 * n + 1) + sumSeries3(n - 1);
}

// 2*3 + 4*5 + 8*7 + ...
int sumSeries4(int n) {
    if (n == 1) {
        return 2 * 3;
    }
    return (1 << (n - 1)) * (2 * n - 1) + sumSeries4(n - 1);
}

// 2*3*4 + 4*5*3 + 8*7*2 + ...
int sumSeries5(int n, int m) {
    if (n == 1) {
        return 2 * 3 * m;
    }
    return (1 << (n - 1)) * (2 * n - 1) * m + sumSeries5(n - 1, m - 1);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Sum of series 1: " << sumSeries1(n) << endl;
    cout << "Sum of series 2: " << sumSeries2(n) << endl;
    cout << "Sum of series 3: " << sumSeries3(n) << endl;
    cout << "Sum of series 4: " << sumSeries4(n) << endl;
    cout << "Sum of series 5: " << sumSeries5(n, n + 1) << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to print the path from a node to the root of a binary tree
bool printPathToRoot(Node* root, int target, vector<int>& path) {
    if (root == nullptr) {
        return false;
    }

    path.push_back(root->data);

    if (root->data == target || printPathToRoot(root->left, target, path) || printPathToRoot(root->right, target, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int targetNode = 5;
    vector<int> path;

    if (printPathToRoot(root, targetNode, path)) {
        cout << "Path from node " << targetNode << " to root: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Node not found in the tree." << endl;
    }

    return 0;
}
