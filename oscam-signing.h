#ifndef OSCAM_SIGNING_H_
#define OSCAM_SIGNING_H_

#ifdef WITH_SSL
#include <openssl/x509.h>
#include <openssl/pem.h>
#endif

#define OBSM "!OBSM!" //Oscam Binary Signature Marker
#define UPXM "UPX!" //UPX Marker
#define CA_FILE_NAME "ca-certificates.crt" //System Certificate Trust Store Filename
#define CA_SYSTEM_LOCATION "/etc/ssl/certs" //System Certificate Trust Store Location

typedef struct {
	unsigned char *data;
	size_t size;
} DIGEST;

struct o_sign_info
{
	bool	is_verified;
	int		cert_version;
	char	cert_valid_from[40];
	char	cert_valid_to[40];
	bool	cert_is_expired;
	char	*cert_serial;
	char	*cert_fingerprint;
	char	*cert_subject;
	char	*cert_issuer;
	bool	cert_is_cacert;
	bool	cert_is_valid_self;
	bool	cert_is_valid_system;
	char	*system_ca_file;
	char	*pkey_type;
	int		sign_digest_size;
	int		hash_digest_size;
	int		hash_size;
	char	*hash_sha256;
};

extern struct o_sign_info osi;
bool init_signing_info(const char *binfile);

#endif