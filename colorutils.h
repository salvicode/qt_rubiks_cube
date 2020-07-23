#ifndef COLORUTILS_H
#define COLORUTILS_H

class QColor;
class ColorUtils
{
public:
    static const int RGB_MIN;
    static const int RGB_MAX;
    static void qColorToRGB_0_1(const QColor &color, float &r, float &g, float &b);
};

#endif // COLORUTILS_H
