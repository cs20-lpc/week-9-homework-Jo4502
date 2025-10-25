template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;
    buffer = new T[maxSize];

    frontIndex = 0;
    backIndex = -1;

     this->length = 0;

}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (this->isEmpty()) {
        throw string("empty");
    }

    return buffer[backIndex];

}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;

    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
    frontIndex = 0;
    backIndex = -1;

}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    for (int i = 0; i < this->length; i++) {
        buffer[(frontIndex + i) % maxSize] = copyObj.buffer[(copyObj.frontIndex + i) % maxSize];
    }
}


template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (this->isEmpty()) {
        throw string("empty");
    }

    frontIndex = (frontIndex + 1) % maxSize;

    this->length--;

}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (this->isFull()) {
        throw string("full");
    }

    backIndex = (backIndex + 1) % maxSize;

    buffer[backIndex] = elem;

    this->length++;

}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (this->isEmpty()) {
        throw string("queue is empty");
    }

    return buffer[frontIndex];

}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
