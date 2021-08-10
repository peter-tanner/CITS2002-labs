
#include <stdbool.h>
#include <math.h>

#define TWO_PI (2*M_PI)
#define EARTH_RADIUS 6300000

double degrees_to_radians(double degrees) {
    return degrees/360*TWO_PI;
}

double radians_to_degrees(double radians) {
    return radians/TWO_PI*360;
}

bool valid_location(double latitude, double longitude) {
    return latitude > -90 && latitude <= 90
        && longitude > 0 && longitude <= 360;
}

double __sin_sqr_delta(double x1, double x2) {
    double x = sin( (x2-x1)/2 );
    return x*x;
}

double haversine(double latitude1, double longitude1, double latitude2, double longitude2) {
    double d = sqrt(__sin_sqr_delta(longitude1,longitude2) + cos(latitude1)*cos(latitude2)*__sin_sqr_delta(longitude1,longitude2));
    return 2*EARTH_RADIUS*asin(d);
}