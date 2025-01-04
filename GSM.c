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

typedef struct GSM_Context
{
    GSM_Instance_t Instance[ GSM_Count ];
} GSM_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static GSM_Status_t GSM_Context_Initialize( void );
static GSM_Status_t GSM_Context_Cycle( void );
static GSM_Status_t GSM_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static GSM_Context_t GSM_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static GSM_Status_t GSM_Context_Initialize( void )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( void )", __FUNCTION__ );

        for ( GSM_t GSM_x = GSM_Null; GSM_x < GSM_Count; ++GSM_x )
        {
            GSM_Context.Instance[ GSM_x ].GSMx = GSM_x;
        }

        Status = GSM_Status_Success;
    }
    while ( 0 );

    return Status;
}

static GSM_Status_t GSM_Context_Cycle( void )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( void )", __FUNCTION__ );

        Status = GSM_Status_Success;
    }
    while ( 0 );

    return Status;
}

static GSM_Status_t GSM_Context_DeInitialize( void )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( void )", __FUNCTION__ );

        for ( GSM_t GSM_x = GSM_Null; GSM_x < GSM_Count; ++GSM_x )
        {
            GSM_Context.Instance[ GSM_x ].GSMx = GSM_x;
        }

        Status = GSM_Status_Success;
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_GetInstance( GSM_t GSMx, GSM_Instance_t ** Instance )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( GSMx=%d, Instance=%p )", __FUNCTION__, GSMx, Instance );

        if ( Instance == NULL )
        {
            Status = GSM_Status_ArgumentInvalid;
            break;
        }

        *Instance = &GSM_Context.Instance[ GSMx ];

        Status = GSM_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GSM_Status_t GSM_Initialize( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_IsValid( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }

        if ( ( Status = GSM_Context_Initialize( ) ) != GSM_Status_Success )
        {
            break;
        }

        for ( GSM_t GSM_x = GSM_Null; GSM_x < GSM_Count; ++GSM_x )
        {
            if ( GSMx != GSM_All && GSMx != GSM_x )
            {
                continue;
            }

            GSM_Status_t GSM_Status = GSM_Status_Success;
            if ( ( GSM_Status = GSM_Instance_Initialize( &GSM_Context.Instance[ GSM_x ] ) ) != GSM_Status_Success )
            {
                Status = GSM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Cycle( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_IsValid( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }

        if ( ( Status = GSM_Context_Cycle( ) ) != GSM_Status_Success )
        {
            break;
        }

        for ( GSM_t GSM_x = GSM_Null; GSM_x < GSM_Count; ++GSM_x )
        {
            if ( GSMx != GSM_All && GSMx != GSM_x )
            {
                continue;
            }

            GSM_Status_t GSM_Status = GSM_Status_Success;
            if ( ( GSM_Status = GSM_Instance_Cycle( &GSM_Context.Instance[ GSM_x ] ) ) != GSM_Status_Success )
            {
                Status = GSM_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_DeInitialize( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Error;

    do
    {
        GSM_Trace( "%s( GSMx=%d )", __FUNCTION__, GSMx );

        if ( ( Status = GSM_IsValid( GSMx ) ) != GSM_Status_Success )
        {
            break;
        }

        for ( GSM_t GSM_x = GSM_Null; GSM_x < GSM_Count; ++GSM_x )
        {
            if ( GSMx != GSM_All && GSMx != GSM_x )
            {
                continue;
            }

            GSM_Status_t GSM_Status = GSM_Status_Success;
            if ( ( GSM_Status = GSM_Instance_DeInitialize( &GSM_Context.Instance[ GSMx ] ) ) != GSM_Status_Success )
            {
                Status = GSM_Status;
            }
        }

        Status = GSM_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

GSM_Status_t GSM_Set_OnCompleteCallback( GSM_t GSMx, GSM_Callback_OnComplete_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSMx, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnCompleteCallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Set_OnTimeCallback( GSM_t GSMx, GSM_Callback_OnTime_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSMx, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnTimeCallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Set_OnVoltageCallback( GSM_t GSMx, GSM_Callback_OnVoltage_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnVoltageCallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Set_OnRSSICallback( GSM_t GSMx, GSM_Callback_OnRSSI_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnRSSICallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Set_OnSocketOpenCallback( GSM_t GSMx, GSM_Callback_OnSocketOpen_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnSocketOpenCallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Set_OnSocketCloseCallback( GSM_t GSMx, GSM_Callback_OnSocketClose_t Callback )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Callback=%p )", __FUNCTION__, GSM, Callback );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Set_OnSocketCloseCallback( Instance, Callback );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Socket_Open( GSM_t GSMx, GSM_Address_t Address, GSM_Port_t Port )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Address=%p, Port=%d )", __FUNCTION__, GSMx, Address, Port );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Socket_Open( Instance, Address, Port );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Socket_Write( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t DataLength )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Data=%p, Length=%d )", __FUNCTION__, GSMx, Data, DataLength );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Socket_Write( Instance, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Socket_Read( GSM_t GSMx, GSM_Data_t * Data, GSM_DataLength_t * DataLength )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d, Data=%p, Length=%p )", __FUNCTION__, GSMx, Data, DataLength );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Socket_Read( Instance, Data, DataLength );
    }
    while ( 0 );
    return Status;
}

GSM_Status_t GSM_Socket_Close( GSM_t GSMx )
{
    GSM_Status_t Status = GSM_Status_Error;
    do
    {
        GSM_Trace( "%s( GSM=%d )", __FUNCTION__, GSMx );
        GSM_Instance_t * Instance = &GSM_Context.Instance[ GSMx ];
        Status = GSM_Instance_Socket_Close( Instance );
    }
    while ( 0 );
    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char GSM_VERSION[] = "0.0.0.v20260117-1036";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
