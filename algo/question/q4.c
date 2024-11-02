// 1.3. We consider the long-term security of the Advanced Encryption Standard
//  (AES) with a key length of 128-bit with respect to exhaustive key-search attacks.
//  AESis perhaps the most widely used symmetric cipher at this time.
//  1. Assume that an attacker has a special purpose application specific integrated cir
// cuit (ASIC) which checks 5·108 keys per second, and she has a budget of $1
//  million. One ASIC costs $50, and we assume 100% overhead for integrating

//  theASIC(manufacturingtheprintedcircuitboards,powersupply,cooling,etc.).
//  HowmanyASICscanweruninparallelwiththegivenbudget?Howlongdoes
//  anaveragekeysearchtake?RelatethistimetotheageoftheUniverse,whichis
//  about1010years.


// Answer
// Step 1: Calculate number of ASICs possible with budget

// Cost per ASIC = $50
// Overhead = 100% = Additional $50 per ASIC
// Total cost per ASIC with overhead = $100
// Budget = $1,000,000
// Number of ASICs = $1,000,000 / $100 = 10,000 ASICs


// Step 2: Calculate total keys checked per second

// One ASIC checks 5×10⁸ keys/second
// Total keys/second = 10,000 × 5×10⁸ = 5×10¹² keys/second

// Step 3: Calculate average time for key search

// AES-128 has 2¹²⁸ possible keys
// Average search requires checking half of keyspace = 2¹²⁷ keys
// Time = (2¹²⁷) ÷ (5×10¹²) seconds
// = 2¹²⁷/(5×10¹²) ≈ 3.4×10²⁵ seconds
// Converting to years: 3.4×10²⁵/(365×24×3600) ≈ 1.08×10¹⁸ years

// Relation to Universe age:

// Universe age = 10¹⁰ years
// Ratio = 1.08×10¹⁸/10¹⁰ = 1.08×10⁸
// The search would take about 108 million times the age of the universe!


// Second part - Future feasibility with Moore's Law:

// Step 1: Calculate required improvement factor

// We need to reduce 1.08×10¹⁸ years to 1 day (24 hours)
// Improvement factor needed = (1.08×10¹⁸ × 365) = 3.94×10²⁰

// Step 2: Apply Moore's Law

// Computing power doubles every 18 months
// Per year improvement = 2^(12/18) = 2^(2/3) ≈ 1.587
// Let's solve: 1.587^x = 3.94×10²⁰
// Taking log: x × log(1.587) = log(3.94×10²⁰)
// x = log(3.94×10²⁰)/log(1.587) ≈ 213 years

