---

This report was generated for **mgau2** using **f20b76dd2ce3cbe6bf7bca0467f09f93a76d45b3** (latest commit as of **October 17th 2020, 6:05 pm**)

---




## Score: 40/50 (80.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/coloredout.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - test_find

- **Points**: 10 / 10

```
==56== Memcheck, a memory error detector
==56== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==56== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==56== Command: ./test -r xml "test_find"
==56== 
==56== 
==56== HEAP SUMMARY:
==56==     in use at exit: 0 bytes in 0 blocks
==56==   total heap usage: 1,667 allocs, 1,667 frees, 216,640 bytes allocated
==56== 
==56== All heap blocks were freed -- no leaks are possible
==56== 
==56== For counts of detected and suppressed errors, rerun with: -v
==56== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_insert_small

- **Points**: 5 / 5





### ✓ - [10/10] - test_insert_find

- **Points**: 10 / 10





### ✓ - [10/10] - test_insert_big

- **Points**: 10 / 10

```
==60== Memcheck, a memory error detector
==60== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==60== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==60== Command: ./test -r xml "test_insert_big"
==60== 
==60== 
==60== HEAP SUMMARY:
==60==     in use at exit: 0 bytes in 0 blocks
==60==   total heap usage: 1,693 allocs, 1,693 frees, 218,128 bytes allocated
==60== 
==60== All heap blocks were freed -- no leaks are possible
==60== 
==60== For counts of detected and suppressed errors, rerun with: -v
==60== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_remove_small

- **Points**: 5 / 5





### ✗ - [0/10] - test_remove_big

- **Points**: 0 / 10

```
==63== Memcheck, a memory error detector
==63== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==63== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==63== Command: ./test -r xml "test_remove_big"
==63== 
==63== 
==63== HEAP SUMMARY:
==63==     in use at exit: 56 bytes in 1 blocks
==63==   total heap usage: 1,706 allocs, 1,705 frees, 219,624 bytes allocated
==63== 
==63== 56 bytes in 1 blocks are definitely lost in loss record 1 of 1
==63==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==63==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==63==    by 0x4361A9: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::Node*&, int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:118)
==63==    by 0x436227: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::Node*&, int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:120)
==63==    by 0x436227: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::Node*&, int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:120)
==63==    by 0x436227: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::Node*&, int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:120)
==63==    by 0x436260: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::Node*&, int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:122)
==63==    by 0x4358B2: AVLTree<int, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >::insert(int const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&) (avltree.cpp:110)
==63==    by 0x4299B8: ____C_A_T_C_H____T_E_S_T____10() (tests.cpp:124)
==63==    by 0x46A422: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==63==    by 0x45AB76: Catch::TestCase::invoke() const (catch.hpp:10793)
==63==    by 0x45AAAC: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==63== 
==63== LEAK SUMMARY:
==63==    definitely lost: 56 bytes in 1 blocks
==63==    indirectly lost: 0 bytes in 0 blocks
==63==      possibly lost: 0 bytes in 0 blocks
==63==    still reachable: 0 bytes in 0 blocks
==63==         suppressed: 0 bytes in 0 blocks
==63== 
==63== For counts of detected and suppressed errors, rerun with: -v
==63== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

```



---