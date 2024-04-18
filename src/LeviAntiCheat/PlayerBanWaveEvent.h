#pragma once
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/player/PlayerEvent.h"

namespace lac::punish {

enum class BanWaveType { Kick, Ban };

class PlayerBanWaveEvent final : public ll::event::Cancellable<ll::event::PlayerEvent> {
public:
    BanWaveType mType;
};

} // namespace lac::punish
