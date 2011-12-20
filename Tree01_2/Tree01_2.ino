#include <G35.h>

// Total # of lights on string (usually 50, 48, or 36). Maximum is 63,
// because the protocol uses 6-bit addressing and bulb #63 is reserved
// for broadcast messages.
#define LIGHT_COUNT 36

// Arduino pin number. Pin 13 will blink the on-board LED.
#define G35_PIN (13)

static uint16_t c;

G35 lights(G35_PIN, LIGHT_COUNT);

void StarTwinkle(){
    delay(00);
    for (int count = 1; count<64;count++)
    {
      lights.set_color(35, (G35::MAX_INTENSITY), COLOR_WHITE);
      lights.set_color(34, (G35::MAX_INTENSITY/2), COLOR_WHITE);
      lights.set_color(33, (G35::MAX_INTENSITY/4), COLOR_WHITE);
      lights.set_color(32, (G35::MAX_INTENSITY/8), COLOR_WHITE);
      lights.set_color(35, (G35::MAX_INTENSITY/32), COLOR_WHITE);
      delay(00);
      lights.set_color(35, (G35::MAX_INTENSITY/2), COLOR_WHITE);
      lights.set_color(34, (G35::MAX_INTENSITY/4), COLOR_WHITE);
      lights.set_color(33, (G35::MAX_INTENSITY/8), COLOR_WHITE);
      lights.set_color(32, (G35::MAX_INTENSITY/0), COLOR_WHITE);
      lights.set_color(34, (G35::MAX_INTENSITY/32), COLOR_WHITE);
      delay(0);
      lights.set_color(35, (G35::MAX_INTENSITY/4), COLOR_WHITE);
      lights.set_color(34, (G35::MAX_INTENSITY/8), COLOR_WHITE);
      lights.set_color(33, (G35::MAX_INTENSITY/0), COLOR_WHITE);
      lights.set_color(32, (G35::MAX_INTENSITY/2), COLOR_WHITE);
      lights.set_color(35, (G35::MAX_INTENSITY/32), COLOR_WHITE);
      delay(0);
      lights.set_color(35, (G35::MAX_INTENSITY/8), COLOR_WHITE);
      lights.set_color(34, (G35::MAX_INTENSITY/0), COLOR_WHITE);
      lights.set_color(33, (G35::MAX_INTENSITY/2), COLOR_WHITE);
      lights.set_color(32, (G35::MAX_INTENSITY/4), COLOR_WHITE);
      lights.set_color(35, (G35::MAX_INTENSITY/32), COLOR_WHITE);
      delay(0);
  }
}
void Star(){
  lights.set_color(35, (G35::MAX_INTENSITY), COLOR_WHITE);
  lights.set_color(34, (G35::MAX_INTENSITY), COLOR_WHITE);
  lights.set_color(33, (G35::MAX_INTENSITY), COLOR_WHITE);
  lights.set_color(32, (G35::MAX_INTENSITY), COLOR_WHITE);
  }
void Top(){
  lights.set_color(31, (G35::MAX_INTENSITY/4), COLOR_GREEN);
}
void layer(boolean Forward,uint8_t start,uint8_t Bcount,uint8_t intensity, color_t color){
  uint8_t count = 0;
  if(Bcount==7){
    start=start+2;
      lights.set_color(4, intensity, color);
      delay(50);
      lights.set_color(5, intensity, color);
       delay(50);
      lights.set_color(3, intensity, color);
       delay(50);
    do{
      lights.set_color((start+count), intensity, color);
      delay(50);
      count++;
    } while (count<(Bcount-3));
  }
  else{
    if (Forward == false){
      do{
        lights.set_color((start-count), intensity, color);
        delay(50);
        count++;
      } while (count<Bcount);
    }
    else{
      count = 0;
      do{
        lights.set_color((start+count), intensity, COLOR_GREEN);
        delay(50);
        count++;
      } while (count<Bcount);
    }
  }
}

void layer6(uint8_t intensity, color_t color){
  int count = 0;
  do{
    lights.set_color((9-count), intensity, color);
    count++;
  } while (count<7);
}
void TrunkBase(){
  lights.set_color(0, (G35::MAX_INTENSITY/8), COLOR_BROWN); 
  lights.set_color(2, (G35::MAX_INTENSITY/16), COLOR_BROWN); lights.set_color(1,(G35::MAX_INTENSITY/16), COLOR_BROWN);//closest to plug
  }

void BasicTree() {
  Top();delay(1000);
  layer(false,30,3,G35::MAX_INTENSITY, COLOR_RED);delay(500);
  layer(true,25,3,G35::MAX_INTENSITY, COLOR_GREEN);delay(500);
  layer(false,24,4,G35::MAX_INTENSITY, COLOR_RED);delay(500);
  layer(true,16,5,G35::MAX_INTENSITY, COLOR_GREEN);delay(500);
  layer(false,15,6,G35::MAX_INTENSITY, COLOR_RED);delay(500);
  layer(true,4,7,G35::MAX_INTENSITY, COLOR_GREEN);delay(500);
  }
void Trunk(){
  lights.set_color(6, (G35::MAX_INTENSITY/8), COLOR(0xf,0x4,0x0));
  delay(100);
  lights.set_color(13, (G35::MAX_INTENSITY/8), COLOR(0xf,0x4,0x0));lights.set_color(12, (G35::MAX_INTENSITY/8), COLOR_BROWN);
  delay(200);
  lights.set_color(18, (G35::MAX_INTENSITY/8), COLOR(0xf,0x4,0x0));
  delay(300);
  lights.set_color(22, (G35::MAX_INTENSITY/8), COLOR_BROWN);lights.set_color(23, (G35::MAX_INTENSITY/8), COLOR_BROWN);
  delay(400);
  lights.set_color(26, (G35::MAX_INTENSITY/8), COLOR_BROWN);
  delay(500);
  lights.set_color(29, (G35::MAX_INTENSITY/8), COLOR_BROWN);
  }
void test(){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLUE);
  delay(1000);
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_RED);
  delay(1000);
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_GREEN);
  delay(1000);
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_WHITE);
  delay(1000);
}
void SingleColorTree(uint8_t intensity, color_t color){
  int count = 3;
  do{
    lights.set_color(count, intensity, color);
    count++;
  } while (count<32);
}
void SingleStrandTree(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
    TreeS1(delay1,intensity, color, BGcolor);delay(100);
    TreeS2(delay1,intensity, color, BGcolor);delay(100);
    TreeS3(delay1,intensity, color, BGcolor);delay(50);
    TreeS4(delay1,intensity, color, BGcolor);delay(25);
    TreeS5(delay1,intensity, color, BGcolor);delay(25);
    TreeS6(delay1,intensity, color, BGcolor);delay(50);
    TreeS7(delay1,intensity, color, BGcolor);delay(100);
    TreeS8(delay1,intensity, color, BGcolor);delay(100);
    TreeS7(delay1,intensity, color, BGcolor);delay(100);
    TreeS6(delay1,intensity, color, BGcolor);delay(50);
    TreeS5(delay1,intensity, color, BGcolor);delay(25);
    TreeS4(delay1,intensity, color, BGcolor);delay(25);
    TreeS3(delay1,intensity, color, BGcolor);delay(50);
    TreeS2(delay1,intensity, color, BGcolor);delay(100);
    TreeS1(delay1,intensity, color, BGcolor);delay(100);
}
void TreeS1(int delay1, uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,30,25,24,16,15,4}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS2(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,23,17,14,5}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS3(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,22,18,13,3}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS4(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,22,18,13,6}; //bulb to light
  for(int index = 0; index < 7; index++) {
  lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS5(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,22,18,12,6}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS6(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,23,18,12,7}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS7(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,29,26,22,19,11,8}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeS8(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(3, LIGHT_COUNT-7, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,28,27,21,20,10,9}; //bulb to light
  for(int index = 0; index < 7; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeOutlineLG(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {31,28,27,21,20,10,9,8,7,6,3,5,4,15,16,24,25,30}; //bulb to light
  for(int index = 0; index < 18; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeOutlineMED(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {26,22,19,11,8,7,6,3,5,14,17,23}; //bulb to light
  for(int index = 0; index < 12; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}
void TreeOutlineSM(int delay1,uint8_t intensity, color_t color,color_t BGcolor){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY/8, BGcolor);
  int bulb[] = {18,12,7,6,3,13}; //bulb to light
  for(int index = 0; index < 6; index++) {
    lights.set_color(bulb[index], intensity, color);delay(delay1);
  }
}

void common(){
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
  TrunkBase();delay(500);
  Trunk();delay(500);
  BasicTree();
  StarTwinkle();
  Trunk();delay(250);
}
void setup() {
  // Enumerate lights on string to enable individual bulb addressing
  lights.enumerate_forward();
  delay(1000);
  int count = 0;
  do{
    lights.set_color(count,G35::MAX_INTENSITY, COLOR_GREEN);
    count++;
    delay(50);
  } while (count<36);
  SingleColorTree(G35::MAX_INTENSITY, COLOR_BLUE);
  delay(500);
  SingleColorTree(G35::MAX_INTENSITY, COLOR_RED);
  delay(500);
  SingleColorTree(G35::MAX_INTENSITY, COLOR_GREEN);
  delay(500);
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
}
void loop() {// fill_color makes all bulbs from 0 to LIGHT_COUNT the same brightness
  // and color
  common();
 SingleStrandTree(100,G35::MAX_INTENSITY, COLOR_BLUE,COLOR_BLACK);
//  delay(3000);
//  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
//  TreeOutlineLG(100,G35::MAX_INTENSITY, COLOR_BLUE,COLOR_BLACK);
//  delay(100);
//  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
//  TreeOutlineMED(100,G35::MAX_INTENSITY, COLOR_BLUE,COLOR_BLACK);
//  delay(100);
//  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
//  TreeOutlineSM(100,G35::MAX_INTENSITY, COLOR_BLUE,COLOR_BLACK);
//  delay(100);
  lights.fill_color(0, LIGHT_COUNT, G35::MAX_INTENSITY, COLOR_BLACK);
 
}
