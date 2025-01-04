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

/**
 *  @file
 *
 *  @brief Platform GSM Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_GSM GSM
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_GSM_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef GSM_H_
    #define GSM_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "GSM_Port.h"

    #include <stdint.h>

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief GSM Operation Status
     *
     *  @enum GSM_Status_t
     */
    typedef enum GSM_Status
    {
        GSM_Status_Success = 0,     ///< Success
        GSM_Status_ArgumentInvalid, ///< Invalid Argument
        GSM_Status_NotSupported,    ///< Not Supported
        GSM_Status_Error,           ///< Generic Error
        GSM_Status_Busy,            ///< Busy
        GSM_Status_Timeout,         ///< Timeout
    } GSM_Status_t;

    /**
     *  @brief GSM Data Length Type
     */
    typedef uint32_t GSM_DataLength_t;

    /**
     *  @brief GSM Data Type
     */
    typedef uint8_t GSM_Data_t;

    /**
     *  @brief GSM Voltage Type
     */
    typedef int32_t GSM_Voltage_t;

    /**
     *  @brief GSM RSSI Type
     */
    typedef int32_t GSM_RSSI_t;

    // FIXME relate to Uniform Resource: Identifier(URI)/ Locator (URL) / Name (URN)
    /**
     *  @brief GSM Address Type
     */
    typedef GSM_Data_t * GSM_Address_t;

    /**
     *  @brief GSM Port Type
     */
    typedef uint16_t GSM_Port_t;

    /**
     *  @brief GSM Timestamp Type
     */
    typedef struct GSM_Timestamp
    {
        uint32_t Year;   ///< Year
        uint32_t Month;  ///< Month
        uint32_t Day;    ///< Day
        uint32_t Hour;   ///< Hour
        uint32_t Minute; ///< Minute
        uint32_t Second; ///< Second
    } GSM_Timestamp_t;

    /**
     *  @brief GSM On Complete Callback Type
     *
     *  @param[in] GSMx   GSM
     *  @param[in] Status Completion Status
     */
    typedef void ( *GSM_Callback_OnComplete_t )( GSM_t GSMx, GSM_Status_t Status );

    /**
     *  @brief GSM On Time Callback Type
     *
     *  @param[in] GSMx      GSM
     *  @param[in] Timestamp Network Timestamp
     */
    typedef void ( *GSM_Callback_OnTime_t )( GSM_t GSMx, GSM_Timestamp_t Timestamp );

    /**
     *  @brief GSM On Voltage Callback Type
     *
     *  @param[in] GSMx    GSM
     *  @param[in] Voltage Voltage Value
     */
    typedef void ( *GSM_Callback_OnVoltage_t )( GSM_t GSMx, GSM_Voltage_t Voltage );

    /**
     *  @brief GSM On RSSI Callback Type
     *
     *  @param[in] GSMx GSM
     *  @param[in] RSSI RSSI Value
     */
    typedef void ( *GSM_Callback_OnRSSI_t )( GSM_t GSMx, GSM_RSSI_t RSSI );

    /**
     *  @brief GSM On Socket Open Callback Type
     *
     *  @param[in] GSMx GSM
     */
    typedef void ( *GSM_Callback_OnSocketOpen_t )( GSM_t GSMx );

    /**
     *  @brief GSM On Socket Close Callback Type
     *
     *  @param[in] GSMx GSM
     */
    typedef void ( *GSM_Callback_OnSocketClose_t )( GSM_t GSMx );

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize GSM instance
     *
     *  @note MUST BE called before using any GSM API
     *
     *  @param[in] GSMx Instance
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Initialize( GSM_t GSMx );

    /**
     *  @brief Cycle GSM instance
     *
     *  @param[in] GSMx Instance
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Cycle( GSM_t GSMx );

    /**
     *  @brief DeInitialize GSM instance
     *
     *  @param[in] GSMx Instance
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_DeInitialize( GSM_t GSMx );

    /**
     *  @brief Set On Complete Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Complete Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnCompleteCallback( GSM_t GSMx, GSM_Callback_OnComplete_t Callback );

    /**
     *  @brief Set On Time Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Time Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnTimeCallback( GSM_t GSMx, GSM_Callback_OnTime_t Callback );

    /**
     *  @brief Set On Voltage Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Voltage Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnVoltageCallback( GSM_t GSMx, GSM_Callback_OnVoltage_t Callback );

    /**
     *  @brief Set On RSSI Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On RSSI Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnRSSICallback( GSM_t GSMx, GSM_Callback_OnRSSI_t Callback );

    /**
     *  @brief Set On Socket Open Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Socket Open Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnSocketOpenCallback( GSM_t GSMx, GSM_Callback_OnSocketOpen_t Callback );

    /**
     *  @brief Set On Socket Close Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Socket Close Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Set_OnSocketCloseCallback( GSM_t GSMx, GSM_Callback_OnSocketClose_t Callback );

    /**
     *  @brief Open Socket
     *
     *  @param[in] GSMx    Instance
     *  @param[in] Address Address/URL
     *  @param[in] Port    Port
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Socket_Open( GSM_t GSMx, GSM_Address_t Address, GSM_Port_t Port );

    /**
     *  @brief Write Socket Data
     *
     *  @param[in] GSMx       Instance
     *  @param[in] Data       Data Pointer
     *  @param[in] DataLength Length
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Socket_Write( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t DataLength );

    /**
     *  @brief Read Socket Data
     *
     *  @param[in]     GSMx       Instance
     *  @param[out]    Data       Data Pointer
     *  @param[in,out] DataLength Length
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Socket_Read( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t * DataLength );

    /**
     *  @brief Close Socket
     *
     *  @param[in] GSMx Instance
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_Socket_Close( GSM_t GSMx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char GSM_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* GSM_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
