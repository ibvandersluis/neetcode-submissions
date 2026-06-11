struct ListNode {
    int val;
    ListNode* next; // toward tail
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class LinkedList {
private:
    size_t size;
    ListNode* head;
    ListNode* tail;

    ListNode* find(int index) {
        ListNode* itr = head;
        for (size_t i = 0; i < index; ++i) {
            itr = itr->next;
        }
        return itr;
    }

public:
    LinkedList() : size(0), head(nullptr), tail(nullptr) {}

    int get(int index) {
        if (index >= size) {
            return -1;
        }
        return find(index)->val;
    }

    void insertHead(int val) {
        head = new ListNode(val, head);
        tail = tail ? tail : head;
        size++;
    }
    
    void insertTail(int val) {
        ListNode* new_tail = new ListNode(val);
        if (tail) {
            tail->next = new_tail;
        }
        tail = new_tail;
        head = head ? head : tail;
        size++;
    }

    bool remove(int index) {
        if (index >= size) {
            return false;
        }
        ListNode* target = find(index);
        if (target == head) {
            head = head->next;
        } else if (target == tail) {
            tail = find(index - 1);
        } else {
            ListNode* prev = find(index - 1);
            ListNode* next = target->next;
            prev->next = next;
        }
        delete target;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        ListNode* itr = head;
        while (itr != nullptr) {
            values.push_back(itr->val);
            itr = itr->next;
        }
        return values;
    }
};
