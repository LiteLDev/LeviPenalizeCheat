#pragma once
#include "CheckType.h"
#include "PunishType.h"
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/player/PlayerEvent.h"


namespace lac::punish {

using ExtraInfo = std::
    unordered_map<std::string, std::variant<std::string, int, unsigned long long, long long, std::string_view, float>>;

class PlayerCheatEvent final : public ll::event::Cancellable<ll::event::PlayerEvent> {
public:
    CheckType const&  mCheatType;
    ExtraInfo const&  mExtraData;
    int const&        mDuration;
    PunishType const& mType;
};

} // namespace lac::punish
