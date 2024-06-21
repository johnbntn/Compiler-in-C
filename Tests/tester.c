#include "../data.h"
#include "../defs.h"
#include "../decl.h"
/*
Be careful making tests as ./tester will run from the main directory
*/
int tests = 0;
int tests_passed = 0;
int status;

int main (int argc, char *argv[]) {

    //Must have compiler in PWD
    status = system("test -e jlcc");
    if (status != 0) {
        printf("Must have jlcc, please run: make jlcc\n");
        return -1;
    }

/* ==================== STD TEST ==================== */
    //compile into asm and check whether the file matches expected
    system("./jlcc Tests/Units/std_test");
    system("diff -u out.s Tests/Expected/std_test_exp.s > Tests/std_test_result\n");
    tests += 1;

    //if the files match, status will be 0 and increment tests_passed
    status = system("! test -s Tests/std_test_result\n");
    if (status != 0) printf("Failed: std_test\n");
    else if (status == 0) {
        printf("Passed: std_test\n");
        system("rm Tests/std_test_result");
        tests_passed += 1;
    }
/* ==================== STD TEST ==================== */

/* ==================== VARS TEST ==================== */
    system("./jlcc Tests/Units/vars_test");
    system("diff -u out.s Tests/Expected/vars_test_exp.s > Tests/vars_test_result\n");
    tests += 1;

    status = system("! test -s Tests/vars_test_result\n");
    if (status != 0) printf("Failed: vars_test\n");
    else if (status == 0) {
        printf("Passed: vars_test\n");
        system("rm Tests/vars_test_result");
        tests_passed += 1;
    }
/* ==================== VARS TEST ==================== */

/* ==================== SYNTAX TEST ==================== */
    system("./jlcc Tests/Units/syntax_test > Tests/syntax_test_output");
    system("diff -u Tests/syntax_test_output Tests/Expected/syntax_test_exp > Tests/syntax_test_result");
    tests += 1;

    status = system("! test -s Tests/syntax_test_result\n");
    if (status != 0) printf("Failed: syntax_test\n");
    else if (status == 0) {
        printf("Passed: syntax_test\n");
        system("rm Tests/syntax_test_result Tests/syntax_test_output");
        tests_passed += 1;
    }
/* ==================== SYNTAX TEST ==================== */

/* ==================== USAGE TEST ==================== */
    system("./jlcc -option Tests/Units/syntax_test > Tests/usage_test_output");
    system("diff -u Tests/usage_test_output Tests/Expected/usage_test_exp > Tests/usage_test_result");
    tests += 1;

    status = system("! test -s Tests/usage_test_result\n");
    if (status != 0) printf("Failed: usage_test\n");
    else if (status == 0) {
        printf("Passed: usage_test\n");
        system("rm Tests/usage_test_result Tests/usage_test_output");
        tests_passed += 1;
    }
/* ==================== USAGE TEST ==================== */

/* ===================== UNDECLARED VARIABLE TEST ==================== */
    system("./jlcc Tests/Units/unvar_test > Tests/unvar_test_output");
    system("diff -u Tests/unvar_test_output Tests/Expected/unvar_test_exp > Tests/unvar_test_result");
    tests += 1;

    status = system("! test -s Tests/unvar_test_result\n");
    if (status != 0) printf("Failed: unvar_test\n");
    else if (status == 0) {
        printf("Passed: unvar_test\n");
        system("rm Tests/unvar_test_result Tests/unvar_test_output");
        tests_passed += 1;
    }
/* ==================== UNDECLARED VARIABLE TEST ==================== */ 

    printf("\nTests Passed: %d/%d\n", tests_passed, tests);
    if (tests_passed == tests) printf("=======ALL TESTS PASSED=======\n");
    return 0;
}