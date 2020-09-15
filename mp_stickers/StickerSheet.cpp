#include "StickerSheet.h"
using namespace cs225;


StickerSheet::StickerSheet(const Image &picture, unsigned max){};
StickerSheet::~StickerSheet(){};
StickerSheet::StickerSheet (const StickerSheet &other){};
const StickerSheet & StickerSheet::operator=(const StickerSheet &other){
    return *this;
};
void StickerSheet::changeMaxStickers(unsigned max){};
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
    int j = 0;
    return j;
};
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
    return 0;
};
void StickerSheet::removeSticker(unsigned index){};
Image* StickerSheet::getSticker(unsigned index){
    Image *image = new Image();
    return image;

};
Image StickerSheet::render()const{
    Image *image = new Image();
    return *image;
};
