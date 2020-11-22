---

This report was generated for **mgau2** using **a4d965f3a89cef5087c3efad59733df8f474e9f6** (latest commit as of **November 17th 2020, 6:00 am**)

---




## Score: 105/215 (48.84%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c dsets.cpp -o .objs/dsets.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c maze.cpp -o .objs/maze.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part1.cpp -o .objs/tests/test_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2.cpp -o .objs/tests/test_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/mazereader.cpp -o .objs/tests/mazereader.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/dsets.o .objs/maze.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/test_part1.o .objs/tests/test_part2.o .objs/tests/mazereader.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - addElements1

- **Points**: 10 / 10





### ✓ - [10/10] - addElements2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion1

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion3

- **Points**: 10 / 10





### ✓ - [5/5] - size1

- **Points**: 5 / 5





### ✓ - [10/10] - size2

- **Points**: 10 / 10





### ✗ - [0/10] - testMakeSmallMaze

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✗ - [0/10] - testMakeMazeConnected

- **Points**: 0 / 10


```
FAIL: Maze is not connected
```


### ✗ - [0/10] - testMakeMazeAcyclic

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✗ - [0/10] - testMakeMazeTree1000

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✓ - [10/10] - testMakeMazeRandom

- **Points**: 10 / 10





### ✗ - [0/10] - testSolveMazeValidPath

- **Points**: 0 / 10


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✗ - [0/10] - testSolutionBottomRow

- **Points**: 0 / 10


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✗ - [0/10] - testSolutionCorrectSquare

- **Points**: 0 / 10


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✗ - [0/10] - testSolveMazeSmall

- **Points**: 0 / 10

```
[Process timed out]
```
```
Unable to Grade (ETIMEDOUT): Your code did not finish within 20000ms.
```


### ✗ - [0/10] - testSolveMazeLarge

- **Points**: 0 / 10

```
[Process timed out]
```
```
Unable to Grade (ETIMEDOUT): Your code did not finish within 30000ms.
```


### ✓ - [10/10] - testDrawMazeSmall

- **Points**: 10 / 10





### ✓ - [10/10] - testDrawMazeMed

- **Points**: 10 / 10





### ✓ - [10/10] - testDrawMazeLarge

- **Points**: 10 / 10





### ✗ - [0/10] - testDrawSolutionMed

- **Points**: 0 / 10


```
Fatal Error: SIGABRT - Abort (abnormal termination) signal
```


### ✗ - [0/10] - testDrawSolutionLarge

- **Points**: 0 / 10

```
[Process timed out]
```
```
Unable to Grade (ETIMEDOUT): Your code did not finish within 30000ms.
```


---