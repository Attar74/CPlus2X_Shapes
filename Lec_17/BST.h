template <class T>
struct Node {
    T Value;
    Node<T>* Left;
    Node<T>* Right;
    Node(T value) {
        Left = Right = NULL;
        Value = value;
    }
};
template <class T>
class BST {
    Node<T>* root;
    bool FindRecursionInternal(Node<T>* temp, T value) {
        if(!temp) {
            return false;
        }
        if(temp->Value == value) {
            return true;
        } else if (temp->Value > value) {
            FindRecursionInternal(temp->Left, value);
        } else {
            FindRecursionInternal(temp->Right, value);
        }
    }

    void inOrderTraversalInternal(Node<T>* temp) {
        if(!temp) {
            return;
        }
        inOrderTraversalInternal(temp->Left);
        cout << temp->Value << endl;
        inOrderTraversalInternal(temp->Right);
    }

    void inOrderTraversalInternalReversed(Node<T>* temp) {
        if(!temp) {
            return;
        }
        inOrderTraversalInternal(temp->Right);
        cout << temp->Value << endl;
        inOrderTraversalInternal(temp->Left);
    }

    void preOrderTraversalInternal(Node<T>* temp) {
        if(!temp) {
            return;
        }
        cout << temp->Value << endl;
        preOrderTraversalInternal(temp->Left);
        preOrderTraversalInternal(temp->Right);
    }

    void postOrderTraversalInternal(Node<T>* temp) {
        if(!temp) {
            return;
        }
        postOrderTraversalInternal(temp->Left);
        postOrderTraversalInternal(temp->Right);
        cout << temp->Value << endl;
    }

public:
    BST() {
        root = NULL;
    }
    ~BST() {
        //Assignment
    }
    void Add(T value) {
        if(!root) {
            root = new Node<T>(value);
        } else {
            Node<T>* temp = root;
            while (true) {
                if (temp->Value < value) {
                    if (!temp->Right) {
                        temp->Right = new Node<T>(value);
                        break;
                    } else {
                        temp = temp->Right;
                    }
                } else if (temp->Value > value) {
                    if (!temp->Left) {
                        temp->Left = new Node<T>(value);
                        break;
                    } else {
                        temp = temp->Left;
                    }
                } else {
                    throw invalid_argument("Duplicate Value!");
                }
            }
        }
    }
    bool FindIterative(T value) {
        Node<T>* temp = root;
        if(!temp) {
            return false;
        }
        while(temp) {
            if(temp->Value == value) {
                return true;
            } else if(temp->Value > value) {
                temp = temp->Left;
            } else if(temp->Value < value) {
                temp = temp->Right;
            }
        }
        return false;
    }
    bool FindUsingRecursion(T value) {
        return FindRecursionInternal(this->root, value);
    }
    void inOrderTraversal() {
        return inOrderTraversalInternal(this->root);
    }
    void inOrderTraversalReversed() {
        return inOrderTraversalInternalReversed(this->root);
    }
    void preOrderTraversal() {
        return preOrderTraversalInternal(this->root);
    }
    void postOrderTraversal() {
        return postOrderTraversalInternal(this->root);
    }
};