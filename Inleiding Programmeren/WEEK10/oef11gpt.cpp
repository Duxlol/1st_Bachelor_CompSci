#include <iostream>
using namespace std;

struct Node {
    string item;
    Node* next;
    Node* prev;
};

struct Queue {
    int size;
    Node* head;
    Node* tail;
};

Queue* createQueue() {
    Queue* queue = new Queue;
    queue->size = 0;
    queue->head = nullptr;
    queue->tail = nullptr;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

bool enqueue(Queue* queue, const string& newItem) {
    Node* newNode = new Node;
    newNode->item = newItem;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        newNode->prev = queue->tail;
        queue->tail = newNode;
    }

    queue->size++;
    return true;
}

string dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return "ERROR";
    }

    Node* tmp = queue->head;
    string item = tmp->item;

    queue->head = tmp->next;
    if (queue->head) {
        queue->head->prev = nullptr;
    } else {
        queue->tail = nullptr;
    }

    delete tmp;
    queue->size--;
    return item;
}

void print(Queue* queue) {
    Node* current = queue->head;
    while (current != nullptr) {
        cout << current->item << endl;
        current = current->next;
    }
}

void destroyQueue(Queue* queue) {
    Node* current = queue->head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    delete queue;
}

int main(){
    Queue* q = createQueue();
    cout << boolalpha << isEmpty(q) << endl;
    cout << dequeue(q) << endl;
    enqueue(q, "Jos");
    enqueue(q ,"An");
    enqueue(q, "Peter");
    print(q);             //Jos, An en Peter worden op drie regels geprint
    string first = dequeue(q);
    cout << first << endl;  //Jos wordt geprint
    print(q);           //An en Peter worden geprint
    destroyQueue(q);
    return 0;
}
