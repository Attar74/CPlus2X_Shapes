template <class T>
class Node {
    T Value;
    Node<T> *Previous;
    Node<T> *Next;

public:
    Node(T val) {
        this->Value = val;
        Previous = 0;
        Next = 0;
    }

    void setNext(Node<T> *next) {
        this->Next = next;
    }

    Node<T> *getNext() {
        return Next;
    }

    void setPrevious(Node<T> *previous) {
        this->Previous = previous;
    }

    Node<T> *getPrevious() {
        return Previous;
    }

    void setValue(T value) {
        this->Value = value;
    }

    T getValue() {
        return Value;
    }
};

template <class T>
class LinkedListDual {
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedListDual() {
        head = tail = 0;
    }
    ~LinkedListDual() {
        //Assignment
    }
    void AddFront (T item) {
        Node<T> * newNode = new Node<T>(item);
        if(!head) {
            head = tail = newNode;
        } else {
            newNode->setNext(head);
            head->setPrevious(newNode);
            head = newNode;
        }
    }
    void AddBack (T item) {
        Node <T>* newNode = new Node<T>(item);
        if(!head) {
            head = tail = newNode;
        } else {
            newNode->setPrevious(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
    }
    void DeleteByValue(T value) {
        Node<T>* temp = head;
        while(temp) {
            if(temp->getValue() == value) {
                temp->getPrevious()->setNext(temp->getNext());
                temp->getNext()->setPrevious(temp->getPrevious());
                break;
            }
            temp = temp->getNext();
        }
    }

    void DeleteByIndexFromFront(int index) {
        if(!head) {
            throw "Not Founded!";
        }
        Node<T>* temp = head;
        if (index == 0) {
            head = head->getNext();
            if(head == NULL) {
                tail = NULL;
            }
            return;
        }
        for(int i =0; i < index; i++){
            temp = temp->getNext();
        }
        if(!temp) {
            throw "Not Founded!";
        } else {
            temp->getPrevious()->setNext(temp->getNext());
            temp->getNext()->setPrevious(temp->getPrevious());
            delete temp;
        }
    }

    void DeleteByIndexFromBack(int index) {
        Node<T>* temp = tail;
        for(int i =0; i < index; i++){
            temp = temp->getPrevious();
        }
        if(!temp) {
            throw "Not Founded!";
        } else {
            temp->getPrevious()->setNext(temp->getNext());
            temp->getNext()->setPrevious(temp->getPrevious());
            delete temp;
        }
    }

    void Insert(T value, int index) {
        if (index < 0) {
            throw invalid_argument("Out of Range");
        }
        if(index == 0) {
            this->AddFront(value);
            return;
        }
        this->AddFront(0);
        Node<T>* temp = head;
        for(int i=0; i < index; i++) {
            temp->setValue(temp->getNext()->getValue());
            temp = temp->getNext();
        }
        temp->setValue(value);

        /*Moshrief*/
        /*Node<T>* newNode = new Node<T>(value);
        temp->getPrevious()->setNext(newNode);
        newNode->setNext(temp);
        newNode->setPrevious(temp->getPrevious());
        temp->setPrevious(newNode);*/
    }

    void PrintAll () {
        Node <T>* temp = head;
        while(temp) {
            cout << temp->getValue() << " ";
            temp= temp->getNext();
        }
    }
};