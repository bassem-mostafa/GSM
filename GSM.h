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
     *  @brief GSM Data Length
     */
    typedef uint32_t GSM_DataLength_t;

    /**
     *  @brief GSM Data
     */
    typedef uint8_t GSM_Data_t;

    /**
     *  @brief GSM Voltage
     */
    typedef int32_t GSM_Voltage_t;

    /**
     *  @brief GSM RSSI
     */
    typedef int32_t GSM_RSSI_t;

    // FIXME relate to Uniform Resource: Identifier(URI)/ Locator (URL) / Name (URN)
    /**
     *  @brief GSM Address
     */
    typedef GSM_Data_t * GSM_Address_t;

    /**
     *  @brief GSM Port
     */
    typedef uint16_t GSM_Port_t;

    /**
     *  @brief GSM Timestamp
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
     *  @brief GSM On Complete Callback
     *
     *  @param[in] GSMx   Instance
     *  @param[in] Status Execution status
     */
    typedef void ( GSM_CallbackOnComplete_t )( GSM_t GSMx, GSM_Status_t Status );

    /**
     *  @brief GSM On Time Callback
     *
     *  @param[in] GSMx      Instance
     *  @param[in] Timestamp Time-stamp
     */
    typedef void ( GSM_CallbackOnTime_t )( GSM_t GSMx, GSM_Timestamp_t Timestamp );

    /**
     *  @brief GSM On Voltage Callback
     *
     *  @param[in] GSMx    Instance
     *  @param[in] Voltage Voltage Value
     */
    typedef void ( GSM_CallbackOnVoltage_t )( GSM_t GSMx, GSM_Voltage_t Voltage );

    /**
     *  @brief GSM On RSSI Callback
     *
     *  @param[in] GSMx Instance
     *  @param[in] RSSI RSSI Value
     */
    typedef void ( GSM_CallbackOnRSSI_t )( GSM_t GSMx, GSM_RSSI_t RSSI );

    /**
     *  @brief GSM On Socket Open Callback
     *
     *  @param[in] GSMx Instance
     */
    typedef void ( GSM_CallbackOnSocketOpen_t )( GSM_t GSMx );

    /**
     *  @brief GSM On Socket Close Callback
     *
     *  @param[in] GSMx Instance
     */
    typedef void ( GSM_CallbackOnSocketClose_t )( GSM_t GSMx );

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
    GSM_Status_t GSM_SetCallbackOnComplete( GSM_t GSMx, GSM_CallbackOnComplete_t * Callback );

    /**
     *  @brief Set On Time Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Time Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_SetCallbackOnTime( GSM_t GSMx, GSM_CallbackOnTime_t * Callback );

    /**
     *  @brief Set On Voltage Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Voltage Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_SetCallbackOnVoltage( GSM_t GSMx, GSM_CallbackOnVoltage_t * Callback );

    /**
     *  @brief Set On RSSI Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On RSSI Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_SetCallbackOnRSSI( GSM_t GSMx, GSM_CallbackOnRSSI_t * Callback );

    /**
     *  @brief Set On Socket Open Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Socket Open Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_SetCallbackOnSocketOpen( GSM_t GSMx, GSM_CallbackOnSocketOpen_t * Callback );

    /**
     *  @brief Set On Socket Close Callback
     *
     *  @param[in] GSMx     Instance
     *  @param[in] Callback On Socket Close Callback
     *
     *  @return GSM_Status_t
     */
    GSM_Status_t GSM_SetCallbackOnSocketClose( GSM_t GSMx, GSM_CallbackOnSocketClose_t * Callback );

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
