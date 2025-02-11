#include "LeviPenalizeCheat/LeviPenalizeCheat.h"
#include "LeviAntiCheat/PlayerBanWaveEvent.h"
#include "LeviAntiCheat/PlayerCheatEvent.h"
#include "LeviAntiCheat/SusClientEvent.h"
#include "ll/api/event/EventBus.h"

#include "ll/api/mod/RegisterHelper.h"

namespace levi_pc {

LeviPenalizeCheat& LeviPenalizeCheat::getInstance() {
    static LeviPenalizeCheat instance;
    return instance;
}

bool LeviPenalizeCheat::load() {
    getSelf().getLogger().debug("Loading...");
    // Code for loading the mod goes here.
    return true;
}

bool LeviPenalizeCheat::enable() {
    getSelf().getLogger().debug("Enabling...");
    // Code for enabling the mod goes here.
    ll::event::EventBus::getInstance().emplaceListener<lac::punish::PlayerCheatEvent>(
        [&](lac::punish::PlayerCheatEvent& ev) {
            getSelf().getLogger().warn(
                "\"{}\" has been detected using: {}",
                ev.self().getRealName(),
                magic_enum::enum_name(ev.mCheatType)
            );
        }
    );
    ll::event::EventBus::getInstance().emplaceListener<lac::punish::PlayerBanWaveEvent>(
        [&](lac::punish::PlayerBanWaveEvent& ev) {
            getSelf().getLogger().warn("\"{}\" has been: {}", ev.self().getRealName(), magic_enum::enum_name(ev.mType));
        }
    );
    ll::event::EventBus::getInstance().emplaceListener<lac::punish::SusClientEvent>([&](lac::punish::SusClientEvent& ev
                                                                                    ) {
        getSelf().getLogger().warn("\"{}\" has been detected using suspicious client", ev.mName);
    });
    return true;
}

bool LeviPenalizeCheat::disable() {
    getSelf().getLogger().debug("Disabling...");
    // Code for disabling the mod goes here.
    return true;
}

} // namespace levi_pc

LL_REGISTER_MOD(levi_pc::LeviPenalizeCheat, levi_pc::LeviPenalizeCheat::getInstance());