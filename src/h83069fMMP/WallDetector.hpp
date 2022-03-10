#pragma once


#include "Types.hpp"


namespace Pikachu
{
  typedef struct
  {
    bool
      leftLeft,
      leftCenter,
      leftRight,
      rightLeft,
      rightCenter,
      rightRight,
      frontLeft,
      frontRight;
  } WallStatus;


  class WallDetector
  {
  public:
    /// ******************************
    /// @brief コンストラクタ。
    ///
    /// ******************************
    WallDetector()
    {}
    /// ******************************
    /// @brief デストラクタ。
    ///
    /// ******************************
    virtual ~WallDetector()
    {}

    /// ******************************
    /// @brief 壁検出モジュールの情報を取得します。
    ///
    /// @return WallStatus 結果。
    /// ******************************
    virtual void GetStatus(WallStatus &ws) = 0;
  };
}    // namespace Pikachu
