ASSG5_B220428CS_ADITHYA_PRACTICE.c
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data1[50];
    char data2[50];
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(char* data1,char* data2){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->data1,data1);
    strcpy(newnode->data2,data2);
    newnode->next=NULL;
    newnode->prev=NULL;
}
struct Node* search(struct Node* head,char* gdata){
    struct Node* trv=head;
    while(trv!=NULL){
        if(strcmp(trv->data1,gdata)==0){
            return trv;
        }
        trv=trv->next;
    }
    return NULL;
}
struct Node* display(struct Node* head){
    struct Node* trv=head;
    if(head==NULL){
        printf("-1\n");
        return head;
    }
    while(trv!=NULL){
        printf("%s %s",trv->data1,trv->data2);
        trv=trv->next;
    }
    printf("\n");
    return head;
}
struct Node* insertAtend(struct Node* head,char* song,char* lang){
     struct Node* newnode=createNode(song,lang);
    if(head==NULL){
        head=newnode;
        return head;
    }
    head->next=newnode;
    newnode->prev=head;
    return head;
}
struct Node* insertAtmid(struct Node* head,char* song,char* lang,char* songpr){
    struct Node* newnode=createNode(song,lang);
    struct Node* temp=search(head,songpr); 
    struct Node* ptr;
    ptr=temp->next;
    ptr->prev=newnode;
    newnode->next=ptr;
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}
struct Node* delete(struct Node* head,char* name){
    
    struct Node* temp=search(head,name);
    if(temp==head){
        struct Node* af=temp->next;
        head=temp->next;
        temp->next=NULL;
        af->prev=NULL;
        return head;
    }
    if(temp->next==NULL){
        struct Node* bf=temp->prev;
        bf->next=NULL;
        temp->prev=NULL;
        return head;
    }
    struct Node* af=temp->next;
    struct Node* bf=temp->prev;
    bf->next=af;
    af->prev=bf;
    temp->next=NULL;
    temp->prev=NULL;
    return head;
}
struct Node* nextnode(struct Node* head,char* name){
    struct Node* trv=search(head,name);
    printf("%s\n",trv->next->data1);
    return head;
}
struct Node* prevnode(struct Node* head,char* name){
    struct Node* trv=search(head,name);
    printf("%s\n",trv->prev->data1);
    return head;
}
int main()
{
    
    struct Node* head=NULL;
    while(1){
        char ch;
        scanf("%c",&ch);
        if(ch=='e'){
            break;
        }
        if(ch=='a'){
            char song[50],lang[50];
            scanf(" %s %s",song,lang);
            char cha;
            cha=getchar();
            if(ch=='\n'){
                head=insertAtend(head,song,lang);
            }
            else{
                char songpr[50];
                scanf("%s",songpr);
            
                struct Node* temp=search(head,songpr);
                if(temp==NULL){
                    head=insertAtend(head,song,lang);
                }
                else{
                    head=insertAtmid(head,song,lang,songpr);
                }
            }
        }
        if(ch=='n'){
            char name[50];
            scanf("%s",name);
            getchar();
            struct Node* temp=search(head,name);
            if(temp==NULL||temp->next==NULL){
                printf("-1\n");
            }
            else{
                head=nextnode(head,name);
            }
        }
        if(ch=='p'){
            char name[50];
            scanf("%s",name);
            getchar();
            struct Node* temp=search(head,name);
            if(temp==NULL||temp->prev==NULL){
                printf("-1\n");
            }
            else{
                head=nextnode(head,name);
            }
        }
        if(ch=='d'){
            head=display(head);
        }
        if(ch=='r'){
            char name[50];
            scanf("%s",name);
            getchar();
            struct Node* temp=search(head,name);
            if(temp==NULL){
                printf("-1\n");
            }
            else{
                head=delete(head,name);
            }
        }
    }
    return 0;
}

