
#include "Calc.hpp"
#include <iostream>
#include <math.h>
/// @brief This function should write all dividers of the given parameter into
/// its array
/// @details uses the modulo operator for division. It divides the paramet n
/// with all number up to the number itself. If there is a rest, the divider is
/// stored in an array.
/// @param[in] n the number for which the factors should be found
/// @return void
void Calc::findAllFactors(int n) {
  ///@note  Begins with dividing through 1, up  to the number itself.

  int countedFactors = 0;
  int nextFreeEmptyElementOfArray = 0;
  //
  for (int i = 1; i < n + 1; i++) {
    /// @note no rest available
    if (n % i == 0) {
      this->factors[nextFreeEmptyElementOfArray] = i;
      countedFactors++;
      nextFreeEmptyElementOfArray++;
    } else {
      /// @note rest available: means its not a factor
    }
  }
  this->amountOfFactors = countedFactors;
}
/// @brief  prints out all elements of factor[i]
/// @param n
void Calc::printAllFactors(int n) {
  if (n != -1) {
    std::cout << "\n~-- Factors for n=" << n << std::endl;
  } else {
    std::cout << "~-- Calculated Factors" << std::endl;
  }
  std::cout << "\n Total amount:" << this->amountOfFactors << std::endl;
  //
  for (int i = 0; i < this->amountOfFactors; i++) {

    std::cout << " " << this->factors[i];
  }
}
/// @brief
/*  Public Key:
   + It must be Prime
   + It must be less than the Totient
   + It must NOT be a factor of the Totient  (P-1)*(Q-1)
*/
/// @param n
void Calc::calculate_E(int n) {

  for (int i = 0 + 1; i < n + 1; i++) {
    if (n % i > 0 && isPrime(i)) {
      this->E = i;
      break;
    } else {
    }
  }
}

void Calc::calculate_ph(int p, int q) { this->ph = (p - 1) * (q - 1); }
int Calc::getEncyptionKey() { return this->E; }
/// @brief finds out the descryption key based on formula
void Calc::calculate_DecryptionKey() {

  // find out d x e
  for (int d = 0; d < this->ph + 1; d++) {
    if ((d * getEncyptionKey()) % this->ph == 1) {
      this->decryption_Key = d;
      break;
    } else {
    }
  }
}

void Calc::printCalculatedKeypair() {

  std::cout << " \n* Public Key: E = " << this->E << "|N=    " << this->N
            << std::endl;
  std::cout << " \n* Private Key: D = " << this->decryption_Key
            << "|N=  " << this->N << std::endl;
}

void Calc::fillPrivateKey() {
  this->privateKey[0] = this->E;
  this->privateKey[1] = this->p * this->q;
}
void Calc::fillPublicKey() {
  this->publicKey[0] = this->decryption_Key;
  this->publicKey[1] = this->p * this->q;
}

void Calc::fillKeysWithValues() {
  fillPrivateKey();
  fillPublicKey();
}
void Calc::calculate_N() { this->N = this->p * this->q; }

void Calc::createRSAKeyPair() {
  // random p,q .. here fixed
  calculate_N();

  //
  calculate_ph(p, q);
  // not actually needed
  findAllFactors(ph);
  printAllFactors(ph);
  // E is no factor of ph
  calculate_E(ph);
  // D
  calculate_DecryptionKey();
  std::cout << "\n* N=" << this->N << "  ph=" << this->ph;
}

/// @brief
/// @return
unsigned long int Calc::encryptRSA(unsigned long int m) {
  unsigned long int encrypted =
      (unsigned long int)pow(m, getEncyptionKey()) % (unsigned long int)this->N;
  return encrypted;
}
/// @brief
/// @return
unsigned long int Calc::decryptRSA(unsigned long int m) {
  unsigned long int decrypted =
      (unsigned long int)pow(m, decryption_Key) % (unsigned long int)this->N;
  return decrypted;
}
void Calc::test() {}
/// @brief 
/// @param number 
/// @return 
bool Calc::isPrime(int number) {
  for (int i= 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    } else {
      return true;
    }
  }
}