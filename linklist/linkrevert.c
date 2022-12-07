#include<stdio.h>
#include<stdlib.h>
//编译命令
// gcc linkrevert.c -o linkrevert
//gcc linkrevert.c -g -fsanitize=address -o linkrevertll
/**
gcc linkrevert.c -o1 -g -fsanitize=address -fno-omit-frame-pointer -o linkrevert
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 struct ListNodeDouble {
      int val;
       struct ListNodeDouble *prev;
      struct ListNodeDouble *next;
 };
 typedef struct Arr //定义一个结构体 包含一个数据域和一个指针域
{
	int val; //数据域
	struct Arr* next;//指针域
}*Node;

struct ListNode* addTwoNumbers_anser(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;


   


}
/**leetcode  第2题
**/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3=NULL;
    struct ListNode* p1=NULL;
    struct ListNode* p2=NULL;
    struct ListNode* new=NULL;
    struct ListNode* init=NULL;
    int count=0;//进位

    p1=l1;
    p2=l2;
    
    while(p1!=NULL||p2!=NULL)
    {






      ////////////////////////////////

        new=malloc(sizeof(struct ListNode));
        if(p1==NULL)
        {
             new->val=p2->val+count;
            p2=p2->next;
        }
        else if(p2==NULL)
        {
            new->val=p1->val+count;
            p1=p1->next;

        }
         
         else
         {
             new->val=(p2->val+p1->val+count)%10;
             count=(p2->val+p1->val+count)/10;
             p1=p1->next;
             p2=p2->next;

         }
         if(l3==NULL)
         {
             l3=new;
             init=new;
         }
         else
         {
             l3->next=new;
             l3=l3->next;

         }

    }
    return init;
}
//单链表反转  
//思路：构建一个双链表 把单链表变成双链表，然后双链表倒序 变成逆向单链表
struct ListNode* revert(struct ListNode* l1)
{
     struct ListNode* init=NULL;
      struct ListNode* Listtmp=NULL;
     struct ListNodeDouble * listDouble22=NULL;
     struct ListNodeDouble * listDouble=NULL;
     if(l1==NULL)
       return NULL;
       while(l1)
       {
        listDouble=malloc(sizeof(struct ListNodeDouble ));
        listDouble->val=l1->val;
        listDouble->next=NULL;
        listDouble->prev=listDouble22;
        if(listDouble22==NULL)
           listDouble22=listDouble;
           else
           {
            listDouble22->next=listDouble;
            listDouble22=listDouble22->next;

           }

        l1=l1->next;
        
       }
       while(listDouble22)
       {
         Listtmp=malloc(sizeof(struct ListNode ));
         Listtmp->val=listDouble22->val;
         Listtmp->next=NULL;
         if(init==NULL)
         {
            init=Listtmp;
         }
         else
         {
            init->next=Listtmp;
            init=init->next;

         }
         listDouble22=listDouble22->prev;

       }

     return init;




}
void test()
{

    Node head,last,p;
        int n,number;
        int i=0;
        head=(Node)malloc(sizeof(struct Arr));
        printf("请输入建立的链表长度:");
        scanf("%d",&n);
        for(i = 0;i < n;i++)
        {
            p=(Node)malloc(sizeof(struct Arr));
            printf("请输入第%d个节点的元素值:\n",i+1);
            scanf("%d",&number);
            p->val=number;
            if(i==0)
            {
                head=p;
                last=head;//此步骤很关键，不能掉
            }
            else
            {
                last->next=p;
                last=p;
                last->next=NULL;
            }
        }
        while(head)
        {
            printf("%d ",head->val);
            head=head->next;
        }

}

int main()
{
    struct ListNode* a1;
    struct ListNode* a11;
    struct ListNode* a12;
    struct ListNode* a13;
    struct ListNode* a21;
    struct ListNode* a22;
    struct ListNode* a23;
    test();

    a11=malloc(sizeof(struct ListNode));
    a12=malloc(sizeof(struct ListNode));
    a13=(struct ListNode*)malloc(sizeof(struct ListNode));
    a21=(struct ListNode*)malloc(sizeof(struct ListNode));
    a22=(struct ListNode*)malloc(sizeof(struct ListNode));
    a23=(struct ListNode*)malloc(sizeof(struct ListNode));
   
     printf("ccccccccccccc\n");
    
    //free(a11->next);
    a11->next=a12;
   a11->val=2;
    printf("okokokok\n");
   a12->val=4;
   a12->next=a13;
   a13->val=3;
   a13->next=NULL;
     printf("a13\n");
    //////////////////////////////////////////
    a21->val=5;
    a21->next=a22;
    a22->val=6;
   a22->next=a23;
   a23->val=4;
    a23->next=NULL;
     printf("okokokok44444\n");
    a1=addTwoNumbers(a11, a21);

    printf("sas\n");
      printf("1=%d\n",a1->val);
      printf("2=%d\n",a1->next->val);
     printf("3=%d\n",a1->next->next->val);
        printf("sas\n");
 
    return 0;
}