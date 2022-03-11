#include "Mouse.hpp"

using namespace eommpsys;

void H8Mouse::SetStart(void) {
  state = WAITING;
  mov_con.PutDownCenterFlag();
}

Result H8Mouse::AutoPilot(SideDegiSens_t& current_pos) {
  static volatile uint16_t acc_count = 0;
  static uint64_t acc_start_time = 0;

  // while (true) {

  if (Time::GetCurrentTime() - acc_start_time > utils::ACCELE_DELTA_TIME) {
    acc_start_time = Time::GetCurrentTime();
    acc_count++;
  }

  switch (state) {
    // 待機状態(初期状態)
    // 加速時の変数の設定、前進命令
    // ACCELERATEに遷移
    case WAITING:
      state = START_REQUIRED;
      break;

    case START_REQUIRED:
      mov_con.Advance<utils::GRID_SIZE,
                      static_cast<uint16_t>(utils::MAX_SPEED *
                                            utils::ACCELE_TABLE[0])>();
      state = ACCELERATE;
      break;

    // 加速状態
    // 加速中。指定の時間間隔で加速。
    // CRUISEに遷移
    case ACCELERATE:
      mov_con.ChangeSpeed(utils::MAX_SPEED * utils::ACCELE_TABLE[acc_count]);
      // }
      if (acc_count >= utils::ACCELE_TABLE.size()) {
        state = CRUISE;
      }
      break;

    case CRUISE:
      if (current_pos.left == true) {
        if (current_pos.center == false) {
          mov_con.BackOnTrack(0.95f, EAST);
        } else {
          mov_con.BackOnTrack(0.97f, EAST);
        }
      } else if (current_pos.right == true) {
        if (current_pos.center == false) {
          mov_con.BackOnTrack(0.95f, WEST);
        } else {
          mov_con.BackOnTrack(0.97f, WEST);
        }

      } else {
        mov_con.ChangeSpeed(utils::MAX_SPEED);
      }

      if (mov_con.CheckEnd() == Result::HALTED) {
        mov_con.Advance<utils::GRID_SIZE, utils::MAX_SPEED>();
      }
      break;

    case STOP_REQURED:
      acc_count = utils::ACCELE_TABLE.size();
      state = DECELERATE;
      break;

    case DECELERATE:
      if (acc_count >= utils::ACCELE_TABLE.size()) {
        mov_con.ChangeSpeed(
            utils::MAX_SPEED *
            utils::ACCELE_TABLE[(utils::ACCELE_TABLE.size() * 2 - 1) -
                                acc_count]);
      }
      if (mov_con.CheckEnd() == HALTED) {
        state = STOPED;
      }
      break;

    case STOPED:
      mov_con.Brake();
      Time::Delay(150);
      mov_con.Stop();
      Time::Delay(50);
      state = TURN_REQUIRED;
      break;

    case TURN_REQUIRED:
      mov_con.Spinturn(utils::MAX_SPEED * 0.35f, next_dir);
      state = TURNING;
      break;

    case TURNING:
      if (mov_con.CheckEnd() == HALTED) {
        mov_con.Brake();
        Time::Delay(100);
        // mov_con.Stop();
        // Time::Delay(200);
        if (next_wall.left == 0 && next_wall.right == 0) {
          // state = START_REQUIRED;
          mov_con.Backward<50, 150>();
          state = KETSU;
        } else {
          mov_con.Backward<90, 150>();
          state = KETSU;
        }
      }
      break;

    case KETSU:
      if (mov_con.CheckEnd() == HALTED) {
        mov_con.Stop();
        Time::Delay(100);
        state = START_REQUIRED;
      }
      break;

    case REACHED:
      state = WAITING;
      mov_con.Stop();
      return Result::HALTED;
      break;

    default:
      return Result::UNKNOWN_ERROR;
  }

  if (mov_con.CheckEnd() == HALTED) {
    acc_count = 0;
  }
  // }

  return Result::SUCCESS;
}
