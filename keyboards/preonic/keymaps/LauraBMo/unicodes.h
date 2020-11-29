

enum unicode_names {
   CALPHA,
   CBETA,
   CGAMMA,
   CDELTA,
   CEPSILON,
   CZETA,
   CETA,
   CTHETA,
   CIOTA,
   CKAPPA,
   CLAMBDA,
   CMU,
   CNU,
   CXI,
   COMICRON,
   CPI,
   CRHO,
   CSIGMA,
   CTAU,
   CUPSILON,
   CPHI,
   CCHI,
   CPSI,
   COMEGA,
   ALPHA,
   BETA,
   GAMMA,
   DELTA,
   EPSILON,
   ZETA,
   ETA,
   THETA,
   IOTA,
   KAPPA,
   LAMBDA,
   MU,
   NU,
   XI,
   OMICRON,
   PI,
   RHO,
   SIGMA,
   TAU,
   UPSILON,
   PHI,
   CHI,
   PSI,
   OMEGA
};

const uint32_t PROGMEM unicode_map[] = {
 [CALPHA]   = 0x0391, // Α
 [CBETA]    = 0x0392, // Β
 [CGAMMA]   = 0x0393, // Γ
 [CDELTA]   = 0x0394, // Δ
 [CEPSILON] = 0x0395, // Ε
 [CZETA]    = 0x0396, // Ζ
 [CETA]     = 0x0397, // Η
 [CTHETA]   = 0x0398, // Θ
 [CIOTA]    = 0x0399, // Ι
 [CKAPPA]   = 0x039A, // Κ
 [CLAMBDA]  = 0x039B, // Λ
 [CMU]      = 0x039C, // Μ
 [CNU]      = 0x039D, // Ν
 [CXI]      = 0x039E, // Ξ
 [COMICRON] = 0x039F, // Ο
 [CPI]      = 0x03A0, // Π
 [CRHO]     = 0x03A1, // Ρ
 [CSIGMA]   = 0x03A3, // Σ
 [CTAU]     = 0x03A4, // Τ
 [CUPSILON] = 0x03A5, // Υ
 [CPHI]     = 0x03A6, // Φ
 [CCHI]     = 0x03A7, // Χ
 [CPSI]     = 0x03A8, // Ψ
 [COMEGA]   = 0x03A9, // Ω
 [ALPHA]    = 0x03B1, // α
 [BETA]     = 0x03B2, // β
 [GAMMA]    = 0x03B3, // γ
 [DELTA]    = 0x03B4, // δ
 [EPSILON]  = 0x03B5, // ε
 [ZETA]     = 0x03B6, // ζ
 [ETA]      = 0x03B7, // η
 [THETA]    = 0x03B8, // θ
 [IOTA]     = 0x03B9, // ι
 [KAPPA]    = 0x03BA, // κ
 [LAMBDA]   = 0x03BB, // λ
 [MU]       = 0x03BC, // μ
 [NU]       = 0x03BD, // ν
 [XI]       = 0x03BE, // ξ
 [OMICRON]  = 0x03BF, // ο
 [PI]       = 0x03C0, // π
 [RHO]      = 0x03C1, // ρ
 [SIGMA]    = 0x03C3, // σ
 [TAU]      = 0x03C4, // τ
 [UPSILON]  = 0x03C5, // υ
 [PHI]      = 0x03C6, // φ
 [CHI]      = 0x03C7, // χ
 [PSI]      = 0x03C8, // ψ
 [OMEGA]    = 0x03C9, // ω
};

#define GK_ALPH XP(ALPHA,CALPHA)
#define GK_BETA XP(BETA,CBETA)
#define GK_GMMA XP(GAMMA,CGAMMA)
#define GK_DLTA XP(DELTA,CDELTA)
#define GK_EPS XP(EPSILON,CEPSILON)
#define GK_ZETA XP(ZETA,CZETA)
#define GK_ETA XP(ETA,CETA)
#define GK_THTA XP(THETA,CTHETA)
#define GK_IOTA XP(IOTA,CIOTA)
#define GK_KPPA XP(KAPPA,CKAPPA)
#define GK_LMBD XP(LAMBDA,CLAMBDA)
#define GK_MU XP(MU,CMU)
#define GK_NU XP(NU,CNU)
#define GK_XI XP(XI,CXI)
#define GK_OMI XP(OMICRON,COMICRON)
#define GK_PI XP(PI,CPI)
#define GK_RHO XP(RHO,CRHO)
#define GK_SGMA XP(SIGMA,CSIGMA)
#define GK_TAU XP(TAU,CTAU)
#define GK_UPS XP(UPSILON,CUPSILON)
#define GK_PHI XP(PHI,CPHI)
#define GK_CHI XP(CHI,CCHI)
#define GK_PSI XP(PSI,CPSI)
#define GK_OMGA XP(OMEGA,COMEGA)
