template <class T>
class ArrayList {
    int size;
    int currentIndex;
    T* nodes;

    void ExpandArray() {
        T* newArray = new T[size + 10];
        for(int i=0;i<size;i++) {
            newArray[i] = nodes[i];
        }
        delete [] nodes;
        nodes = newArray;
        size+10;
    }

public:
    ArrayList(int size) {
        this->size = size;
        currentIndex = 0;
        nodes = new T[size];
    }

    ~ArrayList() {
        if(nodes) {
            delete [] nodes;
            nodes = 0;
        }
    }


    void Add(T item) {
        if(!nodes) {
            size = 10;
            nodes = new T[size];
        }

        if (currentIndex == size)
        {
            ExpandArray();
        }

        nodes[currentIndex] = item;
        currentIndex++;
    }

    void Insert(T item, int index) {
        if(index >= currentIndex || index < 0) {
            throw invalid_argument("Out of Range");
        }
        if(size == currentIndex) {
            ExpandArray();
        }
        for(int i = currentIndex; i > index; i--) {
            nodes[i] = nodes[i-1];
        }
        currentIndex++;
        nodes[index] = item;
    }

    int FindByElement(T item) {
        for(int i = 0; i <= currentIndex; i++) {
            if(nodes[i] == item) {
                return i;
            }
        }
        return -1;
    }

    T FindByIndex(int index) {
        if(index >= currentIndex || index < 0) {
            throw invalid_argument("Out of Range");
        }
        return nodes[index];
    }

    void Delete(int index) {
        if(index >= currentIndex || index < 0) {
            throw invalid_argument("Out of Range");
        }
        for(int i = index; i < currentIndex; i++) {
            nodes[i] = nodes[i + 1];
        }
        currentIndex--;
    }

    void DeleteRange(int from, int to) {
        // Using code logic #1
        int numberOfElementsToBeShifted = to - from + 1;
        for(int i = from; i < currentIndex; i++) {
            nodes[i] = nodes[i + numberOfElementsToBeShifted];
        }
        currentIndex -= numberOfElementsToBeShifted;

        // Using Delete Function #2
        //for(int i = to; i>= from; i--) {
        //   Delete(i);
        //}
    }

    void erase() {
        currentIndex = 0;
    }

    int getCurrentIndex()
    {
        return currentIndex;
    }

    T& operator[](int index) {
        if(index >= currentIndex || index < 0) {
            throw invalid_argument("Out of Range");
        }
        return nodes[index];
    }
};