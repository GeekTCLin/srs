//
// Copyright (c) 2013-2024 The SRS Authors
//
// SPDX-License-Identifier: MIT
//

#ifndef SRS_KERNEL_AAC_HPP
#define SRS_KERNEL_AAC_HPP

#include <srs_core.hpp>

#include <string>

#include <srs_kernel_codec.hpp>

class SrsBuffer;
class ISrsStreamWriter;

// Transmux the RTMP packets to AAC stream.
// 将 RTMP packets 转换为 AAC ？
class SrsAacTransmuxer
{
private:
    ISrsStreamWriter* writer;
private:
    SrsAacObjectType aac_object_;
    int8_t aac_sample_rate_;
    int8_t aac_channels_;
    bool got_sequence_header_;
public:
    SrsAacTransmuxer();
    virtual ~SrsAacTransmuxer();
public:
    // Initialize the underlayer file stream.
    // @remark User can initialize multiple times to encode multiple aac files.
    // @remark User must free the fs, aac encoder never close/free it.
    virtual srs_error_t initialize(ISrsStreamWriter* fs);
public:
   // Write audio/video packet.
   // @remark The assert data should not be NULL.
    virtual srs_error_t write_audio(int64_t timestamp, char* data, int size);
};

#endif

