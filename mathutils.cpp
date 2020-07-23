#include "mathutils.h"


float MathUtils::normalize_0_1(float value, float minValue, float maxValue)
{
    return (value - minValue) / (maxValue - minValue);
}
