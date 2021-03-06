/*
 *	sfidrecord.h
 *
 */

#ifndef _SFID_RECORD_H
#define _SFID_RECORD_H

#include <time.h>

#include "sfidmsg.h"
#include "bbqidmsg.h"
#include "useridlist.h"
#include "bbqmcc.h"

#include <list>

typedef std::list<VFONID>						VfonIdList;
typedef std::list<VfonSession *>				VfonSessionList;
typedef std::list<const BBQ_MeetingInfo_Ext *>	MeetingList;

#pragma pack(1)

typedef struct SFIDRecord {

	// service information
	uint32					serviceType;		// 4

	time_t					serviceStart;		// 4
	time_t					serviceExpire;		// 4

	// session validation, changed on register caller ID or logon
	SIM_SESSIONINFO			sessionInfo;		// 8
	char					password[ USERDATA_NAME_SIZE ];		// 32

	uint32					providerID;			// 4

	// timestamp, modified by heartbeat, updated by heartbeat, can be queried
	time_t					time;				// 4

	// user's network connection
	SIM_CHANNEL				sockChannel;		// 16, socket channel connected.

	SIM_CHANNEL				sockHeartbeat;		// 16, heartbeat channel, UDP preferred

	IPSOCKADDR				netLAN;				// 6

	// access list flags
	BBQACLFlag				flags;				// 4, flags

	BBQUserTechParamInfo	techInfo;			// 16

	BBQUserServiceInfo *	pServiceInfo;		// 4 
	BBQUserInfo *			pUserInfo;			// 4
	UserIdList *			pFriendList;		// 4
	UserIdList *			pBlockList;			// 4

	union {
		struct {
			unsigned int	actStatus : 8;			// user's activity: online, offline, in conf, etc.
			unsigned int	setStatus : 8;			// user's setting status: answer machine, call forward, sms alert, etc.
			unsigned int	paddingStatus : 16;		// reserved.
		};
		uint32				userStatus;			// 4
	};

	// vfon user's server info, may used for distributed server system
	uint32					serverID;			// 4
	IPSOCKADDR				netServer;			// 6

	// user's vfon session list, used for log & billing
	VfonSessionList *		pSessionList;		// 4, vfon session list

	// login time
	time_t					login_time;			// 4

	// cache record load time, to avoid too many visit to DB
	MS_TIME					load_timestamp;		// 4
	MS_TIME					binfo_load_timestamp;// 4

	UserIdList *			pBuddyReverseLink;	// 4

	UserIdList *			pBuddyAddingList;	// 4
	UserIdList *			pWaitAuthList;		// 4

	UserIdList *			pParentIdList;		// 4, parent node list, for layered group tree
	UserIdList *			pChildIdList;		// 4, child node list, for layered group tree

	struct {
		unsigned int		is_dirty	: 1;
		unsigned int		padding		: 31;
	};

	BBQACLFlagExt			extFlags;			// 12

	MeetingList *			pMeetingList;		// 4

	BBQCallForwardInfo *	pCallForwardInfo;	// 4

	UserStatusMap *			pBuddyStatus;		// 4

	BBQVoipItems *			pVoipItems;			// 4

	char *					pXMLEXT;

	uint32					last_msg_rand_id;

	char *					pTagString;

	int						nAESKeyBytes;		// 16 for 128bit, 32 for 256bit
	char *					pAESKeyBytes;	

	offlineim_list *		pImList;			// 4
  uint32        nRoomID;
	char          m_szStatusString[96];
	char					m_userInfo_basc_alias[128];
} SFIDRecord;					// 208 bytes

#define SFID_RECORD_SIZE		208

typedef struct BBQProxyRecord {
	SIM_SESSIONINFO			sessionInfo;		// 8

	SIM_CHANNEL				sockChannel;		// 16, socket channel connected.

	union Flags {
		struct {
			unsigned int	configured : 1;		// static configured proxy
			unsigned int	certified : 1;		// proxy that certified with password
			unsigned int	volunteer : 1;		// proxy that not certified
			unsigned int	client : 1;			// proxy in vfon client
			unsigned int	padding : 28;
		};
		uint32				value;
	} flags;									// 4

	uint16					proxySlot;			// 2, empty proxy channel slot, that can serve others. 
	uint16					proxyMax;			// 2, max proxy channel.
	uint32					proxyBandwidthUsed; // 4, bandwidth used, in Kbps
	uint32					proxyBandwidthTotal;// 4, total bandwidth, in Kbps

	uint32					pick;				// 4, picked times
	uint32					score;				// 4, success times

	// timestamp, modified by heartbeat, updated by heartbeat, used for checking online status
	time_t					time;				// 4

	time_t					startTime;			// 4

	uint16					adminPort;			// 2
	uint16					tcpPort;			// 2
	uint16					udpPortMin;			// 2
	uint16					udpPortMax;			// 2

	uint32					ip;					// 4
	uint32					contryCode;			// 4

	uint32					serviceIp;			// 4, ip for client to connect

	uint16					hasTag;				// 2
	char *					pTagString;			// 4

} BBQProxyRecord;

typedef struct BBQServerRecord {

	SIM_CHANNEL				sockChannel;			// 16, only used for socket connection if this server is directly (parent or child or local servers)

	SIMD_SERVER_INFO		server;					// 128

	union Flags {
		struct {
			unsigned int	direct_connect : 1;
			unsigned int	padding : 31;
		};
		uint32				value;
	} flags;

} BBQServerRecord;

typedef struct BBQDomainRecord {

	SIMD_DOMAIN_INFO	domain;		// domain info 

	BBQServerRecord		servers[2];	// domain servers, up to two for backup purpose

	union Flags {
		struct {
			unsigned int	direct_connect : 1;
			unsigned int	padding : 31;
		};
		uint32				value;
	} flags;

} BBQDomainRecord;

#pragma pack()

#endif /* _SFID_RECORD_H */
