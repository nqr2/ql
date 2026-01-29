#include <ql/Assert.h>
#include <ql/Tap.h>

void assert_failure() {
  ql_fail_with("assertion failed");
}

void assert_false_fails() {
  QL_ASSERT(false, "This always fails");
}

void assert_true_succeeds() {
  QL_ASSERT(true, "This never fails");
}

const ql_Test SUITE[] = {
    QL_FAIL(assert_false_fails),
    QL_PASS(assert_true_succeeds),
    QL_SUITE_END,
};

int main() {
  ql_assert_add_handler(assert_failure);

  if (!ql_test(SUITE)) {
    return 1;
  }

  return 0;
}
