#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace BatteryStatus;

int main() {
  Battery batteryobj;
  assert(batteryobj.batteryIsOk(25, 70, 0.7) == true);
  assert(batteryobj.batteryIsOk(50, 85, 0) == false);
}