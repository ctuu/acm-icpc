#include <algorithm>
#include <array>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define PI 3.141592657
#define EARTH_RADIUS 6371009
static inline double rad(double degree)
{
	return PI * degree / 180.0;
}
static inline double haverSin(double x)
{
	double v = sin(x / 2.0);
	return v * v;
}
//计算距离(单位 : m)
static double getDistance(double lon1, double lat1, double lon2, double lat2)
{
	double radlon1 = rad(lon1);
	double radlat1 = rad(lat1);
	double radlon2 = rad(lon2);
	double radlat2 = rad(lat2);

	double a = fabs(radlat1 - radlat2);
	double b = fabs(radlon1 - radlon2);

	double h = haverSin(b) + cos(lat1) * cos(lat2) * haverSin(a);
	double distance = 2 * EARTH_RADIUS * asin(sqrt(h));
	return distance;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	    int T;
    cin >> T;
    while (T--)
    {
        double lat1, lat2, lng1, lng2;
        cin >> lat1 >> lng1 >> lat2 >> lng2;
		cout << getDistance(lng1, lat1, lng2, lat2) << endl;
	}
	return 0;
}