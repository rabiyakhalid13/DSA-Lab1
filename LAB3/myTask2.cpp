#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StringPool {
private:
    string** stringPool;
    int currentSize;
    int maxSize;

    vector<string*> leakedPointers;

    int totalAllocations;
    int totalDeallocations;

public:
    StringPool() {
        maxSize = 5;
        currentSize = 0;
        totalAllocations = 0;
        totalDeallocations = 0;
        stringPool = new string*[maxSize];
        for (int i = 0; i < maxSize; i++) {
            stringPool[i] = nullptr;
        }
        cout << "[StringPool] Created with capacity " << maxSize << "\n";
    }

    ~StringPool() {
        delete[] stringPool;
        cout << "[StringPool] Destroyed.\n";
    }

    void addString(const string& value) {
        if (currentSize >= maxSize) {
            cout << "Pool is full. Cannot add \"" << value << "\"\n";
            return;
        }
        stringPool[currentSize] = new string(value);
        totalAllocations++;
        currentSize++;
        cout << "Added: \"" << value << "\"\n";
    }

    void removeString(int index) {
        if (index < 0 || index >= currentSize) {
            cout << "Invalid index: " << index << "\n";
            return;
        }

        cout << "Removing: \"" << *stringPool[index]
             << "\" (memory not freed thus potential leak)\n";

        leakedPointers.push_back(stringPool[index]);

        for (int i = index; i < currentSize - 1; i++) {
            stringPool[i] = stringPool[i + 1];
        }
        stringPool[currentSize - 1] = nullptr;
        currentSize--;
    }

    // detects whether any memory has leaked by comparing allocations
    void detectMemoryLeaks() const {
        int leakedCount = static_cast<int>(leakedPointers.size());
        cout << "\n--- Memory Leak Detection ---\n";
        cout << "Total allocations: " << totalAllocations << "\n";
        cout << "Total deallocations: " << totalDeallocations << "\n";
        if (leakedCount > 0) {
            cout << "Leak detected: " << leakedCount
                 << " string(s) removed from the pool were never freed.\n";
        } else {
            cout << "No leaks detected.\n";
        }
        cout << "\n";
    }

    // fixes the leak by deleting every orphaned pointer
    void fixMemoryLeaks() {
        cout << "\nFixing leaks: deleting " << leakedPointers.size()
             << " orphaned string(s)...\n";
        for (string* ptr : leakedPointers) {
            delete ptr;
            totalDeallocations++;
        }
        leakedPointers.clear();
        cout << "All leaked memory has been freed.\n";
    }

    // displays the current status of the pool
    void displayPool() const {
        cout << "\nPool status (" << currentSize << "/" << maxSize << "):\n";
        for (int i = 0; i < currentSize; i++) {
            cout << "  [" << i << "] " << *stringPool[i] << "\n";
        }
        if (currentSize == 0) {
            cout << "  (empty)\n";
        }
    }
};

int main() {
    StringPool pool;

    cout << "\nAdding strings\n";
    pool.addString("diamond");
    pool.addString("amethyst");
    pool.addString("ruby");
    pool.addString("sapphire");
    pool.addString("topaz");

    pool.displayPool();

    cout << "\nRemoving strings without freeing memory\n";
    pool.removeString(0);
    pool.removeString(1);

    pool.displayPool();

    // detect the leak we just created
    pool.detectMemoryLeaks();

    // fix it by deleting the orphaned pointers
    pool.fixMemoryLeaks();

    // confirm the leak is gone
    pool.detectMemoryLeaks();

    pool.displayPool();

    return 0;
}