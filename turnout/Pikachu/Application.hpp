#include "Map.hpp"
#include "Motor.hpp"
#include "Mouse.hpp"
#include "Types.hpp"


namespace Pikachu
{
  class Application
  {
  private:
    static constexpr Cell     CELL_INITIALIZATION     = {};
    static constexpr Location LOCATION_INITIALIZATION = {};
    static constexpr uint8_t  MAP_SIZE_X              = 16;
    static constexpr uint8_t  MAP_SIZE_Y              = 16;
    static constexpr uint16_t SPEED                   = 200;

    static bool
      running;

    /// ******************************
    /// @brief コンストラクタ。
    ///
    /// ******************************
    Application()
    {}
    /// ******************************
    /// @brief デストラクタ。
    ///
    /// ******************************
    ~Application()
    {}

    /// ******************************
    /// @brief 座標を番号に変更します。
    ///
    /// @param location 座標。
    /// @return uint8_t 番号。
    /// ******************************
    inline uint8_t ConvertLocationToNumber(const Location &location) const
    {
      return (location.x * MAP_SIZE_X) + location.y;
    }
    /// ******************************
    /// @brief 座標を番号に変更します。
    ///
    /// @param location 座標。
    /// @return uint8_t 番号。
    /// ******************************
    inline uint8_t ConvertLocationToNumber(const Cell &cell) const
    {
      return (cell.location.x * MAP_SIZE_X) + cell.location.y;
    }

  public:
    Result Run(ExecutionMode mode, Motor &motorLeft, Motor &motorRight, WallDetector &wd);
  };
}    // namespace Pikachu
