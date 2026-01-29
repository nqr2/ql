#include <ql/Tap.h>

const ql_Test SUITE[] = {
    QL_SUITE_END,
};

int main() {
  if (!ql_test(SUITE)) {
    return 1;
  }

  return 0;
}
