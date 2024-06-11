/*
 * Author: Ryan Locquiao
 * File  : main.cpp
 * Date  : 03/30/2024
 * Description: Main file used for testing LinkedList and PairList functionality.
 */

#include "PairList.h"

using std::string;

int main() {
    // Testing LinkedList functionality
    LinkedList<string> list;

    list.addToEnd("Hello");
    list.addToEnd("And");
    list.addToEnd("Goodbye");
    list.printList();
    cout << list.contains("And") << "\n";

    cout << "===========================\n";

    list.deleteNode("And");
    list.printList();

    cout << "===========================\n";

    cout << list.contains("And") << "\n";
    list.insert("Hello", "And Then");
    list.printList();

    // Testing PairList functionality
    cout << "Testing PairList functionality...\n";
    cout << "===========================\n";

    PairList<int, int> pairList;

    pairList.addPair(69, 420);
    pairList.printList();
    pairList.deletePair(69, 420);

    cout << "===========================\n";

    // Testing PairList Getters
    cout << "Testing PairList Getters...\n";
    cout << "===========================\n";

    PairList<string, int> pairList2;

    pairList2.addPair("John", 1);
    pairList2.addPair("Jane", 2);
    pairList2.addPair("Alfa Romeo", 3);

    pairList2.printList();

    cout << "First Pair: (" << pairList2.getFirst(1) << ", " << pairList2.getSecond("John") << ")\n";
    cout << "Second Pair: (" << pairList2.getFirst(2) << ", " << pairList2.getSecond("Jane") << ")\n";
    cout << "Third Pair: (" << pairList2.getFirst(3) << ", " << pairList2.getSecond("Alfa Romeo") << ")\n";

    cout << "===========================";

    return 0;
}