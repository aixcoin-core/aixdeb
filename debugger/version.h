// Copyright (c) 2020-2021 The Aixcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AIXCOIN_DEBUGGER_VERSION_H
#define AIXCOIN_DEBUGGER_VERSION_H

#include <config/aixcoin-config.h>

#ifdef AIXDEB_STR
#error "AIXDEB_STR already defined"
#endif

#define AIXDEB_STR(s) #s

#define _VERSION(maj, min, rev) AIXDEB_STR(maj) "." AIXDEB_STR(min) "." AIXDEB_STR(rev)
#define VERSION() _VERSION(CLIENT_VERSION_MAJOR, CLIENT_VERSION_MINOR, CLIENT_VERSION_REVISION)

#endif // AIXCOIN_DEBUGGER_VERSION_H
