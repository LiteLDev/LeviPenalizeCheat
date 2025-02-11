#pragma once
#include "ll/api/event/Cancellable.h"
#include "ll/api/event/Event.h"
#include "mc/platform/UUID.h"

#include <unordered_map>
#include <variant>

namespace lac::punish {

class SusClientEvent final : public ll::event::Cancellable<ll::event::Event> {
public:
    mce::UUID const&        mUuid;
    std::string_view const& mName;
    std::string_view const& mIp;

public:
    constexpr explicit SusClientEvent(mce::UUID const& uuid, std::string_view const& name, std::string_view const& ip)
    : mUuid(uuid),
      mName(name),
      mIp(ip) {}
};

} // namespace lac::punish
