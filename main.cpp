#include "CTestClasses.hpp"
#include "Calc.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(RSATest1, Subtest_1) { // ASSERT_TRUE(1 == 1);

  Calc calculator;

  calculator.createRSAKeyPair();
  unsigned long int test1 = calculator.encryptRSA(2);
  for (int i = 1; i < 100; i++) {
    unsigned long int m = i;
    std::cout << "\nnr = " << m;
    unsigned long int o = calculator.encryptRSA(m);
    std::cout << "   Encrypted = " << o;
    unsigned long int a = calculator.decryptRSA(o);
    std::cout << "   Decrypted = " << a;
    ASSERT_TRUE(m == a);
  }
}
#if 0

TEST(Testmynumber, DISABLED_Subtest_2) {
  int testNumber = 123456789;
  int testFactors1[] = {1,     3,     9,     3607,     3803,     10821,
                        11409, 32463, 34227, 13717421, 41152263, 123456789};
  Calc calculator;
  calculator.findAllFactors(testNumber);
  calculator.printAllFactors(testNumber);
  std::cout << "\n" << std::endl;
  // compare array with test array
  for (int i = 0; i < 1; i++) {
    if (calculator.factors[i] != testFactors1[i]) {
   //   ASSERT_FALSE(1 == 0);
    }
  }
  //ASSERT_TRUE(1 == 1);
}
#endif
// https://www.tutorialspoint.com/how-is-rsa-algorithm-calculated
int main(int argc, char **argv) {
  testing::InitGoogleTest();
  std::cout << "\nhW" << std::endl;

  Calc calculator;

  
  calculator.createRSAKeyPair();
  calculator.printCalculatedKeypair();
  unsigned long int m = 33;
  std::cout<<"\n~~~ test m= "<<m<<std::endl;
  std::cout<<"TEST ENCRYPT: "<<calculator.encryptRSA(m);
unsigned long int test1= calculator.encryptRSA(m);

  std::cout<<"\nTEST DECRYPT: "<<calculator.decryptRSA(test1);
  return RUN_ALL_TESTS();
}