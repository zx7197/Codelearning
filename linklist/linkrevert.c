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
示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
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

/***
*   使用  -fsanitize=address -fno-omit-frame-pointer编译选项原因如下：
*    使用该版本代码，leetcode提交报错
        AddressSanitizer: heap-buffer-overflow on address 0x6020000001cc at pc…
*    自己编译运行却未报错（gcc linkrevert.c -o linkrevert）
     原因是：
     LeetCode使用了AddressSanitizer检查了是否存在内存非法访问,一般是数组越界，上下都有可能
     Address Sanitizer（ASan）是一个快速的内存错误检测工具。从gcc 4.8开始，AddressSanitizer成为gcc的一部分
*    https://www.jianshu.com/p/3a2df9b7c353
     用-fsanitize=address选项编译和链接你的程序。
     用-fno-omit-frame-pointer编译，以得到更容易理解stack trace。
     可选择-O1或者更高的优化级别编译   
**/
struct ListNode* addTwoNumbers_001(struct ListNode* l1, struct ListNode* l2){
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
        new=(struct ListNode*)malloc(sizeof(new));
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
     struct ListNode* init2=NULL;
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
            init2=Listtmp;
         }
         else
         {
            init->next=Listtmp;
            init=init->next;

         }
         listDouble22=listDouble22->prev;

       }

     return init2;




}
      

struct ListNode*  createLinkedlist()
{

    struct ListNode *head,*last,*p;
    int n,number;
    int i=0;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    printf("请输入建立的链表长度:");
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
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
    // while(head)
    // {
    //     printf("%d ",head->val);
    //     head=head->next;
    // }
    return head;

}
int linkedlist_revert001()
{
    struct ListNode* a12;
    struct ListNode* a21;
    //创建链表
    a12=createLinkedlist();
    //反转链表
    a21=revert(a12);
    printf("反转前");
    while(a12)
    {
        printf("a1=%d ",a12->val);
        a12=a12->next;
    }
    printf("反转后");
    while(a21)
    {
        printf("%d ",a21->val);
        a21=a21->next;
    }



    return 0;
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
    int sel;
    printf("*********************************************\n");
    printf("1:链表反转练习\n");
    scanf("%d",&sel);
    //test();
    switch (sel)
    {
    case  1/* constant-expression */:
        /* code */
        linkedlist_revert001();
        break;
    
    default:
        break;
    }
//     a11=malloc(sizeof(struct ListNode));
//     a12=malloc(sizeof(struct ListNode));
//     a13=(struct ListNode*)malloc(sizeof(struct ListNode));
//     a21=(struct ListNode*)malloc(sizeof(struct ListNode));
//     a22=(struct ListNode*)malloc(sizeof(struct ListNode));
//     a23=(struct ListNode*)malloc(sizeof(struct ListNode));
   
//      printf("ccccccccccccc\n");
    
//     //free(a11->next);
//     a11->next=a12;
//    a11->val=2;
//     printf("okokokok\n");
//    a12->val=4;
//    a12->next=a13;
//    a13->val=3;
//    a13->next=NULL;
//      printf("a13\n");
//     //////////////////////////////////////////
//     a21->val=5;
//     a21->next=a22;
//     a22->val=6;
//    a22->next=a23;
//    a23->val=4;
//     a23->next=NULL;
//      printf("okokokok44444\n");
//     a1=addTwoNumbers_001(a11, a21);

//     printf("sas\n");
//       printf("1=%d\n",a1->val);
//       printf("2=%d\n",a1->next->val);
//      printf("3=%d\n",a1->next->next->val);
//         printf("sas\n");
 
    return 0;
}