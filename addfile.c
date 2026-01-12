#include"addfile.h"
#include<stdio.h>                                             // required for printf(),scanf()
#include<string.h>                                            // required for strcpy(),strcmp()
#include <stdlib.h>                                           // required for system("clear")
#include <unistd.h>
#include"contact.h"


void addtofile(){                                             //SAVE CONTACT TO FILE
    FILE*fp;
    fp=fopen("addressbook.csv","w");
    if(fp==NULL){
        printf("File not created"); 
        return;
    }
    fprintf(fp,"%d\n",i);
    for(int z=0;z<i;z++){
        fprintf(fp,"%s,%s,%s\n",list[z].name,list[z].phone_number,list[z].email_id);
    }
    fclose(fp);
}



void loadfile(){                                     //LOAD CONTACT FROM FILE TO STRUCTURE
    int z;

    FILE*fp;
    fp=fopen("addressbook.csv","r");
    if(fp==NULL){
        printf("File not created \n"); 
        return;
    }
     fscanf(fp,"%d\n",&i);
    for(z=0;z<i;z++){
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",list[z].name,list[z].phone_number,list[z].email_id);
    }
}
