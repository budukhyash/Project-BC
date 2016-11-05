
int choice;
FILE *fp1;
char c;
char file_name[30];

int menu()
{

    printf("\n1--Make a new file\n");
    printf("2--Open an existing file\n");
    printf("3--To view the files\n");
    printf("4--To delete a file\n");
    printf("5--Exit\n");

    printf("\nEnter your choice \n");
    scanf("%d",&choice);

    return choice;
}

void process()
{
        if(choice==1)
        {
            printf("Enter file name\n");
            scanf("%s",file_name);
            fp1=fopen(file_name,"w");

            printf("Enter data into the file\n");
            printf("Press Cltr+D to stop\n");

            while((c=getchar())!=-1)
            fprintf(fp1,"%c",c);

        	fclose(fp1);
        }
        else if(choice==2)
        {
            fp1=fopen(file_name,"r");
            	
	    	
            printf("The files are\n");
            int check=system("ls");

            if(check==0)
            {
                printf("Enter file name--\n");
                read:
                scanf("%s",file_name);
                fp1=fopen(file_name,"r");

                if(fp1==NULL)
                {
                    printf("File not found\n");
                    goto read;
                }
                else
                {
                    printf("File found\n");

                    while((c=getc(fp1))!=-1)
                    fprintf(stdout,"%c",c);

                }
            }
            else
            printf("No files found of that type\n");

        	fclose(fp1);
        }

        else if(choice==3)
        system("ls");

        else if(choice==4)
        {
            printf("The files are\n");
            system("ls");
            printf("Enter the file you wish to delete\n");
            del:
            scanf("%s",file_name);
            if((remove(file_name))==0)
            printf("Deleted Successfully\n");
            else
            {
                printf("File not found.Try again\n");
                goto del;
            }

        }
}
