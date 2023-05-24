#include "model/Pixel.h"

Pixel::Pixel() : red(0), green(0), blue(0), alpha(255) {}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : red(r), green(g), blue(b), alpha(a) {}

uint8_t Pixel::getRed() const {
    return red;
}

uint8_t Pixel::getGreen() const {
    return green;
}

uint8_t Pixel::getBlue() const {
    return blue;
}

uint8_t Pixel::getAlpha() const {
    return alpha;
}

void Pixel::setRed(uint8_t r) {
    red = r;
}

void Pixel::setGreen(uint8_t g) {
    green = g;
}

void Pixel::setBlue(uint8_t b) {
    blue = b;
}

void Pixel::setAlpha(uint8_t a) {
    alpha = a;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << "Pixel(: " << static_cast<int>(pixel.red) << ", g: " << static_cast<int>(pixel.green)
        << ", b: " << static_cast<int>(pixel.blue) << ", a: " << static_cast<int>(pixel.alpha) << ")";
    return os;
}