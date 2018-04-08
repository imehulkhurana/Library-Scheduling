#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
struct lib
{
int info;
char name[100];
struct lib *link;
};
struct lib *start=NULL,*f1=NULL,*r1=NULL,*f2=NULL,*r2=NULL;
void student(int a)
{
if(a==0)
{
int s;
printf("\n Enter number of Students ");
scanf("\n%d",&s);
int id1;
for(int i=0;i<s;i++)
{
printf("\n Enter 4 digit Student %d unique ID ",i);
scanf("%d",&id1);
struct lib *t;
t=(struct lib*)malloc(sizeof(struct lib));
t->info=id1;
if(f1==NULL)
{
t->link=NULL;
f1=t;
r1=t;
}
r1->link=t;
r1=t;
t->link=NULL;
}
student(1);
}
else
{
while(f1!=NULL)
{
if(f2==NULL)
{
printf("\n Student with ID %d is Processing ",f1->info);
struct lib *t5;
t5=(struct lib*)malloc(sizeof(struct lib));
t5->info=f1->info;
if(start==NULL)
{
start=t5;
t5->link=NULL;
}
else
{
struct lib *p;
p=start;
while(p->link!=NULL)
{
p=p->link;
}
p->link=t5;
t5->link=NULL;
}
f1=f1->link;
int ch;
printf("\n Press 1 for Students ");
printf("\n Press 2 for Teachers ");
printf("\n Press 3 if Both are Coming ");
printf("\n Press 4  if Nobody is Coming ");
printf("\n Press 5 to Check Processed Processes ");
printf("\n Press 6 for Exit");
scanf("\n%d",&ch);
switch(ch)
{
case 1:
	student(0);
	break;
case 2:
	teacher(0);
	break;
case 3:
	both();
	break;
case 4:
	break;
case 5:
	studentteacherqueue();
	break;
case 6:
	exit(0);
	break;
default:
	printf(" Enter Correct Choice ");
} 
}
else
{
teacher(1);
}
}
if(f1==NULL)
{
printf("\n No Students to Process ");
}
}
}
void teacher(int a1)
{
if(a1==0)
{
int no;
printf("\n Enter number of Teachers ");
scanf("\n%d",&no);
int id2;
for(int i=0;i<no;i++)
{
printf("\n Enter 2 digit Teacher %d unique ID ",i);
scanf("\n%d",&id2);
struct lib *t1;
t1=(struct lib*)malloc(sizeof(struct lib));
t1->info=id2;
if(f2==NULL)
{
t1->link=NULL;
f2=t1;
r2=t1;
}
r2->link=t1;
r2=t1;
t1->link=NULL;
}
teacher(1);
}
else
{
while(f2!=NULL)
{
printf("\n Teacher with ID %d is processing ",f2->info);
struct lib *t5;
t5=(struct lib*)malloc(sizeof(struct lib));
t5->info=f2->info;
if(start==NULL)
{
start=t5;
t5->link=NULL;
}
else
{
struct lib *p;
p=start;
while(p->link!=NULL)
{
p=p->link;
}
p->link=t5;
t5->link=NULL;
}
f2=f2->link;
int ch;
printf("\n Press 1 for Students ");
printf("\n Press 2 for Teachers ");
printf("\n Press 3 if Both are Coming ");
printf("\n Press 4 if Nobody is Coming ");
printf("\n Press 5 to Check Processed Processes ");
printf("\n Press 6 for Exit");
scanf("\n%d",&ch);
switch(ch)
{
case 1:
        student(0);
        break;
case 2:
        teacher(0);
        break;
case 3:
        both();
        break;
case 4:
        break;
case 5:
        studentteacherqueue();
        break;
case 6:
        exit(0);
        break;
default:
        printf(" Enter correct choice ");
}
}
}
if(f2==NULL)
{
printf("\n No Teachers to Process\n ");
}
}
void both()
{
int id1,id2,s,no1;
printf("\n Enter number of Students followed by number of Teachers ");
scanf("\n%d %d",&s,&no1);
for(int i=0;i<s;i++)
{
printf("\n Enter 4 digit Student %d Unique ID ",i);
scanf("\n%d",&id1);
struct lib *t2;
t2=(struct lib*)malloc(sizeof(struct lib));
t2->info=id1;
if(f1==NULL)
{
t2->link=NULL;
f1=t2;
r1=t2;
}
r1->link=t2;
r1=t2;
t2->link=NULL;
}
for(int i=0;i<no1;i++)
{
printf("\n Enter 2 digit Teacher %d Unique ID ",i);
scanf("\n%d",&id2);
struct lib* t3;
t3=(struct lib*)malloc(sizeof(struct lib));
t3->info=id2;
if(f2==NULL)
{
t3->link=NULL;
f2=t3;
r2=t3;
}
r2->link=t3;
r2=t3;
t3->link=NULL;
}
student(1);
teacher(1);
}
void studentteacherqueue()
{
if(start==NULL)
{
printf("\n No Process has started yet ");
}
struct lib *p=start;
while(p!=NULL)
{
printf("%d ",p->info);
p=p->link;
}
}
int main()
{
pthread_t t1;
pthread_t t2;
pthread_t t3;
pthread_t t4;
char ch;
printf(" Enter your choice: ");
A:
        printf("\n1.Students ");
        printf("\n2.Teachers ");
        printf("\n3.Both at the same time ");
        printf("\n4.Exit\n");
scanf("\n%d",&ch);
int a=0,a1=0;
switch(ch)
{
case 1:
        pthread_create(&t1,NULL,student,0);
        pthread_join(t1,NULL);
        goto A;
        break;
case 2:
        pthread_create(&t2,NULL,teacher,0);
        pthread_join(t2,NULL);
        goto A;
        break;
case 3:
        pthread_create(&t3,NULL,both,0);
        pthread_join(t3,NULL);
case 4:
        studentteacherqueue();
        exit(0);
default:
        printf("\n Enter correct choice. ");
}
studentteacherqueue();
}
