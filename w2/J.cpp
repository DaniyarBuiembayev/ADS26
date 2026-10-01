#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* insert(Node* head, int x, int p) {
    Node* newNode = new Node{x, nullptr};


    if (p == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;


    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// 2. Remove
Node* remove(Node* head, int p) {
    // удаляем первый
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;

    // доходим до узла перед удаляемым
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    return head;
}

// 3. Print
void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << "\n";
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

// 4. Replace
Node* replaceNode(Node* head, int p1, int p2) {
    // сначала достаём узел из p1

    Node* moved;

    if (p1 == 0) {
        moved = head;
        head = head->next;
    }
    else {
        Node* current = head;

        for (int i = 0; i < p1 - 1; i++) {
            current = current->next;
        }

        moved = current->next;
        current->next = moved->next;
    }

    // теперь вставляем moved на позицию p2

    if (p2 == 0) {
        moved->next = head;
        head = moved;
        return head;
    }

    Node* current = head;

    for (int i = 0; i < p2 - 1; i++) {
        current = current->next;
    }

    moved->next = current->next;
    current->next = moved;

    return head;
}

// 5. Reverse
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;

    return head;
}

// 6. Cyclic left
Node* cyclicLeft(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    Node* current = head;

    // находим длину
    int n = 0;
    while (current != nullptr) {
        n++;
        current = current->next;
    }

    x %= n;

    if (x == 0) {
        return head;
    }

    // доходим до x-го узла
    current = head;

    for (int i = 0; i < x - 1; i++) {
        current = current->next;
    }

    Node* newHead = current->next;
    current->next = nullptr;

    // ищем старый tail
    Node* tail = newHead;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = head;

    head = newHead;

    return head;
}

// 7. Cyclic right
Node* cyclicRight(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    // находим длину
    int n = 0;
    Node* current = head;

    while (current != nullptr) {
        n++;
        current = current->next;
    }

    x %= n;

    if (x == 0) {
        return head;
    }

    // right x = left (n - x)
    int left = n - x;

    current = head;

    for (int i = 0; i < left - 1; i++) {
        current = current->next;
    }

    Node* newHead = current->next;
    current->next = nullptr;

    Node* tail = newHead;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = head;

    head = newHead;

    return head;
}

int main() {
    Node* head = nullptr;

    int command;

    while (cin >> command) {

        if (command == 0) {
            break;
        }

        else if (command == 1) {
            int x, p;
            cin >> x >> p;

            head = insert(head, x, p);
        }

        else if (command == 2) {
            int p;
            cin >> p;

            head = remove(head, p);
        }

        else if (command == 3) {
            print(head);
        }

        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;

            head = replaceNode(head, p1, p2);
        }

        else if (command == 5) {
            head = reverse(head);
        }

        else if (command == 6) {
            int x;
            cin >> x;

            head = cyclicLeft(head, x);
        }

        else if (command == 7) {
            int x;
            cin >> x;   

            head = cyclicRight(head, x);
        }
    }

    return 0;
}