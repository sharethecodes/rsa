class Animal
{
  public:
    void die();
    int name;
    int age;
};

class Dog : public Animal
{
  public:
    void bark();
};

class Cat : public Animal
{
  public:
    void meow();
};
