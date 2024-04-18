#include "LeviPenalizeCheat/LeviPenalizeCheat.h"
#include "LeviAntiCheat/PlayerCheatEvent.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"
#include "magic_enum.hpp"
#include <memory>

namespace lac {

static std::unique_ptr<LeviPenalizeCheat> instance;

LeviPenalizeCheat& LeviPenalizeCheat::getInstance() { return *instance; }

bool LeviPenalizeCheat::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the plugin goes here.
    return true;
}

bool LeviPenalizeCheat::enable() {
    auto& logger = getSelf().getLogger();
    getSelf().getLogger().info("Enabling...");
    ll::event::EventBus::getInstance().emplaceListener<lac::punish::PlayerCheatEvent>(
        [&](lac::punish::PlayerCheatEvent& ev) {
            logger.warn(
                "\"{}\" has been detected using: {}",
                ev.self().getRealName(),
                magic_enum::enum_name(ev.mCheatType)
            );
        }
    );
    return true;
}

bool LeviPenalizeCheat::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace lac

LL_REGISTER_PLUGIN(lac::LeviPenalizeCheat, lac::instance);
