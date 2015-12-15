#include <iostream>
#include <string>

using namespace std;

struct listNode
{
    int val;
    listNode *next;
    listNode(int x):val(x), next(nullptr){}
};

//recursively call

listNode *addTwoList(listNode *h1, listNode *e1, listNode *h2, listNode *e2, int carry, listNode *head)
{
    listNode *c1 = h1, *c2 = h2;
    if(h1 != e1 && h2 != e2)
    {
        for(;c1->next != e1; c1 = c1->next);
        for(;c2->next != e2; c2 = c2->next);
        listNode *nh = new listNode((c1->val + c2->val + carry) % 10);
        nh->next = head;
        int ncarry = (c1->val + c2->val) / 10;
        return addTwoList(h1, c1, h2, c2, ncarry, nh);
    }
    if(h1 != e1)
    {
        for(;c1->next != e1; c1 = c1->next);
        listNode *nh = new listNode((c1->val + carry) % 10);
        nh->next = head;
        int ncarry = (c1->val + carry) / 10;
        return addTwoList(h1, c1, h2, c2, ncarry, nh);
    }
    if(h2 != e2)
    {
        for(;c2->next != e2; c2 = c2->next);
        listNode *nh = new listNode((c2->val + carry) % 10);
        nh->next = head;
        int ncarry = (c2->val + carry) / 10;
        return addTwoList(h1, c1, h2, c2, ncarry, nh);
    }
    return head;
}

listNode *addTwoList(listNode *h1, listNode *h2)
{
    if(!h1) return new listNode(h2->val);
    if(!h2) return new listNode(h1->val);
    return addTwoList(h1, nullptr, h2, nullptr, 0, nullptr);
}

//non-recursive version
listNode *addTwoList2(listNode *h1, listNode *h2)
{
    if(!h1) return new listNode(h2->val);
    if(!h2) return new listNode(h1->val);
    listNode *c1 = h1, *c2 = h2, *e1 = nullptr, *e2 = nullptr, *head = nullptr;
    int carry = 0;
    while(h1 != e1 && h2 != e2)
    {
        for(c1 = h1;c1->next != e1; c1 = c1->next);
        for(c2 = h2;c2->next != e2; c2 = c2->next);
        listNode *nh = new listNode((c1->val + c2->val + carry) % 10);
        nh->next = head;
        carry = (c1->val + c2->val) / 10;
        e1 = c1;
        e2 = c2;
        head = nh;
    }
    while(h1 != e1)
    {
        for(c1 = h1; c1->next != e1; c1 = c1->next);
        listNode *nh = new listNode((c1->val + carry) % 10);
        nh->next = head;
        carry = (c1->val + carry) / 10;
        e1 = c1;
        head = nh;
    }
    while(h2 != e2)
    {
        for(c2 = h2;c2->next != e2; c2 = c2->next);
        listNode *nh = new listNode((c2->val + carry) % 10);
        nh->next = head;
        int ncarry = (c2->val + carry) / 10;
        e2 = c2;
        head = nh;
    }
    return head;
}


int main()
{
    // Solution so;
    listNode *A[10];
    for(int i = 0; i < 10; ++i)
        A[i] = new listNode(i);
    for(int i = 0; i < 9; ++i)
        A[i]->next = A[i+1];
    auto t = addTwoList2(A[0],A[4]);
    for(;t; t = t->next)
        cout << t->val;
    cout << endl;

    return 0;
}
