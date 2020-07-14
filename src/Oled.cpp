// 
// 수정 필요
// 

#include "Oled.h"

Oled::Oled() {
	//idisplay(4);
	idisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}


void Oled::display_character(const char* msg) {
	this->clear();
	uint16_t CURSOR_X = 0, CURSOR_Y = 5;
	uint8_t TEXTSIZE = 1;
	idisplay.setCursor(CURSOR_X, CURSOR_Y);  //텍스트를 디스플레이 중간에 표시
	idisplay.setTextSize(TEXTSIZE); //사이즈 조절
	idisplay.setTextColor(WHITE); //텍스트 color

	idisplay.print(msg);
}


// 그래픽 데이터 출력하는 함수
void Oled::display_graphic(const uint8_t* graphic_data) {
	this->clear();
	// 인자 순서대로: 가로위치, 세로위치, 그래픽데이터, 가로크기, 세로크기, 색상
	uint16_t pos_x = 32;  uint16_t pos_y = 0; // 위치
	uint16_t size_x = 64;  uint16_t size_y = 64; // 크기
	idisplay.drawBitmap(pos_x, pos_y, graphic_data, size_x, size_y, WHITE);
}

void Oled::clear() {
	idisplay.clearDisplay();
}

void Oled::show() {
	idisplay.display();
}


void Oled::temp() {
	idisplay.drawPixel(5, 5, 1);
	idisplay.drawPixel(10, 10, 1);
	idisplay.drawCircle(32, 32, 5, 1);
	idisplay.drawChar(20, 3, 'a', 1, 1, 1);
	idisplay.drawChar(26, 3, 'b', 1, 1, 1);
}


