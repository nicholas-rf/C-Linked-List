#include <iostream>
#include "MyLinkedList.h"

/* CIS 25, Nicholas Roze-Freitas, this project re-implements MyVector but by using linked lists */

MyLinkedList::MyLinkedList(void){
  // This function is a constructor that creates a linked list with 10 spaces set to 0
  for(int space = STARTING_POSITION; space < STANDARD_SPACE; space++){
    pushBack(STANDARD_ENTRY);
  } 
}
MyLinkedList::MyLinkedList(int listSize){
  // This function is a constructor that creates a linked list with listSize spaces filled with 0's
  for(int space = STARTING_POSITION; space < listSize; space++){
    pushBack(STANDARD_ENTRY);
  }
  
}
MyLinkedList::MyLinkedList(int listSize, int listEntry){
  // This function is a constructor that creates a linked list with listSize spaces filled with listEntry as data
  for(int space = STARTING_POSITION; space < listSize; space++){
    pushBack(listEntry);
  }
}
MyLinkedList::MyLinkedList(MyLinkedList &list){
  // This function is a copy constructor that takes a reference to a linked list and then creates a copy of it
  listNode *current = new listNode;
  current = list.head;
  while(current != nullptr){
    pushBack(current->data);
    current = current->next;
  }
  
}
listNode* MyLinkedList::lastElement(){
  // This function loops through the list and then returns the last element
  listNode *current = new listNode;
  current = head;
  while(current->next != nullptr){
    current = current->next;
  }
  listNode *lastElementAddress = new listNode;
  lastElementAddress = current;
  return lastElementAddress;
}
std::ostream& operator<<(std::ostream& outStream, MyLinkedList& list){
  // This function overloads the << operator so that you can cout a linked list
  std::string listString = "["; 
  if (list.head != nullptr) { 
    listNode *temporary = list.head; 
    while(temporary != nullptr){ 
      listString += std::to_string(temporary->data); 
      temporary = temporary->next;
      if(temporary == nullptr){
        break;
      } else {
        listString += ", ";
      }
    }
    listString += "]"; 
    outStream << listString; 
    return outStream; 
  } else { 
    listString = "List is empty"; 
    outStream << listString;
    return outStream; 
  }
}
int& MyLinkedList::operator[](int accessPosition){
  // This function overloads the [] operator so you can pass it on a linked list and access the value at that position
  if (accessPosition < STARTING_POSITION || head == nullptr){
    if (accessPosition < STARTING_POSITION){
      std::cout << "Invalid position" << std::endl;
    } else {
      std::cout << "List is empty" << std::endl;
    }
    
  } else {
    listNode *current = new listNode;
    current = head; 
    for(int position = STARTING_POSITION; position < accessPosition; position++){
      current = current->next;
    }
    return current->data; 

  }
  
}
void MyLinkedList::pushBack(int value){
  // This function adds a value to the back of a linked list
  storedSpace++;
  listNode *newNode = new listNode;
  newNode->data = value; 
  if (head == nullptr){
    head = newNode; 
    head->next = nullptr;
    return; 
  }
  listNode *current = new listNode;
  current = head;
  while (current->next != nullptr){
    current = current->next;
  }
  current->next = newNode;
  newNode->next = nullptr;
  return;
}
int MyLinkedList::popBack() {
  // This function returns and removes the last value from a linked list
  if (head != nullptr && storedSpace > 1) {
    storedSpace--;
    listNode *lastElementAddress = lastElement(); 
    listNode *current = new listNode;
    current = head; 
    while(current->next != lastElementAddress){ 
      current = current->next;
    }
    int popValue = lastElementAddress->data; 
    current->next = nullptr; 
    return popValue;
  } else if (storedSpace == 1) {
    storedSpace--;
    int popValue = head->data; 
    head = nullptr; 
    //std::cout << test << std::endl;
    return popValue;
  } else {
    std::cout << "List is empty" << std::endl;
  }
}
void MyLinkedList::insert(int insertPosition, int value){
  // This function inserts a value and insertPosition
  if(head != nullptr){
    if (insertPosition > STARTING_POSITION && insertPosition <= storedSpace){
    storedSpace++;
    listNode *current = new listNode;
    current = head;
    for(int position = STARTING_POSITION; position < insertPosition-1; position++){
      current = current->next;
    }
    listNode *insertedNode = new listNode; 
    insertedNode->data = value; 
    listNode *savedAddress = current->next; 
    current->next = insertedNode;
    insertedNode->next = savedAddress;
    } else if (insertPosition == STARTING_POSITION) {
      storedSpace++;
      listNode *newHead = new listNode;
      newHead->data = value;
      newHead->next = head;
      newHead = head;
    } else if (insertPosition > storedSpace){
      pushBack(value);
    } else {
      std::cerr << "Insert position is out of bounds" << std::endl;
    }
  } else {
    storedSpace++;
    listNode *current = new listNode;
    head = current;
    head->data = value;
    head->next = nullptr;
  }
  
}
void MyLinkedList::remove(int removePosition){
  // This function removes the value at removePosition
  if(head != nullptr){
    if (removePosition > STARTING_POSITION && removePosition <= storedSpace){
    storedSpace--;
    listNode *current = new listNode;
    current = head;
    for (int position = STARTING_POSITION; position < removePosition-1;position++){
      current = current->next;
    }
    listNode *tempAddress = current->next;
    listNode *afterRemoveAddress = tempAddress->next;
    current->next = afterRemoveAddress;
    delete [] tempAddress;
  } else if (removePosition == STARTING_POSITION) {
    if (storedSpace == 1){
      storedSpace--;
      head = nullptr; 
    } else {
        storedSpace--;
        listNode *tempAddress = head->next; 
        head = nullptr;
        head = tempAddress; 
      }
    } else if (removePosition > storedSpace) {
    storedSpace--;
    listNode *lastElementAddress = lastElement(); 
    listNode *current = new listNode;
    current = head; 
    while(current->next != lastElementAddress){ 
      current = current->next;
    }
    current->next = nullptr; 
    }
  } else {
    std::cerr << "Cannot remove list is empty" << std::endl;
  }
}
int& MyLinkedList::at(int atPosition){
  // This function returns a pointer to the position specified at atPosition
  if (head != nullptr && atPosition >= STARTING_POSITION && atPosition <= storedSpace) {
    listNode *current = new listNode; // creates a new list node
    current = head; // sets the nodes address to head
    for(int position = STARTING_POSITION; position < atPosition; position++){
      current = current->next; // loops until current is what we want to return
    }
    return current->data; 
  } else {
    if (head == nullptr) {
      std::cerr << "List is empty" << std::endl;
    } else {
      std::cerr << "Index out of range" << std::endl;
    }
    exit(0);
  }
}
