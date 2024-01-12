#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
int status;
char line[100];
char *content = NULL;
size_t content_size = 0;

//Correct Test Outputs
char lexTest1Output[] = "Token intlit, value 3\nToken +\nToken intlit, value 3\nToken intlit, value 4\n";

int lexTester(void){
    fp = popen("./scanner Tests/lexTest1", "r");
    while (fgets(line, sizeof(line), fp) != NULL){
        content_size += strlen(line);
        content = realloc(content, content_size + 1); // +1 for the null terminator
        strcat(content, line);
    }
    pclose(fp);
    assert(!strcmp(lexTest1Output, content));
    printf("lexTest1 PASSED\n");
    printf("===== ALL TESTS PASSED =====\n");
    return 0;
}

int main(int argc, char *argv[]) {
    lexTester();
    return 0;
}