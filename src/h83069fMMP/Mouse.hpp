#include "MovementController.hpp"

namespace eommpsys {
class H8Mouse {
 private:
  static inline auto& wall_digsens =
      *reinterpret_cast<union un_degisens*>(H8Reg::addr_pbdr);
  H8MovementController mov_con;

  volatile MouseState state;

  Direction next_dir;

 public:
  H8Mouse() : state(WAITING), next_dir(NONE), next_wall({0}) {}
  ~H8Mouse() = default;

  Wall_t next_wall;

  inline void Init(H8Motor& left, H8Motor& right) {
    mov_con.LinkMotor(left, right);
  }
  void SetStart(void);
  Result AutoPilot(SideDegiSens_t& current_pos);

  inline DegiSens_t GetDegiSens(void) { return wall_digsens; }
  inline MouseState GetState(void) { return state; }
  inline void SetNextDir(Wall_t wall) {
    static bool dotti_ni_siyou_kana = true;
    if (wall.right == 0 && wall.left == 0) {
      next_dir = dotti_ni_siyou_kana ? WEST : EAST;
      dotti_ni_siyou_kana = !dotti_ni_siyou_kana;
    } else if (wall.left == 0) {
      next_dir = WEST;
    } else if (wall.right == 0) {
      next_dir = EAST;
    } else if (wall.back == 0) {
      next_dir = SOUTH;
    }
  }
  inline bool OnCenter(void) { return mov_con.OnCenter(); }
  inline void PutDownCenterFlag(void) { mov_con.PutDownCenterFlag(); }
  inline bool CheckFrontWall(void) {
    return (wall_digsens.F1 || wall_digsens.F2) && state != TURNING;
  }

  inline void Stop(void) { state = STOP_REQURED; }
};

}  // namespace eommpsys
