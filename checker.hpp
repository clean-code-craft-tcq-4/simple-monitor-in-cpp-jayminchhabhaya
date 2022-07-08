#pragma once
#include <assert.h>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
#define MinTemperature 0
#define MaxTemperature 45
#define MaxSoc 20
#define MaxSoc 80


namespace BatteryStatus
{
	class Battery
	{
		public:
		    Battery(){
				functptr.emplace_back(Battery::batteryTemperatureIsOk);	
				functptr.emplace_back(Battery::batterysocIsOk); 
				functptr.emplace_back(Battery::batterychargeRateIsOk);
			};
			~Battery(){};
		    bool batteryIsOk(std::vector<float>ParametersofBatteryStatus);
			static bool batteryTemperatureIsOk(float temperature);
			static bool batterysocIsOk(float soc);
			static bool batterychargeRateIsOk(float chargeRate);
			std::vector<std::function<bool(float)>> functptr;
			
    };
}