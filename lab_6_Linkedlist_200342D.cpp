#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
  public:
    int value;
    Node* next_node;

    Node(int val) {
      value = val;
      next_node = nullptr;
    }
};

class Stack {
  private:
    Node* top_node;

  public:
    Stack() {
      top_node = nullptr;
    }

    bool push(int x) {
      Node* new_node = new Node(x);
      if (new_node == nullptr) {
        cout << "Error: memory allocation failed error\n";
        return false;
      } else {
        new_node->next_node = top_node;
        top_node = new_node;
        cout << x << " pushed element to stack\n";
        return true;
      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Error: stack underflow error\n";
        return 0;
      } else {
        int x = top_node->value;
        Node* temp = top_node;
        top_node = top_node->next_node;
        delete temp;
        return x;
      }
    }

    bool isEmpty() {
      return (top_node == nullptr);
    }

    int top() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return top_node->value;
      }
    }

    void display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        Node* current_node = top_node;
        while (current_node != nullptr) {
          cout << current_node->value << " ";
          current_node = current_node->next_node;
        }
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack stack;
  stack.push(8);
  stack.push(10);
  stack.push(5);
  stack.push(11);
  stack.push(15);
  stack.push(23);
  stack.push(6);
  stack.push(18);
  stack.push(20);
  stack.push(17);
  stack.display();
  cout << stack.pop() << " popped element from stack\n";
  cout << stack.pop() << " popped element from stack\n";
  cout << stack.pop() << " popped element from stack\n";
  cout << stack.pop() << " popped element from stack\n";
  cout << stack.pop() << " popped element from stack\n";
  stack.display();
  stack.push(4);
  stack.push(30);
  stack.push(3);
  stack.push(1);
  stack.display();    
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<milliseconds>(end_time - start_time);
  cout << "Time taken for Execution : " << execution_time.count() << " ms" << endl;
  return 0;
}