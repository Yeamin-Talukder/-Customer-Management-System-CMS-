
## Hi, I'm Md Yeamin Talukder 👋


# Customer Management System (CMS)


Welcome to our Customer Management System (CMS) project! We made this project for big companies that have multiple branches across the country. We have two databases in this project, one for managing all branches and the other for managing all customers. Those two databases are branch.txt and customer.txt . In our program, we have two main parts: administration and branch management. The administrator can control all branch details, and the branch manager can control all customer details.In the customer section we add points to customer id accoding to their buying and delete point if they want to use those point for vouchers. This is a very basic customer management system with few functionalities. 



# Features

- ### Add  new Branch:
We can add a new branch to the branch.txt database using admin mode.

-  ###  Delete Branch :
We can delete branches from the branch.txt database using admin mode.

- ###  Update branch:
We can update branch data from the branch.txt database using admin mode. 

- ###  Show Branch :
We can see all the branch details at once in a table formet in admin mode.

- ### Add customer:
We can add customer details to the customer.txt database using branch maneger mode.

- ###  Add Point :
We can add a point in customer ID accoding to their bying in branch mode.

- ### Use point :
We can use save points for vouchers. This will delete a certain number of points from the customer save point.

- ### Search Customer :
We can search for customers using their details in branch mode.


# Files Details
 -  main.c           -> This is the main file that run to start the program.
 -  admin funtion.h  -> This header file have all the admin oparetion  functions and main page working funtions.
 -  branch funtion.h -> This header file have all the branch oparetions functoins .
 -  branch.txt       -> This txt file use as a database for saveing branch and admin details.
 -  customer.txt     -> This txt file use as a database for saveing all customer data.

 # ROADMAP OF PROGRAM :
   ## Admin Login :-
  >   ###  Admin Mode :
   >> -  ADD NEW BRANCH
   >> - DELETE BRANCH
   >> - UPDATE BRANCH
   >> - SHOW ALL BRANCHS
   >> - LOG OUT

  ## Branch Login :-
  >  ### Branch  Mode :                    
  >> - ADD POINTS
  >> - USE POINTS
  >> - SEARCH CUSTOMER
  >> -  LOG OUT

  ## Exit                       



# project Graph
![project graph bl](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/625af126-c63b-4b59-a059-140ba38e503c)



# Setup process
- create a new folder for this project
- place main.c and the header files in that folder
- create another folder within it name it output
- place txt file in output folder
- now you are ready to go run the main.c file




# SCREENSHOTS

 #### OPEN PAGE 
![Screenshot 2023-10-19 225320](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/d4464ffe-4ed5-4cc9-88d3-e6471c7f5ef4)

#### LOGIN PAGE

![Screenshot 2023-10-19 225623](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/a9f45544-4f63-4295-8cdd-c0c517ff2c7e)

 #### ADMIN MODE

![Screenshot 2023-10-19 225634](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/57fc9532-26e6-4a5b-a274-45ac88527af8)

#### SHOW BRANCH

![Screenshot 2023-10-19 230232](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/83554504-65f4-48a1-af80-0cc4551938ce)

 #### BRANCH MODE
![Screenshot 2023-10-20 001307](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/356f8a34-3e0f-4d46-a853-9e26aec127a7)


#### CUSTOMER DETAILS
![Screenshot 2023-10-19 230554](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/bd1bd6e9-872c-4226-8a57-78aafb657c92)

 #### BRANCH.TXT FILE
![Screenshot 2023-10-19 231314](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/8d398137-050b-4522-b053-8fb040b9b278)


 #### CUSTOMER.TXT FILE
 ![Screenshot 2023-10-19 231301](https://github.com/Yeamin-Talukder/-Customer-Management-System-CMS-/assets/61332874/bb420bb1-b6f8-4cab-ab86-a47abd574d17)






# Work of each funtion


## choose_funtion :
  #### Input :
    None

  #### Output :
    Welcome to Our CMS Server

        Press 1 to continue as System Administrator.
        Press 2 to continue as Branch Manager.
        Press 3 to Exit.
  
  #### Return : 
       None
  
 #### Work
    choose_funtion() First, this function calls the main_menu 
    function and saves it's return value inside the press 
    variable. Now we check 
    
    if the return value = 1 , then run the 
    admin_login function. If " admin_login " function returns a 
    value successfully, then we clear the previous screen and 
    print "YOU ARE Logged in AS ADMIN.". Then we run the " 
    admin_open_page " function for further workflow.
    
    If the return value = 2 , then run the branch_login function.
    If " branch_login " funtion return value successfully, then
    we clear the previous screen and print "YOU ARE Logged in AS 
    Branch Maneger.". Then we run the " branch_open_page " 
    function for further workflow.
    
    If the return value = 3 , then we terminate the program.

#### Code 

```c 
int choose_funtion()
{
system("cls");
int press = main_menu();
if (press == 1)
{
    user_index = login(press);    
    admin_open_page();
}

else if (press == 2)
{    user_index = login(press);
     branch_open_page();
}

else if (press == 3)
{
    return 0;
}

}



```


## main_menu : 

   #### Input :
      Press -> This variable gets the Select Option data.


  #### Output :
     Welcome to Our CMS Server

        Press 1 to continue as System Administrator.
        Press 2 to continue as Branch Manager.
        Press 3 to Exit.

      Select Option :

  #### Return :
      press variable

#### work :

    This function shows all the login options and Exit options.
    Then it takes one input from the user to select from those 
    options and return it

#### Code 

```c

int main_menu(){
    
printf("Welcome to Our CMS Server\n\n");
printf("\tPress 1 to continue as System Administrator.\n");
printf("\tPress 2 to continue as Branch Manager.\n"); 
printf("\tPress 3 to Exit.\n");
int press;
printf("\nSelect Option : ");
scanf("%d",&press);
printf("\n\n");

if (press == 1 || press == 2 || press == 3)
{
    return press;
}

else
{
    printf("You choose worng option choose again.\n");
    choose_funtion();
}


}

```



## login :

   #### Input :
        Username -> User Username
        Password -> user Password

  #### Output :

    Admin/Branch Login

    Enter username: 
    Enter password: 

#### Return :

    Index -> user row number from the database

#### Work :

    This function takes a username and password from the user and 
    check them with database entries. If this function is found the
    data, then it returns that data; else, it gives you an option.
    to try again or return to the main menu.


#### Code :

```c



int login(int choose) {
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




```







## admin_open_page :

#### Input :

    n -> This variable take input for doing selective opretion

#### Output :

    Admin Mode :

        press 1 for add new Branch
        press 2 for delete  Branch
        press 3 for update  Branch
        press 4 for show  Branchs
        press 0 for Log Out

#### Return :
     None

#### Work :

    This function shows the options that admin can do and take 
    input to select from those options. Then accoding to select it 
    run another function to do that work.

 #### Code :

 ```c

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



 ```








 ## add_branch :

  #### Input :
      branch_username -> Take user name 
      branch_password -> Take user password
      city_name       -> Take Branch name
      number          -> Take branch number

  #### Output : 
      Enter username:
      Enter password: 
      Enter Branch Name:
      Enter number:

  #### Return :
      None

  #### Work :

      This function take data from user and add it into branch.txt 
      database.Then it call the admin_open_page funtion.

  #### Code :

  ```c

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

  ```



## branch_delete :

 #### Input :

     line -> This is the row number that user want to delete

#### Output :
    It shows all the branch data list in a table format 

#### Return :
    None

 #### Work :

     This function takes one integer input then deletes that line 
     data from the database and call the function 
     admin_open_page   

 #### code :

 ```c



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

 ```    


## branch_update :

  #### Input :
    line -> This is the row number that user want to update

  #### Output :
    It shows all the branch data list in a table format

  #### Return :
    None

  #### Work :
      
    This function take data from user and update it into branch.
    txt database.Then it call the admin_open_page funtion.

  #### Code :

 ```c


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
    

```







## show_branch_list :
  
  #### Input :
    None
  #### Output :

    Show all branchs data in table format 
  #### Return :
    None

  #### Work : 
    This function fetches data from the branch.txt database.
    and print it in table format.       

  #### Code :

 ``` c  


void show_branch_list()
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
    
   printf("\n\nWhat do you think next Admin?\n");
   admin_open_page();

}




 ```








 ## branch_open_page :

 #### Input :

    n -> This variable take input for selecting options

 #### Output :
    
    BRANCH MODE :

           press 1 for add points
           press 2 for Use points
           press 0 for Log Out   

#### Return :
    None

#### Work :
    This function takes input  from the user and runs the 
    operations functions corresponding to it. 


#### Code :
    
   ```c


int branch_open_page()
{

printf("\n\nBRANCH MODE :\n\n");


printf("\tpress 1 for add points\n");
printf("\tpress 2 for Use points\n");
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
case 0:
choose_funtion();
default:
    break;
}

}


   ```








## point_user :
 #### Input :

    Username -> User Username
    number   -> user Password

#### Output :
    Name   : 
    Number : 
    Point  : 

 #### Return :
    Return The index number of the customer


 #### work : 
    Take input from the user and search the database for user 
    if found then output it's details else it show options 
    to add it to our database or go to branch open page.
#### Code :

```c


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


 ```








      
## point :
  
  #### Input :
      coin -> The number of coin you want to delete or add 

 #### Output : 
    Give me the point value  :

#### Return :
    None

#### Work :
    First This function call point_user function then save it's 
    return value in target variable .Then it takes the amount of 
    add/delete points.Then do the add/delete oparetion.Last it call
    the branch open funtion .

#### Code :

```c

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
   else
   {
 fprintf(fp2, "%s\t\t%s\t\t%i\n",  user.c_usernames,user.c_password,user.point-coin);
printf("\n\nOparetion sucessful\n\n");

printf("New Details\n\n");

printf("\tNAME : %s\n\tNumber : %s \n\tPoint : %i",  user.c_usernames, user.c_password, user.point-coin);

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


```




# Thank you 







