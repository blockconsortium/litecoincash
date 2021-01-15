// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_POW_H
#define BITCOIN_POW_H

#include <consensus/params.h>

#include <stdint.h>

class CBlockHeader;
class CBlockIndex;
class uint256;
class CBlock;
class randomx_vm;   // LitecoinCash: fPOW

// LitecoinCash: Hive
struct BeePopGraphPoint {
    int immaturePop;
    int maturePop;
};

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params&);
unsigned int CalculateNextWorkRequired(const CBlockIndex* pindexLast, int64_t nFirstBlockTime, const Consensus::Params&);
unsigned int DarkGravityWave(const CBlockIndex* pindexLast, const Consensus::Params& params);                               // LitecoinCash: LCC (DGW) diff adjust implementation
unsigned int GetNextWorkRequiredLTC(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params&);   // LitecoinCash: LTC diff adjust implementation
unsigned int GetNextHiveWorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params);                       // LitecoinCash: Hive: Get the current Bee Hash Target
bool CheckHiveProof(const CBlock* pblock, const Consensus::Params& params);                                                 // LitecoinCash: Hive: Check the hive proof for given block
bool GetNetworkHiveInfo(int& immatureBees, int& immatureBCTs, int& matureBees, int& matureBCTs, CAmount& potentialLifespanRewards, const Consensus::Params& consensusParams, bool recalcGraph = false); // LitecoinCash: Hive: Get count of all live and gestating BCTs on the network

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params&);

// LitecoinCash: fPOW
bool IsRandomXLightInit();
void InitRandomXLightCache(const int32_t& height);
void KeyBlockChanged(const uint256& new_block);
void CheckIfKeyShouldChange(const uint256& check_block);
void DeallocateRandomXLightCache();
uint256 GetCurrentKeyBlock();
uint256 GetKeyBlock(const uint32_t& nHeight);
randomx_vm* GetMyMachineMining();
randomx_vm* GetMyMachineValidating();
bool CheckRandomXProofOfWork(const CBlockHeader& block, unsigned int nBits, const Consensus::Params& params);

#endif // BITCOIN_POW_H
