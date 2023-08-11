// CPP Program to implement self-organizing list
// using count method
#include <iostream.h>
#include <cstdlib.h>
using namespace std;
  
// structure for self organizing list
struct self_list {
    int value;
    int count;
    struct self_list* next;
};
  
// head and rear pointing to start and end of list resp.
self_list *head = NULL, *rear = NULL;
  
// function to insert an element
void insert_self_list(int number)
{
    // creating a node
    self_list* temp = (self_list*)malloc(sizeof(self_list));
  
    // assigning value to the created node;
    temp->value = number;
    temp->count = 0;
    temp->next = NULL;
  
    // first element of list
    if (head == NULL)
        head = rear = temp;
  
    // rest elements of list
    else {
        rear->next = temp;
        rear = temp;
    }
}
  
// function to search the key in list
// and re-arrange self-organizing list
bool search_self_list(int key)
{
    // pointer to current node
    self_list* current = head;
  
    // pointer to previous node
    self_list* prev = NULL;
  
    // searching for the key
    while (current != NULL) {
  
        // if key is found
        if (current->value == key) {
  
            // increment the count of node
            current->count = current->count + 1;
  
            // if it is not the first element
            if (current != head) {
                self_list* temp = head;
                self_list* temp_prev = NULL;
  
                // finding the place to arrange the searched node
                while (current->count < temp->count) {
                    temp_prev = temp;
                    temp = temp->next;
                }
  
                // if the place is other than its own place
                if (current != temp) {
                    prev->next = current->next;
                    current->next = temp;
  
                    // if it is to be placed at beginning
                    if (temp == head)
                        head = current;
                    else
                        temp_prev->next = current;
                }
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
  
// function to display the list
void display()
{
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
  
    // temporary pointer pointing to head
    self_list* temp = head;
    cout << "List: ";
  
    // sequentially displaying nodes
    while (temp != NULL) {
        cout << temp->value << "(" << temp->count << ")";
        if (temp->next != NULL)
            cout << " --> ";
  
        // incrementing node pointer.
        temp = temp->next;
    }
    cout << endl
         << endl;
}
  
// Driver Code
int main()
{
    /* inserting five values */
    insert_self_list(1);
    insert_self_list(2);
    insert_self_list(3);
    insert_self_list(4);
    insert_self_list(5);
  
    // Display the list
    display();
  
    search_self_list(4);
    search_self_list(2);
    display();
  
    search_self_list(4);
    search_self_list(4);
    search_self_list(5);
    display();
  
    search_self_list(5);
    search_self_list(2);
    search_self_list(2);
    search_self_list(2);
    display();
    return 0;
}
