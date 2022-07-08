#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace std;
using namespace BatteryStatus;
bool CheckStstus(int min,int max,float value, std::string str)
{
	if(value < min || value > max) {
    printError(str);
    return false;
	}
	return true;
}
void printError(std::string str)
{
	cout<<str << " out of range! "<<endl;
}
bool Battery::batteryIsOk(std::vector<float>ParametersofBatteryStatus) {
	int i = 0;
	for (const auto& funptr : functptr) {
      if(!funptr(ParametersofBatteryStatus[i++]))
	  {
		return false;
	  }
    }
	return true;
}
bool Battery::batteryTemperatureIsOk(float temperature)
{
	return CheckStstus(0,45,temperature,"Temperature");
}
bool Battery::batterysocIsOk(float soc)
{
	 return CheckStstus(20,80,soc,"State of Charge");
}
bool Battery::batterychargeRateIsOk(float chargeRate)
{
	if(chargeRate > 0.8) {
    printError("Charge Rate");
    return false;
  }
  return true;
}


