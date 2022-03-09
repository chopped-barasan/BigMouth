#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>

namespace AccelarationTableGenerator {
namespace daikei {
constexpr float velocity(const float t,
                         const float accelaration,
                         const float v_final) {
  return accelaration * t;
}

template <std::size_t... Args>
constexpr std::array<float, sizeof...(Args)> _make_array(
    const float&& accelaration,
    const float&& v_final,
    const float&& dt_msec,
    typename std::integer_sequence<std::size_t, Args...>) {
  return {{velocity(dt_msec * 0.001 * Args, accelaration, v_final)...}};
}

template <int accelaration, int v_final, int dt_msec>
constexpr auto generate() {
  constexpr auto calculateIndexNumberFromTemplateParameters =
      []() -> std::size_t { return 1000.0 * v_final / accelaration; };
  return _make_array(
      accelaration, v_final, dt_msec,
      std::make_integer_sequence<
          std::size_t, calculateIndexNumberFromTemplateParameters() + 1>{});
}
}  // namespace daikei
}  // namespace AccelarationTableGenerator

namespace Table {
constexpr auto translation =
    AccelarationTableGenerator::daikei::generate<1250, 500, 1>();  // mm / sec
constexpr auto rotation =
    AccelarationTableGenerator::daikei::generate<100, 10, 1>();  // rad / sec
}  // namespace Table

namespace {
constexpr auto Offset = 20.0f;
constexpr auto SectionLength = 180.0f;
constexpr auto V = 500.0f;
constexpr auto Dt = 0.001f;
}  // namespace

constexpr bool inBoundOfTable(int p) {
  return p < (int)Table::rotation.size();
}

double theta(unsigned int index) {
  auto omega = [](decltype(index) t) { return Table::rotation[t]; };
  constexpr auto tableMaxIndex = Table::rotation.size() - 1;

  const auto t = index * Dt;
  double th = 0;

  if (inBoundOfTable(index)) {
    th = 1.0 / 2 * omega(index) * t;  // 加速区間のみの積分
  } else {
    const auto omega_final = Table::rotation.back();
    const auto t_final = tableMaxIndex * Dt;
    th = 1.0 / 2 * omega_final * t_final;  // 加速区間を全て積分
    th += omega_final * (t - t_final);     // 定速区間の積分を加算
  }
  return th;
}

int main() {
  std::ofstream ofs_clothoid("clothoid.txt");
  std::ofstream ofs_arc("arc.txt");

  struct {
    float x, y;
  } pos = {0, -SectionLength / 2 + Offset};
  ofs_clothoid << 0.0f << "\t" << -SectionLength / 2 << std::endl;

  unsigned int steps = 0;
  double tanValue;
  do {
    auto radToDeg = [](float x) { return x / 3.14f * 180; };
    const char* message = inBoundOfTable(steps) ? "クロソイド区間" : "円弧区間";

    tanValue = radToDeg(atan2f(SectionLength / 2 - Offset + pos.y,
                               SectionLength / 2 - Offset - pos.x));
    if (inBoundOfTable(steps)) {
      ofs_clothoid << pos.x << "\t" << pos.y << std::endl;
    } else {
      ofs_arc << pos.x << "\t" << pos.y << std::endl;
    }

    std::cerr << "Step: " << steps << ", " << message << std::endl;
    pos.x += V * sin(theta(steps)) * Dt;
    pos.y += V * cos(theta(steps)) * Dt;
    steps++;
  } while (tanValue <= 45.0f);
  fprintf(stderr, "translation accel time length: %lu[msec]\n",
          Table::translation.size());
  fprintf(stderr, "clothoid time length: %lu[msec]\n", Table::rotation.size());
  fprintf(stderr, "arc curve time length: %lu[msec]\n",
          steps - Table::rotation.size());

  return 0;
}
