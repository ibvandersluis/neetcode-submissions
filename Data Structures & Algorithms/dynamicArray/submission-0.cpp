class DynamicArray {
public:

    DynamicArray(int capacity) : size(0), capacity(capacity) {
        int new_arr[capacity];
        data = new int[capacity];
    } 

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = n;
    }

    int popback() {
        return data[--size];
    }

    void resize() {
        capacity *= 2;
        int* new_arr = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_arr[i] = data[i];
        }
        delete data;
        data = &new_arr[0];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
private:
    size_t size;
    size_t capacity;
    int* data;
};
