#include<stdio.h>
#include<string.h>
struct gaz{
     //bottle selling price
     int selpx;
     //the amount we spent buying that bottle
     int px;
     //the amount we spent buying 1kg of gaz
     int refpx;
     //the gaz refilling price/kg
     int refselpx;

}gz;



struct manger{
//manager's name
char name[55];
//the password
char pass1[25];
//gross profit
float proft;
//tva
float tva;

}mn;


struct journale{
     //customer name
     char name[40];
     //customer id
     int id;
     //kilograms of the bottle
     int kg;
     //the selling price
     int selpx;
     //the real price
     int px;
     //the gross profit
     float proft;
     //type of the transaction(refilling || new bottle)
     char type[19];
     //how many bottle to sell
     int qt;
     //the tva
     float tva;
     //the date
	struct dat{
		int day;
		int month;
		int year;
		}d;

}jr[100000];

int i,j,ch,n=0,z=0,k=0;

//struct gaz del;
//used to swap
struct journale temp;
//used to delete
struct journale rem;

//file for the prices
FILE *g;
//store the manager name and password
FILE *fm;
//file for the journale
FILE *jo;
//
//FILE *fst;
//store the counter for the id
FILE *rg;

//menu for recording
void rec();
//menu for displaying
void display();
//managers's menu
void manag();
//recoring a customer
void sell();
//for refilling
void refill();
//t set new prices
void newprice();
//setting password
void pass();
// desplay prices
void cost();
//report menu etc...
void prof();
//display sub menu
void disp();

//void prof();
//monthly report
void mothyear();
//annual report
void year();
//void daily();
//daily report
void daily();
//date sort
void datesort();
//
//void disp();
//display
void printt();
//sort by name
void namesort();
//find menu
void found();
//find using id
void useid();
//find by name
void usename();
//delete menu
void remov();
//delete sub menu
void dele();
//delete an id
void delid();
//delete by arrange of ids
void delids();

//void delname();
//how the syt works menu
void how();
//about us
void about();
//instructions 
void info();
//selling a bottle
void bottle();
//change pass
void chgpass();
//make months strings  
void months(int a,char r[23]);

void main()
{


     g=fopen("cost.txt","a+");
     fscanf(g,"%d\t%d\t%d\t%d",&gz.refselpx,&gz.refpx,&gz.selpx,&gz.px);
     fclose(g);


    jo=fopen("jour.txt","a+");
     do{
          fscanf(jo,"%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%f\t%f\n",&jr[k].id,jr[k].name,jr[k].type,&jr[k].d.day,&jr[k].d.month,&jr[k].d.year,&jr[k].kg,&jr[k].qt,&jr[k].selpx,&jr[k].px,&jr[k].tva,&jr[k].proft);

        //printf("%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",jr[k].id,jr[k].name,jr[k].type,jr[k].d.day,jr[k].d.month,jr[k].d.year,jr[k].kg,jr[k].qt,jr[k].selpx,jr[k].px,jr[k].tva,jr[k].proft);
          k++;

     }while(!feof(jo));
     fclose(jo);


     int m;
     do{

               printf("\n\n\t\t.......................................................................................");
     printf("\n\t\t.  ********   ********   ********      *********   **    **   *********   ********    .");
     printf("\n\t\t.  ********   ***  ***    *******      *********   **    **   *** * ***   *** * ***   .");
     printf("\n\t\t.  **         ***  ***       ***       **          **    **   **     **   **     **   .");
     printf("\n\t\t.  **         ********      ***        *********   ********   **     **   *** * **    .");
     printf("\n\t\t.  ** *****   ********     ***         *********   ********   **     **   *******     .");
     printf("\n\t\t.  **    **   **    **    ***                 **   **    **   **     **   **          .");
     printf("\n\t\t.  ********   **    **   *******       *********   **    **   *** * ***   **          .");
     printf("\n\t\t.  ********   **    **   ********      *********   **    **   *********   **          .");
     printf("\n\t\t.......................................................................................\n\n");

     printf("\n\t\t\t\t\t  MAIN MENU * MAIN MENU * MAIN MENU ");
     printf("\n\t\t\t\t\t**************************************");
     printf("\n\t\t\t\t\t*.............PRESS KEY..............*");
     printf("\n\t\t\t\t\t*    (0)LEARN HOW TO USE THE SYSTEM  *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*    (1)RECORDE A CLIENT             *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*    (2)DISPLAY TRANSACTIONS         *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*    (3)MANAGER'S CONTROL UNITY      *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*    (4)SAVE CHANGES AND EXIT        *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t**************************************\n\n\t\t\t\t\t");


          scanf("%d",&m);
          if(m==1)
          {
               rec();
          }
          else if(m==0)
          {
               info();
          }
          else if(m==2)
          {
               display();
          }
          else if(m==3)
          {
               pass();
          }
          else if(m==4)
          {


          }

          else{
               printf("\n\n\t\t!!!!!!\aCHOOSE BETWEEN 1 AND 4\a!!!!!!!\n\n");
          }
     }while(m!=4);




}


//tree functions

//bouton 1 recording customers transactions
void rec()
{
     int m;
     do{
     printf("\n\t\t\t\t\t\t*RECORD A TRANSACTION*");
     printf("\n\t\t\t\t\t**************************************");
     printf("\n\t\t\t\t\t*.............PRESS KEY..............*");
     printf("\n\t\t\t\t\t*        (1)RECORD A CUSTOMER        *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (2)PRICES                   *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (3)MAIN MENU                *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t**************************************\n\n\t\t\t\t\t");


          scanf("%d",&m);
          if(m==1)
          {
               sell();
          }
          else if(m==2)
          {
               cost();

          }
          else if(m==3)
          {

          }
          else{
               printf("\n\n\t\t\t\t\t!!!!!!\aCHOOSE BETWEEN 1 AND 3\a!!!!!!!\n\n");
          }
     }while(m!=3);

}

//bouton 2 to display or search a transaction made with a client



void display()
{

     int m;

     do{
     printf("\n\t\t\t\t\t\t*LIST OUT INFORMATIONS*");
     printf("\n\t\t\t\t\t**************************************");
     printf("\n\t\t\t\t\t*.............PRESS KEY..............*");
     printf("\n\t\t\t\t\t*        (1)DISPLA STRANSACTIOS      *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (2)FIND A CUSTOMER          *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (3)MAIN MENU                *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t**************************************\n\n\t\t\t\t\t");

          scanf("%d",&m);
          if(m==1)
          {
               disp();
          }
          else if(m==2)
          {
               found();

          }
          else if(m==3)
          {

          }

          else{
               printf("\n\n\t\t\t\t\t!!!!!!\aCHOOSE BETWEEN 1 AND 3\a!!!!!!!\n\n");
          }
     }while(m!=3);


}

//bouton 3 for the manager, to control the system and manage his/her business.


void manag()
{
     int m;

     do{
     printf("\n\t\t\t\t\t      *MANAGERE'S CONTROL UNITY*");
     printf("\n\t\t\t\t\t**************************************");
     printf("\n\t\t\t\t\t*.............PRESS KEY..............*");
     printf("\n\t\t\t\t\t*        (1)SET PRICES               *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (2)CHANGE PASS WORDS        *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (3)REPORTS                  *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (4)DELETE A TRSACTION       *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*        (5)MAIN MENU                *");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t**************************************\n\n\t\t\t\t\t");

          scanf("%d",&m);
          if(m==1)
          {
               newprice();
          }
          else if(m==2)
          {
               chgpass();

          }
          else if(m==3)
          {
               prof();
          }
          else if(m==4)
          {
               remov();

          }

          else if(m==5)
          {

          }

          else{
               printf("\n\n\t\t\t\t\t!!!!!!\aCHOOSE BETWEEN 1 AND 5\a!!!!!!!\n\n");
          }
     }while(m!=5);

}


//action functions


void sell()
{

     rg=fopen("id.txt","a+");
     fscanf(rg,"%d",&z);
     fclose(rg);
     z++;
     rg=fopen("id.txt","w");
     fprintf(rg,"%d",z);
     fclose(rg);


     jr[k].id=z;

     printf("\n\t\t\t\t\tENTER THE FOLLOWING INFORMATIONS:");
     printf("\n\t\t\t\t\tThe customer's Name:");
     scanf("%s",jr[k].name);
     strupr(jr[k].name);
     printf("\n\t\t\t\t\tThe date ex:(Day:11 Month:12 Year:2006)");
     printf("\n\t\t\t\t\tDay :");
     scanf("%d",&jr[k].d.day);
     printf("\t\t\t\t\tMonth :");
     scanf("%d",&jr[k].d.month);
     printf("\t\t\t\t\tYear  :");
     scanf("%d",&jr[k].d.year);
     int choi;

          printf("\n\t\t\t\t\tPRESS:\n\t\t\t\t\t1.TO SELL A BOTTLE OF GAZ\n\t\t\t\t\t2.TO REFILL GAZ IN A BOTTLE\n\t\t\t\t\t3.GO BACK\n\t\t\t\t\t");
          scanf("%d",&choi);
          if(choi==1)
          {
               bottle();
          }
          else if(choi==2)
          {
               refill();
          }

     k++;

}

  void bottle()
    {

     strcpy(jr[k].type,"BUY_A_BOTTLE");

     printf("\n\t\t\t\t\tHOW MANY Kg(it must be a 6kg,12kg,15kg,20kg,30kg or above):");

     scanf("%d",&jr[k].kg);

     printf("\n\t\t\t\t\tThe Quantity:");
     scanf("%d",&jr[k].qt);
       //accountability
     jr[k].selpx=gz.selpx*jr[k].qt*jr[k].kg;
     jr[k].px=gz.px*jr[k].qt*jr[k].kg;
     jr[k].proft=(jr[k].selpx-jr[k].px);
     jr[k].tva=jr[k].proft*0.18;

     int u;
     printf("\n\t\t\t\t\tPRESS:\n\t\t\t\t\t(1)TO SAVE THE TRANSACTION\n\n\t\t\t\t\t(2or else where)TO REJECT THE TRANSACTION\n\t\t\t\t\t");
     scanf("%d",&u);
     if(u==1)
     {
     jo=fopen("jour.txt","a");
     fprintf(jo,"%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",jr[k].id,jr[k].name,jr[k].type,jr[k].d.day,jr[k].d.month,jr[k].d.year,jr[k].kg,jr[k].qt,jr[k].selpx,jr[k].px,jr[k].tva,jr[k].proft);
     fclose(jo);


     printf("\n\t\t\t\t\tRECIPT: %d\tNAME:%s\n\t\t\t\t\tDATE:%d/%d/%d",jr[k].id,jr[k].name,jr[k].d.day,jr[k].d.month,jr[k].d.year);
     printf("\n\t\t\t\t\t|--------------------------------");
     printf("\n\t\t\t\t\t| QUNTITY: %d        ",jr[k].qt);
     printf("\n\t\t\t\t\t| TVA    : %.2f\tFrw      ",jr[k].tva);
     printf("\n\t\t\t\t\t| PRICE  : %d\tFrw        ",jr[k].selpx);
     printf("\n\t\t\t\t\t|--------------------------------");




     }



 //k++;
    }

void refill()
{

     strcpy(jr[k].type,"REFILL_BOTTLE");
     printf("\n\t\t\t\t\tThe bottle's weight (6kg,12kg,15kg,20kg or 30kg):");
     scanf("%d",&jr[k].kg);
     printf("\n\t\t\t\t\tHow many bottle                                 :");
     scanf("%d",&jr[k].qt);
     //accountability
     jr[k].selpx=gz.refselpx*jr[k].qt*jr[k].kg;
     jr[k].px=gz.refpx*jr[k].qt*jr[k].kg;
     jr[k].proft=(jr[k].selpx-jr[k].px);
     jr[k].tva=jr[k].proft*0.18;


     int u;
     printf("\n\t\t\t\t\tPRESS (1)TO SAVE THE TRANSACTION\n\n\t\t\t\t\tPRESS (2or else where)TO REJECT THE TRANSACTION\n\t\t\t\t\t");
     scanf("%d",&u);
     if(u==1)
     {
          jo=fopen("jour.txt","a");
          fprintf(jo,"%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",jr[k].id,jr[k].name,jr[k].type,jr[k].d.day,jr[k].d.month,jr[k].d.year,jr[k].kg,jr[k].qt,jr[k].selpx,jr[k].px,jr[k].tva,jr[k].proft);
          fclose(jo);

    printf("\n\t\t\t\t\tRECIPT: %d\tNAME:%s\n\t\t\t\t\tDATE:%d/%d/%d",jr[k].id,jr[k].name,jr[k].d.day,jr[k].d.month,jr[k].d.year);
     printf("\n\t\t\t\t\t|-------------------------------");
     printf("\n\t\t\t\t\t| QUNTITY: %d \tUnits        ",jr[k].qt);
     printf("\n\t\t\t\t\t| TVA    : %.2f\tFrw        ",jr[k].tva);
     printf("\n\t\t\t\t\t| PRICE  : %d\tFrw          ",jr[k].selpx);
     printf("\n\t\t\t\t\t|-------------------------------");



     }



     //k++;
}

void newprice()
{
     int l;
     do{
          printf("\n\t\t\t\t\tCHANGE PRICES:");
          printf("\n\t\t\t\t\t........................................");
          printf("\n\t\t\t\t\t. PRESS:                               .");
          printf("\n\t\t\t\t\t. (1)SET THE REFILLING PRICES          .");
          printf("\n\t\t\t\t\t. (2)SET THE BOTTLE PRICES             .");
          printf("\n\t\t\t\t\t. (3)SAVE AND EXIT                     .");
          printf("\n\t\t\t\t\t........................................");
          scanf("%d",&l);
          if(l==1)
          {
               printf("\n\t\t\t\t\tHOW MUCH DID 1Kg OF GAZ COST + EXPENSES:");
               scanf("%d",&gz.refpx);

               printf("\n\t\t\t\t\tAT HOW MUCH ARE YOU GOING TO SELL 1Kg:");
               scanf("%d",&gz.refselpx);

              // gz.reftva=gz.refselpx*0.18;

          }
          else if(l==2)
          {

                printf("\n\t\t\t\t\tHOW MUCH DID 1Kg OF GAZ BOTTLE COST + EXPENSES:");
               scanf("%d",&gz.px);

               printf("\n\t\t\t\t\tAT HOW MUCH ARE YOU GOING TO SELL 1Kg:");
               scanf("%d",&gz.selpx);

              // gz.tva=gz.selpx*0.18;

          }
          else if(l==3)
          {

               g=fopen("cost.txt","w");
               fprintf(g,"%d\t%d\t%d\t%d",gz.refselpx,gz.refpx,gz.selpx,gz.px);
               fclose(g);

               cost();

          }
     }while(l!=3);
}


void pass()
{

     fm=fopen("manager.txt","a+");
          fscanf(fm,"%s\t\t%s\n",mn.name,mn.pass1);
          fclose(fm);



     int m,d;
     char pass[5];
     m=strcmp(mn.pass1,"");
     if(m==0)
     {
          do
          {
          printf("\n\t\t\t\t\tDEFINE THE MANAGER'S PASSWORD\n\t\t\t\t\t5CHARACTERS MINIMUM\n\t\t\t\t\t");
          scanf("%s",mn.pass1);
          }while(5>strlen(mn.pass1));

          strupr(mn.pass1);
          printf("\n\t\t\t\t\tYOUR PASSWORD IS:%s",mn.pass1);
          printf("\n\t\t\t\t\tTHE MANAGER'S NAME:");
          scanf("%s",mn.name);
          strupr(mn.name);
          printf("\n\t\t\t\t\tTHE MANAGERE'S NAME IS:%s",mn.name);
     }

     int f=0;
     do{
     printf("\n\t\t\t\t\t      ****ENTER THE PASSWORD****\n\t\t\t\t\t      ==>:");
     scanf("%s",pass);
     strupr(pass);
     d=strcmp(pass,mn.pass1);

     fm=fopen("manager.txt","w");
          fprintf(fm,"%s\t\t%s",mn.name,mn.pass1);
          fclose(fm);


     if(d==0)
     {
          printf("\n\t\t\t\t\tWELCOME MANAGERE %s\n\t\t\t\t\t-------------------------------",mn.name);
         manag();

     }
     else{
               f++;
          printf("\n\t\t\t\t\t\a!!!!WRONG PASSCODE, YOU HAVE %d CHANCES....\n\t\t\t\t\t",3-f);
     }

     }while(d!=0 && f!=3);
}



void chgpass()
{
     int d;
    char pass[25];

     printf("\n\t\t\t\t\tCHANGE THE MANAGER PASSWORD:");
     printf("\n\t\t\t\t\tENTER THE EXISTING PASSWORD:");
     scanf("%s",pass);
     strupr(pass);
     d=strcmp(pass,mn.pass1);
     if(d==0)
     {
          do{
          printf("\n\t\t\t\t\tWHAT IS THE NEW PASSWORD(5 CHARACTERS ):");
          scanf("%s",mn.pass1);
          }while(5>strlen(mn.pass1));
          strupr(mn.pass1);
          printf("\n\t\t\t\t\tYOUR PASSWORD IS:%s",mn.pass1);
          printf("\n\t\t\t\t\tCHANGE THE MANAGER'S NAME :");
          scanf("%s",mn.name);
          strupr(mn.name);
          printf("\n\t\t\t\t\tTHE NEW MANAGERE'S NAME IS:%s",mn.name);

          fm=fopen("manager.txt","w");
          fprintf(fm,"%s\t\t%s",mn.name,mn.pass1);
          fclose(fm);

     }
     else{
          printf("\n\t\t\t\t\t\a!!!!WRONG PASSCODE....\n\t\t\t\t\t");
     }


}


void cost()
{

     printf("\n\t\t\t\t\tTHE PRICES:\n");
     printf("\n\t\t\t\t\tREFILLING SELLING PRICE:%d Frw",gz.refselpx);
     printf("\n\t\t\t\t\tREFILLING GAZ PRICE    :%d Frw",gz.refpx);
     printf("\n\t\t\t\t\tBOTTLE SELLING PRICE   :%d Frw",gz.selpx);
     printf("\n\t\t\t\t\tBOTTLE PRICE           :%d Frw",gz.px);
}



void prof()
{
     do
       {

     printf("\n\t\t\t\t\tPREESS:\n\t\t\t\t\t1.DAILY REPORT\n\t\t\t\t\t2.MOTHLLY REPORT\n\t\t\t\t\t3.ANNUAL REPORT\n\t\t\t\t\t4.EXIT");
     scanf("%d",&ch);
     if(ch==1)
     {
          daily();
     }
     else if(ch==2)
     {
          mothyear();
     }
     else if(ch==3)
     {
          year();
     }
       }while(ch!=4);
}

void mothyear()
     {


     int year,month,c=0,bt=0,rf=0;
     float tva=0,proft=0;
     printf("\n\t\t\t\t\tTHE MONTHLLY PROFIT AND TAXES\n\t\t\t\t\t----------------------------------\n");
     printf("\n\t\t\t\t\tSELECT THE MONTH AND THE YEAR ex:(MONTH:2,YEAR:2018):\n");
     printf("\n\t\t\t\t\tTHE MONTH:");
     scanf("%d",&month);
     printf("\n\t\t\t\t\tTHE YEAR:");
     scanf("%d",&year);



 printf("\n\t\t\t\t\tTHE TRANSACTIONS OF THE %d MONTH  OF THE YEAR %d \n\t\t\t\t\t---------------------------------\n",month,year);
for(i=0;i<k;i++)
{

     //printf("%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%f\t%f\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px,jr[i].tva,jr[i].proft);

     if(jr[i].d.month==month && jr[i].d.year==year)
          {
               //printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
               //printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
               //printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);


          if(0==strcmp(jr[i].type,"BUY_A_BOTTLE"))
          {
           bt++;
          }
          else{
               rf++;
          }



           printf("\n\t\t\t\t\tDATE: %d/%d/%d\tID: %d\tNAME: %s\tSERVICE: %s",jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].id,jr[i].name,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);

               proft=proft+jr[i].proft;
               tva=tva+jr[i].tva;
               c++;

          }
}
     char man[12];
     months(month,man);
     printf("\n\t\t\t\t\t%d TRANSACTIONS MADE IN %s OF %d  %d REFILLINGS  AND %d BOTTLES WERE SOLDE",c,man,year,rf,bt);
     printf("\n\t\t\t\t\t----------------------------------------------------------------------------\n\t\t\t\t\tWE GENERATED:\n\t\t\t\t\t1.GROSS PROFI:%.2f Frw\t2.PROFI:%.2f Frw\t3.TVA TO PAY IS OF:%.2f Frw\n",proft,(proft-tva),tva);
     printf("\n\t\t\t\t\tNB:THIS PROFIT DOSE NOT CONSIDER EXPENSES LIKE SALARIES AND OTHER GOUVERNMENT TAXES\n");
     printf("\t\t\t\t\tIT UP TO YOU TO MAKE SHURE THAT ALL TAXES AND EXPENSES WERE PAYED\n");

     }




void year()
{

     int year,month,c=0,bt=0,rf=0;
     float tva=0,proft=0;
     printf("\n\t\t\t\t\tTHE YEARLLY PROFIT AND TAXES\n\t\t\t\t\t----------------------------------\n");
     printf("\n\t\t\t\t\tSELECT THE YEAR ex:(YEAR:2018):\n");
     printf("\n\t\t\t\t\tTHE YEAR:");
     scanf("%d",&year);


     printf("\n\t\t\t\t\tTHE TRANSACTIONS OF THE YEAR %d \n\t\t\t\t\t-------------------------------\n",year);
for(i=0;i<k;i++)
{

     //printf("%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%f\t%f\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px,jr[i].tva,jr[i].proft);

     if(jr[i].d.year==year)
          {



          if(0==strcmp(jr[i].type,"BUY_A_BOTTLE"))
          {
           bt++;
          }
          else{
               rf++;
          }
              //printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
             // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
              //printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);
printf("\n\t\t\t\t\tDATE: %d/%d/%d\tID: %d\tNAME: %s\tSERVICE: %s",jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].id,jr[i].name,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);

               proft=proft+jr[i].proft;
               tva=tva+jr[i].tva;
               c++;

          }
}

     printf("\n\t\t\t\t\t%d TRANSACTIONS  MADE IN %d  %d REFILLINGS  AND  %d BOTTLES SOLDE",c,year,rf,bt);
     printf("\n\t\t\t\t\t------------------------------------------------------------------\n\t\t\t\t\tWE GENERATED:\n\t\t\t\t\t1.GROSS PROFI:%.2f Frw\t2.PROFI:%.2f Frw\t3.TVA TO PAY IS OF:%.2f Frw\n",proft,(proft-tva),tva);
     printf("\n\t\t\t\t\tNB:THIS PROFIT DOSE NOT CONSIDER EXPENSES LIKE SALARIES AND OTHER GOUVERNMENT TAXES\n");
     printf("\t\t\t\t\tIT UP TO YOU TO MAKE SHURE THAT ALL TAXES AND EXPENSES WERE PAYED\n");


}




void daily()
{

      int year,month,day,c=0,bt=0,rf=0;
      float tva=0,proft=0;
     printf("\n\t\t\t\t\tTHE MONTHLLY PROFIT AND TAXES\n\t\t\t\t\t----------------------------------\n");
     printf("\n\t\t\t\t\tSELECT THE DAY,THE MONTH AND THE YEAR ex:(DAY:1,MONTH:2,YEAR:2018):\n");
     printf("\n\t\t\t\t\tTHE YEAR :");
     scanf("%d",&year);
     printf("\n\t\t\t\t\tTHE MONTH:");
     scanf("%d",&month);
     printf("\n\t\t\t\t\tDAY      :");
     scanf("%d",&day);



     printf("\n\t\t\t\t\tTHE TRANSACTIONS OF THE: %d/%d/%d \n\t\t\t\t\t---------------------------------\n",day,month,year);
for(i=0;i<k;i++)
{

     //printf("%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%f\t%f\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px,jr[i].tva,jr[i].proft);

     if(jr[i].d.month==month && jr[i].d.year==year && jr[i].d.day==day)
          {
             // printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
             // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
             // printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);
          if(0==strcmp(jr[i].type,"BUY_A_BOTTLE"))
          {
           bt++;
          }
          else{
               rf++;
          }
            printf("\n\t\t\t\t\tDATE: %d/%d/%d\tID: %d\tNAME: %s\tSERVICE: %s",jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].id,jr[i].name,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);

               proft=proft+jr[i].proft;
               tva=tva+jr[i].tva;
               c++;

          }
}

     printf("\n\t\t\t\t\t%d TRANSACTIONS MADE ON %d/%d/%d  %d REFILLINGS  AND  %d BOTTLES SOLDE",c,day,month,year,rf,bt);
     printf("\n\t\t\t\t\t-----------------------------------------------------------------------\n\t\t\t\t\tWE GENERATED:\n\t\t\t\t\t1.GROSS PROFI:%.2f Frw\t2.PROFI:%.2f Frw\t3.TVA TO PAY IS OF:%.2f Frw\n",proft,(proft-tva),tva);
     printf("\n\t\t\t\t\tNB:THIS PROFIT DOSE NOT CONSIDER EXPENSES LIKE SALARIES AND OTHER GOUVERNMENT TAXES\n");
     printf("\t\t\t\t\tIT UP TO YOU TO MAKE SHURE THAT ALL TAXES AND EXPENSES WERE PAYED\n");

}



void datesort()
{
     for(i=0;i<k;i++)
     {
          for(j=i;j<k;j++)
          {
               if(jr[i].d.year>jr[j].d.year)
               {
                    temp=jr[i];
                    jr[i]=jr[j];
                    jr[j]=temp;
               }
               else if(jr[i].d.year==jr[j].d.year && jr[i].d.month>jr[j].d.month)
               {
                    temp=jr[i];
                    jr[i]=jr[j];
                    jr[j]=temp;
               }
               else if(jr[i].d.year==jr[j].d.year && jr[i].d.month==jr[j].d.month && jr[i].d.day>jr[j].d.day)
               {
                    temp=jr[i];
                    jr[i]=jr[j];
                    jr[j]=temp;
               }



          }
     }
     printt();
}


void disp()
{
     do{

          printf("\n\t\t\t\t\tPRINT:\n\t\t\t\t\t1.JUST PRINT\n\t\t\t\t\t2.ARRANGED BY DATE\n\t\t\t\t\t3.ARRANGED BY NAME(A=>Z)\n\t\t\t\t\t4.EXIT\n\t\t\t\t\t");

          scanf("%d",&ch);
          if(ch==1)
          {
             printt();
          }
          else if(ch==2)
          {
             datesort();
             //printt();
          }
          else if(ch==3)
          {
            namesort();
            printt();
          }

     }while(ch!=4);
}


void printt()
{
     if(k==0)
     {
          printf("\n\t\t\t\t\t\aTHE LIST IS EMPTY\n");
     }
     else {



     printf("\n\t\t\t\t\tTHE LIST OF ALL TRANSACTIONS");
     printf("\n\t\t\t\t\t-----------------------------\n");


     int len=0,s=0,t=0,y=0,big=0;




     for(i=0;i<k;i++)
     {
          len=0;
          t=strlen(jr[i].name);
          for(j=0;j<k;j++)
          {
               y=strlen(jr[j].name);
               if(t>y)
               {
                    len++;
               }
          }
          if(len==k-1)
          {
               big=t;
          }
     }


     char na[15];
     strcpy(na,"");
      if(big>4)
          {

               for(j=0;j<(big-4);j++)
               {
                 strcat(na," ");
               }

          }

 printf("\t\t\t\t\tID\tNAME%s\tTYPE         \tDATE    \tKILO\tUNITS\tSELLING PRICE\n",na);
     printf("\t\t\t\t\t................................................................................\n\n");


     for(i=0;i<k;i++)
     {
      if(0!=jr[i].id)
         {
              char c[14];


          s=strlen(jr[i].name);
          if(big!=s)
          {
               strcpy(c,"");

               for(j=0;j<(big-s);j++)
               {
                 strcat(c," ");
               }

         printf("\t\t\t\t\t%d\t%s%s\t%s\t%d/%d/%d\t%d Kg\t%d    \t%d\n",jr[i].id,jr[i].name,c,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx);





          }
          else{
               printf("\t\t\t\t\t%d\t%s\t%s\t%d/%d/%d\t%d Kg\t%d    \t%d\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx);
          }




          }
     }

     }
}

void namesort()
{
     for(i=0;i<k;i++)
     {
          for(j=i;j<k;j++)
          {
               if(0<strcmp(jr[i].name,jr[j].name))
               {

                    temp=jr[i];
                    jr[i]=jr[j];
                    jr[j]=temp;

               }
          }
     }
}

void found()
{


do{
     printf("\n\t\t\t\t\tPRESS:\n\t\t\t\t\t1.FIND USING ID\n\t\t\t\t\t2.FIND BY NAME\n\t\t\t\t\t3.EXIT\n\t\t\t\t\t");
     scanf("%d",&ch);
     if(ch==1)
     {

          useid();
     }
     else if(ch==2)
     {
         usename();
     }
     else if(ch==3)
     {

     }
     }while(ch!=3);
}

void useid()
{
     int tra;
     int count=0;
     printf("\n\t\t\t\t\tENTER THE TRANASCTION ID:");

     scanf("%d",&tra);

     for(i=0;i<k;i++)
     {
         if(jr[i].id==tra)
         {

          // printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
          // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
          // printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);
         //printf("\t\t\t\t\t%d\t%s\t%s\t%d/%d/%d\t%d Kg\t%d    \t%d\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx);

           printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);



         }
         else{
          count++;
         }
     }
     if(count==k)
     {
          printf("\n\t\t\t\t\t\aNOT FOUND!!\n");
     }
}


void usename()
{
     char name[45];
     int count=0;
     printf("\n\t\t\t\t\tENTER THE NAME:");
     scanf("%s",name);
     strupr(name);

     for(i=0;i<k;i++)
     {
         if(0==strcmp(jr[i].name,name))
         {
          // printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
          // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
          // printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);

           printf("\n\t\t\t\t\tNAME: %s\tID: %d\tDATE: %d/%d/%d\tSERVICE: %s",jr[i].name,jr[i].id,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);



         }
         else{
          count++;
         }
     }
     if(count==k)
     {
          printf("\n\t\t\t\t\t\aNOT FOUND!!\n");
     }
}


void remov()
{


do{
     printf("\n\t\t\t\t\tDELETING MENUE");
     printf("\n\t\t\t\t\tPRESS:\n");
     printf("\n\t\t\t\t\t1.DELETE USING ID");
    // printf("\n\t\t\t\t\t2.DELETE USING NAME");
     printf("\n\t\t\t\t\t2.SAVE CHANGES AND EXIT");

     scanf("%d",&ch);
     if(ch==1)
     {

        dele();
     }

     else if(ch==2)
     {
     jo=fopen("jour.txt","w");
               for(i=0;i<k;i++)
               {
                    if(jr[i].id!=0)
                    {

                         fprintf(jo,"%d\t%s\t\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%.2f\t%.2f\n",jr[i].id,jr[i].name,jr[i].type,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px,jr[i].tva,jr[i].proft);
                    }
               }
               fclose(jo);


     }
     }while(ch!=2);
}


void dele()
{
     int h;
     do{

         // printf("\n\t\t\t\t\tPRESS:\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t\n\t\t\t\t\t");

          printf("\n\t\t\t\t\tDELITE BY ID MENU");
          printf("\n\t\t\t\t\tPRESS:\n");
          printf("\n\t\t\t\t\t1.DELETE BY ENTERING AN ID");
          printf("\n\t\t\t\t\t2.DELETE BY ENTERING A RANGE OF IDs");
          printf("\n\t\t\t\t\t3.EXIT");


          scanf("%d",&h);
          if(h==1)
          {

          delid();

          }
          else if(h==2)
          {
               delids();
          }
          else if(h==3)
          {

          }
          }while(h!=3);

}

void delid()
{
     int tra;
     int count=0;
     printf("\n\t\t\t\t\tENTER THE TRANASCTION ID:");
     scanf("%d",&tra);

     for(i=0;i<k;i++)
     {
         if(jr[i].id==tra)
         {
          // printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
          // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
          // printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);

         printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);


         printf("\n\t\t\t\t\t\aARE SHURE!!!  PRESS1 TO CONFIRM AND ELSE WHERE TO LEAVE");
         int s;
         scanf("%d",&s);
         if(s==1)
         {
              jr[i]=rem;
         }



         }
         else{
          count++;
         }
     }
     if(count==k)
     {
          printf("\n\t\t\t\t\t\aNOT FOUND!!!\n");
     }
}


void delids()
{
     int tra,tr;
     int count=0;
     printf("\n\t\t\t\t\tENTER THE TRANASCTION ID RANGE:");

     printf("\n\t\t\t\t\tFROM:");
     scanf("%d",&tra);
     printf("\n\t\t\t\t\tTO  :");

     scanf("%d",&tr);
     int s;
     printf("\n\t\t\t\t\tMAKE SURE THAT THE ID STARTS FROM A SMALLER ID TO A HIGHER ID\n\t\t\t\t\t UNLES YOU WILL LOOSE YOUR DATA");
     printf("\n\t\t\t\t\t\aIF YOU ARE SURE!!!  PRESS1 TO CONFIRM AND ELSE WHERE TO LEAVE");
     scanf("%d",&s);
     if(s==1)
     {

          for(i=0;i<k;i++)
          {
               if(jr[i].id>=tra && jr[i].id<=tr)
               {

                    jr[i]=rem;
               }
               else {
                    count++;
               }

         }
         if(count==k)
         {
              printf("\n\t\t\t\t\t\aNOT FOUND!!\n");
         }
     }
}


void delname()
{
     int count=0;
     char name[45];
     printf("\n\t\t\t\t\tENTER THE NAME:");
     scanf("%s",name);
     strupr(name);

     for(i=0;i<k;i++)
     {
         if(0==strcmp(name,jr[i].name))
         {
        //   printf("\n\t\t\t\t\tID: %d\tNAME: %s\tDATE: %d/%d/%d\tSERVICE: %s\n\t\t\t\t\t-------------------------------------------------------------\n",jr[i].id,jr[i].name,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
          // printf("\n\n\t\t\t\t\tKILOS: %d kg,\t\t\tQUANTITY: %d\n\n\t\t\t\t\tSELLING PRICE: %d frw,\tCOST: %d frw",jr[i].kg,jr[i].qt,jr[i].selpx,jr[i].px);
           //printf("\n\n\t\t\t\t\tTVA: %.2f frw,\t\tPROFIT: %.2f frw\n\n\n",jr[i].tva,jr[i].proft);

           printf("\n\t\t\t\t\tNAME: %s\tID: %d\tDATE: %d/%d/%d\tSERVICE: %s",jr[i].name,jr[i].id,jr[i].d.day,jr[i].d.month,jr[i].d.year,jr[i].type);
           printf("\n\t\t\t\t\t---------------------------------------------------------------------");
             printf("\n\t\t\t\t\tKILOS            : %d kg",jr[i].kg);
           printf("\n\n\t\t\t\t\tNUMBER OF BOTTLES: %d Units",jr[i].qt);
           printf("\n\n\t\t\t\t\tSELLING PRICE    : %d Frw",jr[i].selpx);
           printf("\n\n\t\t\t\t\tCOST             : %d Frw",jr[i].px);
           printf("\n\n\t\t\t\t\tTVA              : %.2f Frw",jr[i].tva);
           printf("\n\n\t\t\t\t\tGROSS PROFIT     : %.2f Frw",jr[i].proft);
           printf("\n\n\t\t\t\t\tPROFIT           : %.2f Frw\n",jr[i].proft-jr[i].tva);

         int s;
         scanf("%d",&s);
         if(s==1)
         {
              jr[i]=rem;
         }

         }
         else {
          count++;
         }
     }
     if(count==k)
     {
          printf("\n\t\t\t\t\t\aNOT FOUND!!!!\n");
     }
}

void info()
{

      int m;
     do{
     printf("\n\t\t\t\t\t           *INFORMATION*");
     printf("\n\t\t\t\t\t**************************************");
     printf("\n\t\t\t\t\t*.............PRESS KEY..............*");
     printf("\n\t\t\t\t\t*.....(1)INSTRACTIONS................*");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*.....(2)ABOUT THE SOFTWARE..........*");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t*.....(3)MAIN MENUE..................*");
     printf("\n\t\t\t\t\t*....................................*");
     printf("\n\t\t\t\t\t**************************************\n\n\t\t\t\t\t");


          scanf("%d",&m);
          if(m==1)
          {
              how();
          }
          else if(m==2)
          {

               about();
          }
          else if(m==3)
          {

          }

          else{
               printf("\n\n\t\t\t\t\t!!!!!!\aCHOOSE BETWEEN 1 AND 4\a!!!!!!!\n\n");
          }
     }while(m!=3);





}


void how()
{
     printf("\n\t\t\t\t\t\t\tGAZ SHOP SOFT");
     printf("\n\t\t\t\t\t------------------------------------------------------------");
   printf("\n\n\t\t\t\t\t1.The first thing to do when you start using this software,");
     printf("\n\t\t\t\t\tgo to the manager control unity and define:");
     printf("\n\t\t\t\t\tThe Manager's name,password and products prices.");
     printf("\n\n\t\t\t\t\t2.Secondary,press 1 on the main menu to record.");
     printf("\n\n\t\t\t\t\t3.Third, thing you can do is to display transactions.");
     printf("\n\t\t\t\t\tby pressing 2, and inside there is a sub menu....");
     printf("\n\n\t\t\t\t\t4.Fourth, you can come back to the manager's control unity");
     printf("\n\t\t\t\t\tif you are the manager and redefine the previous information");
     printf("\n\t\t\t\t\tbut you can also choose other options like deleting.");
     printf("\n\n\t\t\t\t\t5.The last,now press 0 and know more about this soft ware");
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\tPRESS 1 TO CONTINUE");
     scanf("%d",&ch);
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\t  .               .");
     printf("\n\t\t\t\t\t .!.             .!.");
     printf("\n\t\t\t\t\t.....   WORNING ..... ");
     printf("\n\t\t\t\t\t---------------------------");
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\t1.IF YOU WANT TO EXIT FROM THE PROGRAM ");
     printf("\n\t\t\t\t\tFOLLOW THE KEEYS LEADING TO THE MAIN MENU");
     printf("\n\t\t\t\t\tAND THEN THERE CHOOSE KEEY 4 TO EXIT.");
     printf("\n\t\t\t\t\tDO NOT CLOSE THE SOFTWARE BY THE WINDOW CLOSING BOX ");
     printf("\n\t\t\t\t\tIF YOU DO IT THAT WAY THERE IS A RISK THAT YOU LOOSE YOUR DATA");
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\t2.DO NOT NEGLECT SOME INSTRACTIONS PROVIDED IN THE SOFTWARE,");
      printf("\n\t\t\t\t\t SUCH AS TO SAVE BY PRESSING A KEEY");
     printf("\n\t\t\t\t\tOR TO MAKE A CHOICE WITHIN A RANGE OF GIVEN NUMBERS.");
     printf("\n\t\t\t\t\t");
     printf("\n\t\t\t\t\t3.IF THE SOFTWARE COMES TO HAVE SOME TECHNICAL PROBLEMS ");
     printf("\n\t\t\t\t\tINFORM US THROUGH THE TELEPHONE OR EMAIL PROVIDED HERE.");
     printf("\n\t\t\t\t\tEMAIL:kayitarelie@gmail.com or iradupat@yahoo.fr\tTELE:+250789421906");
     printf("\n\t\t\t\t\t.......................THANK YOU VERY MUCH.........................\n");
}


void about()
{

     printf("\n\t\t\t\t\t...........................................................");
     printf("\n\t\t\t\t\t.                    GAZSHOP SOFT                         .");
     printf("\n\t\t\t\t\t.        GASABO,KIGALI,RWANDA. 11th APRIL 2018.           .");
     printf("\n\t\t\t\t\t.---------------------------------------------------------.");
     printf("\n\t\t\t\t\t.                                                         .");
     printf("\n\t\t\t\t\t.DEVELOPED BY: PATRICK IRADUKUNDA AND KAYITARE ELIE       .");
     printf("\n\t\t\t\t\t.JURIDICAL STATUS:NONE ( IT A CLASS WORK PROJECT)         .");
     printf("\n\t\t\t\t\t...................00001111000011110000....................\n");
}


void months(int a,char r[23])
{

     if(a==1)
     {
        strcpy(r,"January");
     }
     else if(a==2)
     {
         strcpy(r,"February");
     }
     else if(a==3)
     {
          strcpy(r,"March");
     }
     else if(a==4)
     {
          strcpy(r,"April");
     }
     else if(a==5)
     {
          strcpy(r,"May");
     }
     else if(a==6)
     {
          strcpy(r,"June");
     }
     else if(a==7)
     {
          strcpy(r,"July");
     }
     else if(a==8)
     {
          strcpy(r,"August");
     }
     else if(a==9)
     {
          strcpy(r,"September");
     }
     else if(a==10)
     {
          strcpy(r,"October");
     }
     else if(a==11)
     {
          strcpy(r,"November");
     }
     else if(a==12)
     {
          strcpy(r,"December");
     }
     //return(r);
}



