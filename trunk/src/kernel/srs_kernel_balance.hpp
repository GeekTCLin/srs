//
// Copyright (c) 2013-2024 The SRS Authors
//
// SPDX-License-Identifier: MIT
//

#ifndef SRS_KERNEL_BALANCE_HPP
#define SRS_KERNEL_BALANCE_HPP

#include <srs_core.hpp>

#include <vector>
#include <string>

/**
 * the round-robin load balance algorithm,
 * used for edge pull and other multiple server feature.
 * 负载均衡。。。。。
 */
class SrsLbRoundRobin
{
private:
    // current selected index.
    int index;
    // total scheduled count.   count 自增用于 取模计算
    uint32_t count;
    // current selected server.
    std::string elem;
public:
    SrsLbRoundRobin();
    virtual ~SrsLbRoundRobin();
public:
    virtual uint32_t current();
    virtual std::string selected();
    virtual std::string select(const std::vector<std::string>& servers);
};

#endif

