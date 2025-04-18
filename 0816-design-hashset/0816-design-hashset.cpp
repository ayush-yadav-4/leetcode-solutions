class MyHashSet {
private:
    static const int SIZE = 1009; // use a prime number for better hash distribution
    std::vector<std::list<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        table.resize(SIZE);
    }

    void add(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return; // already exists
        }
        table[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove(key); // std::list has remove()
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return true;
        }
        return false;
    }
};