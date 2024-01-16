#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
char line[201]; //LINES CANT BE MORE THAN 200 CHARACTERS
char *content = NULL;
size_t content_size = 0;

//Correct Test Outputs
char lexTest1Output[] = "Token intlit, value 3\nToken +\nToken intlit, value 3\nToken intlit, value 4\n";

int lexTester(void){
    //use popen to get readable output from terminal
    fp = popen("./scanner Tests/lexTest1", "r");
    while (fgets(line, sizeof(line), fp) != NULL){
        //add more size for reallocation
        content_size += strlen(line);
        //allocate more memory for each line with +1 for null terminator
        content = realloc(content, content_size + 1);
        strcat(content, line);
        memset(line, 0, sizeof(line));
    }
    
    //close pipe
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