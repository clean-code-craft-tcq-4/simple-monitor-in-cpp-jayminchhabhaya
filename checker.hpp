#include <assert.h>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace BatteryStatus
{
	std::vector<std::function<bool(float, float)>> functptr;
	class Battery
	{
		public:
		    Battery(){
				functptr.emplace_back(Battery::batteryTemperatureIsOk);	
				functptr.emplace_back(Battery::batterysocIsOk); 
				functptr.emplace_back(Battery::batterychargeRateIsOk);
			};
			~Battery(){};
		    bool batteryIsOk(float temperature, float soc, float chargeRate);
			static bool batteryTemperatureIsOk(float temperature);
			static bool batterysocIsOk(float soc);
			static bool batterychargeRateIsOk(float chargeRate);
			
    };
}