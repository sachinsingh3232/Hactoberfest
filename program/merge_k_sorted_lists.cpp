class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * res=NULL;
        for(int i=0;i<lists.size();i++)
            res=merge(res,lists[i]);
        return res;
    }
    ListNode * merge(ListNode * head1,ListNode * head2){
        if(head1==NULL)
            return head2;
        else if(head2==NULL)
            return head1;
        ListNode * head3=NULL;
        if(head1->val<=head2->val){
            head3=head1;
            head1=head1->next;
        }
        else{
            head3=head2;
            head2=head2->next;
        }
        ListNode *tail=head3;
        while(head1!=NULL && head2!=NULL){
            ListNode *temp=NULL;
            if(head1->val<=head2->val){
                temp=head1;
                head1=head1->next;
                tail->next=temp;
                tail=temp;
            }
            else{
                temp=head2;
                head2=head2 ->next;
                tail->next=temp;
                tail=temp;
            }
        }
        if(head1!=NULL)
            tail->next=head1;
        else if(head2!=NULL)
            tail->next=head2;
        return head3;
    }
};
