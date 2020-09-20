


## Score: 13/45 (28.89%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part1.cpp -o .objs/tests/tests-part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part2.cpp -o .objs/tests/tests-part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/Image.o .objs/StickerSheet.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-part1.o .objs/tests/tests-part2.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - Image lighten() lightens pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image lighten() does not lighten a pixel above 1.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) darkens pixels by 0.2

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) does not darken a pixel below 0.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image saturate() saturates a pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) rotates the color

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) keeps the hue in the range 0..360

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2.0) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✗ - [0/1] - Image scale(10000\, 200) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.width() * 2 == result.width()
Expanded: 720 (0x2d0) == 10000 (0x2710)
```


### ✗ - [0/1] - Image scale(720\, 10000) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.height() * 2 == result.height()
Expanded: 200 == 10000 (0x2710)
```


### ✗ - [0/1] - Image scale(240\, 50) results in the correct width/height

- **Points**: 0 / 1


```
Fatal Error: SIGFPE - Floating point error signal
```


### ✗ - [0/1] - Image scale(180\, 80) results in the correct width/height

- **Points**: 0 / 1


```
Fatal Error: SIGFPE - Floating point error signal
```


### ✗ - [0/1] - Image scale(10000\, 200) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Original: result.getPixel(100, 100).h > 40
Expanded: 3.0 > 40
```


### ✓ - [1/1] - Image scale(720\, 10000) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✗ - [0/1] - Image scale(240\, 50) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Fatal Error: SIGFPE - Floating point error signal
```


### ✗ - [0/1] - Image scale(180\, 80) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Fatal Error: SIGFPE - Floating point error signal
```


### ✗ - [0/5] - A basic StickerSheet works

- **Points**: 0 / 5


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() does not discard stickers when resized larger

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() does not discard original stickers when resized smaller

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() can increase the number of stickers on an image

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() discards stickers beyond the end of a smaller StickerSheet

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove the last sticker

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove the first sticker

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove all stickers

- **Points**: 0 / 1


```
Original: sheet.render() == alma
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✗ - [0/1] - StickerSheet::getSticker() returns the sticker

- **Points**: 0 / 1


```
Original: *(sheet.getSticker(0)) == i
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=226, h=327, hash=38817995cfe863)
```


### ✗ - [0/1] - StickerSheet::getSticker() returns NULL for a non-existant sticker

- **Points**: 0 / 1


```
Original: sheet.getSticker(1) == __null
Expanded: 0x00000000018da160 == 0
```


### ✗ - [0/1] - StickerSheet::getSticker() returns NULL for a removed sticker

- **Points**: 0 / 1


```
Original: sheet.getSticker(0) == __null
Expanded: 0x00000000022bb160 == 0
```


### ✗ - [0/1] - StickerSheet::translate() translates a sticker's location

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✓ - [1/1] - StickerSheet::translate() returns false for a non-existant sticker

- **Points**: 1 / 1





### ✗ - [0/5] - A complex StickerSheet is correct

- **Points**: 0 / 5


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3fa48f43ec5ef17d)
```


### ✗ - [0/2] - StickerSheet's copy constructor makes an independent copy

- **Points**: 0 / 2


```
Original: s1.render() == expected2
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


### ✗ - [0/2] - StickerSheet's assignment operator makes an independent copy

- **Points**: 0 / 2


```
Original: s1.render() == expected2
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


---

This report was generated for **mgau2** using **61dbe099d32fbcc3bcc9a108d4e8e7b354479403** (from **September 20th 2020, 12:00:25 am**)
