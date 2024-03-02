#include <check.h>
#include <stdio.h>

#include "parser_v2.h"

START_TEST(parser_1) {
  FILE* f = fopen("Ballerina.obj", "r");
  if (f != NULL) {
    model* testModel = (model*)calloc(1, sizeof(model));
    int rValue = modelParser(testModel, "Ballerina.obj");
    int numOfParsedPolygons = testModel->numOfPolygons;
    int numOfParcedVerticies = testModel->vrtx->amountOfPoints / 3;

    ck_assert_int_eq(numOfParcedVerticies, 143358);
    ck_assert_int_eq(numOfParsedPolygons, 286655);
    ck_assert_int_eq(rValue, 0);

    removemodel(testModel);
  }
}
END_TEST

START_TEST(parser_2) {
  model* testModel = (model*)calloc(1, sizeof(model));
  int rValue = modelParser(testModel, "notExistingFile.obj");
  ck_assert_int_eq(rValue, FAILURE);
  removemodel(testModel);
}
END_TEST

void srunner_parser_tests_suite(SRunner* sr) {
  Suite* parserTestsSuite = suite_create("PARCER_TESTS");
  TCase* caseNumOne = tcase_create("PARCES_CASE_TESTS");
  suite_add_tcase(parserTestsSuite, caseNumOne);

  tcase_add_test(caseNumOne, parser_1);
  tcase_add_test(caseNumOne, parser_2);

  srunner_add_suite(sr, parserTestsSuite);
}

int main() {
  Suite* main_suite = suite_create("MAIN_SUITE");
  SRunner* sr = srunner_create(main_suite);

  int numOfFailures = 0;

  srunner_parser_tests_suite(sr);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);

  numOfFailures = srunner_ntests_failed(sr);
  srunner_free(sr);
  return numOfFailures != 0;
}