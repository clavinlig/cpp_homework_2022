#include <iostream>
using namespace std;

// Набор целочисленных констант со значениями от 0 до n:
enum
{
	METRIC,			// 0 - Метрическая система
	BRIT,			// 1 - Британская система
	RUS,			// 2 - Старорусская система
	SYSTEMS_NUMBER	// 3 - Число систем
};

class length
{
private:
	float quantity[SYSTEMS_NUMBER];	// Массив значений величины в разных системах

	// Запись в другие системы:
	void recordToOtherSystems(float a, int system)
	{
		// Коэффициенты перевода:
		static float britToMetric = 0.3048;						// футы в метры
		static float rusToMetric = 0.1778;						// пяди в метры
		static float metricToBrit = 1 / britToMetric;				// метры в футы (3.2808)
		static float metricToRus = 1 / rusToMetric;				// метры в пяди (5.6243)
		static float britToRus = britToMetric * metricToRus;	// футы в пяди
		static float rusToBrit = rusToMetric * metricToBrit;	// пяди в футы

		switch (system)
		{
		case METRIC:
			quantity[BRIT] = a * metricToBrit;
			quantity[RUS] = a * metricToRus;
			break;

		case BRIT:
			quantity[METRIC] = a * britToMetric;
			quantity[RUS] = a * britToRus;
			break;

		case RUS:
			quantity[METRIC] = a * rusToMetric;
			quantity[BRIT] = a * rusToBrit;
			break;

		default:
			cout << "length->recordToOtherSystems: Wrong system number";
		}
	}

public:
	// Передать значение в определённой системе:
	void setQuantity(float a, int system)
	{
		if ((system >= METRIC) && (system < SYSTEMS_NUMBER))
		{
			quantity[system] = a;
			recordToOtherSystems(a, system);
		}
		else
		{
			cout << "length.setQuantity: Wrong system number";
		}
	}

	// Плучить значение в определённой системе:
	float getQuantity(int system)
	{
		if ((system >= METRIC) && (system < SYSTEMS_NUMBER))
		{
			return quantity[system];
		}
		else
		{
			cout << "length.setQuantity: Wrong system number";
			return 0;
		}
	}

	void printInAllSystems()
	{
		cout << " " << quantity[METRIC] << " meters" << endl;
		cout << " " << quantity[BRIT] << " foots" << endl;
		cout << " " << quantity[RUS] << " pyads" << endl;
	}
};

int main()
{
	float	xQuantity;
	int		nSystem;
	float	xMeter, xBrit, xRus;
	length	x;

	cout << "Write quantity: ";
	cin >> xQuantity;
	cout << "\n 0 - metric\n 1 - british\n 2 - old russian\n";

	cout << "\nWrite system: ";
	cin >> nSystem;

	if ((nSystem >= METRIC) && (nSystem < SYSTEMS_NUMBER))
	{

		x.setQuantity(xQuantity, nSystem);

		xMeter = x.getQuantity(METRIC);
		xBrit = x.getQuantity(BRIT);
		xRus = x.getQuantity(RUS);

		cout << "\nResult:" << endl;
		x.printInAllSystems();
	}
	else
	{
		cout << "\n Wrong input system number" << endl;
	}
}