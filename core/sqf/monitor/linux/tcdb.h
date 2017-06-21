///////////////////////////////////////////////////////////////////////////////
//
// @@@ START COPYRIGHT @@@
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
// @@@ END COPYRIGHT @@@
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TCDB_H_
#define TCDB_H_

#include <stdlib.h>
#include "tcdbsqlite.h"
//#include "tcdbzstore.h"
#include "trafconfig.h"

using namespace std;


//
// Trafodion Configuration Database Adaptor (CTrafConfigDb class)
//
//  Implements common interface to storage classes used by the
//  Trafodion Configuration API (trafconfig.cxx/.h).
//

class CTcdb
{
private:
    int            eyecatcher_;      // Debuggging aid -- leave as first
                                     // member variable of the class
public:

    CTcdb( void );
    ~CTcdb( void );

    int         Close( void );
    int         AddRegistryKey( const char *key );
    int         AddRegistryProcess( const char *name );
    int         AddRegistryClusterData( const char *key, const char *dataValue );
    int         AddRegistryProcessData( const char *procName
                                      , const char *key
                                      , const char *dataValue );
    int         AddUniqueString( int nid, int id, const char *uniqStr );
    int         DeleteNodeData( int pnid );
    int         DeleteUniqueString( int nid );
    int         GetNode( int nid
                       , node_configuration_t &nodeConfig );
    int         GetNode( const char *name
                       , node_configuration_t &nodeConfig );
    int         GetNodes( int &count
                        , int max
                        , node_configuration_t nodeConfig[] );
    int         GetPNode( int pnid
                        , physical_node_configuration_t &pnodeConfig );
    int         GetPNode( const char *name
                        , physical_node_configuration_t &pnodeConfig );
    int         GetSNodes( int &count
                         , int max
                         , physical_node_configuration_t pNodeConfig[] );
    int         GetPersistProcess( const char *persistPrefix
                                 , persist_configuration_t &persistConfig );
    int         GetPersistProcessKeys( const char *persistProcessKeys );
    int         GetRegistryClusterSet( int &count
                                     , int max
                                     , registry_configuration_t registryConfig[] );
    int         GetRegistryProcessSet( int &count
                                     , int max
                                     , registry_configuration_t registryConfig[] );
    inline TC_STORAGE_TYPE GetStorageType( void ) { return(dbStorageType_); }
    int         GetUniqueString( int nid, int id, const char *uniqStr );
    int         GetUniqueStringId( int nid
                                 , const char *uniqStr
                                 , int &id );
    int         GetUniqueStringIdMax( int nid, int &id );
    int         Initialize( void );
    bool        IsInitialized( void );
    int         SaveLNodeData( int nid
                             , int pnid
                             , int firstCore
                             , int lastCore
                             , int processors
                             , int roles );
    int         SavePNodeData( const char *name
                             , int pnid
                             , int excludedFirstCore
                             , int excludedLastCore );
    int         UpdatePNodeConfig( int pnid
                                 , const char *name
                                 , int excludedFirstCore
                                 , int excludedLastCore );

protected:
private:
    TC_STORAGE_TYPE         dbStorageType_;
    CTcdbStore             *tcdbStore_;
};


#endif /* TCDB_H_ */
