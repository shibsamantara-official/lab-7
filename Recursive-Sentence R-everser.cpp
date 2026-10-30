#include <iostream>
#include <string>

using namespace std;

class SentenceReverser {
private:
    string sentence;

    // Private recursive method
    void reverseHelper(int index) const {
        if (index == sentence.length()) {
            return;
        }
        reverseHelper(index + 1);
        cout << sentence[index];
    }

public:
    SentenceReverser(const string& str) : sentence(str) {}

    void setSentence(const string& str) {
        sentence = str;
    }

    void printReversed() const {
        cout << "Reversed sentence: ";
        reverseHelper(0);
        cout << '\n';
    }
};

int main() {
    string input;
    cout << "Enter a sentence to reverse: ";
    getline(cin, input);
    
    SentenceReverser reverser(input);
    reverser.printReversed();
    
    return 0;
}