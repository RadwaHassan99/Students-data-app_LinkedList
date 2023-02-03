#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#define upArrow     72
#define downArrow   80
#define home        55
#define esc         27
#define end 	    49
#define enter 	    13
#define create 	     2
#define add 	     3
#define insert 	     4
#define delet        5
#define delet_grade  6
#define delet_id     7
#define delet_name   8
#define search_id    9
#define search_name  10
#define search_grade 11
#define printall     12
#define count_node   13
#define count_odd    14
#define sort         15
#define insert_sort  16
#define reverse      17
#define clear        18
#define exit         19
#define first        2
#define last         19

/**********************************************************/
struct Student
{
  int id;
  char name[20];
  float grades[3];
};


struct Node
{
  struct Student std;
  struct Node * pPREV;
  struct Node * pNEXT;
};
struct Node * pHEAD;
struct Node * pTAIL;



/*********************************************************/

struct Node * CreateNode(struct Student S);
int    AddNode(void);
int    InsertNode(struct Student S,int loc);
int    DeleteNode(int loc);
int    DeletebyGrade(float grade,int sub_no);
int    DeletebyID(int ID);
int    DeletebyName(char NAME[20]);
struct Node * SearchNode(struct Student S);
int    SearchbyName(char N[20]);
int    SearchbyID(int ID);
int    SearchbyGrade(float grade,int no);
void   Printall(void);
void   FreeList(void);
int    CountNodes(void);
int    CountOdd(void);
void   SortbyID(void);
int    Reverse(void);
void   InsertSort(struct Student S);
struct Student Fillstd(void);
void   PrintStd(struct Student S);



void createMenu(void);
/**********************************************************/
int main()
{

char ch;
int x,y=0;
char flag=1;


struct Node * PTR;
struct Student std;

int location;
int ID;
int loc;
char NAME[20]={0};
float grade;
int NO;
float sub_grade;
int sub_NO;
int id;
char name[20];

createMenu();
gotoxy(1,first);
while(flag)
{
  ch=getch();
  if(ch==0)
  {
    ch=getch();
    if(ch==downArrow)
    {
      y=wherey();
      gotoxy(1,y+=1);
      if(y>last)
      {
	gotoxy(1,first);
      }
    }
    else if(ch==upArrow)
    {
      y=wherey();
      gotoxy(1,y-=1);
      if(y<first)
      {
	gotoxy(1,last);
      }
    }
  }
  else if(ch==enter)
  {
    y=wherey();
    switch (y)
    {
      case create:
		createMenu();
		gotoxy(1,last+2);
		CreateNode(std);
		break;
      case add:
		createMenu();
		gotoxy(1,last+2);
		AddNode();
		break;
      case insert:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter location of node:");
		scanf("%d",&location);
		printf("\n");
		InsertNode(std,location);
		break;
     case delet:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter location of node:");
		scanf("%d",&loc);
		printf("\n");
		DeleteNode(loc);
		break;
     case search_id:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter the ID you want: ");
		scanf("%d",&ID);
		SearchbyID(ID);
		break;
     case search_name:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter name you want: ");
		scanf("%s",NAME);
		SearchbyName(NAME);
		break;
     case search_grade:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter grade you want: ");
		scanf("%f",&grade);
		printf("\nEnter the number of the subject: ");
		scanf("%d",&NO);
		SearchbyGrade(grade,NO);
		break;

     case delet_grade:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter grade you want: ");
		scanf("%f",&sub_grade);
		printf("\nEnter the number of the subject: ");
		scanf("%d",&sub_NO);
		DeletebyGrade(sub_grade,sub_NO);
		break;
     case delet_id:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter ID you want: ");
		scanf("%d",&id);
		DeletebyID(id);
		break;
     case delet_name:
		createMenu();
		gotoxy(1,last+2);
		printf("Enter name you want: ");
		scanf("%s",name);
		DeletebyName(name);
		break;
     case count_node:
		createMenu();
		gotoxy(1,last+2);
		CountNodes();
		break;
     case count_odd:
		createMenu();
		gotoxy(1,last+2);
		CountOdd();
		break;
     case sort:
		createMenu();
		gotoxy(1,last+2);
		SortbyID();
		break;
     case insert_sort:
		createMenu();
		gotoxy(1,last+2);
		InsertSort(std);
		break;
     case reverse:
		createMenu();
		gotoxy(1,last+2);
		Reverse();
		break;
     case printall:
		createMenu();
		gotoxy(1,last+2);
		Printall();
		break;
     case clear:
		createMenu();
		FreeList();
		break;
     case exit:
		flag=0;
		break;
   }
  }
   else if(ch==esc)
   {
     flag=0;
   }

  }
return 0;
}
/*********************************************************************/
void createMenu(void)
{
  clrscr();
  printf("**********************Menu****************************");
  gotoxy(1,create);
  printf("1.Create a Node");
  gotoxy(1,add);
  printf("2.ADD a Node in last location");
  gotoxy(1,insert);
  printf("3.Insert a Node in a specific location");
  gotoxy(1,delet);
  printf("4.Delete a Node by Location");
  gotoxy(1,delet_grade);
  printf("5.Delete a Node by grade");
  gotoxy(1,delet_id);
  printf("6.Delete a Node by id");
  gotoxy(1,delet_name);
  printf("7.Delete a Node by name");
  gotoxy(1,search_id);
  printf("8.Search by id");
  gotoxy(1,search_name);
  printf("9.Search by Name");
  gotoxy(1,search_grade);
  printf("10.Search by grade");
  gotoxy(1,printall);
  printf("11.Print the Linked List");
  gotoxy(1,count_node);
  printf("12.Count nodes in the linked list");
  gotoxy(1,count_odd);
  printf("13.Count nodes with odd id");
  gotoxy(1,sort);
  printf("14.Sort");
  gotoxy(1,insert_sort);
  printf("15.Insert in sorted linked list");
  gotoxy(1,reverse);
  printf("16.Reverse");
  gotoxy(1,clear);
  printf("17.Free the Linked List");
  gotoxy(1,exit);
  printf("18.EXIT from the Menu");
  gotoxy(1,last+1);
  printf("*********************output****************************");
  gotoxy(1,first);
}
/*************************************************************/
// Enter and print data of the struct student
struct Student Fillstd(void)
{
  int i;
  struct Student S;
  printf("Enter id: ");
  scanf("%d",&S.id);
  printf("Enter name: ");
  scanf("%s",S.name);
  for(i=0;i<3;i++)
  {
    printf("Enter grade%d: ",i+1);
    scanf("%f",&S.grades[i]);
  }
    return S;
}


void PrintStd(struct Student S)
{
  int i;
  printf("Student id: %d",S.id);
  printf("\nStudent name: %s",S.name);
  for(i=0;i<3;i++)
  {
    printf("\ngrade%d=%f",i+1,S.grades[i]);
  }
}

/**********************************************************************/

//Function to create Node and return its address
struct Node * CreateNode(struct Student S)
{

  struct Node * PTR;
  PTR=(struct Node *)malloc(sizeof(struct Node));
  if(PTR)
  {
    PTR->std=S;
    PTR->pPREV=NULL;  //Not known yet
    PTR->pNEXT=NULL;  //Not known yet
  }
  return PTR;        // address of created Node

}

//Function to add node in the last location of the linked list
int AddNode(void)
{
  struct Node * PTR;
  int retval=0;
  struct Student S = Fillstd();
  PTR = CreateNode(S);

  if(PTR)
  {
    if(pHEAD==NULL)  //No any node exists
    {
      pHEAD=pTAIL=PTR;
    }

    else             //there is one or more nodes
    {
      pTAIL->pNEXT=PTR;
      PTR->pPREV= pTAIL;
      PTR->pNEXT=NULL;
      pTAIL=PTR;

      retval=1;
    }
  }
  return retval;
}

//Function to insert a node in a speciic location
int InsertNode(struct Student S,int loc)
{
  int retval=0;
  int i;
  struct Node * PCURR, * PTR;
  S = Fillstd();
  PTR = CreateNode(S);
  if(PTR)
  {
    retval=1;
    if(pHEAD==pTAIL)       //empty list
    {
      pHEAD=pTAIL=PTR;

    }
    else
    {
      if(loc==0)          //Add it in first location
      {
	pHEAD->pPREV=PTR;
	PTR->pNEXT=pHEAD;
	pHEAD=PTR;
      }
      else
      {
	PCURR=pHEAD;
	for(i=0;i<loc-1 && PCURR;i++)   //reach the node located before the location where the node will be inserted
	{
	  PCURR=PCURR->pNEXT;
	}
	if(PCURR==pTAIL || PCURR==NULL)  //insert the node in the last
	{
	  pTAIL->pNEXT=PTR;
	  PTR->pPREV=pTAIL;
	  PTR->pNEXT=NULL;
	  pTAIL=PTR;
	}
	else                            //insert the node in the middle
	{
	  PTR->pNEXT=(PCURR->pNEXT);
	  (PCURR->pNEXT)->pPREV=PTR;

	  PCURR->pNEXT=PTR;
	  PTR->pPREV=PCURR;
	}
      }
    }
  }
  return retval;
}

//Function to delete a specific Node
int DeleteNode(int loc)
{
  int retval=0;
  struct Node * PTR=NULL;
  int i;
  if(pHEAD)
  {
    PTR=pHEAD;
    if(loc==0)
    {
      if(pTAIL==pHEAD)      //delete first node from list that cantains only one node
      {
	pHEAD=pTAIL=NULL;
      }
      else                   //delete first node from list that cantains more than one node
      {
	pHEAD=pHEAD->pNEXT;
	pHEAD->pPREV=NULL;
      }
      free(PTR);
      retval=1;
    }

    for(i=0;(i<loc)&&(PTR);i++)
    {
      PTR=PTR->pNEXT;
    }
    if(PTR)
    {
      if(PTR==pTAIL)       //delete last node
      {
	pTAIL=pTAIL->pPREV;
	pTAIL->pNEXT=NULL;
      }
      else                //delete a node in the middle
      {
	(PTR->pPREV)->pNEXT=PTR->pNEXT;
	(PTR->pNEXT)->pPREV=PTR->pPREV;
      }
      free(PTR);
      retval=1;
    }
  }
return retval;
}

//Function to search in the list by a specifc id
int SearchbyID(int ID)
{
  struct Node * PTR=NULL;
  int count=0;
  if(pHEAD)
  {
    PTR=pHEAD;
    while((((PTR->std).id)!=ID) && (PTR))
    {
      ++count;
      PTR=PTR->pNEXT;
    }
  }
  if(PTR)
  {
    printf("ID is at location:%d",count);
  }
  else
  {
    printf("\nNot Found");
  }
  return count;
}

//Function to search in the list by a specifc Name
int SearchbyName(char N[20])
{
  struct Node * PTR=NULL;
  int count=0;
  if(pHEAD)
  {
    PTR=pHEAD;
    while((strcmp(N,(PTR->std).name)!=0) &&(PTR))
    {
      PTR=PTR->pNEXT;
      count ++;
    }
    if(PTR)
    {
      printf("Name is found at location: %d",count);

    }
    else
    {
      printf("\nNot found");
    }
  }
  return count;
}

//Function to find students with a specific grade
int SearchbyGrade(float grade,int sub_no)
{
  int retval=-1;
  int count = 0;
  struct Node * PTR=NULL;

  if(pHEAD)
  {
    PTR=pHEAD;
    while(PTR)
    {
      if(((PTR->std).grades[sub_no-1])==grade)
      {
	printf("\nThe grade is found at location:%d\n",count);
	PrintStd(PTR->std);
	retval=count;
      }

      PTR=PTR->pNEXT;
      count ++;
    }
  }
  if(retval==-1)
  {
    printf("Not Found");
  }
  return count;
}

//Function to delete nodes with specific grade
int DeletebyGrade(float grade,int sub_no)
{
  int loc = -1;
  int check;
  struct Node * PTR=NULL;
  if(PTR)
  {
    loc=0;
    PTR=pHEAD;
    while(PTR)
    {
      if(((PTR->std).grades[sub_no-1])==grade)
      {
	check=DeleteNode(loc);
      }
      PTR=PTR->pNEXT;
      loc++;
      if(check!=0)
      {
	loc--;

      }
    }
  }
  return loc;
}

//Function to delete nodes with a specific ID
int DeletebyID(int ID)
{
  int loc;
  loc = SearchbyID(ID);
  DeleteNode(loc);
  return loc;
}

//Function to delete nodes with a specific Name
int DeletebyName(char NAME[20])
{
  int loc;
  loc = SearchbyName(NAME);
  DeleteNode(loc);
  return loc;
}

//Function to print the whole Linked List
void Printall(void)
{
  struct Node * PTR;
  PTR=pHEAD;
  while(PTR)
  {
    PrintStd(PTR->std);
    printf("\n");
    PTR=PTR->pNEXT;
  }
}
//Function to get the number of nodes
int CountNodes(void)
{
  struct Node * PTR=NULL;
  int count=0;
  if(pHEAD)
  {
    PTR=pHEAD;
    while(PTR)
    {
      PTR=PTR->pNEXT;
      ++count;
    }
  }
  return count;
}

//Function to get the number of odd ids
int CountOdd(void)
{
  struct Node * PTR=NULL;
  int count=0;
  if(pHEAD)
  {
    PTR=pHEAD;
    while(PTR)
    {
      if(((PTR->std.id)%2!=0))
      {
	++count;
      }
      PTR=PTR->pNEXT;
    }
  }
  printf("\nthe number of odd ids: %d",count);
  return count;
}

//Function to clear the linked list from memory
void FreeList(void)
{
  struct Node * TEMP;
  while(pHEAD)
  {
    TEMP=pHEAD;
    pHEAD=pHEAD->pNEXT;
    free(TEMP);
  }
  pTAIL=NULL;
}

//Function to sort Linkedlist
void SortbyID(void)
{
  struct Node * PTR1=NULL;
  struct Node * PTR2=NULL;
  int i,j;
  int S=CountNodes();

  PTR2=(struct Node *)malloc(sizeof(struct Node));
  PTR2->pPREV=NULL;  //Not known yet
  PTR2->pNEXT=NULL;  //Not known yet
  if(pHEAD)
  {
   PTR1=pHEAD;
   for(i=0;i<(S-1)&&PTR1;i++)
   {
     for(j=0;j<S-1-i;j++)
     {
	if((PTR1->std.id)<((PTR1->pNEXT)->std.id))
	{
	  PTR2->std=PTR1->std;
	  PTR1->std=(PTR1->pNEXT)->std;
	  (PTR1->pNEXT)->std=PTR2->std;
	}

       PTR1=PTR1->pNEXT;
     }
     PTR1=pHEAD;
  }
  }
}

//Function to insert in descending order list
void   InsertSort(struct Student S)
{
  int i;
  int flag=1;
  struct Node * PCURR, * PTR;
  SortbyID();
  S=Fillstd();
  PTR=CreateNode(S);
  PCURR=pHEAD;

  if(PTR)
  {
    if(pHEAD==pTAIL)
    {
      if((pHEAD->std.id)<(PTR->std.id))
      {
	  pHEAD->pPREV=PTR;
	  PTR->pNEXT=pHEAD;
	  PTR->pPREV=NULL;
	  pHEAD=PTR;
      }
      else
      {
	  pTAIL->pNEXT=PTR;
	  PTR->pPREV=pTAIL;
	  PTR->pNEXT=NULL;
	  pTAIL=PTR;
      }
    }
    else
    {
      while(PCURR&&flag)
      {
	if(PTR->std.id<pTAIL->std.id)
	{
	  pTAIL->pNEXT=PTR;
	  PTR->pPREV=pTAIL;
	  pTAIL=PTR;
	  flag=0;
	}
	else if(((PCURR->std.id)>(PTR->std.id)) && ((PTR->std.id) > (PCURR->pNEXT->std.id)))
	{
	  PCURR->pNEXT->pPREV=PTR;
	  PTR->pNEXT=PCURR->pNEXT;
	  PCURR->pNEXT=PTR;
	  PTR->pPREV=PCURR;
	  flag=0;
	}
	else
	{
	  PCURR=PCURR->pNEXT;
	}
      }
    }
  }

}


//Function to reverse order of Linked List
int Reverse(void)
{
  struct Node * PTR;
  struct Node * PRV=NULL;
  struct Student temp;
  int retval=0;
  PTR=pHEAD;
  if(PTR)
  {
    if(pHEAD==pTAIL)
    {
      printf("reversed");

    }
    else
    {
      while(PTR && (PTR!=PRV))
      {
	while(PTR->pNEXT  &&  (PTR->pNEXT != PRV))
	{
	  retval=1;
	  temp=PTR->std;
	  PTR->std=PTR->pNEXT->std;
	  PTR->pNEXT->std=temp;
	  PTR=PTR->pNEXT;
	}
	PRV=PTR;
	PTR=pHEAD;

      }


    }


  }

  return retval;
}