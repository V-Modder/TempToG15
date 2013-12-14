#include "WeatherUnderground.h"

WeatherUnderground::WeatherUnderground()
{
	this->update();
}

void WeatherUnderground::update(void)
{
	//Download JSON-Datei
	URLDownloadToFile(NULL, (LPCWSTR) JSONFILE, lFILENAME, NULL, NULL);
	//Lese json-Datei 
	std::string buffer;
	std::ifstream in( FILENAME );
    copy( std::istreambuf_iterator< char >( in ), std::istreambuf_iterator< char >(), back_inserter( buffer ) );
	
	JSONValue *value = JSON::Parse(buffer.c_str());
	JSONObject root;
	JSONObject child;
	JSONArray jarr;

	root = value->AsObject();

	if (root.find(L"forecast") != root.end() && root[L"forecast"]->IsObject())
	{
		root = root[L"forecast"]->AsObject();
		root = root[L"simpleforecast"]->AsObject();
		jarr = root[L"forecastday"]->AsArray();

		root = jarr[0]->AsObject();
		child = root[L"high"]->AsObject();
		this->max = child[L"celsius"]->AsString().c_str(),5;

		child = root[L"low"]->AsObject();
		this->min = child[L"celsius"]->AsString().c_str(),5;

		this->cond = root[L"conditions"]->AsString().c_str(),30;

		child = root[L"avewind"]->AsObject();
		this->wind = child[L"kph"]->AsNumber();

		this->wdir = child[L"dir"]->AsString().c_str(),20;

		this->luft = root[L"avehumidity"]->AsNumber();
	}
}

char* WeatherUnderground::maxDayTempC()
{
	char ma [5];
	wcstombs(ma, this->max.c_str(),5);
	return ma;
}

std::wstring WeatherUnderground::maxDayTempW()
{
	return this->max;
}

char* WeatherUnderground::minDayTempC()
{
	char mi [5];
	wcstombs(mi, this->min.c_str(),5);
	return mi;
}

std::wstring WeatherUnderground::minDayTempW()
{
	return this->min;
}

char* WeatherUnderground::conditionC()
{
	char mi [30];
	wcstombs(mi, this->cond.c_str(),30);
	return mi;
}

std::wstring WeatherUnderground::conditionW()
{
	return this->cond;
}

std::wstring WeatherUnderground::windSpeed()
{
	wchar_t buffer[256];
	std::wstring s;
	int slen;

	slen = swprintf(buffer, 255, L"%f", this->wind);
	s.assign(buffer, slen);
	return s;
}

char* WeatherUnderground::windDirectionC()
{
	char mi [20];
	wcstombs(mi, this->wdir.c_str(),20);
	return mi;
}

std::wstring WeatherUnderground::windDirectionW()
{
	return this->wdir;
}

std::wstring WeatherUnderground::humidity()
{
	wchar_t buffer[256];
	std::wstring s;
	int slen;

	slen = swprintf(buffer, 255, L"%f", this->luft);
	s.assign(buffer, slen);
	return s;
}