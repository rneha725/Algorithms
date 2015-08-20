#include <iostream>
#include <cstdlib>

#define LIST head
typedef int TYPE;

using namespace std;

class listNode
{
public:
    TYPE info;
    listNode* link;

    listNode(TYPE info, listNode* link = NULL)
    {
        this->info = info;
        this->link = link;
    }
    void append(TYPE); // uses listNode pointer type to be called and inserts at the
    void insertAtFront(TYPE); // inserts at the beginning of the list
    void assignTail(); // assigns the tail of the list to tail pointer, use if you want to update tail for assurance
    void printLinear(); // prints using linear function body
    void printRecursive(); // prints using recursion
    int lengthLinear(); // gives legth of the linked list using linear body
    int lengthRecursive(); // returns length using recursion
    TYPE getInfo() {if(this == NULL) return -1; else return info;}
    listNode* getLink() {if(this == NULL) return NULL; else return link;}
    bool lookupLinear(TYPE); // searches for an element in linked list linearly
    bool lookupRecursive(TYPE); // searches using recursion
    void deleteNode(listNode*&); // deleting a given node from linked list
    void deleteNodeFake(listNode*&); // trick to delete a node
    listNode* getMiddleNode(); // returns middle node of linked list
    listNode* getNth(int); // return N-th node of the linked list
    void deleteList(); // deletes whole list
    listNode* reverseListRecursive(); // reverses linked list using recusrion
    void reverseListIterative(); // ...
    bool checkLoop(); // detects loop in linked list
    bool checkPalindrome(); //...
    void temp(listNode*); //just a temporary function doing some random stuff...
}*head = NULL, *tail = head, *globalVar = NULL;

void listNode::append(TYPE info)
{
    if(head == NULL)
    {
        if(info == -1);
        else
            head = new listNode(info, NULL);
    }
    else
    {
        listNode* current = head;
        while(current->link != NULL)
        {
            current  = current->link;
        }
        current->link = new listNode(info, NULL);
    }
}

void listNode::insertAtFront(TYPE info)
{
    listNode* newNode = new listNode(info, head);
    head = newNode;
}

void listNode::assignTail()
{
    if(this == NULL);
    else if(this->link == NULL)
        tail = this;
    else
    {
        listNode* current = this;
        while(current->link != NULL) current = current->link;
        tail = current;
    }
}

void listNode::printRecursive()
{
    if(this == NULL) return;
    else
    {
        cout<<this->info<<" ";
        this->link->printRecursive();
    }
}

void listNode::printLinear()
{
    if(this == NULL)
    {
        cerr<<"List empty.\n";
        return;
    }
    listNode* current = this; //after the function, current will be automtically deallocated, no use of free required
    while(current != NULL)
    {
        cout<<current->info<<" ";
        current = current->link;
    }
}

int listNode::lengthLinear()
{
    listNode* current = this; //after the function, current will be automtically deallocated
    int length = 0;
    while(current != NULL)
    {
        length++;
        current = current->link;
    }
    return length;
}

int listNode::lengthRecursive()
{
    if(this == NULL) return 0;
    else return 1 + link->lengthRecursive();
}

void listNode::temp(listNode* node) //just a temporary function doing some random stuff...
{
    node = new listNode(0, NULL);
}

bool listNode::lookupLinear(TYPE item)
{
    if(head == NULL) {return 0;}
    listNode* temp = head;
    while( temp != NULL)
    {
        if(temp->info == item) return 1;
        temp = temp->link;
    }
    return 0;
}

bool listNode::lookupRecursive(TYPE item)
{
    if(this == NULL) return 0;
    else if(this->info == item) return 1;
    else if(this->info != item) return this->link->lookupRecursive(item);
}

void listNode::deleteNode(listNode*& node)
{
    if(head == NULL)
    {
        cerr<<"Underflow"; return;
    }
    if(node->link == NULL)
    {
        node = NULL;
        return;
    }
    listNode* temp1;
    if(node == head)
    {
        temp1 = head;
        head = head->link;
        delete(temp1);
        return;
    }
    listNode* temp = head;
    while(temp->link != NULL)
    {
        if(temp->link == node) break;
        temp = temp->link;
    };
    temp1  = temp->link;
    temp->link = temp->link->link;
    delete(temp1);
    return;

}

void listNode::deleteNodeFake(listNode* &node)
{
    if(this == NULL)
    {
        cerr<<"Underflow";
        return;
    }
    if(node->link == NULL)
    {
        node = NULL;
        return;
    }
    listNode* temp = node->link;
    node->info = node->link->info;
    node->link = node->link->link;
    delete(temp);
}

listNode* listNode::getMiddleNode()
{
    if(this == NULL)
    {
        cout<<"Empty List.\n";
        return NULL;
    }
    if(this->link == NULL)
    {
        cerr<<"Only one element exists, no middle element.\n";
        return NULL;
    }
    if(this->link->link == NULL)
    {
        return this;
    }
    else
    {
        listNode* temp0 = this, *temp1 = this;
        while(temp0->link && temp1)
        {
            if(!temp1->link) break;
            temp0 = temp0->link;
            temp1 = temp1->link->link;
        }
        return temp0;
    }
}

listNode* listNode::getNth(int n)
{
    listNode* temp0 = this, *temp1 = this;
    if(head == NULL)
    {
        cout<<"Not allowed on an empty list.\n";
        return NULL;
    }
    while(n-- && temp1)
    {
        temp1 = temp1->link;
    }
    if(++n) { cerr<<"Node does not exist."; return NULL;}
    while(temp1 != NULL)
    {
        temp1 = temp1->link;
        temp0 = temp0->link;
    }
    return temp0;
}

void listNode::deleteList()
{
    if(this == NULL)
    {
        cerr<<"Underflow.";
        return;
    }
    listNode* temp = this, *temp1 = this;
    while(temp != NULL)
    {
        temp1 = temp->link;
        free(temp);
        temp = temp1;
    }
    head = NULL;
}

listNode* listNode::reverseListRecursive()
{
    if(this == NULL)
    {
        return NULL;
    }
    if(this->link == NULL) return this;
    listNode* current = this, *temp;
    if(current->link->link == NULL)
    {
        globalVar = current->link;
    }
    else
    {
        current->link->reverseListRecursive();
    }
    current->link->link = current;
    current->link = NULL;
    return globalVar;
}

// void listNode::reverseTailRecursion(listNode* current, listNode* previous, listNode*& head) //GFG tail recursion
// {
    // to be implemented
// }

bool listNode::checkLoop()
{
    Hashset newSet = new Hashset();
    listNode* node = this;
    while(node != NULL)
    {
        if(newSet.contains(node)) return 1;
        newSet.add(node);
        node = node->link;
    }
    return 0;
}

void listNode::reverseListIterative()
{

}

bool listNode::checkPalindrome()
{
    int n = this->lengthLinear();
    n = n/2;
    listNode* temp = this->getMiddleNode();
    temp->link->reverseListRecursive();
    temp = temp->link;
    while((n)--)
    {
        if(this->info != temp->info) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(n == -1) goto skip; // jump, in the case of empty string by user
    do {
        LIST->append(n);
        cin>>n;
    } while(n!=-1);
    skip:;
    head = head->link->reverseListRecursive();
    // head->deleteList();
    // cout<<head->getNth(2)->getInfo();
    // cout<<head->getMiddleNode()->getInfo();
    // listNode* newNode = new listNode(3,NULL);
    // head->deleteNodeFake(head);
    // cout<<head->lookupRecursive(1);
    // no input would be taken
    // head->insertAtFront(1);
    // cout<<head->lengthRecursive();
    // cout<<head->lengthLinear();
    // cout<<head->lengthRecursive();
    // head->temp(head);
    head->printLinear();
    // head->assignTail();
    // cout<<tail->getInfo();
    // delete(head);
    // cout<<head->getLink();
}
