#pragma once

#include "Types.hpp"

namespace Pikachu {
class Motor {
 private:
  bool running, signalAbort;

 protected:
  /// ******************************
  /// @brief 回転が終了したときに継承クラスから呼び出します。
  ///
  /// ******************************
  inline void End() {
    running = false;
    signalAbort = false;
  }

  /// ******************************
  /// @brief 回転を開始します。
  ///        継承クラスにて環境依存のコードを含む具体的な処理を記述してください。
  ///
  /// @return Result 結果。
  /// ******************************
  virtual Result Start_(uint16_t distance,
                        uint16_t speed,
                        bool reverse = false) = 0;
  /// ******************************
  /// @brief 回転を中断します。
  ///        継承クラスにて環境依存のコードを含む具体的な処理を記述してください。
  ///
  /// ******************************
  virtual void Abort_() = 0;
  /// ******************************
  /// @brief 回転中に回転速度を変更します。
  ///        継承クラスにて環境依存のコードを含む具体的な処理を記述してください。
  ///
  /// @param speed 変更後の回転速度。
  /// ******************************
  virtual void ChangeSpeed_(uint16_t speed) = 0;

 public:
  /// ******************************
  /// @brief コンストラクタ。
  ///
  /// ******************************
  Motor() : running(true), signalAbort(true) {}
  /// ******************************
  /// @brief デストラクタ。
  ///
  /// ******************************
  virtual ~Motor() {}

  /// ******************************
  /// @brief 回転を開始します。
  ///        distanceを0に指定した場合、Abort()を呼び出すまで回転します。
  ///        speedは0より大きい値を指定してください。0以下の場合はResult::INVALID_SPEEDを返します。
  ///
  /// @param distance 回転距離（単位： mm）。
  /// @param speed 回転速度（単位： mm/s)。
  /// @param reverse 逆回転か否か。
  /// @return Result 結果。
  /// ******************************
  inline Result Start(uint16_t distance, uint16_t speed, bool reverse = false) {
    Result result;

    if (speed <= 0) {
      return Result::INVALID_SPEED;
    } else if (running) {
      return Result::RUNNING;
    }

    signalAbort = false;
    result = Start_(distance, speed, reverse);

    if (result == Result::SUCCESS) {
      running = true;
    }

    return result;
  }
  /// ******************************
  /// @brief 回転を中断します。
  ///        回転していない場合はResult::HALTEDを返します。
  ///
  /// @return Result 結果。
  /// ******************************
  inline Result Abort() {
    if (running == false) {
      return Result::HALTED;
    } else if (signalAbort) {
      return Result::ABORTING;
    }

    signalAbort = true;
    Abort_();

    return Result::SUCCESS;
  }
  /// ******************************
  /// @brief 回転速度を変更します。
  ///        回転中に回転速度を変更する場合に使用します。
  ///        回転していない場合はResult::NOT_STARTEDを返します。
  ///
  /// @param speed 変更後の回転速度（単位： mm/s)。
  /// @return Result
  /// ******************************
  inline Result ChangeSpeed(uint16_t speed) {
    if (speed <= 0) {
      return Result::INVALID_SPEED;
    } else if (running == false) {
      return Result::HALTED;
    } else if (signalAbort) {
      return Result::ABORTING;
    }

    ChangeSpeed_(speed);

    return Result::SUCCESS;
  }
  /// ******************************
  /// @brief 回転が終了したか確認します。
  ///        回転していない場合はResult::RUNNNINGを返します。回転している場合はResult::HALTEDを返します。
  ///
  /// @return Result 結果。
  /// ******************************
  inline Result CheckEnd() {
    if (running) {
      return Result::RUNNING;
    } else {
      return Result::HALTED;
    }
  }
};
}  // namespace Pikachu
