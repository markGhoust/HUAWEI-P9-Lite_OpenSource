

#ifndef __NAS_MSCC_SND_INTERNAL_MSG_H__
#define __NAS_MSCC_SND_INTERNAL_MSG_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "NasMsccCtx.h"
#include "NasMsccMntn.h"



#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum NAS_MSCC_INTERNAL_MSG_TYPE_ENUM
{
    ID_NAS_MSCC_MSCC_SWITCH_ON_RSLT_CNF = ID_NAS_MSCC_MNTN_INTERNAL_MSG_BASE,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_SWITCH_ON_RSLT_CNF_STRU*/
    ID_NAS_MSCC_MSCC_POWER_OFF_RSLT_CNF                                     ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_POWER_OFF_RSLT_CNF_STRU*/

    ID_NAS_MSCC_MSCC_SYS_ACQ_REQ                                            ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_SYS_ACQ_STRU*/
    ID_NAS_MSCC_MSCC_SYS_ACQ_RSLT_CNF                                       ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_SYS_ACQ_RSLT_CNF_STRU */
    ID_NAS_MSCC_MSCC_ABORT_FSM_REQ                                          ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_ABORT_REQ_STRU*/

    ID_NAS_MSCC_MSCC_BSR_RSLT_CNF                                           ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_BSR_RSLT_CNF_STRU*/

    ID_NAS_MSCC_MSCC_SYS_CFG_RSLT_CNF                                       ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_SYS_CFG_RSLT_CNF_STRU*/

    ID_NAS_MSCC_MSCC_CL_INTERSYS_RSLT_CNF                                    ,/* _H2ASN_MsgChoice NAS_MSCC_MSCC_CL_INTERSYS_RSLT_CNF_STRU*/

    ID_NAS_MSCC_MSCC_PIF_MSG_TYPE_ENUM_BUTT
};
typedef VOS_UINT16 NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16;



enum NAS_MSCC_SWITCH_ON_RESULT_ENUM
{
    NAS_MSCC_SWITCH_ON_RESULT_FAILURE   = 0x00000000,
    NAS_MSCC_SWITCH_ON_RESULT_SUCCESS   = 0x00000001,
    NAS_MSCC_SWITCH_ON_RESULT_BUTT      = 0x00000003
};
typedef VOS_UINT32 NAS_MSCC_SWITCH_ON_RESULT_ENUM_UINT32;



enum NAS_MSCC_SYSTEM_ACQUIRED_RESULT_ENUM
{
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_SUCCESS                 = 0x00000000,
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_FAILURE                 = 0x00000001,
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_ABORTED                 = 0x00000002,
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_L2C                     = 0x00000003,
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_BUTT                    = 0x00000004
};
typedef VOS_UINT32 NAS_MSCC_SYSTEM_ACQUIRED_RESULT_ENUM_UINT32;



enum NAS_MSCC_BSR_RESULT_ENUM
{
    NAS_MSCC_BSR_RESULT_SUCCESS,
    NAS_MSCC_BSR_RESULT_FAILURE,
    NAS_MSCC_BSR_RESULT_ABORT,
    NAS_MSCC_BSR_RESULT_L2C,
    NAS_MSCC_BSR_RESULT_BUTT
};
typedef VOS_UINT16 NAS_MSCC_BSR_RESULT_ENUM_UINT16;



enum NAS_MSCC_BSR_ACQ_SYS_ENUM
{
    NAS_MSCC_BSR_NEED_ACQ_SYS,           /* 需要搜网 */
    NAS_MSCC_BSR_NOT_NEED_ACQ_SYS,       /* 不需要搜网 */
    NAS_MSCC_BSR_ACQ_SYS_BUTT
};
typedef VOS_UINT8 NAS_MSCC_BSR_ACQ_SYS_ENUM_UINT8;



enum NAS_MSCC_BSR_RETRY_TIMER_ENUM
{
    NAS_MSCC_BSR_NEED_START_RETRY_TIMER,          /* 需重启retry定时器 */
    NAS_MSCC_BSR_NOT_NEED_START_RETRY_TIMER,      /* 不需重启retry定时器 */
    NAS_MSCC_BSR_RETRY_TIMER_BUTT
};
typedef VOS_UINT8 NAS_MSCC_BSR_RETRY_TIMER_ENUM_UINT8;


enum NAS_MSCC_POWEROFF_RSLT_ENUM
{
    NAS_MSCC_POWEROFF_RSLT_POWER_OFF,
    NAS_MSCC_POWEROFF_RSLT_POWER_SAVE,
    NAS_MSCC_POWEROFF_RSLT_POWER_SAVE_HRPD_LTE,

    NAS_MSCC_POWEROFF_RSLT_BUTT
};
typedef VOS_UINT32 NAS_MSCC_POWEROFF_RSLT_ENUM_UINT32;



enum NAS_MSCC_SYS_CFG_RESULT_ENUM
{
    NAS_MSCC_SYS_CFG_RESULT_SUCCESS   = 0x00000000,
    NAS_MSCC_SYS_CFG_RESULT_FAILURE   = 0x00000001,
    NAS_MSCC_SYS_CFG_RESULT_BUTT      = 0xFFFFFFFF
};
typedef VOS_UINT32 NAS_MSCC_SYS_CFG_RESULT_ENUM_UINT32;



enum NAS_MSCC_CL_INTERSYS_RESULT_ENUM
{
    /* L重选或者重定向到C成功时，；
       C重选到L时，成功 */
    NAS_MSCC_CL_INTERSYS_RESULT_SUCC,

    /* L重选或者重定向到C失败又回退到L时，异系统结果为失败；
       C重选到L失败又回退到C时，异系统结果为失败 */
    NAS_MSCC_CL_INTERSYS_RESULT_FAIL,

    /* 异系统被打断时，退出异系统时结果为abort */
    NAS_MSCC_CL_INTERSYS_RESULT_ABORTED,

    NAS_MSCC_CL_INTERSYS_RESULT_BUTT
};
typedef VOS_UINT32 NAS_MSCC_CL_INTERSYS_RESULT_ENUM_UINT32;


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/



typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    NAS_MSCC_SWITCH_ON_RESULT_ENUM_UINT32                   enRslt;
}NAS_MSCC_MSCC_SWITCH_ON_RSLT_CNF_STRU;




typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    NAS_MSCC_POWEROFF_RSLT_ENUM_UINT32                      enRslt;
}NAS_MSCC_MSCC_POWER_OFF_RSLT_CNF_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT8                                               aucRsv[2];
}NAS_MSCC_MSCC_ABORT_FSM_REQ_STRU;




typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    NAS_MSCC_SYS_ACQ_SCENE_ENUM_UINT32                      enSysAcqScene;
    NAS_MSCC_PIF_PLMN_SEARCH_TYPE_ENUM_UINT32               enLteSrchType;/* 搜索LTE指示的搜索类型 */
}NAS_MSCC_MSCC_SYS_ACQ_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_ENUM_UINT32             enRslt;
    VOS_UINT8                                               ucSearchHrpdFlag;
    VOS_UINT8                                               ucSearchLteFlag;
    VOS_UINT8                                               aucRsv[2];
}NAS_MSCC_MSCC_SYS_ACQ_RSLT_CNF_STRU;




typedef struct
{
    VOS_MSG_HEADER                                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId;                 /* _H2ASN_Skip */
    NAS_MSCC_BSR_RESULT_ENUM_UINT16                         enRslt;                  /* BSR 结果 */
    NAS_MSCC_BSR_ACQ_SYS_ENUM_UINT8                         enIsNeedAcqSys;          /* 是否需要搜网 */
    NAS_MSCC_BSR_RETRY_TIMER_ENUM_UINT8                     enIsNeedStartRetryTimer; /* 是否要启动retry定时器 */
    VOS_UINT8                                               ucReserved[2];
}NAS_MSCC_MSCC_BSR_RSLT_CNF_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT8                                               aucReserved[2];
    NAS_MSCC_SYS_CFG_RESULT_ENUM_UINT32                     enRslt;
}NAS_MSCC_MSCC_SYS_CFG_RSLT_CNF_STRU;




typedef struct
{
    VOS_MSG_HEADER                                                   /* _H2ASN_Skip */
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId; /* _H2ASN_Skip */
    VOS_UINT8                                               aucReserved[2];
    NAS_MSCC_CL_INTERSYS_RESULT_ENUM_UINT32                 enRslt;
}NAS_MSCC_MSCC_CL_INTERSYS_RSLT_CNF_STRU;



/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/
/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    NAS_MSCC_INTERNAL_MSG_TYPE_ENUM_UINT16                  enMsgId;            /* _H2ASN_MsgChoice_Export CNAS_XSD_INTERNAL_MSG_TYPE_ENUM_UINT16 */

    VOS_UINT8                                               aucMsgBlock[2];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          CNAS_XSD_INTERNAL_MSG_TYPE_ENUM_UINT16
    ****************************************************************************/
}NAS_MSCC_INTERNAL_MSG_DATA;
/*_H2ASN_Length UINT32*/


typedef struct
{
    VOS_MSG_HEADER
    NAS_MSCC_INTERNAL_MSG_DATA          stMsgData;
}NAS_MSCC_INTERNAL_MSG;


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_VOID NAS_MSCC_SndPowerOffRslt(
    NAS_MSCC_POWEROFF_RSLT_ENUM_UINT32  enRslt
);

VOS_VOID NAS_MSCC_SndSwitchOnRslt(
    VOS_UINT32                          ulResult
);

VOS_VOID NAS_MSCC_SndAbortFsmReq(VOS_VOID);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

VOS_VOID NAS_MSCC_SndInternalSysAcqReq(
    NAS_MSCC_SYS_ACQ_SCENE_ENUM_UINT32                      enSysAcqScene,
    NAS_MSCC_PIF_PLMN_SEARCH_TYPE_ENUM_UINT32               enLteSrchType
);

VOS_VOID NAS_MSCC_SndInternalSysAcqRsltCnf(
    NAS_MSCC_SYSTEM_ACQUIRED_RESULT_ENUM_UINT32             enRslt,
    VOS_UINT8                                               ucSearchLteFlag,
    VOS_UINT8                                               ucSearchHrpdFlag
);

VOS_VOID NAS_MSCC_SndBsrResult(
    NAS_MSCC_BSR_RESULT_ENUM_UINT16     enBsrRslt,
    NAS_MSCC_BSR_ACQ_SYS_ENUM_UINT8     enIsNeedAcqSys,
    NAS_MSCC_BSR_RETRY_TIMER_ENUM_UINT8 enIsNeedStartRetryTimer
);
#endif

VOS_VOID NAS_MSCC_SndSysCfgRslt(
    NAS_MSCC_SYS_CFG_RESULT_ENUM_UINT32      ulResult
);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
VOS_VOID NAS_MSCC_SndCLInterSysRsltCnf(
    NAS_MSCC_CL_INTERSYS_RESULT_ENUM_UINT32                 enCLInterSysRslt
);
#endif

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CnasXsdSndInternalMsg.h */

