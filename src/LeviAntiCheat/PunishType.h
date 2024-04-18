#pragma once

namespace lac::punish {

enum class PunishType {
    Warning = 0, //
    Mute    = 1,
    Kick    = 2,
    Ban     = 3,
    Cancel  = 4,
    None    = 5
};

}
