/// @brief This class provides calculation
/// @param factors contains all dividers of n

//https://www.cs.utexas.edu/~mitra/honors/soln.html
class Calc {
public:
  int factors[100];
  int amountOfFactors=0;
  int ph; // 
  int decryption_Key;
  int E; // encryption...
  //
  int publicKey[2];
  int privateKey[2];
  // ATTENTION
  /// @warning  needs to be corrected
  int p=7;
  int q=19;
  int N; // 
  // functions:
  void createRSAKeyPair();
  void findAllFactors(int n);
  void calculate_N();
  void calculate_E(int n);
  void calculate_DecryptionKey();
  void calculate_ph(int p, int q);
  void fillPrivateKey();
  void fillPublicKey();
  void fillKeysWithValues();

  bool isPrime(int number);
  //
   unsigned long int encryptRSA(unsigned long int m);
   unsigned long int decryptRSA(unsigned long int m);
   // status
   void printCalculatedKeypair();

   // getter setter
   int getEncyptionKey();
   int getDecryptionKey();

   void printAllFactors(int n = -1);
   void test();

 protected:
 private:
};