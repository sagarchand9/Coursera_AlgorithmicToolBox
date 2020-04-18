#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

int m = -1;

class StackWithMax {
    vector<int> stack;
    

  public:

    void Push(int value) {
        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return stack.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;
    StackWithMax stack_max;

    int temp;
    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            temp = stoi(value);
            m = std::max(m, temp);
            stack.Push(temp);
            stack_max.Push(m);
        }
        else if (query == "pop") {
            stack.Pop();
            stack_max.Pop();
        }
        else if (query == "max") {
            cout << stack_max.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}