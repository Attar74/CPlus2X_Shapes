template <class T>
struct Node {
    T Value;
    Node* Next;
};

template <class T>
class LinkedList {
    Node <T>* head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while(head != NULL) {
            Node<T>* temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void AddFront(T item) {
        if(!head) {
            head = new Node<T>;
            head->Next = NULL;
            head->Value = item;
        }
        else {
            Node <T> * temp = new Node<T>;
            temp->Value = item;
            temp->Next = head;
            head = temp;
        }
    }

    void AddBack(T item) {
        if(!head) {
            head = new Node<T>;
            head->Next = NULL;
            head->Value = item;
        }
        else {
            Node<T>* temp = head;
            while(temp->Next != NULL) {
                temp = temp->Next;
            }
            Node <T> * newNode = new Node<T>;
            temp->Next = newNode;
            newNode->Value = item;
            newNode->Next = NULL;
        }
    }

    /*void DeleteByItem(T item) {
        Node<T>* temp = head;
        while(temp->Next->Value != item) {
            temp = temp->Next;
        }
        temp->Next = temp->Next->Next;
        delete temp->Next;
    }*/

    void DeleteByIndex(int index) {
        Node<T>* temp = head;

        //For handling delete the first element
        if(index == 0) {
            head = temp->Next;
            delete temp;
            return;
        }

        int i = index -1; // Moshrief approach
        //int i = 0; // Mine
        while(temp != NULL && i > 0 ){ // replace i > 0 with index - i > 1 Mine
            temp = temp->Next;
            i--;
        }
        if(!temp) {
            throw invalid_argument("Out of Range");
        }
        Node <T>* toBeDeleted = temp->Next;
        temp->Next = temp->Next->Next;
        delete toBeDeleted;
    }

    void PrintAll() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->Value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
};