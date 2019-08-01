// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2015-2017 The ALQO developers
// Copyright (c) 2018 The ZARHEXCASH developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>


using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"
#include "test/bignum.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x00000feb8ae2aaa7e734d875607e8710d2b6c9ed59dab09eb30f9d0e90c22114"))
	(1, uint256("0x00000bee1b0295c474e8287cdb2a786aebd51cda7e49839f9eac9208d6452b10"))
	(2, uint256("0x000000b8d4ed3aaf3ef1450cb2532d5c324c35d1fa94719df7e8e20e525c26d0"))
	(3, uint256("0x000006a09bf5f71da0d896cda2cb51ad87685d387713edd1bc86c85683cc0d54"))
	(4, uint256("0x00000d9460815fdbe07d6b30a2a37166e53af22d7e66c7acd08f3fdec14524b2"))
	(5, uint256("0x00000593362ac73dd7dc36e4acb5e0f68b11c52b489b936e7cc12fe716c417ce"))
	(6, uint256("0x000005782eae7bddc20751efafa00f1787b1fcb97d3c2255929cefc0893d9916"))
	(7, uint256("0x0000013555ca4c6d82483d8f425e417f0b15ecdbf827b66ab866b2e68408b01b"))
	(8, uint256("0x00000843a080c4b1d9cd98f23cd5842e25375bddec455e367b3b541dc068d55b"))
	(9, uint256("0x00000dd02a54a090212bf256d6eaabb79458d2d8c382125736b497c37c447e0a"))
	(10, uint256("0x0000064e4abaadd71c2ed158682f5e0bb652f9dc81ed9d8bba8f8ba647d34f5d"))
	(11, uint256("0x000002ff71c377369eb38d1967d40723c9b2d36e92ebecf07dc3eb3e0874f789"))
	(12, uint256("0x000003d8bdda28ca344f1e7aa1f78e8f7424d78d57412c5cae391fc87c0aa197"))
	(13, uint256("0x000000baa9069836a95f47fd9c2e3bb862b05b402cf4e232bcbc2f53526f402f"))
	(14, uint256("0x0000089432be8ba65c146f086afa08484831565a66d7f23f23c9eee0c95b5ff4"))
	(15, uint256("0x00000cf36b8920ab5c0e693d78991a7f8db9575e30547ec955ddce96650eeccb"))
	(16, uint256("0x0000009c8fc79e4e764999f65edccff94f757700fee3e9fa713e7bae7609421a"))
	(17, uint256("0x000000705b4d4836116cfaa6b628cb2487c69f7a6164eed0d748acf1201527e0"))
	(18, uint256("0x00000872d0893af13c69ba2d6543a4e551a3ac75f38f158b80b42032077db549"))
	(19, uint256("0x00000e532406724d30e2ce554e6c2464738bcb835f7f48813ca5614311023e9a"))
	(20, uint256("0x00000f674e4d420d19f8310121233ac51a46bf1b560a0fb8bbfd67f01744390d"))
	(21, uint256("0x00000db6e2d5cdb867f1ef04a0c178e03a7385c46affacc66430b106434ffcdf"))
	(22, uint256("0x000000c322b3027eecd628113ec90e1214ed49f54a57a52a2d4aecbc6ee5b601"))
	(23, uint256("0x0000029de18c69b4e4807ed6f0575e3036a6c8dcfdc445b1cf1781041e23a866"))
	(24, uint256("0x000006469e22c2d3932dc687b0e3ff2cb888db9fa0b0b3c6a55a116275b24906"))
	(25, uint256("0x000001722044b9f7a25f9e4ac73259dc858d464a433cf5e9b104147a678d94c6"))
	(26, uint256("0x0000056d4fbe108affc99b42736575f7562149371dbb4873efe3e98a0f372c5f"))
	(27, uint256("0x000002c0779825d48135fe37f4201da80b0be97c333570e104037bd5a540b628"))
	(28, uint256("0x000001d40031b43b887d059e11a051242396f41075b85399072b948ad80ecfcd"))
	(29, uint256("0x000005463131672b6408eee3dc81d55f5492ba22866e0bdcf56bcc9197c38f56"))
	(50, uint256("0x000002aa21fa72ef34459710497f1438eacd883241503d53fc3fa1990fef9f83"))
	(100, uint256("0x000000c8f43a9ed729ffebde89d7dba4be17923e0141f2d641dc2ba198d74274"))
	(200, uint256("0x00000087464680313978d3a9555bd9e894a7f635214e78f71a4098e1b36b1c69"))
	(300, uint256("0x0000004066ab5bc814e6c228f71b32f20c9b6797d90aa314d3e7550b9b3b1091"))
	(400, uint256("0x000000b68721abe2c1b7f3c52903ad8676597f3351f7329a1b8a21c4513e01d1"))
	(500, uint256("0x000000dcf6bf3f8ec5b448b44728667ddab97ecfd78405664dac2480d5a60e4c"))
	//1 Checkpoint set Complete 
	(600, uint256("0x00000010364080b31ff0d947fa0c6b36aeaada22544bf6862c6be48c0acbd848"))
	(700, uint256("0x000000dce0b91607921632e0c669442107e5679e1de6161857b3501e5fa68f5d"))
	(900, uint256("0x000000da3b1ee09bd690ac021c31ebbac245ec6de580df079dad56bcd568d596"))
	(1000, uint256("0x0000002771a008225741bd55cf92ef561ce7a8efd5bb21dbb779c5f8e7cba736"))
	(2000, uint256("0x000000f57ee1799a6df3b621fd0ce4c6a317626130587b2d239e5bceb748d748"))
	(3000, uint256("0x00000032604a052956a1d3ab5ce9331fa345c523b47240710e63045d90c00300"))
	(4000, uint256("0x00000128ae56e626d9c06114970f43c278c5416b6559b93cd7a7385e9aa26659"))
	(5000, uint256("0x634807e2b80c77d91fab6d82e2a58bdec72bbe5c33f60ff82fc52a1f5ba4de11"))
	(6000, uint256("0xcc7cca6982030bf2e74d3800132029e2f5a7f7e47edb86c4e22d7d5dcb47313f"))
	(7000, uint256("0x047a44f146ac18f04673b0e6c8ccbb60ab01c4dcbf3471fed216f983f2199ba1"))
	(8000, uint256("0x2aa53985f81e2c17b19e9651c3903519cce2d2e100cb557581f7c6c2c8170cfb"))
	(9000, uint256("0x82e6d9d13a028ea56f74c484ffa8299f134c8e8e4604cd13c8d05a5df416f6fe"))
	(10000, uint256("0xef3110ca8d30d3bd740932d4e8d9cc2c0a3f72fc8d958d22164b6797d7184923"))
	(11000, uint256("0x5b7883982bef3984a37c2573a793bcd4933941fcaa70f1e16d0f222ecbd3f707"))
	(12000, uint256("0xc330567b75c9bb6112ff88ac82cb655e37f8254f0f48a2a651e28788313a942b"))
	(13000, uint256("0x8657ab9437e4968d6f31cc365829a88238e4498ff47914994969c4acfc09996e"))
	(14000, uint256("0x69ed1316a8a8d2672bc53db3cdd008942d9ed4096587adf98e47edbaed853037"))
	(15000, uint256("0x7b0d1d736b6f03127436d847f16bd7f8470561b55da00be0fdd919737b465d90"))
	(16000, uint256("0x764d4abade45578954b71fccd65422650183809bafcf4e2c08a67ae4bc2c934a"))
	(17000, uint256("0x8bd509693fde7f9f1b7b3bc319a1475e8e4abe1b92def30f29d431c2e87da1b4"))
	(18000, uint256("0xf0e244f1a3dfe68c1baaa32479998d332312cdd24510abff21e3dc89c14680fe"))
	//2 Checkpoint set Complete 		

;
        

	
        
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1555531712, // * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    0        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x0"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1553367419,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x0"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1553367419,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x1a;
        pchMessageStart[1] = 0xa1;
        pchMessageStart[2] = 0x32;
        pchMessageStart[3] = 0x27;
        vAlertPubKey = ParseHex("04be7d52226485aabea892f45174c4c4a9dd6630ef9f170cc92d1a1f8ce3c34609446953747a9e25ae0f6275f367c9ae31be713e05312b519606302c38fff272c4");
        nDefaultPort = 40445;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // ZARHEXCASH starting difficulty is 1 / 2^12  //20
        nSubsidyHalvingInterval = 300000; // ZARHEXCASH - Halving  every 500000 //olD new halving due to erro 
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 3 * 75; // Old target retarget 60 // new 75sec * 8 retarget
        nTargetSpacing = 1 * 75;  // old ZARHEXCASH: 90 Sec Block // new 75 sec per block
        nLastPOWBlock = 4400; // Chain was destoyed by miners RIP 5000000 Originally  
        nMaturity = 100; // Maturity to block 
        nMasternodeCountDrift = 20;
	nMasternodeColleteralLimxDev = 8500000; //Params().MasternodeColleteralLimxDev()  Para
        nModifierUpdateBlock = 1; // we use the version 2 for dmd
        nMaxMoneyOut = 2000000000 * COIN;

        const char* pszTimestamp = "This is genesis block for Zarhexcash network 20190711 madcat asscror deamonproff spanish cow Relaunch";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04eddada8be2e74ced2c25dd3e6b61d0d27ad565a1d3ae7a88734dd8d71b8a9b428a3fc7fefeb85c03d47b77e1f3ecc882f25d0a21d104c9e5eabfa8fc6ee668c6") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1563029372;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 8334138;



        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000feb8ae2aaa7e734d875607e8710d2b6c9ed59dab09eb30f9d0e90c22114"));
        assert(genesis.hashMerkleRoot == uint256("0x3c9a29d8e4a1e88f32a8e0c5714af5d93e1b0fafc9907da898c92d716ad8aa0b"));

        vSeeds.push_back(CDNSSeedData("seed1.zarbitcoin.net","51.75.162.95"));             // seed 1
        vSeeds.push_back(CDNSSeedData("seed2.zarbitcoin.net","51.75.162.92"));             // seed 2
        vSeeds.push_back(CDNSSeedData("seed3.zarbitcoin.net","51.75.170.189"));             // seed 3
	vSeeds.push_back(CDNSSeedData("seed5.zarbitcoin.net","51.38.71.12"));             // seed 5
        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 80); //Prefix Zarhexcash Z
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 83); //Prefix Zarhexcash a
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);//Prefix Zarhexcash A
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x11)(0x1A)(0x12)(0x24).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x1A).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md 109 	0x8000006d
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x21)(0x20)(0x40)(0x17).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04cd66b21f8273bf8c6ddd2b97fe5f830271637ceb82bc6269b010fef7090aa05657b78178f3605c11abd8567dbca949012e864a5132b355dcfa4d33346eaeee1f";
        strDarksendPoolDummyAddress = "ZE7KqyKYv8q9cqh1McgVf9ocjKg2sxxBFb";
        nStartMasternodePayments = 1573953427; //Sat Nov 16 20:17:07 EST 2019
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x34;
        pchMessageStart[1] = 0x44;
        pchMessageStart[2] = 0x75;
        pchMessageStart[3] = 0x14;
        vAlertPubKey = ParseHex("04697b433b115ed0e4e73915b016018e0010e9af78104ce53b78b18d88e47e537c11125431d13ffec917981c58a90191a8fc7d0846c96fe7e7fe99cba0dcf983e0");
        nDefaultPort = 55600;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // ZARHEXCASH: 1 day
        nTargetSpacing = 1.5 * 60;  // ZARHEXCASH: 2 minute
        nLastPOWBlock = 262800;
        nMaturity = 15;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 100000000 * COIN;

        genesis.nTime = 1553367419;
        genesis.nNonce = 5688368;

 
      




        hashGenesisBlock = genesis.GetHash();
     //   assert(hashGenesisBlock == uint256("0x000000b8099430a4804c27719187e997438f4bbff044633ee7a6897c2919f692"));

        vFixedSeeds.clear();
        vSeeds.clear();
	
	//vSeeds.push_back(CDNSSeedData("160.119.102.145", "51.38.71.12")); //SEEDERS1 

		
	base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 84);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 195);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0xb2)(0x21)(0x14)(0x11).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x42)(0x31)(0x59)(0x21).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x42)(0x22)(0x13)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));


        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "049e53e687fdafd78fd42d730fad0e7ea1819396176a2cb85d7a76fa4559cdbd2c2f05330a6f5cbadb44a6c1d324f167e679e9f3e95d9d5649761a3e7f59bf4500";
        strDarksendPoolDummyAddress = "bADWWVV4XPDfe6xNB7vrd9oGqNAFcrtqd8";
        nStartMasternodePayments = 1562531573;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0x54;
        pchMessageStart[2] = 0x95;
        pchMessageStart[3] = 0x64;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // ZARHEXCASH: 1 day
        nTargetSpacing = 1 * 60;        // ZARHEXCASH: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1509321603;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 129915;
		
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 43444;
//        assert(hashGenesisBlock == uint256("0x00000fea76c2e8523777b3dce649c363b4c5e0234605cae551f8d822d17fcc16"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
