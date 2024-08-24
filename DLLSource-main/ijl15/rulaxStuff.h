#pragma once
#include "Global.h"
#include "moreshit.h"
#include "MapleClientCollectionTypes/ZXString.h"
#include <string>
#include "shavitstuff/BossHP.h"
#include "HackStuff/loginstuff.h"
#include "HackStuff/haxAddresses.h"

BOOL loggedIn = false;
bool loaded = false;
const DWORD dwDInput8DLLInject = 0x00796357;
const DWORD dwMovementFlushInterval = 0x0068A83F;
const DWORD dwStatWndOnStatChange = 0x00A20213;
const DWORD dwUserEmoteCoolTime = 0x00A244AE;
const DWORD dwUserGivePopularityCoolTime = 0x00A23F28;
const DWORD dwMessageChatDelay = 0x00490651;
const DWORD dwMessageChatSpam = 0x00490607;
const DWORD dwRemoteAddress = 0x00AFE084;
const DWORD dwIGCipherHash = 0x00A4A845; //related to packet encryption, not used, kept for reference
const DWORD dwIGCipherVirtual1 = 0x00A4A8DA;
const DWORD dwIGCipherVirtual2 = 0x00A4A9BF;
const DWORD dwIGCipherDecrypt = 0x00A4A942;
const DWORD dwIGCipherDecryptStr = 0x00A4A9F7;
const DWORD dwUnlimitedSoulRush = 0x0096BF09;
const DWORD dwUnlimitedFJ = 0x0096BEB5;
const DWORD dwUnlimitedFJYVector = 0x0096BF86;
const DWORD dwMesoDropColorRet = 0x00A20B7B;
const DWORD PetEquipCapRemoval = 0x0046D473 - (0x0046D43B + 5);

// Define the jmp opcode
const BYTE jmpOpcode = 0xE9;
//const DWORD dwWhiteToColorRet = 0x0098A7A0;


//0x008DB181 + 1	position of the line breaks in the text displayed in this chat log //ty dream
//008DFB06 008D4B75 008D4C27 008D4CBF 008D6308 //related to vertical scrolling //ty rynyan
//005F456A version number edit //ty windy
//08DFBA0 character typing limit	//ty chris
//008C4EA2 stat window related?? //ty masterrulax
//skill tooltip extension x 008F26F3/008F26F8 y //ty rynyan
//item UI tooltip extension 008EEEAF //ty rain

// ===== Resolution Modifications ====


const DWORD dwByteAvatarMegaHPos = 0x0045B97E;
const DWORD dwAvatarMegaWidth = 0x0045A5CB;
const DWORD dwApplicationHeight = 0x009F7B1D;
const DWORD dwApplicationWidth = 0x009F7B23;
const DWORD dwCursorVectorVPos = 0x0059A15D;
const DWORD dwCursorVectorHPos = 0x0059A169;
const DWORD dwUpdateMouseLimitVPos = 0x0059AC22;
const DWORD dwUpdateMouseLimitHPos = 0x0059AC09;
const DWORD dwCursorPosLimitVPos = 0x0059A8B1;
const DWORD dwCursorPosLimitHPos = 0x0059A898;
const DWORD dwToolTipLimitVPos = 0x008F32DF;
const DWORD dwToolTipLimitHPos = 0x008F32CC;
const DWORD dwTempStatToolTipDraw = 0x007B2EA0;
const DWORD dwTempStatToolTipFind = 0x007B3087;
const DWORD dwTempStatIconVPos = 0x007B2C97;
const DWORD dwTempStatIconHpos = 0x007B2CB5;
const DWORD dwTempStatCoolTimeVPos = 0x007B2DA0;
const DWORD dwTempStatCoolTimeHPos = 0x007B2DBE;
const DWORD dwQuickSlotInitVPos = 0x008D1793;
const DWORD dwQuickSlotInitHPos = 0x008D179A;
const DWORD dwQuickSlotVPos = 0x008DF782;
const DWORD dwQuickSlotHPos = 0x008DF7F8;
const DWORD dwQuickSlotCWndVPos = 0x008DE8EE;
const DWORD dwQuickSlotCWndHPos = 0x008DE8E5;
const DWORD dwViewPortHeight = 0x009DFCF0;
const DWORD dwViewPortWidth = 0x009DFE68;
const DWORD dwBossBar = 0x00533B0E;
const DWORD dwBossBarRetn = 0x00533B15;
const DWORD dwBossBarRetn2 = 0x007E16A1;
const DWORD dwCashFix = 0x00469348;
const DWORD dwCashFixRtm = 0x0046934E;
const DWORD dwVersionNumberFix = 0x005F464D;
const DWORD dwVersionNumberFixRtm = 0x005F4657;
const int dwVersionNumberFixNOPs = 10;
const DWORD dwAlwaysViewRestoreFix = 0x00642105;
const DWORD dwAlwaysViewRestorerFixRtm = 0x0064210C;
const int dwAlwaysViewRestoreFixNOPs = 7;

//const DWORD dwloginFrameFix = 0x005F4C11;
//const DWORD dwloginFrameFixCall = 0x009DE4D2;
//const int loginFrameFixNOPs = 5;

const DWORD dwLoginBackCanvasFix = 0x0060E1BF;
const DWORD dwLoginBackCanvasFixRetn = 0x0060E1CA;
const int LoginBackCanvasFixNOPs = 11;

const DWORD dwLoginViewRecFix = 0x0062B334;
const DWORD dwLoginViewRecFixRetn = 0x0062B345;
const int LoginViewRecFixNOPs = 17;

const DWORD dwLoginBackBtnFix = 0x0060E69D;	//not used, kept for referrence
const DWORD dwLoginBackBtnFixRetn = 0x0060E6A4;
const int LoginBackBtnFixNOPs = 7;

const DWORD dwInitialLoginScreenBackXY = 0x005F4B48;	//not used, kept for referrence, resets on back step from next step

const DWORD dwLoginDescriptorFix = 0x0060D85B;
const DWORD dwLoginDescriptorFixRetn = 0x0060D88E;
const int LoginDescriptorFixNOPs = 51;

const DWORD dwMoreGainMsgs = 0x0089B185;
const DWORD dwMoreGainMsgsRetn = 0x0089B18B;
const int MoreGainMsgsNOPs = 6;

const DWORD dwMoreGainMsgsFade = 0x0089B563;
const DWORD dwMoreGainMsgsFadeRetn = 0x0089B56A;
const int MoreGainMsgsFadeNOPs = 7;

const DWORD dwMoreGainMsgsFade1 = 0x0089B4E6;
const DWORD dwMoreGainMsgsFade1Retn = 0x0089B4EB;
const int MoreGainMsgsFade1NOPs = 5;

const DWORD dwMuruengraidPlayer = 0x00554041;
const DWORD dwMuruengraidPlayerRetn = 0x00554049;
const int MuruengraidPlayerNOPs = 8;

const DWORD dwMuruengraidClock = 0x005540C9;
const DWORD dwMuruengraidClockRetn = 0x005540D1;
const int MuruengraidClockNOPs = 8;

const DWORD dwMuruengraidMonster = 0x0055414F;
const DWORD dwMuruengraidMonsterRetn = 0x00554157;
const int MuruengraidMonsterNOPs = 8;

const DWORD dwMuruengraidMonster1 = 0x005543F1;
const DWORD dwMuruengraidMonster1Retn = 0x005543F8;
const int MuruengraidMonster1NOPs = 7;

const DWORD dwMuruengraidMonster2 = 0x0055447C;
const DWORD dwMuruengraidMonster2Retn = 0x00554483;
const int MuruengraidMonster2NOPs = 7;

const DWORD dwMuruengraidEngBar = 0x00554507;
const DWORD dwMuruengraidEngBarRetn = 0x0055450C;
const int MuruengraidEngBarNOPs = 5;

const DWORD dwMuruengraidEngBar1 = 0x005541DA;
const DWORD dwMuruengraidEngBar1Retn = 0x005541E2;
const int MuruengraidEngBar1NOPs = 8;

const DWORD dwMuruengraidEngBar2 = 0x00554265;
const DWORD dwMuruengraidEngBar2Retn = 0x0055426A;
const int MuruengraidEngBar2NOPs = 5;

const DWORD dwMuruengraidClearRoundUI = 0x0053500A;	//; int __cdecl sub_43E86F(int, wchar_t *, int, int, int, int, int, int, int, int)
const DWORD dwMuruengraidClearRoundUIRetn = 0x00535014;	//may be used to fix other cases of pop-up UI misallignment
const int MuruengraidClearRoundUINOPs = 10;

const DWORD dwMuruengraidTimerCanvas = 0x00555314;
const DWORD dwMuruengraidTimerCanvasRetn = 0x00555319;
const int MuruengraidTimerCanvasNOPs = 5;

const DWORD dwMuruengraidTimerMinutes = 0x005556CC;
const DWORD dwMuruengraidTimerMinutesRetn = 0x005556D5;
const int MuruengraidTimerMinutesNOPs = 9;

const DWORD dwMuruengraidTimerSeconds = 0x005556E6;
const DWORD dwMuruengraidTimerSecondsRetn = 0x005556EC;
const int MuruengraidTimerSecondsNOPs = 6;

const DWORD dwMuruengraidTimerBar = 0x00555541;
const DWORD dwMuruengraidTimerBarRetn = 0x00555548;
const int MuruengraidTimerBarNOPs = 7;

const DWORD dwMuruengraidMonster1_2 = 0x00554BA3;
const DWORD dwMuruengraidMonster1_2Retn = 0x00554BA8;
const int MuruengraidMonster1_2NOPs = 5;

const DWORD dwStatsSubMov = 0x008C5112;
const DWORD dwStatsSubMovRetn = 0x008C5117;
const int StatsSubMovNOPs = 5;

//beginning of packed client run addies //CwvsAppSetup?? //CWvsAppInitializeInput?? //CWvsAppCallUpdate?? //CClientSocketConnect??
const DWORD dwCLoginSendCheckPasswordPacket = 0x005F6994;
const DWORD dwCLoginSendCheckPasswordPacketRetn = 0x005F6B5D;
const int CLoginSendCheckPasswordPacketNops = 6;

const DWORD dw0x0044E550 = 0x0044E550;
const DWORD dw0x0044E550Retn = 0x0044E562;
const int dw0x0044E550Nops = 18;

const DWORD dw0x0044E5BE = 0x0044E5BE;
const DWORD dw0x0044E5BERetn = 0x0044E5D0;
const int dw0x0044E5BENops = 18;

const DWORD dw0x0044E5DB = 0x0044E5DB;
const DWORD dw0x0044E5DBRetn = 0x0044E5ED;
const int dw0x0044E5DBNops = 18;

const DWORD dw0x0044E6AC = 0x0044E6AC;
const DWORD dw0x0044E6ACRetn = 0x0044E6BE;
const int dw0x0044E6ACNops = 18;

const DWORD dw0x0044E71D = 0x0044E71D;
const DWORD dw0x0044E71DRetn = 0x0044E72F;
const int dw0x0044E71DNops = 18;

const DWORD dw0x0044E80C = 0x0044E80C;
const DWORD dw0x0044E80CRetn = 0x0044E81E;
const int dw0x0044E80CNops = 18;

const DWORD dw0x0044E8B4 = 0x0044E8B4;
const DWORD dw0x0044E8B4Retn = 0x0044E8C6;
const int dw0x0044E8B4Nops = 18;

const DWORD dw0x0044EA22 = 0x0044EA22;
const DWORD dw0x0044EA22Retn = 0x0044EA37;
const int dw0x0044EA22Nops = 19;

const DWORD dw0x0044EA6F = 0x0044EA6F;
const DWORD dw0x0044EA6FRetn = 0x0044EA81;
const int dw0x0044EA6FNops = 18;

const DWORD dw0x0044EBD6 = 0x0044EBD6;
const DWORD dw0x0044EBD6Retn = 0x0044EBE8;
const int dw0x0044EBD6Nops = 18;

const DWORD dw0x0044ECA1 = 0x0044ECA1;
const DWORD dw0x0044ECA1Retn = 0x0044ECB3;
const int dw0x0044ECA1Nops = 18;

const DWORD dw0x0044ED32 = 0x0044ED32;
const DWORD dw0x0044ED32Retn = 0x0044ED44;
const int dw0x0044ED32Nops = 18;

const DWORD dw0x0044ED52 = 0x0044ED52;
const DWORD dw0x0044ED52Retn = 0x0044ED64;
const int dw0x0044ED52Nops = 18;

const DWORD dw0x0044EED3 = 0x0044EED3;
const DWORD dw0x0044EED3Retn = 0x0044EEE3;
const int dw0x0044EED3Nops = 16;
//start of 494 bloc
const DWORD dw0x00494943 = 0x00494943;
const DWORD dw0x00494943Retn = 0x00494955;
const int dw0x00494943Nops = 18;

const DWORD dw0x00494BB6 = 0x00494BB6;
const DWORD dw0x00494BB6Retn = 0x00494BC8;
const int dw0x00494BB6Nops = 18;

const DWORD dw0x00494CA9 = 0x00494CA9;
const DWORD dw0x00494CA9Retn = 0x00494CBB;
const int dw0x00494CA9Nops = 18;

const DWORD dw0x00494CF0 = 0x00494CF0;
const DWORD dw0x00494CF0Retn = 0x00494D02;
const int dw0x00494CF0Nops = 18;

const DWORD dw0x00494D3B = 0x00494D3B;
const DWORD dw0x00494D3BRetn = 0x00494DEF;
const int dw0x00494D3BNops = 18;

const DWORD dw0x00494EAF = 0x00494EAF;
const DWORD dw0x00494EAFRetn = 0x00494ECA;
const int dw0x00494EAFNops = 27;

const DWORD dw0x00494EEC = 0x00494EEC;
const DWORD dw0x00494EECRetn = 0x00494EFE;
const int dw0x00494EECNops = 18;

const DWORD dw0x00494F87 = 0x00494F87;
const DWORD dw0x00494F87Retn = 0x00494F99;
const int dw0x00494F87Nops = 18;
//start of 009F bloc
const DWORD dw0x009F4E84 = 0x009F4E84;
const DWORD dw0x009F4E84Retn = 0x009F4E96;
const int dw0x009F4E84Nops = 18;

const DWORD dw0x009F4EC3 = 0x009F4EC3;
const DWORD dw0x009F4EC3Retn = 0x009F4ED5;
const int dw0x009F4EC3Nops = 18;

const DWORD dw0x009F4F12 = 0x009F4F12;
const DWORD dw0x009F4F12Retn = 0x009F4F24;
const int dw0x009F4F12Nops = 18;

const DWORD dw0x009F4FC6 = 0x009F4FC6;
const DWORD dw0x009F4FC6Retn = 0x009F4FD8;
const int dw0x009F4FC6Nops = 18;

const DWORD dw0x009F503C = 0x009F503C;
const DWORD dw0x009F503CRetn = 0x009F504E;
const int dw0x009F503CNops = 18;

const DWORD dw0x009F51A7 = 0x009F51A7;
const DWORD dw0x009F51A7Retn = 0x009F51B7;
const int dw0x009F51A7Nops = 16;

const DWORD dw0x009F526F = 0x009F526F;
const DWORD dw0x009F526FRetn = 0x009F55D8;
const int dw0x009F526FNops = 19;

const DWORD dw0x009F5653 = 0x009F5653;
const DWORD dw0x009F5653Retn = 0x009F5667;
const int dw0x009F5653Nops = 20;

const DWORD dw0x009F5833 = 0x009F5833;
const DWORD dw0x009F5833Retn = 0x009F5AA2;
const int dw0x009F5833Nops = 18;

const DWORD dw0x009F5C2C = 0x009F5C2C;
const DWORD dw0x009F5C2CRetn = 0x009F5C41;
const int dw0x009F5C2CNops = 21;

const DWORD dw0x009F5CA3 = 0x009F5CA3;	//dwCWvsAppRun
const DWORD dw0x009F5CA3Retn = 0x009F5FDB;
const int dw0x009F5CA3Nops = 18;

const DWORD dw0x009F5FBD = 0x009F5FBD;
const DWORD dw0x009F5FBDRetn = 0x009F5FDB;
const int dw0x009F5FBDNops = 30;

const DWORD dw0x009F631C = 0x009F631C;
const DWORD dw0x009F631CRetn = 0x009F632E;
const int dw0x009F631CNops = 18;

const DWORD dw0x009F691F = 0x009F691F;
const DWORD dw0x009F691FRetn = 0x009F6945;
const int dw0x009F691FNops = 38;

const DWORD dw0x009F6F36 = 0x009F6F36;
const DWORD dw0x009F6F36Retn = 0x009F6F48;
const int dw0x009F6F36Nops = 18;

const DWORD dw0x009F6F5C = 0x009F6F5C;
const DWORD dw0x009F6F5CRetn = 0x009F6F6E;
const int dw0x009F6F5CNops = 18;

const DWORD dw0x009F7CFA = 0x009F7CFA;
const DWORD dw0x009F7CFARetn = 0x009F7D0C;
const int dw0x009F7CFANops = 18;

const DWORD dw0x009F7D83 = 0x009F7D83;
const DWORD dw0x009F7D83Retn = 0x009F8210;
const int dw0x009F7D83Nops = 5;

const DWORD dw0x009F81FB = 0x009F81FB;
const DWORD dw0x009F81FBRetn = 0x009F8210;
const int dw0x009F81FBNops = 21;

const DWORD dw0x009F84E9 = 0x009F84E9;
const DWORD dw0x009F84E9Retn = 0x009F84FB;
const int dw0x009F84E9Nops = 18;

const DWORD dw0x009F8AD4 = 0x009F8AD4;
const DWORD dw0x009F8AD4Retn = 0x009F8AEE;
const int dw0x009F8AD4Nops = 26;
//start of 00A4B bloc
const DWORD dw0x00A4BB39 = 0x00A4BB39;
const DWORD dw0x00A4BB39Retn = 0x00A4BB4B;
const int dw0x00A4BB39Nops = 18;

const DWORD dw0x00A4BC79 = 0x00A4BC79;
const DWORD dw0x00A4BC79Retn = 0x00A4BC89;
const int dw0x00A4BC79Nops = 16;

const DWORD dw0x00A4BD05 = 0x00A4BD05;
const DWORD dw0x00A4BD05Retn = 0x00A4BD17;
const int dw0x00A4BD05Nops = 18;

const DWORD dw0x00A4BD4E = 0x00A4BD4E;
const DWORD dw0x00A4BD4ERetn = 0x00A4BD60;
const int dw0x00A4BD4ENops = 18;

const DWORD dw0x00A4BD99 = 0x00A4BD99;
const DWORD dw0x00A4BD99Retn = 0x00A4BDAB;
const int dw0x00A4BD99Nops = 18;

const DWORD dw0x00A4BDE3 = 0x00A4BDE3;
const DWORD dw0x00A4BDE3Retn = 0x00A4BDF5;
const int dw0x00A4BDE3Nops = 18;

const DWORD dw0x00A4BDFE = 0x00A4BDFE;
const DWORD dw0x00A4BDFERetn = 0x00A4BE10;
const int dw0x00A4BDFENops = 18;

const DWORD dw0x00A4BE47 = 0x00A4BE47;
const DWORD dw0x00A4BE47Retn = 0x00A4BE59;
const int dw0x00A4BE47Nops = 18;


const DWORD dwCashFix1 = 0x00469414;
const DWORD dwCashFix1Rtm = 0x00469420;
const int dwCashFix1NOPs = 12;
const DWORD dwCashFix2 = 0x0046942F;
const DWORD dwCashFix2Rtm = 0x0046943D;
const int dwCashFix2NOPs = 14;
const DWORD dwCashFix3 = 0x0046944C;
const DWORD dwCashFix3Rtm = 0x0046945C;
const int dwCashFix3NOPs = 16;
const DWORD dwCashFix4 = 0x0046946B;
const DWORD dwCashFix4Rtm = 0x00469479;
const int dwCashFix4NOPs = 14;
const DWORD dwCashFix5 = 0x00469488;
const DWORD dwCashFix5Rtm = 0x00469499;
const int dwCashFix5NOPs = 17;
const DWORD dwCashFix6 = 0x004694A8;
const DWORD dwCashFix6Rtm = 0x004694B4;
const int dwCashFix6NOPs = 12;
const DWORD dwCashFix7 = 0x004694C8;
const DWORD dwCashFix7Rtm = 0x004694D9;
const int dwCashFix7NOPs = 17;
const DWORD dwCashFix8 = 0x004694E8;
const DWORD dwCashFix8Rtm = 0x004694F3;
const int dwCashFix8NOPs = 11;
const DWORD dwCashFixOnOff = 0x00776B5F;
const DWORD dwCashFixOnOffRtm = 0x00776B64;
const DWORD dwCashFixOnOffCall = 0x004732D2;
const int dwCashFixOnOffNOPs = 5;
//const DWORD dwCashFixOnOffCall2 = 0x00BEC20C;
const DWORD dwCashFixPrev = 0x004AB10F;
const DWORD dwCashFixPrevRtm = 0x004AB11D;
const int dwCashFixPrevNOPs = 14;

// ===== Unlimited Teleport =====
const DWORD dwTeleFieldLimit = 0x00957BB7;
const DWORD dwTeleUpdateTime = 0x00957BFE;
const DWORD dwTeleFootholdAbove = 0x00957EFC;
const DWORD dwTeleFootholdBelow = 0x00957ED9;
const DWORD dwTeleIsPortal = 0x00957C25;

// ===== Uncapped Hair/Face Id =====
const DWORD dwHairFaceUncap1 = 0x005C94F3;
const DWORD dwHairFaceUncap2 = 0x009ACA9B;
const int dwHairFaceUncapNOPs = 18;
const DWORD dwHairFaceUncapCapRetn = 0x005C9505;
const DWORD dwHairFaceUncapFaceRetn = 0x005C95BF;
const DWORD dwHairFaceUncapHairRetn = 0x005C958D;
const DWORD dwHairFaceUncapRetn = 0x009ACAAD;

// ===== Status Bar =====
const DWORD dwStatusBarVPos = 0x008CFD55;
const DWORD dwStatusBarPosRetn = 0x008CFD5A;

const DWORD dwStatusBarBackgroundVPos = 0x008D1F65;
const DWORD dwStatusBarBackgroundPosRetn = 0x008D1F6A;

const DWORD dwStatusBarInputVPos = 0x008D217C;
const DWORD dwStatusBarInputPosRetn = 0x008D2185;

// ===== Login Screen =====
const DWORD dwLoginCreateDlg = 0x006203E8;
const DWORD dwLoginCreateDlgRtn = 0x006203F6;

const DWORD dwLoginUsername = 0x006209A6;
const DWORD dwLoginUsernameRtn = 0x006209B1;

const DWORD dwLoginPassword = 0x00620A0D;
const DWORD dwLoginPasswordRtn = 0x00620A15;

const DWORD dwLoginInputBackgroundColor = 0x0062094F;
const DWORD dwLoginInputFontColor = 0x00620930;
const DWORD dwLoginLoginBtn = 0x00620644;
const DWORD dwLoginFindPasswordBtn = 0x006207AF;
const DWORD dwLoginQuitBtn = 0x00620917;
const DWORD dwLoginFindIDBtn = 0x00620735;
const DWORD dwLoginSaveIDBtn = 0x006206BE;
const DWORD dwLoginWebHomeBtn = 0x006208A0;
const DWORD dwLoginWebRegisterBtn = 0x00620829;
//addresses hooked by CRCbypassed v83 version to redirect to their section. may be incomplete
//0x0044E550 //0x0044E5DB //0x0044E71D //0x0044E8B4 //0x0044EA6F //0x0044ECA1 //0x0044ED52 //0x00494D3B //0x00494EEC //0x009F4E84
//0x009F4F12 //0x009F503C //0x009F526F //0x009F6F36 //0x009F7CFA //0x009F84E9 //0x00A4BDFE //0x00A4BD99 //0x00A4BD05 //0x00A4BB39
int m_nGameHeight = 768;
int m_nGameWidth = 1366;
int chair_transparency = 255;
int skill_transparency = 255;
bool skills = true;
bool chairs = true;
bool gfxon = false;

void setResolution(int res) {
	switch (res) {
	case 4:
		m_nGameWidth = 800;
		m_nGameHeight = 600;
		break;
	case 3:
		m_nGameWidth = 1920;
		m_nGameHeight = 1080;
		break;
	case 2:
		m_nGameWidth = 1366;
		m_nGameHeight = 768;
		break;
	case 1:
	default:
		m_nGameWidth = 1280;
		m_nGameHeight = 720;
		break;
	}
}


//auto GetHitPoint_Hook = (int(__thiscall*)(void*, tagRECT, int))0x00642260;
//int(__fastcall GetHitPoint)(void* _this, void* edx, tagRECT rcAttack, int rcAttack_12)
//{
//	if (gettingHit) {
//		return 0;
//	}
//	return(GetHitPoint_Hook(_this, rcAttack))
//}




auto CUserRemote__OnPrepareCancel = (int(__thiscall*)(int, int))0x00980BF5;
int(__fastcall CUserPrepareCancelPacket)(int remote, void* edx, int a2)
{
	if (gfxon)
	{
		return (CUserRemote__OnPrepareCancel(remote, a2));
	}
	return 0;
}

auto CUserRemote__OnPrepare = (int(__thiscall*)(int, int))0x00980A81;
int(__fastcall CUserPreparePacket)(int remote, void* edx, int a2)
{
	if (gfxon)
	{
		return (CUserRemote__OnPrepare(remote, a2));
	}
	return 0;
}

auto CUserRemote__OnAttack = (int(__thiscall*)(int, int, int))0x009803AB;
int(__fastcall CUserOnAttackPacket)(int remote, void* edx, int a2, int a3)
{
	if (gfxon)
	{
		return (CUserRemote__OnAttack(remote, a2, a3));
	}
	return 0;
}

void toggleGfx()
{
	gfxon = !gfxon;
}

void toggleSkills()
{
	skills = !skills;
	skill_transparency = skills ? 255 : 0;
}

void toggleChairs()
{
	chairs = !chairs;
	chair_transparency = chairs ? 0 : 255;
}

void setTransparency(int transparency)
{
	skill_transparency = transparency;
	chair_transparency = transparency;
}


// maybe one day.
auto hook_message = (void(__thiscall*)(void*, ZXString<char>*, int))0x0052C315;
void(__fastcall messageStuff)(void* level, void* ecx, ZXString<char>* a2, int bOnlyBalloon) {
	static const std::unordered_map<std::string, std::function<void()>> commandMap = {
		{"#gfx", toggleGfx},
		{"#skills", toggleSkills},
		{"#chairs", toggleChairs},
		{"#opacity", []() {setTransparency(255); }},
		{"#opacity 1", []() {setTransparency(200); }},
		{"#opacity 2", []() {setTransparency(150); }},
		{"#opacity 3", []() {setTransparency(100); }},
	};

	auto handler = commandMap.find(a2->m_pStr);
	if (handler != commandMap.end()) {
		handler->second();
		return;
	}

	return hook_message(level, a2, bOnlyBalloon);
}

bool Hook_CWvsApp__EnableWinkey(bool enable)
{
	typedef void(__fastcall* CWvsApp__EnableWinkey_t)(void* pThis, void* edx, int bEnable);
	static auto CWvsApp__EnableWinkey = reinterpret_cast<CWvsApp__EnableWinkey_t>(0x009FEC62);

	CWvsApp__EnableWinkey_t hook = [](void* pThis, void* edx, int bEnable) -> void
	{
		bEnable = 1;
		CWvsApp__EnableWinkey(pThis, edx, bEnable);
		return;
	};

	return SetHook(enable, reinterpret_cast<void**>(&CWvsApp__EnableWinkey), hook);
}

//auto CLogin__SendCheckPasswordPacket_hook = (int(__thiscall*)(int, const char*, const char*))0x005C9AFA;
auto CLogin_SendPassword_Hook = (int(__thiscall*)(int, char*, char*))0x005F6952;
int(__fastcall sendpassword)(int loginbase, void* edx, const char* username, const char* password)
{

	// Option 1: Using a dynamic array
	size_t ulen = std::strlen(username);
	char* unonConstStr = new char[ulen + 1];  // +1 for the null terminator
	std::strcpy(unonConstStr, username);

	// Option 2: Using std::vector
	std::vector<char> uStr(username, username + ulen + 1);  // +1 for the null terminator
	char* vecUserName = uStr.data();

	size_t plen = std::strlen(password);
	char* pnonConstStr = new char[ulen + 1];  // +1 for the null terminator
	std::strcpy(pnonConstStr, password);

	// Option 2: Using std::vector
	std::vector<char> pStr(password, password + plen + 1);  // +1 for the null terminator
	char* vecPW = pStr.data();


	// Clean up
	delete[] unonConstStr;
	return CLogin_SendPassword_Hook(loginbase, vecUserName, vecPW);
}

void doini()
{
	INIReader reader("config.ini");
	if (reader.ParseError() == 0) {
		/*m_nGameWidth = reader.GetInteger("general", "width", 1280);
		m_nGameHeight = reader.GetInteger("general", "height", 720);*/

		setResolution(reader.GetInteger("general", "resolution", 1));

		if (reader.GetBoolean("clienthax", "nobulb", "true")) {
			PatchNop(0x00A08D5B, 5);
		}

		if (reader.GetBoolean("clienthax", "customcolor", "true")) {
			WriteValue(0x0098B70C + 1, 0xFFFF5D00); //CASE 25, changed hue to ORANGE which is FF5D00
			WriteByte(0x008c4944 + 1, 25); //Stat Window Strings Name and Level pushed to case 25
			WriteByte(0x008AA6CB + 1, 25); //Skill Strings pushed to case 25
		}

		if (reader.GetBoolean("clienthax", "arancombo1080p", "true")) {
			WriteValue(0x00960581 + 3, 0x00073A); //Aran Combo Numbers (Move 3 bytes to write instruction)
			WriteValue(0x00960839 + 1, 0x00073A); //Aran Combo Letters Witdh
			WriteValue(0x00960C67 + 1, 0x000770); //Aran Combo SMASH / FENRIR Witdh
			WriteValue(0x00960DED + 1, 0x000770); //Aran Combo DRAIN Witdh
		}

		if (reader.GetInteger("clienthax", "ChairOpacity", chair_transparency) > 255) {
			chair_transparency = 255;
		}
		else {
			chair_transparency = (reader.GetInteger("clienthax", "ChairOpacity", chair_transparency));
		}

		if (reader.GetInteger("clienthax", "SkillOpacity", skill_transparency) > 255) {
			skill_transparency = 255;
		}

		else {
			skill_transparency = (reader.GetInteger("clienthax", "SkillOpacity", skill_transparency));
		}
			SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnAttack), CUserOnAttackPacket);
			SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnPrepare), CUserPreparePacket);
			SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnPrepareCancel), CUserPrepareCancelPacket);

		if (reader.GetBoolean("clienthax", "moveattack", "true")) {
			// CUserLocal::IsImmovable
			WriteByte(0x0095F97A, 0xEB); // jmp
			WriteByte(0x0095F97A + 1, 0x59); // 0095F9D5
			// CVecCtrlUser::WorkUpdateActive
			WriteByte(0x009CBFB0, 0xEB); // jmp
			// CUserLocal::Jump
			PatchNop(0x0094C3BB, 6);
		}

		//Hook_CWvsApp__EnableWinkey(reader.GetBoolean("clienthax", "enablewinkey", "false"));
	}
}

typedef void(__cdecl* animationlayer_t)(void*, void*, int, void*, int, int, void*, int, int, int);
static auto animation_hook = reinterpret_cast<animationlayer_t>(0x0043EA3E);
void __cdecl LoadLayer(void* a1, void* a2, int a3, void* a4, int a5, int a6, void* a7, int a8, int alpha, int a10) {
	if ((int)_ReturnAddress() == 0x006697BB) { // hit animation
		return animation_hook(a1, a2, a3, a4, a5, a6, a7, a8, skill_transparency, a10);
	}
	if ((int)_ReturnAddress() == 0x004397A8)
	{
		return animation_hook(a1, a2, a3, a4, a5, a6, a7, a8, skill_transparency, a10);
	}
	if ((int)_ReturnAddress() == 0x0094172D) // chair
	{
		return animation_hook(a1, a2, a3, a4, a5, a6, a7, a8, chair_transparency, a10);
	}
	return animation_hook(a1, a2, a3, a4, a5, a6, a7, a8, alpha, a10);
}


typedef void(__cdecl* animationlayer_t2)(void*, wchar_t*, int, void*, int, int, void*, int, int, int);
static auto animation_hook2 = reinterpret_cast<animationlayer_t>(0x0043E86F);
void __cdecl LoadLayer2(void* a1, wchar_t* a2, int a3, void* a4, int a5, int a6, void* a7, int a8, int alpha, int a10) {
	if ((int)_ReturnAddress() == 0x0043D7F7)
	{
		return animation_hook2(a1, a2, a3, a4, a5, a6, a7, a8, skill_transparency, a10);
	}
	return animation_hook2(a1, a2, a3, a4, a5, a6, a7, a8, alpha, a10);
}


int nStatusBarY = 0;
__declspec(naked) void AdjustStatusBar() {
	__asm {
		push nStatusBarY
		push ebx // horizontal position; 0
		mov ecx, esi
		jmp dword ptr[dwStatusBarPosRetn]
	}
}

__declspec(naked) void
AdjustStatusBarBG() {
	__asm {
		push nStatusBarY
		movsd
		push 0
		jmp dword ptr[dwStatusBarBackgroundPosRetn]
	}
}

__declspec(naked) void AdjustStatusBarInput() {
	__asm {
		push nStatusBarY
		push edi
		lea ecx, [esi + 0x0CD0]
		jmp dword ptr[dwStatusBarInputPosRetn]
	}
}

__declspec(naked) void PositionLoginDlg() {
	__asm {
		push 0x000000B4
		push 400
		push - 48	// y
		push - 185	// x
		jmp dword ptr[dwLoginCreateDlgRtn]
	}
}
__declspec(naked) void PositionLoginUsername() {
	__asm {
		push 0x0F
		push 0x00000084
		push 127	// y
		push 0		// x
		jmp dword ptr[dwLoginUsernameRtn]
	}
}
__declspec(naked) void PositionLoginPassword() {
	__asm {
		push 0x0F
		push 0x78
		push 127	// y
		push 272	// x
		jmp dword ptr[dwLoginPasswordRtn]
	}
}
__declspec(naked) void PositionBossBarY() {
	__asm {	//finally working!, originally posted by Angxl
		//push 22	//modification
		push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}
__declspec(naked) void PositionBossBarY1() {
	__asm {	//finally working!, originally posted by Angxl
		push 22	//modification
		//push edi	//part of original memory
		push dword ptr ss : [ebp - 68]	//part of original memory
		lea eax, dword ptr ss : [ebp - 32]	//part of original memory
		jmp dword ptr[dwBossBarRetn]
	}
}

int serverMessageExists;
__declspec(naked) void PositionBossBarY2() {
	__asm {
		mov esi, eax
		and dword ptr ss : [ebp - 4] , 0
		mov serverMessageExists, esi
		jmp dword ptr[dwBossBarRetn2]
	}
}

int myHeight = -(m_nGameHeight - 600) / 2;
int myWidth = -(m_nGameWidth - 800) / 2;

__declspec(naked) void CashShopFix() {
	__asm {
		push    eax //vCanvas //originally posted by shavitash		//fixed
		push    ebx //nZ
		push    ebx //uHeight
		push    ebx //uWidth
		push	myHeight//84//myHeight //nTop - do the math yourself, this wont compile obviously
		push	myWidth//283//myWidth //nLeft - same as above
		jmp dword ptr[dwCashFixRtm]
	}
}

int nHeightOfsetted1 = 0; int nWidthOfsetted1 = 0; int nTopOfsetted1 = 0; int nLeftOfsetted1 = 0;
int nHeightOfsetted2 = 0; int nWidthOfsetted2 = 0; int nTopOfsetted2 = 0; int nLeftOfsetted2 = 0;
int nHeightOfsetted3 = 0; int nWidthOfsetted3 = 0; int nTopOfsetted3 = 0; int nLeftOfsetted3 = 0;
int nHeightOfsetted4 = 0; int nWidthOfsetted4 = 0; int nTopOfsetted4 = 0; int nLeftOfsetted4 = 0;
int nHeightOfsetted5 = 0; int nWidthOfsetted5 = 0; int nTopOfsetted5 = 0; int nLeftOfsetted5 = 0;
int nHeightOfsetted6 = 0; int nWidthOfsetted6 = 0; int nTopOfsetted6 = 0;
int nHeightOfsetted7 = 0; int nWidthOfsetted7 = 0; int nTopOfsetted7 = 0; int nLeftOfsetted7 = 0;
int nHeightOfsetted8 = 0; int nWidthOfsetted8 = 0; int nTopOfsetted8 = 0; int nLeftOfsetted8 = 0;

__declspec(naked) void CashShopFix1() {
	__asm {
		push	nHeightOfsetted1
		push	nWidthOfsetted1
		push	nTopOfsetted1
		push	nLeftOfsetted1
		jmp dword ptr[dwCashFix1Rtm]
	}
}

__declspec(naked) void CashShopFix2() {
	__asm {
		push	nHeightOfsetted2
		push	nWidthOfsetted2
		push	nTopOfsetted2
		push	nLeftOfsetted2
		jmp dword ptr[dwCashFix2Rtm]
	}
}

__declspec(naked) void CashShopFix3() {
	__asm {
		push	nHeightOfsetted3
		push	nWidthOfsetted3
		push	nTopOfsetted3
		push	nLeftOfsetted3
		jmp dword ptr[dwCashFix3Rtm]
	}
}

__declspec(naked) void CashShopFix4() {
	__asm {
		push	nHeightOfsetted4
		push	nWidthOfsetted4
		push	nTopOfsetted4
		push	nLeftOfsetted4
		jmp dword ptr[dwCashFix4Rtm]
	}
}

__declspec(naked) void CashShopFix5() {
	__asm {
		push	nHeightOfsetted5
		push	nWidthOfsetted5
		push	nTopOfsetted5
		push	nLeftOfsetted5
		jmp dword ptr[dwCashFix5Rtm]
	}
}

__declspec(naked) void CashShopFix6() {
	__asm {
		push	nHeightOfsetted6
		push	nWidthOfsetted6
		push	nTopOfsetted6
		jmp dword ptr[dwCashFix6Rtm]
	}
}

__declspec(naked) void CashShopFix7() {
	__asm {
		push	nHeightOfsetted7
		push	nWidthOfsetted7
		push	nTopOfsetted7
		push	nLeftOfsetted7
		jmp dword ptr[dwCashFix7Rtm]
	}
}

__declspec(naked) void CashShopFix8() {
	__asm {
		push	nHeightOfsetted8
		push	nWidthOfsetted8
		push	nTopOfsetted8
		push	nLeftOfsetted8
		jmp dword ptr[dwCashFix8Rtm]
	}
}

__declspec(naked) void CashShopFixOnOff() {	//could be improved upon because idk if it's the right way to do it or if it might cause issues
	__asm {
		pop	ebx
		push ecx
		mov ecx, dword ptr[dwCashFixOnOffCall]
		call ecx
		add esp, 4
		leave
		retn    4
	}
}

int nHeightOfsettedPrev = 0; int nWidthOfsettedPrev = 0; int nTopOfsettedPrev = 0; int nLeftOfsettedPrev = 0;

__declspec(naked) void CashShopFixPrev() {
	__asm {
		push	nHeightOfsettedPrev
		push	nWidthOfsettedPrev
		push	nTopOfsettedPrev
		push	nLeftOfsettedPrev
		jmp dword ptr[dwCashFixPrevRtm]
	}
}

__declspec(naked) void HairFaceIdUncap1()
{
	__asm {
		cmp eax, 0x2
		je FACE_RET
		cmp eax, 0x5
		je FACE_RET
		cmp eax, 0x3
		je HAIR_RET
		cmp eax, 0x4
		je HAIR_RET
		cmp eax, 0x6
		je HAIR_RET
		jmp CAP_RET
		FACE_RET :
		jmp dword ptr[dwHairFaceUncapFaceRetn]
			HAIR_RET :
			jmp dword ptr[dwHairFaceUncapHairRetn]
			CAP_RET :
			jmp dword ptr[dwHairFaceUncapCapRetn]
	}
}

__declspec(naked) void HairFaceIdUncap2()
{
	__asm {
		cmp eax, 0x2
		je FACE_RET
		cmp eax, 0x5
		je FACE_RET
		cmp eax, 0x3
		je HAIR_RET
		cmp eax, 0x4
		je HAIR_RET
		cmp eax, 0x6
		je HAIR_RET
		jmp SKIN_RET
		FACE_RET :
		mov eax, 0x0
			mov ecx, 0x0
			jmp JMP_RET
			HAIR_RET :
		mov eax, 0x1
			mov ecx, 0x1
			jmp JMP_RET
			SKIN_RET :
		mov eax, 0x2
			mov ecx, 0x2
			jmp JMP_RET
			JMP_RET :
		jmp dword ptr[dwHairFaceUncapRetn]
	}
}

int nTopOfsettedVerFix = 0; int nLeftOfsettedVerFix = 0;

__declspec(naked) void VersionNumberFix() {
	__asm {
		mov    eax, nLeftOfsettedVerFix
		sub    eax, DWORD PTR[ebp - 0x1c]
		push	nTopOfsettedVerFix
		jmp dword ptr[dwVersionNumberFixRtm]
	}
}

int myAlwaysViewRestoreFixOffset = 0;

__declspec(naked) void AlwaysViewRestoreFix() {
	__asm {
		test	eax, eax
		jnz C_Dest
		mov ecx, myAlwaysViewRestoreFixOffset
		push myAlwaysViewRestoreFixOffset
		jmp dword ptr[dwAlwaysViewRestorerFixRtm]
		C_Dest:
		mov ecx, DWORD PTR[eax]
			push eax
			jmp dword ptr[dwAlwaysViewRestorerFixRtm]
	}
}

//int nHeightOfsettedloginFrameFix = 0; int nWidthOfsettedloginFrameFix = 0;
//int nTopOfsettedloginFrameFix = 0; int nLeftOfsettedloginFrameFix = 0;

//__declspec(naked) void loginFrameFix() {
//	__asm {
//		pop ebx
////		push 1
//		push 0
//		push 1
//		push	nHeightOfsettedloginFrameFix
//		push	nWidthOfsettedloginFrameFix
//		push	nTopOfsettedloginFrameFix
//		push	nLeftOfsettedloginFrameFix
//		push esi
//		call dword ptr[dwloginFrameFixCall]
//		add esp, 4
//		leave
//		retn 4
//	}
//}

int nHeightOfsettedLoginBackCanvasFix = 0; int nWidthOfsettedLoginBackCanvasFix = 0;
int nTopOfsettedLoginBackCanvasFix = 0; int nLeftOfsettedLoginBackCanvasFix = 0;

__declspec(naked) void ccLoginBackCanvasFix() {
	__asm {
		push	nHeightOfsettedLoginBackCanvasFix
		push	nWidthOfsettedLoginBackCanvasFix
		push	nTopOfsettedLoginBackCanvasFix
		push	nLeftOfsettedLoginBackCanvasFix
		jmp dword ptr[dwLoginBackCanvasFixRetn]
	}
}

int nHeightOfsettedLoginViewRecFix = 0; int nWidthOfsettedLoginViewRecFix = 0;
int nTopOfsettedLoginViewRecFix = 0; int nLeftOfsettedLoginViewRecFix = 0;

//__declspec(naked) void ccLoginViewRecFix() {
//	__asm {
//		push	nHeightOfsettedLoginViewRecFix
//		push	nWidthOfsettedLoginViewRecFix
//		push	nTopOfsettedLoginViewRecFix
//		push	nLeftOfsettedLoginViewRecFix
//		jmp dword ptr[dwLoginViewRecFixRetn]
//	}
//}

int yOffsetOfLoginBackBtnFix = 0; int xOffsetOfLoginBackBtnFix = 0;

__declspec(naked) void ccLoginBackBtnFix() {	//un used
	__asm {
		mov    esi, yOffsetOfLoginBackBtnFix
		push	esi
		mov    edi, xOffsetOfLoginBackBtnFix
		push	edi
		push   0x3e8
		jmp dword ptr[dwLoginBackBtnFixRetn]
	}
}

int a1x = 0; int a2x = 0; int a2y = 0; int a3 = 0; int a1y = 0;

__declspec(naked) void ccLoginDescriptorFix() {
	__asm {
		and edx, 0x3f
		add    edx, 0x21
		add    edx, a2y
		cmp     ecx, edi
		setl   bl
		mov     ecx, esi
		mov    DWORD PTR[esi + 0x4], 0xaf7084
		mov    DWORD PTR[esi + 0x8], 0xaf7080
		neg     ebx
		sbb     ebx, ebx
		and ebx, a3	//and ebx, 0x64
		add     ebx, eax
		push    ebx
		push    edx
		xor eax, eax
		add eax, a1x //a1x
		push    eax
		push    edx
		push    eax
		push    edx
		mov    eax, a2x	//mov    eax, 0xffffff6b
		push    eax
		push	edi
		jmp dword ptr[dwLoginDescriptorFixRetn]
	}
}

int MoreGainMsgsOffset = 6;

__declspec(naked) void ccMoreGainMsgs() {
	__asm {
		mov    eax, DWORD PTR[edi + 0x10]
		cmp    eax, MoreGainMsgsOffset
		jmp dword ptr[dwMoreGainMsgsRetn]
	}
}

int MoreGainMsgsFadeOffset = 0;

__declspec(naked) void ccMoreGainMsgsFade() {
	__asm {
		add eax, MoreGainMsgsFadeOffset
		push 3
		jmp dword ptr[dwMoreGainMsgsFadeRetn]
	}
}

int MoreGainMsgsFade1Offset = 0;

__declspec(naked) void ccMoreGainMsgsFade1() {
	__asm {
		push MoreGainMsgsFade1Offset
		jmp dword ptr[dwMoreGainMsgsFade1Retn]
	}
}

int yOffsetOfMuruengraidPlayer = 50; int xOffsetOfMuruengraidPlayer = 169;

__declspec(naked) void ccMuruengraidPlayer() {
	__asm {
		push yOffsetOfMuruengraidPlayer
		push xOffsetOfMuruengraidPlayer
		push ecx
		jmp dword ptr[dwMuruengraidPlayerRetn]
	}
}

int yOffsetOfMuruengraidClock = 26; int xOffsetOfMuruengraidClock = 400;

__declspec(naked) void ccMuruengraidClock() {
	__asm {
		push yOffsetOfMuruengraidClock
		push xOffsetOfMuruengraidClock
		push ecx
		jmp dword ptr[dwMuruengraidClockRetn]
	}
}

int yOffsetOfMuruengraidMonster = 50; int xOffsetOfMuruengraidMonster = 631;

__declspec(naked) void ccMuruengraidMonster() {
	__asm {
		push yOffsetOfMuruengraidMonster
		push xOffsetOfMuruengraidMonster
		push ecx
		jmp dword ptr[dwMuruengraidMonsterRetn]
	}
}

int yOffsetOfMuruengraidMonster1 = 32; int xOffsetOfMuruengraidMonster1 = 317;

__declspec(naked) void ccMuruengraidMonster1() {
	__asm {
		push yOffsetOfMuruengraidMonster1
		push xOffsetOfMuruengraidMonster1
		jmp dword ptr[dwMuruengraidMonster1Retn]
	}
}

int yOffsetOfMuruengraidMonster2 = 32; int xOffsetOfMuruengraidMonster2 = 482;

__declspec(naked) void ccMuruengraidMonster2() {
	__asm {
		push yOffsetOfMuruengraidMonster2
		push xOffsetOfMuruengraidMonster2
		jmp dword ptr[dwMuruengraidMonster2Retn]
	}
}

int yOffsetOfMuruengraidEngBar = 86; int xOffsetOfMuruengraidEngBar = 17;

__declspec(naked) void ccMuruengraidEngBar() {
	__asm {
		push yOffsetOfMuruengraidEngBar
		push xOffsetOfMuruengraidEngBar
		push ecx
		jmp dword ptr[dwMuruengraidEngBarRetn]
	}
}

int yOffsetOfMuruengraidEngBar1 = 130; int xOffsetOfMuruengraidEngBar1 = 20;

__declspec(naked) void ccMuruengraidEngBar1() {
	__asm {
		push yOffsetOfMuruengraidEngBar1
		push xOffsetOfMuruengraidEngBar1
		push ecx
		jmp dword ptr[dwMuruengraidEngBar1Retn]
	}
}

int yOffsetOfMuruengraidEngBar2 = 80; int xOffsetOfMuruengraidEngBar2 = 9;

__declspec(naked) void ccMuruengraidEngBar2() {
	__asm {
		push yOffsetOfMuruengraidEngBar2
		push xOffsetOfMuruengraidEngBar2
		push ecx
		jmp dword ptr[dwMuruengraidEngBar2Retn]
	}
}

int yOffsetOfMuruengraidClearRoundUI = 260; int xOffsetOfMuruengraidClearRoundUI = 400;

__declspec(naked) void ccMuruengraidClearRoundUI() {
	__asm {
		mov ecx, esi
		push yOffsetOfMuruengraidClearRoundUI
		push xOffsetOfMuruengraidClearRoundUI
		jmp dword ptr[dwMuruengraidClearRoundUIRetn]
	}
}

int yOffsetOfMuruengraidTimerCanvas = 28; int xOffsetOfMuruengraidTimerCanvas = 112;

__declspec(naked) void ccMuruengraidTimerCanvas() {
	__asm {
		push yOffsetOfMuruengraidTimerCanvas
		movsd
		push xOffsetOfMuruengraidTimerCanvas
		jmp dword ptr[dwMuruengraidTimerCanvasRetn]
	}
}

int yOffsetOfMuruengraidTimerMinutes = 0; int xOffsetOfMuruengraidTimerMinutes = 0;

__declspec(naked) void ccMuruengraidTimerMinutes() {
	__asm {
		mov    DWORD PTR[esi + 0x848], edi
		push eax
		push yOffsetOfMuruengraidTimerMinutes
		push xOffsetOfMuruengraidTimerMinutes
		jmp dword ptr[dwMuruengraidTimerMinutesRetn]
	}
}

int yOffsetOfMuruengraidTimerSeconds = 0; int xOffsetOfMuruengraidTimerSeconds = 68;

__declspec(naked) void ccMuruengraidTimerSeconds() {
	__asm {
		mov ecx, esi
		push edx
		push yOffsetOfMuruengraidTimerSeconds
		push xOffsetOfMuruengraidTimerSeconds
		jmp dword ptr[dwMuruengraidTimerSecondsRetn]
	}
}

int yOffsetOfMuruengraidTimerBar = 16; int xOffsetOfMuruengraidTimerBar = 345;

__declspec(naked) void ccMuruengraidTimerBar() {
	__asm {
		push yOffsetOfMuruengraidTimerBar
		push xOffsetOfMuruengraidTimerBar
		jmp dword ptr[dwMuruengraidTimerBarRetn]
	}
}

int xOffsetOfMuruengraidMonster1_2 = 318;

__declspec(naked) void ccMuruengraidMonster1_2() {
	__asm {
		mov    edx, xOffsetOfMuruengraidMonster1_2
		jmp dword ptr[dwMuruengraidMonster1_2Retn]
	}
}

__declspec(naked) void ccStatsSubMov() {
	__asm {
		mov     ecx, esi
		add   DWORD PTR[ebp + 0x8], 84 //260-176
		push   DWORD PTR[ebp + 0x8]
		jmp dword ptr[dwStatsSubMovRetn]
	}
}
//beginning of packed client run caves

__declspec(naked) void ccCLoginSendCheckPasswordPacket() {
	__asm {
		jmp dword ptr[dwCLoginSendCheckPasswordPacketRetn]
	}
}

__declspec(naked) void cc0x0044E550() {
	__asm {
		jmp dword ptr[dw0x0044E550Retn]
	}
}

__declspec(naked) void cc0x0044E5BE() {
	__asm {
		jmp dword ptr[dw0x0044E5BERetn]
	}
}

__declspec(naked) void cc0x0044E5DB() {
	__asm {
		jmp dword ptr[dw0x0044E5DBRetn]
	}
}

__declspec(naked) void cc0x0044E6AC() {
	__asm {
		jmp dword ptr[dw0x0044E6ACRetn]
	}
}

__declspec(naked) void cc0x0044E71D() {
	__asm {
		jmp dword ptr[dw0x0044E71DRetn]
	}
}

__declspec(naked) void cc0x0044E80C() {
	__asm {
		jmp dword ptr[dw0x0044E80CRetn]
	}
}

__declspec(naked) void cc0x0044E8B4() {
	__asm {
		jmp dword ptr[dw0x0044E8B4Retn]
	}
}

__declspec(naked) void cc0x0044EA22() {
	__asm {
		jmp dword ptr[dw0x0044EA22Retn]
	}
}

__declspec(naked) void cc0x0044EA6F() {
	__asm {
		jmp dword ptr[dw0x0044EA6FRetn]
	}
}

__declspec(naked) void cc0x0044EBD6() {
	__asm {
		jmp dword ptr[dw0x0044EBD6Retn]
	}
}

__declspec(naked) void cc0x0044ECA1() {
	__asm {
		jmp dword ptr[dw0x0044ECA1Retn]
	}
}

__declspec(naked) void cc0x0044ED32() {
	__asm {
		jmp dword ptr[dw0x0044ED32Retn]
	}
}

__declspec(naked) void cc0x0044ED52() {
	__asm {
		jmp dword ptr[dw0x0044ED52Retn]
	}
}

__declspec(naked) void cc0x0044EED3() {
	__asm {
		jmp dword ptr[dw0x0044EED3Retn]
	}
}

__declspec(naked) void cc0x00494943() {
	__asm {
		jmp dword ptr[dw0x00494943Retn]
	}
}

__declspec(naked) void cc0x00494BB6() {
	__asm {
		jmp dword ptr[dw0x00494BB6Retn]
	}
}

__declspec(naked) void cc0x00494CA9() {
	__asm {
		jmp dword ptr[dw0x00494CA9Retn]
	}
}

__declspec(naked) void cc0x00494CF0() {
	__asm {
		jmp dword ptr[dw0x00494CF0Retn]
	}
}

__declspec(naked) void cc0x00494D3B() {
	__asm {
		jmp dword ptr[dw0x00494D3BRetn]
	}
}

__declspec(naked) void cc0x00494EAF() {
	__asm {
		jmp dword ptr[dw0x00494EAFRetn]
	}
}

__declspec(naked) void cc0x00494EEC() {
	__asm {
		jmp dword ptr[dw0x00494EECRetn]
	}
}

__declspec(naked) void cc0x00494F87() {
	__asm {
		jmp dword ptr[dw0x00494F87Retn]
	}
}

__declspec(naked) void cc0x009F4E84() {
	__asm {
		jmp dword ptr[dw0x009F4E84Retn]
	}
}

__declspec(naked) void cc0x009F4EC3() {
	__asm {
		jmp dword ptr[dw0x009F4EC3Retn]
	}
}

__declspec(naked) void cc0x009F4F12() {
	__asm {
		jmp dword ptr[dw0x009F4F12Retn]
	}
}

__declspec(naked) void cc0x009F4FC6() {
	__asm {
		jmp dword ptr[dw0x009F4FC6Retn]
	}
}

__declspec(naked) void cc0x009F503C() {
	__asm {
		jmp dword ptr[dw0x009F503CRetn]
	}
}

__declspec(naked) void cc0x009F51A7() {
	__asm {
		jmp dword ptr[dw0x009F51A7Retn]
	}
}

__declspec(naked) void cc0x009F526F() {
	__asm {
		jmp dword ptr[dw0x009F526FRetn]
	}
}

__declspec(naked) void cc0x009F5653() {
	__asm {
		jmp dword ptr[dw0x009F5653Retn]
	}
}

__declspec(naked) void cc0x009F5833() {
	__asm {
		jmp dword ptr[dw0x009F5833Retn]
	}
}

__declspec(naked) void cc0x009F5C2C() {
	__asm {
		jmp dword ptr[dw0x009F5C2CRetn]
	}
}

__declspec(naked) void cc0x009F5CA3() {
	__asm {
		jmp dword ptr[dw0x009F5CA3Retn]
	}
}

__declspec(naked) void cc0x009F5FBD() {
	__asm {
		jmp dword ptr[dw0x009F5FBDRetn]
	}
}

__declspec(naked) void cc0x009F631C() {
	__asm {
		jmp dword ptr[dw0x009F631CRetn]
	}
}

__declspec(naked) void cc0x009F691F() {
	__asm {
		jmp dword ptr[dw0x009F691FRetn]
	}
}

__declspec(naked) void cc0x009F6F36() {
	__asm {
		jmp dword ptr[dw0x009F6F36Retn]
	}
}

__declspec(naked) void cc0x009F6F5C() {
	__asm {
		jmp dword ptr[dw0x009F6F5CRetn]
	}
}

__declspec(naked) void cc0x009F7CFA() {
	__asm {
		jmp dword ptr[dw0x009F7CFARetn]
	}
}

__declspec(naked) void cc0x009F7D83() {
	__asm {
		jmp dword ptr[dw0x009F7D83Retn]
	}
}

__declspec(naked) void cc0x009F81FB() {
	__asm {
		jmp dword ptr[dw0x009F81FBRetn]
	}
}

__declspec(naked) void cc0x009F84E9() {
	__asm {
		jmp dword ptr[dw0x009F84E9Retn]
	}
}

__declspec(naked) void cc0x009F8AD4() {
	__asm {
		jmp dword ptr[dw0x009F8AD4Retn]
	}
}

__declspec(naked) void cc0x00A4BB39() {
	__asm {
		jmp dword ptr[dw0x00A4BB39Retn]
	}
}

__declspec(naked) void cc0x00A4BC79() {
	__asm {
		jmp dword ptr[dw0x00A4BC79Retn]
	}
}

__declspec(naked) void cc0x00A4BD05() {
	__asm {
		jmp dword ptr[dw0x00A4BD05Retn]
	}
}

__declspec(naked) void cc0x00A4BD4E() {
	__asm {
		jmp dword ptr[dw0x00A4BD4ERetn]
	}
}

__declspec(naked) void cc0x00A4BD99() {
	__asm {
		jmp dword ptr[dw0x00A4BD99Retn]
	}
}

__declspec(naked) void cc0x00A4BDE3() {
	__asm {
		jmp dword ptr[dw0x00A4BDE3Retn]
	}
}

__declspec(naked) void cc0x00A4BDFE() {
	__asm {
		jmp dword ptr[dw0x00A4BDFERetn]
	}
}

__declspec(naked) void cc0x00A4BE47() {
	__asm {
		jmp dword ptr[dw0x00A4BE47Retn]
	}
}


const char myWzFile[] = "TamingMob";
const char* ptrmyWzFile = myWzFile;

int MINT = 51 + 1;
const DWORD dwTesting = 0x009F74D2;
const DWORD dwTestingRetn = 0x009F74EA;
const int TestingNOPs = 24;
__declspec(naked) void testingCodeCave() {
	__asm {
		mov    DWORD PTR[ebp - 0x78], 0xb3f434
		mov    DWORD PTR[ebp - 0x74], 0xb3f42c
		mov    DWORD PTR[ebp - 0x70], 0xb3f428
		mov    DWORD PTR[ebp - 0x6C], 0xb3f428
		mov    DWORD PTR[ebp - 0x18], edi
		jmp dword ptr[dwTestingRetn]
	}
}

const DWORD dwTesting2 = 0x005549F8;
const DWORD dwTesting2Retn = 0x005549FD;
const int Testing2NOPs = 5;
__declspec(naked) void testingCodeCave2() {
	__asm {
		//call dword ptr[custom_sub_4289B7]
		jmp dword ptr[dwTesting2Retn]
	}
}

const DWORD dwTesting3 = 0x005556CC;
const DWORD dwTesting3Retn = 0x005556D5;
const int Testing3NOPs = 9;
__declspec(naked) void testingCodeCave3() {
	__asm {
		mov    DWORD PTR[esi + 0x848], edi
		push eax
		push 80//0
		push 250//0
		jmp dword ptr[dwTesting3Retn]
	}
}

const DWORD dwTesting4 = 0x005556E6;
const DWORD dwTesting4Retn = 0x005556EC;
const int Testing4NOPs = 6;
__declspec(naked) void testingCodeCave4() {
	__asm {
		mov ecx, esi
		push edx
		push 80//0
		push 318//68
		jmp dword ptr[dwTesting4Retn]
	}
}


// ===== Cash Effect Id Expansion CodeCaves =====
const DWORD dwCashEffExpansion1 = 0x0093C144;
const DWORD dwCashEffExpansion1CheckRtm = 0x0093C156;
const DWORD dwCashEffExpansion1Rtm = 0x0093C163;
const int dwCashEffExpansion1NOPs = 13; // TBD

__declspec(naked) void cash_effect_expansion_1()
{
	__asm {
		mov eax, [ebp + 8] // item ID
		cdq
		mov ecx, 0x2710 // 10000
		idiv ecx
		cmp eax, 0x1F5 // 501
		je enable_loop

		mov eax, [ebp + 8] // item ID
		cdq
		mov ecx, 0x3E8 // 1000
		idiv ecx
		jmp dword ptr[dwCashEffExpansion1CheckRtm] // back to check for 4290xxx

		enable_loop:
		jmp dword ptr[dwCashEffExpansion1Rtm] // set ani type to 32
	}
}

const DWORD dwCashEffExpansion2 = 0x0093C67A;
const DWORD dwCashEffExpansion2CheckRtm = 0x0093C690;
const DWORD dwCashEffExpansion2Rtm = 0x0093C69A;
const int dwCashEffExpansion2NOPs = 13; // TBD

__declspec(naked) void cash_effect_expansion_2()
{
	__asm {
		mov eax, [ebp + 8] // item ID
		cdq
		mov ecx, 0x2710 // 10000
		idiv ecx
		cmp eax, 0x1F5 // 501
		je enable_loop

		mov eax, [ebp + 8] // item ID
		cdq
		mov ecx, 0x3E8 // 1000
		idiv ecx
		jmp dword ptr[dwCashEffExpansion2CheckRtm] // back to check for 4290xxx

		enable_loop:
		jmp dword ptr[dwCashEffExpansion2Rtm] // set ani type to 32
	}
}


//const DWORD dwCashEffExpansion2 = 0x0093C67E;
//const DWORD dwCashEffExpansion2Rtm = 0x004AB11D;
//const int dwCashEffExpansion2NOPs = 14;
//
//const DWORD dwCashEffExpansion3 = 0x0095B112;
//const DWORD dwCashEffExpansion3Rtm = 0x004AB11D;
//const int dwCashEffExpansion3NOPs = 14;


//expanded vendor 

const void* shop_dlg_fix_retn_1 = reinterpret_cast<void*>(0x00755B18); // starting at
__declspec(naked) void shop_dlg_fix_1()
{
	_asm {
	main_shop_fix_1:

		cmp dword ptr[eax + 2Ch], 0x20000002
			jle register_1
			continue_1 :
		cmp dword ptr[eax + 34h], 0x20000002
			jle register_2
			continue_2 :
		cmp dword ptr[eax + 3Ch], 0x20000002
			jle register_3
			continue_3 :
		cmp dword ptr[eax + 44h], 0x20000002
			jle register_4
			jmp shop_proceed_normally

			register_1 :
		mov dword ptr[eax + 2Ch], 0x00000000
			jmp continue_1
			register_2 :
		mov dword ptr[eax + 34h], 0x00000000
			jmp continue_2
			register_3 :
		mov dword ptr[eax + 3Ch], 0x00000000
			jmp continue_3
			register_4 :
		mov dword ptr[eax + 44h], 0x00000000
			jmp shop_proceed_normally

			shop_proceed_normally :
		mov ecx, [ebp - 24]
			mov ecx, [eax + ecx + 04]
			jmp[shop_dlg_fix_retn_1]
	}
};


//double jump by goose
// Part 1
extern "C" int jumpCount = 0;
const void* dblJumpFalse = reinterpret_cast<void*>(0x009B2139);
const void* jumpReturnAddress = reinterpret_cast <void*>(0x009B204B);
const void* proceedDoubleJump = reinterpret_cast<void*>(0x009B2053);

__declspec(naked) void evaluateHasJumped() {
	__asm {
		pushfd
		pushad
		cmp[jumpCount], 1
		je goToEnd

		popad
		popfd
		jmp[proceedDoubleJump]
		goToEnd:
		popad
			popfd
			jmp[dblJumpFalse]
	}
}
// Part 2 
extern "C" const double jumpMult = 2.5;
const void* firstCall = reinterpret_cast <void*>(0x006724FC);
const void* continueAddress = reinterpret_cast <void*>(0x009B211C);
const void* fixed_call = reinterpret_cast<void*>(0x00BEBFA0);

__declspec(naked) void jumpPhysics() {
	__asm {
		mov eax, [esi + 424]//1A8h old hex offset
		lea ecx, [eax + 6Ch]//84h old hex offset

		call firstCall
		mov eax, [fixed_call]
		mov eax, dword ptr[eax]
		mov eax, [eax + 8]
		fmul qword ptr[eax + 72]
		fmul qword ptr[ebp - 32]
		fmul[jumpMult]
		inc dword ptr[jumpCount]
		jmp continueAddress
	}
}
// Part 3, clear "JumpCount"
const int push_val = 2273;
const void* onGroundJumpProceed = reinterpret_cast <void*>(0x009B201D);
__declspec(naked) void clearJumps() {
	__asm {
		lea eax, [ebp - 18h]
		push[push_val]
		mov dword ptr[jumpCount], 0
		jmp[onGroundJumpProceed]
	}
}

//fire arrow

DWORD dwFireArrow = 0x00955DA8;
DWORD dwFireArrowRet = 0x00955DAD; // fail
DWORD dwFireSucc = 0x00956372; // multi mob attack
__declspec(naked) void FireArrow() {
	__asm {
		cmp eax, 12121002
		je success
		cmp eax, 12121012
		je success
		cmp eax, 12121054
		je success
		cmp eax, 12121055
		je success
		cmp eax, 2121006
		je success
		cmp eax, 2121052
		je success
		cmp eax, 2121054
		je success
		cmp eax, 0x0021E3CB
		jmp dwFireArrowRet
		success :
		jmp dwFireSucc
	}
}

DWORD dwFireBulletAdd = 0x00956445;
DWORD dwFireBulletSucc = 0x0095645B;
DWORD dwFireBulletRet = 0x0095644E;
__declspec(naked) void FireArrowBullet() {
	__asm {
		cmp dword ptr[ebp - 0x14], 2221003
		je success
		cmp dword ptr[ebp - 0x14], 2101004
		je success
		cmp dword ptr[ebp - 0x14], 2301005
		je success
		cmp dword ptr[ebp - 0x14], 2321007
		je success
		jmp dwFireBulletRet
		success :
		jmp dwFireBulletSucc
	}
}


//super tubi - alternative method
//__declspec(naked) void ccTubi() {
//	__asm {
//		mov    eax, 1
//		ret 8
//	}
//}

//goose lt/rb to any area
// LT/RB implementation, any skill
const void* return_Address_LtRb = reinterpret_cast<void*>(0x00953E5C);
const void* continue_Address_LtRb = reinterpret_cast<void*>(0x00953E32);
__declspec(naked) void LtRb_Eval() {
	__asm {
		cmp dword ptr[ebp - 16], 4111005
		je Label_return_LtRb
		//cmp dword ptr[ebp-16], "YourSkillIDHere"
		//je Label_return_Address_Avenger
		//mortal blow xbow
		cmp dword ptr[ebp - 16], 3201005
		je Label_return_LtRb

		mov ecx, [ebp - 180]
		jmp[Label_return_LtRb]

		Label_return_LtRb:
		jmp[return_Address_LtRb]
	}
}

//goose keyskill expansion// Codecaves

DWORD Array_aDefaultQKM_Address = (DWORD)&Array_aDefaultQKM;
DWORD Array_mystery_Address = (DWORD)&Array_Expanded;
DWORD Array_mystery_Address_plus = (DWORD)&Array_Expanded + 1;
DWORD cooldown_Array_Address = (DWORD)&cooldown_Array;
DWORD Array_Expanded_Testing_Cooldown_fix_Address = (DWORD)&Array_Expanded_Testing_Cooldown_fix;

DWORD CompareValidate_Retn = 0x8DD8BD;
_declspec(naked) void CompareValidateFuncKeyMappedInfo_cave()
{
	_asm
	{
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		jmp CompareValidate_Retn
			//push 0x8DD8BD;
			//ret;
	}
}

DWORD sub_9FA0CB_cave_retn_1 = 0x9FA0E1;
_declspec(naked) void sub_9FA0CB_cave()
{
	_asm {
		test eax, eax;
		jne label;
		push 0xD4;
		pushad;
		popad;
		// -> ZAllocEx<ZAllocAnonSelector>::Alloc(ZAllocEx<ZAllocAnonSelector>::_s_alloc, 0x44u);
		//push 0x9FA0E1;
		//ret;
		jmp sub_9FA0CB_cave_retn_1
			label :
		push 0x138;
		push 0x0;
		push eax;
		pushad;
		popad;
		// -> memset(this + 0xD20, 0, 0x60u);
		//push 0x8DD8BD;
		//ret;
		jmp CompareValidate_Retn
	}
}
//DWORD sDefaultQuickslotKeyMap_cave_retn = 0x72B7C2;
_declspec(naked) void sDefaultQuickslotKeyMap_cave()
{
	_asm {
		push ebx;
		push esi;
		push edi;
		xor edx, edx;
		mov ebx, ecx;
		call label;
		nop;
		lea edi, dword ptr ds : [ebx + 0x4] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		lea edi, dword ptr ds : [ebx + 0x6C] ;
		mov ecx, 0x1A;
		mov esi, Array_aDefaultQKM_Address;
		rep movsd;
		pop edi;
		pop esi;
		pop ebx;
		ret;
		// 0xBF8EE8
	label:
		push esi;
		mov esi, ecx;
		lea eax, dword ptr ds : [esi + 0x4] ;
		// -> _DWORD *__fastcall sub_72B7BC(_DWORD *a1)
		push 0x72B7C2;
		ret;
		//jmp sDefaultQuickslotKeyMap_cave_retn
	}
}
_declspec(naked) void DefaultQuickslotKeyMap_cave()
{
	_asm {
		push esi;
		push edi;
		lea eax, dword ptr ds : [ecx + 0x4] ;
		mov esi, Array_aDefaultQKM_Address;
		mov ecx, 0x1A;
		mov edi, eax;
		rep movsd;
		pop edi;
		pop esi;
		ret;
	}
}
_declspec(naked) void Restore_Array_Expanded() //Thank you Max
{
	_asm {
		lea eax, [esi + 0D7Ch]
		push esi
		push edi
		push ecx
		mov esi, [Array_Expanded_Testing_Cooldown_fix_Address]
		mov edi, Array_mystery_Address
		mov ecx, 78
		rep movsd
		pop ecx
		pop edi
		pop esi
		push 0x008CFE03;
		ret;
	}
}

//recoil shot

DWORD dwRecoilShot = 0x00953646;
DWORD dwRecoilShotRet = 0x0095364D;
DWORD dwRecoilShotSucc = 0x00953669;
__declspec(naked) void RecoilShotLowerCD() {
	__asm {
		cmp eax, 5201006
		je success
		jmp dwRecoilShotRet
		success :
		mov eax, 100//700 //originally 2000ms
			jmp dwRecoilShotSucc
	}
}

//no charge on pierce arrow
DWORD dwPA = 0x00968048;
DWORD dwPAReturn = 0x00967B8B;
DWORD dwPAS = 0x009690E9;
__declspec(naked) void PA() {
	__asm {
		je PAS
		jmp dword ptr[dwPAReturn]
		PAS:
		jmp dword ptr[dwPAS]
	}
}

//corckscrew blow
DWORD dwCB = 0x00968278;
DWORD dwCBReturn = 0x00967B8B;
DWORD dwCBS = 0x009690AE;
__declspec(naked) void CorkscrewBlow() {
	__asm {
		je CBS
		jmp dword ptr[dwCBReturn]
		CBS:
		jmp dword ptr[dwCBS]
	}
}

//big bang
DWORD dwBB = 0x00967ECC;
DWORD dwBBReturn = 0x00967ED2;
DWORD dwBBS = 0x0096928B;
__declspec(naked) void BigBang() {
	__asm {
		je BBS
		jmp dword ptr[dwBBReturn]
		BBS:
		jmp dword ptr[dwBBS]
	}
}

//chatline fix
DWORD chat_Y_offset_retn = 0x008DD6BE;
DWORD call_func_chat_cave = 0x00403382;

__declspec(naked) void chat_Y_offset_cave()
{
	_asm {
		call call_func_chat_cave
		push eax
		mov eax, [ebp - 28h]
		dec eax
		mov[ebp - 28h], eax
		pop eax
		jmp chat_Y_offset_retn
	}
};


void UpdateResolution() {
	nStatusBarY = m_nGameHeight - 578;

	CodeCave(AdjustStatusBar, dwStatusBarVPos, 5);
	CodeCave(AdjustStatusBarBG, dwStatusBarBackgroundVPos, 5);
	CodeCave(AdjustStatusBarInput, dwStatusBarInputVPos, 9);
	if (m_nGameHeight != 600) write_to_mem(0x0064208F + 1, 300 + static_cast<int>((m_nGameHeight - 600) / 1.75f)); // viewrange.bottom
	write_to_mem<uint8_t>(0x00620827 + 1, 120);
	WriteValue(dwApplicationHeight + 1, m_nGameHeight);//push 600
	WriteValue(dwApplicationWidth + 1, m_nGameWidth);	//push 800 ; CWvsApp::InitializeGr2D
	WriteValue(dwCursorVectorVPos + 2, (unsigned int)floor(-m_nGameHeight / 2));//push -300				!!moves all interactable UI elements!!
	WriteValue(dwCursorVectorHPos + 2, (unsigned int)floor(-m_nGameWidth / 2));	//push -400 ; CInputSystem::SetCursorVectorPos				!!moves all interactable UI elements!!
	WriteValue(dwUpdateMouseLimitVPos + 1, m_nGameHeight);//mov ecx,600
	WriteValue(dwUpdateMouseLimitHPos + 1, m_nGameWidth);	//mov ecx,800 ; CInputSystem::UpdateMouse
	WriteValue(dwCursorPosLimitVPos + 1, m_nGameHeight);//mov eax,600
	WriteValue(dwCursorPosLimitHPos + 1, m_nGameWidth);	//mov eax,800 ; CInputSystem::SetCursorPos
	WriteValue(dwViewPortHeight + 3, m_nGameHeight);//lea eax,[esi+eax-600]
	WriteValue(dwViewPortWidth + 3, m_nGameWidth);	//lea eax,[ecx+eax-800]

	WriteValue(dwToolTipLimitVPos + 1, m_nGameHeight - 1); //mov eax,599 ; CUIToolTip::MakeLayer CRABO-BOI FIX
	WriteValue(dwToolTipLimitHPos + 1, m_nGameWidth - 1); //mov eax,799 ; CUIToolTip::MakeLayer TESTING

	WriteValue(dwTempStatToolTipDraw + 3, -m_nGameWidth + 6); //lea eax,[eax+ecx-797] ; CTemporaryStatView::ShowToolTip
	WriteValue(dwTempStatToolTipFind + 3, -m_nGameWidth + 6); //lea eax,[eax+ecx-797] ; CTemporaryStatView::FindIcon
	WriteValue(dwTempStatIconVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon buff y-pos
	WriteValue(dwTempStatIconHpos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon buff x-pos
	WriteValue(dwTempStatCoolTimeVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon cooltime y-pos
	WriteValue(dwTempStatCoolTimeHPos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon cooltime x-pos

	WriteValue(dwQuickSlotInitVPos + 1, m_nGameHeight + 1);//add eax,533
	WriteValue(dwQuickSlotInitHPos + 1, 798); //push 647 //hd800
	WriteValue(dwQuickSlotVPos + 2, m_nGameHeight + 1);//add esi,533
	WriteValue(dwQuickSlotHPos + 1, 798); //push 647 //hd800
	WriteValue(dwQuickSlotCWndVPos + 2, -500);
	WriteValue(dwQuickSlotCWndHPos + 2, -798); //lea ebx,[eax-647]

	//WriteValue(dwByteAvatarMegaHPos + 1, m_nGameWidth + 100); //push 800 ; CAvatarMegaphone::ByeAvatarMegaphone ; IWzVector2D::RelMove ##BAK
	WriteValue(dwByteAvatarMegaHPos + 1, m_nGameWidth); //push 800 ; CAvatarMegaphone::ByeAvatarMegaphone ; IWzVector2D::RelMove
	WriteValue(dwAvatarMegaWidth + 1, m_nGameWidth); //push 800 ; CAvatarMegaphone ; CreateWnd

	WriteValue(0x0043717B + 1, m_nGameHeight);//mov edi,600
	WriteValue(0x00437181 + 1, m_nGameWidth);	//mov esi,800 ; CreateWnd
	WriteValue(0x0053808B + 1, m_nGameHeight);//push 600
	WriteValue(0x00538091 + 1, m_nGameWidth);	//push 800 ; RelMove?
	WriteValue(0x004CC160 + 1, m_nGameWidth);	//mov [ebp-16],800 ; CreateWnd
	WriteValue(0x004CC2C5 + 2, m_nGameHeight);//cmp ecx,600
	WriteValue(0x004CC2B0 + 1, m_nGameWidth);	//mov eax,800 ; CreateWnd
	WriteValue(0x004D59B2 + 1, m_nGameHeight);//mov eax,800
	WriteValue(0x004D599D + 1, m_nGameWidth);	//mov eax,800 ; CreateWnd
	WriteValue(0x0085F36C + 2, m_nGameWidth);	//cmp edx,800
	WriteValue(0x0085F374 + 1, m_nGameWidth - 80);	//mov ecx,720 ; CreateDlg
	WriteValue(0x008EBC58 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x008EBC3C + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x009966B5 + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x009966CA + 2, m_nGameWidth);	//cmp edi,800
	WriteValue(0x009966D2 + 1, m_nGameWidth - 100);	//mov edx,700 ; CreateDlg
	WriteValue(0x009A3E7F + 1, m_nGameHeight);//mov edx,600
	WriteValue(0x009A3E72 + 1, m_nGameWidth);	//mov edx,800 ; CreateDlg
	//WriteValue(0x0045B898 + 1, m_nGameHeight - 25);	//push 575
	WriteValue(0x0045B898 + 1, m_nGameWidth - 225);	//push 575 ##ED  //smega x axis fade
	//WriteValue(0x0045B97E + 1, m_nGameWidth);	//push 800 ; RelMove? ##REDUN
	//WriteValue(0x004D9BD1 + 1, m_nGameWidth);	//push 800	; StringPool#1443 (BtMouseCilck)		//click ???related?? for tabs and numbers in cash shop
	//WriteValue(0x004D9C37 + 1, m_nGameWidth);	//push 800	; StringPool#1443 (BtMouseCilck)		//click ???related?? for tabs and numbers in cash shop
	//WriteValue(0x004D9C84 + 1, m_nGameWidth);	//push 800 ; StringPool#1443 (BtMouseCilck)		//click ???related?? for tabs and numbers in cash shop
	WriteValue(0x005386F0 + 1, m_nGameHeight);//push 600
	WriteValue(0x005386F5 + 1, m_nGameWidth);	//push 800 ; CField::DrawFearEffect
	WriteValue(0x0055B808 + 1, m_nGameHeight);//push 600
	WriteValue(0x0055B80D + 1, m_nGameWidth);	//mov edi,800
	WriteValue(0x0055B884 + 1, m_nGameWidth);	//push 600 ; RelMove?
	WriteValue(0x007E15BE + 1, m_nGameWidth);	//push 800 ; CreateWnd
	WriteValue(0x007E16B9 + 1, m_nGameHeight);//push 600
	WriteValue(0x007E16BE + 1, m_nGameWidth);	//push 800 ; CWnd::GetCanvas //!!length of server message at top
	WriteValue(0x008AA266 + 1, m_nGameHeight);//push 600
	WriteValue(0x008AA26B + 1, m_nGameWidth);	//push 800 ; CreateWnd
	WriteValue(0x009F6E99 + 1, m_nGameHeight);//push 600
	WriteValue(0x009F6EA0 + 1, m_nGameWidth);	//push 800 ; StringPool#1162 (MapleStoryClass)

	WriteValue(0x007CF48F + 1, m_nGameHeight);//mov eax,600 ; 
	WriteValue(0x007CF49D + 1, m_nGameWidth);	//mov eax,800 ; IWzVector2D::RelMove
	WriteValue(0x008A12F4 + 1, m_nGameHeight);//mov eax,600 ; 
	WriteValue(0x008A1302 + 1, m_nGameWidth);	//mov eax,800 ; IWzVector2D::RelMove
	WriteValue(0x007F257E + 1, m_nGameHeight);//push 600
	WriteValue(0x007F258F + 1, m_nGameWidth);	//push 800 ; CWnd::CreateWnd
	WriteValue(0x0046B85C + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x0046B86A + 1, m_nGameWidth);	//mov eax,800 ; IWzVector2D::RelMove
	WriteValue(0x009994D8 + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x009994ED + 2, m_nGameWidth);	//cmp edi,800
	WriteValue(0x009994F5 + 1, m_nGameWidth - 100);	//mov edx,700 ; CreateDlg

	WriteValue(0x0062FC4A + 1, m_nGameHeight);//push 600
	WriteValue(0x0062FC4F + 1, m_nGameWidth);	//push 800 ; IWzGr2DLayer::Getcanvas
	WriteValue(0x0062FE63 + 1, m_nGameHeight);//push 600
	WriteValue(0x0062FE68 + 1, m_nGameWidth);	//push 800 ; IWzGr2DLayer::Getcanvas
	WriteValue(0x0062F9C6 + 1, m_nGameHeight);//push 600
	WriteValue(0x0062F9CB + 1, m_nGameWidth);	//push 800; (UI/Logo/Wizet)
	WriteValue(0x0062F104 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x0062F109 + 1, m_nGameWidth);	//mov eax,800 ; Rectangle
	WriteValue(0x006406D5 + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x006406C3 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x0064050A + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x006404F8 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x00640618 + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x00640690 + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x0064061D + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x0064064B + 1, m_nGameHeight);//mov ecx,600
	WriteValue(0x00640606 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x0064067E + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x00640639 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x0064043E + 1, (unsigned int)floor(m_nGameWidth / 2));	//mov edi,400
	WriteValue(0x00640443 + 1, (unsigned int)floor(m_nGameHeight / 2));	//mov esi,300
	WriteValue(0x00640626 + 1, (unsigned int)floor(m_nGameWidth / 2));	//add eax,400 ; bunch of modulus stuff

	WriteValue(0x00641038 + 2, m_nGameHeight);//??possibly related to player display
	WriteValue(0x0064103F + 2, m_nGameWidth);//??possibly related to player display
	WriteValue(0x00641048 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//mov esi,-300
	WriteValue(0x00641050 + 1, (unsigned int)floor(-m_nGameWidth / 2));		//mov esi,-400 ;
	WriteValue(0x00641A19 + 3, m_nGameHeight);//mov [ebp+28],600
	WriteValue(0x00641A12 + 3, m_nGameWidth);	//mov [ebp+32],800 ; idk
	WriteValue(0x00641B38 + 3, m_nGameHeight);//mov [ebp-32],600
	WriteValue(0x00641B2E + 3, m_nGameWidth);	//mov [ebp-36],800 ; CAnimationDisplayer::SetCenterOrigin

	WriteValue(0x006CD842 + 1, (unsigned int)floor(m_nGameWidth / 2));	//push 400 ; RelMove?

	WriteValue(0x0059A0A2 + 6, (unsigned int)floor(m_nGameHeight / 2));	//mov [ebx+2364],300
	WriteValue(0x0059A09C + 2, (unsigned int)floor(m_nGameWidth / 2));	//mov [esi],400	; CInputSystem::LoadCursorState
	WriteValue(0x0080546C + 1, m_nGameHeight);//mov edi,600
	WriteValue(0x00805459 + 1, m_nGameWidth);	//mov edx,800 ; CUIEventAlarm::CreateEventAlarm
	WriteValue(0x008CFD4B + 1, m_nGameHeight - 22);	//push 578
	WriteValue(0x008CFD50 + 1, m_nGameWidth);	//push 800
	WriteValue(0x0053836D + 1, (unsigned int)floor(-m_nGameHeight / 2));//push -300
	WriteValue(0x00538373 + 1, (unsigned int)floor(-m_nGameWidth / 2));	//push -400	; RelMove?
	WriteValue(0x0055BB2F + 1, (unsigned int)floor(-m_nGameHeight / 2));//push -300
	WriteValue(0x0055BB35 + 1, (unsigned int)floor(-m_nGameWidth / 2));	//push -400 ; RelMove?

	WriteValue(0x005A8B46 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005A8B56 + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005A9B42 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005A9B52 + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005AADAA + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005AADBA + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005ABC65 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005ABC75 + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005ACB29 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005ACB39 + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005C187E + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005C188E + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005C2D62 + 1, m_nGameHeight);//mov eax,600
	WriteValue(0x005C2D72 + 1, m_nGameWidth);	//mov eax,800 ; RelMove?
	WriteValue(0x005E3FA0 + 1, m_nGameHeight);//push 600

	WriteValue(0x005F64DE + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x005F6627 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x005F464D + 1, (unsigned int)floor(m_nGameWidth / 2));//??related to login game frame

	WriteValue(0x0060411C + 1, m_nGameHeight);//push 600
	//WriteValue(0x00604126 + 1, floor(-m_nGameWidth / 2));	//push -300 //moves characters side to side on char select //unnecessary atm
	WriteValue(0x0060F79B + 1, (m_nGameHeight / 2) - 201);//??possibly related to login utildlg
	WriteValue(0x0060F7A4 + 1, (m_nGameHeight / 2) - 181);//??possibly related to login utildlg
	WriteValue(0x0060F7AC + 1, (m_nGameWidth / 2) - 201);//??possibly related to login utildlg
	WriteValue(0x0060F7B5 + 1, (m_nGameWidth / 2) - 181);//??possibly related to login utildlg
	WriteValue(0x00613093 + 1, (m_nGameHeight / 2) - 200);//??likely related to login pop-up msg
	WriteValue(0x00613099 + 1, (m_nGameWidth / 2) - 45);//??likely related to login pop-up msg
	WriteValue(0x0061DAFF + 1, (m_nGameHeight / 2) - 150);//??likely related to login pop-up msg
	WriteValue(0x0061DB08 + 1, (m_nGameHeight / 2) - 130);//??likely related to login pop-up msg
	WriteValue(0x0061DB10 + 1, (m_nGameWidth / 2) - 201);//??likely related to login pop-up msg
	WriteValue(0x0061DB19 + 1, (m_nGameWidth / 2) - 181);//??likely related to login pop-up msg

	WriteValue(0x004372B1 + 1, (unsigned int)floor(-m_nGameHeight / 2));//push -300
	WriteValue(0x004372B6 + 1, (unsigned int)floor(-m_nGameWidth / 2));	//push -400 ; RelMove?
	WriteValue(0x006CE3AB + 1, m_nGameWidth);	//push 800 // quest
	WriteValue(0x007E1CB7 + 1,	m_nGameWidth);	//push 800
	WriteValue(0x008D82F5 + 1, m_nGameHeight - 22);	//push 578
	WriteValue(0x008D82FA + 1, m_nGameWidth);	//push 800 ; CreateWnd?
	WriteValue(0x00935870 + 1, (unsigned int)floor(m_nGameHeight / 2));	//push 300
	WriteValue(0x0093586B + 1, m_nGameWidth);	// push 800 ; RelMove? (Skills)
	WriteValue(0x009DFD5C + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x009DFED2 + 1, m_nGameHeight);//mov ecx,600	; IWzVector2D::RelMove
	WriteValue(0x009F6ADD + 1, (unsigned int)floor(m_nGameHeight / 2)); //push 300 ; MapleStoryClass
	WriteValue(0x006D50D8 + 1, m_nGameHeight);//push 600
	WriteValue(0x0074BAA9 + 1, m_nGameHeight);//push 600
	WriteValue(0x0074B951 + 1, m_nGameHeight);//push 600
	WriteValue(0x0074B4A2 + 1, m_nGameHeight);//push 600
	WriteValue(0x0074B3B7 + 1, m_nGameHeight);//push 600
	WriteValue(0x006421B3 + 1, m_nGameHeight);//push 600 ; CSoundMan::PlayBGM

	WriteValue(0x0059EB49 + 1, m_nGameHeight);//push 600 ; CSoundMan::PlayBGM
	WriteValue(0x008D247B + 1, m_nGameHeight - 33);	//push 567 ; IWzVector2D::RelMove
	WriteValue(0x008DEB93 + 1, m_nGameHeight - 20);	//push 580
	WriteValue(0x008DEE2F + 1, m_nGameHeight - 20);	//push 580
	WriteValue(0x008D2765 + 1, m_nGameHeight - 19);	//push 581
	WriteValue(0x008D29B4 + 1, m_nGameHeight - 19);	//push 581
	WriteValue(0x008D8BFE + 1, m_nGameHeight - 19);	//push 581
	WriteValue(0x008D937E + 1, m_nGameHeight - 19);	//push 581 //008D9373  move mana bar outline? //ty rynyan
	WriteValue(0x008D9AC9 + 1, m_nGameHeight - 19);	//push  
	WriteValue(0x008D1D50 + 1, m_nGameHeight - 22);	//push 578
	WriteValue(0x008D1D55 + 1, m_nGameWidth);	//push 800
	WriteValue(0x008D1FF4 + 1, m_nGameHeight - 22);	//push 578
	WriteValue(0x008D1FF9 + 1, m_nGameWidth);	//push 800 ; CUIStatusBar
	WriteValue(0x0062F5DF + 1, m_nGameHeight);//push 600
	WriteValue(0x0062F5E4 + 1, m_nGameWidth);	//push 800 ; (UI/Logo/Nexon)
	WriteValue(0x004EDB89 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x004EDB78 + 1, m_nGameHeight);//mov ecx,600 ; CreateWnd
	WriteValue(0x004EDAD8 + 1, m_nGameWidth);	//mov ecx,800
	WriteValue(0x009F7079, m_nGameHeight);	// dd 600
	WriteValue(0x009F707E, m_nGameWidth);	// dd 800
	WriteValue(0x00BE2738, (unsigned int)floor(m_nGameWidth / 2));	// dd 400
	WriteValue(0x00BE2DF4, (unsigned int)floor(m_nGameHeight / 2));	// dd 300
	WriteValue(0x00BE2DF0, (unsigned int)floor(m_nGameWidth / 2));	// dd 400
	WriteValue(0x00640656 + 2, (unsigned int)floor(-m_nGameWidth / 2));		//add edi,-400 ;

	WriteValue(0x006CE4C6 + 1, (unsigned int)floor(-m_nGameWidth / 2));		//push -400 ;
	WriteValue(0x009E2E85 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300		overall screen visible UI scaling
	WriteValue(0x009E2E8B + 1, (unsigned int)floor(-m_nGameWidth / 2));		//push -400 ;	overall screen visible UI scaling

	WriteValue(0x0093519A + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x00954433 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x00981555 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x00981F7A + 2, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	WriteValue(0x00A448B0 + 2, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ; CWvsPhysicalSpace2D::Load]

	WriteValue(0x0066BACE + 2, (unsigned int)floor(-m_nGameWidth / 2));		//and ecx,-400
	WriteValue(0x009B76BD + 3, (unsigned int)floor(-m_nGameHeight / 2));	//push -300
	WriteValue(0x009B76CB + 3, (unsigned int)floor(m_nGameHeight / 2));		//push 300

	WriteValue(0x009F7078 + 1, m_nGameHeight);//??related to application dimensions	//(ragezone release merge)//thanks mr mr of ragezone for these addresses
	WriteValue(0x009F707D + 1, m_nGameWidth);//??related to application dimensions

	WriteValue(0x0058C8A6 + 1, m_nGameWidth);//??

	WriteValue(0x004EDABF + 1, m_nGameHeight);//??

	WriteValue(0x00991854 + 1, m_nGameHeight);//??unknown cwnd function
	WriteValue(0x0099185F + 1, (m_nGameWidth / 2) - 134);//??unknown cwnd function
	WriteValue(0x00991867 + 1, (m_nGameWidth / 2) - 133);//??unknown cwnd function
	WriteValue(0x00992BA7 + 1, (unsigned int)floor(m_nGameWidth / 2));//??unknown cwnd function, possibly related to cutildlg
	WriteValue(0x00992BAC + 1, (unsigned int)floor(m_nGameHeight / 2));//??unknown cwnd function, possibly related to cutildlg

	WriteValue(0x007E1E07 + 2, m_nGameWidth);//??related to displaying server message at top of screen
	WriteValue(0x007E19CA + 2, m_nGameWidth);//??related to displaying server message at top of screen

	WriteValue(0x005362B2 + 1, (m_nGameWidth / 2) - 129);//??related to boss bar
	WriteValue(0x005364AA + 2, (m_nGameWidth / 2) - 128);//??related to boss bar

	WriteValue(0x00592A08 + 1, (m_nGameWidth / 2) - 125);//??likely related to mouse pos

	WriteValue(0x00621226 + 1, (m_nGameWidth / 2) - 216);//??possibly related to logo
	WriteByte(0x0062121E + 1, 0x01);//??possibly related to logo

	WriteValue(0x008C069F + 1, (m_nGameHeight / 2) - 14);//??related to status bar
	WriteValue(0x008C06A4 + 1, (m_nGameWidth / 2) - 158);//???related to status bar

	WriteValue(0x00A24D0B + 1, (m_nGameWidth / 2) - 129);//??

	WriteValue(0x00BE273C, 128);//??
	WriteByte(0x00A5FC2B, 0x05);//??
	//WriteByte(0x008D1790 + 2, 0x01); //related to quickslots area presence		 originally 1U but changed because unsigned int crashes it after char select
	WriteByte(0x0089B636 + 2, 0x01); //related to exp gain/item pick up msg, seems to affect msg height ! originally 1U but changed because unsigned int crashes it after char select
	WriteByte(0x00592A06 + 1, 0x01);//???likely related to mouse pos

	WriteValue(0x00744EB4 + 1, m_nGameWidth);//??related to in-game taking screenshot functionality
	WriteValue(0x00744EB9 + 1, m_nGameHeight);//??related to in-game taking screenshot functionality
	WriteValue(0x00744E2A + 1, 3 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality
	WriteValue(0x00744E43 + 1, m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality
	WriteValue(0x00744DA6 + 1, 4 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality

	WriteValue(0x00897BB4 + 1, (m_nGameWidth / 2) - 143);//??related to exp gain/item pick up msg

	int msgAmntOffset, msgAmnt; msgAmnt = 26; msgAmntOffset = msgAmnt * 14;

	WriteValue(0x0089B639 + 1, m_nGameHeight - 6 - msgAmntOffset);//inventory/exp gain y axis //####hd100 //90
	WriteValue(0x0089B6F7 + 1, m_nGameWidth - 405);//inventory/exp gain x axis //310 //####hd415 //405

	WriteValue(0x0089AF33 + 1, 400);//length of pick up and exp gain message canvas //found with help from Davi
	WriteValue(0x0089B2C6 + 1, 400);//address to move the message in the canvas adjusted above to the center of the new canvas  //thanks chris

	WriteValue(0x0089AEE2 + 3, msgAmnt);//moregainmsgs part 1
	MoreGainMsgsOffset = msgAmnt;	//param for ccmoregainmssgs
	CodeCave(ccMoreGainMsgs, dwMoreGainMsgs, MoreGainMsgsNOPs); //moregainmsgs part 2
	MoreGainMsgsFadeOffset = 15000;	//param for ccmoregainmssgsFade
	CodeCave(ccMoreGainMsgsFade, dwMoreGainMsgsFade, MoreGainMsgsFadeNOPs); //moregainmsgsFade
	MoreGainMsgsFade1Offset = 255 * 4 / 3;	//param for ccmoregainmssgsFade
	CodeCave(ccMoreGainMsgsFade1, dwMoreGainMsgsFade1, MoreGainMsgsFade1NOPs); //moregainmsgsFade1

	WriteValue(0x0045B337 + 1, m_nGameWidth);//related to smega display  //likely screen area where pop up starts for smega
	WriteValue(0x0045B417 + 1, m_nGameWidth - 225);//smega with avatar x axis for duration on screen

	WriteValue(0x007C2531 + 1, m_nGameHeight - 80);//??

	//WriteValue(0x0089B796 + 2, m_nGameHeight - 18);//???related to exp gain/item pick up msg
	//WriteValue(0x0089BA03 + 1, m_nGameHeight - 96); //??related to exp gain/item pick up msg
	//WriteValue(0x008D3F73 + 1, m_nGameHeight - 93);//bottom frame, white area
	//WriteValue(0x008D3FE5 + 1, m_nGameHeight - 93);//bottom frame, grey area
	//WriteValue(0x008D8353 + 1, m_nGameHeight - 46); //bottom frame, character level
	//WriteValue(0x008D83D1 + 1, m_nGameHeight - 55); //role
	//WriteValue(0x008D8470 + 1, m_nGameHeight - 40); //name of character

	//WriteValue(0x008DE850 + 1, 580);//quickslotcheckX//interactivity of bottom buttoms
	//WriteValue(0x008DE896 + 1, 647);//quickslotcheckX//interactivity of bottom buttoms
	//WriteValue(0x008DE82B + 1, 507);///quickslotcheckY //interactivity of bottom buttoms

	//WriteValue(0x008DA11C + 1, m_nGameHeight - 19);//??likely various status bar UI components
	//WriteValue(0x008DA3D4 + 1, m_nGameHeight - 56); //exphpmp % labels
	//WriteValue(0x008DA463 + 1, m_nGameHeight - 51); //stat bar gradient or bracket
	//WriteValue(0x008DA4F2 + 1, m_nGameHeight - 51);//stat bar gradient or bracket
	//WriteValue(0x008DA61B + 1, m_nGameHeight - 56);//??likely various status bar UI components

	//WriteValue(0x008DA90F + 1, m_nGameHeight - 51);//brackets for stat numbers
	//WriteValue(0x008DA9C6 + 1, m_nGameHeight - 51);
	//WriteValue(0x008DAC3F + 1, m_nGameHeight - 51);
	//WriteValue(0x008DACF1 + 1, m_nGameHeight - 51);
	//WriteValue(0x008DAF64 + 1, m_nGameHeight - 51);

	//WriteValue(0x008DFA6F + 1, m_nGameHeight - 81);//chat box selection, dragging box size, minus plus sign, typing interac
	//WriteValue(0x008DFB01 + 1, m_nGameHeight - 81);
	//WriteValue(0x008DFBA5 + 1, m_nGameHeight - 80);
	//WriteValue(0x008DFC10 + 1, m_nGameHeight - 85);

	//WriteValue(0x008D4AFB + 1, m_nGameHeight - 91); //is for the little grab/resize bar on it (I think)??
	//WriteValue(0x008D4C1F + 1, m_nGameHeight - 90);//??likely various status bar UI components
	//WriteValue(0x008D4CDD + 1, m_nGameHeight - 20);//??likely various status bar UI components
	//WriteValue(0x008D4BBC + 6, m_nGameHeight - 114);//??likely various status bar UI components
	//WriteValue(0x008D4C47 + 1, m_nGameHeight - 87);//minimized chat box frame
	//WriteValue(0x008D628B + 1, m_nGameHeight - 91); //is for the background for the text area.??
	//WriteValue(0x008D6300 + 1, m_nGameHeight - 90); //is for the scroll bar on the chat text area.??
	//WriteValue(0x008D4B6D + 1, m_nGameHeight - 90);//scroll bar of chat
	//WriteValue(0x008D276A + 1, m_nGameHeight - 19);//??likely various status bar UI components

	//WriteValue(0x008D7778 + 3, m_nGameHeight - 42);//???likely various status bar UI components
	//WriteValue(0x008D7785 + 3, m_nGameHeight - 26);//??likely various status bar UI components
	//WriteValue(0x008D783A + 3, m_nGameHeight - 41);//??likely various status bar UI components
	//WriteValue(0x008D7847 + 3, m_nGameHeight - 26);//??likely various status bar UI components

	//WriteValue(0x008D2FAE + 1, m_nGameHeight - 57); //bottom 4 large buttons
	//WriteValue(0x008D3056 + 1, m_nGameHeight - 57);
	//WriteValue(0x008D311F + 1, m_nGameHeight - 57);
	//WriteValue(0x008D31E7 + 1, m_nGameHeight - 57);//bottom 4 large buttons
	WriteValue(0x00849E39 + 1, m_nGameHeight - 177); //system menu pop up
	WriteValue(0x0084A5B7 + 1, m_nGameHeight - 281); //shortcuts pop up	//0x84A5BD -  System Options "X" Position. if needed

	WriteValue(0x00522C73 + 1, m_nGameHeight - 92);// ??various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00522E65 + 1, m_nGameHeight - 92); // ??various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x0052307E + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523359 + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523595 + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up //quest complete y axis
	WriteValue(0x0052378B + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x0052397D + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523BB1 + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523DA5 + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523FA3 + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x005243DB + 1, m_nGameHeight - 92);// various requests like party, guild, friend, family, invites that pop up
	WriteValue(0x00523154 + 1, m_nGameHeight - 102);//?? various requests like party, guild, friend, family, invites that pop up

	WriteValue(0x0052418C + 1, m_nGameHeight - 102);//party quest available pop-up y axis		my first address find own my own

	WriteValue(0x00523092 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up	//trade		 //thank you Rain for the width addresses
	WriteValue(0x0052336D + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up //Party Invite
	WriteValue(0x00522E79 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up //friend request
	WriteValue(0x00522C87 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up	// Guild Invite
	//WriteValue(0x005235A9 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up	// Quest Complete, currently unneeded as working without it
	WriteValue(0x0052379F + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up//??
	WriteValue(0x00523991 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up/??
	WriteValue(0x00523BC5 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up/??
	WriteValue(0x00523DC5 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up// ??
	WriteValue(0x00523FB7 + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up// ??
	WriteValue(0x005243EF + 1, m_nGameWidth - 942);//various requests like party, guild, friend, family, invites that pop up//??

	//WriteValue(0x008D326E + 1, m_nGameHeight - 85); //smol buttoms right of chat box (all - 85 ones)
	//WriteValue(0x008D32F5 + 1, m_nGameHeight - 85);
	//WriteValue(0x008D337C + 1, m_nGameHeight - 85);
	//WriteValue(0x008D3403 + 1, m_nGameHeight - 85);
	//WriteValue(0x008D348A + 1, m_nGameHeight - 85);
	//WriteValue(0x008D3586 + 1, m_nGameHeight - 85);
	//WriteValue(0x008D3696 + 1, m_nGameHeight - 85);
	//WriteValue(0x008D4058 + 1, m_nGameHeight - 85);
	//WriteValue(0x008DF903 + 1, m_nGameHeight - 85);
	//WriteValue(0x008DFFCF + 1, m_nGameHeight - 85);
	//WriteValue(0x008D40CE + 1, m_nGameHeight - 81);//smol buttoms right of chat box (all - 85 ones)

	//CodeCave(PositionBossBarY2, 0x007E169B, 6);//boss bar, check for server msg, looking in wrong address...
	//if (serverMessageExists != 0) 
	//{
	//	CodeCave(PositionBossBarY, dwBossBar, 7);//boss bar normal position without server msg
	//}
	//else {
	//	CodeCave(PositionBossBarY1, dwBossBar, 7);//boss bar with server msg
	//}

	WriteByte(0x00533B03, 0xb8);	//boss bar extend to window
	WriteValue(0x00533B03 + 1, m_nGameWidth - 15);	//boss bar	extend to window
	WriteByte(0x00534370, 0xb9);	//boss bar	extend to window
	WriteValue(0x00534370 + 1, m_nGameWidth - 22);	//boss bar	extend to window

	//myHeight = -(Client::m_nGameHeight - 600) / 2;//cash shop fix for frame area	//recalc offsets
	//myWidth = -(Client::m_nGameWidth - 800) / 2;//cash shop fix for frame area		//recalc offsets
	//CodeCave(CashShopFix, dwCashFix, 6);//cash shop fix for frame area //moves frame to top left (not used rn)

	myHeight = (m_nGameHeight - 600) / 2;//cash shop fix for frame area	//recalc offsets
	myWidth = (m_nGameWidth - 800) / 2;//cash shop fix for frame area		//recalc offsets
	nHeightOfsetted1 = 316; nWidthOfsetted1 = 256; nTopOfsetted1 = 0 + myHeight; nLeftOfsetted1 = 0 + myWidth; //parameters for fix1
	CodeCave(CashShopFix1, dwCashFix1, dwCashFix1NOPs);
	nHeightOfsetted2 = 104; nWidthOfsetted2 = 256; nTopOfsetted2 = 318 + myHeight; nLeftOfsetted2 = -1 + myWidth; //parameters for fix2
	CodeCave(CashShopFix2, dwCashFix2, dwCashFix2NOPs);
	nHeightOfsetted3 = 163; nWidthOfsetted3 = 246; nTopOfsetted3 = 426 + myHeight; nLeftOfsetted3 = 0 + myWidth; //parameters for fix3
	CodeCave(CashShopFix3, dwCashFix3, dwCashFix3NOPs);
	nHeightOfsetted4 = 78; nWidthOfsetted4 = 508; nTopOfsetted4 = 17 + myHeight; nLeftOfsetted4 = 272 + myWidth; //parameters for fix4
	CodeCave(CashShopFix4, dwCashFix4, dwCashFix4NOPs);
	nHeightOfsetted5 = 430; nWidthOfsetted5 = 412; nTopOfsetted5 = 95 + myHeight; nLeftOfsetted5 = 275 + myWidth; //parameters for fix5
	CodeCave(CashShopFix5, dwCashFix5, dwCashFix5NOPs);	//main part of shop, item listings	//thanks angel for stuff that helped
	nHeightOfsetted6 = 358; nWidthOfsetted6 = 90; nTopOfsetted6 = 157 + myHeight; //parameters for fix6
	CodeCave(CashShopFix6, dwCashFix6, dwCashFix6NOPs);//code cave 6 //best sellers
	WriteValue(0x004694BA + 1, myWidth + 690);//nleft, actual drawn part	//best sellers
	nHeightOfsetted7 = 56; nWidthOfsetted7 = 545; nTopOfsetted7 = 530 + myHeight; nLeftOfsetted7 = 254 + myWidth; //parameters for fix7
	CodeCave(CashShopFix7, dwCashFix7, dwCashFix7NOPs);
	nHeightOfsetted8 = 22; nWidthOfsetted8 = 89; nTopOfsetted8 = 97 + myHeight; nLeftOfsetted8 = 690 + myWidth; //parameters for fix8
	CodeCave(CashShopFix8, dwCashFix8, dwCashFix8NOPs);
	CodeCave(CashShopFixOnOff, dwCashFixOnOff, dwCashFixOnOffNOPs);	//fix for preview On/Off button not being accurate on entering cash shop //thanks windyboy

	nHeightOfsettedPrev = 165 + myHeight; nWidthOfsettedPrev = 212 + myWidth; nTopOfsettedPrev = 40 + myHeight; nLeftOfsettedPrev = 24 + myWidth; //parameters for fix cash preview
	CodeCave(CashShopFixPrev, dwCashFixPrev, dwCashFixPrevNOPs); //cash shop preview fix

	WriteValue(0x00641F61 + 1, (unsigned int)floor(m_nGameWidth / 2));	//mov ebc,400 ;  VRleft		//camera movement
	WriteValue(0x00641FC8 + 1, (unsigned int)floor(m_nGameHeight / 2));	//add eax,300  ; VRTop //camera movement //not working for most maps
	//WriteValue(0x0064202F + 2, (unsigned int)floor(m_nGameWidth / 2));	//mov ebc,400 ;  VRright		//camera movement	//crashes
	WriteValue(0x0064208F + 1, (unsigned int)floor(m_nGameHeight / 2));	//add eax,300  ; VRbottom //camera movement //not working for most maps

	myAlwaysViewRestoreFixOffset = myHeight; //parameters for fix view restore all maps number ?????working????!!!
	CodeCave(AlwaysViewRestoreFix, dwAlwaysViewRestoreFix, dwAlwaysViewRestoreFixNOPs);	//fix view restora on all maps, currently does nothing; i likely looked in the wrong area

	//nHeightOfsettedloginFrameFix = 0 + myHeight; nWidthOfsettedloginFrameFix = 0 + myWidth;
	//nTopOfsettedloginFrameFix = 0 + myHeight; nLeftOfsettedloginFrameFix = 0 + myWidth; //parameters for fix cash preview
	//CodeCave(loginFrameFix, dwloginFrameFix, loginFrameFixNOPs); //failed login frame fix =(
	nTopOfsettedVerFix = 10 + myHeight; nLeftOfsettedVerFix = 645 + myWidth; //parameters for fix version number
	CodeCave(VersionNumberFix, dwVersionNumberFix, dwVersionNumberFixNOPs);	//game version number fix //use this if you use no frame or default client frame


	nHeightOfsettedLoginBackCanvasFix = 352 + myHeight; nWidthOfsettedLoginBackCanvasFix = 125 + myWidth;//para for world select buttonsViewRec
	nTopOfsettedLoginBackCanvasFix = 125 + myHeight; nLeftOfsettedLoginBackCanvasFix = 0 + myWidth;
	CodeCave(ccLoginBackCanvasFix, dwLoginBackCanvasFix, LoginBackCanvasFixNOPs);	//world select buttons fix		//thank you teto for pointing out my error in finding the constructor

	//yOffsetOfLoginBackBtnFix = 300 + myHeight; xOffsetOfLoginBackBtnFix = 0 + myWidth;	//para for back button
	//CodeCave(ccLoginBackBtnFix, dwLoginBackBtnFix, LoginBackBtnFixNOPs); //back button on world select //unnecessary as buttons move with canvas

	//nHeightOfsettedLoginViewRecFix = 167 + myHeight; nWidthOfsettedLoginViewRecFix = 540 + myWidth;//para for ViewRec fix
	//nTopOfsettedLoginViewRecFix = 51 + myHeight; nLeftOfsettedLoginViewRecFix = 136 + myWidth;
	//CodeCave(ccLoginViewRecFix, dwLoginViewRecFix, LoginViewRecFixNOPs);	//world ViewRec fix	

	//a1x = 0 + myWidth; a2x = -149 + myWidth; a2y = 0 + myHeight; a3 = 25; a1y = -250; //a4 = 0;	//LoginDescriptor params
	//WriteValue(0x0060D849 + 1, 300 + a1y); //speed 1	//temporary fix by increasing the speed of display until i get good enough at procedural programming 
	//and memory management and reverse engineering to use nexon's own functions to put a black layer with greater z value to cover the tabs being shown off screen at origin
	//CodeCave(ccLoginDescriptorFix, dwLoginDescriptorFix, LoginDescriptorFixNOPs);	//world LoginDescriptor fix	
	int customEngY = -62, customEngX = -22, dojangYoffset = 0;	//myHeight //-55-35 (myHeight*250/100)	-(myWidth*53/100) 140 -130
	yOffsetOfMuruengraidPlayer = 50 + dojangYoffset; xOffsetOfMuruengraidPlayer = 169 + myWidth; //params
	CodeCave(ccMuruengraidPlayer, dwMuruengraidPlayer, MuruengraidPlayerNOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidClock = 26 + dojangYoffset; xOffsetOfMuruengraidClock = 400 + myWidth; //params
	CodeCave(ccMuruengraidClock, dwMuruengraidClock, MuruengraidClockNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidMonster = 50 + dojangYoffset; xOffsetOfMuruengraidMonster = 631 + myWidth; //params
	CodeCave(ccMuruengraidMonster, dwMuruengraidMonster, MuruengraidMonsterNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidMonster1 = 32 + dojangYoffset; xOffsetOfMuruengraidMonster1 = 317 + myWidth; //params
	CodeCave(ccMuruengraidMonster1, dwMuruengraidMonster1, MuruengraidMonster1NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidMonster2 = 32 + dojangYoffset; xOffsetOfMuruengraidMonster2 = 482 + myWidth; //params
	CodeCave(ccMuruengraidMonster2, dwMuruengraidMonster2, MuruengraidMonster2NOPs);	//muruengraid scaling
	yOffsetOfMuruengraidEngBar = 86 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar = 17 + myWidth + customEngX; //params
	CodeCave(ccMuruengraidEngBar, dwMuruengraidEngBar, MuruengraidEngBarNOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidEngBar1 = 130 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar1 = 20 + myWidth + customEngX; //params
	CodeCave(ccMuruengraidEngBar1, dwMuruengraidEngBar1, MuruengraidEngBar1NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidEngBar2 = 80 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar2 = 9 + myWidth + customEngX; //params
	CodeCave(ccMuruengraidEngBar2, dwMuruengraidEngBar2, MuruengraidEngBar2NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidClearRoundUI = 260 + myHeight; xOffsetOfMuruengraidClearRoundUI = 400 + myWidth; //params
	CodeCave(ccMuruengraidClearRoundUI, dwMuruengraidClearRoundUI, MuruengraidClearRoundUINOPs);	//muruengraid scaling
	//yOffsetOfMuruengraidTimerCanvas = 28 + dojangYoffset; xOffsetOfMuruengraidTimerCanvas = 112 + myWidth; //params
	//CodeCave(ccMuruengraidTimerCanvas, dwMuruengraidTimerCanvas, MuruengraidTimerCanvasNOPs);	//muruengraid scaling	
	//yOffsetOfMuruengraidTimerMinutes = 0 + dojangYoffset; xOffsetOfMuruengraidTimerMinutes = 0 + myWidth; //params	//not needed, bar moves all, kept for referrence or if change are needed
	//CodeCave(ccMuruengraidTimerMinutes, dwMuruengraidTimerMinutes, MuruengraidTimerMinutesNOPs);	//muruengraid scaling	
	//yOffsetOfMuruengraidTimerSeconds = 0 + dojangYoffset; xOffsetOfMuruengraidTimerSeconds = 68 + myWidth; //params
	//CodeCave(ccMuruengraidTimerSeconds, dwMuruengraidTimerSeconds, MuruengraidTimerSecondsNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidTimerBar = 16 + dojangYoffset; xOffsetOfMuruengraidTimerBar = 345 + myWidth; //params
	CodeCave(ccMuruengraidTimerBar, dwMuruengraidTimerBar, MuruengraidTimerBarNOPs);	//muruengraid scaling
	xOffsetOfMuruengraidMonster1_2 = 318 + myWidth; //params	//finally fixed this bugger
	CodeCave(ccMuruengraidMonster1_2, dwMuruengraidMonster1_2, MuruengraidMonster1_2NOPs);	//muruengraid scaling

	//testingOut("IWzProperty__GetItem _this: 0x%x, result: 0x%x, sPath: %s");//, _this, result, (char*)sPath);

	//int myStatsWindowOffsetVal = 4, myStatsWindowOffset = 176, myStatsWindowOffset1 = 177;
	//WriteValue(0x008C4AB3 + 1, myStatsWindowOffset); //stat window ty resinate
	//WriteValue(0x008C510A + 1, myStatsWindowOffset1); //stat window ty resinate

	//const char* testString = "RoSWzFile"; WriteString(0x00B3F434, testString);//testing
	//WriteValue(0x009F74EA + 3, 16); //testing
	//WriteValue(0x008C4286 + 1, 400); //testing
	//WriteValue(0x00780743 + 3, 400); //testing
	//WriteByte(0x004289C0 + 1, 99); //testing
	//FillBytes(0x00485C01, 0x90, 2);
	//FillBytes(0x00485C21, 0x90, 2);

	//CodeCave(testingCodeCave, dwTesting, TestingNOPs); //testing
	//CodeCave(testingCodeCave2, dwTesting2, Testing2NOPs); //testing
	//CodeCave(testingCodeCave3, dwTesting3, Testing3NOPs); //testing
	//CodeCave(testingCodeCave4, dwTesting4, Testing4NOPs); //testing
}

void GooseExpansion() {
	//ExpandedStorage
		// Draw Icons in Trunk Inv
	WriteByte(0x007C7C27 + 3, 0xC9);
	// Draw Tooltips in Trunk Inv
	WriteByte(0x007C82C3 + 3, 0xBF);
	// Draw Icons in Player inv
	WriteByte(0x007C8035 + 3, 0xC9);
	// Draw Tooltips in Plaer Inv
	WriteByte(0x007C8385 + 3, 0xBF);
	// Storage Meso Button Y
	WriteByte(0x007C65B6 + 1, 0xC6);
	// Player Meso Button 
	WriteByte(0x007C6631 + 1, 0xC6);
	// Player and Merchant Mesos Y offset
	WriteByte(0x007C8197 + 1, 0xC8);
	//Merchant Scrollbar Length
	WriteByte(0x007C69DC + 1, 0x64);
	WriteByte(0x007C69DC + 2, 0x01);
	WriteByte(0x007C70B3 + 2, 0xF9); // Scrollbar Fix, ty Angel
	//Player Scrollbar Length
	WriteByte(0x007C6A3A + 1, 0x40);
	WriteByte(0x007C6A3A + 2, 0x01);
	WriteByte(0x007C7081 + 2, 0xF8); // Scrollbar Fix, ty Angel

	//ExpandedVendor
	WriteByte(0x00753DB8 + 1, 0x64); // Vendor Scrollbar
	WriteByte(0x00753DB8 + 2, 0x01);
	WriteByte(0x00754719 + 2, 0xF8); // Scrollbar Fix

	WriteByte(0x00753E19 + 1, 0x64); //Player Scrollbar
	WriteByte(0x00753E19 + 2, 0x01);
	WriteByte(0x0075474B + 2, 0xF8); // Scrollbar Fix

	WriteByte(0x00755748 + 3, 0xDE); // Drawing Vendor Items

	WriteByte(0x00755E44 + 2, 0x09); //Drawing Player Items

	WriteByte(0x007560D5 + 3, 0xDE); // Vendor    Item Tooltips
	WriteByte(0x00756197 + 3, 0xDE); // Player Item Tooltips

	WriteByte(0x007540A3 + 1, 0xD8); // Fix Rechargeable items in the bottom 4 slots
	// Array References
	WriteByte(0x007557D6, 0xB8);
	WriteValue(0x007557D6 + 1, (DWORD)&shop_btn_Array);
	WriteByte(0x007557D6 + 5, 0x90);

	WriteByte(0x00755A2A, 0xB8);
	WriteValue(0x00755A2A + 1, (DWORD)&shop_btn_Array);
	WriteByte(0x00755A2A + 5, 0x90);

	WriteByte(0x00755ACC, 0xB8);
	WriteValue(0x00755ACC + 1, (DWORD)&shop_btn_Array);
	WriteByte(0x00755ACC + 5, 0x90);

	WriteByte(0x00755B0B, 0xB8);
	WriteValue(0x00755B0B + 1, (DWORD)&shop_btn_Array);
	WriteByte(0x00755B0B + 5, 0x90);

	WriteByte(0x00755AB9, 0xB9);
	WriteValue(0x00755AB9 + 1, (DWORD)&shop_btn_Array);
	WriteByte(0x00755AB9 + 5, 0x90);


	//Ranged Attack Skills LT/RB
	// Switch statement to insert skills into 'is_attack_area_set_by_data' to use LT/RB
	_is_attack_area_set_by_data = reinterpret_cast<is_attack_area_set_by_data_t>(0x007666CB);
	SetHook(TRUE, reinterpret_cast<PVOID*>(&_is_attack_area_set_by_data), is_attack_area_set_by_data);

	//Avenger + other ranged skills patch to evaluate inside TryDoingShootAttack
	CodeCave(LtRb_Eval, 0x00953E2C, 6);

	//skillexpansion
	WriteByte(0x008AA86F + 1, 0x73); // Extend rendering area to fit modified wz
	WriteByte(0x008AACD5 + 1, 0xF0); // Extends scrollbar
	WriteByte(0x008AAE23 + 1, 0x59); // Moves Macro button down

	WriteByte(0x008AD9F2 + 2, 0x4F); // Draw extra tooltips
	WriteByte(0x008ACE76 + 3, 0x66); // Draw Extra icons
	WriteByte(0x008AD7B4 + 2, 0xFB); // Scrollbar Fix
	WriteByte(0x008AC4DF + 1, 0x5B); // Skillpoints Y offset
	WriteByte(0x008AADAC + 3, 0x67); // Level-up buttons expanded
	WriteByte(0x008AB929 + 2, 0xE0); // Makes new buttons clickable

	WriteByte(0x008AD903 + 2, 0x06); // Increases buttons to be read in SetButton
	WriteByte(0x008AD7F8 + 2, 0x06); // Increases buttons to be read in SetButton

	//CUISkill::OnCreate
	WriteByte(0x008AAD3C + 1, 5); //lea eax
	WriteValue(0x008AAD3C + 2, (DWORD)&Btn_Array + 12);

	//CUISKill::SetButton
	WriteByte(0x008AD920 + 1, 0x34); // lea ecx, [eax*8..
	WriteByte(0x008AD920 + 2, 0xC5); // lea ecx, [eax*8..
	WriteValue(0x008AD920 + 3, (DWORD)&Btn_Array + 12); //..Array]

	//keyslots

	// CUIStatusBar::OnCreate
	WriteByte(0x008D155C + 1, 0xF0); // Draw rest of quickslot bar
	WriteByte(0x008D155C + 2, 0x03);
	WriteByte(0x008D182E + 1, 0xF0); // Draw rest of hotkeys
	WriteByte(0x008D182E + 2, 0x03);
	WriteByte(0x008D1AC0 + 1, 0xF0); // Draw rest of cooldowns, who tf knows why. TY Rulax
	WriteByte(0x008D1AC0 + 2, 0x03);

	//----CQuickslotKeyMappedMan::CQuickslotKeyMappedMan?????
	WriteValue(0x0072B7CE + 1, (DWORD)&Array_aDefaultQKM_0);
	WriteValue(0x0072B8EB + 1, (DWORD)&Array_aDefaultQKM_0);

	//----CUIStatusBar::CQuickSlot::CompareValidateFuncKeyMappedInfo
	WriteByte(0x008DD916, 0x1A); // increase 8 --> 26
	WriteByte(0x008DD8AD, 0x1A); // increase 8 --> 26
	WriteByte(0x008DD8FD, 0xBB);
	WriteValue(0x008DD8FD + 1, (DWORD)&Array_Expanded);
	WriteByte(0x008DD8FD + 5, 0x90); //Errant byte
	WriteByte(0x008DD898, 0xB8);
	WriteValue(0x008DD898 + 1, (DWORD)&Array_Expanded);
	WriteByte(0x008DD898 + 5, 0x90); //Errant Byte

	//----CUIStatusBar::CQuickSlot::Draw
	WriteByte(0x008DE75E + 3, 0x6C);
	WriteByte(0x008DDF99, 0xB8);
	WriteValue(0x008DDF99 + 1, (DWORD)&Array_Expanded);
	FillBytes(0x008DDF99 + 5, 0x90, 3); // Nopping errant operations

	//----CUIStatusBar::OnMouseMove
	WriteByte(0x008D7F1E + 1, 0x34);
	WriteByte(0x008D7F1E + 2, 0x85);
	WriteValue(0x008D7F1E + 3, (DWORD)&Array_Expanded);

	//----CUIStatusBar::CQuickSlot::GetPosByIndex
	WriteValue(0x008DE94D + 2, (DWORD)&Array_ptShortKeyPos);
	WriteValue(0x008DE955 + 2, (DWORD)&Array_ptShortKeyPos + 4);
	WriteByte(0x008DE941 + 2, 0x1A); //change cmp 8 --> cmp 26

	//CUIStatusBar::GetShortCutIndexByPos
	WriteValue(0x008DE8F4 + 1, (DWORD)&Array_ptShortKeyPos_Fixed_Tooltips + 4);
	WriteByte(0x008DE926 + 1, 0x3E);

	//CUIStatusBar::CQuickSlot::DrawSkillCooltime
	WriteByte(0x008E099F + 3, 0x1A);
	WriteByte(0x008E069D, 0xBE);
	WriteValue(0x008E069D + 1, (DWORD)&cooldown_Array); //Pass enlarged FFFFF array
	WriteByte(0x008E069D + 5, 0x90); //Errant byte
	WriteByte(0x008E06A3, 0xBF);
	WriteValue(0x008E06A3 + 1, (DWORD)&Array_Expanded + 1);
	WriteByte(0x008E06A3 + 5, 0x90);

	//----CDraggableMenu::OnDropped
	WriteByte(0x004F928A + 2, 0x1A); //change cmp 8 --> cmp 26
	//----CDraggableMenu::MapFuncKey
	WriteByte(0x004F93F9 + 2, 0x1A); //change cmp 8 --> cmp 26
	//----CUIKeyConfig::OnDestroy
	WriteByte(0x00833797 + 2, 0x6C); // Updates the offset to 108 (triple) (old->24h)
	WriteByte(0x00833841 + 2, 0x6C); // Updates the offset to 108 (triple) (old->24h)
	WriteByte(0x00833791 + 1, 0x68); // push 68h (triple)
	WriteByte(0x0083383B + 1, 0x68); // push 68h (triple)
	//----CUIKeyConfig::~CUIKeyConfig
	WriteByte(0x0083287F + 2, 0x6C); // triple the base value at this hex (old->24h)
	WriteByte(0x00832882 + 1, 0x68); // push 68h (triple)
	//----CQuickslotKeyMappedMan::SaveQuickslotKeyMap
	WriteByte(0x0072B8C0 + 2, 0x6C); // triple the base value at this hex (old->24h)
	WriteByte(0x0072B8A0 + 1, 0x68); // push 68h, (triple) //CQuickslotKeyMappedMan::SaveQuickslotKeyMap
	WriteByte(0x0072B8BD + 1, 0x68); // push 68h, (triple) //CQuickslotKeyMappedMan::SaveQuickslotKeyMap
	//----CQuickslotKeyMappedMan::OnInit
	WriteByte(0x0072B861 + 1, 0x68); // push 68h (triple) (these ones might have to be just 60)
	WriteByte(0x0072B867 + 2, 0x6C); // triple the base value at this hex (old->24h)
	//----CUIKeyConfig::CNoticeDlg::OnChildNotify????
	WriteByte(0x00836A1E + 1, 0x68); // push 68h (triple)
	WriteByte(0x00836A21 + 2, 0x6C); // triple the base value at this hex (old->24h)


	// CODECAVES CLIENT EDITS ---- 
	CodeCave(CompareValidateFuncKeyMappedInfo_cave, 0x8DD8B8, 5);
	CodeCave(sub_9FA0CB_cave, 0x9FA0DB, 5);
	CodeCave(sDefaultQuickslotKeyMap_cave, 0x72B7BC, 5);
	CodeCave(DefaultQuickslotKeyMap_cave, 0x72B8E6, 5);
	CodeCave(Restore_Array_Expanded, 0x008CFDFD, 6); //restores the skill array to 0s

	//Goose dbl jump
		//CodeCave(evaluateHasJumped, 0x009B204B, 5);
		////Executes Jump physics if player has not jumped
		//CodeCave(jumpPhysics, 0x009B20FD, 6);
		////Clears jumpcount when jumping on ground 
		//CodeCave(clearJumps, 0x009B2015, 5);

	//chat line fix:
	CodeCave(chat_Y_offset_cave, 0x008DD6B9, 5);
}


//BOOL __thiscall CItemInfo::EQUIPITEM::IsAbleToStickWithWeapon(CItemInfo::EQUIPITEM* this, int a2)


bool Hook_CItemInfo__IsAbleToStickWithWeapon(bool enable)
{
	typedef BOOL(__fastcall* CItemInfo__IsAbleToStickWithWeapon_t)(void* pThis, void* edx, int nItemID);
	static auto f = reinterpret_cast<CItemInfo__IsAbleToStickWithWeapon_t>(0x0046D39C);

	CItemInfo__IsAbleToStickWithWeapon_t hook = [](void* pThis, void* edx, int nItemID) -> BOOL
		{
			auto ret = f(pThis, edx, nItemID);
			return TRUE;
		};
	return SetHook(enable, reinterpret_cast<void**>(&f), hook);
}


//Item ID in item.

bool Hook_CItemInfo__GetItemDesc(bool enable)
{
	typedef ZXString<char>* (__fastcall* CItemInfo__GetItemDesc_t)(void* pThis, void* edx, ZXString<char>* result, int nItemID);
	static auto CItemInfo__GetItemDesc = reinterpret_cast<CItemInfo__GetItemDesc_t>(0x005CF69E);

	CItemInfo__GetItemDesc_t hook = [](void* pThis, void* edx, ZXString<char>* result, int nItemID) -> ZXString<char>*
		{
			auto ret = CItemInfo__GetItemDesc(pThis, edx, result, nItemID);

			int type = nItemID / 1000000;
			if (type >= 1 && type <= 5)
			{
				if (ret->Length() > 0)
				{
					*ret += "\r\n";
				}
				*ret += "#cItem ID: ";
				*ret += std::to_string(nItemID).c_str();
				*ret += "#";
			}

			return ret;
		};
	return SetHook(enable, reinterpret_cast<void**>(&CItemInfo__GetItemDesc), hook);
}


//WORLD MAP CENTER ON OPEN CODECAVE
const DWORD CodeCave_CWorldMapDlg__OnCreate_Return = 0x009EB5A1;
__declspec(naked) void CodeCave_CWorldMapDlg__OnCreate()
{
	__asm {
		push    524; dialogue height
		push    666; dialogue width

		// push -> (screenHeight / 2) - 262
		mov        eax, [m_nGameHeight]
		shr        eax, 1
		sub        eax, 262
		push    eax

		// push -> (screenWidth / 2) - 333
		mov        eax, [m_nGameWidth]
		shr        eax, 1
		sub        eax, 333
		push    eax

		jmp        dword ptr[CodeCave_CWorldMapDlg__OnCreate_Return]
	}
}


// CAP_RET, FACE_RET, HAIR_RET are assumed to be defined elsewhere
constexpr uint32_t CAP_RET = 0x005C9505;
constexpr uint32_t FACE_RET = 0x005C95BF;
constexpr uint32_t HAIR_RET = 0x005C958D;
constexpr uint32_t RET = 0x009ACAAD;

// Hair and Face ID Extension Hook
__declspec(naked) void hair_face_id_extension_hook() {
	__asm {
		cmp eax, 0x2
		je face_check
		cmp eax, 0x5
		je face_check
		cmp eax, 0x3
		je hair_check
		cmp eax, 0x4
		je hair_check
		cmp eax, 0x6
		je hair_check

		jmp DWORD PTR[CAP_RET]

		face_check:
		jmp DWORD PTR[FACE_RET]

			hair_check :
			jmp DWORD PTR[HAIR_RET]
	}
}

// Face and Hair NPC Extension
__declspec(naked) void face_hair_npc_extension() {
	__asm {
		cmp eax, 0x2
		je face_check
		cmp eax, 0x5
		je face_check
		cmp eax, 0x3
		je hair_check
		cmp eax, 0x4
		je hair_check
		cmp eax, 0x6
		je hair_check

		jmp skin_check

		face_check :
		mov eax, 0x0
			mov ecx, 0x0
			jmp return_point

			hair_check :
		mov eax, 0x1
			mov ecx, 0x1
			jmp return_point

			skin_check :
		mov eax, 0x2
			mov ecx, 0x2

			return_point :
			jmp DWORD PTR[RET]
	}
}

//CodeCaves for Ignore List bigger.
_declspec(naked) void ExceptionList_BackButton_CodeCave()
{
	_asm {
		push 1
		push 5 //Y (from top)
		push 162 //X

		push 0x008FC6DC
		retn
	}
}
_declspec(naked) void ExceptionList_MesoButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 100 //X (from 10)

		push 0x008FC75C
		retn
	}
}
_declspec(naked) void ExceptionList_RegisterButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 133 //X (from 80)

		push 0x008FC7DC
		retn
	}
}
_declspec(naked) void ExceptionList_DeleteButton_CodeCave()
{
	_asm {
		push 1
		push 179 //Y
		push 10 //X (from 124)

		push 0x008FC85F
		retn
	}
}
_declspec(naked) void ExceptionList_Scrollbar_CodeCave()
{
	_asm {
		push 148 //vertical length
		push 25
		push 161
		push 3
		push 1

		push 0x008FC8AF
		retn
	}
}

//Code cave to hijack 5 bytes to change color of the chat
/*
_declspec(naked) void WhiteColorChange_CodeCave()
{
	_asm {

		push 0xFFFF8000
		push 12
		push ecx

		jmp dwWhiteToColorRet
	}
}
*/

//Meso color drop codecave
_declspec(naked) void MesoDropColor_CodeCave()
{
	_asm {

		push 13
		push 07
		push dword ptr[ebp - 0x10]

		jmp dwMesoDropColorRet
	}
}

void DarnellEdits()
{
	CodeCave(HairFaceIdUncap1, dwHairFaceUncap1, dwHairFaceUncapNOPs);
	CodeCave(HairFaceIdUncap2, dwHairFaceUncap2, dwHairFaceUncapNOPs);
}


//CodeCave for moving the StatDetail UI on the X axis
const DWORD dwStatTest = 0x008C5112;
const DWORD dwStatTestRetn = 0x008C5117;
const int StatTestNop = 5;

__declspec(naked) void CodeCave_StatTest() {
	__asm {
		mov     ecx, esi
		add   DWORD PTR[ebp + 0x8], 53 //260-176
		push   DWORD PTR[ebp + 0x8]
		jmp dword ptr[dwStatTestRetn]
	}
}

//CodeCave to fix mouse scroll
DWORD fixMouseWheelAddr = 0x009E8090;
DWORD fixMouseWheelRetJmpAddr = 0x009E809F;
DWORD SetCursorVectorPos = 0x0059A0CB;

__declspec(naked) void fixMouseWheelHook() {
	__asm {
		// is mouse wheel
		cmp eax, 522
		je[halo3]
		mov eax, dword ptr[edi]
		shr eax, 0x10
		push eax
		movzx eax, word ptr[edi]
		push eax
		call SetCursorVectorPos
		halo3 :
		jmp[fixMouseWheelRetJmpAddr]
	}
}


//Change Jobs Names
typedef const char* (__cdecl* get_job_name_t)(int jobId);
static auto get_job_name_hook = reinterpret_cast<get_job_name_t>(0x004A77EF);

const char* __cdecl get_job_name(int nJob)
{
	switch (nJob)
	{
	case 700:
		return "Super Beginner";

	default:
		return get_job_name_hook(nJob);
	}
}

void Hook_Jobs(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)get_job_name_hook, &get_job_name);
	DetourTransactionCommit();
}

////DISCORD STUFF
//typedef void(__thiscall* CLogin__OnSelectCharacterResult_t)(void* a1, void* a2);
//static auto CLogin__OnSelectCharacterResult = reinterpret_cast<CLogin__OnSelectCharacterResult_t>(0x005FB541);
//void __fastcall CLogin__OnSelectCharacterResult_Hook(void* a1, int edx, void* a2) {
//	CLogin__OnSelectCharacterResult(a1, a2);
//}
//
//typedef void(__thiscall* CWvsContext__OnLeaveGame_t)(void* a1);
//static auto CWvsContext__OnLeaveGame = reinterpret_cast<CWvsContext__OnLeaveGame_t>(0x00A041FF);
//void __fastcall CWvsContext__OnLeaveGame_Hook(void* a1, int edx) {
//	CWvsContext__OnLeaveGame(a1);
//	DiscordRichPresence::getInstance().setIsLoggedIn(false);
//}
//typedef char* (__fastcall* CWvsContext__GetCharacterName_t)(void* pThis, int edx);
//static auto CWvsContext__GetCharacterName = reinterpret_cast<CWvsContext__GetCharacterName_t>(0x004AC308);
//static auto Singleton = (void**)0x00BE7918;
//static auto GetCharacterName() {
//	return CWvsContext__GetCharacterName(*Singleton, 0);
//}
//typedef int(__fastcall* GetJobCode_t)(void* pThis, int edx);
//static auto _GetJobCode = reinterpret_cast<GetJobCode_t>(0x0095FFC3);
//typedef uint8_t(__fastcall* CUserLocal__GetCharacterLevel_t)(void* pThis, int edx);
//static auto _CUserLocal__GetCharacterLevel = reinterpret_cast<CUserLocal__GetCharacterLevel_t>(0x00949B15);
//static auto Singleton2 = (void**)0x00BEBF98;
//
//static auto GetJobCode() {
//	return _GetJobCode(*Singleton2, 0);
//}
//
//static auto GetCharacterLevel() {
//	return (unsigned int)_CUserLocal__GetCharacterLevel(*Singleton2, 0);
//}
//
//void HookLogin() {
//	SetHook(true, reinterpret_cast<void**>(&CLogin__OnSelectCharacterResult), CLogin__OnSelectCharacterResult_Hook);
//	SetHook(true, reinterpret_cast<void**>(&CWvsContext__OnLeaveGame), CWvsContext__OnLeaveGame_Hook);
//}



void RulaxEdits() {

	//discord hook
	//HookLogin();

	//Change Job names.
	Hook_Jobs(true);

	//Job Name Check Removal For Stat Window
	PatchNop(0x008C5AFC, 6);

	//tb rush skill
	WriteValue(0x00952E1F + 3,5111013);
	WriteValue(0x00952114 + 1, 5111013);
	WriteValue(0x00950B69 + 1, 5111013);

	//Battleship climb
	WriteByte(0x009CC11F, 0xEB);

	//Uncap MobStat
	WriteValue(0x0067DD1D + 1, 999999);
	WriteValue(0x00793499 + 1, 999999);
	WriteValue(0x00793107 + 1, 999999);
	WriteValue(0x007926DD + 1, 999999);
	WriteValue(0x0077E215 + 1, 999999);
	WriteValue(0x00780620 + 1, 999999);

	WriteByte(0x007930C5, 0xEB); // I GUESS THEY NEVER MISS HUH?
	WriteByte(0x00793484, 0xEB);

	//Battleship faster mount animation+
	WriteValue(0x00936B2D + 6, 28);

	//Fix Mouse Cursor scroll position
	CodeCave(fixMouseWheelHook, fixMouseWheelAddr, 15);

	//NINJA BOUNCE HOOK AND NOP and Momentums
	CodeCave((void*)FlashJumpAll, 0x0096BF0B, 0);
	PatchNop(0x0096C073, 6);

	//Ninja Bounce Momentum OFFSETS
	WriteValue(0x0096C00A + 1, 0xFFFFFD55);
	WriteValue(0x0096C021 + 3, 0x0000025E);
	WriteValue(0x0096C031 + 1, 0xFFFFFD50);

	BossHP::Hook();



	//Hook for meso drop pickup message color
	CodeCave(MesoDropColor_CodeCave, 0x00A20B75, 6);

	//Hook For White Chat Color Change.
	//CodeCave(WhiteColorChange_CodeCave, 0x0098A79B, 5);

	//Render Pet Behind Player
	WriteByte(0x0070451B + 2, 1); // Over NPCs and Mobs & behind characters


	//UI RELATED

	//Stat window x button delete
	WriteByte(0x008C485F + 1, 0x00);

	//Detail Button Stat window move
	WriteByte(0x008C4E20 + 1, 0x5F);

	//Stat Detail Back Button move
	WriteByte(0x008C2754 + 1, 0xE9);

	//Ap Up Button Stat window move
	WriteByte(0x008C7AD9 + 1, 0xC6);

	//Hook for moving the StatDetail UI on the X axis
	CodeCave(CodeCave_StatTest, dwStatTest, StatTestNop); //testing

	//Increase Stat UI render
	WriteValue(0x008C6C72 + 1, 0x000000E0);
	WriteValue(0x008C5760 + 1, 0x000000E0);
	WriteValue(0x008C4AB3 + 1, 0x00000105);

	//GUIDE BOOK RELATED

	//Render limit guidebook
	WriteValue(0x00461B76 + 1, 0x00000261);
	WriteValue(0x00461B7B + 1, 0x000003DE);

	//Prev and Next buttons position
	WriteValue(0x00462592 + 1, 0x00000222);
	WriteValue(0x0046260C + 1, 0x00000222);
	WriteValue(0x00462611 + 1, 0x00000321);

	//Close Button position
	WriteByte(0x00462689 + 1, 0x0C);
	WriteValue(0x0046268B + 1, 0x0000034f);


	//Text color
	WriteValue(0x00461D29 + 1, 0xFFFF5D00);
	WriteValue(0x00461DAC + 1, 0xFFFF5D00);
	WriteValue(0x00461FED + 1, 0xFFFFA774);

	//Text edits
	WriteValue(0x00462C87 + 3, 0x000001B0); //Text separation
	WriteValue(0x00462E0C + 3, 0x00000180); //Text lenght
	WriteValue(0x00462C1B + 1, 0x0000015E); //x/x X position
	WriteValue(0x00462C23 + 1, 0x00000227); //x/x Y position



	//Goose Ignore List
	WriteByte(0x00900AD4 + 1, 0xC9); //Increase render Area, should be tight like this
	WriteByte(0x00900AD9 + 1, 0xB4); //Increase render Area

	WriteByte(0x008FC9F7 + 2, 0xF7); //Fixes Scrollbar

	WriteByte(0x008FCADF + 2, 0x0A); //Increase Draw amount to 10
	WriteByte(0x008FD26E + 2, 0xB8);  //Increase GetItemIndexFromPoint by (14*4)=56

	WriteByte(0x008FCF1D + 3, 0x28); //Increase the CAP

	CodeCave(ExceptionList_BackButton_CodeCave, 0x008FC6D3, 9);
	CodeCave(ExceptionList_MesoButton_CodeCave, 0x008FC756, 6);
	CodeCave(ExceptionList_RegisterButton_CodeCave, 0x008FC7D6, 6);
	CodeCave(ExceptionList_DeleteButton_CodeCave, 0x008FC859, 6);
	CodeCave(ExceptionList_Scrollbar_CodeCave, 0x008FC8A2, 13);

	//WIP Cash Weapon hook
	Hook_CItemInfo__IsAbleToStickWithWeapon(true);

	//Item ID in item hook
	Hook_CItemInfo__GetItemDesc(true);

	// Worldmap Center on open codecave
	CodeCave(CodeCave_CWorldMapDlg__OnCreate, 0x009EB594, 13);

	// WorldMap Cap Increase
	WriteByte(0x009EA030, 0x81);
	WriteByte(0x009EA031, 0xFE);
	WriteByte(0x009EA032, 0xB4);

	// Instant FA
	WriteByte(0x0095795E, 0x83);
	WriteByte(0x0095795E + 1, 0xC0);
	WriteByte(0x0095795E + 2, 0x00);

	// Close range removed (i.e no wack on bow or claw.)
	WriteByte(0x009516C2, 0xE9);
	WriteByte(0x009516C2 + 1, 0xc8);
	WriteByte(0x009516C2 + 2, 0xfc);
	WriteByte(0x009516C2 + 3, 0xff);
	WriteByte(0x009516C2 + 4, 0xff);

	// Hair ID Fix
	WriteByte(0x005C94FC + 2, 7);
	WriteByte(0x005C94FF + 1, 0x8E);

	// Repeat same thing more than 3x (ChatSpam) & Infinite ChatBox
	WriteByte(0x004905EB, 0xEB);
	WriteByte(0x004CAA09, 0xEB); // Infinite chat 1 of 2 scroll through chat box
	WriteByte(0x004CAA84, 0xEB); // Infinite chat 2 of 2 scroll through chat box
	//Remove "Repeating the same line over and over\r\ncan negatively affect other users." check allow spam text
	WriteByte(0x00490607, 0xEB);
	WriteByte(0x00490609, 0x27);
	//Remove "Too much chatting can disrupt\r\nother players' ability to play the game." check allow spam text
	WriteByte(0x00490651, 0xEB);
	WriteByte(0x00490652, 0x1D);
	// Pic Modifier - Allowed PIC to by typed
	PatchNop(0x004ca8ba, 2);
	PatchNop(0x0062EE54, 21); //remove Nexon intro screen.

	// No Gender Lock by Eric
	PatchNop(0x00460AED, 2);

	// NoBreath - no popup when you get hit about swaping gear/dropping/etc.
	WriteByte(0x00452316, 0x7C);

	//was for hendi client (had hid the stat menu under lvl 10)
	WriteByte(0x008C61A5, 0x00);
	WriteByte(0x008C7A6D, 0x00);

	//Launches Game in Windowed mode vs full screen
	WriteByte(0x009F7A9B + 1, 0);

	//Droppable NX
	PatchNop(0x004F350C, 6); // Apply 6 NOPs at address 0x004F351E
	PatchNop(0x004F351E, 6); //Apply 6 NOPs at address 0x004F350C

	//monster magnet fix on static enemies
	FillBytes(0x0096C554, 0x90, 4);


	//Maker Skill Instant
	WriteByte(0x826F92 + 2, 0x08);
	WriteByte(0x826F92 + 3, 0x01);
	WriteByte(0x826F92 + 4, 0x00);
	WriteByte(0x826F92 + 5, 0x00);

	// Boomerang Step In Air
	WriteValue(0x00950B4D + 2, 0x00950C53 - (0x00950B4D + 6));

	//Stat Window Render size increase
	WriteValue(0x008C510A + 1, 0x00000177);

	//UNCAPPED DMG AND STATS
	unsigned char Uncap_Array[] = { 0x00, 0x00,0xC0 ,0xFF ,0xFF ,0xFF ,0xDF ,0x41 };
	WriteByteArray(0x00AFE8A0, Uncap_Array, sizeof(Uncap_Array));
	WriteValue(0x008C3304 + 1, 2147483647);

	unsigned char Uncap_Stat_Arr_1[] = { 0xFF, 0xFE, 12 };
	WriteByteArray(0x00780620 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x0077E055 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x0077E12F + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x0077E215 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x0078FF5F + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x0079166C + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x00791CD5 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1));
	WriteByteArray(0x007806D0 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1)); //Accuracy uncap 
	WriteByteArray(0x00780702 + 1, Uncap_Stat_Arr_1, sizeof(Uncap_Stat_Arr_1)); //Avoidability uncap


	//Tooltip modificatons
	WriteByte(0x008339A1 + 2, 0x2C);   // Keyboard
	WriteValue(0x004B7379 + 3, 0);       // Cash Shop

	// ToolTip Area on hover.      
	int toolTipColors = 0xBB204491;
	WriteValue(0x008E6F35 + 1, toolTipColors); //CUIToolTip::SetToolTip_String
	WriteValue(0x008E70C5 + 1, toolTipColors); //CUIToolTip::SetToolTip_MultiLine
	WriteValue(0x008E7317 + 1, toolTipColors); //CUIToolTip::SetToolTip_String2
	WriteValue(0x008E7716 + 1, toolTipColors); //CUIToolTip::SetToolTip_WorldMap
	WriteValue(0x008E7E49 + 1, toolTipColors); //CUIToolTip::SetToolTip_Ring
	WriteValue(0x008E97D2 + 1, toolTipColors); //CUIToolTip::SetToolTip_Equip
	WriteValue(0x008EDBCF + 1, toolTipColors); //CUIToolTip::SetToolTip_Pet
	WriteValue(0x008EEEF1 + 1, toolTipColors); //CUIToolTip::SetToolTip_Bundle
	WriteValue(0x008F0460 + 1, toolTipColors); //CUIToolTip::SetToolTip_Package
	WriteValue(0x008F1D6B + 1, toolTipColors); //CUIToolTip::SetToolTip_SlotInc
	WriteValue(0x008F214B + 1, toolTipColors); //CUIToolTip::SetToolTip_EquipExt
	WriteValue(0x008F22BB + 1, toolTipColors); //CUIToolTip::SetToolTip_MacroSys
	WriteValue(0x008F2876 + 1, toolTipColors); //CUIToolTip::SetToolTip_Skill


	//Speed Cap Removal
	WriteValue(0x00780746, 400);
	WriteValue(0x008c4287, 400);
	WriteValue(0x0094D91F, 400);

	//Ladder/Climb Speed
	WriteValue(0x009CC6F9 + 2, 0x00C1CF80); //switch addy
	WriteDouble(0x00C1CF80, 8.0); //Addy speed control



	// make fire / holy / angel ray arrow hit multi mob

	CodeCave(FireArrow, dwFireArrow, 5);
	CodeCave(FireArrowBullet, dwFireBulletAdd, 5);
	FillBytes(0x0095644A, 0x90, 2); //codecave shorter than original code, not necessary but more clean


	// assassinate -> dark sight damage calc
		// this removes the boost by just changing the skill id the client checks for, to garbage
		// dark sight requirement detours are in dllmain.cpp
	const uint32_t ASSASSINATE_DAMAGE_BOOST = 0x0079028F + 3;
	WriteValue(ASSASSINATE_DAMAGE_BOOST, 133742069);
	//Give assassinate crit
	WriteByte(0x00790107, 0xEB); //JMP instead of JNZ
	// Allow usage of pots while in Dark Sight skill
	FillBytes(0x0094F6AB, 0x90, 6);
	// Allow double click pots while in Dark Sight skill
	FillBytes(0x004F0311, 0x90, 6);

	//Remove You may not use this skill yet message
	PatchNop(0x00967707, 12);

	//Remove this card is already full blablabla..
	PatchNop(0x00A08283, 18);


	//Super Tubi
	FillBytes(0x00485C01, 0x90, 2);
	FillBytes(0x00485C21, 0x90, 2);
	FillBytes(0x00485C32, 0x90, 2);

	//if (useTubi) { CodeCave(ccTubi, 0x00485BF7, 10); } //alternative method

	// Enable Teleport mid air - 
	//Ezrosia V2 ()newer ones) FillBytes(0x00957C2D, 0x90, 6);
	PatchNop(0x00957C2D, 6);


	// Lacking Level Check Removal
	WriteByte(0x008AD01A, jmpOpcode);
	WriteValue(0x008AD01A + 1, 0x008AD227 - (0x008AD01A + 5));

	//recoil shot spam
	CodeCave(RecoilShotLowerCD, dwRecoilShot, 5);
	FillBytes(0x0095364B, 0x90, 2);

	//PetEquip Cap Removal
	WriteByte(0x0046D43B, jmpOpcode);
	WriteValue(0x0046D43B + 1, PetEquipCapRemoval);


	//swear filter
	PatchNop(0x007A03C8, 2); //remove 3rd party censor (also removes the ?? spam)

	//map transition


	//DrawLimitedView effect (black screen with small circle)  the black effect with small circle in Horntail PQ maps or Resurrection/Bishop skill quest maps:
	//Left position was 237/800
	//Top position was 110/600
	WriteByte(0x0055BEEC + 2, 0x7F); //release canvas
	WriteValue(0x0055BEE6 + 2, 485); //release canvas
	WriteByte(0x0055C07F + 2, 0x7F); //draw circle top pos
	WriteValue(0x0055C086 + 1, 485); //draw circle left pos
	WriteByte(0x0055C1C5 + 2, 0x7F); //draw circle top pos
	WriteValue(0x0055C1CD + 1, 485); //draw circle left pos

	//PROPER FJ Bitch 
	//PatchNop(0x009675A5, 5);
	//PatchNop(0x0096BEBC, 2);
	//PatchNop(0x0096BEC7, 2);
	PatchNop(0x0096BED2, 2);
	PatchNop(0x0096BEE2, 2);
	PatchNop(0x0096BF59, 6);
	WriteByte(0x0096BF86, 0xEB); // JMP
	PatchNop(0x0096BFAE, 6);

	//remove charge for piercing arrow
	//CodeCave(PA, dwPA, 5);

	//corkscrew blow
	//CodeCave(CorkscrewBlow, dwCB, 5);

	//bigbang
	//CodeCave(BigBang, dwBB, 5);

	// Davi extended cape ids 1 & 2
	CodeCave(cash_effect_expansion_1, dwCashEffExpansion1, dwCashEffExpansion1NOPs);
	CodeCave(cash_effect_expansion_2, dwCashEffExpansion2, dwCashEffExpansion2NOPs);

	// Davi extended cape ids 3
	// WriteValue(0x0093C144  + 1, 0x2710); // mov ecx, 10000
	// WriteValue(0x0093C14F  + 1, 0x1F5); // cmp eax, 501
	// WriteValue(0x0093C67E  + 1, 0x2710); // mov ecx, 10000
	// WriteValue(0x0093C689  + 1, 0x1F5); // cmp eax, 501
	WriteValue(0x0095B112 + 1, 0x2710); // mov ecx, 10000
	WriteValue(0x0095B11F + 1, 0x1F5); // cmp eax, 501

}

typedef int(__fastcall* CUser__IsDarkSight_t)(void* ecx, void* edx);
auto g_real_CUser__IsDarkSight = reinterpret_cast<CUser__IsDarkSight_t>(0x004F0D45);

int __fastcall Horizons_CUser__IsDarkSight(void* ecx, void* edx)
{
	auto nReturnAddress = reinterpret_cast<uint32_t>(_ReturnAddress());

	//Dark sight checks for assassinate
	if (nReturnAddress >= 0x00969465 && nReturnAddress <= 0x0096969D)
	{
		return 1;
	}
	return g_real_CUser__IsDarkSight(ecx, edx);
}

