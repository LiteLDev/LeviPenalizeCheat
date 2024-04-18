#pragma once

namespace lac::punish {

enum class CheckType {
    IllegalMovement,
    Timer,
    Spam,
    InvalidFilterString,
    IllegalTrade,
    IllegalBreaking,
    FakeName,
    SpawnXpOrbs,
    Toolbox,
    AutoClick,
    Reach,
    InvalidNbtItem,
    InvalidAnvilEnchant,
    AutoOffhand,
    BanItem,
    InvalidEnchantLevel,
    InvalidGetItem,
    InvalidStackItem,
    MessageTooLong,
    CommandSpam,
    XpHack,
    NoPacket,
    BadPacket,
};

} // namespace lac::punish
