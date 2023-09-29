#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *INFO = "[+]";
const char *ERROR = "[-]";
const char *WARNING = "[+-]";

typedef struct HelloConfig {
    char *queryData;
    char *file_path;
} ConfigClone;

typedef struct Config {
    char *query;
    char *file_path;
    // use 0 or 1
    int ignore_case;

} StringConfig;

int len(char **data) {
    int count = 0;
    for(int i = 0; data[i] != NULL; i++) {
        count++;
    }
    return count;
}

void new(StringConfig *config, char *args[]) {
    if(len(args) < 2) {
        printf("%s Error: Unable to acquire values", ERROR);
        exit(1);
    }
    char *env = getenv("IGNORE_CASE");
    if(env == NULL) {
        env = "0";
    }
    config->file_path = args[1];
    config->query = args[2];
    config->ignore_case = atoi(env);
}

void search(char *file_path, char *query) {
    char data[256];
    FILE *poem = fopen(file_path, "r");
    if(poem == NULL) {
        printf("%s file can't be opened \n", ERROR);
        exit(0);
    }
    while(fgets(data, 100, poem) != NULL) {
        char *res = strstr(data, query);
        if(res != NULL) {
	printf("%s RES: %s", INFO, res);
        }
    }
    fclose(poem);
}

int main(int argc, char *argv[]) {
    StringConfig config;
    new(&config, argv);
    search(config.file_path, config.query);

    return EXIT_SUCCESS;
}
