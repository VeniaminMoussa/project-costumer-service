/* Moussa Beniamin
AM: 2022201700115
dit17115@uop.gr

Giannopoulos Kostantinos
AM: 2022201700033
dit17033@uop.gr
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include"header.h"
int main (void)
{
	system("clear");

	FILE *fp;
	int i, j, n, choice=0, size=0, size_data=1, order;
	char *command=NULL, **data=NULL, *file=NULL, **str=NULL, check;
	citizen *header=NULL;

	srand(time(NULL));

	while(choice!=4)
	{
		switch(choice)
		{
			case 0:
			{
				system("clear");

				printf(BOLD);
				printf(KCYN);
				printf("\n%30s","~e-Goverment~\n");/*Entering the Main Menu and Selecting a Choice*/
				printf(UNDERLINE);
				for(i=0;i<47;i++)
					printf("_");
				printf(KNRM);
				printf(KCYN);
		
				printf("\n\n%28s%25s%26s%25s","1.Citizen\n","2.List\n","3.Files\n","4.Exit\n");

				printf(KCYN);
				printf(BOLD);
				printf("\nEnter Choice[Number] ");
				printf(KBLU);
				printf("$>");
				printf(KNRM);
				scanf("%d",&choice);
				while(getchar() != '\n');			

				while((choice<1)||(choice>4))
				{
					printf(KCYN);
					printf(BOLD);
					printf("Try again entering a choice ");
					printf(KBLU);
					printf("$>");
					printf(KNRM);
					scanf("%d",&choice);
					while(getchar() != '\n');
				}


				if(!size)
				{	
					command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/
					if(command==NULL)
					{
						printf(KRED);
						printf("\n%33s\n","No Memory Available");
						printf(KNRM);
						exit(1);
					}

					for(i=0;i<SIZE;i++)/*Refreshing the command string*/
						command[i]=0;
				}
				else
				{
					command=(char*)realloc(command,sizeof(char)*SIZE);

					if(command==NULL)
					{
						printf(KRED);
						printf("\n%33s\n","No Memory Available");
						printf(KNRM);
						exit(1);
					}


					for(i=0;i<SIZE;i++)/*Refreshing the command string*/
						command[i]=0;
				}

				system("clear");

			}
			break;
			case 1:
			{
				while(choice==1)
				{
					system("clear");

					printf(BOLD);
					printf(KCYN);
					printf("\n%69s","~Citizen Section~\n");/*Entering Citizen Section*/
					printf(UNDERLINE);

					for(i=0;i<120;i++)
						printf("_");
					printf(KNRM);

					printf(ITALIC);
					printf(KCYN);
					printf("\nType: %cnewCitizen [First Name],[Last Name],[Birthday],[Phone Number],[e-mail],[IP:Port],[Certificate],[Exchange Number]",250);
					printf("\n      %cserveCitizen",250);
					printf("\n      %cremoveCitzen",250);
					printf("\n      %cexit",250);
					printf("\n\nNotification: %c[Birthday]=dd/mm/yyyy",250);
					printf("\n              %c[Phone Number]=xxxx-xxxxxx or xxx-xxxxxxx",250);
					printf("\n              %c[Certification]=familyCert, birthCert, debtCert, residentCert, electionCert",250);
					printf("\n              %c[Exchange Number]=xxxxx-xxxxx-x",250);

					do
					{
						printf(KNRM);
						printf(KBLU);
						printf(BOLD);
						printf("\n\n$>");
						printf(KNRM);

						scanf("%[^\n]s",command);
						while(getchar() != '\n');

						order=command_citizen(command,SIZE);/*Clarify citizen command*/
						size=strlen(command)+1;

						if(order==1)/*Order for new citizen*/
						{
							size_data=store_data(&data,command," ,	");

							str=(data+1);
							n=check_newcitizen(&str,size_data,1);

							if(n)
							{
								order=insert_citizen(&str,&header,time(NULL),1);

								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								if(order)
									order=4;
							}
							else
							{
								free(command);

								command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

								if(command==NULL)
								{
									printf(KRED);
									printf("\n%33s\n","No Memory Available");
									printf(KNRM);
									exit(1);
								}

								for(i=0;i<SIZE;i++)/*Refreshing the command string*/
									command[i]=0;
							}
						
						}
						else if(order==2)/*Order to serve citizen*/
						{
							header=servecitizen(&header);

							printf(KCYN);
							printf("\n\nPress ENTER key to Continue...\n");
							printf(HIDE);
							getchar();
							printf(KNRM);
							while(getchar() != '\n');

							free(command);

								command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

								if(command==NULL)
								{
									printf(KRED);
									printf("\n%33s\n","No Memory Available");
									printf(KNRM);
									exit(1);
								}

								for(i=0;i<SIZE;i++)/*Refreshing the command string*/
									command[i]=0;

							order=4;
						}
						else if(order==3)/*Order to remove citizen*/
						{
							if(header==NULL)
							{
								printf(KRED);
								printf("\n%70s\n","~The list is empty~");
								printf(KNRM);

								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								free(command);

								command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

								if(command==NULL)
								{
									printf(KRED);
									printf("\n%33s\n","No Memory Available");
									printf(KNRM);
									exit(1);
								}

								for(i=0;i<SIZE;i++)/*Refreshing the command string*/
									command[i]=0;

							}
							else
							{
								free(command);

								command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

								if(command==NULL)
								{
									printf(KRED);
									printf("\n%33s\n","No Memory Available");
									printf(KNRM);
									exit(1);
								}

								for(i=0;i<SIZE;i++)/*Refreshing the command string*/
									command[i]=0;


								printf(KCYN);
								printf("\n\nEnter Last Name ");
								printf(KBLU);
								printf(BOLD);
								printf("S>");
								printf(KNRM);
								
								scanf("%[^\n]s",command);
								while(getchar() != '\n');

								header=removecitizen(&header,&command);

								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								free(command);

								command=(char*)malloc(sizeof(char)*SIZE);/*Creating the string of the command*/

								if(command==NULL)
								{
									printf(KRED);
									printf("\n%33s\n","No Memory Available");
									printf(KNRM);
									exit(1);
								}

								for(i=0;i<SIZE;i++)/*Refreshing the command string*/
									command[i]=0;
							}

							order=4;
						}
						else if(order==4)
							choice=0;
					}while(order!=4);
				}
			}
			break;
			case 2:
			{
				while(choice==2)
				{
					system("clear");

					printf(BOLD);
					printf(KCYN);
					printf("\n%52s","~List Section~\n");/*Entering List Section*/
					printf(UNDERLINE);

					for(i=0;i<89;i++)
						printf("_");
					printf(KNRM);

					printf(ITALIC);
					printf(KCYN);
					printf("\nType: %cprint [Certification] or *",250);
					printf("\n      %cprintRev [Certification] or *",250);
					printf("\n      %cexit"	,250);
					printf("\n\nNotification: [Certification]=familyCert, birthCert, debtCert, residentCert, electionCert");

					do
					{
						printf(KNRM);
						printf(KBLU);
						printf(BOLD);
						printf("\n\n$>");
						printf(KNRM);

						scanf("%[^\n]s",command);
						while(getchar() != '\n');

						order=command_list(command,SIZE);/*Clarify list command*/
						size=strlen(command)+1;

						size_data=store_data(&data,command," ,	");

						command=(char*)realloc(command,sizeof(char)*size);

						if(command==NULL)
						{
							printf(KRED);
							printf("\n%54s\n","No Memory Available");
							printf(KNRM);
							exit(1);
						}
						if(order==1)
						{
							printlist(header,data,size_data);

							printf(KCYN);
							printf("\nPress ENTER key to Continue...\n");
							printf(HIDE);
							getchar();
							printf(KNRM);
							while(getchar() != '\n');

							order=3;
						}
						else if(order==2)
						{
							printrev(header,data,size_data,0);

							printf(KCYN);
							printf("\nPress ENTER key to Continue...\n");
							printf(HIDE);
							getchar();
							printf(KNRM);
							while(getchar() != '\n');

							order=3;
						}
						else if(order==3)
							choice=0;

					}while(order!=3);
				}
			}
			break;
			case 3:
			{
				while(choice==3)
				{
					system("clear");

					printf(BOLD);
					printf(KCYN);
					printf("\n%30s","~File Section~\n");/*Entering File Section*/
					printf(UNDERLINE);

					for(i=0;i<47;i++)
						printf("_");
					printf(KNRM);

					printf(ITALIC);
					printf(KCYN);
					printf("\nType: %cbackup [archive name].txt",250);
					printf("\n      %crestore [archive name].txt",250);
					printf("\n      %cexit"	,250);

					do
					{
						printf(KNRM);
						printf(KBLU);
						printf(BOLD);
						printf("\n\n$>");
						printf(KNRM);

						scanf("%[^\n]s",command);/*Giving the command*/
						while(getchar() != '\n');
				
						order=command_file(command,SIZE);/*Clarify file command*/
						size=strlen(command)+1;

						size_data=store_data(&data,command," ,	");

						command=(char*)realloc(command,sizeof(char)*size);

						if(command==NULL)
						{
							printf(KRED);
							printf("\n%25s\n","No Memory Available");
							printf(KNRM);
							exit(1);
						}

						if(order==1)
						{
							file = (char*)malloc(50*sizeof(char));
							if (file==NULL) exit(1);

							if(size_data>2)
							{
								printf(KRED);
								printf("\n%42s\n","~Invalid Command.Too many arguments~");
								printf(KNRM);
								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								order=3;
							}
							else if(size_data==1)
							{
								printf(KRED);
								printf("\n%42s\n","~There is no given name for the File~");
								printf(KNRM);
								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								order=3;
							}
							else if(size_data==2)
							{
								if(strlen(data[1])<5)
								{
									printf(KRED);
									printf("\n%40s\n","~Invalid Command at archive name~");
									printf(KNRM);
									printf(KCYN);
									printf("\n\nPress ENTER key to Continue...\n");
									printf(HIDE);
									getchar();
									printf(KNRM);
									while(getchar() != '\n');

									order=3;
								}
								else
								{
									i=(strlen(data[1])-strlen(".txt"));

									if(strncmp(data[1]+i,".txt",strlen(".txt"))!=0)
									{
										printf(KRED);
										printf("\n%40s\n","~Invalid Command at archive name~");
										printf(KNRM);
										printf(KCYN);
										printf("\n\nPress ENTER key to Continue...\n");
										printf(HIDE);
										getchar();
										printf(KNRM);
										while(getchar() != '\n');

										order=3;
									}
									else
									{
										if(header==NULL)
										{
											printf(KRED);
											printf("\n%33s\n","~The list is Empty~");
											printf(KNRM);
											printf(KCYN);
											printf("\n\nPress ENTER key to Continue...\n");
											printf(HIDE);
											getchar();
											printf(KNRM);
											while(getchar() != '\n');

											order=3;
										}
										else
										{

											strncpy(file,data[1],strlen(data[1]));
											strncpy(file+strlen(data[1]),"\0",1);

											fp=fopen(file,"w+");/*open the file*/

											if (fp==NULL)
											{
												printf(KRED);
												printf("\nFile is not opening...\n");
												order=3;
												printf(KNRM);
												printf(KCYN);
												printf("\n\nPress ENTER key to Continue...\n");
												printf(HIDE);
												getchar();
												printf(KNRM);
												while(getchar() != '\n');

											}
											else
											{
												backup(&header,fp);
												printf(KCYN);
												printf("\n\nPress ENTER key to Continue...\n");
												printf(HIDE);
												getchar();
												printf(KNRM);
												while(getchar() != '\n');

												order=3;
												fclose(fp); /*close the file*/
											}
										}
									}
								}
							}
						}
						else if(order==2)
						{
							file = (char*)malloc(50*sizeof(char));
							if (file==NULL) exit(1);

							if(size_data>2)
							{
								printf(KRED);
								printf("\n%42s\n","~Invalid Command.Too many arguments~");
								printf(KNRM);
								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								order=3;
							}
							else if(size_data==1)
							{
								printf(KRED);
								printf("\n%42s\n","~There is no given name for the File~");
								printf(KNRM);
								printf(KCYN);
								printf("\n\nPress ENTER key to Continue...\n");
								printf(HIDE);
								getchar();
								printf(KNRM);
								while(getchar() != '\n');

								order=3;
							}
							else if(size_data==2)
							{
								if(strlen(data[1])<5)
								{
									printf(KRED);
									printf("\n%40s\n","~Invalid Command at archive name~");
									printf(KNRM);
									printf(KCYN);
									printf("\n\nPress ENTER key to Continue...\n");
									printf(HIDE);
									getchar();
									printf(KNRM);
									while(getchar() != '\n');

									order=3;
								}
								else
								{
									i=(strlen(data[1])-strlen(".txt"));

									if(strncmp(data[1]+i,".txt",strlen(".txt"))!=0)
									{
										printf(KRED);
										printf("\n%40s\n","~Invalid Command at archive name~");
										printf(KNRM);
										printf(KCYN);
										printf("\n\nPress ENTER key to Continue...\n");
										printf(HIDE);
										getchar();
										printf(KNRM);
										while(getchar() != '\n');

										order=3;
									}
									else
									{
										strncpy(file,data[1],strlen(data[1]));
										strncpy(file+strlen(data[1]),"\0",1);

										if (!(fp=fopen(file,"r")))
										{	
											printf(KRED);
											for(i=0;i<8;i++)
												printf(" ");

											printf("\n~Error opening the file %s~",file);
											printf(KNRM);
											printf(KCYN);
											printf("\n\n\nPress ENTER key to Continue...\n");
											printf(HIDE);
											getchar();
											printf(KNRM);
											while(getchar() != '\n');

											order=3;
										}
										else
										{
											check='n';

											if(header!=NULL)
											{
												printf(BOLD);
												printf(KCYN);
												printf("Delete the existed List (y or n) ");
												printf(KBLU);
												printf("$>");
												printf(KNRM);
												scanf("%c",&check);
												while(getchar() != '\n');
	
												while((check!='n')&&(check!='y'))
												{
													printf(KCYN);
													printf(BOLD);
													printf("Try again entering a choice ");
													printf(KBLU);
													printf("$>");
													printf(KNRM);
													scanf("%c",&check);
													while(getchar() != '\n');
												}
											}

											header=restore(&header,fp,check);
											printf(KCYN);
											printf("\n\nPress ENTER key to Continue...\n");
											printf(HIDE);
											getchar();
											printf(KNRM);
											while(getchar() != '\n');

											order=3;
											fclose(fp); /*close the file*/

										}
									}
								}
							}
						}
						else if(order==3)
							choice=0;
					}while(order!=3);
				}
			}
			break;
			case 4:/*Free every allocated memory,that has remained before exiting the game*/
			{
				free(command);

				for(i=0;i<size_data;i++)
					free(data[i]);

				free(data);
			}
			break;
		}
	}
	return 0;
}
int store_data(char ***data, char *command, const char token[])/*Distinguish all the datas from the command line and store them at the data board*/
{
	int size_data=1, i, n;
	char *str;

	(*data)=(char**)realloc((*data),sizeof(char*)*size_data);

	if((*data)==NULL)
	{
		printf("\n%70s\n","No Memory Available");
		exit(1);
	}

	(*data)[0]=strtok(command,token);

	if((*data)[0]==NULL)
		return 0;

	size_data++;
	(*data)=(char**)realloc((*data),sizeof(char*)*size_data);

	if((*data)==NULL)
	{
		printf("\n%70s\n","No Memory Available");
		exit(1);
	}

	while(((*data)[size_data-1]=strtok(NULL,token))!=NULL)
	{
		size_data++;
		(*data)=(char**)realloc((*data),sizeof(char*)*size_data);

		if((*data)==NULL)
		{
			printf("\n%70s\n","No Memory Available");
			exit(1);
		}
	}

	size_data--;
	(*data)=(char**)realloc((*data),sizeof(char*)*size_data);

	if((*data)==NULL)
	{
		printf("\n%70s\n","No Memory Available");
		exit(1);
	}

	return size_data;
}

/*		newCitizen Stella, Panagiotopoulou, 17/10/1993, 2310-618445, stella.pan@gmail.gr,  102.83.31.17:9535, birthCert, 79927-39871-2		*/


