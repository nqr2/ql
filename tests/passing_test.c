#include <ql/Tap.h>

void one() {
}

const ql_Test SUITE[] = {
    {"pass", one, false},
    QL_SUITE_END,
};

int main() {
  if (!ql_test(SUITE)) {
    return 1;
  }

  return 0;
}
