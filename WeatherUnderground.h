#ifndef _WEATHERUNDERGROUND_H_

#include <cstdlib>
#include <fstream>
#include <iterator>
#include <UrlMon.h>
#include <string>
#include <iostream>     // std::cout, std::right, std::endl
#include <iomanip>
#include "JSON.h"
#pragma comment(lib, "urlmon.lib")

#define lFILENAME L"wu_Raesfeld.json"
#define FILENAME "wu_Raesfeld.json"
#define JSONFILE L"http://api.wunderground.com/api/8525b3ba614c185a/forecast/lang:DL/q/zmw:00000.15.10406.json"

class WeatherUnderground
{
	public:
		WeatherUnderground();
		void update(void);
		char* maxDayTempC();
		std::wstring maxDayTempW();
		char* minDayTempC();
		std::wstring minDayTempW();
		char* conditionC();
		std::wstring conditionW();
		std::wstring windSpeed();
		char* windDirectionC();
		std::wstring windDirectionW();
		std::wstring humidity();
	private:
		std::wstring max;
		std::wstring min;
		std::wstring cond;
		double wind;
		std::wstring wdir;
		double luft;

};
#endif