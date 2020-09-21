#include "Image.h" //include the Image header file
using namespace cs225;

void Image::lighten(){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.l = pixel.l + 0.1;
           if (pixel.l>1)
                pixel.l = 1;
            else if(pixel.l <0)
                pixel.l = 0;
        }
    }

}
void Image::lighten(double amount){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.l = pixel.l + amount;
           if (pixel.l>1)
               pixel.l = 1;
            else if (pixel.l <0)
                pixel.l = 0;
        }
    }

}
void Image::darken(){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.l = pixel.l - 0.1;
           if (pixel.l>1)
               pixel.l = 1;
            else if (pixel.l <0)
                pixel.l = 0;
        }
    }
}
void Image::darken(double amount){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.l = pixel.l - amount;
           if (pixel.l>1)
               pixel.l = 1;
            else if (pixel.l <0)
                pixel.l = 0;
        }
    }
}
void Image::saturate(){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.s = pixel.s + 0.1;
           if (pixel.s>1)
               pixel.s = 1;
            else if (pixel.s <0)
                pixel.s = 0;
        }
    }
}
void Image::saturate(double amount){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.s = pixel.s + amount;
           if (pixel.s>1)
               pixel.s = 1;
            else if (pixel.s <0)
                pixel.s = 0;
        }
    }
}
void Image::desaturate(){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.s = pixel.s - 0.1;
           if (pixel.s>1)
               pixel.s = 1;
            else if (pixel.s <0)
                pixel.s = 0;
        }
    }
}
void Image::desaturate(double amount){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.s = pixel.s - amount;
           if (pixel.s>1)
               pixel.s = 1;
            else if (pixel.s <0)
                pixel.s = 0;
        }
    }
}
void Image::grayscale(){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.s = 0;
        }
    }   
}
void Image::rotateColor(double degrees){
    // unsigned int width = width();
    // unsigned int height = height();
    for(unsigned int x = 0; x < width(); x++){
        for(unsigned int y = 0; y < height(); y++){
           HSLAPixel & pixel = getPixel(x, y);
           pixel.h = pixel.h + degrees;
           if (pixel.h <0)
                pixel.h = pixel.h + 360;
            else if (pixel.h > 360)
                pixel.h = pixel.h - 360;
        }
    }
}
void Image::illinify(){
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & pixel = getPixel(x, y);
            if ((113.5 <= pixel.h) && (pixel.h <= 293.5))
                pixel.h = 216.0; // if within this range, turn into illini orange
            else
                pixel.h = 11.0; // otherwise change hue into illini blue
        }
    }
}
void Image::scale(double factor){
    // unsigned int width = width();
    // unsigned int height = height();
    // PNG oldImage = *this;
    // this->resize(oldImage->width() * factor, oldImage->height() * factor);
    // for (unsigned x = 0; x < this->width(); x++) {
    //     for (unsigned y = 0; y < this->height() * factor; y++) {
    //         HSLAPixel & pixel = oldImage.getPixel(x/factor, y/factor); 
    //         HSLAPixel & newpixel = getPixel(x,y);
    //         newpixel = pixel;
    PNG oldImage = PNG(*this);
    // std::cout<<"width"<< this->width()<< "height:" << this->height()<<std::endl;
    this->resize(oldImage.width() * factor, oldImage.height() * factor);
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & pixel = oldImage.getPixel(x/factor, y/factor); // so this shouldn't be x, y then?
            HSLAPixel & newpixel = getPixel(x,y);
            newpixel = pixel;
            
        }
    }
    
    
      
}

void Image::scale(unsigned w, unsigned h){
    Image oldImage = Image(*this);
    // resize(w, h);
    // for (unsigned x = 0; x < w; x++) {
    //     for (unsigned y = 0; y < h; y++) {
    //         HSLAPixel & pixel = oldImage.getPixel(x, y); 
    //         HSLAPixel & newpixel = getPixel(x*w,y*h);
    //         newpixel = pixel;
    //     }
    // }
    double newx  = w/oldImage.width();
    double newy = h/oldImage.height();
    double newz = w/h;
    this->resize(w, h);
    for (unsigned x = 0; x < w; x++) {
        for (unsigned y = 0; y < h; y++) {
            HSLAPixel & pixel = oldImage.getPixel(x/newx, y/newy)); 
            //adjusted line 192, test AG
            HSLAPixel & newpixel = getPixel(x,y);
            newpixel = pixel;
        }
    }
}


