#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (rear) {
            rear->next = newNode;
            newNode->prev = rear;
        }
        rear = newNode;
        if (!front) {
            front = rear;
        }
    }

    void dequeue() {
        if (front) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            if (!front) {
                rear = nullptr;
            }
        }
    }

    T peek() {
        return front ? front->data : T();
    }

    bool isEmpty() {
        return !front;
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front of queue: " << queue.peek() << endl;
    queue.dequeue();

    if (queue.isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
