/*================================================================
*   Copyright (C) 2023 Goldman Ltd. All rights reserved.
*   
*   File：MGJ11.cpp
*   Author：leekaihua
*   Date：2023年04月11日
*   Brife：
*



*/

#include &quot;bits/stdc++.h&quot;
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
ListNode* merge(ListNode *l1,ListNode *l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *q=new ListNode(0);
    ListNode *p=q;
    while(l1&amp;&amp;l2){
        if(l1-&gt;val&lt;l2-&gt;val){
            p-&gt;next=l1;
            l1=l1-&gt;next;
        }else{
            p-&gt;next=l2;
            l2=l2-&gt;next;
        }
        p=p-&gt;next;
    }
    if(l1){
        p-&gt;next=l1;
    }
    if(l2){
        p-&gt;next=l2;
    }
    return q-&gt;next;
}
int main()
{
    ListNode *l=new ListNode(0);
    ListNode *l1=l;
    int x,n=0;
    string s;
    getline(cin,s);
    stringstream ss1(s);
    while(ss1&gt;&gt;x){
        l1-&gt;next=new ListNode(x);
        l1=l1-&gt;next;
        ++n;
    }
    s=&quot;&quot;;
    getline(cin, s);
    stringstream ss2(s);
    ListNode *r=new ListNode(-1);
    ListNode *l2=r;
    while(ss2&gt;&gt;x){
        l2-&gt;next=new ListNode(x);
        l2=l2-&gt;next;
        ++n;
    }
    ListNode *res=merge(l-&gt;next,r-&gt;next);
    for(int i=0;i&lt;n;i++){
        if(i==n-1){
            printf(&quot;%d\n&quot;,res-&gt;val);
        }else{
            printf(&quot;%d &quot;,res-&gt;val);
        }
        res=res-&gt;next;
    }
    return 0;
}