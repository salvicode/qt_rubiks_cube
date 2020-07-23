#include "colorutils.h"
#include <QColor>
#include "mathutils.h"

const int ColorUtils::RGB_MIN = 1;
const int ColorUtils::RGB_MAX = 255;

void ColorUtils::qColorToRGB_0_1(const QColor &color, float &r, float &g, float &b)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    r = MathUtils::normalize_0_1(red, RGB_MIN, RGB_MAX);
    g = MathUtils::normalize_0_1(green, RGB_MIN, RGB_MAX);
    b = MathUtils::normalize_0_1(blue, RGB_MIN, RGB_MAX);
}
