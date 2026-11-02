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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "GSM.h"
#include "GSM_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GSM_Status_t GSM_Initialize( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_Port_Initialize( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Cycle( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_Port_Cycle( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_DeInitialize( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_Port_DeInitialize( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnComplete( GSM_t GSMx, GSM_CallbackOnComplete_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSMx=%d, Callback=%p )", __FUNCTION__, GSMx, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnComplete( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnTime( GSM_t GSMx, GSM_CallbackOnTime_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSMx, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnTime( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnVoltage( GSM_t GSMx, GSM_CallbackOnVoltage_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnVoltage( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnRSSI( GSM_t GSMx, GSM_CallbackOnRSSI_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnRSSI( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnSocketOpen( GSM_t GSMx, GSM_CallbackOnSocketOpen_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnSocketOpen( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_SetCallbackOnSocketClose( GSM_t GSMx, GSM_CallbackOnSocketClose_t * Callback )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );

        if ( ( Status = GSM_Port_SetCallbackOnSocketClose( GSMx, Callback ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Socket_Open( GSM_t GSMx, GSM_Address_t Address, GSM_Port_t Port )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Address=%p, Port=%d )", __FUNCTION__, GSMx, Address, Port );

        if ( ( Status = GSM_Port_Socket_Open( GSMx, Address, Port ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Socket_Write( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t DataLength )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Data=%p, Length=%d )", __FUNCTION__, GSMx, Data, DataLength );

        if ( ( Status = GSM_Port_Socket_Write( GSMx, Data, DataLength ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Socket_Read( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t * DataLength )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d, Data=%p, Length=%p )", __FUNCTION__, GSMx, Data, DataLength );

        if ( ( Status = GSM_Port_Socket_Read( GSMx, Data, DataLength ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Socket_Close( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Success;

    do
    {
        GSM_Trace( "%s( GSM=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_Port_Socket_Close( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char GSM_VERSION[] = "0.0.0.v20261102-2328";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
