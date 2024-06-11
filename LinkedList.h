/*
 * Author: Ryan Locquiao
 * File  : LinkedList.h
 * Date  : 03/30/2024
 * Description: LinkedList is an object that stores data.
 */

#ifndef CS_211_PROJECT9_LINKEDLIST_H
#define CS_211_PROJECT9_LINKEDLIST_H

#endif //CS_211_PROJECT9_LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <cstdlib>

using std::cout;

template <class T>
class LinkedList {
private:
    Node<T>* head;    /**< Variable used for anchoring the head of LinkedList */

public:
    // Constructor
    /**
     * @brief Default constructor to initialize the head
     * @notes Copied from lecture.
     */
    LinkedList() : head(NULL) {}

    // Functionality
    /**
     * @brief Creates a new node and adds it to the end of the list
     * @param data - value to parse
     * @notes Copied from lecture, but refactored to be templated and changed up
     * some variable names to be a little more obvious.
     */
    void addToEnd(T data) {
        if (head == NULL) {
            head = new Node<T>();
            head->Data = data;
            head->Next = NULL;
        } else {
            Node<T>* pointer = this->head;

            while (pointer->Next != NULL) {
                pointer = pointer->Next;
            }

            Node<T>* newNode = new Node<T>;
            newNode->Data = data;
            newNode->Next = NULL;

            pointer->Next = newNode;
        }
    }

    /**
     * @brief Inserts a new node between nodes
     * @param search - node to search
     * @param data - value to parse
     * @notes Copied from lecture, but refactored to be templated and changed up
     * some variable names to be a little more obvious.
     */
    void insert(T search, T data) {
        Node<T>* pointer = head;

        while (pointer->Data != search) {
            pointer = pointer->Next;
        }

        Node<T>* newNode = new Node<T>;
        newNode->Data = data;

        newNode->Next = pointer->Next;
        pointer->Next = newNode;
    }

    /**
     * @brief Deletes a node in the list
     * @param search - node to search
     * @notes Had a bit of trouble with getting the lecture code getting to work
     * in some cases, so I had redone it completely. Comments are left within
     * function.
     */
    void deleteNode(T search) {
        // Check if there is data in head and if it matches search and if so
        // set it to temp and delete
        if (head != NULL && head->Data == search) {
            Node<T>* temp = head;
            head = head->Next;
            delete temp;
            return; // Exit function if search was successful
        }

        Node<T>* temp = head;

        // Traverse the lust until we find our node
        while (temp != NULL && temp->Next->Data != search) {
            temp = temp->Next;
        }

        // If no matching node, exit
        if (temp->Next == NULL) return;

        // If node found, delete
        Node<T>* nodeToDelete = temp->Next;
        temp->Next = temp->Next->Next;

        delete nodeToDelete;
    }

    /**
     * @brief Prints out each node in the list
     * @notes Copied from lecture, but modified variable names to be more obvious
     * and removed the use of .c_str() as it seemed unnecessary and caused my code
     * to no function properly when using type int.
     */
    void printList() {
        Node<T>* pointer = head;

        while (pointer != NULL) {
            cout << pointer->Data << "\n";
            pointer = pointer->Next;
        }
    }

    /**
     * @brief Checks to see if a node is in the list
     * @param search - node to search
     * @return True or False
     * @notes Written similarly to the other functions, but just made to return
     * either true or false depending on whether search was found.
     */
    bool contains(T search) {
        Node<T>* pointer = head;

        while (pointer != NULL) {
            if (pointer->Data == search) {
                //cout << "List Contains " << search << "\n"; // Debugging
                return true;
            }
            pointer = pointer->Next;
        }

        //cout << "List Does Not Contain " << search << "\n"; // Debugging
        return false;
    }

    // Added Functions
    /**
     * @brief Allows access to the LinkedList head
     * @return Head
     * @notes Added function made to allow other classes to access the head of
     * a LinkedList.
     */
    Node<T>* getHead() const {
        return head;
    }
};