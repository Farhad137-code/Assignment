#include <iostream>
#include <stack>
using namespace std;


struct Page {
    string url;
    string title;

    Page(string u, string t) {
        url = u;
        title = t;
    }
};

class BrowsingHistory {
private:
    stack<Page> historyStack;

public:
    void addNewVisitedURL(string url, string title) {
        Page newPage(url, title);
        historyStack.push(newPage);
        cout << "Visited: " << title << " (" << url << ")" << endl;
    }

    void clearBrowsingHistory() {
        while (!historyStack.empty()) {
            historyStack.pop();
        }
        cout << "Browsing history cleared!" << endl;
    }

  
    void displayBrowsingHistory() {
        if (historyStack.empty()) {
            cout << "No browsing history to display!" << endl;
            return;
        }

        stack<Page> tempStack = historyStack; 
     
        cout << "Browsing History (Most recent to oldest):" << endl;

       
        while (!tempStack.empty()) {
            Page page = tempStack.top();
            cout << "Title: " << page.title << ", URL: " << page.url << endl;
            tempStack.pop();
        }
    }
};

int main() {
    BrowsingHistory bh;

   
    bh.addNewVisitedURL("https://www.example.com", "Example Website");
    bh.addNewVisitedURL("https://www.google.com", "Google");
    bh.addNewVisitedURL("https://www.github.com", "GitHub");

   
    bh.displayBrowsingHistory();

    bh.clearBrowsingHistory();

   
    bh.displayBrowsingHistory();

    return 0;
}