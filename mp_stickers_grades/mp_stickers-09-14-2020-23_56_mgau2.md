


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
tests/tests-part2.cpp:13:16: fatal error: no matching constructor for initialization of 'StickerSheet'
  StickerSheet sheet(alma, 5);
               ^     ~~~~~~~
tests/../StickerSheet.h:6:7: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
class StickerSheet{
      ^
tests/../StickerSheet.h:6:7: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
tests/../StickerSheet.h:6:7: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
1 error generated.
make: *** [.objs/tests/tests-part2.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part1.cpp -o .objs/tests/tests-part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part2.cpp -o .objs/tests/tests-part2.o

```


---

This report was generated for **mgau2** using **aa652c78197a090682e74484c732df06f3d6bf8c** (from **September 14th 2020, 11:56:24 pm**)
