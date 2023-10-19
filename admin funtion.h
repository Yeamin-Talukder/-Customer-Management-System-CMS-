

// defineing necessary data for header file

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int user_index;


#define max 1000
#define min 1000

#define Branch_file "Branch.txt"


//branch stracture declaration

struct branch {
char branch_usernames[max];
char branch_password[max];
int position;

char city_name[max];
long long int branch_number;
};



//customer stracture declaration


struct cms {
char c_usernames[max];
char c_password[max];
long long int point;
};











// main login system beginning one


// main login system


int login(int choose) {

system("cls");

    char username[max];
    char password[max];

char mode[20];

if (choose == 1)
{
    printf("Admin Login \n\n");
strcpy(mode, "Admin");
}

else if (choose == 2)
{
    printf("Branch Login \n\n");
    strcpy(mode, "Branch");
}

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(Branch_file, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }
    struct branch user;
    int index = 0;

int position = (choose == 1)? 1 :0;


    while (fscanf(file, "%s %s %i %s %lli", user.branch_usernames, user.branch_password, &user.position,user.city_name,&user.branch_number) != EOF)
    {
        if (strcmp(username, user.branch_usernames) == 0 && strcmp(password, user.branch_password) == 0 && user.position == position)
        {
            fclose(file);
            system("cls");
            printf("Welcome to %s Mode %s\n\n",mode,username);
            return index; // Return the index of the logged-in user
        }
        index++;
    }

    fclose(file);
   
   printf("Username of password Does not match\n");
   printf("\tpress 1 to try again\n");
   printf("\tPress 2 for main page\n");
   
   int select;
   scanf("%d",&select);

   if (select == 1)
   {
login(choose);

   }
   
   else if (select == 2)
   {
choose_funtion();
   }

else
{
    printf("Please choose correct option\n");
    login(choose);
}


    // Invalid login
}














// main open page function or you can say main menu functionality


int main_menu(){
    
printf("Welcome to Our CMS Server\n\n");
printf("\tPress 1 to continue as System Administrator.\n");
printf("\tPress 2 to continue as Branch Manager.\n"); 
printf("\tPress 0 to Exit.\n");
int press;
printf("\nSelect Option : ");
scanf("%d",&press);
printf("\n\n");

if (press == 1 || press == 2 || press == 0)
{
    return press;
}

else
{
    printf("You choose worng option choose again.\n");
    choose_funtion();
}


}











// This funtion will activate main menu funtion and then do the chooseing thing
int choose_funtion()
{
    system("cls");


int press = main_menu();

    

if (press == 1)
{
    user_index = login(press);    
    admin_open_page();
}

else if(press == 2)
{    user_index = login(press);
     branch_open_page();
}

else if (press == 0)
{
    return 0;
}



}



















// admin open page funtion

int admin_open_page(){
printf("Admin Mode :\n\n\n\n");

printf("\tpress 1 for add new Branch\n");
printf("\tpress 2 for delete  Branch\n");
printf("\tpress 3 for update  Branch\n");
printf("\tpress 4 for show  Branchs\n");
printf("\tpress 0 for Log Out\n");

int n;
scanf("%d",&n);

switch (n)
{
case 1 : // case 1 adding funtion done work properly
    add_branch();
    break;

case 2 : // case 2 delete funtion is under construction
branch_delete();
break;

case 3 : // case 3 update function is under construction
branch_update();
admin_open_page();
break;

case 4 : // case 4 done
show_branch_list();
default:

case 0 :
choose_funtion(); // case 0 done
    break;
}
    
}















// This funtion will add new branches to the ilst useing admin power




void add_branch()
{
    FILE *file = fopen(Branch_file, "a");//declares a file in append (a) mode
    if (!file) {
        printf("Error opening users file.\n");
        return;
    }

    struct branch newUser;

    printf("Enter username: ");
    scanf("%s", newUser.branch_usernames);

    printf("Enter password: ");
    scanf("%s", newUser.branch_password);

// seting postion to 0 because brance postion is always 0 
   newUser.position = 0;

    printf("Enter Branch Name: ");
    scanf("%s", newUser.city_name);

    printf("Enter number: ");
    scanf("%lld",&newUser.branch_number);

// incerting the data in the txt file

    fprintf(file, "%s\t\t%s\t\t%i\t  %s\t\t%lli\n", newUser.branch_usernames, newUser.branch_password, newUser.position,newUser.city_name, newUser.branch_number);
    fclose(file);
        
    printf("Registration successful!\n\n");
    

    // opening admin page further oparetions
    printf("Hey Admin What's Next?\n\n");
    admin_open_page(); 
}










// show brance list of admin controllers

void show_branch_list()
{

system("cls");

 FILE *file = fopen(Branch_file, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }


struct branch user;
int i = 1;  

printf("         USERNAME       PASSWORD     POSITION      CITY NAME       BRANCH NUMBER\n");
printf("-------------------------------------------------------------------------------------\n\n");

    while (fscanf(file, "%s %s %i %s %lli", user.branch_usernames, user.branch_password, &user.position,user.city_name,&user.branch_number) != EOF)
        {
             printf("%i) %12s      %8s     %8i      %12s   %15lli\n\n",i,user.branch_usernames, user.branch_password,user.position,user.city_name,user.branch_number);
i++;
}

  fclose(file);
    
   printf("\n\nWhat do you think next Admin?\n");
   admin_open_page();

}












// show brance list for other things

void show_branch_list_other()
{

 FILE *file = fopen(Branch_file, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }


struct branch user;
int i = 1;

    

printf("         USERNAME       PASSWORD     POSITION      CITY NAME       BRANCH NUMBER\n");
printf("-------------------------------------------------------------------------------------\n\n");

    while (fscanf(file, "%s %s %i %s %lli", user.branch_usernames, user.branch_password, &user.position,user.city_name,&user.branch_number) != EOF)
        {
             printf("%i) %12s      %8s     %8i      %12s   %15lli\n\n",i,user.branch_usernames, user.branch_password,user.position,user.city_name,user.branch_number);
i++;
}


  fclose(file);
  
   

}













// delete branch from selecting number of the data row


int branch_delete() {
   


   FILE *file = fopen(Branch_file, "r");  //declares a file in read mode

    if (!file) {
        printf("Error opening users file.\n");
        return;
    }


    FILE* fp2;
    fp2 = fopen("temp.txt", "w");


int line;
char ch;
int temp = 1;


show_branch_list_other();
    
    system("cls");
    printf("\nEnter line number to delete the line: ");
    scanf("%d", &line);


    while (!feof(file)) {
        ch = getc(file);

        if (ch == '\n')
            temp++;

        if (temp != line)
            putc(ch, fp2);
    }

    fclose(file);

    fclose(fp2);

    remove(Branch_file);
    rename("temp.txt", Branch_file);

        

    printf("/nFile delete Sucessfully :\n");



printf("\n\nWhat to do next?\n\n");

admin_open_page();




}






















//branch update useing copy methode




// branch update function



int branch_update()
{

   FILE *file = fopen(Branch_file, "r");  //declares a file in read mode

    if (!file) {
        printf("Error opening users file.\n");
        return;
    }


    FILE* fp2;
    fp2 = fopen("temp.txt", "a+");


int line;
char ch;
int temp = 1;


show_branch_list_other();
    
    printf("\nEnter line number to update the line: ");
    scanf("%d", &line);


    struct branch newUser;
    struct branch user;

printf("Enter New Username: ");
    scanf("%s", newUser.branch_usernames);

    printf("Enter New Password: ");
    scanf("%s", newUser.branch_password);

 printf("Enter New  Position: ");
    scanf("%i",&newUser.position);

  printf("Enter Full Name: ");
    scanf("%s", newUser.city_name);

    printf("Enter number: ");
    scanf("%lld",&newUser.branch_number);



     while (!feof(file)) {
fscanf(file, "%s %s %i %s %lli", user.branch_usernames, user.branch_password, &user.position,user.city_name,&user.branch_number);

       
        if (temp != line)
{ fprintf(fp2, "%s\t\t%s\t\t%i\t  %s\t\t%lli\n", user.branch_usernames, user.branch_password, user.position,user.city_name, user.branch_number);
  }
  
else
{
     fprintf(fp2, "%s\t\t%s\t\t%i\t  %s\t\t%lli\n", newUser.branch_usernames, newUser.branch_password, newUser.position,newUser.city_name, newUser.branch_number);

}


temp++;

     }




    fclose(file);
    fclose(fp2);


    remove(Branch_file);
    rename("temp.txt", Branch_file);

    
        

    printf("Update successful!\n\n");

printf("What to do next?\n\n");
admin_open_page();




    }
    
