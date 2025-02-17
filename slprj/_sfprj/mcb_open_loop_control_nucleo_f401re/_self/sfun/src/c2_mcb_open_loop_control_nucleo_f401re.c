/* Include files */

#include "mcb_open_loop_control_nucleo_f401re_sfun.h"
#include "c2_mcb_open_loop_control_nucleo_f401re.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c2_emlrtMCI = { 141,/* lineNo */
  13,                                  /* colNo */
  "rng",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pName */
};

static emlrtMCInfo c2_b_emlrtMCI = { 125,/* lineNo */
  13,                                  /* colNo */
  "eml_rand_mt19937ar",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+randfun\\eml_rand_mt19937ar.m"/* pName */
};

static emlrtRSInfo c2_emlrtRSI = { 4,  /* lineNo */
  "Subsystem/Safety code generator/MATLAB Function",/* fcnName */
  "#mcb_open_loop_control_nucleo_f401re:4003"/* pathName */
};

static emlrtRSInfo c2_b_emlrtRSI = { 5,/* lineNo */
  "Subsystem/Safety code generator/MATLAB Function",/* fcnName */
  "#mcb_open_loop_control_nucleo_f401re:4003"/* pathName */
};

static emlrtRSInfo c2_c_emlrtRSI = { 71,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_d_emlrtRSI = { 132,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_e_emlrtRSI = { 133,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_f_emlrtRSI = { 135,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_g_emlrtRSI = { 137,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_h_emlrtRSI = { 139,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_i_emlrtRSI = { 282,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_j_emlrtRSI = { 284,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_k_emlrtRSI = { 286,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_l_emlrtRSI = { 287,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo c2_m_emlrtRSI = { 74,/* lineNo */
  "randi",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\randi.m"/* pathName */
};

static emlrtRSInfo c2_n_emlrtRSI = { 107,/* lineNo */
  "rand",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m"/* pathName */
};

static emlrtRSInfo c2_o_emlrtRSI = { 41,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c2_p_emlrtRSI = { 43,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c2_q_emlrtRSI = { 45,/* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo c2_r_emlrtRSI = { 23,/* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo c2_s_emlrtRSI = { 51,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static uint32_T c2_uv[625] = { 5489U, 1301868182U, 2938499221U, 2950281878U,
  1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U, 219885934U,
  2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U, 3418470598U,
  951210697U, 3693558366U, 2923482051U, 1793174584U, 2982310801U, 1586906132U,
  1951078751U, 1808158765U, 1733897588U, 431328322U, 4202539044U, 530658942U,
  1714810322U, 3025256284U, 3342585396U, 1937033938U, 2640572511U, 1654299090U,
  3692403553U, 4233871309U, 3497650794U, 862629010U, 2943236032U, 2426458545U,
  1603307207U, 1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U,
  761573964U, 3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U,
  3295982469U, 1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
  699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
  1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U, 3570962471U,
  4287636090U, 4087307012U, 3603343627U, 202242161U, 2995682783U, 1620962684U,
  3704723357U, 371613603U, 2814834333U, 2111005706U, 624778151U, 2094172212U,
  4284947003U, 1211977835U, 991917094U, 1570449747U, 2962370480U, 1259410321U,
  170182696U, 146300961U, 2836829791U, 619452428U, 2723670296U, 1881399711U,
  1161269684U, 1675188680U, 4132175277U, 780088327U, 3409462821U, 1036518241U,
  1834958505U, 3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U,
  1924681712U, 3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
  3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U, 2339662006U,
  501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U, 3393774360U,
  1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U, 819755096U,
  2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U, 1029741190U,
  2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U, 2701024045U,
  4117700889U, 759495121U, 3332270341U, 2313004527U, 2277067795U, 4131855432U,
  2722057515U, 1264804546U, 3848622725U, 2211267957U, 4100593547U, 959123777U,
  2130745407U, 3194437393U, 486673947U, 1377371204U, 17472727U, 352317554U,
  3955548058U, 159652094U, 1232063192U, 3835177280U, 49423123U, 3083993636U,
  733092U, 2120519771U, 2573409834U, 1112952433U, 3239502554U, 761045320U,
  1087580692U, 2540165110U, 641058802U, 1792435497U, 2261799288U, 1579184083U,
  627146892U, 2165744623U, 2200142389U, 2167590760U, 2381418376U, 1793358889U,
  3081659520U, 1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
  3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
  3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
  354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
  1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U, 1684529556U,
  1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U, 171579916U,
  3878728600U, 2475806724U, 2030324028U, 3331164912U, 1708711359U, 1970023127U,
  2859691344U, 2588476477U, 2748146879U, 136111222U, 2967685492U, 909517429U,
  2835297809U, 3206906216U, 3186870716U, 341264097U, 2542035121U, 3353277068U,
  548223577U, 3170936588U, 1678403446U, 297435620U, 2337555430U, 466603495U,
  1132321815U, 1208589219U, 696392160U, 894244439U, 2562678859U, 470224582U,
  3306867480U, 201364898U, 2075966438U, 1767227936U, 2929737987U, 3674877796U,
  2654196643U, 3692734598U, 3528895099U, 2796780123U, 3048728353U, 842329300U,
  191554730U, 2922459673U, 3489020079U, 3979110629U, 1022523848U, 2202932467U,
  3583655201U, 3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U,
  396426791U, 3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
  3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
  2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U, 1521001832U,
  3605886097U, 2802786495U, 2728923319U, 3996284304U, 903417639U, 1171249804U,
  1020374987U, 2824535874U, 423621996U, 1988534473U, 2493544470U, 1008604435U,
  1756003503U, 1488867287U, 1386808992U, 732088248U, 1780630732U, 2482101014U,
  976561178U, 1543448953U, 2602866064U, 2021139923U, 1952599828U, 2360242564U,
  2117959962U, 2753061860U, 2388623612U, 4138193781U, 2962920654U, 2284970429U,
  766920861U, 3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
  3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U, 686850534U,
  1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U, 4195430425U,
  607905174U, 3902331779U, 2454067926U, 1708133115U, 1170874362U, 2008609376U,
  3260320415U, 2211196135U, 433538229U, 2728786374U, 2189520818U, 262554063U,
  1182318347U, 3710237267U, 1221022450U, 715966018U, 2417068910U, 2591870721U,
  2870691989U, 3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
  4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U, 1123218514U,
  551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U, 422862282U,
  3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U, 1324564878U,
  1928816105U, 1786535431U, 2878099422U, 3290185549U, 539474248U, 1657512683U,
  552370646U, 1671741683U, 3655312128U, 1552739510U, 2605208763U, 1441755014U,
  181878989U, 3124053868U, 1447103986U, 3183906156U, 1728556020U, 3502241336U,
  3055466967U, 1013272474U, 818402132U, 1715099063U, 2900113506U, 397254517U,
  4194863039U, 1009068739U, 232864647U, 2540223708U, 2608288560U, 2415367765U,
  478404847U, 3455100648U, 3182600021U, 2115988978U, 434269567U, 4117179324U,
  3461774077U, 887256537U, 3545801025U, 286388911U, 3451742129U, 1981164769U,
  786667016U, 3310123729U, 3097811076U, 2224235657U, 2959658883U, 3370969234U,
  2514770915U, 3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
  4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U, 1477814055U,
  4043852216U, 1876372354U, 3133294443U, 3871104810U, 3177020907U, 2074304428U,
  3479393793U, 759562891U, 164128153U, 1839069216U, 2114162633U, 3989947309U,
  3611054956U, 1333547922U, 835429831U, 494987340U, 171987910U, 1252001001U,
  370809172U, 3508925425U, 2535703112U, 1276855041U, 1922855120U, 835673414U,
  3030664304U, 613287117U, 171219893U, 3423096126U, 3376881639U, 2287770315U,
  1658692645U, 1262815245U, 3957234326U, 1168096164U, 2968737525U, 2655813712U,
  2132313144U, 3976047964U, 326516571U, 353088456U, 3679188938U, 3205649712U,
  2654036126U, 1249024881U, 880166166U, 691800469U, 2229503665U, 1673458056U,
  4032208375U, 1851778863U, 2563757330U, 376742205U, 1794655231U, 340247333U,
  1505873033U, 396524441U, 879666767U, 3335579166U, 3260764261U, 3335999539U,
  506221798U, 4214658741U, 975887814U, 2080536343U, 3360539560U, 571586418U,
  138896374U, 4234352651U, 2737620262U, 3928362291U, 1516365296U, 38056726U,
  3599462320U, 3585007266U, 3850961033U, 471667319U, 1536883193U, 2310166751U,
  1861637689U, 2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
  2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
  643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U, 3285177704U,
  1948416081U, 1311525291U, 1183517742U, 1739192232U, 3979815115U, 2567840007U,
  4116821529U, 213304419U, 4125718577U, 1473064925U, 2442436592U, 1893310111U,
  4195361916U, 3747569474U, 828465101U, 2991227658U, 750582866U, 1205170309U,
  1409813056U, 678418130U, 1171531016U, 3821236156U, 354504587U, 4202874632U,
  3882511497U, 1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U,
  3725758099U, 831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U,
  3358210805U, 4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U,
  190157081U, 3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
  2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
  453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U, 3541393095U,
  4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U, 1795580598U,
  2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U, 705213300U,
  363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U, 2199989172U,
  1987356470U, 4026755612U, 2147252133U, 270400031U, 1367820199U, 2369854699U,
  2844269403U, 79981964U, 624U };

/* Function Declarations */
static void initialize_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void initialize_params_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void mdl_start_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void mdl_terminate_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void enable_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void disable_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void sf_gateway_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void ext_mode_exec_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void c2_update_jit_animation_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void c2_do_animation_call_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void set_sim_state_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_st);
static real_T c2_now(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                     *chartInstance);
static real_T c2_mod(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                     *chartInstance, real_T c2_x);
static real_T c2_rand(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                      *chartInstance, const emlrtStack *c2_sp);
static real_T c2_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint32_T c2_c_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr);
static uint32_T c2_d_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr);
static real_T c2_e_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr);
static real_T c2_f_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr);
static void c2_g_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr,
   uint32_T c2_b_y[625]);
static void c2_h_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr,
   uint32_T c2_b_y[625]);
static void c2_i_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr,
   uint32_T c2_b_y[2]);
static void c2_j_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr,
   uint32_T c2_b_y[2]);
static void c2_slStringInitializeDynamicBuffers
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void init_dsm_address_info
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_r_not_empty = false;
  chartInstance->c2_seed_not_empty = false;
  chartInstance->c2_method_not_empty = false;
  chartInstance->c2_state_not_empty = false;
  chartInstance->c2_b_state_not_empty = false;
  chartInstance->c2_c_state_not_empty = false;
  chartInstance->c2_doneDoubleBufferReInit = false;
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c2_JITStateAnimation[0],
                        &chartInstance->c2_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    2U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  1U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "c2_mcb_open_loop_control_nucleo_f401re", 0, -1, 126);
  covrtEmlSaturationInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 71, -1,
    85);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 53, 66, -1, 115,
                    false);
}

static void mdl_cleanup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void enable_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  static char_T c2_cv[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'n', 'g',
    ':', 'b', 'a', 'd', 'S', 'e', 't', 't', 'i', 'n', 'g', 's' };

  time_t c2_b_eTime;
  time_t c2_eTime;
  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  real_T c2_b_mti;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d_r;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_y;
  real_T c2_s;
  real_T c2_s0;
  real_T c2_x;
  int32_T c2_exitg1;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_mti;
  int32_T c2_prevEpochTime;
  int32_T c2_t;
  uint32_T c2_arg3;
  uint32_T c2_b_arg3;
  uint32_T c2_b_r;
  uint32_T c2_b_s;
  uint32_T c2_b_seed;
  uint32_T c2_b_t;
  uint32_T c2_b_varargin_1;
  uint32_T c2_c_arg3;
  uint32_T c2_c_r;
  uint32_T c2_c_seed;
  uint32_T c2_c_varargin_1;
  uint32_T c2_method2;
  uint32_T c2_u;
  uint32_T c2_u1;
  uint32_T c2_varargin_1;
  boolean_T c2_covSaturation = false;
  c2_st.tls = chartInstance->c2_fEmlrtCtx;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_JITTransitionAnimation[0] = 0U;
  chartInstance->c2_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0,
                     !chartInstance->c2_r_not_empty)) {
    c2_b_st.site = &c2_emlrtRSI;
    if (!chartInstance->c2_seed_not_empty) {
      chartInstance->c2_seed = 0U;
      chartInstance->c2_seed_not_empty = true;
    }

    c2_c_st.site = &c2_c_emlrtRSI;
    if (!chartInstance->c2_method_not_empty) {
      chartInstance->c2_method = 7U;
      chartInstance->c2_method_not_empty = true;
    }

    c2_c_st.site = &c2_d_emlrtRSI;
    c2_x = c2_now(chartInstance) * 8.64E+6;
    c2_b_x = c2_x;
    c2_c_y = c2_b_x;
    c2_c_y = muDoubleScalarFloor(c2_c_y);
    c2_s = c2_mod(chartInstance, c2_c_y);
    c2_eTime = time(NULL);
    c2_prevEpochTime = (int32_T)c2_eTime + 1;
    do {
      c2_exitg1 = 0;
      c2_b_eTime = time(NULL);
      c2_t = (int32_T)c2_b_eTime;
      if (c2_t <= c2_prevEpochTime) {
        c2_c_x = c2_now(chartInstance) * 8.64E+6;
        c2_d_x = c2_c_x;
        c2_d_y = c2_d_x;
        c2_d_y = muDoubleScalarFloor(c2_d_y);
        c2_s0 = c2_mod(chartInstance, c2_d_y);
        if (c2_s != c2_s0) {
          c2_exitg1 = 1;
        }
      } else {
        c2_exitg1 = 1;
      }
    } while (c2_exitg1 == 0);

    c2_d = muDoubleScalarRound(c2_s);
    c2_covSaturation = false;
    if (c2_d < 4.294967296E+9) {
      if (c2_d >= 0.0) {
        c2_u = (uint32_T)c2_d;
      } else {
        c2_covSaturation = true;
        c2_u = 0U;
      }
    } else if (c2_d >= 4.294967296E+9) {
      c2_covSaturation = true;
      c2_u = MAX_uint32_T;
    } else {
      c2_u = 0U;
    }

    covrtSaturationUpdateFcn(chartInstance->c2_covrtInstance, 4, 0, 0, 0,
      c2_covSaturation);
    chartInstance->c2_seed = c2_u;
    c2_c_st.site = &c2_e_emlrtRSI;
    if (!chartInstance->c2_method_not_empty) {
      chartInstance->c2_method = 7U;
      chartInstance->c2_method_not_empty = true;
    }

    c2_method2 = chartInstance->c2_method;
    if (c2_method2 == 7U) {
      c2_c_st.site = &c2_f_emlrtRSI;
      c2_varargin_1 = chartInstance->c2_seed;
      if (!chartInstance->c2_state_not_empty) {
        for (c2_i = 0; c2_i < 625; c2_i++) {
          chartInstance->c2_state[c2_i] = c2_uv[c2_i];
        }

        chartInstance->c2_state_not_empty = true;
      }

      c2_arg3 = c2_varargin_1;
      c2_b_seed = c2_arg3;
      c2_b_r = c2_b_seed;
      chartInstance->c2_state[0] = c2_b_seed;
      for (c2_mti = 0; c2_mti < 623; c2_mti++) {
        c2_b_mti = 2.0 + (real_T)c2_mti;
        c2_d1 = muDoubleScalarRound(c2_b_mti - 1.0);
        if (c2_d1 < 4.294967296E+9) {
          if (c2_d1 >= 0.0) {
            c2_u1 = (uint32_T)c2_d1;
          } else {
            c2_u1 = 0U;
          }
        } else if (c2_d1 >= 4.294967296E+9) {
          c2_u1 = MAX_uint32_T;
        } else {
          c2_u1 = 0U;
        }

        c2_b_r = (c2_b_r ^ c2_b_r >> 30U) * 1812433253U + c2_u1;
        chartInstance->c2_state[(int32_T)c2_b_mti - 1] = c2_b_r;
      }

      chartInstance->c2_state[624] = 624U;
    } else if (c2_method2 == 5U) {
      c2_c_st.site = &c2_g_emlrtRSI;
      c2_b_varargin_1 = chartInstance->c2_seed;
      if (!chartInstance->c2_b_state_not_empty) {
        for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
          chartInstance->c2_b_state[c2_i1] = 362436069U + 158852560U * (uint32_T)
            c2_i1;
        }

        chartInstance->c2_b_state_not_empty = true;
      }

      c2_b_arg3 = c2_b_varargin_1;
      c2_b_s = c2_b_arg3;
      chartInstance->c2_b_state[0] = 362436069U;
      chartInstance->c2_b_state[1] = c2_b_s;
      if (chartInstance->c2_b_state[1] == 0U) {
        chartInstance->c2_b_state[1] = 521288629U;
      }
    } else if (c2_method2 == 4U) {
      c2_c_st.site = &c2_h_emlrtRSI;
      c2_c_varargin_1 = chartInstance->c2_seed;
      if (!chartInstance->c2_c_state_not_empty) {
        chartInstance->c2_c_state = 1144108930U;
        chartInstance->c2_c_state_not_empty = true;
      }

      c2_c_arg3 = c2_c_varargin_1;
      c2_c_seed = c2_c_arg3;
      c2_c_r = c2_c_seed >> 16U;
      c2_b_t = c2_c_seed & 32768U;
      chartInstance->c2_c_state = c2_c_r << 16U;
      chartInstance->c2_c_state = c2_c_seed - chartInstance->c2_c_state;
      chartInstance->c2_c_state -= c2_b_t;
      chartInstance->c2_c_state <<= 16U;
      chartInstance->c2_c_state += c2_b_t;
      chartInstance->c2_c_state += c2_c_r;
      if (chartInstance->c2_c_state < 1U) {
        chartInstance->c2_c_state = 1144108930U;
      } else if (chartInstance->c2_c_state > 2147483646U) {
        chartInstance->c2_c_state = 2147483646U;
      }
    } else {
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 22),
                    false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1, 22),
                    false);
      sf_mex_call(&c2_b_st, &c2_emlrtMCI, "error", 0U, 2U, 14, c2_e_y, 14,
                  sf_mex_call(&c2_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c2_b_st, NULL, "message", 1U, 1U, 14, c2_f_y)));
    }

    c2_b_st.site = &c2_b_emlrtRSI;
    c2_c_st.site = &c2_m_emlrtRSI;
    c2_d_r = c2_rand(chartInstance, &c2_c_st);
    c2_e_x = c2_d_r * 201.0;
    c2_f_x = c2_e_x;
    c2_g_y = c2_f_x;
    c2_g_y = muDoubleScalarFloor(c2_g_y);
    c2_d_r = c2_g_y;
    chartInstance->c2_r = c2_d_r;
    chartInstance->c2_r_not_empty = true;
  }

  c2_b_y = chartInstance->c2_r;
  *chartInstance->c2_y = c2_b_y;
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, *chartInstance->c2_y);
}

static void ext_mode_exec_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_jit_animation_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_do_animation_call_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_st;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(7, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_y, 0, 0U, 0, 0U, 0),
                false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_d_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &chartInstance->c2_method, 7, 0U,
      0, 0U, 0), false);
  }

  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  c2_e_y = NULL;
  if (!chartInstance->c2_r_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &chartInstance->c2_r, 0, 0U, 0, 0U,
      0), false);
  }

  sf_mex_setcell(c2_b_y, 2, c2_e_y);
  c2_f_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &chartInstance->c2_seed, 7, 0U, 0,
      0U, 0), false);
  }

  sf_mex_setcell(c2_b_y, 3, c2_f_y);
  c2_g_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &chartInstance->c2_c_state, 7, 0U,
      0, 0U, 0), false);
  }

  sf_mex_setcell(c2_b_y, 4, c2_g_y);
  c2_h_y = NULL;
  if (!chartInstance->c2_state_not_empty) {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", chartInstance->c2_state, 7, 0U, 1,
      0U, 1, 625), false);
  }

  sf_mex_setcell(c2_b_y, 5, c2_h_y);
  c2_i_y = NULL;
  if (!chartInstance->c2_b_state_not_empty) {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", chartInstance->c2_b_state, 7, 0U,
      1, 0U, 1, 2), false);
  }

  sf_mex_setcell(c2_b_y, 6, c2_i_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_mcb_open_loop_control_nucleo_f401re
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_i;
  int32_T c2_i1;
  uint32_T c2_b_uv[625];
  uint32_T c2_uv1[2];
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "y");
  chartInstance->c2_method = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "method", &chartInstance->c2_method_not_empty);
  chartInstance->c2_r = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "r", &chartInstance->c2_r_not_empty);
  chartInstance->c2_seed = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "seed", &chartInstance->c2_seed_not_empty);
  chartInstance->c2_c_state = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "state", &chartInstance->c2_c_state_not_empty);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                        "state", &chartInstance->c2_state_not_empty, c2_b_uv);
  for (c2_i = 0; c2_i < 625; c2_i++) {
    chartInstance->c2_state[c2_i] = c2_b_uv[c2_i];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
                        "state", &chartInstance->c2_b_state_not_empty, c2_uv1);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    chartInstance->c2_b_state[c2_i1] = c2_uv1[c2_i1];
  }

  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static real_T c2_now(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                     *chartInstance)
{
  time_t c2_rawtime;
  c2_sxaDueAh1f53T9ESYg9Uc4E c2_timeinfoDouble;
  struct tm c2_timeinfo;
  real_T c2_cDaysMonthWise[12];
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_b_r;
  real_T c2_b_x;
  real_T c2_c_a;
  real_T c2_c_r;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_dDateNum;
  real_T c2_d_r;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_x;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_b_rEQ0;
  boolean_T c2_c_b;
  boolean_T c2_c_rEQ0;
  boolean_T c2_d_b;
  boolean_T c2_e_b;
  boolean_T c2_f_b;
  boolean_T c2_guard1;
  boolean_T c2_rEQ0;
  (void)chartInstance;
  c2_cDaysMonthWise[0] = 0.0;
  c2_cDaysMonthWise[1] = 31.0;
  c2_cDaysMonthWise[2] = 59.0;
  c2_cDaysMonthWise[3] = 90.0;
  c2_cDaysMonthWise[4] = 120.0;
  c2_cDaysMonthWise[5] = 151.0;
  c2_cDaysMonthWise[6] = 181.0;
  c2_cDaysMonthWise[7] = 212.0;
  c2_cDaysMonthWise[8] = 243.0;
  c2_cDaysMonthWise[9] = 273.0;
  c2_cDaysMonthWise[10] = 304.0;
  c2_cDaysMonthWise[11] = 334.0;
  time(&c2_rawtime);
  c2_timeinfo = *localtime(&c2_rawtime);
  c2_timeinfo.tm_year += 1900;
  c2_timeinfo.tm_mon++;
  c2_timeinfoDouble.tm_min = (real_T)c2_timeinfo.tm_min;
  c2_timeinfoDouble.tm_sec = (real_T)c2_timeinfo.tm_sec;
  c2_timeinfoDouble.tm_hour = (real_T)c2_timeinfo.tm_hour;
  c2_timeinfoDouble.tm_mday = (real_T)c2_timeinfo.tm_mday;
  c2_timeinfoDouble.tm_mon = (real_T)c2_timeinfo.tm_mon;
  c2_timeinfoDouble.tm_year = (real_T)c2_timeinfo.tm_year;
  c2_x = c2_timeinfoDouble.tm_year / 4.0;
  c2_b_x = c2_x;
  c2_c_y = c2_b_x;
  c2_c_y = muDoubleScalarCeil(c2_c_y);
  c2_c_x = c2_timeinfoDouble.tm_year / 100.0;
  c2_d_x = c2_c_x;
  c2_d_y = c2_d_x;
  c2_d_y = muDoubleScalarCeil(c2_d_y);
  c2_e_x = c2_timeinfoDouble.tm_year / 400.0;
  c2_f_x = c2_e_x;
  c2_e_y = c2_f_x;
  c2_e_y = muDoubleScalarCeil(c2_e_y);
  c2_dDateNum = ((((365.0 * c2_timeinfoDouble.tm_year + c2_c_y) - c2_d_y) +
                  c2_e_y) + c2_cDaysMonthWise[(int32_T)c2_timeinfoDouble.tm_mon
                 - 1]) + c2_timeinfoDouble.tm_mday;
  if (c2_timeinfoDouble.tm_mon > 2.0) {
    c2_g_x = c2_timeinfoDouble.tm_year;
    c2_a = c2_g_x;
    c2_h_x = c2_a;
    c2_i_x = c2_h_x;
    c2_j_x = c2_i_x;
    c2_b = muDoubleScalarIsNaN(c2_j_x);
    if (c2_b) {
      c2_b_r = rtNaN;
    } else {
      c2_k_x = c2_i_x;
      c2_b_b = muDoubleScalarIsInf(c2_k_x);
      if (c2_b_b) {
        c2_b_r = rtNaN;
      } else if (c2_i_x == 0.0) {
        c2_b_r = 0.0;
      } else {
        c2_b_r = muDoubleScalarRem(c2_i_x, 4.0);
        c2_rEQ0 = (c2_b_r == 0.0);
        if (c2_rEQ0) {
          c2_b_r = 0.0;
        } else if (c2_b_r < 0.0) {
          c2_b_r += 4.0;
        }
      }
    }

    c2_guard1 = false;
    if (c2_b_r == 0.0) {
      c2_l_x = c2_timeinfoDouble.tm_year;
      c2_b_a = c2_l_x;
      c2_m_x = c2_b_a;
      c2_o_x = c2_m_x;
      c2_p_x = c2_o_x;
      c2_c_b = muDoubleScalarIsNaN(c2_p_x);
      if (c2_c_b) {
        c2_c_r = rtNaN;
      } else {
        c2_t_x = c2_o_x;
        c2_e_b = muDoubleScalarIsInf(c2_t_x);
        if (c2_e_b) {
          c2_c_r = rtNaN;
        } else if (c2_o_x == 0.0) {
          c2_c_r = 0.0;
        } else {
          c2_c_r = muDoubleScalarRem(c2_o_x, 100.0);
          c2_b_rEQ0 = (c2_c_r == 0.0);
          if (c2_b_rEQ0) {
            c2_c_r = 0.0;
          } else if (c2_c_r < 0.0) {
            c2_c_r += 100.0;
          }
        }
      }

      if (c2_c_r != 0.0) {
        c2_dDateNum++;
      } else {
        c2_guard1 = true;
      }
    } else {
      c2_guard1 = true;
    }

    if (c2_guard1) {
      c2_n_x = c2_timeinfoDouble.tm_year;
      c2_c_a = c2_n_x;
      c2_q_x = c2_c_a;
      c2_r_x = c2_q_x;
      c2_s_x = c2_r_x;
      c2_d_b = muDoubleScalarIsNaN(c2_s_x);
      if (c2_d_b) {
        c2_d_r = rtNaN;
      } else {
        c2_u_x = c2_r_x;
        c2_f_b = muDoubleScalarIsInf(c2_u_x);
        if (c2_f_b) {
          c2_d_r = rtNaN;
        } else if (c2_r_x == 0.0) {
          c2_d_r = 0.0;
        } else {
          c2_d_r = muDoubleScalarRem(c2_r_x, 400.0);
          c2_c_rEQ0 = (c2_d_r == 0.0);
          if (c2_c_rEQ0) {
            c2_d_r = 0.0;
          } else if (c2_d_r < 0.0) {
            c2_d_r += 400.0;
          }
        }
      }

      if (c2_d_r == 0.0) {
        c2_dDateNum++;
      }
    }
  }

  c2_dDateNum += ((c2_timeinfoDouble.tm_hour * 3600.0 + c2_timeinfoDouble.tm_min
                   * 60.0) + c2_timeinfoDouble.tm_sec) / 86400.0;
  return c2_dDateNum;
}

static real_T c2_mod(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                     *chartInstance, real_T c2_x)
{
  real_T c2_a;
  real_T c2_b_r;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  boolean_T c2_b;
  boolean_T c2_b_b;
  boolean_T c2_rEQ0;
  (void)chartInstance;
  c2_a = c2_x;
  c2_b_x = c2_a;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_b = muDoubleScalarIsNaN(c2_d_x);
  if (c2_b) {
    c2_b_r = rtNaN;
  } else {
    c2_e_x = c2_c_x;
    c2_b_b = muDoubleScalarIsInf(c2_e_x);
    if (c2_b_b) {
      c2_b_r = rtNaN;
    } else if (c2_c_x == 0.0) {
      c2_b_r = 0.0;
    } else {
      c2_b_r = muDoubleScalarRem(c2_c_x, 2.147483647E+9);
      c2_rEQ0 = (c2_b_r == 0.0);
      if (c2_rEQ0) {
        c2_b_r = 0.0;
      } else if (c2_b_r < 0.0) {
        c2_b_r += 2.147483647E+9;
      }
    }
  }

  return c2_b_r;
}

static real_T c2_rand(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct
                      *chartInstance, const emlrtStack *c2_sp)
{
  static char_T c2_cv[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  emlrtStack c2_b_st;
  emlrtStack c2_c_st;
  emlrtStack c2_d_st;
  emlrtStack c2_st;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_j_y = NULL;
  real_T c2_b_j;
  real_T c2_b_r;
  real_T c2_c_kk;
  real_T c2_c_r;
  real_T c2_d;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d_r;
  real_T c2_e_r;
  real_T c2_f_r;
  int32_T c2_b_a;
  int32_T c2_b_kk;
  int32_T c2_exitg1;
  int32_T c2_i;
  int32_T c2_i1;
  int32_T c2_j;
  int32_T c2_k;
  int32_T c2_kk;
  uint32_T c2_b_u[2];
  uint32_T c2_a;
  uint32_T c2_b;
  uint32_T c2_b_y;
  uint32_T c2_c_y;
  uint32_T c2_d_state;
  uint32_T c2_d_y;
  uint32_T c2_e_state;
  uint32_T c2_e_y;
  uint32_T c2_f_state;
  uint32_T c2_f_y;
  uint32_T c2_g_state;
  uint32_T c2_g_y;
  uint32_T c2_h_state;
  uint32_T c2_hi;
  uint32_T c2_i_y;
  uint32_T c2_icng;
  uint32_T c2_jsr;
  uint32_T c2_lo;
  uint32_T c2_mti;
  uint32_T c2_s;
  uint32_T c2_test1;
  uint32_T c2_test2;
  uint32_T c2_u;
  uint32_T c2_u1;
  uint32_T c2_ui;
  boolean_T c2_b_isvalid;
  boolean_T c2_exitg2;
  boolean_T c2_isvalid;
  c2_st.prev = c2_sp;
  c2_st.tls = c2_sp->tls;
  c2_b_st.prev = &c2_st;
  c2_b_st.tls = c2_st.tls;
  c2_c_st.prev = &c2_b_st;
  c2_c_st.tls = c2_b_st.tls;
  c2_d_st.prev = &c2_c_st;
  c2_d_st.tls = c2_c_st.tls;
  c2_st.site = &c2_n_emlrtRSI;
  if (!chartInstance->c2_method_not_empty) {
    chartInstance->c2_method = 7U;
    chartInstance->c2_method_not_empty = true;
  }

  if (chartInstance->c2_method == 4U) {
    c2_b_st.site = &c2_o_emlrtRSI;
    if (!chartInstance->c2_c_state_not_empty) {
      chartInstance->c2_c_state = 1144108930U;
      chartInstance->c2_c_state_not_empty = true;
    }

    c2_d_state = chartInstance->c2_c_state;
    c2_e_state = c2_d_state;
    c2_f_state = c2_e_state;
    c2_g_state = c2_f_state;
    c2_s = c2_g_state;
    c2_hi = c2_s / 127773U;
    c2_lo = c2_s - c2_hi * 127773U;
    c2_test1 = 16807U * c2_lo;
    c2_test2 = 2836U * c2_hi;
    c2_a = c2_test1;
    c2_b = c2_test2;
    if (c2_a < c2_b) {
      c2_h_state = c2_b - c2_a;
      c2_h_state = ~c2_h_state;
      c2_h_state &= 2147483647U;
    } else {
      c2_h_state = c2_a - c2_b;
    }

    c2_d_r = (real_T)c2_h_state * 4.6566128752457969E-10;
    c2_g_state = c2_h_state;
    c2_d1 = c2_d_r;
    c2_e_state = c2_g_state;
    c2_e_r = c2_d1;
    c2_b_r = c2_e_r;
    chartInstance->c2_c_state = c2_e_state;
  } else if (chartInstance->c2_method == 5U) {
    c2_b_st.site = &c2_p_emlrtRSI;
    if (!chartInstance->c2_b_state_not_empty) {
      for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
        chartInstance->c2_b_state[c2_i1] = 362436069U + 158852560U * (uint32_T)
          c2_i1;
      }

      chartInstance->c2_b_state_not_empty = true;
    }

    c2_icng = chartInstance->c2_b_state[0];
    c2_jsr = chartInstance->c2_b_state[1];
    c2_u = c2_jsr;
    c2_u1 = c2_icng;
    c2_u1 = 69069U * c2_u1 + 1234567U;
    c2_u ^= c2_u << 13;
    c2_u ^= c2_u >> 17;
    c2_u ^= c2_u << 5;
    c2_ui = c2_u1 + c2_u;
    chartInstance->c2_b_state[0] = c2_u1;
    chartInstance->c2_b_state[1] = c2_u;
    c2_c_r = (real_T)c2_ui * 2.328306436538696E-10;
    c2_d = c2_c_r;
    c2_b_r = c2_d;
  } else {
    c2_b_st.site = &c2_q_emlrtRSI;
    if (!chartInstance->c2_state_not_empty) {
      for (c2_i = 0; c2_i < 625; c2_i++) {
        chartInstance->c2_state[c2_i] = c2_uv[c2_i];
      }

      chartInstance->c2_state_not_empty = true;
    }

    c2_c_st.site = &c2_r_emlrtRSI;
    c2_d_st.site = &c2_s_emlrtRSI;

    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on: */
    /*  */
    /*  A C-program for MT19937, with initialization improved 2002/1/26. */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto. */
    /*  */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
    /*  All rights reserved. */
    /*  */
    /*  Redistribution and use in source and binary forms, with or without */
    /*  modification, are permitted provided that the following conditions */
    /*  are met: */
    /*  */
    /*    1. Redistributions of source code must retain the above copyright */
    /*       notice, this list of conditions and the following disclaimer. */
    /*  */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer */
    /*       in the documentation and/or other materials provided with the */
    /*       distribution. */
    /*  */
    /*    3. The names of its contributors may not be used to endorse or */
    /*       promote products derived from this software without specific */
    /*       prior written permission. */
    /*  */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
    /*  */
    /* =============================   END   ================================= */
    do {
      c2_exitg1 = 0;
      for (c2_j = 0; c2_j < 2; c2_j++) {
        c2_b_j = 1.0 + (real_T)c2_j;
        c2_mti = chartInstance->c2_state[624] + 1U;
        if (c2_mti >= 625U) {
          for (c2_kk = 0; c2_kk < 227; c2_kk++) {
            c2_c_kk = 1.0 + (real_T)c2_kk;
            c2_b_y = (chartInstance->c2_state[(int32_T)c2_c_kk - 1] &
                      2147483648U) | (chartInstance->c2_state[(int32_T)(c2_c_kk
              + 1.0) - 1] & 2147483647U);
            c2_c_y = c2_b_y;
            c2_e_y = c2_c_y;
            if ((c2_e_y & 1U) == 0U) {
              c2_e_y >>= 1U;
            } else {
              c2_e_y = c2_e_y >> 1U ^ 2567483615U;
            }

            chartInstance->c2_state[(int32_T)c2_c_kk - 1] =
              chartInstance->c2_state[(int32_T)(c2_c_kk + 397.0) - 1] ^ c2_e_y;
          }

          for (c2_b_kk = 0; c2_b_kk < 396; c2_b_kk++) {
            c2_c_kk = 228.0 + (real_T)c2_b_kk;
            c2_b_y = (chartInstance->c2_state[(int32_T)c2_c_kk - 1] &
                      2147483648U) | (chartInstance->c2_state[(int32_T)(c2_c_kk
              + 1.0) - 1] & 2147483647U);
            c2_g_y = c2_b_y;
            c2_i_y = c2_g_y;
            if ((c2_i_y & 1U) == 0U) {
              c2_i_y >>= 1U;
            } else {
              c2_i_y = c2_i_y >> 1U ^ 2567483615U;
            }

            chartInstance->c2_state[(int32_T)c2_c_kk - 1] =
              chartInstance->c2_state[(int32_T)((c2_c_kk + 1.0) - 228.0) - 1] ^
              c2_i_y;
          }

          c2_b_y = (chartInstance->c2_state[623] & 2147483648U) |
            (chartInstance->c2_state[0] & 2147483647U);
          c2_d_y = c2_b_y;
          c2_f_y = c2_d_y;
          if ((c2_f_y & 1U) == 0U) {
            c2_f_y >>= 1U;
          } else {
            c2_f_y = c2_f_y >> 1U ^ 2567483615U;
          }

          chartInstance->c2_state[623] = chartInstance->c2_state[396] ^ c2_f_y;
          c2_mti = 1U;
        }

        c2_b_y = chartInstance->c2_state[(int32_T)c2_mti - 1];
        chartInstance->c2_state[624] = c2_mti;
        c2_b_y ^= c2_b_y >> 11U;
        c2_b_y ^= c2_b_y << 7U & 2636928640U;
        c2_b_y ^= c2_b_y << 15U & 4022730752U;
        c2_b_y ^= c2_b_y >> 18U;
        c2_b_u[(int32_T)c2_b_j - 1] = c2_b_y;
      }

      c2_b_u[0] >>= 5U;
      c2_b_u[1] >>= 6U;
      if ((c2_b_u[0] == 0U) && (c2_b_u[1] == 0U)) {
        if ((chartInstance->c2_state[624] >= 1U) && (chartInstance->c2_state[624]
             < 625U)) {
          c2_isvalid = true;
        } else {
          c2_isvalid = false;
        }

        c2_b_isvalid = c2_isvalid;
        if (c2_isvalid) {
          c2_b_isvalid = false;
          c2_k = 0;
          c2_exitg2 = false;
          while ((!c2_exitg2) && (c2_k + 1 < 625)) {
            if (chartInstance->c2_state[c2_k] == 0U) {
              c2_b_a = c2_k + 1;
              c2_k = c2_b_a;
            } else {
              c2_b_isvalid = true;
              c2_exitg2 = true;
            }
          }
        }

        if (!c2_b_isvalid) {
          c2_h_y = NULL;
          sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1,
            37), false);
          c2_j_y = NULL;
          sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv, 10, 0U, 1, 0U, 2, 1,
            37), false);
          sf_mex_call(&c2_d_st, &c2_b_emlrtMCI, "error", 0U, 2U, 14, c2_h_y, 14,
                      sf_mex_call(&c2_d_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c2_d_st, NULL, "message", 1U, 1U, 14, c2_j_y)));
        }
      } else {
        c2_exitg1 = 1;
      }
    } while (c2_exitg1 == 0);

    c2_f_r = 1.1102230246251565E-16 * ((real_T)c2_b_u[0] * 6.7108864E+7 +
      (real_T)c2_b_u[1]);
    c2_d2 = c2_f_r;
    c2_b_r = c2_d2;
  }

  return c2_b_r;
}

const mxArray
  *sf_c2_mcb_open_loop_control_nucleo_f401re_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static real_T c2_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier)
{
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr),
    &c2_thisId);
  sf_mex_destroy(&c2_nullptr);
  return c2_b_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d;
  sf_mex_destroy(&c2_u);
  return c2_b_y;
}

static uint32_T c2_c_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr)
{
  emlrtMsgIdentifier c2_thisId;
  uint32_T c2_b_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr),
    &c2_thisId, c2_svPtr);
  sf_mex_destroy(&c2_nullptr);
  return c2_b_y;
}

static uint32_T c2_d_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr)
{
  uint32_T c2_b_u;
  uint32_T c2_b_y;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b_u, 1, 7, 0U, 0, 0U, 0);
    c2_b_y = c2_b_u;
  }

  sf_mex_destroy(&c2_u);
  return c2_b_y;
}

static real_T c2_e_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr)
{
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr),
    &c2_thisId, c2_svPtr);
  sf_mex_destroy(&c2_nullptr);
  return c2_b_y;
}

static real_T c2_f_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr)
{
  real_T c2_b_y;
  real_T c2_d;
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d, 1, 0, 0U, 0, 0U, 0);
    c2_b_y = c2_d;
  }

  sf_mex_destroy(&c2_u);
  return c2_b_y;
}

static void c2_g_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr,
   uint32_T c2_b_y[625])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId,
                        c2_svPtr, c2_b_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_h_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr,
   uint32_T c2_b_y[625])
{
  int32_T c2_i;
  uint32_T c2_b_uv[625];
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_uv, 1, 7, 0U, 1, 0U, 1,
                  625);
    for (c2_i = 0; c2_i < 625; c2_i++) {
      c2_b_y[c2_i] = c2_b_uv[c2_i];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_i_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_nullptr, const char_T *c2_identifier, boolean_T *c2_svPtr,
   uint32_T c2_b_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char_T *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nullptr), &c2_thisId,
                        c2_svPtr, c2_b_y);
  sf_mex_destroy(&c2_nullptr);
}

static void c2_j_emlrt_marshallIn
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T *c2_svPtr,
   uint32_T c2_b_y[2])
{
  int32_T c2_i;
  uint32_T c2_b_uv[2];
  (void)chartInstance;
  if (mxIsEmpty(c2_u)) {
    *c2_svPtr = false;
  } else {
    *c2_svPtr = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_b_uv, 1, 7, 0U, 1, 0U, 1, 2);
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_b_y[c2_i] = c2_b_uv[c2_i];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_slStringInitializeDynamicBuffers
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c2_mcb_open_loop_control_nucleo_f401re_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3886392151U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1414309603U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2068641763U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4112325602U);
}

mxArray *sf_c2_mcb_open_loop_control_nucleo_f401re_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_mcb_open_loop_control_nucleo_f401re_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_vars");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rawtime");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_mcb_open_loop_control_nucleo_f401re_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c2_mcb_open_loop_control_nucleo_f401re(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiCO4GVgYAPSHEDMxAABrFA+IxCzQ2mIOAtcXAGISyoLUkHixUXJnilAOi8xF8x"
    "PLK3wzEvLB5tvwYAwnw2L+YxI5nNCxSHggz1l+kUcQPoNkPSzENAvAGRVQsMFFj7k2y/gQJl+TP"
    "uxuZ8Nxf0Qfm5qSUZ+CkR/ACP++GVEi18mJHNzGDIZCqDucCDgDyY0fwjAPBHR4ACmOxocqJEeG"
    "giERwBaeID4zlYxAUX56UWJuQpumTmpxTG+jiE+jk4xQUYGRiZJMSX5+TlJ+RUxqbk5MTmZSTG5"
    "iSU5iUkxRYl5KWmleTEFRZlliSWpIOl4kJhe7mBIF6Sm6yKovgsMA5weGNwh6aHBnSrhMFjyKaH"
    "4YEGJDxaG4tTUFJA+j4HOnw5zIPERMIcq+bOCQDg4o+VPZ4rzZ1Feul7ukCmvWdH8D+IXlwDLF6"
    "j+jIFODw0pkPSgkEqV9DCDQHgkoYVHEtXL6/jc5HRDMwsD83hwOKeV5kCTy2h6oUZ6OQBNLwn0S"
    "S/JaOGRTIP0UmJoaWlsnliEnmBG0wsV0ssCaHpxGDblS3FGkXFyfl46RvkCANjK8zo="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_mcb_open_loop_control_nucleo_f401re_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sth44iXR8seh6pktWcBKzoF";
}

static void sf_opaque_initialize_c2_mcb_open_loop_control_nucleo_f401re(void
  *chartInstanceVar)
{
  initialize_params_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
  initialize_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_mcb_open_loop_control_nucleo_f401re(void
  *chartInstanceVar)
{
  enable_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_mcb_open_loop_control_nucleo_f401re(void
  *chartInstanceVar)
{
  disable_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_mcb_open_loop_control_nucleo_f401re(void
  *chartInstanceVar)
{
  sf_gateway_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_mcb_open_loop_control_nucleo_f401re(SimStruct* S)
{
  return get_sim_state_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_mcb_open_loop_control_nucleo_f401re
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void
  sf_opaque_cleanup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mcb_open_loop_control_nucleo_f401re_optimization_info();
    }

    mdl_cleanup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
      ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c2_mcb_open_loop_control_nucleo_f401re(void
  *chartInstanceVar)
{
  mdl_start_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo
      (((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*)
        chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c2_mcb_open_loop_control_nucleo_f401re(void *
  chartInstanceVar)
{
  mdl_terminate_c2_mcb_open_loop_control_nucleo_f401re
    ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mcb_open_loop_control_nucleo_f401re
  (SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_mcb_open_loop_control_nucleo_f401re
      ((SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_mcb_open_loop_control_nucleo_f401re_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [26] = {
    "eNrtWk1vG0UY3kRuaFFbBQmpHJCohIS4UPJFPxACJ/4oFgk1sdNWyJIZ7772jjI7s52ZdeIeUI4",
    "cOXIoUiUO/AF+AD+BG/wKxJEj7+yuHbNZ4l3bNElVS5v17PrZd95nnvdjd2Mt1HYs/FzH7fm7lr",
    "WE+8u4LVrR51I8XhjbouMF65N4XH/dsmyXSF3jXWHl/9jCgR7wRtDt0sOcWB54dSKJp6awy4kHu",
    "6AECzQVPN/kKe+CBG7jBXwhdS67inoBo3y/GnDbWFaPXGq7DVcEzNnCCxLnAWeD/7LrB7qOFstU",
    "gq2rAI52pQh6bpWR3uksSH1QcsHeV4GXmysFuhH4xlW1EzBNfQaVQ7BrXGmCLKgJ/jY00VDSh7k",
    "VQlVjiBaezyjh2bl2iWqAj+rQsOc7+PdBoJG9jHbRXodyooWkhFU8VjIKz4itM5znDsqa5eZZe7",
    "oMnaDXo7xn2JWBBxz9R51k4KpbEn2QpAcPeM4YNN5VDsMFHukyewzWjCynisHAi1ZFTYUN7Vb6y",
    "JCa0m7V5iXCmMqHbQp/G/rAQvtloskU2Mh+DrBS1GmKh0SaKMgZSQGnTwKIsSXBHZp9hfsJVJhw",
    "v8TkmQFOPSMpcJDm0dRHF5qkyUBp4ZUwjMrb2xntncTWuAbZJTZkzn2SUAU44VBXOe06VJEOM2h",
    "kSYdeZr4C8KmhluoGvHwg5D5ynDfJHnNlIiEfGpwelEFDmDAqqO6HhAUZ5+wpzHBGHnsKM1Y+u4",
    "g18TMV2Ca2C46pJ5TBDihzAZU5P2Md2URv+1QPyqBsSf2skRQocLCQGJaaAx/2+D4XB7wqhdeIO",
    "4JTdAWAWYNIjmVhC8uSHFRx8tlmLeFJ0yhrmvbMI5qRjtHGfeBYWYyvphISG6OqwrF1wwnNgm3Q",
    "p1jauaJKYzs1qIQx4IT96FsL+frRN+Lx+iiWaqopcaUIlmGOndJmJ2z2oEk9CA80CPYU0TD+GLs",
    "r1rHdK4un213EbwtT4qwZcY/HcIUUft4bwy3HY3ut7dmdtvCBt5kQftsWXEvB2jywGYh2d2NlVc",
    "LJeV3NwH+aP0mcdQJ3zPtw//4YfiHFrjW2n2W9imO4awk7hQRuKebw219+fPi9U/jq5w/Fn+KnR",
    "7/PYv/y9Xz6vh6P3x72a6OK1j+R9M1vP5+gjxsJfdwI85u7sUEf795V4N729/Uje+uLp6Ia6e3a",
    "6fN9LTHf4fGbuGlMeGH+lHbNie+9zJgE0T2Buf7dsfkuTeDjypieLOuvz2bDv1lMrmNhAn4Zvw0",
    "Sup3e/nJxNvxJ+2nzX0qstxl7oF3hRPh6zny7OHZdZlHLT4mrND8WE34sD514fFQM998dFeehh6",
    "MJfNQTfJhx6eNWXYoeNrg3wwLb2tlsbm9utXbXVtY2Oi0tBOuIwxZ4rMVopxWVuJYk3MEGrOVjt",
    "cH+wJxum2O3vPOgi7y6ljHuN+uM9WDdj/RwdH8uPJyXOJ20HoV/rUfBUtiphPn8rOOz+Cxaj/qz",
    "ucTn4QQeSon4LM0cn5L3bnkXJl9fSvh/aXj/EePds9bDkRPp4SbMRQ8/TOCjk+CjM/d8jb1xb/X",
    "23ZU77ZDnbsBiubzSyzz08musl29ejF7sBB/2/6AXvXrv3vodIpOCeaWXOejleayX4kuTX5Qr1/",
    "GOu5eaXy7Kc4fzjpsnL/N67pGGW3jB9s7Kv7zPcy7670/r763E75fPsR/J/bTP9c6bX3/kvK99J",
    "x5/OnoHV3Ipc1LeAsSnt4F0086+JPr+Oyd/w+eMFcNf/E8EX69vcsIGikavMIaHsdb2QY5OSSAq",
    "/d3KWdQhK6WfSesjribi24wPKHfEgfpgde2jtVnq2j8jDu0+",
    ""
  };

  static char newstr [1849] = "";
  newstr[0] = '\0';
  for (i = 0; i < 26; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c2_mcb_open_loop_control_nucleo_f401re(SimStruct *S)
{
  const char* newstr =
    sf_c2_mcb_open_loop_control_nucleo_f401re_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1453175934U));
  ssSetChecksum1(S,(1359242384U));
  ssSetChecksum2(S,(4000264103U));
  ssSetChecksum3(S,(3612844911U));
}

static void mdlRTW_c2_mcb_open_loop_control_nucleo_f401re(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c2_mcb_open_loop_control_nucleo_f401re
  (SimStruct *S)
{
  SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *chartInstance;
  chartInstance = (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct *)
    utMalloc(sizeof(SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc2_mcb_open_loop_control_nucleo_f401reInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_mcb_open_loop_control_nucleo_f401re;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c2_mcb_open_loop_control_nucleo_f401re
    (chartInstance);
}

void c2_mcb_open_loop_control_nucleo_f401re_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c2_mcb_open_loop_control_nucleo_f401re(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mcb_open_loop_control_nucleo_f401re(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mcb_open_loop_control_nucleo_f401re(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_mcb_open_loop_control_nucleo_f401re_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
