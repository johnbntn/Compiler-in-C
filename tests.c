#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
char line[201]; //---LINES CANT BE MORE THAN 200 CHARACTERS--- (shouldn't matter b/c only reading token info)
char *content = NULL;
size_t content_size = 0;

//Correct Test Outputs
char lexTest1Output[] = "Token intlit, value 3\nToken +\nToken intlit, value 3\nToken intlit, value 4\n";
char lexTest2Output[] = "Unrecognizable token T on line 1\n";
char lexTest3Output[] = "Token intlit, value 4\nToken +\nToken intlit, value 57\nToken *\nToken intlit, value 3\nToken /\nToken intlit, value 8\n";
char lexTest4Output[] = "Token intlit, value 4\nToken +\nToken intlit, value 4\nUnrecognizable token a on line 1\n";

//get output string from terminal and concacate the lines
void stringMaker(){
    while (fgets(line, sizeof(line), fp) != NULL){
        content_size += strlen(line);
        content = realloc(content, content_size + 1);
        strcat(content, line);
        memset(line, 0, sizeof(line));
    }
}

//compare output to expected output
int lexTester(void){
    //lexTest1
    fp = popen("./scanner Tests/lexTest1_StdInput", "r");
    stringMaker();
    assert(!strcmp(lexTest1Output, content));
    content = NULL;
    printf("\nlexTest1 PASSED\n");

    //lexTest2
    fp = popen("./scanner Tests/lexTest2_OnlyText", "r");
    stringMaker();
    assert(!strcmp(lexTest2Output, content));
    printf("lexTest2 PASSED\n");
    content = NULL;

    //lexTest3
    fp = popen("./scanner Tests/lexTest3_StdInput", "r");
    stringMaker();
    assert(!strcmp(lexTest3Output, content));
    printf("lexTest3 PASSED\n");
    content = NULL;

    //lextTest4
    fp = popen("./scanner Tests/lexTest4_InvalidToken", "r");
    stringMaker();
    assert(!strcmp(lexTest4Output, content));
    printf("lexTest4 PASSED\n");
    
    pclose(fp);
    free(content);
    
    printf("===== ALL TESTS PASSED =====\n");
    return 0;
}

int main(int argc, char *argv[]) {
    lexTester();
    return 0;
}