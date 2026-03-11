/**
 * @file src/upnp.cpp
 * @brief Desktop-only build disables automatic UPnP port mapping.
 */

#include "logging.h"
#include "upnp.h"

namespace upnp {
  std::unique_ptr<platf::deinit_t> start() {
    BOOST_LOG(info) << "UPnP port mapping is disabled in desktop-only builds";
    return nullptr;
  }
}  // namespace upnp
