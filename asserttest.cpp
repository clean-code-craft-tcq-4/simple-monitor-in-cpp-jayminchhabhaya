#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace BatteryStatus;

int main() {
  Battery batteryobj;
  std::vector<float>args{25, 70, 0.7};
  assert(batteryobj.batteryIsOk(args) == true);
   std::vector<float>args1{50, 85, 0};
  assert(batteryobj.batteryIsOk(args1) == false);
}