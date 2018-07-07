#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include"header.h"
int command_file(const char* command, const int size)/*Clarify the command in file section*/
{
	int i;

	for(i=0;i<size-strlen("backup");i++)
	{
		if(strncmp(command+i,"backup",strlen("backup"))==0)
			return 1;
	}
	for(i=0;i<size-strlen("restore");i++)
	{
		if(strncmp(command+i,"restore",strlen("restore"))==0)
			return 2;
	}
	for(i=0;i<size-strlen("exit");i++)
	{	

		if((strncmp(command+i,"exit",strlen("exit"))==0)||(strncmp(command+i,"EXIT",strlen("EXIT"))==0))
			return 3;
	}

	printf(KRED);
	printf("\n%32s\n","~Invalid Command~");
	printf(KNRM);
	return 0;
}
void backup(citizen **header, FILE *fp )
{
	citizen *tmp=NULL;
	int n, i;

	tmp=(*header);

		while(tmp!=NULL)
		{
			n=fprintf(fp,"%s, ",tmp->first_name);

			n=(strlen("First Name")-n);

			for(i=0;i<(n+12);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s, ",tmp->last_name);

			n=(strlen("Last Name")-n);

			for(i=0;i<(n+12);i++)
				fprintf(fp," ");

			if(tmp->birthday.day<10)
				n=fprintf(fp,"0%d/",tmp->birthday.day);
			else
				n=fprintf(fp,"%d/",tmp->birthday.day);

			if(tmp->birthday.month<10)
				n+=fprintf(fp,"0%d/%d",tmp->birthday.month,tmp->birthday.year);
			else
				n+=fprintf(fp,"%d/%d",tmp->birthday.month,tmp->birthday.year);

			n=(strlen("Birthday")-n);

			for(i=0;i<(n+8);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s, ",tmp->phone);

			n=(strlen("Phone Number")-n);

			for(i=0;i<(n+8);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s, ",tmp->email);

			n=(strlen("E-mail")-n);

			for(i=0;i<(n+19);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s:%d, ",tmp->terminal.IP,tmp->terminal.port);

			n=(strlen("IP:Port")-n);

			for(i=0;i<(n+15);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s, ",tmp->cert);

			n=(strlen("Certificate")-n);

			for(i=0;i<(n+9);i++)
				fprintf(fp," ");

			n=fprintf(fp,"%s, ",tmp->exchange);

			n=(strlen("Exchange Number")-n);

			for(i=0;i<(n+9);i++)
				fprintf(fp," ");

			fprintf(fp,"%ld\n",tmp->tp);

			tmp = tmp->next;
		}

		printf(KGRN);
		printf("\n%35s\n","~Back up File Created~");
		printf(KNRM);
		return;
}
citizen* restore(citizen **header,FILE *fp, const char choice)
{
	citizen **tmp=NULL;
	char **data=NULL, *str=NULL;
	int size_data, n, i;
	
	if(choice=='y')
	{

		while((*header)!=NULL)
		{
			str=(*header)->first_name;
			free(str);

			str=(*header)->last_name;
			free(str);

			str=(*header)->phone;
			free(str);

			str=(*header)->email;
			free(str);

			str=(*header)->cert;
			free(str);

			str=(*header)->exchange;
			free(str);

			(*header)=(*header)->next;
		}
	}

	tmp=header;

	str=(char*)malloc(sizeof(char)*SIZE);

	if(str==NULL)
	{
		printf("\n%33s\n","No Memory Available");
		exit(1);
	}

	while (!feof(fp))
	{
		fgets(str,SIZE,fp);

		size_data=store_data(&data,str," ,	");

		n=check_newcitizen(&data,size_data,0);

		if(n)
		{
			insert_citizen(&data,tmp,atol(data[8]),0);

			free(str);

			str=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

			if(str==NULL)
			{
				printf(KRED);
				printf("\n%33s\n","No Memory Available");
				printf(KNRM);
				exit(1);
			}

			for(i=0;i<SIZE;i++)/*Refreshing the command string*/
				str[i]=0;
		}
		else
		{
			free(str);

			str=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

			if(str==NULL)
			{
				printf(KRED);
				printf("\n%33s\n","No Memory Available");
				printf(KNRM);
				exit(1);
			}

			for(i=0;i<SIZE;i++)/*Refreshing the command string*/
				str[i]=0;
		}
	}
	
	

	return (*header);
}
