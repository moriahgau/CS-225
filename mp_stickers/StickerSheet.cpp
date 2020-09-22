#include "StickerSheet.h"
using namespace cs225;


StickerSheet::StickerSheet(const Image &picture, unsigned max){ //:basepicture(picture)
    basepicture = picture; //make a deep copy, but not sure why? should we just always deep copy? never shallow
    themax = max;
    stickers = new Image [max]; // ptr or not? 
    xposition = new unsigned[max];
    yposition = new unsigned[max];
    layer = new unsigned[max];
    for(unsigned i = 0; i < max; i++){ //not sure if this is necessary, since new makes all nullptrs and NULL? 

        xposition[i] = 0;
        yposition[i] = 0;
        layer[i] = 0;
    }

// Rule of three, wouldn't this be the same as copy?, do I think need another copy? 
};
StickerSheet::~StickerSheet(){
    // all the delete functions
    delete[] stickers;
    stickers = nullptr;
    delete[] xposition;
    xposition = nullptr;
    delete[] yposition;
    yposition = nullptr;
    delete[] layer;
    layer = nullptr;
};
StickerSheet::StickerSheet (const StickerSheet &other){
    basepicture = other.basepicture;
    stickers = new Image [themax]; // ptr or not? 
    xposition = new unsigned[themax];
    yposition = new unsigned[themax];
    layer = new unsigned[themax];
    for(unsigned i = 0; i < other.themax; i++){
        stickers[i] = other.stickers[i];
        xposition[i] = other.xposition[i];
        yposition[i] = other.yposition[i];
        layer[i] = other.layer[i];
    }
    //do i need to account for nullpointers?
    // Rule of three, wouldn't this be the same as copy?, do I think need another copy? 
};
const StickerSheet & StickerSheet::operator=(const StickerSheet &other){
    if(&other!= this){
        //dtor
        delete[] stickers;
        stickers = nullptr;
        delete xposition;
        xposition = nullptr;
        delete yposition;
        yposition = nullptr;
        //
        basepicture = other.basepicture;
        themax = other.themax;
        stickers = new Image[themax]; // ptr or not? 
        xposition = new unsigned[themax];
        yposition = new unsigned[themax];
        layer = new unsigned[themax];
        for(unsigned i = 0; i < other.themax; i++){
            stickers[i] = other.stickers[i];
            xposition[i] = other.xposition[i];
            yposition[i] = other.yposition[i];
            layer[i] = other.layer[i];
        }
    }
    return *this; // is this not the same as the constructor above? 
     //operator overload must destruct then copy
};
void StickerSheet::changeMaxStickers(unsigned max){
    if (themax == max)
        return; // do I need to check if the maxes are the same? 
    else{
        Image *tempSheet = new Image[max];
        unsigned *tempx = new unsigned[max];
        unsigned *tempy = new unsigned[max];
        unsigned *templayer = new unsigned[max];
        for(unsigned i = 0; i < max; i++){
            tempSheet[i] = stickers[i];
            tempx[i] = xposition[i];
            tempy[i] =  yposition[i];
            templayer[i] = layer[i];
        }
        delete[] stickers;
        stickers = tempSheet;
        delete[] xposition;
        xposition = tempx;
        delete[] yposition;
        yposition = tempy;
        delete[] layer;
        layer = templayer;
        themax = max;
    }

};
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
    for (unsigned i = 0; i < themax; i++){
        if (layer[i] == 0 ){
            stickers[i] = sticker; 
            xposition[i] = x; 
            yposition[i] = y;
            layer[i] = 1;
            return 1;
        } 
    }
    return -1;
};
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
    if(index < themax && layer[index] != 0){ 
        xposition[index] = x;
        yposition[index] = y;
        return true;
    }
    else 
        return false; 
};
void StickerSheet::removeSticker(unsigned index){
    if(index < themax && layer[index] != 0){
        layer[index] = 0;
    }
};
Image* StickerSheet::getSticker(unsigned index){
    if (index < themax && layer[index] == 1 )
        return &stickers[index];
    else
        return NULL;

};

Image StickerSheet::render()const{
    unsigned max_w = basepicture.width();
    unsigned max_h = basepicture.height();
    for(unsigned i = 0; i < themax; i++){
        unsigned w = xposition[i] + stickers[i].width();
        unsigned h = yposition[i] + stickers[i].height();
        if (w > max_w)
            max_w = w;
        if (h > max_h)
            max_h = h;
    }
    Image finalSheet = basepicture;
    Image *original = stickers;
    finalSheet.resize(max_w, max_h);
    for (unsigned j = 0; j < themax; j++){
        if(layer[j] ==1){
            for (unsigned x = 0; x < stickers[j].width(); x++) {
                for (unsigned y = 0; y < stickers[j].height(); y++) {
                    HSLAPixel & pixel = stickers[j].getPixel(x, y); 
                    HSLAPixel & newpixel = finalSheet.getPixel(xposition[j]+x,yposition[j]+y);
                    if(pixel.a != 0)
                        newpixel = pixel;
                }
            }
        }
    }  
    return finalSheet;  
};
