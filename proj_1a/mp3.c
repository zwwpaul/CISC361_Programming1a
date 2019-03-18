#include "mp3.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define BUFFERSIZE 128

mp3_t *getNewmp3(char* artist, char* title, char* date, int time)
{
mp3_t *newmp3 = (mp3_t*)malloc(sizeof(mp3_t));
newmp3->artist =malloc(strlen(artist));
strcpy(newmp3->artist, artist);
newmp3->title =malloc(strlen(title));
strcpy(newmp3->title,title);
newmp3->date =malloc(strlen(date));
strcpy(newmp3->date,date);
newmp3->time= time;
newmp3->next= NULL;
newmp3->prev= NULL;
return newmp3;
}

void print()
{
mp3_t* temp;
temp=head;
while(temp!=NULL){
printf("%s--%s--%s--%d\n",temp->artist, temp->title, temp->date, temp->time);
temp=temp->next;
}
}



void printReverse()
{
mp3_t* temp2;
temp2=tail;
while(temp2!=NULL){
printf("%s--%s--%s--%d\n",temp2->artist, temp2->title, temp2->date, temp2->time);
temp2=temp2->prev;
}
}

void insert(char* artist, char* title, char* date, int time)
{
mp3_t *mp3_t1, *mp3_t2;
mp3_t1=getNewmp3(artist, title, date, time);
mp3_t2=head;
if(mp3_t2==NULL){
        head=mp3_t1;
        tail=mp3_t1;
}
else{
        while(mp3_t2->next!=NULL){
                mp3_t2=mp3_t2->next;}
        tail=mp3_t1;
        mp3_t2->next=mp3_t1;
        mp3_t1->prev=mp3_t2;
}
}

void removeMp3(mp3_t* s, char* artist_name, char* title_name){
mp3_t *temp;
if(s==NULL){
        printf("\nEmpty List\n");
}
while(s!=NULL){
if(strcmp(s->artist,artist_name)==0){
        if(strcmp(s->title,title_name)==0){
                temp=s->next;
                if(s==head&&s==tail){
                head=NULL;
                tail=NULL;
                }
                if(s==head){
                        head=s->next;
                }
                if(s==tail){
                        tail=s->prev;
                }
                if(s->prev!=NULL){
                        s->prev->next=s->next;
                }
                if(s->next!=NULL){
                        s->next->prev=s->prev;
                }
                s->next=NULL;
                s->prev=NULL;
                }
        free(s->artist);
        free(s->title);
        free(s->date);
        free(s);
        s=temp;
        }else{
        s=s->next;
        }
}
}

void freeList(mp3_t* p)
{
mp3_t* temp3;
while(p!=NULL){
        temp3=p->next;
        if(head==p){
                head=p->next;}
        if(tail==p){
                tail=p->prev;}
        if(p->prev!=NULL){
                p->prev->next= p->next;}
        if(p->next!=NULL){
                p->next->prev= p->prev;}
        p->next=NULL;
        p->prev=NULL;
        free(p->artist);
        free(p->title);
        free(p->date);
        free(p);
        p=temp3;
}
}
int main(){
  int i;
  int len;
  char c;
  char* artist;
  char* artist_delete;
  char* title;
  char* title_delete;
  char* date;
  char* time_s;
  int time;
  head = NULL;
  tail =NULL;

  while (1) {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("(1) Insert\n");
    printf("(2) Delete\n");
    printf("(3) Display\n");
    printf("(4) Display in reverse order\n");
    printf("(5) Exit\n");
    printf("Enter your choice : ");
    if (scanf("%d%c", &i, &c) <= 0) {
        printf("Enter only an integer from 1 to 5\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1: artist=malloc(BUFFERSIZE);
                title=malloc(BUFFERSIZE);
                date=malloc(BUFFERSIZE);
                time_s=malloc(BUFFERSIZE);

                printf("It's time to enter information for a song!\n");

                printf("Please enter the name of artist.\n");
                if(fgets (artist, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(artist);
                        artist[len-1]='\0';
                }else{
                        printf("Please enter the name of artist.\n");
                }


                printf("Please enter a title.\n");
                if(fgets (title, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(title);
                        title[len-1]='\0';
                }else{
                        printf("Please enter a title.\n");
                }

                printf("Please enter the date.\n");
                if(fgets (date, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(date);
                        date[len-1]='\0';
                }else{
                        printf("Please enter date.\n");
                }

                printf("Please enter song time.\n");
                if(fgets (time_s, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(time_s);
                        time_s[len-1]='\0';
                }else{
                        printf("Please enter song time.\n");
                }
                time = atoi(time_s);
                insert(artist, title, date, time);
                break;

        case 2: title_delete=malloc(BUFFERSIZE);
                artist_delete=malloc(BUFFERSIZE);
                printf("Please enter an artist.\n");
                if(fgets (artist_delete, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(artist_delete);
                        artist_delete[len-1]='\0';
                }else{
                        printf("Please an the artist.\n");
                }


                printf("Please enter the song you want to delete.\n");
                if(fgets (title_delete, BUFFERSIZE, stdin)!=NULL){
                        len=strlen(title_delete);
                        title_delete[len-1]='\0';
                }else{
                        printf("Please enter the title.\n");
                }

                removeMp3(head,artist_delete,title_delete);
                free(title_delete);
                free(artist_delete);
                break;
        case 3: if (head == NULL)
                  printf("List is Empty\n");
                else
                  print();
                break;
        case 4: if (head == NULL)
                  printf("List is Empty\n");
                else
                  printReverse();
                break;
        case 5: printf("Bye user!\n");
                freeList(head);
                exit(0);
                break;
        default: printf("Invalid option\n");
        }
    }
  }
  return 0;
}
                                          
