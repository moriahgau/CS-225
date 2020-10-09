


## Score: 121/121 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2_extra.cpp -o .objs/tests/test_part2_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part2.o .objs/tests/tests_part1.o .objs/tests/test_part2_extra.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [5/5] - List::reverse

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::reverseNth #2

- **Points**: 5 / 5





### ✓ - [10/10] - List::merge

- **Points**: 10 / 10

```
==91== Memcheck, a memory error detector
==91== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==91== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==91== Command: ./test -r xml "List::merge"
==91== 
==91== 
==91== HEAP SUMMARY:
==91==     in use at exit: 16 bytes in 1 blocks
==91==   total heap usage: 243,357 allocs, 243,356 frees, 79,517,865 bytes allocated
==91== 
==91== LEAK SUMMARY:
==91==    definitely lost: 0 bytes in 0 blocks
==91==    indirectly lost: 0 bytes in 0 blocks
==91==      possibly lost: 0 bytes in 0 blocks
==91==    still reachable: 16 bytes in 1 blocks
==91==         suppressed: 0 bytes in 0 blocks
==91== Reachable blocks (those to which a pointer was found) are not shown.
==91== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==91== 
==91== For counts of detected and suppressed errors, rerun with: -v
==91== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #1

- **Points**: 2 / 2

```
==93== Memcheck, a memory error detector
==93== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==93== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==93== Command: ./test -r xml "List::sort\ simple\ #1"
==93== 
==93== 
==93== HEAP SUMMARY:
==93==     in use at exit: 0 bytes in 0 blocks
==93==   total heap usage: 2,250 allocs, 2,250 frees, 276,576 bytes allocated
==93== 
==93== All heap blocks were freed -- no leaks are possible
==93== 
==93== For counts of detected and suppressed errors, rerun with: -v
==93== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #2

- **Points**: 2 / 2

```
==95== Memcheck, a memory error detector
==95== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==95== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==95== Command: ./test -r xml "List::sort\ simple\ #2"
==95== 
==95== 
==95== HEAP SUMMARY:
==95==     in use at exit: 0 bytes in 0 blocks
==95==   total heap usage: 2,250 allocs, 2,250 frees, 276,624 bytes allocated
==95== 
==95== All heap blocks were freed -- no leaks are possible
==95== 
==95== For counts of detected and suppressed errors, rerun with: -v
==95== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::sort #1

- **Points**: 5 / 5





### ✓ - [5/5] - List::sort #2

- **Points**: 5 / 5





### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==99== Memcheck, a memory error detector
==99== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==99== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==99== Command: ./test -r xml "List::insertFront\ size"
==99== 
==99== 
==99== HEAP SUMMARY:
==99==     in use at exit: 0 bytes in 0 blocks
==99==   total heap usage: 2,395 allocs, 2,395 frees, 281,176 bytes allocated
==99== 
==99== All heap blocks were freed -- no leaks are possible
==99== 
==99== For counts of detected and suppressed errors, rerun with: -v
==99== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==101== Memcheck, a memory error detector
==101== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==101== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==101== Command: ./test -r xml "List::insertBack\ size"
==101== 
==101== 
==101== HEAP SUMMARY:
==101==     in use at exit: 0 bytes in 0 blocks
==101==   total heap usage: 2,395 allocs, 2,395 frees, 281,176 bytes allocated
==101== 
==101== All heap blocks were freed -- no leaks are possible
==101== 
==101== For counts of detected and suppressed errors, rerun with: -v
==101== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==103== Memcheck, a memory error detector
==103== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==103== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==103== Command: ./test -r xml "List::insert\ contents"
==103== 
==103== 
==103== HEAP SUMMARY:
==103==     in use at exit: 0 bytes in 0 blocks
==103==   total heap usage: 2,391 allocs, 2,391 frees, 281,080 bytes allocated
==103== 
==103== All heap blocks were freed -- no leaks are possible
==103== 
==103== For counts of detected and suppressed errors, rerun with: -v
==103== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==105== Memcheck, a memory error detector
==105== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==105== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==105== Command: ./test -r xml "List::triplerotate\ basic"
==105== 
==105== 
==105== HEAP SUMMARY:
==105==     in use at exit: 0 bytes in 0 blocks
==105==   total heap usage: 2,399 allocs, 2,399 frees, 281,368 bytes allocated
==105== 
==105== All heap blocks were freed -- no leaks are possible
==105== 
==105== For counts of detected and suppressed errors, rerun with: -v
==105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==107== Memcheck, a memory error detector
==107== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==107== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==107== Command: ./test -r xml "List::triplerotate\ simple"
==107== 
==107== 
==107== HEAP SUMMARY:
==107==     in use at exit: 0 bytes in 0 blocks
==107==   total heap usage: 2,403 allocs, 2,403 frees, 281,464 bytes allocated
==107== 
==107== All heap blocks were freed -- no leaks are possible
==107== 
==107== For counts of detected and suppressed errors, rerun with: -v
==107== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==109== Memcheck, a memory error detector
==109== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==109== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==109== Command: ./test -r xml "List::split\ simple"
==109== 
==109== 
==109== HEAP SUMMARY:
==109==     in use at exit: 0 bytes in 0 blocks
==109==   total heap usage: 2,253 allocs, 2,253 frees, 276,648 bytes allocated
==109== 
==109== All heap blocks were freed -- no leaks are possible
==109== 
==109== For counts of detected and suppressed errors, rerun with: -v
==109== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==112== Memcheck, a memory error detector
==112== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==112== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==112== Command: ./test -r xml "List::_destroy\ empty\ list"
==112== 
==112== 
==112== HEAP SUMMARY:
==112==     in use at exit: 0 bytes in 0 blocks
==112==   total heap usage: 2,403 allocs, 2,403 frees, 282,008 bytes allocated
==112== 
==112== All heap blocks were freed -- no leaks are possible
==112== 
==112== For counts of detected and suppressed errors, rerun with: -v
==112== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==114== Memcheck, a memory error detector
==114== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==114== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==114== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==114== 
==114== 
==114== HEAP SUMMARY:
==114==     in use at exit: 0 bytes in 0 blocks
==114==   total heap usage: 2,407 allocs, 2,407 frees, 286,344 bytes allocated
==114== 
==114== All heap blocks were freed -- no leaks are possible
==114== 
==114== For counts of detected and suppressed errors, rerun with: -v
==114== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==116== Memcheck, a memory error detector
==116== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==116== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==116== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==116== 
==116== 
==116== HEAP SUMMARY:
==116==     in use at exit: 0 bytes in 0 blocks
==116==   total heap usage: 2,407 allocs, 2,407 frees, 288,744 bytes allocated
==116== 
==116== All heap blocks were freed -- no leaks are possible
==116== 
==116== For counts of detected and suppressed errors, rerun with: -v
==116== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==118== Memcheck, a memory error detector
==118== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==118== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==118== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==118== 
==118== 
==118== HEAP SUMMARY:
==118==     in use at exit: 0 bytes in 0 blocks
==118==   total heap usage: 2,407 allocs, 2,407 frees, 288,744 bytes allocated
==118== 
==118== All heap blocks were freed -- no leaks are possible
==118== 
==118== For counts of detected and suppressed errors, rerun with: -v
==118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==120== Memcheck, a memory error detector
==120== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==120== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==120== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==120== 
==120== 
==120== HEAP SUMMARY:
==120==     in use at exit: 0 bytes in 0 blocks
==120==   total heap usage: 2,407 allocs, 2,407 frees, 291,144 bytes allocated
==120== 
==120== All heap blocks were freed -- no leaks are possible
==120== 
==120== For counts of detected and suppressed errors, rerun with: -v
==120== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==122== Memcheck, a memory error detector
==122== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==122== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==122== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==122== 
==122== 
==122== HEAP SUMMARY:
==122==     in use at exit: 0 bytes in 0 blocks
==122==   total heap usage: 2,407 allocs, 2,407 frees, 286,344 bytes allocated
==122== 
==122== All heap blocks were freed -- no leaks are possible
==122== 
==122== For counts of detected and suppressed errors, rerun with: -v
==122== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==124== Memcheck, a memory error detector
==124== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==124== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==124== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==124== 
==124== 
==124== HEAP SUMMARY:
==124==     in use at exit: 0 bytes in 0 blocks
==124==   total heap usage: 2,407 allocs, 2,407 frees, 291,144 bytes allocated
==124== 
==124== All heap blocks were freed -- no leaks are possible
==124== 
==124== For counts of detected and suppressed errors, rerun with: -v
==124== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==126== Memcheck, a memory error detector
==126== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==126== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==126== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==126== 
==126== 
==126== HEAP SUMMARY:
==126==     in use at exit: 0 bytes in 0 blocks
==126==   total heap usage: 2,400 allocs, 2,400 frees, 283,776 bytes allocated
==126== 
==126== All heap blocks were freed -- no leaks are possible
==126== 
==126== For counts of detected and suppressed errors, rerun with: -v
==126== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==128== Memcheck, a memory error detector
==128== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==128== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==128== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==128== 
==128== 
==128== HEAP SUMMARY:
==128==     in use at exit: 0 bytes in 0 blocks
==128==   total heap usage: 2,400 allocs, 2,400 frees, 286,176 bytes allocated
==128== 
==128== All heap blocks were freed -- no leaks are possible
==128== 
==128== For counts of detected and suppressed errors, rerun with: -v
==128== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::reverse simple

- **Points**: 4 / 4

```
==130== Memcheck, a memory error detector
==130== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==130== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==130== Command: ./test -r xml "List::reverse\ simple"
==130== 
==130== 
==130== HEAP SUMMARY:
==130==     in use at exit: 0 bytes in 0 blocks
==130==   total heap usage: 2,256 allocs, 2,256 frees, 276,756 bytes allocated
==130== 
==130== All heap blocks were freed -- no leaks are possible
==130== 
==130== For counts of detected and suppressed errors, rerun with: -v
==130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::reverse edge cases

- **Points**: 2 / 2

```
==132== Memcheck, a memory error detector
==132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==132== Command: ./test -r xml "List::reverse\ edge\ cases"
==132== 
==132== 
==132== HEAP SUMMARY:
==132==     in use at exit: 0 bytes in 0 blocks
==132==   total heap usage: 2,401 allocs, 2,401 frees, 281,456 bytes allocated
==132== 
==132== All heap blocks were freed -- no leaks are possible
==132== 
==132== For counts of detected and suppressed errors, rerun with: -v
==132== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::reverseNth #3

- **Points**: 5 / 5

```
==134== Memcheck, a memory error detector
==134== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==134== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==134== Command: ./test -r xml "List::reverseNth\ #3"
==134== 
==134== 
==134== HEAP SUMMARY:
==134==     in use at exit: 0 bytes in 0 blocks
==134==   total heap usage: 2,262 allocs, 2,262 frees, 276,936 bytes allocated
==134== 
==134== All heap blocks were freed -- no leaks are possible
==134== 
==134== For counts of detected and suppressed errors, rerun with: -v
==134== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::merge #2

- **Points**: 5 / 5

```
==136== Memcheck, a memory error detector
==136== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==136== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==136== Command: ./test -r xml "List::merge\ #2"
==136== 
==136== 
==136== HEAP SUMMARY:
==136==     in use at exit: 16 bytes in 1 blocks
==136==   total heap usage: 2,292 allocs, 2,291 frees, 278,728 bytes allocated
==136== 
==136== LEAK SUMMARY:
==136==    definitely lost: 0 bytes in 0 blocks
==136==    indirectly lost: 0 bytes in 0 blocks
==136==      possibly lost: 0 bytes in 0 blocks
==136==    still reachable: 16 bytes in 1 blocks
==136==         suppressed: 0 bytes in 0 blocks
==136== Reachable blocks (those to which a pointer was found) are not shown.
==136== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==136== 
==136== For counts of detected and suppressed errors, rerun with: -v
==136== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::sort simple #3

- **Points**: 2 / 2

```
==138== Memcheck, a memory error detector
==138== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==138== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==138== Command: ./test -r xml "List::sort\ simple\ #3"
==138== 
==138== 
==138== HEAP SUMMARY:
==138==     in use at exit: 0 bytes in 0 blocks
==138==   total heap usage: 2,253 allocs, 2,253 frees, 276,688 bytes allocated
==138== 
==138== All heap blocks were freed -- no leaks are possible
==138== 
==138== For counts of detected and suppressed errors, rerun with: -v
==138== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==140== Memcheck, a memory error detector
==140== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==140== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==140== Command: ./test -r xml "List::insert\ contents\ #2"
==140== 
==140== 
==140== HEAP SUMMARY:
==140==     in use at exit: 0 bytes in 0 blocks
==140==   total heap usage: 2,406 allocs, 2,406 frees, 281,576 bytes allocated
==140== 
==140== All heap blocks were freed -- no leaks are possible
==140== 
==140== For counts of detected and suppressed errors, rerun with: -v
==140== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split edge cases

- **Points**: 5 / 5

```
==142== Memcheck, a memory error detector
==142== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==142== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==142== Command: ./test -r xml "List::split\ edge\ cases"
==142== 
==142== 
==142== HEAP SUMMARY:
==142==     in use at exit: 0 bytes in 0 blocks
==142==   total heap usage: 2,396 allocs, 2,396 frees, 281,240 bytes allocated
==142== 
==142== All heap blocks were freed -- no leaks are possible
==142== 
==142== For counts of detected and suppressed errors, rerun with: -v
==142== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::triplerotate hard

- **Points**: 2 / 2

```
==144== Memcheck, a memory error detector
==144== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==144== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==144== Command: ./test -r xml "List::triplerotate\ hard"
==144== 
==144== 
==144== HEAP SUMMARY:
==144==     in use at exit: 0 bytes in 0 blocks
==144==   total heap usage: 2,408 allocs, 2,408 frees, 281,624 bytes allocated
==144== 
==144== All heap blocks were freed -- no leaks are possible
==144== 
==144== For counts of detected and suppressed errors, rerun with: -v
==144== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate image

- **Points**: 10 / 10





---

This report was generated for **mgau2** using **1b5913bd9ec166ef0a0026e41f9dbc19335117fc** (latest commit as of **October 7th 2020, 7:00 am**)
