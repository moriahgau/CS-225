#include "Image.h"
#include "StickerSheet.h"

int main() {
  Image base, sticker_1, sticker_2, sticker_3;
  base.readFromFile("bobabear.png");
  sticker_1.readFromFile("icecream.png");
  sticker_2.readFromFile("gudetama.png");
  sticker_3.readFromFile("pusheen.png");
  StickerSheet final(base, 7);
  final.addSticker(sticker_1, 10,10);
  final.addSticker(sticker_2, 720,750);
  final.addSticker(sticker_3, 10,750);
  Image outputted = final.render();
  outputted.writeToFile("myImage.png");


  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}
