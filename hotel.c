#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct hotel
{
int id;
char hname[20];
int rooms;
char description[100];
int price1;
int price2;
int price3;
};
void append(char fname[]);
void display(char fname[]);
void displayall(char fname[] );
void book(char fname[]);
void del(char fname[]);

int main()
{
int ch;
int choice;
int citychoice;
char name[]="empty.dat";
printf("Enter location:\n1.Belagavi\n2.Hubli\n3.Banglore\n");
scanf("%d",&citychoice);
switch(citychoice){
case 1:{strcpy(name,"belagavi.dat");
break;}
case 2:{strcpy(name,"hubli.dat");
break;}
case 3:{strcpy(name,"banglore.dat");
break;}
}

while(1)
{
printf("...................HOTEL MANAGEMENT SYSTEM................\n\n");
printf("Enter 1 if you are a user.Enter password if you are a admin :");
scanf("%d",&choice);
if(choice == 420 || choice == 1)
{printf("Wellcome\n");}
else{

    printf("Wrong password");
    exit(0);
}
switch(choice)
{
case 420:
{
printf("11. Add Hotel\n\n");
printf("12. Display Hotel details\n\n");
printf("13. Delete Hotel from list\n\n");
printf("0. Exit\n\n");
break;
}
case 1:{

printf("1. Display required hotel deatails by entering its ID\n\n");
printf("2. Display All available hotel\n\n");
printf("3. Book a hotel\n\n");
printf("0. Exit\n\n");
break;
}
}

printf("\nPlease enter your Choice:");
scanf("%d",&ch);
switch(ch)
{
case 11: append(name);
break;

case 12: displayall(name);
break;

case 13: del(name);
break;

case 1:display(name);
break;

case 2: displayall(name);
break;

case 3: book(name);
break;

case 0: exit(0);
}

}

return 0 ;

}
void append(char fname[])
{
printf("Add a hotel details:");
FILE *fp;
struct hotel temp1;
fp=fopen(fname,"ab");
printf("\nEnter ID ");
scanf("%d",&temp1.id);
printf("\nEnter hotel name ");
scanf("%s",temp1.hname);
printf("\nEnter number of rooms ");
scanf("%d",&temp1.rooms);
printf("\nEnter oneword discription about the hotel:");
scanf("%s",temp1.description);
printf("\nEnter price in Goibibo ");
scanf("%d",&temp1.price1);
printf("\nEnter price in Trivago ");
scanf("%d",&temp1.price2);
printf("\nEnter price in Makemytrip");
scanf("%d",&temp1.price3);
fwrite(&temp1,sizeof(temp1),1,fp);
fclose(fp);

/*FILE *fp2;
struct hotel temp2;
fp2=fopen(trivago,"ab");
printf("\nEnter ID ");
scanf("%d",&temp2.id);
printf("\nEnter hotel name ");
scanf("%s",temp2.hname);
printf("\nEnter price ");
scanf("%d",&temp2.price);
printf("\nEnter number of rooms ");
scanf("%d",&temp2.rooms);
printf("\nEnter oneword discription about the hotel:");
scanf("%s",temp2.description);
fwrite(&temp2,sizeof(temp2),1,fp2);
fclose(fp2);

FILE *fp3;
struct hotel temp3;
fp3=fopen(makemytrip,"ab");
printf("\nEnter ID ");
scanf("%d",&temp3.id);
printf("\nEnter hotel name ");
scanf("%s",temp3.hname);
printf("\nEnter price ");
scanf("%d",&temp3.price);
printf("\nEnter number of rooms ");
scanf("%d",&temp3.rooms);
printf("\nEnter oneword discription about the hotel:");
scanf("%s",temp3.description);
fwrite(&temp3,sizeof(temp3),1,fp3);
fclose(fp3);*/

}


void displayall(char fname[])
{
FILE *fp;
struct hotel tempo;
fp=fopen(fname,"rb");
printf("\t\t All Hotel Details\n\n");
printf("========================================================\n\n");
while(1)
{
fread(&tempo,sizeof(tempo),1,fp);
if(feof(fp))
{
break;
}
printf("Hotel ID : %d\n",tempo.id);
printf("Hotel name : %s\t",tempo.hname);
printf("\nprices : Goibibo          Trivago         makemytrip\n");
printf("Single : %d Rs           %d Rs            %d Rs\n",tempo.price1,tempo.price2,tempo.price3);
printf("Double : %d Rs           %d Rs            %d Rs\n",tempo.price1+250,tempo.price2+200,tempo.price3+230);
printf("\n========================================================\n\n");
}
fclose(fp);
}
void display(char fname[])
{
FILE *fp;
struct hotel t;
int id,found=0;

fp=fopen(fname,"rb");

printf("\nEnter the Hotel ID:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
printf("Hotel Details of %d\n\n",t.id);
printf("*********************************************8\n\n");

printf("Hotel name : %s\n\n",t.hname);
printf("%s\n",t.description);
printf("Number of rooms available : %d\n",t.rooms);
if(t.rooms>15){
printf("\nprices : Goibibo          Trivago         makemytrip\n");
printf("Single : %d Rs           %d Rs            %d Rs\n",t.price1,t.price2,t.price3);
printf("Double : %d Rs           %d Rs            %d Rs\n",t.price1+250,t.price2+200,t.price3+230);
}
else{
    printf("Rates are higher than usual since less than 15 rooms are left\n");
    printf("\nprices : Goibibo          Trivago         makemytrip\n");
printf("Single : %d Rs           %d Rs            %d Rs\n",t.price1+700,t.price2+700,t.price3+700);
printf("Double : %d Rs           %d Rs            %d Rs\n",t.price1+1000,t.price2+1000,t.price3+1000);

}
}
}
if(found==0)
{
printf("\nSorry No hotel Found");
}
fclose(fp);
}


void del(char fname[])
{
FILE *fp,*fp1;
struct hotel t;
int id,found=0;

fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Hotel ID you want to Delete:");
scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}
}
fclose(fp);
fclose(fp1);
}

void book(char fname[])
{
FILE *fp,*fp1;
struct hotel t;
int id,found=0,n;
int siteno;
char sitename[20];
fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the hotel ID you want to book:");
scanf("%d",&id);
printf("Enter the Website through which you want to book \n1.Goibibo\n2.Trivago\n3.Makemytrip\n");
scanf("%d",&siteno);
switch(siteno){
case 1:{strcpy(sitename,"Goibibo");
break;}
case 2:{strcpy(sitename,"Trivago");
break;}
case 3:{strcpy(sitename,"Makemytrip");
break;}
}

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.id==id)
{
found=1;
printf("Enter number of rooms to be booked : ");
scanf("%d",&n);
printf("%d rooms are booked through %s\n",n,sitename);
switch(siteno){
case 1:{if(t.rooms>15)
    {printf("Bill amount :%d * %d = %d Rs\n",n,t.price1,n*(t.price1));}
    else{
        printf("Bill amount :%d * %d = %d Rs\n",n,t.price1+1000,n*(t.price1+1000));
    }
break;}

case 2:{if(t.rooms>15)
    {printf("Bill amount :%d * %d = %d Rs\n",n,t.price2,n*(t.price2));}
    else{
        printf("Bill amount :%d * %d = %d Rs\n",n,t.price2+1000,n*(t.price2+1000));
    }
break;}

case 3:{if(t.rooms>15)
    {printf("Bill amount :%d * %d = %d Rs\n",n,t.price3,n*(t.price3));}
    else{
        printf("Bill amount :%d * %d = %d Rs\n",n,t.price3+1000,n*(t.price3+1000));
    }
break;}
}
fflush(stdin);
t.rooms=t.rooms-n;
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}
