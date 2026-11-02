// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef GSM_INTERNAL_H_
    #define GSM_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "GSM_Port.h"
    #include "driver/BC92/GSM_BC92.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef GSM_TIM
        #define GSM_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef GSM_LOG
        #define GSM_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define GSM_NAME       "GSM"
    #define GSM_LOG_PREFIX UTIL_StringConcatenateConstant( GSM_NAME, "> " )

    #ifdef DEBUG
        #define GSM_Raw( Level, Format, ... ) LOG_Raw( GSM_LOG, Level, Format, ##__VA_ARGS__ )
        #define GSM_Trace( Format, ... )      LOG_Trace( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GSM_Debug( Format, ... )      LOG_Debug( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GSM_Info( Format, ... )       LOG_Info( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GSM_Warning( Format, ... )    LOG_Warning( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GSM_Error( Format, ... )      LOG_Error( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GSM_Fatal( Format, ... )      LOG_Fatal( GSM_LOG, UTIL_StringConcatenateConstant( GSM_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define GSM_Raw( Level, Format, ... )
        #define GSM_Trace( Format, ... )
        #define GSM_Debug( Format, ... )
        #define GSM_Info( Format, ... )
        #define GSM_Warning( Format, ... )
        #define GSM_Error( Format, ... )
        #define GSM_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum GSM_Type
    {
        GSM_Type_Unknown = 0,
        GSM_Type_Null,
        GSM_Type_BC92,
    } GSM_Type_t;

    typedef struct GSM_Instance
    {
        GSM_Type_t Type;

        union
        {
            GSM_BC92_t BC92x;
        };

        GSM_CallbackOnComplete_t * OnComplete;
        GSM_CallbackOnTime_t * OnTime;
        GSM_CallbackOnVoltage_t * OnVoltage;
        GSM_CallbackOnRSSI_t * OnRSSI;
        GSM_CallbackOnSocketOpen_t * OnSocketOpen;
        GSM_CallbackOnSocketClose_t * OnSocketClose;

    } GSM_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    GSM_Status_t GSM_Port_Initialize( GSM_t GSMx );
    GSM_Status_t GSM_Port_Cycle( GSM_t GSMx );
    GSM_Status_t GSM_Port_DeInitialize( GSM_t GSMx );

    GSM_Status_t GSM_Port_SetCallbackOnComplete( GSM_t GSMx, GSM_CallbackOnComplete_t * Callback );
    GSM_Status_t GSM_Port_SetCallbackOnTime( GSM_t GSMx, GSM_CallbackOnTime_t * Callback );
    GSM_Status_t GSM_Port_SetCallbackOnVoltage( GSM_t GSMx, GSM_CallbackOnVoltage_t * Callback );
    GSM_Status_t GSM_Port_SetCallbackOnRSSI( GSM_t GSMx, GSM_CallbackOnRSSI_t * Callback );
    GSM_Status_t GSM_Port_SetCallbackOnSocketOpen( GSM_t GSMx, GSM_CallbackOnSocketOpen_t * Callback );
    GSM_Status_t GSM_Port_SetCallbackOnSocketClose( GSM_t GSMx, GSM_CallbackOnSocketClose_t * Callback );

    GSM_Status_t GSM_Port_Socket_Open( GSM_t GSMx, GSM_Address_t Address, GSM_Port_t Port );
    GSM_Status_t GSM_Port_Socket_Write( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t DataLength );
    GSM_Status_t GSM_Port_Socket_Read( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t * DataLength );
    GSM_Status_t GSM_Port_Socket_Close( GSM_t GSMx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* GSM_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
