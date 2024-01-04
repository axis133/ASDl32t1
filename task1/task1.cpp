#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Set {
private:
    set<char> elements;

public:
    void add(char element) {
        elements.insert(element);
    }

    void remove(char element) {
        elements.erase(element);
    }

    bool contains(char element) {
        return elements.count(element) > 0;
    }
};

bool isVoicedConsonant(char letter) {
    set<char> voicedConsonants = { 'b', 'd', 'g', 'v', 'z', 'j' };
    return voicedConsonants.count(letter) > 0;
}

bool isVoicelessConsonant(char letter) {
    set<char> voicelessConsonants = { 'p', 't', 'k', 'f', 's', 'h' };
    return voicelessConsonants.count(letter) > 0;
}

int main() {
    vector<string> words = { "apple", "banana", "orange", "cat" };

    Set voicedConsonantsSet;
    Set voicelessConsonantsSet;

    for (int i = 0; i < words.size(); i++) {
        if (i % 2 != 0) {
            for (char letter : words[i]) {
                if (isVoicedConsonant(letter)) {
                    voicedConsonantsSet.add(letter);
                }
                else if (isVoicelessConsonant(letter)) {
                    voicelessConsonantsSet.add(letter);
                }
            }
        }
        else {
            for (char letter : words[i]) {
                if (voicedConsonantsSet.contains(letter)) {
                    voicedConsonantsSet.remove(letter);
                }
                else if (voicelessConsonantsSet.contains(letter)) {
                    voicelessConsonantsSet.remove(letter);
                }
            }
        }
    }

    cout << "Звонкие согласные в нечетных словах: ";
    for (char element : voicedConsonantsSet) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Глухие согласные в нечетных словах: ";
    for (char element : voicelessConsonantsSet) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
