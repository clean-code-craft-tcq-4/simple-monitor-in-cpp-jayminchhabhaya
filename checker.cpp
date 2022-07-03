#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace std;
using namespace BatteryStatus;
bool Battery::batteryIsOk(std::vector<float>BatteryFunctionParameters) {
	int i = 0;
	for (const auto& funptr : functptr) {
        if(!funptr(BatteryFunctionParameters[i++]))
		{
		 return false;
		}
    }
	return true;
}
bool Battery::batteryTemperatureIsOk(float temperature)
{
	if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
	}
	return true;
}
bool Battery::batterysocIsOk(float soc)
{
	if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}
bool Battery::batterychargeRateIsOk(float chargeRate)
{
	if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}


