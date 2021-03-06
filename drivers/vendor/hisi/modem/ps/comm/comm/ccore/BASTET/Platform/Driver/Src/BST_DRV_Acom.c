
/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "BST_Platform.h"
#include "BST_DRV_Acom.h"
#include "BST_SRV_Event.h"
/*lint -e767*/
#define    THIS_FILE_ID        PS_FILE_ID_BST_DRV_ACOM_C
/*lint +e767*/
/******************************************************************************
   2 宏定义
******************************************************************************/

/*****************************************************************************
  3 函数声明
*****************************************************************************/
BST_ERR_ENUM_UINT8 BST_DRV_ACOM_Initial( BST_VOID *pvArg );
/******************************************************************************
   4 私有定义
******************************************************************************/

/******************************************************************************
   5 全局变量定义
******************************************************************************/
BST_DRV_STRU                            g_BstDrvAcomHandle =
{
    BST_DRV_ACOM_Initial,
    BST_DRV_ACOM_Send,
    BST_DRV_ACOM_Recv,
    BST_NULL_PTR,
    BST_FALSE
};
/******************************************************************************
   6 函数实现
******************************************************************************/


BST_ERR_ENUM_UINT8  BST_DRV_ACOM_Initial( BST_VOID *pvArg )
{
    BST_Pal_DrvAcomInit( BST_SRV_ApiSendAcomRxEvent );
    g_BstDrvAcomHandle.ulIsInited       = BST_TRUE;
    return BST_NO_ERROR_MSG;
}
