// 
// ok
// 

#include "Led.h"
#include <Adafruit_NeoPixel.h>

// ������ �Լ�: led ����� ���� �ʱ�ȭ��
Led::Led(int a_numpixel, int a_pin) {
    numpixels = a_numpixel;
    PIN_LED = a_pin;
    strip = Adafruit_NeoPixel(numpixels, PIN_LED, NEO_GRB + NEO_KHZ800);
    strip.begin();
    set_brightness(150);
    strip.show();
} // note: �ڵ� ���� �ٲ��� �� ��.


// ��� ���� �Լ�
void Led::set_brightness(int x) {
    strip.setBrightness(x);
}


// ���� �Լ�
void Led::off() 
{
    const unsigned long user_delay = 1000;
    colorWipe(strip.Color(0, 0, 0), user_delay);
}


//���� ��Ÿ���� �Լ�
void Led::color(int* cock_color) 
{
    const unsigned long user_delay = 1000;
    colorWipe(strip.Color(cock_color[0], cock_color[1], cock_color[2]), user_delay);
}


//random_color()�� rainbow�� rainbowCycle �� �ϳ��� ����
void Led::random_color() 
{
    //rainbow();
    rainbowCycle();
}


void Led::temp() {
    //strip.clear();
    strip.setPixelColor(5, 255, 0, 0);
}



// ============ private ������ �Լ� ===============

//��� LED�� ��°����� �������� �ѹ��� �����ִ� ������ �ѹ� ����
void Led::rainbow() {
    const int user_delay = 20; //�ð��� �� ������� ����
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip.show();
        delay(user_delay);
    }
}

//NeoPixel�� �޸� LED�� ���� �ٸ������� �����Ͽ� �پ��� ������ 5�� �ݺ�
void Led::rainbowCycle() {
    const int user_delay = 20; //�ð��� �� ������� ����
    for (int j = 0; j < 256 * 5; j++) {
        for (int i = 0; i < numpixels; i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / numpixels) + j) & 255));
        }
        strip.show();
        delay(user_delay);
    }
}

void Led::colorWipe(uint32_t c, uint8_t wait) {
    for (uint16_t i = 0; i < numpixels; i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
}

uint32_t Led::Wheel(byte WheelPos) {
    if (WheelPos < 85) {
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    else if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else {
        WheelPos -= 170;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
}


