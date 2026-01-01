/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        unordered_map<Node *, Node *> mp;

        Node *newHead = new Node(head->val);
        Node *newTemp = newHead;
        Node *oldTemp = head->next;
        mp[head] = newHead;

        while (oldTemp != NULL)
        {
            Node *newNode = new Node(oldTemp->val);
            newTemp->next = newNode;

            newTemp = newTemp->next;
            mp[oldTemp] = newTemp;
            oldTemp = oldTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL)
        {
            newTemp->random = mp[oldTemp->random];
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        return newHead;
    }
};