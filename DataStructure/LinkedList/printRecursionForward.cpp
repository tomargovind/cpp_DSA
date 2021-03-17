#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printLinkedList(Node *temp)
{
    if (temp == NULL)
    {
        cout << endl;
        return;
    }
    cout << temp->data << " ";
    printLinkedList(temp->next);
}

int main()
{
    Node *head = new Node();
    head->data = 2;
    head->next = NULL;

    int n;
    cin >> n;

    Node *temp2 = head;
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp2->next = temp;
        cin >> temp->data;
        temp->next = NULL;
        temp2 = temp;
    }

    printLinkedList(head);

    return 0;
}