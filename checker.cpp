#include <assert.h>
#include <iostream>
using namespace std;
using namespace BatteryStatus;
bool Battery::batteryIsOk(float temperature, float soc, float chargeRate) {
	
  if(functptr[0](temperature) && functptr[1](soc) && functptr[2](chargeRate)) 
	 return true;
  return false; 
}
bool batteryTemperatureIsOk(float temperature)
{
	if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
	}
	return true;
}
bool batterysocIsOk(float soc)
{
	if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  }
  return true;
}
bool batterychargeRateIsOk(float chargeRate)
{
	if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}


