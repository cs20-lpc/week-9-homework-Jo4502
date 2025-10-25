template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if(isEmpty())         // if queue is empty throw string
    throw string("the back is empty");
    
    return last->value;     // return the value of last
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (head != nullptr) {
        Node* temp = head;   // save current head
        head = head->next;   // move to next node
        delete temp;         // delete old head
    }

    last = nullptr;
    this->length = 0;       // reset last and lenght
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    head = nullptr;
    last = nullptr;     // start empty
    this->length = 0;

    Node* curr = copyObj.head;
    while (curr != nullptr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (isEmpty())
        throw string("empty [dequeue]");

    Node* temp = head;       // store current head
    head = head->next;       // move to next node
    delete temp;             
    this->length--; 
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
   
    if (isEmpty()) {
        head = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty())
        throw string("empty [front]");

    return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
