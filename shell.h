#define MAX_VAR_NUM 10
#define PIPE_MAX_NUM 10
#define FILE_MAX_SIZE 40
#define MAX_CMD_LEN  128
#define HISTORY_COUNT 20


struct commandType {
  char *command;
  char *VarList[MAX_VAR_NUM];
  int VarNum;
};

int shell_exit(char **args);

char *builtin_str[] = {
  "exit"
};
int (*builtin_func[]) (char **) = {
  &shell_exit
};

int shell_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int (*builtin_func[]) (char **) = {
  &shell_exit
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}


typedef struct {
  int   boolInfile;
  int   boolOutfile;
  int   boolBackground;
  struct commandType CommArray[PIPE_MAX_NUM];
  int   pipeNum;
  char  inFile[FILE_MAX_SIZE];
  char  outFile[FILE_MAX_SIZE];
} parseInfo;

/* the function prototypes */
parseInfo *parse(char *);
void free_info(parseInfo *);
void print_info(parseInfo *);
