#include<stdio.h>                                             // required for printf(),scanf()
#include<string.h>                                            // required for strcpy(),strcmp()
#include <stdlib.h>                                           // required for system("clear")
#include <unistd.h> 
#include"contact.h"                                          // required for sleep()
#include"addfile.h"



int main(){

    system("clear");
    int a,x;
    int add,search,view,edit;
    int invalid_input=0;
    char yn;
    loadfile();                                                     //to load the contact from the file
do{                                                                //outer do while for continue option
    do{                                                            //inner do while for invalid input  
        invalid_input=0;
printf("\n================ ADDRESS BOOK MENU ================\n");
printf("1. Add Contact\n");
printf("2. Search Contact\n");
printf("3. View Contacts\n");
printf("4. Edit Contact\n");
printf("5. Delete Contact\n");
printf("6. Save & Exit\n");
printf("==================================================\n");
printf("Enter your option: ");


        scanf("%d",&a);
switch(a){                                                          //switch case for main menu
  case 1:                                                          //add contact
    {
        char name[30],number[15],mail[30];
        int valid_name,valid_number,valid_email;
    do{
       
        printf("\n👤ENTER YOUR NAME:\n");
        getchar();                                                // to consume the newline character left by previous input
        scanf(" %[^\n]",name);
        valid_name=isvalidname(name);   
    }while(valid_name==1);
    if(valid_name==0) printf("==================================================\n");

    do{
        
        printf("\n📞ENTER YOUR PHONE NUMBER:\n");
        getchar();                                                // to consume the newline character left by previous input
        scanf(" %[^\n]",number);
        valid_number=isvalidnumber(number);   
    }while(valid_number==1);
    if(valid_number==0) printf("==================================================\n");

    do{
        printf("\n📧ENTER YOUR EMAIL ID:\n");
        getchar();                                               // to consume the newline character left by previous input
        scanf(" %[^\n]",mail);
        valid_email=isvalidemail(mail);   
    }while(valid_email==1);
    if(valid_email==0) printf("==================================================\n");

add=addcontact(name,number,mail);                                  //calling the function addcontact

    if(add==1){
        printf("🚀CONTACT ADDED SUCCESSFULLY\n");
        printf("\n");
    }
    break;
}


  case 2:
    {
    search=searchcontact();                                          //calling the function searchcontact
    if(search == 1){
        printf("\n✅successfully Completed\n");
         printf("\n==================================================\n");

    break;
    }
    else {
        printf("\n ⚠️ DATA NOT FOUND\n");
         printf("\n==================================================\n");

    break;
    }

}
    case 3:
    {
      view = viewcontact();                                        //calling the function viewcontact
      printf("\n==================================================\n");

      break;
}
   case 4:
   {
    edit=editcontact();                                            //calling the function editcontact
    printf("\n==================================================\n");

    break;
}
    case 5:
    {
        removecontact();                                           //calling the function removecontact
        printf("\n==================================================\n");

        break;
}
    
     case 6:
    {
        addtofile(); 
        printf("SAVING...\n");                                           //to add the contact to the file
        sleep(2); 
        printf("✅ SAVED SUCCESSFULLY\n");                                             
        return 0;
}
    default:
    {
        printf("⚠️ Invalid Input\n");
        invalid_input=1;
        printf("\n==================================================\n");

        break;
    }
   
}                                                                  //closing of main switch case
}while(invalid_input==1);                                         //closing of do while for invalid input

do{
    printf("\n▶  Do You Want To Continue: y/n:");
getchar();
scanf(" %c",&yn); 
if(yn!='y' && yn!='n'){
    printf("⚠️ Invalid Input\n");
}
}while(yn!='y' && yn!='n');                                       //closing of do for continue option


}                                                                 //closing of do main for continue option
while(yn=='y');

if(yn=='n'){
    printf("\nFile Not Saved\n");
    printf("\n==================================================\n");
    int x;
    printf("\n1.Save and Exit\n");
    printf("\n2.Exit\n");
    scanf("%d",&x);
    if(x==2){
        printf("\n==================================================\n");
        return 0;
    } 
    else{
    printf("\n==================================================\n");
    printf("\nPress ENTER To Save The File : ");
    char w;
    scanf("%c",&w);
    if(w=='\n'){
        addtofile(); 
        printf("SAVING...\n");                                           //to add the contact to the file
        sleep(2); 
        printf("✅ SAVED SUCCESSFULLY\n");  
        printf("\n==================================================\n");                                           
        return 0;
    }
    }
    
}
return 0;
}                   