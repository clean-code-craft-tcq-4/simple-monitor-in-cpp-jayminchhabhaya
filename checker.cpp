#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace std;
using namespace BatteryStatus;
void printError(std::string str){
	cout<<str << " out of range! "<<endl;
}
bool ChecksStatus(int min,int max,float value, std::string str){
	if(value < min || value > max) {
    printError(str);
    return false;
	}
	return true;
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
bool Battery::batteryTemperatureIsOk(float temperature){
	return ChecksStatus(MINTEMPERATURE,MAXTEMPERATURE,temperature,"Temperature");
}
bool Battery::batterysocIsOk(float soc){
	 return ChecksStatus(MINSOC,MAXSOC,soc,"State of Charge");
}
bool Battery::batterychargeRateIsOk(float chargeRate){
	if(chargeRate > 0.8) {
    printError("Charge Rate");
    return false;
  }
  return true;
}


