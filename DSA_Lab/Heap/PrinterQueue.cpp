#include <iostream>
#include <queue>
#include <map>

using namespace std;

class PrinterQueue {
private:
    map<int, queue<std::string>> files;

public:
    void addNewRequest(int priority, string fileName) {
        if (files.find(priority) == files.end()) {
            queue<string> q;
            q.push(fileName);
            files[priority] = q;
        } else {
            files[priority].push(fileName);
        }
    }

    void print() {
        if (files.empty()) {
            cout << "No file to print" << endl;
            return;
        }

        auto highestPriority = files.rbegin();

        if (!highestPriority->second.empty()) {
            cout << highestPriority->second.front() << endl;
            highestPriority->second.pop();
        }

        if (highestPriority->second.empty()) {
            files.erase(highestPriority->first);
        }
    }
};

int main(){
    
}