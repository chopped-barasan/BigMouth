#include <iostream>
#include <utility>

void g(int a, int b, int c) {
  std::cout << a << ", " << b << ", " << c << std::endl;
}

template <class T, T... Seq>
void f(std::integer_sequence<T, Seq...>) {
  // 定数のシーケンス{0, 1, 2}を取り出して、関数g()の引数として転送
  g(Seq...);
}

int main(void) {
  f(std::make_integer_sequence<uint16_t, 5>());

  return 0;
}
