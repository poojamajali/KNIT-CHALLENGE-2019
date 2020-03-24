/*****  KNIT CHALLENGE 2019 *****/
/**
    MEMBER 1: POOJA MAJALI
    MEMBER 2: PRIYA MAJALI
    3RD SEMESTER,COMPUTER SCIENCE
    DATE: 10/8/2019
**/


/**HEADER FILES**/
#include <stdio.h>
#include <stdlib.h> // For exit()
#include<string.h>
#define MAX 10000

/**STRUCTURE TO STORE THE OUTPUT OF KEYWORD**/
struct node
{
    char id[10];
    char output[1000];
    int no;

};

/**STRUCTURE USED TO STORE THE LAST SEARCHED KEYWORDS**/
struct trend
{
    char t[1000];
};

/**STRUCTURE DECLARATION**/
struct trend tren[MAX];
struct node k[100];
/**GLOBAL DECLARATIONS**/
FILE *fp,*fptr;
char d[1000],keyword[1000];
char start,c;
char endd[10]="-*-*-*-";
int a,count=0,found=0,tempp=1,source=0,disp=0;
int mat[100][100]={0};
int visited1[100]={0};

/**SEARCH FUNCTION TO SEARCH THE SPECIFICATION OF THE PRODUCT DISPLAYED**/
void search(char s[1000],int i)
{
     fp=fopen("input.txt","r");
     char pname[1000],id[10];
     strcpy(id,k[i].id);
     int flag=0;

        do{
             flag=0;
             c=fscanf(fp,"%s",d);
             while(1)
             {
                 a=strcasecmp(d,endd);
                 if(a==0)
                 break;

                 a=strcasecmp(s,d);
                 if(a==0)
                    {
                        c=fscanf(fp,"%s",pname);
                    }

                 a=strcasecmp(d,id);
                 if(a==0)
                 {
                    flag=1;

                 }

                c=fscanf(fp,"%s",d);
             }
             if(flag==1)
                {
                    printf("\n%s\n",pname);
                    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
                    break;
                }

        }while(c!= EOF);

fclose(fp);

if(flag==0)
    printf("\nNOT FOUND");

}


/**FUNCTION TO DISPLAY ALL INFORMATION ABOUT THAT PRODUCT**/
void displayall(int i)
{
     printf("\nID=%s\n",k[i].id);

     fp=fopen("input.txt","r");
     char z[1000],s1;
     int flag=0;
int co;
if(disp++==0)
    co=1;
else co=0;

     do{
            fptr=fopen("storedata.txt","w");
            flag=0;
            c=fscanf(fp,"%s",d);
            co++;
            s1=fprintf(fptr,"%s ",d);
            if(co==2)
                {
                    s1=fprintf(fptr,"\n");
                    co=0;
                }
            while(1)
            {
                a=strcasecmp(d,endd);
                if(a==0)
                break;

                a=strcasecmp(d,k[i].id);
                if(a==0)
                {
                    flag=1;
                }
                c=fscanf(fp,"%s",d);
                co++;
                s1=fprintf(fptr,"%s ",d);
                if(co==2)
                {
                    s1=fprintf(fptr,"\n");
                    co=0;
                }
            }
            fclose(fptr);
            if(flag==1)
            {

                fptr=fopen("storedata.txt","r");
                s1=fscanf(fptr,"%s",d);
                printf("%s ",d);
                while(s1 != '*')
                {
                    s1=fgetc(fptr);
                    printf("%c",s1);
                }
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
                break;
            }

}while(c != EOF);
fclose(fp);
fclose(fptr);
}


/**FUNCTION TO STORE DATA IN A TEXT FILE TO DISPLAY SPECIFIC INFORMATION**/
void storedata(int i)
{
    fp=fopen("input.txt","r");
     char z[1000],s1;
     int flag=0;
int co;
if(disp++==0)
    co=1;
else co=0;

     do{
            fptr=fopen("storedata.txt","w");
            flag=0;
            c=fscanf(fp,"%s",d);
            co++;
            s1=fprintf(fptr,"%s ",d);
            if(co==2)
                {
                    s1=fprintf(fptr,"\n");
                    co=0;
                }
            while(1)
            {
                a=strcasecmp(d,endd);
                if(a==0)
                break;

                a=strcasecmp(d,k[i].id);
                if(a==0)
                {
                    flag=1;
                }
                c=fscanf(fp,"%s",d);
                co++;
                s1=fprintf(fptr,"%s ",d);
                if(co==2)
                {
                    s1=fprintf(fptr,"\n");
                    co=0;
                }
            }
            fclose(fptr);
            if(flag==1)
            {
                break;
            }

}while(c != EOF);
fclose(fp);
}


/**THIS FUNCTION GIVES VARIOUS DISPLAY CHOICES FOR THE GIVEN PRODUCT**/
int displayinfo(int i)
{
    int ch,t=0;
char tem[1000];

    printf("\nPRODUCT NUMBER: %d\n",tempp++);

    printf("\nFOR THIS PRODUCT YOU WANT TO DISPLAY :");
    printf("\n1 : PRODUCT NAME \n2 : DOMAIN \n3 : ID\n4 : ALL SPECIFICATIONS AVAILABLE\n5 : SPECIFICATION OF YOUR CHOICE\n6 : EXIT\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:search("product-name",i);
                break;
        case 2:search("domain",i);
                break;
        case 3: printf("\nID=%s\n",k[i].id);
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
                break;
        case 4:displayall(i);
                break;
        case 5: printf("\nENTER SPECIFICATION :");
                storedata(i);
                fp=fopen("storedata.txt","r");
                char cha;
                scanf("%s",tem);
                cha=fscanf(fp,"%s",d);
                while(cha!=EOF)
                {
                    a=strcasecmp(d,tem);
                    if(a==0)
                    {
                        cha=fscanf(fp,"%s",d);
                        printf(" %s %s ",tem,d);
                        t=1;
                        break;

                    }
                    cha=fscanf(fp,"%s",d);
                }
                if(t==0)
                    printf("\nNOT FOUND");
                fclose(fp);
                printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
                break;
        case 6: break;

    }

return 0;
}

/**FUNCTION TO DISPLAY THE AVAILABLE CHOICES OF SPECIFICATIONS**/
void dsome(int mat[100][100],int count,int source)
{

int i;

        visited1[source]=1;
        for(i=0;i<count;i++)
        {
                if(mat[source][i]==1 && visited1[i]==0)
            {
                dsome(mat,count,i);
            }
        }
}

/**FUNCTION DISPLAYS ALL THE PRODUCTS OF THE SPECIFICATION SELECTED**/
void dfs(int mat[100][100],int count,int source)
{

int i;

        visited1[source]=1;
        for(i=0;i<count;i++)
        {
                if(mat[source][i]==1 && visited1[i]==0)
            {
                displayinfo(i);
                dfs(mat,count,i);
            }
        }
}

/**READS THE ENTIRE INPUT FILE AND SEARCHES THE KEYWORD ENTERED AND STORES THE OUTPUT**/
void read()
{
    fp=fopen("input.txt","r");
    int flag;
        char id[10];
   int p=0;
        do{
        flag=0;
        start=fscanf(fp,"%s",d);
        c=start;
        while(1)
        {
            a=strcasecmp(d,endd);
            if(a==0)
            break;
            a=strcasecmp(d,"id");
            if(a==0)
            {
                c=fscanf(fp,"%s",id);
            }
            a=strcasecmp(d,keyword);
            if(a==0)
            {
                found=1;
                c=fscanf(fp,"%s",d);
                strcpy(k[p].output,d);

                flag=1;

            }
             c=fscanf(fp,"%s",d);
        }

        if(flag==1)
        {
             strcpy(k[p++].id,id);
             count++;
        }
}while(start!= EOF);

fclose(fp);

}
/**ASSIGN NUMBER FOR EACH OUTPUT**/
void assign_number()
{
    for(int i=0;i<count;i++)
    {
        k[i].no=i;
    }
}


/**COMPARES IF OUTPUT AND SIMILAR AND HENCE CREATES A MATRIX **/
void compare()
{
    for(int i=0;i<count;i++)
    {
     for(int j=0;j<count;j++)
            {
                if(i==j)
                {

                }
                else
                {
                    a=strcasecmp(k[i].output,k[j].output);
                    if(a==0)
                    {
                        mat[i][j]=1;
                        mat[j][i]=1;
                    }
                }
            }
    }
}


/**FUNCTION TO OUTPUT THE MOST SEARCHED WORD OF THE SEARCH ENGINE**/
void trendin()
{
        FILE *f;
        int L=0,cou=0;

        f=fopen("trending.txt","r+");
        c=fscanf(f,"%s",tren[L++].t);
        if(c==EOF)
            printf("\nNO SEARCHES YET. THIS IS THE 1 ST SEARCH...\n ");

        else
        {
            while(c!=EOF)
            {
                c=fscanf(f,"%s",tren[L++].t);
                cou++;
            }

         fclose(f);

        int C=-1;
        int in=2;

         int visi[MAX]={0};
        for(int i=0;i<cou;i++)
        {
            int c=1;
            for(int j=0;j<cou;j++)
            {
                if(i==j)
                {}
                else
                {
                    a=strcasecmp(tren[i].t,tren[j].t);
                    if(a==0)
                    {
                        if(visi[i]==0 || visi[j]==0)
                        {
                            c++;
                            visi[i]=1;
                            visi[j]=1;
                        }
                    }
                }
            }
            if(c>C)
            {
                C=c;
                in=i;
            }
        }
        printf("\nMOST SEARCHED KEYWORD =  %s",tren[in].t);
        printf("\nNUMBER OF TIMES: %d\n",C);

    }
}


/**MAIN FUNCTION TO CALL OTHER FUNCTIONS**/
int main()
{

printf("\t\t\t\t\t*********************************");
printf("\n\t\t\t\t\t\tKNIT CHALLENGE-2019");
printf("\n\t\t\t\t\t*********************************");
printf("\n\t\t\t\t\t   WELCOME TO KNIT SEARCH ENGINE");
printf("\n\t\t\t\t\t*********************************");
 int m;
do{

        trendin();
        FILE *f;
         f=fopen("trending.txt","a+");
         printf("\nENTER YOUR KEYWORD : ");
         scanf("%s",keyword);
         count=0;
           int i=0;
            a=strcasecmp(keyword,"id");
            if(a==0)
            {
                found=1;
                fp=fopen("input.txt","r");
                c=fscanf(fp,"%s",d);
                while(c != EOF)
                {
                    a=strcasecmp(d,"id");
                    if(a==0)
                    {
                         c=fscanf(fp,"%s",d);
                         strcpy(k[i].id,d);
                         strcpy(k[i++].output,d);
                         count++;
                    }
                    c=fscanf(fp,"%s",d);
                }
                fclose(fp);

            }
            else
            {
                read();
            }


        //read();





        if(found==0)
        {
            printf("\nKEYWORD DOESN'T EXIST...\n");

        }
        else
        {
            fprintf(f,"%s\n",keyword);


        fclose(f);
        assign_number();
        compare();

        printf("\nINDEX\tSPECIFICATION\n");



        printf("\n %d ->\t%s",k[source].no,k[source].output);
        dsome(mat,count,source);
        for(int i=0;i<count;i++)
        {
            if(visited1[i]==0)
            {
                printf("\n %d ->\t%s",k[i].no,k[i].output);
                dsome(mat,count,i);
            }
        }
        printf("\n");

        printf("\nEnter Index Number Of Your Choice Of Specification : ");
        int choice;
        scanf("%d",&choice);

        printf("\nFOR THE GIVEN SPECIFICATION, PRODUCTS ARE: \n");
        displayinfo(choice);
        for(int i=0;i<count;i++)
            visited1[i]=0;
        dfs(mat,count,choice);
        }

        printf("\t\tTHE END");

        printf("\nWANT TO SEARCH OTHER KEYWORD? \n\t0 -> YES 1 -> NO \n");
        scanf("%d",&m);

    }while(m != 1);

    if(m==1)
    {
        printf("\nTHANK YOU!");
    }


	return 0;
}





