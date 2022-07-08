#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace BatteryStatus;

int main() {
  Battery batteryobj;
  std::vector<float>ParametersofBatteryStatus{25, 70, 0.7};
  assert(batteryobj.batteryIsOk(ParametersofBatteryStatus) == true);
  std::vector<float>ParametersofBatteryStatus1{50, 85, 0};
  assert(batteryobj.batteryIsOk(ParametersofBatteryStatus1) == false);
}