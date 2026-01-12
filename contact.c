#include "contact.h"
#include<stdio.h>                                             // required for printf(),scanf()
#include<string.h>                                            // required for strcpy(),strcmp()
#include <stdlib.h>                                           // required for system("clear")
#include <unistd.h>
struct address list[100]= {
    {"Sugavelan", "9876543210", "suga@gmail.com"},
    {"Babu", "9123456789", "babu@gmail.com"},
    {"Yogender", "9999999999", "yogender@vit.ac.in"},
    {"Sethu","1111122222","sethu@gmail.com"},
    {"Mughil","9876556789","mugi@gmail.com"}
};                                                                        //global variable

int i=5;                                                      //counter for number of contacts

int isvalidname(char name[]){
    
    int flag_name=0;
     
        for(int j=0;name[j]!='\0';j++){
            if(name[j]>='0' && name[j]<='9'){
                printf("\n❌ Name Should Not Contain Numbers\n");
                printf("Enter The Name Again!\n");
                printf("\n");
                flag_name=1;
                break;
            }
        }
    if(flag_name==1) return 1;
    else if(flag_name==0) return 0;   
}

int isvalidnumber(char number[]){
    int flag_number=0;

        for (int j = 0; j < i; j++) {
            if (strcmp(list[j].phone_number, number) == 0) {
                printf("\n❌ Phone Number Already Exists!\n\n");
                flag_number = 1;
                break;
            }
        }

                if(strlen(number)!=10){
                        printf("❌Phone Number Should Be 10 Digits\n");
                        printf("Enter The Phone Number Again!\n");
                        printf("\n");
                        flag_number=1; 
                }
                
                
            if(flag_number==0){
                for(int j=0;number[j]!='\0';j++){  

                    if(!(number[j]>='0' && number[j]<='9')){
                        printf("❌Phone Number Should Only Contain Number\n");
                        printf("Enter The Phone Number Again!\n");
                        printf("\n");
                        flag_number=1;
                        break;
                    }
                }
            }
   

   if(flag_number==1) return 1;
   else if(flag_number==0) return 0;  
}


int isvalidemail(char mail[]){
    int flag_mail=0;
       
        char*at=strchr(mail,'@');
        char*dot1=strchr(mail,'.');
        char*dot=strrchr(mail,'.');
        for(int j=0;j<i;j++){
            if(strcmp(list[j].email_id,mail)==0){
                printf("❌ Email ID Already Exists!\n\n");
                flag_mail=1;
                break;
            }
            
        }
        if(flag_mail==0){
            if (at==NULL || dot==NULL){
                printf("❌ Email Not Valid\n");
                printf("Enter The Email Again!\n");
                printf("\n");
            flag_mail=1;
            }
            else if(at>dot){
                printf("❌ Email Not Valid\n");
                printf("Enter The Email Again!\n");
                printf("\n");
                flag_mail=1;
           }
            else if(at==mail || dot==at+1 || *(dot+1)=='\0'||dot1==at+1||dot1==mail){
                printf("❌ Email Not Valid\n");
                printf("Enter The Email Again!\n");
                printf("\n");
                flag_mail=1;
            }

        }
         
    printf("==================================================\n");   
    if (flag_mail==1) return 1; 
    else if(flag_mail==0) return 0;
    
}   


int addcontact(char name[],char number[],char email[])                      //TO ADD A CONTACT
{
   
strcpy(list[i].name,name);
strcpy(list[i].phone_number,number);
strcpy(list[i].email_id,email);
i++;
return 1;

}



int searchcontact(){
    char search[20];
    int z,flag=0;
    printf("Enter Name or Phone_number or Email_id:");
    scanf(" %[^\n]",search);
    printf("%-3s %-20s %-20s %-30s\n", "No", "Name", "Phone Number", "Email ID");
    for(z=0;z<i;z++){
    if(strcmp(search,list[z].name)==0 || strcmp(search,list[z].phone_number)==0 || strcmp(search,list[z].email_id)==0){
        printf("%-3d %-20s %-20s %-30s\n",z,list[z].name,list[z].phone_number,list[z].email_id);
        flag=1;
       }
    }
    if(flag==1) return 1;
    else return 0;
    
 }



int viewcontact(){
    int z;
    printf("%-20s %-20s %-30s\n", "Name", "Phone Number", "Email ID");
    for(z=0;z<i;z++){
        printf("%-20s %-20s %-30s \n",list[z].name,list[z].phone_number,list[z].email_id);
    }
    return 1;
}







//TO EDIT A CONTACT//

int editcontact(){
    char edit[50];
    int flag_num=0;
    int z,re=-1,count=0;
    int invalid_input=0;
if(i==0) printf("⚠️ No Contacts Available To Edit\n");
else{
             printf("Enter The Detail:");
             getchar();
             scanf(" %[^\n]",edit);
for(z=0;z<i;z++){
if(strcmp(edit,list[z].name)==0 || strcmp(edit,list[z].phone_number)==0 || strcmp(edit,list[z].email_id)==0){
        re=z;
        count++;
}
}
if(count>1){
    printf("\n ⚠️ Multiple Contacts Found With The Same Detail. Please Be More Specific.\n");
    printf("==================================================\n");
     printf("%-3s %-20s %-20s %-30s\n", "No", "Name", "Phone Number", "Email ID");
    for(z=0;z<i;z++){
        if(strcmp(edit,list[z].name)==0 || strcmp(edit,list[z].phone_number)==0 || strcmp(edit,list[z].email_id)==0){
            printf("%-3d %-20s %-20s %-30s\n",z,list[z].name,list[z].phone_number,list[z].email_id);
        }
    }
    printf("==================================================\n");
    printf("Please Enter The Phone Number Of The Contact You Want To Edit:\n");
    char num[15];
   
    do{
        flag_num=0;
        printf("Enter The Phone Number:\n");
        getchar();
        scanf(" %[^\n]",num);
        for(int j=0;j<i;j++){
            if(strcmp(num,list[j].phone_number)==0){
                re=j;
                break;
            }
        }
        if(strcmp(num,list[re].phone_number)!=0){
            printf("❌ Phone Number Not Found. Please Enter Again.\n");
            flag_num=1;
        }
    }while(flag_num==1);
 
}

if(re==-1) printf("\n ⚠️ Contact Not Found\n");
else{
    printf("%-20s %-20s %-30s \n",list[re].name,list[re].phone_number,list[re].email_id);
    printf("What Do You Want To Edit:\n1.Name\n2.Phone Number\n3.Email Id\n");
    int c;
    do{                                                                   //inner do while for invalid input
        printf("Enter Your Choice:\n");
    scanf("%d",&c);
    switch(c){
        case 1:
        {
            char name[30];
            int flag_name=0;
           do{ 
            flag_name=0;
            printf("Enter The New Name:\n");
            getchar();
            scanf(" %[^\n]",name);
            flag_name=isvalidname(name);
        }while(flag_name==1);
        if(flag_name==0){
            strcpy(list[re].name,name);
            printf("✅ The Contact Has Edited Successfully\n");
            printf("%-20s %-20s %-30s \n",list[re].name,list[re].phone_number,list[re].email_id);
            break;
        }
    }
        case 2:
        {
          
            char number[15];
            int flag_number=0;
            do{
                flag_number=0;
            printf("Enter The New Phone Number:\n");
            getchar();
            scanf(" %[^\n]",number);
          flag_number= isvalidnumber(number);
            } while(flag_number==1);

            if(flag_number==0){
                strcpy(list[re].phone_number,number);
                printf("The Contact Has Edited Successfully\n");
                printf("%-20s %-20s %-30s \n",list[re].name,list[re].phone_number,list[re].email_id);
            }
            
            break;
    }
        case 3:
        {
            char mail[30];
            int flag_mail=0;
            do{
                flag_mail=0;
            printf("Enter the new email id:\n");
            getchar();
            scanf(" %[^\n]",mail);
            flag_mail=isvalidemail(mail);
        
    }while(flag_mail==1); 
            if(flag_mail==0){
                strcpy(list[re].email_id,mail);
                printf("The Contact Has Edited Successfully✅\n");
                printf("%-20s %-20s %-30s \n",list[re].name,list[re].phone_number,list[re].email_id);
            }
            break;
}
        default:
        {
            printf("⚠️ Invalid Input\n");
            invalid_input=1;
            break;

}
}
    }while(invalid_input==1);                                       //closing of do while for invalid input
return 1;
}
}
}




//TO DELETE A CONTACT//


int removecontact(){
    char remove[20];
    int z,re=-1,count=0;
printf("👤 Enter The Detail:");
scanf(" %[^\n]",remove);
for(z=0;z<i;z++){
if(strcmp(remove,list[z].name)==0 || strcmp(remove,list[z].phone_number)==0 || strcmp(remove,list[z].email_id)==0){
        re=z;
        count++;       
}
}
if(count>1){
    printf("\n ⚠️ Multiple Contacts Found With The Same Detail. Please Be More Specific.\n");
    printf("==================================================\n");
     printf("%-3s %-20s %-20s %-30s\n", "No", "Name", "Phone Number", "Email ID");
    for(z=0;z<i;z++){
        if(strcmp(remove,list[z].name)==0 || strcmp(remove,list[z].phone_number)==0 || strcmp(remove,list[z].email_id)==0){
            printf("%-3d %-20s %-20s %-30s\n",z,list[z].name,list[z].phone_number,list[z].email_id);
        }
    }
    printf("==================================================\n");
    printf("Please Enter The Phone Number Of The Contact You Want To Delete:\n");
    char num[15];
   int flag_num=0;
    do{
         flag_num=0;
        printf("Enter The Phone Number:\n");
        getchar();
        scanf(" %[^\n]",num);
        for(int j=0;j<i;j++){
            if(strcmp(num,list[j].phone_number)==0){
                re=j;
                break;
            }
        }
        if(strcmp(num,list[re].phone_number)!=0){
            printf("❌ Phone Number Not Found. Please Enter Again.\n");
            flag_num=1;
        }
    }while(flag_num==1);
if(re==-1) printf("\n ⚠️  Contact Not Found");
else{
for(z=re;z<i;z++){
    list[z]=list[z+1]; 
}
i--;
printf("%-3s %-20s %-20s %-30s\n", "No", "Name", "Phone Number", "Email ID");
for(z=0;z<i;z++){
        printf("%-3d %-20s %-20s %-30s\n",z,list[z].name,list[z].phone_number,list[z].email_id);
    }
    printf("\n 🗑️  The Contact Has Deleted Successfully✅");
}
return 1;
}
}
