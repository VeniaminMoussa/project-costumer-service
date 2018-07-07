#define KNRM  "\e[0m"
#define KRED  "\e[31m"
#define KGRN  "\e[32m"
#define KYEL  "\e[33m"
#define KBLU  "\e[34m"
#define KMAG  "\e[35m"
#define KCYN  "\e[36m"
#define KWHT  "\e[37m"
#define HIDE "\e[8m"
#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define ITALIC "\e[3m"
#define DIM "\e[2m"
#define SIZE 1000
typedef struct
{ 
	int year;
	int month;
	int day;
}date;
typedef struct
{ 
	char IP[16];
	int port;
}netData;
typedef struct ctzn
{
	char *first_name;
	char *last_name;
	date birthday;
	char *phone;
	char *email;
	char *cert;
	netData terminal;
	char *exchange;
	time_t tp;

	struct ctzn *next;
}citizen;
int command_citizen(const char* command, const int size);
int command_list(const char* command, const int size);
int command_file(const char* command, const int size);
char* checksum(char **exchange);
int check_newcitizen(char ***data,const int size_data, const int check);
int insert_citizen(char ***data, citizen **header,const time_t value, const int check);
citizen* removecitizen(citizen **header, char **command);
citizen* servecitizen(citizen **header);
void printlist(citizen *header, char **data,const int size_data);
int printrev(citizen *header, char **data,const int size_data, const int list);
void backup(citizen **header, FILE *fp );
citizen* restore(citizen **header,FILE *fp, const char choice);
int store_data(char ***data, char *commmand, const char token[]);

