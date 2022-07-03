#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace BatteryStatus;

int main() {
  Battery batteryobj;
  std::vector<float>BatteryFunctionParameters{25, 70, 0.7};
  assert(batteryobj.batteryIsOk(BatteryFunctionParameters) == true);
   std::vector<float>BatteryFunctionParameters1{50, 85, 0};
  assert(batteryobj.batteryIsOk(BatteryFunctionParameters1) == false);
}