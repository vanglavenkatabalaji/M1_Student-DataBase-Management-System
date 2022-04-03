#include<stdio.h>
#include<conio.h>
#include <string.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();
 

struct student{
    char roll_no[2];
    char name[10];
    char gender[7];
    char class[10];
    float per;
    char mobileno[10];
    
};
void main()
{
 int choice;
 while(choice!=5){
   printf("\t\t\t\t=======STUDENT DATABASE MANAGEMENT SYSTEM======");
  printf("\n\n\n\t\t\t\t 1.Add student Record\n");
  printf("\t\t\t\t 2.Student Records\n");
  printf("\t\t\t\t 3.Search Student\n");
  printf("\t\t\t\t 4.Delete Record\n");
  printf("\t\t\t\t 5.Exit\n");
  printf("\t\t\t\t -------------------------------------------\n");
  printf("\t\t\t\t  ");
  scanf("%d",&choice);
  
  switch(choice){
         case 1:
                
                addstudent();
                
                break;
        case 2:
        
                studentrecord();
                printf("\t\t\t\t\tPress any key to exit\n");
                getch();
                
                break;
       case 3:
              
              searchstudent();
              printf("\t\t\t\tPress any key to exit\n");
              getch();
              
              break;
       case 4:
              
              delete();
              printf("\t\t\t\tPress any key to exit\n");
              getch();
              
              break;
      case 5:
            
            printf("\n\t\t\t\tThank u\n");
            
            break;

}  
}
}
void addstudent(){
  char another;
  FILE *fp;
  struct student info1;
  do{
     
     printf("\t\t\t\t======Add Student info======\n\n\n");
     fp=fopen("student_info1.txt","a");
     
     printf("\n\t\t\tEnter roll no : ");
     scanf("%s",info1.roll_no);
     printf("\n\t\t\tEnter name : ");
     scanf("%s",info1.name);
     printf("\n\t\t\tEnter gender :");
     scanf("%s",info1.gender);
     printf("\n\t\t\tEnter class :");
     scanf("%s",info1.class);
     printf("\n\t\t\tEnter percentage :");
     scanf("%f",&info1.per);
     printf("\n\t\t\tEnter mobileno :");
     scanf("%s",info1.mobileno);
     
     
   
     printf("\n\t\t\t---------------------------------------\n");
        
        if(fp==NULL){
             fprintf(stderr,"\t\t\t Can't open file\n");
        }
        else{
             printf("\t\t\tRecord stored sucessfully\n");
        }
        fwrite(&info1,sizeof(struct student),1,fp);
        fclose(fp);

        printf("\t\t\tDo you want to add another record?(y/n) : ");
        scanf("%s",&another);
}while(another=='y'||another=='Y');
}
void studentrecord()
{
FILE *fp;
 struct student info1;
fp=fopen("student_info1.txt","r");
printf("\t\t\t\t======Student Records====\n\n\n");
if(fp==NULL){
  fprintf(stderr,"\t\t\t\tCan't open file\n");
}
else{
     printf("\t\t\tRecords\n");
     printf("\t\t\t\t__________________\n\n");
  }
  while(fread(&info1,sizeof(struct student),1,fp)){
    printf("\n\t\t\t\troll no: %s",info1.roll_no);
    printf("\n\t\t\t\tname :%s ",info1.name);
    printf("\n\t\t\t\tgender :%s",info1.gender);
    printf("\n\t\t\t\tclass :%s ",info1.class);
    printf("\n\t\t\t\tpercentage :%.02f",info1.per);
    printf("\n\t\t\t\tmobileno :%s",info1.mobileno);
    

    
}
fclose(fp);
getch();
}
void searchstudent()
{
FILE*fp;
struct student info1;
char roll_no[2],found=0;
int result;

 fp=fopen("student_info1.txt","r");
 printf("\t\t\t\t======Search Student=====\n\n\n");
 printf("\t\t\tEnter roll no : ");
 scanf("%s",roll_no);
 while(fread(&info1,sizeof(struct student),1,fp)){
       result = strcmp(info1.roll_no,roll_no);
    if(result == 0) {
       found=1;
    printf("\n\t\t\t\tRoll no       :%s",info1.roll_no);
    printf("\n\t\t\t\tname          :%s ",info1.name);
    printf("\n\t\t\t\tgender        :%s",info1.gender);
    printf("\n\t\t\t\tclass         :%s",info1.class);
    printf("\n\t\t\t\tpercentage    :%.02f",info1.per);
    printf("\n\t\t\t\tmobileno      :%s",info1.mobileno);
    
    
    printf("\n\t\t\t\t____________________________\n");
       }
}
if(!found){
    printf("\t\t\tRecord not found");
}
fclose(fp);
getch();
}
void delete()
{
 FILE *fp,*fp1;
   struct student info1;
   char roll_no[2],found=0;
   int result;
   
   printf("\t\t\t\t======Delete Student Record=====\n\n\n");
   fp=fopen("student_info1.txt","r");
   fp1=fopen("temp.txt","w");
   printf("\t\t\tEnter roll no : ");
   scanf("%s",roll_no);

   if(fp==NULL){
      fprintf(stderr,"\t\t\t\tCan't open file\n");
}
while(fread(&info1,sizeof(struct student),1,fp))
{
    result = strcmp(info1.roll_no,roll_no);
   if(result==0){
     found=1;
  }else{
       fwrite(&info1,sizeof(struct student),1,fp1);
   }
 }
 fclose(fp);
 fclose(fp1);
 
 if(found){
   remove("student_info1");
   rename("temp.txt","student_info1.txt");
   printf("\n\t\tRecord deleted successfully\n");
  }
 if(!found){
   printf("\n\t\t\tRecord not found\n");
}
getch();
}