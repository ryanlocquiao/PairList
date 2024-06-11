/*
 * Author: Ryan Locquiao
 * File  : PairList.h
 * Date  : 03/30/2024
 * Description: PairList is an object that holds a list of Pairs.
 */

#ifndef CS_211_PROJECT9_PAIRLIST_H
#define CS_211_PROJECT9_PAIRLIST_H

#endif //CS_211_PROJECT9_PAIRLIST_H

#include "Pair.h"
#include "LinkedList.h"

template <class F, class S>
class PairList : public LinkedList<Pair<F, S>> {
public:
    /**
     * @brief Adds a Pair to the list
     * @param first - value to parse
     * @param second - value to parse
     */
    void addPair(F first, S second) {
        this->addToEnd(Pair<F, S>(first, second));
    }

    /**
     * @brief Searches for the first element of a pair using the second element
     * @param second - second element used to search
     * @return The first element of that pair
     */
    F getFirst(S second) const {
        Node<Pair<F, S>>* pointer = this->getHead();

        while (pointer != NULL) {
            if (pointer->Data.getSecond() == second) {
                return pointer->Data.getFirst();
            }
            pointer = pointer->Next;
        }
    }

    /**
     * @brief Searches for the second element of a pair using the first element
     * @param first - first element used to search
     * @return The second element of that pair
     */
    S getSecond(F first) const {
        Node<Pair<F, S>>* pointer = this->getHead();

        while (pointer != NULL) {
            if (pointer->Data.getFirst() == first) {
                return pointer->Data.getSecond();
            }
            pointer = pointer->Next;
        }
    }

    /**
     * @brief Deletes the pair given in the argument
     * @param first - value to parse
     * @param second - value to parse
     */
    void deletePair(F first, S second) {
        Pair<F, S> pair(first, second);
        this->deleteNode(pair);
    }

    /**
     * @brief Prints the entire list of Pairs
     */
    void printList() {
        cout << "Printing List...\n";

        Node<Pair<F, S>>* pointer = this->getHead();

        while (pointer != NULL) {
            cout << "(" << pointer->Data.getFirst() << ", " << pointer->Data.getSecond() << ")\n";
            pointer = pointer->Next;
        }

        cout << "List Printed\n";
    }
};