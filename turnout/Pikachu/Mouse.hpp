#pragma once


#include "Motor.hpp"
#include "WallDetector.hpp"


namespace Pikachu
{
  class Mouse
  {
  private:
    Motor
      *motorLeft,
      *motorRight;
    WallDetector
      *wd;

  public:
    uint16_t
      distanceCell,
      distanceTireToTire;

  public:
    /// ******************************
    /// @brief コンストラクタ。
    ///
    /// ******************************
    Mouse()
    {
      motorLeft    = nullptr;
      motorRight   = nullptr;
      wd           = nullptr;
      distanceCell = 0;
    }
    /// ******************************
    /// @brief デストラクタ。
    ///
    /// ******************************
    ~Mouse()
    {
      motorLeft  = nullptr;
      motorRight = nullptr;
      wd         = nullptr;
    }

    /// ******************************
    /// @brief モータインスタンスとリンクします。
    ///
    /// @param left 左モータインスタンス。
    /// @param right 右モータインスタンス。
    /// ******************************
    inline void LinkMotor(Motor &left, Motor &right)
    {
      motorLeft  = &left;
      motorRight = &right;
    }
    /// ******************************
    /// @brief ウエスタンデジタルインスタンスとリンクします。
    ///
    /// @param wd ウエスタンデジタルインスタンス。
    /// ******************************
    void LinkWallDetector(WallDetector &wd)
    {
      this->wd = &wd;
    }
    /// ******************************
    /// @brief モータインスタンスとのリンクを解除します。
    ///
    /// ******************************
    inline void UnlinkMotor()
    {
      motorLeft  = nullptr;
      motorRight = nullptr;
    }
    /// ******************************
    /// @brief ウエスタンデジタルインスタンスとのリンクを解除します。
    ///
    /// ******************************
    inline void UnlinkWallDetector()
    {
      wd = nullptr;
    }

    /// ******************************
    /// @brief 前進します。
    ///
    /// @param speed 速度（単位： mm/s)。
    /// @return Result 結果。
    /// ******************************
    Result Advance(uint16_t speed);
    /// ******************************
    /// @brief 超信地旋回します。
    ///        機体の正面を北とします。
    ///        directionが北の場合は何もしません。
    ///        directionは北、南、西、東のみ有効です。それ以外の場合はResult::INVALID_DIRECTIONを返します。
    ///
    /// @param speed 速度（単位： mm/s)。
    /// @param direction 回転方向。
    /// @return Result 結果。
    /// ******************************
    Result Spinturn(uint16_t speed, Direction direction);
    /// ******************************
    /// @brief 半径を指定して曲線を描いて右左折します。
    ///        directionは西、東のみ有効です。それ以外の場合はResult::INVALID_DIRECTIONを返します。
    ///
    /// @param speed 速度（単位： mm/s)。
    /// @param direction 回転方向。
    /// @param radiusInner 回転軸と内輪の距離。
    /// @return Result 結果。
    /// ******************************
    Result Curve(uint16_t speed, Direction direction, uint16_t radius);
    /// ******************************
    /// @brief ピボットします。（片方のタイヤのみを回転させます。）
    ///        degreesが0の場合は何もしません。
    ///        軸はAxis.LEFT、Axis.RIGHTのみ有効です。それ以外の場合はResult::INVALID_AXISを返します。
    ///        degreesは0~360の範囲が有効です。範囲外の場合はResult::INVALID_DEGREESを返します。
    ///
    /// @param speed 速度（単位： mm/s)。
    /// @param axis 軸。
    /// @param dgrees 回転角度（単位：degrees）。
    /// @return Result 結果。
    /// ******************************
    Result Pivot(uint16_t speed, Axis axis, uint16_t degrees);
  };
}    // namespace Pikachu
