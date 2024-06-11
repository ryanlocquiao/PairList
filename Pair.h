/*
 * Author: Ryan Locquiao
 * File  : Pair.h
 * Date  : 03/30/2024
 * Description: Pair is an object that holds a pair of two different data types.
 */

#ifndef CS_211_PROJECT9_PAIR_H
#define CS_211_PROJECT9_PAIR_H

#endif //CS_211_PROJECT9_PAIR_H

#include <iostream>

using std::cout;

/**
 * @notes Added two functions to help LinkedList work. Check bool operator == & !=.
 */

template <class F, class S>
class Pair {
private:
    F first;                        /**< First Value Pair */
    S second;                       /**< Second Value Pair */

public:
    // Constructors
    /**
     * @brief Default constructor that initializes the data section
     */
    Pair() : first(), second() {}

    /**
     * @brief Overloaded constructor that sets the arguments to the data section
     * @param firstValue - first value to parse
     * @param secondValue - second value to parse
     */
    Pair(F firstValue, S secondValue) : first(firstValue), second(secondValue) {}

    // Getter Methods
    /**
     * @brief Gets the first value in the pair
     * @return The first value in the pair
     */
    F getFirst() const {
        return first;
    }

    /**
     * @brief Gets the second value in the pair
     * @return The second value in the pair
     */
    S getSecond() const {
        return second;
    }

    // Setter Methods
    /**
     * @brief Sets the argument to the data section
     * @param value - value to parse
     */
    void setFirst(F value) {
        first = value;
    }

    /**
     * @brief Sets the argument to the data section
     * @param value - value to parse
     */
    void setSecond(S value) {
        second = value;
    }

    // Added Functions
    /**
     * @brief Function made to solve no matching operator error in deleteNode
     * @param element - element of a Pair
     * @return True or False
     * @notes My refactored deleteNode function form LinkedList could not find
     * search with the default operator ==, because T was of type Pair, so I made
     * this function inside of Pair for LinkedList since it was having trouble
     * detecting T for type Pair
     */
    bool operator==(const Pair& element) const {
        return first == element.first && second == element.second;
    }

    /**
     * @brief Function made to solve no matching operator error in deleteNode
     * @param element - element of a Pair
     * @return True or False
     * @notes My refactored deleteNode function form LinkedList could not find
     * search with the default operator !=, because T was of type Pair, so I made
     * this function inside of Pair for LinkedList since it was having trouble
     * detecting T for type Pair
     */
    bool operator!=(const Pair& element) const {
        return first != element.first || second != element.second;
    }
};