#ifndef CODE_VECTOR_H
#define CODE_VECTOR_H

template<typename T>
class Vector {
private:
    T *elements;
    int capacity;
    int currentSize;

public:
    Vector(int initialCapacity) : capacity(initialCapacity), currentSize(0) {
        elements = new T[capacity];
    }

    void push_back(const T &element) {
        if (currentSize < capacity) {
            elements[currentSize] = element;
            ++currentSize;
        } else {
            capacity *= 2;
            T *newElements = new T[capacity];
            for (int i = 0; i < currentSize; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            elements[currentSize] = element;
            ++currentSize;
        }
    }

    T &getElement(int index) const {
        return elements[index];
    }

    void setElement(int index, const T &value) {
        elements[index] = value;
    }

    void erase(int index) {
        if (index < 0 || index >= currentSize)
            return;

        delete elements[index];

        for (int i = index; i < currentSize - 1; ++i)
            elements[i] = elements[i + 1];
        --currentSize;
    }

    int getIndex(const T &value) const {
        for (int i = 0; i < currentSize; ++i) {
            if (elements[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int Size() const {
        return currentSize;
    }

    ~Vector() {
        delete[] elements;
    }
};

#endif //CODE_VECTOR_H
