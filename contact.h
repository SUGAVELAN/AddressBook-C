#ifndef CONTACT_H
#define CONTACT_H

struct address                                                //structure to store the contact details
{
    char name[30];
    char phone_number[15];
    char email_id[30];
};
extern struct address list[100];  
extern int i;   



int isvalidname(char name[]);
int isvalidnumber(char number[]);
int isvalidemail(char mail[]);


int addcontact(char name[],char number[],char email[]);
int searchcontact();
int viewcontact();
int editcontact();
int removecontact();
#endif