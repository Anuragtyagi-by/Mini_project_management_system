#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
 void insert_record();
 void display_record();
 void search_record();
 void del_record();
 void update_record();
 void sort_record();

 struct student
   {
      int roll;
      char course[20],anu[10];
      char name[40];
      char mini[50];
      
  };
  struct student s;
int main()
 {
    int ch;
    clrscr();
    while(ch!=7)
      {
        clrscr();
        printf("\t-----------------------------------------------\n");
        printf("\t   Welcome to Mini Project MANAGEMENT SYSTEM \n");
        printf("\t-----------------------------------------------\n");
        printf("\t-----------------------------------------------\n");
        printf("\t           Made by - ANURAG TYAGI \n");
        printf("\t-----------------------------------------------\n");
        printf("\t-----------------------------------------------\n");
        printf("\t      Mini project coordinator - Mr.Ravikant \n");
        printf("\t-----------------------------------------------\n\n\n");
        printf("\t-----AVAILABLE FUNCTIONALITIES-----\n\n");
        printf("\t\t1:Insert Student record\n");
        printf("\t\t2:Display Student record\n");
        printf("\t\t3:Search student record\n");
        printf("\t\t4:Delete student record\n");
        printf("\t\t5:update student record\n");
        printf ("\t\t6:short student record\n");
        printf ("\t\t7:Exit\n");
        printf("\t---------------------------------------------\n");
        printf("\t\t enter your choice:");
        scanf("%d",&ch);
        switch(ch)
          {
            case 1:clrscr();
                      insert_record();
                      break;
            case 2:clrscr();
                      display_record();
                      break;
            case 3:clrscr();
                      search_record();
                      break;
            case 4:clrscr();
                      del_record();
                      break;
            case 5:clrscr();
                      update_record();
                      break;
            case 6:clrscr();
                      sort_record();
                      break;
            case 7: exit(1);
            default:
                   printf("\n wrong choice entered");
          }
          
          printf("\n\t\t\t press any key to continue");
          
          getch();
      }
  }
    
    void insert_record()
     {
        FILE *fp;
        fp=fopen("stu.doc","ab+");
        if(fp==NULL)
          {
             printf("\n\t\t Error: cannot  open the file!!!");
             return;
           }
       printf("\t***previous stored data***\n");
       display_record();
        
       printf("\n\n\t ***Enter new student data***\n");
       printf("\n Enter student roll number:");
       scanf("%d",&s.roll);
       fflush(stdin);
       gets(s.anu);
       printf("\n Enter student course:");
       gets(s.course);
       printf("\n Enter student name:");
       gets(s.name);
       printf("\n Enter student mini project:");
       gets(s.mini);
       fwrite(&s,sizeof(s),1,fp);
         {
            printf("\n\n\t!!! Student record inserted successfully \n");
         }
       fclose(fp);
       printf("\n\t\tUpdate Record!!\n");
       display_record();
    }
                       
 void display_record()
  {
     FILE *fp;
     fp=fopen("stu.doc","rb");
     if(fp==NULL)
      {
         printf("\n\t\tError:Cannot open the file!!!");
         return; 
       }
     printf("\n\n\t***Student details are as follows***\n");
     printf("---------------------------------------------------\n");
     printf("\nRoll No.| Name of sudent | Course | Mini Project\n");
     printf("---------------------------------------------------\n");
     while(fread(&s,sizeof(s),1,fp)==1)
       {
         printf(" %d          %s            %s     %s\n",s.roll,s.name,s.course,s.mini);
         printf("---------------------------------------------------\n");
        }
      fclose(fp);
 }

  void search_record()
    {
      int ro,flag=0;
      FILE *fp;
      fp=fopen("stu.doc","rb");
      if(fp==NULL)
       {
          printf("\n\t\tError:Can not open the file!!!");
          return;
        }
    printf("\n\nEnter student roll number to search:");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
      {
         if(s.roll==ro)
           {
              flag=1;
              printf("\n\nSearchsuccessful and student record is as follows\n\n");
              printf("---------------------------------------------------\n");
              printf("\nRoll No.| Name of sudent | Course | Mini Project\n\n");
              printf("---------------------------------------------------\n");
              printf(" %d             %s         %s     %s\n",s.roll,s.name,s.course,s.mini);
              printf("---------------------------------------------------\n");
           }
        }
  if(flag==0)
   {
      printf("\n\n\t\tNo search record found !!!\n");
    }
  fclose(fp);
 }
  
  void del_record()
   {
     char name[40];
     unsigned flag=0;

    FILE *fp,*ft;
      fp=fopen("stu.doc","rb");
      if(fp==NULL)
       {
          printf("\n\t\tError:Can not open the file!!!");
          return;
        }
      printf("\n\t***Previous stored data***");
      display_record();
      printf("\n\nEnter student name which you want to delete:");
      scanf("%s",name);
      ft=fopen("stut.doc","ab+");
      while(fread(&s,sizeof(s),1,fp)==1)
         {
	    if(strcmp(name,s.name)!=0)
              {
              	printf("\n\n Record deleted successfully\n\n");
              	fwrite(&s,sizeof(s),1,ft);
              }
	    else{
	      flag=1;
	       }
          }
       if(flag==0)
         {
         	printf(" No such record found!!!\n");
         }
       fclose(fp);
       fclose(ft);
       remove("stu.doc");
       rename("stut.doc","stu.doc");
       printf("\n\t Update record!!\n\n");
       display_record();
    }
    
  void update_record()  
   {
   	int ro,flag=0;
   	FILE *fp;
   	fp=fopen("stu.doc","rb+");
   	if(fp==NULL)
   	  {
   	     printf("\n\t\t Error:cannot open the file!!!");
   	     return;
   	   }
       printf("\n\n\t enter roll number of student for update");
       scanf("%d",&ro);
       printf("\n\t\t***previously stored record of given roll number***");
       while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
         {
           if(s.roll==ro)
             {
               flag=1;
               printf("\nRoll No.| Name of sudent | Course | Mini Project\n\n");
               printf(" %d             %s         %s    %s\n",s.roll,s.name,s.course,s.mini);
	       printf("***Now enter the New Record***");
               printf("\n\nUpdated Student Roll number");
               scanf("%d",&s.roll);
               fflush(stdin);
               gets(s.anu);
               printf("\nUpdated student Name:");
               gets(s.name);
               printf("\nUpdate student course:");
               gets(s.course);
	       printf("\nUpdate student mini project:");
	           gets(s.mini);
               
               fseek(fp,-(long)sizeof(s),1);
               fwrite(&s,sizeof(s),1,fp);
               printf("\n\n\t\t record successfully check the display\n");
              }
            }
         if(flag==0)
           {
             printf("\n\t\tError:Something went wrong!!!");
           }
         fclose(fp);
     }    
  
  void sort_record()
   {
      struct student temp;
      struct student arr[50];
      int i,j,k=0;
      FILE *fp;
      fp=fopen("stu.doc","rb");
      if(fp==NULL)
        {
          printf("\n\t\tError:cannot open file!!!\n");
        }
       i=0;
       while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
        {
          i++;
          k++; 
         }
       for(i=0;i<k;i++)
         {
           for(j=0;j<k-i-1;j++)
             {
                if(arr[j].roll>arr[j+1].roll)
                  {
                  	temp=arr[j];
                  	arr[j]=arr[j+1];
                  	arr[j+1]=temp;
                   }
	      }
        printf("\n\t\tAfter sorting student details\n\n");
        for(i=0;i<k;i++)
          {
            printf("%d | %s | %s | %s\n",arr[i].roll,arr[i].name,arr[i].course,arr[i].mini);
           }
          fclose(fp);
       }
  }
       
  
            
     
  
  
 
     
  
  
   
  
  
 
  
  
 
