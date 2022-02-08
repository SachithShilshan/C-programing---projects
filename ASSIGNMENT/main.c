#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();

struct {

    char name[60];
    int acc_no;
    char nic[10];
    char acc_type[1];
    float amt;

    }add,upd,check,rem,transaction;


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu(void)
{   int choice;
    system("cls");
    printf("\n\n\t\t\t\t\n                        _______________________________________\n\n                                ******* ABC BANK *******\n                        _______________________________________");
    printf("\n\n\n\t\t\t        WELCOME TO THE MAIN MENU\n ");
    printf("\n\n\t\t1. Create new account \n\t\t2. Cash Deposit \n\t\t3. Cash withdraw \n\t\t4. Account Details \n\t\t5. customer's Details \n\t\t6. Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;

        case 2:Deposit();
        break;

        case 3:withdraw();
        break;

        case 4:Account_Details();
        break;

        case 5:customer_list();
        break;

        case 6:close();
        break;

    }



}

void new_acc()

{

    int choice;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t  ADD RECORD  ");

    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %s %s %f \n",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account number already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;

    printf("\n\n        CODE          TITLE           INTEREST RATE   MINIMUM BALACE");
    printf("\n\n\t#N            Normal          %4              Rs.500\n\t#E            Eighteen Plus   %4.5            Rs.1000\n\t#R            Rankakulu       %5              Rs.1500\n\t#W            Wanitha         %4.7            Rs.1000\n\n");
        printf("\nEnter the name: ");
    scanf("%s",add.name);
    printf("\nEnter the NIC number: ");
    scanf("%s",&add.nic);
    printf("\nEnter the amount to deposit: Rs. ");
    scanf("%f",&add.amt);
    printf("\nType of account: ");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %s %s %f \n",add.acc_no,add.name,add.nic,add.acc_type,add.amt);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void Deposit(void)
{
    int balance,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the account no. :");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %s %s %f ",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nEnter The Amount You Would Like To Deposit : ");
            scanf("%d",&balance);
            system("cls");

                add.amt+=balance;

                fprintf(newrec,"%d %s %s %s %f \n",add.acc_no,add.name,add.nic,add.acc_type,add.amt);
                system("cls");
                printf("Changes saved!");


        }
        else
            fprintf(newrec,"%d %s %s %s %f \n",add.acc_no,add.name,add.nic,add.acc_type,add.amt);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

   if (add.acc_no!=upd.acc_no)
   {
       printf("\n\nRecord not found!!");
   }
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();

}


void customer_list()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\n  ACC. NO.\t   ACC TYPE\t\t\t       NAME\t\t\tNIC\t\t\t BALANCE\n");

    while(fscanf(view,"%d %s %s %s %f ",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
       {
           printf("\n  %6d\t %10s\t\t\t %10s\t\t %10s\t\t\t %f",add.acc_no,add.acc_type,add.name,add.nic,add.amt);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}


void withdraw(void)
{

    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    printf("Enter the amount you want to withdraw: Rs. ");
    scanf("%f",&transaction.amt);

if(add.amt>transaction.amt)
{

    while (fscanf(old,"%d %s %s %s %f ",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {

                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %s %s %f\n",add.acc_no,add.name,add.nic,add.acc_type,add.amt);


                     printf("\nwithdraw to account no. :");
         scanf("%d",&upd.acc_no);
        while(fscanf(old,"%d %s %s %s %f ",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
        {
          if (add.acc_no==upd.acc_no)

            {   test=1;

                system("cls");

                add.amt+=transaction.amt;

                fprintf(newrec,"%d %s %s %s %f \n",add.acc_no,add.name,add.nic,add.acc_type,add.amt);
                system("cls");
                printf("\n\nWithdraw successfully!");


        }

   }
   }
   }
}
else
{
    printf("\n\nYou haven't enough money  ");
}

   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");



   if (add.acc_no!=upd.acc_no)
   {
       printf("\n\nRecord not found!!");
   }




if(test!=1)
   {

       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        withdraw();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }


   if (add.acc_no!=upd.acc_no)
   {
       printf("\n\nRecord not found!!");
   }
   }



void Account_Details(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");

       printf("  Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %s %s %f ",&add.acc_no,add.name,&add.nic,add.acc_type,&add.amt)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\n  Account NO.:%d\n  Name:%s \n  NIC number:%s \n  Type Of Account:%s \n  Amount deposited:Rs. %f \n\n",
                       add.acc_no,add.name,add.nic,add.acc_type,add.amt);



            }
        }

    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    Account_Details();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else

        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void close(void)
   {
     printf("\n\n\t\t\t\t\n                        _______________________________________\n\n                                *******ABC BANK *******\n                        _______________________________________");
     printf("\n\n\n\n\n\n         **************************...THANK YOU...*************************\n\n\n");
    }



int main(void)
{

    int i=0;
    printf("LONDING\t");


        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();




}
