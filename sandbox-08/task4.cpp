#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int value = 1; value <= 3; ++value) {
        Node* node = new Node{value, nullptr};
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int length = 0;
    for (Node* node = head; node != nullptr; node = node->next) {
        if (length != 0) {
            std::cout << ' ';
        }
        std::cout << node->value;
        ++length;
    }
    std::cout << '\n' << length << '\n';

    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    tail = nullptr;
    return 0;
}
