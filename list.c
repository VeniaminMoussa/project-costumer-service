#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include"header.h"
int command_list(const char* command, const int size)/*Clarify the command in list section*/
{
	int i;

	for(i=0;i<size-strlen("printRev");i++)
	{
		if(strncmp(command+i,"printRev",strlen("printRev"))==0)
			return 2;
	}
	for(i=0;i<size-strlen("print");i++)
	{
		if(strncmp(command+i,"print",strlen("print"))==0)
			return 1;
	}
	for(i=0;i<size-strlen("exit");i++)
	{	

		if((strncmp(command+i,"exit",strlen("exit"))==0)||(strncmp(command+i,"EXIT",strlen("EXIT"))==0))
			return 3;
	}

	printf(KRED);
	printf("\n%53s\n","~Invalid Command~");
	printf(KNRM);
	return 0;
}
void printlist(citizen *header, char **data,const int size_data)
{
	char *date=NULL;
	int i, j, n, check;
	citizen *tmp;

	if(size_data==2)
	{

		if ((header)==NULL)
		{
			printf(KRED);
			printf("\n%54s\n","~The list is empty~");
			printf(KNRM);
			return;
		}
		else
		{
			if(strncmp(data[1],"*",strlen("*"))==0)
			{
				printf(BOLD);
				printf(KCYN);
				printf("\n%94s\n","~Citizen List~");
				printf(KNRM);
				printf(KCYN);
				printf( "\n%17s%21s%20s%20s%14s%26s%26s%24s%13s\n","First Name","Last Name","Birthday","Phone Number","E-mail","IP:Port","Certificate","Exchange Number","Date");
				printf(KNRM);

				for(j=1,n=0;header!=NULL;j++)/*Printing all the list*/
				{
					n=printf("%d.",j);
					n=(7-n);

					for(i=0;i<n;i++)
						printf(" ");

					n=printf("%s",header->first_name);

					n=(strlen("First Name")-n);

					for(i=0;i<(n+12);i++)
						printf(" ");

					n=printf("%s",header->last_name);

					n=(strlen("Last Name")-n);

					for(i=0;i<(n+12);i++)
						printf(" ");

					if(header->birthday.day<10)
						n=printf("0%d/",header->birthday.day);
					else
						n=printf("%d/",header->birthday.day);

					if(header->birthday.month<10)
						n+=printf("0%d/%d",header->birthday.month,header->birthday.year);
					else
						n+=printf("%d/%d",header->birthday.month,header->birthday.year);

					n=(strlen("Birthday")-n);

					for(i=0;i<(n+8);i++)
						printf(" ");

					n=printf("%s",header->phone);

					n=(strlen("Phone Number")-n);

					for(i=0;i<(n+8);i++)
						printf(" ");

					n=printf("%s",header->email);

					n=(strlen("E-mail")-n);

					for(i=0;i<(n+19);i++)
						printf(" ");

					n=printf("%s:%d",header->terminal.IP,header->terminal.port);

					n=(strlen("IP:Port")-n);

					for(i=0;i<(n+15);i++)
						printf(" ");

					n=printf("%s",header->cert);

					n=(strlen("Certificate")-n);

					for(i=0;i<(n+9);i++)
						printf(" ");

					n=printf("%s",header->exchange);

					n=(strlen("Exchange Number")-n);

					for(i=0;i<(n+9);i++)
						printf(" ");

					date=asctime(localtime(&(header->tp)));
					printf("%s\n",date);

					header=header->next;
				}

				return;
			}
			else
			{
				check=0;
				tmp=header;
				while(tmp!=NULL)
				{
					if(strncmp(data[1],tmp->cert,strlen(data[1]))==0)
						check++;
				
					tmp=tmp->next;
				}

				if(check)
				{
					printf(BOLD);
					printf(KCYN);
					printf("\n%89s%s~\n","~Citizen List ",data[1]);
					printf(KNRM);
					printf(KCYN);
					printf( "\n%17s%21s%20s%20s%14s%26s%26s%24s%13s\n","First Name","Last Name","Birthday","Phone Number","E-mail","IP:Port","Certificate","Exchange Number","Date");
					printf(KNRM);

				
					for(j=1,n=0;header!=NULL;)/*Printing all the list*/
					{
						if(strncmp(data[1],header->cert,strlen(data[1]))!=0)
						{
							header=header->next;
							continue;
						}

						n=printf("%d.",j);
						n=(7-n);

						for(i=0;i<n;i++)
							printf(" ");

						n=printf("%s",header->first_name);

						n=(strlen("First Name")-n);

						for(i=0;i<(n+12);i++)
							printf(" ");

						n=printf("%s",header->last_name);

						n=(strlen("Last Name")-n);

						for(i=0;i<(n+12);i++)
							printf(" ");

						if(header->birthday.day<10)
							n=printf("0%d/",header->birthday.day);
						else
							n=printf("%d/",header->birthday.day);

						if(header->birthday.month<10)
							n+=printf("0%d/%d",header->birthday.month,header->birthday.year);
						else
							n+=printf("%d/%d",header->birthday.month,header->birthday.year);

						n=(strlen("Birthday")-n);

						for(i=0;i<(n+8);i++)
							printf(" ");

						n=printf("%s",header->phone);

						n=(strlen("Phone Number")-n);

						for(i=0;i<(n+8);i++)
							printf(" ");

						n=printf("%s",header->email);

						n=(strlen("E-mail")-n);

						for(i=0;i<(n+19);i++)
							printf(" ");

						n=printf("%s:%d",header->terminal.IP,header->terminal.port);

						n=(strlen("IP:Port")-n);

						for(i=0;i<(n+15);i++)
							printf(" ");

						n=printf("%s",header->cert);

						n=(strlen("Certificate")-n);

						for(i=0;i<(n+9);i++)
							printf(" ");
	
						n=printf("%s",header->exchange);

						n=(strlen("Exchange Number")-n);

						for(i=0;i<(n+9);i++)
							printf(" ");

						date=asctime(localtime(&(header->tp)));
						printf("%s\n",date);

						header=header->next;

						j++;
					}

					return;
				}
				else
				{
					printf(KRED);
					printf("\n%66s\n","~There is no such Certificate on the List~");
					printf(KNRM);
					return;	
				}

			}
		}
	}
	else
	{
		printf(KRED);
		printf("\n%53s\n","~Invalid Command~");
		printf(KNRM);
		return;	
	}
}
int printrev(citizen *header, char **data,const int size_data, const int list)
{
	char *date=NULL;
	int i, j, n, check=0;
	citizen *tmp;

	if(size_data==2)
	{

		if (((header)==NULL)&&(!list))
		{
			printf(KRED);
			printf("\n%54s\n","~The list is empty~");
			printf(KNRM);
			return 0;
		}
		else
		{
			if(strncmp(data[1],"*",strlen("*"))==0)
			{
				if(!list)
				{
					printf(BOLD);
					printf(KCYN);
					printf("\n%94s\n","~Citizen List~");
					printf(KNRM);
					printf(KCYN);
					printf( "\n%17s%21s%20s%20s%14s%26s%26s%24s%13s\n","First Name","Last Name","Birthday","Phone Number","E-mail","IP:Port","Certificate","Exchange Number","Date");
					printf(KNRM);
				}

				if(header==NULL)
					return 1;
				else
				{
					j=printrev(header->next,data,size_data,1);
				
					n=printf("%d.",j);
					n=(7-n);

					for(i=0;i<n;i++)
						printf(" ");

					n=printf("%s",header->first_name);

					n=(strlen("First Name")-n);

					for(i=0;i<(n+12);i++)
						printf(" ");

					n=printf("%s",header->last_name);

					n=(strlen("Last Name")-n);

					for(i=0;i<(n+12);i++)
						printf(" ");

					if(header->birthday.day<10)
						n=printf("0%d/",header->birthday.day);
					else
						n=printf("%d/",header->birthday.day);

					if(header->birthday.month<10)
						n+=printf("0%d/%d",header->birthday.month,header->birthday.year);
					else
						n+=printf("%d/%d",header->birthday.month,header->birthday.year);

					n=(strlen("Birthday")-n);

					for(i=0;i<(n+8);i++)
						printf(" ");

					n=printf("%s",header->phone);

					n=(strlen("Phone Number")-n);

					for(i=0;i<(n+8);i++)
						printf(" ");

					n=printf("%s",header->email);

					n=(strlen("E-mail")-n);

					for(i=0;i<(n+19);i++)
						printf(" ");

					n=printf("%s:%d",header->terminal.IP,header->terminal.port);

					n=(strlen("IP:Port")-n);

					for(i=0;i<(n+15);i++)
						printf(" ");

					n=printf("%s",header->cert);

					n=(strlen("Certificate")-n);

					for(i=0;i<(n+9);i++)
						printf(" ");

					n=printf("%s",header->exchange);

					n=(strlen("Exchange Number")-n);

					for(i=0;i<(n+9);i++)
						printf(" ");

					date=asctime(localtime(&(header->tp)));
					printf("%s\n",date);
				}

				return j+1;
			}
			else
			{
				if(!list)
				{
					check=0;
					tmp=header;
					while(tmp!=NULL)
					{
						if(strncmp(data[1],tmp->cert,strlen(data[1]))==0)
							check++;
				
						tmp=tmp->next;
					}

					if(check)
					{
						printf(BOLD);
						printf(KCYN);
						printf("\n%99s%s~\n","~Citizen List ",data[1]);
						printf(KNRM);
						printf(KCYN);
						printf( "\n%17s%21s%20s%20s%14s","First Name","Last Name","Birthday","Phone Number","E-mail");
						printf( "%26s%26s%24s%13s\n","IP:Port","Certificate","Exchange Number","Date");
						printf(KNRM);
					}
					else
					{
						printf(KRED);
						printf("\n%66s\n","~There is no such Certificate on the List~");
						printf(KNRM);
						return 0;	
					}

				}

				if(header==NULL)
					return 1;
				else
				{
					j=printrev(header->next,data,size_data,1);

					if(strncmp(data[1],header->cert,strlen(data[1]))==0)
					{
						n=printf("%d.",j);
						n=(7-n);

						for(i=0;i<n;i++)
							printf(" ");

						n=printf("%s",header->first_name);

						n=(strlen("First Name")-n);

						for(i=0;i<(n+12);i++)
							printf(" ");

						n=printf("%s",header->last_name);

						n=(strlen("Last Name")-n);

						for(i=0;i<(n+12);i++)
							printf(" ");

						if(header->birthday.day<10)
							n=printf("0%d/",header->birthday.day);
						else
							n=printf("%d/",header->birthday.day);

						if(header->birthday.month<10)
							n+=printf("0%d/%d",header->birthday.month,header->birthday.year);
						else
							n+=printf("%d/%d",header->birthday.month,header->birthday.year);

						n=(strlen("Birthday")-n);

						for(i=0;i<(n+8);i++)
							printf(" ");

						n=printf("%s",header->phone);

						n=(strlen("Phone Number")-n);

						for(i=0;i<(n+8);i++)
							printf(" ");

						n=printf("%s",header->email);

						n=(strlen("E-mail")-n);

						for(i=0;i<(n+19);i++)
							printf(" ");

						n=printf("%s:%d",header->terminal.IP,header->terminal.port);

						n=(strlen("IP:Port")-n);

						for(i=0;i<(n+15);i++)
							printf(" ");

						n=printf("%s",header->cert);

						n=(strlen("Certificate")-n);

						for(i=0;i<(n+9);i++)
							printf(" ");

						n=printf("%s",header->exchange);

						n=(strlen("Exchange Number")-n);

						for(i=0;i<(n+9);i++)
							printf(" ");

						date=asctime(localtime(&(header->tp)));
						printf("%s\n",date);

						return j+1;
					}
					else
						return j--;
				}
			}
		}
	}
	else
	{
		printf(KRED);
		printf("\n%53s\n","~Invalid Command~");
		printf(KNRM);
		return 0;	
	}
}
