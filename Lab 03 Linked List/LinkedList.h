//
//  LinkedList.hpp
//  Lab 03 Linked List
//
//  Created by C/R
//

#include <sstream>
#include <string>
#include "LinkedListInterface.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/** Linked List */
template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
   struct Node
   {
      T data;
      Node* next;
      Node(const T& d) : data(d), next(NULL) {}
      Node(const T& d, Node* n, Node* p) : data(d), next(n) {}
   };
   Node* head;

public:
   LinkedList() { this->head = NULL;}
   ~LinkedList() { clear(); }
   
   // Insert Node at beginning of list
   void push_front(const T& d)
   {
      if (head == NULL)
      {
         head = new Node(d);
         return;
      }
      Node* temp = head;
      head = new Node(d);
      head->next = temp;
      return;
   }
    
   // Remove Node at beginning of linked list
   void pop_front(void)
   {
      if (head != NULL)
      {
         if (head->next == NULL)
         {
            Node* temp = head;
            delete temp;
            head = NULL;
         }
         else
         {
            Node* ptr = head;
            Node* temp = head->next;
            head = temp;
            if (ptr == NULL) return;
            delete ptr;
         }
      }
      else
      {
         throw std::string("Empty!");
      }
   }
   
    // Return reference to value of Node at beginning of linked list
   T& front() { return head->data; }

    // Return true if linked list size == 0
   bool empty() const
   {
      if (head == NULL)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   //Remove all Nodes with a certain value
   void remove(const T& value)
   {
      Node* ptr = head;
      Node* temp = head;
      while (ptr->next != NULL)
      {
        if (head->data == value)
        {
           head = ptr->next;
           delete ptr;
           ptr = head;
           continue;
        }
         else if (ptr->next->data == value)
         {
            temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
         }
         if (ptr->next == NULL) continue;
         ptr = ptr->next;
      }
      if (head->data == value)
            {
               head = ptr->next;
               delete ptr;
            }
   }
    
    // Remove all Nodes from linked list
   void clear(void)
   {
      Node* ptr = head;
      Node* temp = head;
      while (ptr != NULL)
      {
         temp = ptr;
         //std::cout << ptr->data << std::endl;
         ptr = ptr->next;
         delete temp;
      }
      head = NULL;
   }
 
    // Reverse Nodes in linked list
   void reverse()
   {
      Node* ptr = head;
      Node* next;
      Node* prev = NULL;
      while (ptr != NULL)
      {
         next = ptr->next;
         ptr->next = prev;
         prev = ptr;
         ptr = next;
      }
      head = prev;
   }

    // Return the number of nodes in the linked list
   size_t size(void) const
   {
      if (empty()) return 0;
      int numItems = 0;
      Node* temp = head;
      while (temp != NULL)
      {
         temp = temp->next;
         ++numItems;
      }
      return numItems;
   }
   
   // Overrides the extraction operator
   friend std::ostream& operator<<(std::ostream& os, const LinkedList& myClass)
   {
      return os << myClass.toString();
   }

   // Return contents of Linked List as a string
   std::string toString(void) const
   {
      try
      {
         if (empty()) throw std::string(" Empty!");
         std::ostringstream os;
         Node* ptr = head;
         while (ptr != NULL)
         {
            os << ptr->data;
            if (ptr->next != NULL) os << " ";
            ptr = ptr->next;
         }
         return os.str();
      } catch (std::string& errorString)
      {
         return errorString;
      }
   }
};

#endif   // LINKED_LIST_H



