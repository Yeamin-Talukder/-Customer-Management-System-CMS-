// branch login system 



#define CUSTOMER_FILE "customer.txt"

struct customer {
    char username[max];
    char number[max];
    int point ;
};







// branch open page


int branch_open_page()
{

printf("\n\nBRANCH MODE :\n\n");


printf("\tpress 1 for Add points\n");
printf("\tpress 2 for Use points\n");
printf("\tpress 3 for Customer points\n");
printf("\tpress 0 for Log Out\n");

int n;
scanf("%d", &n);

switch (n)
{
case 1:
   point(1);
    break;
case 2:
point(2);
break;

case 3:
point_user();
branch_open_page();
break;

case 0:
choose_funtion();
default:
    break;
}

}













//  point user funtion 


point_user()
{

  

char username[max];
    char Number[max];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter Number: ");
    scanf("%s", Number);
    
    FILE *file = fopen(CUSTOMER_FILE, "r+");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }
    
    struct cms user;
    int index = 1;

    while (fscanf(file, "%s %s %lli", user.c_usernames, user.c_password, &user.point) != EOF)
    {
        if (strcmp(username, user.c_usernames) == 0 && strcmp(Number, user.c_password) == 0)
        {
            fclose(file);
            printf("\n\nName   : %s\nNumber : %s\nPoint  : %lli\n",user.c_usernames, user.c_password, user.point);
            return index; // Return the index of the logged-in user
        }
        index++;
    }

    fclose(file);


printf("\nUser not found\n");

printf("\nDo you want to add this user to our database?\n1.Yes\n2.No\n");
int choose;
scanf("%d",&choose);


if (choose == 1)
{
   file = fopen(CUSTOMER_FILE, "a+");

 fseek(file, 0, SEEK_END);

 fprintf(file, "%s\t\t%s\t\t0\n", username,Number);

    fclose(file);
      




printf("Add user to database successfully\n");
    branch_open_page();


}



else
{
    branch_open_page();
}


}






















//add point funtion 

point(int choose)
{



int target = point_user();


printf("\n\nGive me the point value  : ");
int coin;
scanf("%d",&coin);


 FILE *file = fopen(CUSTOMER_FILE, "r+");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }
    

    FILE* fp2;
    fp2 = fopen("temp.txt", "w");





    struct cms user;
    int index = 1;

    while (fscanf(file, "%s %s %lli", user.c_usernames, user.c_password, &user.point) != EOF)
    {
        if (index != target )
        {
 fprintf(fp2, "%s\t\t%s\t\t%i\n",  user.c_usernames,user.c_password,user.point);

        }

else
{
    
    if (choose ==1)
    {
           fprintf(fp2, "%s\t\t%s\t\t%i\n",  user.c_usernames,user.c_password,user.point+coin);
    printf("\n\nOparetion sucessful\n\n");

printf("New Details\n\n");

printf("NAME : %s\n Number : %s \n Point : %i",  user.c_usernames, user.c_password, user.point+coin);

    
    }
   
   else if(user.point-coin >0)
   {
               fprintf(fp2, "%s\t\t%s\t\t%i\n",  user.c_usernames,user.c_password,user.point-coin);
printf("\n\nOparetion sucessful\n\n");

printf("New Details\n\n");

printf("\tNAME : %s\n\tNumber : %s \n\tPoint : %i",  user.c_usernames, user.c_password, user.point-coin);

   }
   
else
{
    printf("YOU DON'T HAVE ENOUGH POINT");
}


}


        index++;
    }

    fclose(file);

    fclose(fp2);


    remove(CUSTOMER_FILE);
    rename("temp.txt", CUSTOMER_FILE);





branch_open_page();


}

