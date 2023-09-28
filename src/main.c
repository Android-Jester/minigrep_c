#include <stdio.h>
#include <stdlib.h>
const char *INFO = "[+]";
const char *ERROR = "[-]";
const char *WARNING = "[+-]";

typedef struct Config {
    char *query;
    char *file_path;
    // use 0 or 1
    int ignore_case;

} StringConfig;

// void new(StringConfig *config, char *args[]) {
//     char *query = args[1];
//     char *file_path = args[2];
//     int ignore_case = atoi(getenv("IGNORE_CASE"));
//     config->file_path = file_path;
//     config->query = query;
//     config->ignore_case = ignore_case;
// }

// int len(char **contents) {
//     int count = 0;
//     char *init_char = contents[0];
//     while(init_char != NULL) {
//         count++;
//         init_char = contents[count];
//     }
//     return count;
// }

// char **file_search(char *query, char **contents) {
//     char **results;
//     // Line by line
//     for(int i = 0; i < len(contents); i++) {
//     }
// }

// char **search(char *query, char *contents) {
//   char **results;
//   for (int i = 0; i < len(contents); i++) {
//   }
// }

int main(int argc, char *argv[]) {
    // StringConfig config;
    // new(&config, argv);
    char *poemData;
    FILE *poem = fopen("test.txt", "rw");
    if(NULL == poem) {
        printf("file can't be opened \n");
    }

    while(fgets(poemData, 100, poem) != NULL) {
        printf("%s Poem: %s", INFO, poemData);
    };
    fclose(poem);
    return EXIT_SUCCESS;
}
