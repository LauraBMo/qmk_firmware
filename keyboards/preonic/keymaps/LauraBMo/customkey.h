
/* My alias to make a more readable keymap */


/* Space Cadet Shift */
/* https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_space_cadet */
/* LAPO_KEYS is already in use */
#define LSPO_KEYS KC_LGUI, KC_LSFT, KC_SCLN
#define RSPC_KEYS KC_LSFT, KC_LSFT, KC_LBRC

/* Control on hold and *** on tap */
#define CTL_LBR LCTL_T(KC_LBRC)
#define CTL_SPC RCTL_T(KC_SPC)
#define CTL_BSLS RCTL_T(KC_BSLS)
#define CTL_ACUT RCTL_T(ES_ACUT)

/* Shift on hold, (***) on tap */
#define SFT_QUOT RSFT_T(KC_QUOT)
#define SFT_CCED RSFT_T(ES_CCED)
#define SFT_GRV LSFT_T(ES_GRV)

/* Greek alphabet, see unicodes.h */
#define GK_ALPH XP(ALPHA, CALPHA)
#define GK_BETA XP(BETA, CBETA)
#define GK_GMMA XP(GAMMA, CGAMMA)
#define GK_DLTA XP(DELTA, CDELTA)
#define GK_EPS XP(EPSILON, CEPSILON)
#define GK_ZETA XP(ZETA, CZETA)
#define GK_ETA XP(ETA, CETA)
#define GK_THTA XP(THETA, CTHETA)
#define GK_IOTA XP(IOTA, CIOTA)
#define GK_KPPA XP(KAPPA, CKAPPA)
#define GK_LMBD XP(LAMBDA, CLAMBDA)
#define GK_MU XP(MU, CMU)
#define GK_NU XP(NU, CNU)
#define GK_XI XP(XI, CXI)
#define GK_OMI XP(OMICRON, COMICRON)
#define GK_PI XP(PI, CPI)
#define GK_RHO XP(RHO, CRHO)
#define GK_SGMA XP(SIGMA, CSIGMA)
#define GK_TAU XP(TAU, CTAU)
#define GK_UPS XP(UPSILON, CUPSILON)
#define GK_PHI XP(PHI, CPHI)
#define GK_CHI XP(CHI, CCHI)
#define GK_PSI XP(PSI, CPSI)
#define GK_OMGA XP(OMEGA, COMEGA)
