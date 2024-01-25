#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
FILE *pp;
char line[201]; //---LINES CANT BE MORE THAN 200 CHARACTERS--- (shouldn't matter b/c only reading token info)
char *content = NULL;
size_t content_size = 0;

//Correct Test Outputs
char lexTest1Output[] = "Token intlit, value 3\nToken +\nToken intlit, value 3\nToken intlit, value 4\n";
char lexTest2Output[] = "Unrecognizable token T on line 1\n";
char lexTest3Output[] = "Token intlit, value 4\nToken +\nToken intlit, value 57\nToken *\nToken intlit, value 3\nToken /\nToken intlit, value 8\n";
char lexTest4Output[] = "Token intlit, value 4\nToken +\nToken intlit, value 4\nUnrecognizable token a on line 1\n";

void stringMaker(){
    while (fgets(line, sizeof(line), fp) != NULL){
        content_size += strlen(line);
        content = realloc(content, content_size + 1);
        strcat(content, line);
        memset(line, 0, sizeof(line));
    }
}

int lexTester(void){
    //lexTest1
    fp = popen("./scanner Tests/lexTest1", "r");
    stringMaker();
    assert(!strcmp(lexTest1Output, content));
    content = NULL;
    printf("\nlexTest1 PASSED\n");
    //lexTest1

    //lexTest2
    fp = popen("./scanner Tests/lexTest2", "r");
    stringMaker();
    assert(!strcmp(lexTest2Output, content));
    printf("lexTest2 PASSED\n");
    content = NULL;

    //lexTest3
    fp = popen("./scanner Tests/lexTest3", "r");
    stringMaker();
    assert(!strcmp(lexTest3Output, content));
    printf("lexTest3 PASSED\n");
    content = NULL;

    //lextTest4
    fp = popen("./scanner Tests/lexTest4", "r");
    stringMaker();
    assert(!strcmp(lexTest4Output, content));
    printf("lexTest4 PASSED\n");
    pclose(fp);

    printf("===== ALL TESTS PASSED =====\n");
    return 0;
}

int main(int argc, char *argv[]) {
    lexTester();
    return 0;
}