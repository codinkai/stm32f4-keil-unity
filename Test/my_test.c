
#include "unity.h"
#include "debug_printf.h"

void setUp() {
  printf("setUp my_test\n");
}

void tearDown() {
  printf("tearDown my_test\n");
}

void testWillAlwaysPass(void) {
  TEST_ASSERT_EQUAL_INT(42,42);
}

void xxtestWillAlwaysFail(void) {
  TEST_ASSERT_EQUAL_INT(42,1);
}
