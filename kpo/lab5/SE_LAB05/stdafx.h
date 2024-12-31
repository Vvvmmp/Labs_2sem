#pragma once


#define TEST_CREATE_01(name) (strlen(name) > DICTNAMEMAXSIZE ? throw THROW01 : 0)
#define TEST_CREATE_02(size) (size > DICTMAXSIZE ? throw THROW02 : 0)
#define TEST_ADDENTRY_03(maxsize) (maxsize < inst.size ? throw THROW03 : 0)
#define TEST_ADDENTRY_04(id1) (id1 == ed.id ? throw THROW04 : 0)
#define TEST_GETENTRY_05() (throw THROW05)
#define TEST_DELENTRY_06(flag) (!flag ? throw THROW06 : 0)
#define TEST_UPDENTRY_07(flag) (!flag ? throw THROW07 : 0)
#define TEST_UPDENTRY_08(id1) (id1 == id ? THROW08 : 0)
//#define TEST_DICTIONARY(createCounter, size1, size2, printCounter) (createCounter == 2 && size1 >= 7 && size2 >= 7 && printCounter >= 2)