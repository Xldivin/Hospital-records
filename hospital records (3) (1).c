#include<stdio.h>
#include<string.h>
struct registration
{
    int id;
    char fname[20];
    char lname[20];
    char gender[20];
    char address[20];
    char insurance[20];
    char service[20];
    int age;
} pa;

void new_patient(void)
{
    FILE*p;
    p=fopen("patientrecord.txt","a");
    printf("\n\t Enter ID:");
    scanf("%d",&pa.id);

    printf("\n\t Enter First Name:");
    scanf("%s",&pa.fname);

    printf("\n\t Enter Last Name:");
    scanf("%s",&pa.lname);

    printf("\n\t Enter Gender:");
    scanf("%s",&pa.gender);

    printf("\n\t Enter Address:");
    scanf("%s",&pa.address);

    printf("\n\t Enter Insurance Type:");
    scanf("%s",&pa.insurance);

    printf("\n\t Enter Service To Be Rendered:");
    scanf("%s",&pa.service);

    printf("\n\t Enter Age Of Patient:");
    scanf("%d",&pa.age);




    fprintf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n\n",pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,pa.age);

    printf("REGISTERED SUCCESSFULL\n");


    fclose(p);
    int reset;
    printf("Press Any Number to Return To Main Menu/...");
    scanf("%d",&reset);
    main(reset);
}
void displaypatient(void)
{
    FILE*p;
    p=fopen("patientrecord.txt","r");
    printf("\t\t\t\t\t LIST OF ALL PATIENTS\n");
    printf("\t\t\t\t\t---------------------\n\n");

    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",&pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,&pa.age);
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,pa.age);
    }

    fclose(p);

    int reset;
    printf("Press Any Number to Return To Main Menu:...");
    scanf("%d",&reset);
    main(reset);
}
void patientsearch(void)
{
    int sea;
    FILE*p;
    p=fopen("patientrecord.txt","r");
    printf("\t\n\t\tEnter PATIENT  ID:");
    scanf("%d",&sea);
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",&pa.id,&pa.fname,&pa.lname,&pa.gender,&pa.address,&pa.insurance,&pa.service,&pa.age);
        if(pa.id==sea)
        {
            printf("\n\n\t\tTHE PATIENT FOUND\n");
            printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,pa.age);
        }
    }
     fclose(p);
     if(sea!=pa.id)
        {
            printf("\n\n\tNO PATIENT WITH THAT ID:%d \n",sea);
        }

    int reset;
    printf("Press Any Number to Return To Main Menu:...");
    scanf("%d",&reset);
    main(reset);
}
void patientdelete(void)
{
    struct registration dis;
    FILE*p;
    FILE*e;
    p=fopen("patientrecord.txt","r");
    printf("ENTER ID OF PATIENT TO DELETE \n");
    int id;
    int flag=0;
    scanf("%d",&id);
    e=fopen("delete.txt","w");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",&pa.id,&pa.fname,&pa.lname,pa.gender,&pa.address,&pa.insurance,&pa.service,&pa.age);
        if(pa.id!=id)
        {
            fprintf(e,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,pa.age);

        }
        else
        {
            flag=1;
        }
    }
    fclose(p);
    fclose(e);
    if(flag==1)
    {
        e=fopen("delete.txt","r");
        p=fopen("patientrecord.txt","w");

        while(!feof(e))
        {
            fscanf(e,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",&pa.id,&pa.fname,&pa.lname,&pa.gender,&pa.address,&pa.insurance,&pa.service,&pa.age);
            fprintf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",pa.id,pa.fname,pa.lname,pa.gender,pa.address,pa.insurance,pa.service,pa.age);

        }
        fclose(p);
        fclose(e);


        printf("\t\t\tDELETED SUCCESSFULL\n\n");

    }
    else if(flag==0)
    {
        printf("NOT FOUND!\n");
    }

    int reset;
    printf("Press Any Number to Return To Main Menu:...");
    scanf("%d",&reset);
    main(reset);
}

void patientsort(void)
{
    FILE *p;
    int s=0,x,y,go,end;
    struct registration re[80],swap;
    p=fopen("patientrecord.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",&re[s].id,re[s].fname,re[s].lname,re[s].gender,re[s].address,re[s].insurance,re[s].service,&re[s].age);
        s++;
    }
    if(s==0)
    {
        printf("FILE FOUND EMPTY");
    }
    else
    {
        for(x=0;x<s-1;x++)
        {
            go=re[x].id;
            end=x;
            for(y=x+1;y<s;y++)
            {
                if(re[y].id<go)
                {
                    go=re[y].id;
                    end=y;
                }
            }
            swap=re[x];
            re[x]=re[end];
            re[end]=swap;
        }
        for(x=0;x<s;x++)
        {
            printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",re[x].id,re[x].fname,re[x].lname,re[x].gender,re[x].address,re[x].insurance,re[x].service,re[x].age);
        }
    }
    fclose(p);
    int reset;
    printf("Press Any Number to Return To Main Menu:...");
    scanf("%d",&reset);
    main(reset);
}
main()
{
    int z;
    do
   {
        printf("\n\n\n\n\n\n\n\n\n\n\n");

        printf("\t\t\t\t                                        \n");
        printf("\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM   \n");
        printf("\t\t\t\t________________________________________\n");
        printf("\t\t\t\t                                        \n");
        printf("\t\t\t\t  PRESS 1.ENTER NEW PATIENT INFORMATION \n");
        printf("\t\t\t\t  PRESS 2.DISPLAY ALL PATIENTS          \n");
        printf("\t\t\t\t  PRESS 3.SEARCH PATIENT INFORMATION    \n");
        printf("\t\t\t\t  PRESS 4.DELETE PATIENT BY ID          \n");
        printf("\t\t\t\t  PRESS 5.SORT PATIENTS INFORMATION    \n");
        printf("\t\t\t\t  PRESS 0.EXIT                          \n");
        printf("\t\t\t\t________________________________________\n");

        printf("\t\t\t\t PRESS ANY NUMBER FROM ABOVE:..");
        scanf("%d",&z);

         switch(z)
        {
        case 1:
            new_patient();
            break;
        case 2:
            displaypatient();
            break;
        case 3:
            patientsearch();
            break;
        case 4:
            patientdelete();
            break;
        case 5:
            patientsort();
            break;
        case 0:
            printf("\n\n\n\n\n\t\t\t\tTHANK YOU TO USE OUR SYSTEM!!!\n");
        default:
            printf("\n\n\n\n\n\t\t\t\tWRONG CHOICE");

             }
       }while(z=0);
    }

