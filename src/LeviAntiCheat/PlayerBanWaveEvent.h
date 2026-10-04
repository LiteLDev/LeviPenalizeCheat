#pragma once
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/player/PlayerEvent.h"
#include <magic_enum.hpp>

namespace lac::punish {

enum class BanWaveType { Kick, Ban };

class PlayerBanWaveEvent final : public ll::event::Cancellable<ll::event::PlayerEvent> {
public:
    BanWaveType mType;

public:
    constexpr explicit PlayerBanWaveEvent(Player& player, BanWaveType type) : Cancellable(player), mType(type) {}

    void serialize(CompoundTag& nbt) const override {
        Cancellable::serialize(nbt);
        nbt["type"] = magic_enum::enum_name(mType);
    }
};

} // namespace lac::punish
