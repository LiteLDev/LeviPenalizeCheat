#pragma once
#include "CheckType.h"
#include "PunishType.h"
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/player/PlayerEvent.h"
#include <magic_enum.hpp>


namespace lac::punish {

using ExtraInfo = std::
    unordered_map<std::string, std::variant<std::string, int, unsigned long long, long long, std::string_view, float>>;

class PlayerCheatEvent final : public ll::event::Cancellable<ll::event::PlayerEvent> {
public:
    CheckType const&  mCheatType;
    ExtraInfo const&  mExtraData;
    int const&        mDuration;
    PunishType const& mType;

public:
    constexpr explicit PlayerCheatEvent(
        Player&           player,
        CheckType const&  cheatType,
        ExtraInfo const&  info,
        int const&        duration,
        PunishType const& punishType
    )
    : Cancellable(player),
      mCheatType(cheatType),
      mExtraData(info),
      mDuration(duration),
      mType(punishType) {}

    void serialize(CompoundTag& nbt) const override {
        Cancellable::serialize(nbt);
        nbt["check type"] = magic_enum::enum_name(mCheatType);
        for (auto& [name, value] : mExtraData) {
            std::visit([&](auto& value) -> void { nbt["extra data"][name] = value; }, value);
        }
        nbt["duration"]    = mDuration;
        nbt["punish type"] = magic_enum::enum_name(mType);
    }
};

} // namespace lac::punish
