#pragma once
#include <cstdlib>
#include <filesystem>
#include <string>

namespace openskydimo
{

inline constexpr auto DEFAULT_SOCKET_PATH = "/run/openskydimo/openskydimo.sock";

inline std::string GetSocketPath()
{
    if (const char* override = std::getenv("OPENSKYDIMO_SOCKET"); override && *override)
        return override;

    return DEFAULT_SOCKET_PATH;
}

inline std::filesystem::path GetConfigPath()
{
    if (const char* override = std::getenv("OPENSKYDIMO_CONFIG"); override && *override)
        return override;

    if (const char* stateDir = std::getenv("STATE_DIRECTORY"); stateDir && *stateDir)
        return std::filesystem::path(stateDir) / "config.json";

    return "/var/lib/openskydimo/config.json";
}

} // namespace openskydimo
