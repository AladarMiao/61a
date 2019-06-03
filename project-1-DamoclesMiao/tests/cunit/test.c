#include <stddef.h>
#include "../../string-helpers.h"
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include "test.h"

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void) {
  return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void) {
  return 0;
}

/* The test initialization function.
 * Opens the temporary file used by the test.
 */
void init_test1(void) {
  return;
}

/* The test cleanup function.
 * Closes the temporary file used by the test in particular.
 */
void clean_test1(void) {
  return;
}

/* Simple test of is_digit().
 */
void testISDIGIT_Integers(void) {
  CU_ASSERT_FALSE(is_digit(0));
  CU_ASSERT_FALSE(is_digit(9));
  CU_ASSERT_FALSE(is_digit(-1));
}

void testISDIGIT_Digits(void) {
  CU_ASSERT_TRUE(is_digit('1'));
  CU_ASSERT_TRUE(is_digit('0'));
  CU_ASSERT_TRUE(is_digit('9'));
}

void testISDIGIT_EscChars(void) {
  CU_ASSERT_FALSE(is_digit('\0'));
  CU_ASSERT_FALSE(is_digit('\"'));
  CU_ASSERT_FALSE(is_digit('\n'));
}

void testISALPHA_LowerCase(void) {
  CU_ASSERT_TRUE(is_alpha('d'));                                                                      	                                                                                                 CU_ASSERT_TRUE(is_alpha('g'));                                                                                                                                                                       CU_ASSERT_TRUE(is_alpha('z')); 
}

void testISALPHA_UpperCase(void) {
  CU_ASSERT_TRUE(is_alpha('C'));
  CU_ASSERT_TRUE(is_alpha('P'));
  CU_ASSERT_TRUE(is_alpha('A'));
}

void testISALPHA_alphabets(void) {
  char p = 'p';
  CU_ASSERT_TRUE(is_alpha(p));
  
}

void testISSPACE_Spaces(void) {
  char f = ' ';
  CU_ASSERT_TRUE(is_space(f));
  
}

void testISSPACE_CorrectSpaces(void) {
  CU_ASSERT_TRUE(is_space(' '));
  CU_ASSERT_FALSE(is_space('A'));
  CU_ASSERT_FALSE(is_space('q'));
}

void testISSPACE_Integers(void) {
  CU_ASSERT_FALSE(is_space('9'));
}

void testISIDENTIFIER_Identifiers(void) {
  CU_ASSERT_TRUE(is_valid_identifier("ouroboros"));
  CU_ASSERT_TRUE(is_valid_identifier("flumpool"));
  CU_ASSERT_TRUE(is_valid_identifier("josh_hug_fan"));
}

void testISIDENTIFIER_alphabets(void) {
  
  CU_ASSERT_TRUE(is_valid_identifier("struggle"));
  
}

void testISIDENTIFIER_numbers(void) {
  CU_ASSERT_TRUE(is_valid_identifier("23456"));
  
}

void testICOMPONENT_Icomponent(void) {
  CU_ASSERT_TRUE(is_identifier_component('_'));
  
}

void testICOMPONENT_alphabets(void) {
  CU_ASSERT_TRUE(is_identifier_component('f'));
  
}

void testICOMPONENT_numbers(void) {
  CU_ASSERT_TRUE(is_identifier_component('6'));
  CU_ASSERT_FALSE(is_identifier_component(7));
}

void testConcat (void) {
    char *goo = "goo";
    char *cindy = "su";
    char *str[10];
    str[0]=*goo;
    str[1]=*cindy;
    CU_ASSERT_EQUAL(0, (strcmp("goosu",str_concat(str, 2))));
}


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main() {
  CU_TestInfo isdigit_tests[] = {{"Test actual digits", testISDIGIT_Digits},
                                 {"Test esc chars", testISDIGIT_EscChars},
                                 {"Test numbers", testISDIGIT_Integers},
                                 CU_TEST_INFO_NULL};
  CU_TestInfo isconcat_tests[]={{"eh", testConcat}};

 CU_TestInfo isalpha_tests[] = {{"Test lower case", testISALPHA_LowerCase}, 
{"Test upper case", testISALPHA_UpperCase}, {"Test actual alphabets", testISALPHA_alphabets}, CU_TEST_INFO_NULL};

  CU_TestInfo isspace_tests[] = {{"Test actual spaces", testISSPACE_Spaces}, {"Test alphabets and correct space", testISSPACE_CorrectSpaces}, {"Test numbers", testISSPACE_Integers},                                                                                                                                                                CU_TEST_INFO_NULL};

  CU_TestInfo isidentifier_tests[] = {{"Test actual identifiers", testISIDENTIFIER_Identifiers}, {"Test alphabets", testISIDENTIFIER_alphabets}, {"Test numbers", testISIDENTIFIER_numbers}, CU_TEST_INFO_NULL};

  CU_TestInfo isicomponent_tests[] = {{"Test actual icomponent", testICOMPONENT_Icomponent}, {"Test alphabets", testICOMPONENT_alphabets}, {"Test numbers", testICOMPONENT_numbers}, CU_TEST_INFO_NULL};

  CU_SuiteInfo suites[] = {{"is_digit testing", init_suite1, clean_suite1,
                           isdigit_tests}, {"is_alpha testing", init_suite1, clean_suite1, isalpha_tests}, {"is_space testing", init_suite1, clean_suite1, isspace_tests}, {"is_identifier_component testing", init_suite1, clean_suite1, isicomponent_tests}, {"is_valid_identifier testing", init_suite1, clean_suite1, isidentifier_tests},{"str_concat testing", init_suite1, clean_suite1,
                                                                                                                                                                                                                                                                                                                                               isconcat_tests},
                           CU_SUITE_INFO_NULL};

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  if (CU_register_suites(suites)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
