#ifndef CODE_LIST_H
#define CODE_LIST_H

template<typename T>
class List {
private:
    struct Node {
        T value;
        Node *nextNode;
    };
    Node *head;
    Node *tail;
    int size;
public:
    // Nested iterator class
    class Iterator {
    private:
        Node *currentNode;

    public:
        Iterator(Node *node) : currentNode(node) {}

        // Overloaded operators for iterator traversal
        Iterator &operator++() {
            currentNode = currentNode->nextNode;
            return *this;
        }

        T &operator*() const {
            return currentNode->value;
        }

        bool operator!=(const Iterator &other) const {
            return currentNode != other.currentNode;
        }
    };

    // Get iterator to beginning of the list
    Iterator begin() {
        return Iterator(head);
    }

    // Get iterator to end of the list
    Iterator end() {
        return Iterator(nullptr);
    }

    List(int size) : head(nullptr), tail(nullptr), size(size) {
    };

    void push_front(T newValue) {
        Node *newNode = new Node;
        newNode->value = newValue;
        newNode->nextNode = nullptr;
        if (head == nullptr)
            tail = newNode;
        else {
            Node *previousNode = head;
            newNode->nextNode = previousNode;
        }
        head = newNode;
        size += 1;
    }

    void push_back(T newValue) {
        Node *newNode = new Node;
        newNode->value = newValue;
        newNode->nextNode = nullptr;
        if (head == nullptr)
            head = newNode;
        else
            tail->nextNode = newNode;
        tail = newNode;
        size += 1;
    }

    T remove_front() {
        T ret;

        Node *tmp = head;
        head = head->nextNode;
        if (head == nullptr)
            tail = nullptr;
        ret = tmp->value;
        delete tmp;
        size -= 1;

        return ret;
    }

    int getSize() {
        return size;
    }

    T &getValue() {
        return head->value;
    }

    T getTailValue() {
        T ret;
        Node *tmp = tail;
        ret = tmp->value;
        return ret;
    }

    void clear() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->nextNode;
            delete current;
            current = next;
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~List() {
        clear();
    }
};

#endif //CODE_LIST_H
