#pragma once


struct color_t {
    uint8_t r,g,b,a;
    color_t () {r=g=b=0;a=1;}
    color_t (uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};