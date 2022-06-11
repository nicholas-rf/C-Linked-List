#ifndef MYLINKEDLISTTYPE_H
#define MYLINKEDLISTTYPE_H
#include <iostream>

/* CIS 25, Nicholas Roze-Freitas, this project re-implements MyVector but by using linked lists*/

struct listNode{
    int data;
    listNode *next = nullptr;
};
const int STANDARD_SPACE = 10;
const int STANDARD_ENTRY = 0;
const int STARTING_POSITION = 0;

class MyLinkedList{
public:
  MyLinkedList(void);
  MyLinkedList(int listSize);
  MyLinkedList(int listSize, int listEntry);
  MyLinkedList(MyLinkedList& list);

  void shrink();
  void pushBack(int value);
  int popBack();
  void insert(int insertPosition, int value);
  void remove(int removePosition);
  int& at(int atPosition);
  void printLinkedList();
  friend std::ostream& operator<<(std::ostream& outStream, MyLinkedList& list);
  int& operator[](int accessPosition);
  

private:
  int storedSpace = 0; 
  listNode *lastElement();
  listNode *head = nullptr;
  listNode *addNode(listNode *head, int data);
  
  
};


#endif