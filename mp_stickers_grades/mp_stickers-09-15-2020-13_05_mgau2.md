


## Score: 11/19 (57.89%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part1.cpp -o .objs/tests/tests-part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part2.cpp -o .objs/tests/tests-part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/Image.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-part1.o .objs/tests/tests-part2.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

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
[Process timed out]
```
```
Unable to Grade (ETIMEDOUT): Your code did not finish within 10000ms.
```


### ✗ - [0/1] - Image scale(240\, 50) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.width() * 0.5 == result.width()
Expanded: 180.0 == 240
```


### ✗ - [0/1] - Image scale(180\, 80) results in the correct width/height

- **Points**: 0 / 1


```
Original: img.height() * 0.5 == result.height()
Expanded: 50.0 == 80
```


### ✗ - [0/1] - Image scale(10000\, 200) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Original: result.getPixel(100, 100).h < 60
Expanded: 100.0 < 60
```


### ✗ - [0/1] - Image scale(720\, 10000) scales pixel data in a reasonable way

- **Points**: 0 / 1

```
[Process timed out]
```
```
Unable to Grade (ETIMEDOUT): Your code did not finish within 10000ms.
```


### ✗ - [0/1] - Image scale(240\, 50) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Original: result.getPixel(100, 20).h > 180
Expanded: 100.0 > 180
```


### ✗ - [0/1] - Image scale(180\, 80) scales pixel data in a reasonable way

- **Points**: 0 / 1


```
Original: result.getPixel(100, 20).h > 180
Expanded: 100.0 > 180
```


---

This report was generated for **mgau2** using **aa652c78197a090682e74484c732df06f3d6bf8c** (from **September 15th 2020, 1:05:57 pm**)
