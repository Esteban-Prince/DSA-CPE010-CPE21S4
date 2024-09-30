#include<iostream>

using namespace std;

//Write a C++ program t create a singly liked list of prime numbers less than 20. By iterating through the list, display all the prime numbers, the head, and the tail of the list.


// Create a struct to hold the data
struct Node {
  int data;
  Node* next;
};

// create new node

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// create linked list

Node* createPrimeList(int limit) {
  Node* head = nullptr;
  Node* tail = nullptr;

// check if prime number, if yes, then create a new node
  for (int i = 2; i < limit; i++) {
    if (isPrime(i)) {
      Node* newNode = new Node;
      newNode->data = i;
      newNode->next = nullptr;

      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }
  }

  return head;
}

// display the linked list

void displayList(Node* head) {
  cout << "Prime numbers in the list: ";
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Main function to output the code
int main() {
  Node* head = createPrimeList(20);

  cout << "Head: " << head->data << endl;

  Node* tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  cout << "Tail: " << tail->data << endl;

  displayList(head);

  // Clean up the list
  Node* temp = head;
  while (temp != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }

  return 0;
}