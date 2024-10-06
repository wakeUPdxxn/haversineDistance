#include <cmath>
#include <numbers>
#include <concepts>

template<typename T>
concept isFloating = std::is_floating_point<T>::value == true;

namespace Angle {
    template<isFloating T>
    T toRad(T value) {
        return value * (std::numbers::pi / 180);
    }
};

template<isFloating D>
D haversineDistCount(D lat1, D long1, D lat2, D long2)
{
    D R = D(6371);

    D lat_delta = Angle::toRad(lat2 - lat1);
    D long_delta = Angle::toRad(long2 - long1);

    D lat1_angle = Angle::toRad(lat1);
    D lat2_angle = Angle::toRad(lat2);

    D a = pow(sin(lat_delta / 2), 2)
        + cos(lat1_angle)
        * cos(lat2_angle)
        * pow(sin(long_delta / 2), 2);

    D c = 2 * atan2(sqrt(a), sqrt(1 - a));
    D result = R * c;

    return result;
}