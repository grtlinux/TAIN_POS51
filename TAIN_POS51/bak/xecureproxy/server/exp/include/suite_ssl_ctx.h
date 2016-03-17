//
//	suite_ssl_ctx.h
//

#ifndef _SUITE_SSL_CTX_H_
#define _SUITE_SSL_CTX_H_

/**
 *	Constants
 */

//
//	ssl constants
//
#define	SSL_RANDOM_SIZE						32
#define	SSL_MAX_SESSION_ID_SIZE				32
#define	SSL_MASTER_SECRET_SIZE				48
#define SSL_SEQ_NUM_SIZE					 8
#define	SSL_MAX_RECORD_SIZE					0x4000	// 16384 bytes

//
//	context buffer size
//
#define SFSSL_CTX_BUFFER_SIZE				(SSL_MAX_RECORD_SIZE + 5)

/**
 *	Struct
 */

//
//	Callback functions
//
typedef struct {
	//
	//	CertCB
	//
	int	(*CertCB_VerifyCertificate)			(const uint8 cert_format, 
											 const XE_SSL_BLIST *cert_list);
	int	(*CertCB_GetSelfCertificate)		(uint8 *cert_format, 
											 XE_SSL_BLIST *cert_list, 
											 const XE_SSL_BLIST *ca_dn_list);
	int	(*CertCB_ComputeSignature)			(BIN *signature, 
											 const uint8 signID, 
											 const BIN *digest);
	int	(*CertCB_VerifySignature)			(const BIN *signature, 
											 const uint8 signID, 
											 const BIN *digest, 
											 const uint8 cert_format, 
											 const BIN *cert);
	int	(*CertCB_EncryptMessage)			(BIN *cipher_text, 
											 const uint8 encID, 
											 const BIN *plain_text, 
											 const uint8 cert_format, 
											 const BIN *cert);
	int	(*CertCB_DecryptMessage)			(BIN *plain_text, 
											 const uint8 encID, 
											 const BIN *cipher_text);
	int	(*CertCB_GetCADNList)				(XE_SSL_BLIST *ca_dn_list);
	//
	//	SessionCB
	//
	int	(*SessionCB_CreateSession)			(BIN *session_id, 
											 const uint32 session_id_length);
	int	(*SessionCB_ReadSession)			(uint8 version[2], 
											 uint8 cipher_suite[2], 
											 uint8 *comp_method, 
											 uint8 *cert_format,
											 BIN *peer_cert,
											 BIN *master_secret, 
											 uint8 *is_resumable,
											 const BIN *session_id);
	int	(*SessionCB_WriteSession)			(const uint8 version[2], 
											 const BIN *session_id,
											 const uint8 cipher_suite[2], 
											 const uint8 comp_method,
											 const uint8 cert_format,
											 const BIN *peer_cert,
											 const BIN *master_secret, 
											 const uint8 is_resumable);
	int	(*SessionCB_DeleteSession)			(const BIN *session_id);
	//
	//	DebugCB
	//
	void (*DebugCB_PrintText)				(const uint8 *text);
	void (*DebugCB_PrintBinary)				(const uint8 *data, 
											 const uint32 length);
	void (*DebugCB_DumpRecord)				(const uint8 type, 
											 const uint8 version[2], 
											 const uint8 length[2], 
											 const BIN *fragment);
	void (*DebugCB_DumpSecret)				(const uint8 client_random[32], 
											 const uint8 server_random[32], 
											 const BIN *master_secret,
											 const BIN *clnt_write_mac_secret, 
											 const BIN *srvr_write_mac_secret,
											 const BIN *clnt_write_key, 
											 const BIN *srvr_write_key,
											 const BIN *clnt_write_iv, 
											 const BIN *srvr_write_iv);
	//
	//	TempkeyCB
	//
	int	(*TempkeyCB_GetKeyPair)				(BIN *priv_key, 
											 BIN *pub_key, 
											 BIN *key_param, 
											 const uint8 key_type);
	int	(*TempkeyCB_GetRandom)				(uint8 *random, 
											 const uint32 length);
	//
	//	SocketCB
	//
	int	(*SocketCB_Read)					(int fd, char *buf, int len);
	int	(*SocketCB_Write)					(int fd, char *buf, int len);
} XE_SSL_CallBack;

//
//	Config information
//
typedef struct {
	BIN				*cipher_suites;
	BIN				*comp_methods;
	uint8			client_auth;			// true(1) or false(0)
	BIN				*client_cert_types;
	uint8			debug_level;
} XE_SSL_ConfigInfo;

//
//	Cipher spec
//
typedef struct {
	uint8			cipher_algorithm;
	uint8			cipher_type;			// block(1) or stream(0)
	uint8			cipher_block_size;
	uint8			cipher_key_size;
	uint8			cipher_IV_size;
	uint8			cipher_is_exportable;	// true(1) or false(0)
	uint8			hash_algorithm;
	uint8			hash_size;
} XE_SSL_CipherSpec;

//
//	Security parameters
//
typedef struct {
	uint8			version[2];
	BIN 			*p_session_id;
	uint8			cipher_suite[2];
	uint8			compression_method;
	BIN 			*p_master_secret;
	uint8			is_resumable;			// true(1) or false(0)
} XE_SSL_SecurityParams;

//
//	Session secrets
//
typedef struct {
	// client secret
	uint8			client_random[SSL_RANDOM_SIZE];
	uint8			client_MAC_key[20];
	uint8			client_key[24];
	uint8			client_IV[20];

	// server secret
	uint8			server_random[SSL_RANDOM_SIZE];
	uint8			server_MAC_key[20];
	uint8			server_key[24];
	uint8			server_IV[20];
		
	// sequence number
	uint8			read_seq[SSL_SEQ_NUM_SIZE];
	uint8			write_seq[SSL_SEQ_NUM_SIZE];

	// rc4 key
	void			*p_rc4_client_key;
	void			*p_rc4_server_key;
} XE_SSL_ConnectionSecrets;

//
//
//
typedef struct {
	uint8			type;
	uint8			length[3];
	BIN 			*body;
} XE_SSL_Handshake;

typedef struct {
	uint8			type;
	uint8			version[2];
	uint8			length[2];
	BIN 			*fragment;
} XE_SSL_Record;

//
//	SSL context
//
typedef struct {
	int				hsock;					// socket handle
	int				reason_code;			// reason code

	uint8			mode;					// server(1) or client(0) mode

	// {{
	// callback and config is setted at initial time.
	//
	XE_SSL_CallBack		callback;			// call back functions
	XE_SSL_ConfigInfo	config;				// config infos
	// }}

	//// Handshake Layer //////////////////////////////////

	// {{
	struct {
		uint8		cert_type;				// X509, WTLS, URL
		uint8		sign_type;				// RSA, ECC
		XE_SSL_BLIST	*p_cert_list;
		XE_SSL_BLIST	*p_CA_DN_list;		// CD DN list
	} self_infos;
	// }}

	// pending_params : 
//	XE_SSL_SecurityParams	pending_params;
//	XE_SSL_CipherSpec		pending_cipher_spec;

	struct {
		uint32			state;

		// message flow
		uint8			message_flow;		// FULL, RESUME
		// client auth
		uint8			auth;				// true(1), false(0)
		// handshake msg flags 
		uint16			messages;

		// hash context
		void 			*p_md5_ctx;
		void 			*p_sha_ctx;

		// pre master secret
		BIN 			*p_pre_master_secret;

		// peer infos
		struct {
			uint8			cert_format;		// X509, WTLS, URL
			XE_SSL_BLIST	*p_cert_list;
			XE_SSL_BLIST	*p_CA_DN_list;
			// public key from server_key_exchange
			void			*p_rsa;
		} peer_infos;

		// temporal key for server_key_exch : 
		//		it is used for server to make ServerKeyExchange message. 
		//		client don't use this.
		//
		struct {
			uint8			key_type;
			BIN				*p_private_key;
			BIN				*p_public_key;
			BIN				*p_param;
		} tempkey;

		XE_SSL_Record	*p_record;
	} handshake_ctx;

	//// Fragment Layer ///////////////////////////////////

	// alert_infos :
	//		if alert was received (or sent), it contains alert infos 
	//		that was received (or sent).
	//
	struct {
		uint8			level;
		uint8			desc;
	} alert_infos;

	struct {
		int				state_r;
		int				state_w;

		XE_SSL_Handshake *p_handshake;
		XE_SSL_Record	*p_record;
		int				index;
	} hs_rw_ctx;

	struct {
		// read
		int				state_r;
		int				remain_r;
		XE_SSL_Record	*p_record_r;

		// write, close
		int				state_w;
		int				state_c;
		int				remain_w;
		XE_SSL_Record	*p_record_w;
	} appdata_ctx;

	//// Record Layer /////////////////////////////////////

	uint8			record_encrypt; 		// encryption on/off
	uint8			record_decrypt; 		// decryption on/off

	// session_params :
	//		this parameter will be setted during handshake process.
	//		after handshaking, session_secret values are generated from
	//		this parameter values. and it will be saved in session manager.
	//
	XE_SSL_SecurityParams	session_params;
	XE_SSL_CipherSpec		session_cipher_spec;

	// connection_secrets :
	//		it is setted after handshake process. after setting it is used 
	//		for record encryption and record decryption.
	//
	XE_SSL_ConnectionSecrets	connection_secrets;

	struct {
		// read
		int				state_r;
		uint8			header_r[5];
		XE_SSL_Record	*p_record_r;
		
		// write
		int				state_w;
		uint8			header_w[5];
	} record_ctx;

	struct {
		// read
		int				state_r;
		int				remain_r;
		
		// write
		int				state_w;
		int				remain_w;
	} socket_ctx;

	// buffers
	uint8			buffer[SFSSL_CTX_BUFFER_SIZE];
} XE_SSL_CTX;

/**
 *	Prototypes
 */

#ifdef  __cplusplus
extern "C" {
#endif

XFA_EXPORT_TYPE
XE_SSL_CTX *
		XFA_SSL_CreateCTX					(void);

XFA_EXPORT_TYPE
XE_SSL_CTX *
		XFA_SSL_CopyCTX						(const XE_SSL_CTX *ssl_ctx);

XFA_EXPORT_TYPE
void	XFA_SSL_DestroyCTX					(XE_SSL_CTX *ssl_ctx);

#ifdef  __cplusplus
}
#endif

#endif
