// Copyright (c) 2018 Karl-Johan Alm
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AIXCOIN_AIXDEB_SCRIPT_H
#define AIXCOIN_AIXDEB_SCRIPT_H

#include <script/script.h>

typedef void (*aix_logf_t) (const char *fmt...);
extern aix_logf_t aix_logf, aix_sighash_logf, aix_sign_logf, aix_segwit_logf, aix_taproot_logf;
extern bool aixdeb_verbose;
void aix_logf_dummy(const char* fmt...);
void aix_logf_stderr(const char* fmt...);
inline bool aix_enabled(aix_logf_t logger) { return logger != aix_logf_dummy; }

opcodetype GetOpCode(const char* name);
void GetStackFeatures(opcodetype opcode, size_t& spawns, size_t& slays);

#endif // AIXCOIN_AIXDEB_SCRIPT_H
