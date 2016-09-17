//=======================================================================
// Copyright Baptiste Wicht 2013-2016.
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://www.opensource.org/licenses/MIT)
//=======================================================================

#ifndef NET_ICMP_LAYER_H
#define NET_ICMP_LAYER_H

#include <types.hpp>
#include <expected.hpp>

#include "tlib/net_constants.hpp"

#include "net/network.hpp"
#include "net/ip_layer.hpp"

namespace network {

namespace icmp {

static_assert(sizeof(echo_request_header) == sizeof(header::rest), "Invalid size for echo request header");

void decode(network::interface_descriptor& interface, network::ethernet::packet& packet);

std::expected<network::ethernet::packet> kernel_prepare_packet(network::interface_descriptor& interface, const packet_descriptor& descriptor);
std::expected<network::ethernet::packet> user_prepare_packet(char* buffer, network::interface_descriptor& interface, const packet_descriptor* descriptor);

std::expected<void> finalize_packet(network::interface_descriptor& interface, network::ethernet::packet& p);

} // end of icmp namespace

} // end of network namespace

#endif
