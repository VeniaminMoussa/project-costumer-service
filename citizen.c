#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
int command_citizen(const char* command, const int size)/*Clarify the command in citizen section*/
{
	int i;

	for(i=0;i<size-strlen("newCitizen");i++)
	{
		if(strncmp(command+i,"newCitizen",strlen("newCitizen"))==0)
			return 1;
	}
	for(i=0;i<size-strlen("serveCitizen");i++)
	{
		if(strncmp(command+i,"serveCitizen",strlen("serveCitizen"))==0)
			return 2;
	}
	for(i=0;i<size-strlen("removeCitizen");i++)
	{
		if(strncmp(command+i,"removeCitizen",strlen("removeCitizen"))==0)
			return 3;
	}
	for(i=0;i<size-strlen("exit");i++)
	{	

		if((strncmp(command+i,"exit",strlen("exit"))==0)||(strncmp(command+i,"EXIT",strlen("EXIT"))==0))
			return 4;
	}

	printf(KRED);
	printf("\n%69s\n","~Invalid Command~");
	printf(KNRM);
	return 0;
}
int check_newcitizen(char ***data,const int size_data, const int check)
{
	int n, i, j;
	char *str=NULL, *c=NULL;

	if((!size_data)&&(!check))
	{
		printf(KGRN);
		printf( "\n%35s\n","~The list is uploaded~");
		printf(KNRM);
		return 0;
	}

	if(size_data<9)
	{
		printf(KRED);
		printf("\n%69s\n","~Not enough datas~");
		printf(KNRM);
		return 0;
	}
	else if(size_data>9)
	{
		printf(KRED);
		printf("\n%72s\n","~Too many enough datas~");
		printf(KNRM);
		return 0;
	}

	str=strdup((*data)[0]);/*Changing the first name to its proper form*/

	for(i=0,n=strlen((*data)[0]);i<n;i++)
		(*data)[0][i]='\0';

	for(i=0,j=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			(*data)[0][j]=str[i];
			j++;
		}
		else
			continue;
	}

	free(str);

	if((strlen((*data)[0])==0)||(strlen((*data)[0])>21))
	{
		printf(KRED);
		printf("\n%76s\n","~Invalid Command in First Name~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=strlen((*data)[0]);i<n;i++)
	{
		if(i==0)
		{
			if(islower((*data)[0][i]))
			{
				(*data)[0][i]=toupper((*data)[0][i]);
				continue;
			}
		}
		else if(isupper((*data)[0][i]))
			(*data)[0][i]=tolower((*data)[0][i]);
	}

	str=strdup((*data)[1]);/*Changing the last name to its proper form*/

	for(i=0,n=strlen((*data)[1]);i<n;i++)
		(*data)[1][i]='\0';

	for(i=0,j=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			(*data)[1][j]=str[i];
			j++;
		}
		else
			continue;
	}

	free(str);

	if((strlen((*data)[1])==0)||(strlen((*data)[1])>21))
	{
		printf(KRED);
		printf("\n%76s\n","~Invalid Command in Last Name~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=strlen((*data)[1]);i<n;i++)
	{
		if(i==0)
		{
			if(islower((*data)[1][i]))
			{
				(*data)[1][i]=toupper((*data)[1][i]);
				continue;
			}
		}
		else if(isupper((*data)[1][i]))
			(*data)[1][i]=tolower((*data)[1][i]);
	}

	if(strlen((*data)[2])!=10)/*Checking the Birthday data*/
	{
		printf(KRED);
		printf("\n%75s\n","~Invalid Command in Birthday~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=strlen((*data)[2]);i<n;i++)
	{
		if((i==2)||(i==5))
		{
			if(((*data)[2][i])!='/')
			{
				printf(KRED);
				printf("\n%75s\n","~Invalid Command in Birthday~");
				printf(KNRM);
				return 0;
			}
			else
				continue;
		}

		if(isdigit((*data)[2][i])==0)
		{
			printf(KRED);
			printf("\n%75s\n","~Invalid Command in Birthday~");
			printf(KNRM);
			return 0;
		}
	}
	str=strdup((*data)[2]);
	c=strtok(str,"/");
	if((atoi(c)>31)||(atoi(c)<1))
	{
		printf(KRED);
		printf("\n%75s\n","~Invalid Command in Birthday~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,"/");
	if((atoi(c)>12)||(atoi(c)<1))
	{
		printf(KRED);
		printf("\n%75s\n","~Invalid Command in Birthday~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,"/");
	if((atoi(c)>1995)||(atoi(c)<1900))
	{
		printf(KRED);
		printf("\n%75s\n","~Invalid Command in Birthday~");
		printf(KNRM);
		free(str);
		return 0;
	}

	free(str);

	if(strlen((*data)[3])!=11)/*Checking if the number is correct*/
	{
		printf(KRED);
		printf("\n%74s\n","~Invalid Command in Number~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=0;i<strlen((*data)[3]);i++)
	{
		if(((*data)[3][i]=='-')&&(!n))
			n++;
		else if(((*data)[3][i]=='-')&&(n))
		{
			printf(KRED);
			printf("\n%74s\n","~Invalid Command in Number~");
			printf(KNRM);
			return 0;
		}
	}

	if((str=strchr((*data)[3],'-'))==NULL)
	{
		printf(KRED);
		printf("\n%74s\n","~Invalid Command in Number~");
		printf(KNRM);
		return 0;
	}
	else
	{
		if(((*data)[3][3]!=(*str))&&((*data)[3][4]!=(*str)))
		{
			printf(KRED);
			printf("\n%74s\n","~Invalid Command in Number~");
			printf(KNRM);
			return 0;
		}
	}

	for(i=0;i<strlen((*data)[3]);i++)
	{
		if((*data)[3][i]=='-')
			continue;

		if(!isdigit((*data)[3][i]))
		{
			printf(KRED);
			printf("\n%74s\n","~Invalid Command in Number~");
			printf(KNRM);
			return 0;
		}
	}

	for(i=0,n=0;i<strlen((*data)[4]);i++)/*Checking if the e-mail is correct*/
		if(isalnum((*data)[4][i]))
			n++;
	if(n<4)/*Checking if there are at least four numbers or alphas*/
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=0;i<strlen((*data)[4]);i++)/*Checking if there are exactly one '@'*/
		if((*data)[4][i]=='@')
			n++;
	if(n!=1)
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=0;i<strlen((*data)[4]);i++)/*Checking if there is at least one '.'*/
		if((*data)[4][i]=='.')
			n++;
	if(n<1)
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	if(isdigit((*data)[4][0]))/*Checking if the the e-mail beginns with a digit*/
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	n=strlen((*data)[4]);
	if((!isalpha((*data)[4][n-1]))||(!isalpha((*data)[4][n-2]))||((*data)[4][n-3]!='.'))/*Checking if the domain of the e-mail, consist from two alphas*/
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	if((strlen((*data)[4])==0)||(strlen((*data)[4])>26))
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in E-mail~");
		printf(KNRM);
		return 0;
	}

	for(i=0;i<strlen((*data)[5]);i++)/*Checking if the IP is correct*/
	{
		if(((*data)[5][i]==':')||((*data)[5][i]=='.'))
			continue;
		else
		{
			if(!isdigit((*data)[5][i]))
			{
				printf(KRED);
				printf("\n%72s\n","~Invalid Command in IP~");
				printf(KNRM);
				return 0;
			}
		}
	}

	for(i=0,n=0;i<strlen((*data)[5]);i++)/*Checking if the IP section is properly typed*/
	{
		if((*data)[5][i]=='.')
			n++;
		if((n==3)&&((*data)[5][i]==':'))
			break;
		else if((*data)[5][i]==':')
		{
			printf(KRED);
			printf("\n%72s\n","~Invalid Command in IP~");
			printf(KNRM);
			return 0;
		}
	}
	str=strdup((*data)[5]);
	c=strtok(str,".:");
	if((atoi(c)<0)||(atoi(c)>256))
	{
		printf(KRED);
		printf("\n%72s\n","~Invalid Command in IP~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,".:");
	if((atoi(c)<0)||(atoi(c)>256))
	{
		printf(KRED);
		printf("\n%72s\n","~Invalid Command in IP~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,".:");
	if((atoi(c)<0)||(atoi(c)>256))
	{
		printf(KRED);
		printf("\n%72s\n","~Invalid Command in IP~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,".:");
	if((atoi(c)<0)||(atoi(c)>256))
	{
		printf(KRED);
		printf("\n%72s\n","~Invalid Command in IP~");
		printf(KNRM);
		free(str);
		return 0;
	}

	c=strtok(NULL,".:");
	if((atoi(c)<0)||(atoi(c)>65535))
	{
		printf(KRED);
		printf("\n%73s\n","~Invalid Command in Port~");
		printf(KNRM);
		free(str);
		return 0;
	}

	free(str);

	if((strlen((*data)[6])==strlen("familyCert"))&&(strncmp((*data)[6],"familyCert",strlen((*data)[6]))==0));/*Checking if the Certificate is invalid*/
	else if((strlen((*data)[6])==strlen("birthCert"))&&(strncmp((*data)[6],"birthCert",strlen((*data)[6]))==0));
	else if((strlen((*data)[6])==strlen("debtCert"))&&(strncmp((*data)[6],"debtCert",strlen((*data)[6]))==0));
	else if((strlen((*data)[6])==strlen("residentCert"))&&(strncmp((*data)[6],"residentCert",strlen((*data)[6]))==0));
	else if((strlen((*data)[6])==strlen("electionCert"))&&(strncmp((*data)[6],"electionCert",strlen((*data)[6]))==0));
	else
	{
		printf(KRED);
		printf("\n%76s\n","~Invalid Command in Certificate~");
		printf(KNRM);
		return 0;
	}

	if(strlen((*data)[7])!=13)/*Checking the Birthday data*/
	{
		printf(KRED);
		printf("\n%78s\n","~Invalid Command in Exchange Number~");
		printf(KNRM);
		return 0;
	}

	for(i=0,n=strlen((*data)[7]);i<n;i++)
	{
		if((i==11)||(i==5))
		{
			if(((*data)[7][i])!='-')
			{
				printf(KRED);
				printf("\n%78s\n","~Invalid Command in Exchange Number~");
				printf(KNRM);
				return 0;
			}
			else
				continue;
		}

		if(isdigit((*data)[7][i])==0)
		{
			printf(KRED);
			printf("\n%78s\n","~Invalid Command in Exchange Number~");
			printf(KNRM);
			return 0;
		}
	}

	(*data)[7]=checksum(&(*data)[7]);/*Correcting the exchange number if it is invalid*/

	return 1;
}
int insert_citizen(char ***data, citizen **header,const time_t value, const int check)
{
	citizen *new, *currentPtr, *previousPtr;
	char *str=NULL;
	int n, i;

	new=(citizen*)malloc(sizeof(citizen));

	if (new!=NULL)
	{    /* is space available */

		new->tp=value;

		(new->first_name)=(char*)malloc(sizeof(char)*(strlen((*data)[0])+1));/*Creating the string of the first name*/

		if(new->first_name==NULL)
		{
			printf(KRED);
			printf("\n%70s\n","No Memory Available");
			printf(KNRM);
			exit(1);
		}

		strcpy(new->first_name,(*data)[0]);/*Storing the first name data*/

		(new->last_name)=(char*)malloc(sizeof(char)*(strlen((*data)[1])+1));/*Creating the string of the last name*/

		if(new->last_name==NULL)
		{
			printf(KRED);
			printf("\n%70s\n","No Memory Available");
			printf(KNRM);
			exit(1);
		}

		strcpy(new->last_name,(*data)[1]);/*Storing the last name data*/

		str=strtok((*data)[2],"/");/*Storing the birthday data*/

		new->birthday.day=atoi(str);

		str=strtok(NULL,"/");
		new->birthday.month=atoi(str);

		str=strtok(NULL,"/");
		new->birthday.year=atoi(str);

		(new->phone)=(char*)malloc(sizeof(char)*(strlen((*data)[3])+1));/*Creating the string of the phone*/

		if(new->phone==NULL)
		{
			printf(KRED);
			printf("\n%70s\n","No Memory Available");
			printf(KNRM);
			exit(1);
		}

		strcpy(new->phone,(*data)[3]);/*Storing the phone data*/

		(new->email)=(char*)malloc(sizeof(char)*(strlen((*data)[5])+1));/*Creating the string of the e-mail data*/

		if(new->email==NULL)
		{
			printf(KRED);
			printf("\n%70s\n","No Memory Available");
			printf(KNRM);
			exit(1);
		}

		strcpy(new->email,(*data)[4]);/*Storing the email data*/

		str=strtok((*data)[5], ":");
		strcpy(new->terminal.IP,(*data)[5]);/*Storing the IP data*/

		str=strtok(NULL, " .	:");
		new->terminal.port=atoi(str);

		(new->cert)=(char*)malloc(sizeof(char)*(strlen((*data)[6])+1));/*Creating the string of the Certificate data*/
		
		if(new->cert==NULL)
		{
			printf(KRED);
			printf("\n%70s\n","No Memory Available");
			printf(KNRM);
			exit(1);
		}

	
		strcpy(new->cert,(*data)[6]);/*Storing the certificate data*/

		(new->exchange)=(char*)malloc(sizeof(char)*(strlen((*data)[7])+1));/*Creating the string of the Certificate data*/
		
		if(new->exchange==NULL)
		{
			printf("\n%70s\n","No Memory Available");
			exit(1);
		}

		strcpy(new->exchange,(*data)[7]);/*Storing the certificate data*/

		new->next=NULL;

		previousPtr=NULL;
		currentPtr=(*header);

		while((currentPtr!=NULL)&&(value>currentPtr->tp))
		{
			previousPtr=currentPtr;         
			currentPtr=currentPtr->next;  
		}

		if(previousPtr==NULL)
		{ 
			new->next=(*header);
			(*header)=new;
		}
		else
		{
			previousPtr->next=new;
			new->next=currentPtr;
		}

		if(check)
		{
			printf(KGRN);
			printf( "\n%82s\n","~The citizen has been inserted on the list~");
			printf(KNRM);
			return 1;
		}
	}
	else
	{
		if(check)
		{
			printf(KRED);
			printf( "\n%89s\n","~The citizen hasn't been inserted. No memory available~");
			printf(KNRM);
			return 0;
		}
	}
}
citizen* removecitizen(citizen **header, char **command)
{
	char *c, *str=NULL, *date=NULL;
	int i, j, n, size;
	double value;
	citizen *tmp=NULL, *previous=NULL, *current=NULL;

	str=strdup(*command);
	c=strtok(str," ,	");
	n=1;
								
	while((c=strtok(NULL," ,	"))!=NULL)
		n++;

	if(n!=1)
	{
		printf(KRED);
		printf("\n%79s\n","~Invalide Command.Too many arguments~");
		printf(KNRM);
		return (*header);
	}

	free(str);

	str=strdup(*command);/*Changing the name to its proper form*/

	for(i=0,n=strlen(*command);i<n;i++)
		(*command)[i]='\0';

	for(i=0,j=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			(*command)[j]=str[i];
			j++;
		}
		else
			continue;
	}

	free(str);

	if(strlen(*command)==0)
	{
		printf(KRED);
		printf("\n%69s\n","~Invalid Command~");
		printf(KNRM);
		return (*header);
	}

	for(i=0,n=strlen((*command));i<n;i++)
	{
		if(isupper((*command)[i]))
			(*command)[i]=tolower((*command)[i]);
	}

	for(j=0,n=0,tmp=(*header);tmp!=NULL;n++)/*Checking if the given name is too large*/
	{
		if((strlen(tmp->last_name)-strlen((*command)))<0)
		{
			tmp=tmp->next;
			continue;
		}

		tmp=tmp->next;

		j++;
	}

	if(j>n)
	{
		printf(KRED);
		printf("\n%69s\n","~Too Large Name~");
		printf(KNRM);
		return (*header);
	}

	for(j=1,n=0,tmp=(*header);tmp!=NULL;)/*Printing the delete list*/
	{
		n=strlen(tmp->last_name)-strlen((*command));

		if(n<0)
		{
			tmp=tmp->next;
			continue;
		}

		str=strdup(tmp->last_name);

		str[0]=tolower(str[0]);

		for(i=0;i<(strlen(str)-strlen((*command))+1);i++)
		{
			if(strncmp(str+i,(*command),strlen((*command)))==0)
			{
				i=0;
				break;
			}
		}

		if(i)
		{
			tmp=tmp->next;
			continue;
		}

		free(str);

		if(j==1)
		{
			printf(BOLD);
			printf(KCYN);
			printf("\n%101s\n","~Remove From Citizen List~");
			printf(KNRM);
			printf(KCYN);
			printf( "\n%17s%21s%20s%20s%14s%26s%26s%24s%13s\n","First Name","Last Name","Birthday","Phone Number","E-mail","IP:Port","Certificate","Exchange Number","Date");
			printf(KNRM);
		}

		n=printf("%d.",j);
		n=(7-n);

		for(i=0;i<n;i++)
			printf(" ");

		n=printf("%s",tmp->first_name);

		n=(strlen("First Name")-n);

		for(i=0;i<(n+12);i++)
			printf(" ");

		n=printf("%s",tmp->last_name);

		n=(strlen("Last Name")-n);

		for(i=0;i<(n+12);i++)
			printf(" ");

		if(tmp->birthday.day<10)
			n=printf("0%d/",tmp->birthday.day);
		else
			n=printf("%d/",tmp->birthday.day);

		if(tmp->birthday.month<10)
			n+=printf("0%d/%d",tmp->birthday.month,tmp->birthday.year);
		else
			n+=printf("%d/%d",tmp->birthday.month,tmp->birthday.year);

		n=(strlen("Birthday")-n);

		for(i=0;i<(n+8);i++)
			printf(" ");

		n=printf("%s",tmp->phone);

		n=(strlen("Phone Number")-n);

		for(i=0;i<(n+8);i++)
			printf(" ");

		n=printf("%s",tmp->email);

		n=(strlen("E-mail")-n);

		for(i=0;i<(n+19);i++)
			printf(" ");

		n=printf("%s:%d",tmp->terminal.IP,tmp->terminal.port);

		n=(strlen("IP:Port")-n);

		for(i=0;i<(n+15);i++)
			printf(" ");

		n=printf("%s",tmp->cert);

		n=(strlen("Certificate")-n);

		for(i=0;i<(n+9);i++)
			printf(" ");

		n=printf("%s",tmp->exchange);

		n=(strlen("Exchange Number")-n);

		for(i=0;i<(n+9);i++)
			printf(" ");

		date=asctime(localtime(&(tmp->tp)));
		printf("%s\n",date);

		tmp=tmp->next;

		j++;
	}

	size=j-1;

	if(j==1)
	{
		printf(KRED);
		printf("\n%78s\n","~There is no such name on the List~");
		printf(KNRM);
		return (*header);
	}


	printf(KCYN);
	printf("Enter Choice [0=exit] ");
	printf(KBLU);
	printf(BOLD);
	printf("$>");
	printf(KNRM);
	scanf("%d",&n);
	while(getchar() != '\n');

	while((n<0)||(n>size))
	{
		printf(KCYN);
		printf(BOLD);
		printf("Try again entering a choice: ");
		printf(KBLU);
		printf("$>");
		printf(KNRM);
		scanf("%d",&n);
		while(getchar() != '\n');
	}

	if(n)
	{
		for(j=1,tmp=(*header);tmp!=NULL;)/*Finding the citizen on the list*/
		{
			i=strlen(tmp->last_name)-strlen((*command));

			if(i<0)
			{
				tmp=tmp->next;
				continue;
			}

			str=strdup(tmp->last_name);

			str[0]=tolower(str[0]);

			for(i=0;i<(strlen(str)-strlen((*command))+1);i++)
			{
				if(strncmp(str+i,(*command),strlen((*command)))==0)
				{
					i=0;
					break;
				}
			}

			if(i)
			{
				tmp=tmp->next;
				free(str);
				continue;
			}

			free(str);

			if(j==n)
			{
				value=tmp->tp;
				break;
			}
		
			tmp=tmp->next;

			j++;
		}

		if(value==(*header)->tp)/*removing a client from the list*/
		{ 
			tmp=*header;
			*header=(*header)->next;

			str=tmp->first_name;
			free(str);

			str=tmp->last_name;
			free(str);

			str=tmp->phone;
			free(str);

			str=tmp->email;
			free(str);

			str=tmp->cert;
			free(str);

			str=tmp->exchange;
			free(str);

			free(tmp);

			tmp=NULL;

			printf(KGRN);
			printf("\n%73s\n","~Citizen Has Been Removed~");
			printf(KNRM);            
			return (*header);
		}
		else
		{
			previous=*header;
			current=(*header)->next;

			while((current!=NULL)&&(current->tp!=value))
			{ 
				previous=current;
				current=current->next; 
			}

			if(current!=NULL)
			{
				tmp=current;
				previous->next=current->next;
		
				str=tmp->first_name;
				free(str);

				str=tmp->last_name;
				free(str);

				str=tmp->phone;
				free(str);

				str=tmp->email;
				free(str);

				str=tmp->cert;
				free(str);

				str=tmp->exchange;
				free(str);

				free(tmp);

				tmp=NULL;

				printf(KGRN);
				printf("\n%73s\n","~Citizen Has Been Removed~");
				printf(KNRM);

				return (*header);
			}                                                        
		}
	}
	else
		return (*header);
}
citizen* servecitizen(citizen **header)
{
	char *str=NULL;
	citizen *delete;

	if((*header)==NULL)
	{
		printf(KRED);
		printf("\n%70s\n","~The list is empty~");
		printf(KNRM);

		return NULL;
	}
	else
	{
		delete=(*header);
		(*header)=(*header)->next;
		
		str=delete->first_name;
		free(str);

		str=delete->last_name;
		free(str);

		str=delete->phone;
		free(str);

		str=delete->email;
		free(str);

		str=delete->cert;
		free(str);

		str=delete->exchange;
		free(str);

		free(delete);

		delete=NULL;

		printf(KGRN);
		printf("\n%73s\n","~Citizen Has Been Served~");
		printf(KNRM);

		return (*header);	

	}
}
char* checksum(char **exchange)
{
	char *str=NULL;
	int n, sum, check, i;

	str=(*exchange);

	for(sum=0,i=0;i<strlen(str);i++)
	{
		if((i==5)&&(i==11))
			continue;

		if(i==12)
		{
			sum+=str[i]-'0';
			continue;
		}

		sum+=str[i]-'0';

		if(((i+1)==5)||((i+1)==11))
			i++;

		check=str[++i]-'0';

		check*=2;
		if(check>9)
			check=(check/10)+(check%10);
		sum+=check;
	}

	if(!(sum%10))
		return str;
	else
	{
		for(sum=0,i=0;i<strlen(str);i++)
		{
			if((i==5)||(i==11))
				continue;

			if(i==12)
			{
				str[i]=(sum*9)%10+'0';
				continue;
			}

			n=rand()%('9'-'0'+1)+'0';

			str[i]=n;
			sum+=str[i]-'0';

			if(((i+1)==5)||((i+1)==11))
				i++;

			if(i==11)
				continue;

			n=rand()%('9'-'0'+1)+'0';

			str[++i]=n;

			check=str[i]-'0';

			check*=2;
			if(check>9)
				check=(check/10)+(check%10);
			sum+=check;
		}
	}
	return str;
}
