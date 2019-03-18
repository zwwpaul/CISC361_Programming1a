#include<stdlib.h>
#include<string.h>

typedef struct mp3
{
char *artist;
char *title;
char *date;
int time;
struct mp3 *next;
struct mp3 *prev;
}mp3_t;

mp3_t *head;
mp3_t *tail;
mp3_t *getNewmp3(char* artist, char* title, char* date, int time);
void print();
void printReverse();
void freeList(mp3_t *p);
void insert(char* artist, char* title, char* date, int time);
void removeMp3(mp3_t *head,char* artist_name, char* title_name);
