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
   
    scanf("%d",&choice);
   
    return choice;
}

void process()
{
    switch(choice)
        {
        	case 1:
        	{
	            printf("Enter file name -1 for menu\n");
	            scanf("%s",file_name);
	            if(atoi(file_name)==-1)
	            	break;
	           
	            fp1=fopen(file_name,"w");

	            printf("Enter data into the file Press Cltr+D to stop\n");

	            while((c=getchar())!=EOF)
	            fprintf(fp1,"%c",c);

	        	fclose(fp1);
	        }break;
        
        case 2:
        	{
	            fp1=fopen(file_name,"r");
	            	
		    	printf("\nThe files are\n");
	            int check=system("ls");

	            if(check==0) //if ANY files are found ls returns 0 else 512 idk why :)
	            {
	                printf("\nEnter file name to open -1 for menu\n");
	                
	                read:
	                scanf("%s",file_name);
	                if(atoi(file_name)==-1)
	            	break;

	                fp1=fopen(file_name,"r");

	                if(fp1==NULL)
	                {
	                    printf("\nFile not found\n");
	                    goto read;
	                }
	                else
	                {
	                    printf("\nFile found. Contents are:\n");

	                    while((c=getc(fp1))!=-1)
	                    fprintf(stdout,"%c",c);

	                }
	            }
	            else
	            printf("\nNo files found of that type\n");

	        	fclose(fp1);
        	
        	}
        	break;

        case 3:
        system("ls");
        break;

        case 4:
        {
            printf("\nThe files are\n");
            system("ls");
            printf("\nEnter the file you wish to delete -1 for menu\n");
            
            del:
            scanf("%s",file_name);
            if(atoi(file_name)==-1)
	            	break;
           
            if(remove(file_name)==0)
            	printf("Deleted successfuly\n");
            else
            {
            	printf("File not found.Try again\n");
            	goto del;
            }
        }
        	break;

        case 5:
        exit(0);

        default:
        printf("Enter a correct choice\n");
        menu();
    }
       
}
