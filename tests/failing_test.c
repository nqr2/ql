#include <ql/Tap.h>

void one() {
  ql_fail_with("failed!");
}

const ql_Test SUITE[] = {
    QL_FAIL(one),
    QL_SUITE_END,
};

int main() {
  if (!ql_test(SUITE)) {
    return 1;
  }

  return 0;
}
