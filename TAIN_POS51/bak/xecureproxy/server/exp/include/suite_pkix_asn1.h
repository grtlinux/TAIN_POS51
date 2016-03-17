/*************************************************************/
/* Copyright (C) 2011 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* Generated for: SoftForum Co. Ltd., Seoul, Korea - license 7704 for Windows */
/* Abstract syntax: suite_pkix_asn1 */
/* Created: Tue Aug 30 10:12:39 2011 */
/* ASN.1 compiler (RAD) version: 8.1.3 */
/* Runtime version is unknown */
/* Compiler operating system: Windows NT/Windows 9x */
/* Compiler machine type: Intel x86 */
/* Target operating system: Linux 2.0 or later */
/* Target machine type: Intel x86 */
/* C compiler options required: None */
/* ASN.1 compiler options and file names specified:
 * -errorfile
 * D:\crypto\ossasn1\output\syntax_with_ARC_SPKM\glibc_2.2_64\compiler.log.txt
 * -gendirectives suite_pkix_asn1.gen -dualheader -verbose -ignoreError 1130
 * -ber -der -root -compat v5.3.0
 * D:\crypto\ossasn1\asn1dflt\asn1dflt.glibc2.3.linux-x86
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_ac509.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_arc.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_cmp_2510.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_cmp_extn.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_cms_2630.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_crmf_2511.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_ctl.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_dhpop_2875.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_dist_token.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_dvcs_3029.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_ess_2634.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_hsm.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_netscape.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_ocsp_2560.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_opp2.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_opp.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_oppxw.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_1v2.1.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_5v2.0.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_6.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_8v1.2.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_9v2.0.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_10v1.5.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkcs_12v1.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkix_asn1.gen.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkix_explicit88_2459.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkix_implicit88_2459.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_sivid.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_softforum.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_softforum_gw.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_spkm.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_tsp_3161.asn
 * D:\crypto\ossasn1\syntax\syntax_withARC_SPKM\suite_pkix_asn1.asn
 */

#ifndef OSS_suite_pkix_asn1
#define OSS_suite_pkix_asn1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "asn1hdr.h"
#include "asn1code.h"

#define          AttributeCertificate_PDU 1
#define          AttributeCertificateInfo_PDU 2
#define          Holder_PDU 3
#define          ObjectDigestInfo_PDU 4
#define          AttCertIssuer_PDU 5
#define          V2Form_PDU 6
#define          IssuerSerial_PDU 7
#define          AttCertValidityPeriod_PDU 8
#define          ACTargetInformation_PDU 9
#define          TargetCert_PDU 10
#define          IetfAttrSyntax_PDU 11
#define          SvceAuthInfo_PDU 12
#define          RoleSyntax_PDU 13
#define          Clearance_PDU 14
#define          AAControls_PDU 15
#define          ACClearAttrs_PDU 16
#define          ProxyInfo_PDU 17
#define          ARCCertRequest_PDU 18
#define          HashedIDNInfo_PDU 19
#define          ARCCERT_HashAlgorithm_PDU 20
#define          Qualifications_PDU 21
#define          UsageType_PDU 22
#define          CertifiedTime_PDU 23
#define          ARCCertResponse_PDU 24
#define          ARCCertInfo_PDU 25
#define          TargetToCertify_PDU 26
#define          ARCCERT_PKIStatus_PDU 27
#define          ARCCERT_PKIFailureInfo_PDU 28
#define          ARCCDummy1_PDU 29
#define          ARCCDummy2_PDU 30
#define          ARCCDummy3_PDU 31
#define          PKIMessage_PDU 32
#define          ProtectedPart_PDU 33
#define          PasswordBasedMac_PDU 34
#define          DHBasedMac_PDU 35
#define          DHBMParameter_PDU 36
#define          NestedMessageContent_PDU 37
#define          OOBCert_PDU 38
#define          OOBCertHash_PDU 39
#define          CertAnnContent_PDU 40
#define          KeyPolicyRequest_PDU 41
#define          KeyPolicies_PDU 42
#define          CMPEXTNDummy1_PDU 43
#define          CMPEXTNDummy2_PDU 44
#define          CMPEXTNDummy3_PDU 45
#define          ContentInfo_PDU 46
#define          SignedData_PDU 47
#define          SignerInfos_PDU 48
#define          SignedAttributes_PDU 49
#define          EnvelopedData_PDU 50
#define          DigestedData_PDU 51
#define          EncryptedData_PDU 52
#define          AuthenticatedData_PDU 53
#define          SignedAndEnvelopedData_PDU 54
#define          IssuerAndSerialNumber_PDU 55
#define          SigningTime_PDU 56
#define          Countersignature_PDU 57
#define          RC2CBCParameter_PDU 58
#define          OctetString_PDU 59
#define          ContentInfo_P7_PDU 60
#define          SignedData_P7_PDU 61
#define          DigestedData_P7_PDU 62
#define          CMSDummy1_PDU 63
#define          CMSDummy2_PDU 64
#define          CertReqMessages_PDU 65
#define          CertReqMsg_PDU 66
#define          Controls_PDU 67
#define          POPOSigningKeyInput_PDU 68
#define          PBMParameter_PDU 69
#define          RegToken_PDU 70
#define          Authenticator_PDU 71
#define          PKIArchiveOptions_PDU 72
#define          OldCertId_PDU 73
#define          ProtocolEncrKey_PDU 74
#define          UTF8Pairs_PDU 75
#define          CertReq_PDU 76
#define          CertificateTrustList_PDU 77
#define          CTLDummy1_PDU 78
#define          CTLDummy2_PDU 79
#define          DhSigStatic_PDU 80
#define          TokenDistURLToBeSigned_PDU 81
#define          TokenDistURLSignatureValue_PDU 82
#define          KISA_DISTRIBUTION_TOKEN_TokenDistURLDummy1_PDU 83
#define          DVCSRequest_PDU 84
#define          DVCSResponse_PDU 85
#define          DVCSDummy1_PDU 86
#define          DVCSDummy2_PDU 87
#define          DVCSDummy3_PDU 88
#define          ReceiptRequest_PDU 89
#define          Receipt_PDU 90
#define          ContentHints_PDU 91
#define          MsgSigDigest_PDU 92
#define          ContentReference_PDU 93
#define          EquivalentLabels_PDU 94
#define          MLExpansionHistory_PDU 95
#define          SigningCertificate_PDU 96
#define          ESSCertID_PDU 97
#define          SignTokenToBeSigned_PDU 98
#define          SignTokenSignatureValue_PDU 99
#define          SignedPublicKeyAndChallenge_PDU 100
#define          OCSPRequest_PDU 101
#define          TBSRequest_PDU 102
#define          CertID_PDU 103
#define          OCSPResponse_PDU 104
#define          BasicOCSPResponse_PDU 105
#define          ResponseData_PDU 106
#define          SingleResponse_PDU 107
#define          ArchiveCutoff_PDU 108
#define          AcceptableResponses_PDU 109
#define          ServiceLocator_PDU 110
#define          OPP2ConnReq_PDU 111
#define          OPP2ConnResp_PDU 112
#define          OPP2BindReq_PDU 113
#define          OPP2BindResp_PDU 114
#define          BindReq_PDU 115
#define          BindReqInput_PDU 116
#define          BindRep_PDU 117
#define          BindReq_XW_PDU 118
#define          PKCS1_V21_TokenDistURLDummy1_PDU 119
#define          PBKDF2_params_PDU 120
#define          PBEParameter_PDU 121
#define          PBES2_params_PDU 122
#define          PBMAC1_params_PDU 123
#define          RC2_CBC_Parameter_PDU 124
#define          RC5_CBC_Parameters_PDU 125
#define          MyPrintableString_PDU 126
#define          ExtendedCertificateOrCertificate_PDU 127
#define          PrivateKeyInfo_PDU 128
#define          PrivateKeyAlgorithmIdentifier_PDU 129
#define          EncryptedPrivateKeyInfo_PDU 130
#define          EncryptionAlgorithmIdentifier_PDU 131
#define          PKCS9EmailAddress_PDU 132
#define          PKCS9UnstructuredName_PDU 133
#define          PKCS9UnstructuredAddress_PDU 134
#define          PKCS9ContentType_PDU 135
#define          PKCS9MessageDigest_PDU 136
#define          PKCS9SigningTime_PDU 137
#define          PKCS9SigningDescription_PDU 138
#define          PKCS9SMIMECapabilities_PDU 139
#define          CertificationRequest_PDU 140
#define          SignatureAlgorithmIdentifier_PDU 141
#define          CertificationRequestInfo_PDU 142
#define          PFX_PDU 143
#define          AuthenticatedSafe_PDU 144
#define          SafeContents_PDU 145
#define          KeyBag_PDU 146
#define          PKCS8ShroudedKeyBag_PDU 147
#define          CertBag_PDU 148
#define          X509CertificateBag_PDU 149
#define          SdsiCertificateBag_PDU 150
#define          CRLBag_PDU 151
#define          X509CRLBag_PDU 152
#define          SecretBag_PDU 153
#define          FriendlyNameBMPString_PDU 154
#define          LocalKeyIdOctetString_PDU 155
#define          PKCS12Dummy1_PDU 156
#define          PKCS12Dummy2_PDU 157
#define          PKCS12Dummy3_PDU 158
#define          PKCS12Dummy4_PDU 159
#define          PKCS12Dummy5_PDU 160
#define          PKCS12Dummy6_PDU 161
#define          PKCS12Dummy7_PDU 162
#define          AlgorithmID_PDU 163
#define          AttributeType_PDU 164
#define          X520name_PDU 165
#define          X520CommonName_PDU 166
#define          X520LocalityName_PDU 167
#define          X520StateOrProvinceName_PDU 168
#define          X520OrganizationName_PDU 169
#define          X520OrganizationalUnitName_PDU 170
#define          X520Title_PDU 171
#define          X520dnQualifier_PDU 172
#define          X520countryName_PDU 173
#define          Pkcs9email_PDU 174
#define          Name_PDU 175
#define          DistinguishedName_PDU 176
#define          Certificate_PDU 177
#define          TBSCertificate_PDU 178
#define          CertificateSerialNumber_PDU 179
#define          Certificates_PDU 180
#define          PCaPubs_PDU 181
#define          X509_Certificates_PDU 182
#define          ForwardCertificationPath_PDU 183
#define          CertificationPath_PDU 184
#define          CrossCertificates_PDU 185
#define          CertificatePair_PDU 186
#define          CertificateList_PDU 187
#define          TBSCertList_PDU 188
#define          AlgorithmIdentifier_PDU 189
#define          RSAPrivateKey_PDU 190
#define          RSAPublicKey_PDU 191
#define          PlainText_PDU 192
#define          Dss_Sig_Value_PDU 193
#define          DomainParameters_PDU 194
#define          Dss_Parms_PDU 195
#define          CommonName_PDU 196
#define          TeletexCommonName_PDU 197
#define          TeletexOrganizationName_PDU 198
#define          TeletexPersonalName_PDU 199
#define          TeletexOrganizationalUnitNames_PDU 200
#define          PDSName_PDU 201
#define          PhysicalDeliveryCountryName_PDU 202
#define          PostalCode_PDU 203
#define          PhysicalDeliveryOfficeName_PDU 204
#define          PhysicalDeliveryOfficeNumber_PDU 205
#define          ExtensionORAddressComponents_PDU 206
#define          PhysicalDeliveryPersonalName_PDU 207
#define          PhysicalDeliveryOrganizationName_PDU 208
#define          ExtensionPhysicalDeliveryAddressComponents_PDU 209
#define          UnformattedPostalAddress_PDU 210
#define          StreetAddress_PDU 211
#define          PostOfficeBoxAddress_PDU 212
#define          PosteRestanteAddress_PDU 213
#define          UniquePostalName_PDU 214
#define          LocalPostalAttributes_PDU 215
#define          ExtendedNetworkAddress_PDU 216
#define          TerminalType_PDU 217
#define          TeletexDomainDefinedAttributes_PDU 218
#define          AuthorityKeyIdentifier_PDU 219
#define          SubjectKeyIdentifier_PDU 220
#define          KeyUsage_PDU 221
#define          PrivateKeyUsagePeriod_PDU 222
#define          CertificatePolicies_PDU 223
#define          CPSuri_PDU 224
#define          UserNotice_PDU 225
#define          PolicyMappings_PDU 226
#define          SubjectAltName_PDU 227
#define          IssuerAltName_PDU 228
#define          SubjectDirectoryAttributes_PDU 229
#define          BasicConstraints_PDU 230
#define          NameConstraints_PDU 231
#define          PolicyConstraints_PDU 232
#define          CRLDistPointsSyntax_PDU 233
#define          ExtKeyUsageSyntax_PDU 234
#define          AuthorityInfoAccessSyntax_PDU 235
#define          IssuingDistributionPoint_PDU 236
#define          BaseCRLNumber_PDU 237
#define          CRLReason_PDU 238
#define          CertificateIssuer_PDU 239
#define          HoldInstructionCode_PDU 240
#define          InvalidityDate_PDU 241
#define          NetscapeCertType_PDU 242
#define          NetscapeBaseUrl_PDU 243
#define          NetscapeRevocationUrl_PDU 244
#define          NetscapeCaRevocationUrl_PDU 245
#define          NetscapeCertRenewalUrl_PDU 246
#define          NetscapeCaPolicyUrl_PDU 247
#define          NetscapeSSLServerName_PDU 248
#define          NetscapeComment_PDU 249
#define          HashContent_PDU 250
#define          EncryptedVID_PDU 251
#define          EncryptContent_PDU 252
#define          IdentifyData_PDU 253
#define          VID_PDU 254
#define          SIVIDDummy1_PDU 255
#define          GWConnReq_PDU 256
#define          GWConnResp_PDU 257
#define          GWEnvelopedData_PDU 258
#define          GWEncryptedData_PDU 259
#define          GWDummy1_PDU 260
#define          GWDummy2_PDU 261
#define          Req_contents_PDU 262
#define          Rep_ti_contents_PDU 263
#define          REP_IT_TOKEN_PDU 264
#define          ERROR_TOKEN_PDU 265
#define          Mic_Header_PDU 266
#define          Wrap_Header_PDU 267
#define          Del_Header_PDU 268
#define          InitialContextToken_PDU 269
#define          DHParameter_PDU 270
#define          SpkmCtx_PDU 271
#define          TimeStampReq_PDU 272
#define          MessageImprint_PDU 273
#define          TimeStampResp_PDU 274
#define          TimeStampToken_PDU 275
#define          TSTInfo_PDU 276
#define          PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_1_PDU 277
#define          PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_2_PDU 278
#define          PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_3_PDU 279
#define          PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_4_PDU 280
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_1_PDU 281
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_2_PDU 282
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_3_PDU 283
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_4_PDU 284
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_5_PDU 285
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_6_PDU 286
#define          PKCS1_V21_PKCS1Algorithms_PARAMETERS_7_PDU 287
#define          OAEP_PSSDigestAlgorithms_OSET 1 /* Class is ALGORITHM-IDENTIFIER */
#define          PKCS1MGFAlgorithms_OSET 2   /* Class is ALGORITHM-IDENTIFIER */
#define          PKCS1PSourceAlgorithms_OSET 3 /* Class is ALGORITHM-IDENTIFIER */
#define          PKCS1Algorithms_OSET 4      /* Class is ALGORITHM-IDENTIFIER */

typedef struct ObjectID {
    unsigned short  length;
    unsigned char   *value;
} ObjectID;

typedef struct Any {
    unsigned long   length;
    unsigned char   *value;
} Any;

typedef struct TYPE_IDENTIFIER {
    ObjectID        id;
    unsigned short  Type;
} TYPE_IDENTIFIER;

typedef int             AttCertVersion;
#define                     AttCertVersion_v2 1

typedef struct CertificateSerialNumber {
    unsigned short  length;
    unsigned char   *value;
} CertificateSerialNumber;

typedef struct UniqueIdentifier {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} UniqueIdentifier;

typedef struct IssuerSerial {
    unsigned char   bit_mask;
#       define      IssuerSerial_issuerUID_present 0x80
    struct GeneralNames_ *issuer;
    CertificateSerialNumber serial;
    UniqueIdentifier issuerUID;  /* optional; set in bit_mask
                                  * IssuerSerial_issuerUID_present if present */
} IssuerSerial;

typedef struct AlgorithmIdentifier {
    unsigned char   bit_mask;
#       define      parameters_present 0x80
    ObjectID        algorithm;
    Any             parameters;  /* optional; set in bit_mask parameters_present
                                  * if present */
} AlgorithmIdentifier;

typedef enum _enum1 {
    publicKey = 0,
    publicKeyCert = 1,
    otherObjectTypes = 2
} _enum1;

typedef struct _bit1 {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} _bit1;

typedef struct ObjectDigestInfo {
    unsigned char   bit_mask;
#       define      otherObjectTypeID_present 0x80
    _enum1          digestedObjectType;
    ObjectID        otherObjectTypeID;  /* optional; set in bit_mask
                                         * otherObjectTypeID_present if
                                         * present */
    AlgorithmIdentifier digestAlgorithm;
    _bit1           objectDigest;
} ObjectDigestInfo;

typedef struct Holder {
    unsigned char   bit_mask;
#       define      Holder_baseCertificateID_present 0x80
#       define      entityName_present 0x40
#       define      Holder_objectDigestInfo_present 0x20
    IssuerSerial    baseCertificateID;  /* optional; set in bit_mask
                                         * Holder_baseCertificateID_present if
                                         * present */
    struct GeneralNames_ *entityName;  /* optional; set in bit_mask
                                        * entityName_present if present */
    ObjectDigestInfo objectDigestInfo;  /* optional; set in bit_mask
                                         * Holder_objectDigestInfo_present if
                                         * present */
} Holder;

typedef struct V2Form {
    unsigned char   bit_mask;
#       define      issuerName_present 0x80
#       define      V2Form_baseCertificateID_present 0x40
#       define      V2Form_objectDigestInfo_present 0x20
    struct GeneralNames_ *issuerName;  /* optional; set in bit_mask
                                        * issuerName_present if present */
    IssuerSerial    baseCertificateID;  /* optional; set in bit_mask
                                         * V2Form_baseCertificateID_present if
                                         * present */
    ObjectDigestInfo objectDigestInfo;  /* optional; set in bit_mask
                                         * V2Form_objectDigestInfo_present if
                                         * present */
} V2Form;

typedef struct AttCertIssuer {
    unsigned short  choice;
#       define      v1Form_chosen 1
#       define      v2Form_chosen 2
    union _union {
        struct GeneralNames_ *v1Form;  /* to choose, set choice to
                                        * v1Form_chosen */
        V2Form          v2Form;  /* to choose, set choice to v2Form_chosen */
    } u;
} AttCertIssuer;

typedef struct AttCertValidityPeriod {
    GeneralizedTime notBeforeTime;
    GeneralizedTime notAfterTime;
} AttCertValidityPeriod;

typedef ObjectID        AttributeType;

typedef Any             AttributeValue;

typedef struct Attribute {
    AttributeType   type;
    struct _setof1 {
        struct _setof1  *next;
        AttributeValue  value;
    } *values;
} Attribute;

typedef struct _seqof1_ {
    struct _seqof1_ *next;
    Attribute       value;
} *_seqof1;

typedef struct AttributeCertificateInfo {
    unsigned char   bit_mask;
#       define      AttributeCertificateInfo_issuerUniqueID_present 0x80
#       define      AttributeCertificateInfo_extensions_present 0x40
    AttCertVersion  version;
    Holder          holder;
    AttCertIssuer   issuer;
    AlgorithmIdentifier signature;
    CertificateSerialNumber serialNumber;
    AttCertValidityPeriod attrCertValidityPeriod;
    struct _seqof1_ *attributes;
    UniqueIdentifier issuerUniqueID;  /* optional; set in bit_mask
                           * AttributeCertificateInfo_issuerUniqueID_present if
                           * present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                               * AttributeCertificateInfo_extensions_present if
                               * present */
} AttributeCertificateInfo;

typedef struct AttributeCertificate {
    AttributeCertificateInfo acinfo;
    AlgorithmIdentifier signatureAlgorithm;
    _bit1           signatureValue;
} AttributeCertificate;

typedef struct ACTargetInformation_ {
    struct ACTargetInformation_ *next;
    struct Targets_ *value;
} *ACTargetInformation;

typedef struct AnotherName {
    ObjectID        type_id;
    Any             value;
} AnotherName;

typedef struct CountryName {
    unsigned short  choice;
#       define      CountryName_x121_dcc_code_chosen 1
#       define      CountryName_iso_3166_alpha2_code_chosen 2
    union _union {
        char            x121_dcc_code[4];  /* to choose, set choice to
                                          * CountryName_x121_dcc_code_chosen */
        char            iso_3166_alpha2_code[3];  /* to choose, set choice to
                                   * CountryName_iso_3166_alpha2_code_chosen */
    } u;
} CountryName;

typedef struct AdministrationDomainName {
    unsigned short  choice;
#       define      AdministrationDomainName_numeric_chosen 1
#       define      AdministrationDomainName_printable_chosen 2
    union _union {
        char            numeric[17];  /* to choose, set choice to
                                   * AdministrationDomainName_numeric_chosen */
        char            printable[17];  /* to choose, set choice to
                                 * AdministrationDomainName_printable_chosen */
    } u;
} AdministrationDomainName;

typedef char            X121Address[17];

typedef X121Address     NetworkAddress;

typedef char            TerminalIdentifier[25];

typedef struct PrivateDomainName {
    unsigned short  choice;
#       define      PrivateDomainName_numeric_chosen 1
#       define      PrivateDomainName_printable_chosen 2
    union _union {
        char            numeric[17];  /* to choose, set choice to
                                       * PrivateDomainName_numeric_chosen */
        char            printable[17];  /* to choose, set choice to
                                        * PrivateDomainName_printable_chosen */
    } u;
} PrivateDomainName;

typedef char            OrganizationName[65];

typedef char            NumericUserIdentifier[33];

typedef struct PersonalName {
    unsigned char   bit_mask;
#       define      PersonalName_given_name_present 0x80
#       define      PersonalName_initials_present 0x40
#       define      PersonalName_generation_qualifier_present 0x20
    char            surname[41];
    char            given_name[17];  /* optional; set in bit_mask
                                      * PersonalName_given_name_present if
                                      * present */
    char            initials[6];  /* optional; set in bit_mask
                                   * PersonalName_initials_present if present */
    char            generation_qualifier[4];  /* optional; set in bit_mask
                                 * PersonalName_generation_qualifier_present if
                                 * present */
} PersonalName;

typedef struct BuiltInStandardAttributes {
    unsigned short  bit_mask;
#       define      country_name_present 0x8000
#       define      administration_domain_name_present 0x4000
#       define      network_address_present 0x2000
#       define      terminal_identifier_present 0x1000
#       define      private_domain_name_present 0x0800
#       define      organization_name_present 0x0400
#       define      numeric_user_identifier_present 0x0200
#       define      personal_name_present 0x0100
#       define      organizational_unit_names_present 0x0080
    CountryName     country_name;  /* optional; set in bit_mask
                                    * country_name_present if present */
    AdministrationDomainName administration_domain_name;  /* optional; set in
                                   * bit_mask administration_domain_name_present
                                   * if present */
    NetworkAddress  network_address;  /* optional; set in bit_mask
                                       * network_address_present if present */
    TerminalIdentifier terminal_identifier;  /* optional; set in bit_mask
                                              * terminal_identifier_present if
                                              * present */
    PrivateDomainName private_domain_name;  /* optional; set in bit_mask
                                             * private_domain_name_present if
                                             * present */
    OrganizationName organization_name;  /* optional; set in bit_mask
                                          * organization_name_present if
                                          * present */
    NumericUserIdentifier numeric_user_identifier;  /* optional; set in bit_mask
                                           * numeric_user_identifier_present if
                                           * present */
    PersonalName    personal_name;  /* optional; set in bit_mask
                                     * personal_name_present if present */
    struct OrganizationalUnitNames_ *organizational_unit_names;  /* optional;
                                   * set in bit_mask
                                   * organizational_unit_names_present if
                                   * present */
} BuiltInStandardAttributes;

typedef struct ORAddress {
    unsigned char   bit_mask;
#       define      built_in_domain_defined_attributes_present 0x80
#       define      extension_attributes_present 0x40
    BuiltInStandardAttributes built_in_standard_attributes;
    struct BuiltInDomainDefinedAttributes_ *built_in_domain_defined_attributes;                                         /* optional; set in bit_mask
                                * built_in_domain_defined_attributes_present if
                                * present */
    struct ExtensionAttributes_ *extension_attributes;  /* optional; set in
                                   * bit_mask extension_attributes_present if
                                   * present */
} ORAddress;

typedef struct Name {
    unsigned short  choice;
#       define      rdnSequence_chosen 1
    union _union {
        struct RDNSequence_ *rdnSequence;  /* to choose, set choice to
                                            * rdnSequence_chosen */
    } u;
} Name;

typedef struct PKIX1Explicit88_DirectoryString {
    unsigned short  choice;
#       define      PKIX1Explicit88_DirectoryString_teletexString_chosen 1
#       define      PKIX1Explicit88_DirectoryString_printableString_chosen 2
#       define      PKIX1Explicit88_DirectoryString_universalString_chosen 3
#       define      DirectoryString_utf8String_chosen 4
#       define      DirectoryString_bmpString_chosen 5
    union _union {
        char            *teletexString;  /* to choose, set choice to
                      * PKIX1Explicit88_DirectoryString_teletexString_chosen */
        char            *printableString;  /* to choose, set choice to
                    * PKIX1Explicit88_DirectoryString_printableString_chosen */
        struct _char1 {
            unsigned int    length;
            int             *value;
        } universalString;  /* to choose, set choice to
                    * PKIX1Explicit88_DirectoryString_universalString_chosen */
        unsigned char   *utf8String;  /* to choose, set choice to
                                       * DirectoryString_utf8String_chosen */
        struct _char2 {
            unsigned int    length;
            unsigned short  *value;
        } bmpString;  /* to choose, set choice to
                       * DirectoryString_bmpString_chosen */
    } u;
} PKIX1Explicit88_DirectoryString;

typedef struct EDIPartyName {
    unsigned char   bit_mask;
#       define      nameAssigner_present 0x80
    PKIX1Explicit88_DirectoryString nameAssigner;  /* optional; set in bit_mask
                                                    * nameAssigner_present if
                                                    * present */
    PKIX1Explicit88_DirectoryString partyName;
} EDIPartyName;

typedef struct _octet1 {
    unsigned int    length;
    unsigned char   *value;
} _octet1;

typedef struct GeneralName {
    unsigned short  choice;
#       define      otherName_chosen 1
#       define      rfc822Name_chosen 2
#       define      dNSName_chosen 3
#       define      x400Address_chosen 4
#       define      directoryName_chosen 5
#       define      ediPartyName_chosen 6
#       define      uniformResourceIdentifier_chosen 7
#       define      iPAddress_chosen 8
#       define      registeredID_chosen 9
    union _union {
        AnotherName     otherName;  /* to choose, set choice to
                                     * otherName_chosen */
        char            *rfc822Name;  /* to choose, set choice to
                                       * rfc822Name_chosen */
        char            *dNSName;  /* to choose, set choice to dNSName_chosen */
        ORAddress       x400Address;  /* to choose, set choice to
                                       * x400Address_chosen */
        Name            directoryName;  /* to choose, set choice to
                                         * directoryName_chosen */
        EDIPartyName    ediPartyName;  /* to choose, set choice to
                                        * ediPartyName_chosen */
        char            *uniformResourceIdentifier;  /* to choose, set choice to
                                          * uniformResourceIdentifier_chosen */
        _octet1         iPAddress;  /* to choose, set choice to
                                     * iPAddress_chosen */
        ObjectID        registeredID;  /* to choose, set choice to
                                        * registeredID_chosen */
    } u;
} GeneralName;

typedef struct TargetCert {
    unsigned char   bit_mask;
#       define      targetName_present 0x80
#       define      certDigestInfo_present 0x40
    IssuerSerial    targetCertificate;
    GeneralName     targetName;  /* optional; set in bit_mask targetName_present
                                  * if present */
    ObjectDigestInfo certDigestInfo;  /* optional; set in bit_mask
                                       * certDigestInfo_present if present */
} TargetCert;

typedef struct Target {
    unsigned short  choice;
#       define      targetName_chosen 1
#       define      targetGroup_chosen 2
#       define      targetCert_chosen 3
    union _union {
        GeneralName     targetName;  /* to choose, set choice to
                                      * targetName_chosen */
        GeneralName     targetGroup;  /* to choose, set choice to
                                       * targetGroup_chosen */
        TargetCert      targetCert;  /* to choose, set choice to
                                      * targetCert_chosen */
    } u;
} Target;

typedef struct Targets_ {
    struct Targets_ *next;
    Target          value;
} *Targets;

typedef struct _choice1 {
    unsigned short  choice;
#       define      octets_chosen 1
#       define      oid_chosen 2
#       define      string_chosen 3
    union _union {
        _octet1         octets;  /* to choose, set choice to octets_chosen */
        ObjectID        oid;  /* to choose, set choice to oid_chosen */
        unsigned char   *string;  /* to choose, set choice to string_chosen */
    } u;
} _choice1;

typedef struct IetfAttrSyntax {
    unsigned char   bit_mask;
#       define      policyAuthority_present 0x80
    struct GeneralNames_ *policyAuthority;  /* optional; set in bit_mask
                                             * policyAuthority_present if
                                             * present */
    struct _seqof2 {
        struct _seqof2  *next;
        _choice1        value;
    } *values;
} IetfAttrSyntax;

typedef struct SvceAuthInfo {
    unsigned char   bit_mask;
#       define      authInfo_present 0x80
    GeneralName     service;
    GeneralName     ident;
    _octet1         authInfo;  /* optional; set in bit_mask authInfo_present if
                                * present */
} SvceAuthInfo;

typedef struct RoleSyntax {
    unsigned char   bit_mask;
#       define      roleAuthority_present 0x80
    struct GeneralNames_ *roleAuthority;  /* optional; set in bit_mask
                                           * roleAuthority_present if present */
    GeneralName     roleName;
} RoleSyntax;

typedef unsigned char   ClassList;
#define                     ClassList_unmarked 0x80
#define                     ClassList_unclassified 0x40
#define                     ClassList_restricted 0x20
#define                     ClassList_confidential 0x10
#define                     ClassList_secret 0x08
#define                     topSecret 0x04

typedef struct PKIXAttributeCertificate_SecurityCategory {
    ObjectID        type;
    Any             value;
} PKIXAttributeCertificate_SecurityCategory;

typedef struct Clearance {
    unsigned char   bit_mask;
#       define      classList_present 0x80
#       define      securityCategories_present 0x40
    ObjectID        policyId;
    ClassList       classList;  /* classList_present not set in bit_mask implies
                                 * value is { unclassified } */
    struct _setof2 {
        struct _setof2  *next;
        PKIXAttributeCertificate_SecurityCategory value;
    } *securityCategories;  /* optional; set in bit_mask
                             * securityCategories_present if present */
} Clearance;

typedef struct AAControls {
    unsigned char   bit_mask;
#       define      AAControls_pathLenConstraint_present 0x80
#       define      permittedAttrs_present 0x40
#       define      excludedAttrs_present 0x20
#       define      permitUnSpecified_present 0x10
    unsigned int    pathLenConstraint;  /* optional; set in bit_mask
                                         * AAControls_pathLenConstraint_present
                                         * if present */
    struct AttrSpec_ *permittedAttrs;  /* optional; set in bit_mask
                                        * permittedAttrs_present if present */
    struct AttrSpec_ *excludedAttrs;  /* optional; set in bit_mask
                                       * excludedAttrs_present if present */
    ossBoolean      permitUnSpecified;  /* permitUnSpecified_present not set in
                                         * bit_mask implies value is TRUE */
} AAControls;

typedef struct AttrSpec_ {
    struct AttrSpec_ *next;
    ObjectID        value;
} *AttrSpec;

typedef struct _struct1_6 {
    unsigned short  length;
    unsigned char   *value;
} _struct1_6;

typedef struct ACClearAttrs {
    GeneralName     acIssuer;
    _struct1_6      acSerial;
    struct _seqof1_ *attrs;
} ACClearAttrs;

typedef struct ProxyInfo_ {
    struct ProxyInfo_ *next;
    struct Targets_ *value;
} *ProxyInfo;

typedef int             ARCVersion;
#define                     ARCVersion_v1 1
#define                     ARCVersion_v2 2

typedef enum OperationType {
    OperationType_register = 0,
    issue = 1,
    transfer = 2,
    OperationType_delete = 3
} OperationType;

typedef struct _struct1_5 {
    unsigned short  length;
    unsigned char   *value;
} _struct1_5;

typedef struct TargetRecord {
    _struct1_5      serialNo;
    OperationType   opType;
} TargetRecord;

typedef AlgorithmIdentifier ARCCERT_HashAlgorithm;

typedef struct _bit1_2 {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} _bit1_2;

typedef struct HashedDataInfo {
    ARCCERT_HashAlgorithm hashAlg;
    _bit1_2         hashedData;
} HashedDataInfo;

typedef struct ARCCERT_Target {
    unsigned short  choice;
#       define      targetRecord_chosen 1
#       define      targetHash_chosen 2
    union _union {
        TargetRecord    targetRecord;  /* to choose, set choice to
                                        * targetRecord_chosen */
        HashedDataInfo  targetHash;  /* to choose, set choice to
                                      * targetHash_chosen */
    } u;
} ARCCERT_Target;

typedef struct ARCCertRequest {
    unsigned char   bit_mask;
#       define      ARCCertRequest_version_present 0x80
#       define      ARCCertRequest_extensions_present 0x40
    ARCVersion      version;  /* ARCCertRequest_version_present not set in
                               * bit_mask implies value is v1 */
    struct GeneralNames_ *requester;
    GeneralizedTime requestTime;
    struct ARCCertificatePolicies_ *policy;
    ARCCERT_Target  target;
    _struct1_5      nonce;
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * ARCCertRequest_extensions_present if
                                      * present */
} ARCCertRequest;

typedef struct _octet1_2 {
    unsigned int    length;
    unsigned char   *value;
} _octet1_2;

typedef struct HashedIDNInfo {
    ARCCERT_HashAlgorithm hashAlg;
    _octet1_2       hashedIDN;
} HashedIDNInfo;

typedef ObjectID        CertPolicyId;

typedef ObjectID        PolicyQualifierId;

typedef struct PolicyQualifierInfo {
    PolicyQualifierId policyQualifierId;
    Any             qualifier;
} PolicyQualifierInfo;

typedef struct PolicyInformation {
    unsigned char   bit_mask;
#       define      policyQualifiers_present 0x80
    CertPolicyId    policyIdentifier;
    struct _seqof7 {
        struct _seqof7  *next;
        PolicyQualifierInfo value;
    } *policyQualifiers;  /* optional; set in bit_mask policyQualifiers_present
                           * if present */
} PolicyInformation;

typedef struct ARCCertificatePolicies_ {
    struct ARCCertificatePolicies_ *next;
    PolicyInformation value;
} *ARCCertificatePolicies;

typedef struct IssuerAndSerialNumber {
    Name            issuer;
    CertificateSerialNumber serialNumber;
} IssuerAndSerialNumber;

typedef struct KeyIdentifier {
    unsigned int    length;
    unsigned char   *value;
} KeyIdentifier;

typedef KeyIdentifier   SubjectKeyIdentifier;

typedef struct CertIdentifier {
    unsigned short  choice;
#       define      issuerAndSerialNumber_chosen 1
#       define      subjectKeyIdentifier_chosen 2
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                           * to issuerAndSerialNumber_chosen */
        SubjectKeyIdentifier subjectKeyIdentifier;  /* to choose, set choice to
                                               * subjectKeyIdentifier_chosen */
    } u;
} CertIdentifier;

typedef struct NomineeInfo {
    unsigned char   bit_mask;
#       define      nominee_present 0x80
#       define      nomineeCert_present 0x40
    struct GeneralNames_ *nominee;  /* optional; set in bit_mask nominee_present
                                     * if present */
    CertIdentifier  nomineeCert;  /* optional; set in bit_mask
                                   * nomineeCert_present if present */
} NomineeInfo;

typedef unsigned char   NomineeRole;
#define                     onlyForNominee 0x80
#define                     readDocument 0x40
#define                     downloadDocument 0x20

typedef struct Qualification {
    NomineeInfo     nomineeInfo;
    NomineeRole     nomineeRole;
} Qualification;

typedef struct Qualifications_ {
    struct Qualifications_ *next;
    Qualification   value;
} *Qualifications;

typedef unsigned char   UsageType;
#define                     online 0x80
#define                     mobile 0x40
#define                     paperEnable 0x20

typedef GeneralizedTime DateOfExpiration;

typedef GeneralizedTime CertifiedTime;

typedef struct SerialNumber {
    unsigned short  length;
    unsigned char   *value;
} SerialNumber;

typedef struct RequestInfo {
    unsigned short  choice;
#       define      arcCertRequest_chosen 1
#       define      RequestInfo_null_chosen 2
    union _union {
        ARCCertRequest  arcCertRequest;  /* to choose, set choice to
                                          * arcCertRequest_chosen */
        Nulltype        null;  /* to choose, set choice to
                                * RequestInfo_null_chosen */
    } u;
} RequestInfo;

typedef struct OperationRequesterInfo {
    unsigned short  choice;
#       define      opRequester_chosen 1
#       define      OperationRequesterInfo_null_chosen 2
    union _union {
        struct GeneralNames_ *opRequester;  /* to choose, set choice to
                                             * opRequester_chosen */
        Nulltype        null;  /* to choose, set choice to
                                * OperationRequesterInfo_null_chosen */
    } u;
} OperationRequesterInfo;

typedef unsigned char   *PackageIdentifier;

typedef unsigned char   *DocumentIdentifier;

typedef struct DocumentHash {
    ARCCERT_HashAlgorithm hashAlg;
    _bit1_2         hashedDocument;
} DocumentHash;

typedef struct DocumentInfo {
    unsigned char   bit_mask;
#       define      fileIDs_present 0x80
    DocumentIdentifier docID;
    struct FileIDs_ *fileIDs;  /* optional; set in bit_mask fileIDs_present if
                                * present */
    DocumentHash    docHash;
} DocumentInfo;

typedef struct PackageDocumentInfo {
    PackageIdentifier packageID;
    DocumentInfo    docInfo;
} PackageDocumentInfo;

typedef struct PeerARCInfo {
    struct GeneralNames_ *peerARC;
    PackageIdentifier peerARCPackageID;
} PeerARCInfo;

typedef unsigned char   Reason;
#define                     userRequest 0x80
#define                     arcRequest 0x40
#define                     expired 0x20

typedef struct OperationRecord {
    unsigned char   bit_mask;
#       define      issuedDocInfo_present 0x80
#       define      peerARCInfo_present 0x40
#       define      reason_present 0x20
    _struct1_5      serialNo;
    OperationRequesterInfo opRequesterInfo;
    GeneralizedTime opRequestTime;
    GeneralizedTime opTime;
    OperationType   opType;
    PackageDocumentInfo orgDocInfo;
    PackageDocumentInfo issuedDocInfo;  /* optional; set in bit_mask
                                         * issuedDocInfo_present if present */
    PeerARCInfo     peerARCInfo;  /* optional; set in bit_mask
                                   * peerARCInfo_present if present */
    Reason          reason;  /* optional; set in bit_mask reason_present if
                              * present */
} OperationRecord;

typedef struct OriginalAndIssuedDocumentInfo {
    PackageDocumentInfo orgDocInfo;
    PackageDocumentInfo issuedDocInfo;
    ossBoolean      issuedDocOriginal;
} OriginalAndIssuedDocumentInfo;

typedef struct TargetToCertify {
    unsigned short  choice;
#       define      opRecord_chosen 1
#       define      orgAndIssued_chosen 2
#       define      dataHash_chosen 3
    union _union {
        OperationRecord opRecord;  /* to choose, set choice to
                                    * opRecord_chosen */
        OriginalAndIssuedDocumentInfo orgAndIssued;  /* to choose, set choice to
                                                      * orgAndIssued_chosen */
        HashedDataInfo  dataHash;  /* to choose, set choice to
                                    * dataHash_chosen */
    } u;
} TargetToCertify;

typedef struct ARCCertInfo {
    unsigned char   bit_mask;
#       define      ARCCertInfo_version_present 0x80
#       define      ARCCertInfo_extensions_present 0x40
    ARCVersion      version;  /* ARCCertInfo_version_present not set in bit_mask
                               * implies value is v1 */
    SerialNumber    serialNumber;
    struct GeneralNames_ *issuer;
    GeneralizedTime dateOfIssue;
    DateOfExpiration dateOfExpiration;
    struct ARCCertificatePolicies_ *policy;
    RequestInfo     requestInfo;
    TargetToCertify target;
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * ARCCertInfo_extensions_present if
                                      * present */
} ARCCertInfo;

typedef int             PKIStatus;
#define                     PKIStatus_granted 0
#define                     grantedWithMods 1
#define                     rejection 2
#define                     waiting 3
#define                     revocationWarning 4
#define                     revocationNotification 5
#define                     keyUpdateWarning 6

typedef unsigned int    PKIFailureInfo;
#define                     badAlg 0x80000000
#define                     badMessageCheck 0x40000000
#define                     badRequest 0x20000000
#define                     badTime 0x10000000
#define                     badCertId 0x08000000
#define                     badDataFormat 0x04000000
#define                     wrongAuthority 0x02000000
#define                     incorrectData 0x01000000
#define                     missingTimeStamp 0x00800000
#define                     badPOP 0x00400000
#define                     timeNotAvailable 0x00020000
#define                     unacceptedPolicy 0x00010000
#define                     unacceptedExtension 0x00008000
#define                     addInfoNotAvailable 0x00004000
#define                     systemFailure 0x00000040

typedef struct PKIStatusInfo {
    unsigned char   bit_mask;
#       define      statusString_present 0x80
#       define      failInfo_present 0x40
    PKIStatus       status;
    struct PKIFreeText_ *statusString;  /* optional; set in bit_mask
                                         * statusString_present if present */
    PKIFailureInfo  failInfo;  /* optional; set in bit_mask failInfo_present if
                                * present */
} PKIStatusInfo;

typedef struct ARCErrorNotice {
    unsigned char   bit_mask;
#       define      transactionIdentifier_present 0x80
    PKIStatusInfo   transactionStatus;
    GeneralName     transactionIdentifier;  /* optional; set in bit_mask
                                             * transactionIdentifier_present if
                                             * present */
} ARCErrorNotice;

typedef struct ARCCertResponse {
    unsigned short  choice;
#       define      arcCertInfo_chosen 1
#       define      arcErrorNotice_chosen 2
    union _union {
        ARCCertInfo     arcCertInfo;  /* to choose, set choice to
                                       * arcCertInfo_chosen */
        ARCErrorNotice  arcErrorNotice;  /* to choose, set choice to
                                          * arcErrorNotice_chosen */
    } u;
} ARCCertResponse;

typedef unsigned char   *FileIdentifier;

typedef struct FileIDs_ {
    struct FileIDs_ *next;
    FileIdentifier  value;
} *FileIDs;

typedef int             ARCCERT_PKIStatus;
#define                     accepted 0
#define                     ARCCERT_PKIStatus_grantedWithMods 1
#define                     ARCCERT_PKIStatus_rejection 2
#define                     ARCCERT_PKIStatus_waiting 3
#define                     ARCCERT_PKIStatus_revocationWarning 4
#define                     ARCCERT_PKIStatus_revocationNotification 5
#define                     ARCCERT_PKIStatus_keyUpdateWarning 6

typedef unsigned int    ARCCERT_PKIFailureInfo;
#define                     ARCCERT_PKIFailureInfo_badAlg 0x80000000
#define                     ARCCERT_PKIFailureInfo_badMessageCheck 0x40000000
#define                     ARCCERT_PKIFailureInfo_badRequest 0x20000000
#define                     ARCCERT_PKIFailureInfo_badTime 0x10000000
#define                     ARCCERT_PKIFailureInfo_badDataFormat 0x04000000
#define                     ARCCERT_PKIFailureInfo_wrongAuthority 0x02000000
#define                     ARCCERT_PKIFailureInfo_incorrectData 0x01000000
#define                     ARCCERT_PKIFailureInfo_timeNotAvailable 0x00020000
#define                     ARCCERT_PKIFailureInfo_unacceptedPolicy 0x00010000
#define                     ARCCERT_PKIFailureInfo_unacceptedExtension 0x00008000
#define                     badSenderNonce 0x00002000
#define                     signerNotTrusted 0x00000800
#define                     unsupportedVersio 0x00000200
#define                     unAuthorized 0x00000100
#define                     systemUnavail 0x00000080
#define                     ARCCERT_PKIFailureInfo_systemFailure 0x00000040

typedef int             ARCCDummy1;

typedef int             ARCCDummy2;

typedef int             ARCCDummy3;

typedef struct InfoTypeAndValue {
    unsigned char   bit_mask;
#       define      infoValue_present 0x80
    ObjectID        infoType;
    Any             infoValue;  /* optional; set in bit_mask infoValue_present
                                 * if present */
} InfoTypeAndValue;

typedef struct PKIHeader {
    unsigned short  bit_mask;
#       define      messageTime_present 0x8000
#       define      protectionAlg_present 0x4000
#       define      senderKID_present 0x2000
#       define      recipKID_present 0x1000
#       define      transactionID_present 0x0800
#       define      senderNonce_present 0x0400
#       define      recipNonce_present 0x0200
#       define      freeText_present 0x0100
#       define      generalInfo_present 0x0080
    int             pvno;
#       define      ietf_version2 1
    GeneralName     sender;
    GeneralName     recipient;
    GeneralizedTime messageTime;  /* optional; set in bit_mask
                                   * messageTime_present if present */
    AlgorithmIdentifier protectionAlg;  /* optional; set in bit_mask
                                         * protectionAlg_present if present */
    KeyIdentifier   senderKID;  /* optional; set in bit_mask senderKID_present
                                 * if present */
    KeyIdentifier   recipKID;  /* optional; set in bit_mask recipKID_present if
                                * present */
    _octet1         transactionID;  /* optional; set in bit_mask
                                     * transactionID_present if present */
    _octet1         senderNonce;  /* optional; set in bit_mask
                                   * senderNonce_present if present */
    _octet1         recipNonce;  /* optional; set in bit_mask recipNonce_present
                                  * if present */
    struct PKIFreeText_ *freeText;  /* optional; set in bit_mask
                                     * freeText_present if present */
    struct _seqof13 {
        struct _seqof13 *next;
        InfoTypeAndValue value;
    } *generalInfo;  /* optional; set in bit_mask generalInfo_present if
                      * present */
} PKIHeader;

typedef int             Version;
#define                     Version_v1 0
#define                     Version_v2 1
#define                     Version_v3 2

typedef struct Time {
    unsigned short  choice;
#       define      utcTime_chosen 1
#       define      generalTime_chosen 2
    union _union {
        UTCTime         utcTime;  /* to choose, set choice to utcTime_chosen */
        GeneralizedTime generalTime;  /* to choose, set choice to
                                       * generalTime_chosen */
    } u;
} Time;

typedef struct Validity {
    Time            notBefore;
    Time            notAfter;
} Validity;

typedef struct SubjectPublicKeyInfo {
    AlgorithmIdentifier algorithm;
    _bit1           subjectPublicKey;
} SubjectPublicKeyInfo;

typedef struct TBSCertificate {
    unsigned char   bit_mask;
#       define      TBSCertificate_version_present 0x80
#       define      TBSCertificate_issuerUniqueID_present 0x40
#       define      subjectUniqueID_present 0x20
#       define      TBSCertificate_extensions_present 0x10
    Version         version;  /* TBSCertificate_version_present not set in
                               * bit_mask implies value is v1 */
    CertificateSerialNumber serialNumber;
    AlgorithmIdentifier signature;
    Name            issuer;
    Validity        validity;
    Name            subject;
    SubjectPublicKeyInfo subjectPublicKeyInfo;
    UniqueIdentifier issuerUniqueID;  /* optional; set in bit_mask
                                       * TBSCertificate_issuerUniqueID_present
                                       * if present */
    UniqueIdentifier subjectUniqueID;  /* optional; set in bit_mask
                                        * subjectUniqueID_present if present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * TBSCertificate_extensions_present if
                                      * present */
} TBSCertificate;

typedef struct Certificate {
    TBSCertificate  tbsCertificate;
    AlgorithmIdentifier signatureAlgorithm;
    _bit1           signature;
} Certificate;

typedef struct _seqof4_ {
    struct _seqof4_ *next;
    Certificate     value;
} *_seqof4;

typedef struct EncryptedValue {
    unsigned char   bit_mask;
#       define      intendedAlg_present 0x80
#       define      EncryptedValue_symmAlg_present 0x40
#       define      encSymmKey_present 0x20
#       define      keyAlg_present 0x10
#       define      valueHint_present 0x08
    AlgorithmIdentifier intendedAlg;  /* optional; set in bit_mask
                                       * intendedAlg_present if present */
    AlgorithmIdentifier symmAlg;  /* optional; set in bit_mask
                                   * EncryptedValue_symmAlg_present if
                                   * present */
    _bit1           encSymmKey;  /* optional; set in bit_mask encSymmKey_present
                                  * if present */
    AlgorithmIdentifier keyAlg;  /* optional; set in bit_mask keyAlg_present if
                                  * present */
    _octet1         valueHint;  /* optional; set in bit_mask valueHint_present
                                 * if present */
    _bit1           encValue;
} EncryptedValue;

typedef struct CertOrEncCert {
    unsigned short  choice;
#       define      CertOrEncCert_certificate_chosen 1
#       define      encryptedCert_chosen 2
    union _union {
        Certificate     certificate;  /* to choose, set choice to
                                       * CertOrEncCert_certificate_chosen */
        EncryptedValue  encryptedCert;  /* to choose, set choice to
                                         * encryptedCert_chosen */
    } u;
} CertOrEncCert;

typedef struct SinglePubInfo {
    unsigned char   bit_mask;
#       define      pubLocation_present 0x80
    int             pubMethod;
#       define      dontCare 0
#       define      x500 1
#       define      web 2
#       define      byLDAP 3
    GeneralName     pubLocation;  /* optional; set in bit_mask
                                   * pubLocation_present if present */
} SinglePubInfo;

typedef struct PKIPublicationInfo {
    unsigned char   bit_mask;
#       define      pubInfos_present 0x80
    int             action;
#       define      dontPublish 0
#       define      pleasePublish 1
    struct _seqof11 {
        struct _seqof11 *next;
        SinglePubInfo   value;
    } *pubInfos;  /* optional; set in bit_mask pubInfos_present if present */
} PKIPublicationInfo;

typedef struct CertifiedKeyPair {
    unsigned char   bit_mask;
#       define      privateKey_present 0x80
#       define      publicationInfo_present 0x40
    CertOrEncCert   certOrEncCert;
    EncryptedValue  privateKey;  /* optional; set in bit_mask privateKey_present
                                  * if present */
    PKIPublicationInfo publicationInfo;  /* optional; set in bit_mask
                                          * publicationInfo_present if
                                          * present */
} CertifiedKeyPair;

typedef struct CertResponse {
    unsigned char   bit_mask;
#       define      certifiedKeyPair_present 0x80
#       define      rspInfo_present 0x40
    int             certReqId;
    PKIStatusInfo   status;
    CertifiedKeyPair certifiedKeyPair;  /* optional; set in bit_mask
                                         * certifiedKeyPair_present if
                                         * present */
    _octet1         rspInfo;  /* optional; set in bit_mask rspInfo_present if
                               * present */
} CertResponse;

typedef struct CertRepMessage {
    unsigned char   bit_mask;
#       define      caPubs_present 0x80
    struct _seqof4_ *caPubs;  /* optional; set in bit_mask caPubs_present if
                               * present */
    struct _seqof14 {
        struct _seqof14 *next;
        CertResponse    value;
    } *response;
} CertRepMessage;

typedef struct CertificationRequestInfo {
    Version         version;
    Name            subject;
    SubjectPublicKeyInfo subjectPublicKeyInfo;
    struct Attributes_ *attributes;
} CertificationRequestInfo;

typedef AlgorithmIdentifier SignatureAlgorithmIdentifier;

typedef struct Signature {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} Signature;

typedef struct CertificationRequest {
    CertificationRequestInfo certificationRequestInfo;
    SignatureAlgorithmIdentifier signatureAlgorithm;
    Signature       signature;
} CertificationRequest;

typedef struct KeyRecRepContent {
    unsigned char   bit_mask;
#       define      newSigCert_present 0x80
#       define      caCerts_present 0x40
#       define      keyPairHist_present 0x20
    PKIStatusInfo   status;
    Certificate     newSigCert;  /* optional; set in bit_mask newSigCert_present
                                  * if present */
    struct _seqof4_ *caCerts;  /* optional; set in bit_mask caCerts_present if
                                * present */
    struct _seqof15 {
        struct _seqof15 *next;
        CertifiedKeyPair value;
    } *keyPairHist;  /* optional; set in bit_mask keyPairHist_present if
                      * present */
} KeyRecRepContent;

typedef struct _struct1_1 {
    unsigned short  length;
    unsigned char   *value;
} _struct1_1;

typedef struct CertId {
    GeneralName     issuer;
    _struct1_1      serialNumber;
} CertId;

typedef struct TBSCertList {
    unsigned char   bit_mask;
#       define      TBSCertList_version_present 0x80
#       define      TBSCertList_nextUpdate_present 0x40
#       define      revokedCertificates_present 0x20
#       define      crlExtensions_present 0x10
    Version         version;  /* optional; set in bit_mask
                               * TBSCertList_version_present if present */
    AlgorithmIdentifier signature;
    Name            issuer;
    Time            thisUpdate;
    Time            nextUpdate;  /* optional; set in bit_mask
                                  * TBSCertList_nextUpdate_present if present */
    struct _seqof12 {
        struct _seqof12 *next;
        struct _seq1 {
            unsigned char   bit_mask;
#               define      crlEntryExtensions_present 0x80
            CertificateSerialNumber userCertificate;
            Time            revocationDate;
            struct Extensions_ *crlEntryExtensions;  /* optional; set in
                                   * bit_mask crlEntryExtensions_present if
                                   * present */
        } value;
    } *revokedCertificates;  /* optional; set in bit_mask
                              * revokedCertificates_present if present */
    struct Extensions_ *crlExtensions;  /* optional; set in bit_mask
                                         * crlExtensions_present if present */
} TBSCertList;

typedef struct CertificateList {
    TBSCertList     tbsCertList;
    AlgorithmIdentifier signatureAlgorithm;
    _bit1           signature;
} CertificateList;

typedef struct RevRepContent {
    unsigned char   bit_mask;
#       define      revCerts_present 0x80
#       define      RevRepContent_crls_present 0x40
    struct _seqof16 {
        struct _seqof16 *next;
        PKIStatusInfo   value;
    } *status;
    struct _seqof17 {
        struct _seqof17 *next;
        CertId          value;
    } *revCerts;  /* optional; set in bit_mask revCerts_present if present */
    struct _seqof18 {
        struct _seqof18 *next;
        CertificateList value;
    } *crls;  /* optional; set in bit_mask RevRepContent_crls_present if
               * present */
} RevRepContent;

typedef struct CAKeyUpdAnnContent {
    Certificate     oldWithNew;
    Certificate     newWithOld;
    Certificate     newWithNew;
} CAKeyUpdAnnContent;

typedef Certificate     CertAnnContent;

typedef struct RevAnnContent {
    unsigned char   bit_mask;
#       define      crlDetails_present 0x80
    PKIStatus       status;
    CertId          certId;
    GeneralizedTime willBeRevokedAt;
    GeneralizedTime badSinceDate;
    struct Extensions_ *crlDetails;  /* optional; set in bit_mask
                                      * crlDetails_present if present */
} RevAnnContent;

typedef Nulltype        PKIConfirmContent;

typedef struct ErrorMsgContent {
    unsigned char   bit_mask;
#       define      errorCode_present 0x80
#       define      errorDetails_present 0x40
    PKIStatusInfo   pKIStatusInfo;
    int             errorCode;  /* optional; set in bit_mask errorCode_present
                                 * if present */
    struct PKIFreeText_ *errorDetails;  /* optional; set in bit_mask
                                         * errorDetails_present if present */
} ErrorMsgContent;

typedef struct PKIBody {
    unsigned short  choice;
#       define      ir_chosen 1
#       define      ip_chosen 2
#       define      cr_chosen 3
#       define      cp_chosen 4
#       define      p10cr_chosen 5
#       define      popdecc_chosen 6
#       define      popdecr_chosen 7
#       define      kur_chosen 8
#       define      kup_chosen 9
#       define      krr_chosen 10
#       define      krp_chosen 11
#       define      rr_chosen 12
#       define      rp_chosen 13
#       define      ccr_chosen 14
#       define      ccp_chosen 15
#       define      ckuann_chosen 16
#       define      cann_chosen 17
#       define      rann_chosen 18
#       define      crlann_chosen 19
#       define      conf_chosen 20
#       define      nested_chosen 21
#       define      genm_chosen 22
#       define      genp_chosen 23
#       define      error_chosen 24
    union _union {
        struct CertReqMessages_ *ir;  /* to choose, set choice to ir_chosen */
        CertRepMessage  ip;  /* to choose, set choice to ip_chosen */
        struct CertReqMessages_ *cr;  /* to choose, set choice to cr_chosen */
        CertRepMessage  cp;  /* to choose, set choice to cp_chosen */
        CertificationRequest p10cr;  /* to choose, set choice to p10cr_chosen */
        struct POPODecKeyChallContent_ *popdecc;  /* to choose, set choice to
                                                   * popdecc_chosen */
        struct POPODecKeyRespContent_ *popdecr;  /* to choose, set choice to
                                                  * popdecr_chosen */
        struct CertReqMessages_ *kur;  /* to choose, set choice to kur_chosen */
        CertRepMessage  kup;  /* to choose, set choice to kup_chosen */
        struct CertReqMessages_ *krr;  /* to choose, set choice to krr_chosen */
        KeyRecRepContent krp;  /* to choose, set choice to krp_chosen */
        struct RevReqContent_ *rr;  /* to choose, set choice to rr_chosen */
        RevRepContent   rp;  /* to choose, set choice to rp_chosen */
        struct CertReqMessages_ *ccr;  /* to choose, set choice to ccr_chosen */
        CertRepMessage  ccp;  /* to choose, set choice to ccp_chosen */
        CAKeyUpdAnnContent ckuann;  /* to choose, set choice to ckuann_chosen */
        CertAnnContent  cann;  /* to choose, set choice to cann_chosen */
        RevAnnContent   rann;  /* to choose, set choice to rann_chosen */
        struct CRLAnnContent_ *crlann;  /* to choose, set choice to
                                         * crlann_chosen */
        PKIConfirmContent conf;  /* to choose, set choice to conf_chosen */
        struct PKIMessage *nested;  /* to choose, set choice to nested_chosen */
        struct GenMsgContent_ *genm;  /* to choose, set choice to genm_chosen */
        struct GenRepContent_ *genp;  /* to choose, set choice to genp_chosen */
        ErrorMsgContent error;  /* to choose, set choice to error_chosen */
    } u;
} PKIBody;

typedef struct PKIProtection {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} PKIProtection;

typedef struct PKIMessage {
    unsigned char   bit_mask;
#       define      protection_present 0x80
#       define      extraCerts_present 0x40
    PKIHeader       header;
    PKIBody         body;
    PKIProtection   protection;  /* optional; set in bit_mask protection_present
                                  * if present */
    struct _seqof4_ *extraCerts;  /* optional; set in bit_mask
                                   * extraCerts_present if present */
} PKIMessage;

typedef PKIMessage      NestedMessageContent;

typedef struct PKIFreeText_ {
    struct PKIFreeText_ *next;
    unsigned char   *value;
} *PKIFreeText;

typedef struct ProtectedPart {
    PKIHeader       header;
    PKIBody         body;
} ProtectedPart;

typedef ObjectID        PasswordBasedMac;

typedef ObjectID        DHBasedMac;

typedef struct DHBMParameter {
    AlgorithmIdentifier owf;
    AlgorithmIdentifier mac;
} DHBMParameter;

typedef Certificate     OOBCert;

typedef struct OOBCertHash {
    unsigned char   bit_mask;
#       define      hashAlg_present 0x80
#       define      certId_present 0x40
    AlgorithmIdentifier hashAlg;  /* optional; set in bit_mask hashAlg_present
                                   * if present */
    CertId          certId;  /* optional; set in bit_mask certId_present if
                              * present */
    _bit1           hashVal;
} OOBCertHash;

typedef struct Challenge {
    unsigned char   bit_mask;
#       define      owf_present 0x80
    AlgorithmIdentifier owf;  /* optional; set in bit_mask owf_present if
                               * present */
    _octet1         witness;
    _octet1         challenge;
} Challenge;

typedef struct POPODecKeyChallContent_ {
    struct POPODecKeyChallContent_ *next;
    Challenge       value;
} *POPODecKeyChallContent;

typedef struct POPODecKeyRespContent_ {
    struct POPODecKeyRespContent_ *next;
    int             value;
} *POPODecKeyRespContent;

typedef struct OptionalValidity {
    unsigned char   bit_mask;
#       define      OptionalValidity_notBefore_present 0x80
#       define      OptionalValidity_notAfter_present 0x40
    Time            notBefore;  /* optional; set in bit_mask
                                 * OptionalValidity_notBefore_present if
                                 * present */
    Time            notAfter;  /* optional; set in bit_mask
                                * OptionalValidity_notAfter_present if
                                * present */
} OptionalValidity;

typedef struct _struct1_3 {
    unsigned short  length;
    unsigned char   *value;
} _struct1_3;

typedef struct CertTemplate {
    unsigned short  bit_mask;
#       define      CertTemplate_version_present 0x8000
#       define      serialNumber_present 0x4000
#       define      signingAlg_present 0x2000
#       define      issuer_present 0x1000
#       define      validity_present 0x0800
#       define      subject_present 0x0400
#       define      publicKey_present 0x0200
#       define      CertTemplate_issuerUID_present 0x0100
#       define      subjectUID_present 0x0080
#       define      CertTemplate_extensions_present 0x0040
    Version         version;  /* optional; set in bit_mask
                               * CertTemplate_version_present if present */
    _struct1_3      serialNumber;  /* optional; set in bit_mask
                                    * serialNumber_present if present */
    AlgorithmIdentifier signingAlg;  /* optional; set in bit_mask
                                      * signingAlg_present if present */
    Name            issuer;  /* optional; set in bit_mask issuer_present if
                              * present */
    OptionalValidity validity;  /* optional; set in bit_mask validity_present if
                                 * present */
    Name            subject;  /* optional; set in bit_mask subject_present if
                               * present */
    SubjectPublicKeyInfo publicKey;  /* optional; set in bit_mask
                                      * publicKey_present if present */
    UniqueIdentifier issuerUID;  /* optional; set in bit_mask
                                  * CertTemplate_issuerUID_present if present */
    UniqueIdentifier subjectUID;  /* optional; set in bit_mask
                                   * subjectUID_present if present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * CertTemplate_extensions_present if
                                      * present */
} CertTemplate;

typedef unsigned char   ReasonFlags;
#define                     unused 0x80
#define                     ReasonFlags_keyCompromise 0x40
#define                     ReasonFlags_cACompromise 0x20
#define                     ReasonFlags_affiliationChanged 0x10
#define                     ReasonFlags_superseded 0x08
#define                     ReasonFlags_cessationOfOperation 0x04
#define                     ReasonFlags_certificateHold 0x02

typedef struct RevDetails {
    unsigned char   bit_mask;
#       define      RevDetails_revocationReason_present 0x80
#       define      badSinceDate_present 0x40
#       define      crlEntryDetails_present 0x20
    CertTemplate    certDetails;
    ReasonFlags     revocationReason;  /* optional; set in bit_mask
                                        * RevDetails_revocationReason_present if
                                        * present */
    GeneralizedTime badSinceDate;  /* optional; set in bit_mask
                                    * badSinceDate_present if present */
    struct Extensions_ *crlEntryDetails;  /* optional; set in bit_mask
                                           * crlEntryDetails_present if
                                           * present */
} RevDetails;

typedef struct RevReqContent_ {
    struct RevReqContent_ *next;
    RevDetails      value;
} *RevReqContent;

typedef struct CRLAnnContent_ {
    struct CRLAnnContent_ *next;
    CertificateList value;
} *CRLAnnContent;

typedef struct GenMsgContent_ {
    struct GenMsgContent_ *next;
    InfoTypeAndValue value;
} *GenMsgContent;

typedef struct GenRepContent_ {
    struct GenRepContent_ *next;
    InfoTypeAndValue value;
} *GenRepContent;

typedef struct KeyPolicyRequest {
    unsigned char   bit_mask;
#       define      requesterRefNum_present 0x80
#       define      requesterName_present 0x40
#       define      rAPolicy_present 0x20
    _octet1_2       transacId;
    _octet1_2       requesterRefNum;  /* optional; set in bit_mask
                                       * requesterRefNum_present if present */
    Name            requesterName;  /* optional; set in bit_mask
                                     * requesterName_present if present */
    Nulltype        rAPolicy;  /* optional; set in bit_mask rAPolicy_present if
                                * present */
} KeyPolicyRequest;

typedef struct _seqof1_4_ {
    struct _seqof1_4_ *next;
    InfoTypeAndValue value;
} *_seqof1_4;

typedef struct KeyPolicy {
    unsigned char   bit_mask;
#       define      KeyPolicy_extensions_present 0x80
#       define      KeyPolicy_additionalInfos_present 0x40
#       define      rAIssuanceAllowed_present 0x20
    _octet1_2       identifier;
    unsigned char   *name;
    AlgorithmIdentifier keyAlgorithm;
    int             keyBitLength;
    char            *validity;
    char            *ldapAttr;  /* NULL for not present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * KeyPolicy_extensions_present if
                                      * present */
    struct _seqof1_4_ *additionalInfos;  /* optional; set in bit_mask
                                          * KeyPolicy_additionalInfos_present if
                                          * present */
    Nulltype        rAIssuanceAllowed;  /* optional; set in bit_mask
                                         * rAIssuanceAllowed_present if
                                         * present */
} KeyPolicy;

typedef struct KeyPolicies {
    unsigned char   bit_mask;
#       define      KeyPolicies_additionalInfos_present 0x80
    _octet1_2       transacId;
    struct _seqof2_4 {
        struct _seqof2_4 *next;
        KeyPolicy       value;
    } *policies;
    struct _seqof1_4_ *additionalInfos;  /* optional; set in bit_mask
                                          * KeyPolicies_additionalInfos_present
                                          * if present */
} KeyPolicies;

typedef int             CMPEXTNDummy1;

typedef int             CMPEXTNDummy2;

typedef int             CMPEXTNDummy3;

typedef ObjectID        ContentType;

typedef struct ContentInfo {
    ContentType     contentType;
    Any             content;
} ContentInfo;

typedef int             CMSVersion;
#define                     v0 0
#define                     CMSVersion_v1 1
#define                     CMSVersion_v2 2
#define                     CMSVersion_v3 3
#define                     v4 4

typedef struct EncapsulatedContentInfo {
    unsigned char   bit_mask;
#       define      eContent_present 0x80
    ContentType     eContentType;
    _octet1         eContent;  /* optional; set in bit_mask eContent_present if
                                * present */
} EncapsulatedContentInfo;

typedef struct SignedData {
    unsigned char   bit_mask;
#       define      SignedData_certificates_present 0x80
#       define      SignedData_crls_present 0x40
    CMSVersion      version;
    struct DigestAlgorithmIdentifiers_ *digestAlgorithms;
    EncapsulatedContentInfo encapContentInfo;
    struct CertificateSet_ *certificates;  /* optional; set in bit_mask
                                            * SignedData_certificates_present if
                                            * present */
    struct CertificateRevocationLists_ *crls;  /* optional; set in bit_mask
                                                * SignedData_crls_present if
                                                * present */
    struct SignerInfos_ *signerInfos;
} SignedData;

typedef AlgorithmIdentifier DigestAlgorithmIdentifier;

typedef struct DigestAlgorithmIdentifiers_ {
    struct DigestAlgorithmIdentifiers_ *next;
    DigestAlgorithmIdentifier value;
} *DigestAlgorithmIdentifiers;

typedef struct SignerIdentifier {
    unsigned short  choice;
#       define      SignerIdentifier_issuerAndSerialNumber_chosen 1
#       define      SignerIdentifier_subjectKeyIdentifier_chosen 2
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                   * to
                             * SignerIdentifier_issuerAndSerialNumber_chosen */
        SubjectKeyIdentifier subjectKeyIdentifier;  /* to choose, set choice to
                              * SignerIdentifier_subjectKeyIdentifier_chosen */
    } u;
} SignerIdentifier;

typedef struct SignatureValue {
    unsigned int    length;
    unsigned char   *value;
} SignatureValue;

typedef struct SignerInfo {
    unsigned char   bit_mask;
#       define      signedAttrs_present 0x80
#       define      unsignedAttrs_present 0x40
    CMSVersion      version;
    SignerIdentifier sid;
    DigestAlgorithmIdentifier digestAlgorithm;
    struct SignedAttributes_ *signedAttrs;  /* optional; set in bit_mask
                                             * signedAttrs_present if present */
    SignatureAlgorithmIdentifier signatureAlgorithm;
    SignatureValue  signature;
    struct UnsignedAttributes_ *unsignedAttrs;  /* optional; set in bit_mask
                                                 * unsignedAttrs_present if
                                                 * present */
} SignerInfo;

typedef struct SignerInfos_ {
    struct SignerInfos_ *next;
    SignerInfo      value;
} *SignerInfos;

typedef struct SignedAttributes_ {
    struct SignedAttributes_ *next;
    Attribute       value;
} *SignedAttributes;

typedef struct UnsignedAttributes_ {
    struct UnsignedAttributes_ *next;
    Attribute       value;
} *UnsignedAttributes;

typedef struct OriginatorInfo {
    unsigned char   bit_mask;
#       define      OriginatorInfo_certs_present 0x80
#       define      OriginatorInfo_crls_present 0x40
    struct CertificateSet_ *certs;  /* optional; set in bit_mask
                                     * OriginatorInfo_certs_present if
                                     * present */
    struct CertificateRevocationLists_ *crls;  /* optional; set in bit_mask
                                                * OriginatorInfo_crls_present if
                                                * present */
} OriginatorInfo;

typedef AlgorithmIdentifier ContentEncryptionAlgorithmIdentifier;

typedef struct EncryptedContent {
    unsigned int    length;
    unsigned char   *value;
} EncryptedContent;

typedef struct EncryptedContentInfo {
    unsigned char   bit_mask;
#       define      encryptedContent_present 0x80
    ContentType     contentType;
    ContentEncryptionAlgorithmIdentifier contentEncryptionAlgorithm;
    EncryptedContent encryptedContent;  /* optional; set in bit_mask
                                         * encryptedContent_present if
                                         * present */
} EncryptedContentInfo;

typedef struct EnvelopedData {
    unsigned char   bit_mask;
#       define      EnvelopedData_originatorInfo_present 0x80
#       define      EnvelopedData_unprotectedAttrs_present 0x40
    CMSVersion      version;
    OriginatorInfo  originatorInfo;  /* optional; set in bit_mask
                                      * EnvelopedData_originatorInfo_present if
                                      * present */
    struct RecipientInfos_ *recipientInfos;
    EncryptedContentInfo encryptedContentInfo;
    struct UnprotectedAttributes_ *unprotectedAttrs;  /* optional; set in
                                   * bit_mask
                                   * EnvelopedData_unprotectedAttrs_present if
                                   * present */
} EnvelopedData;

typedef struct RecipientIdentifier {
    unsigned short  choice;
#       define      RecipientIdentifier_issuerAndSerialNumber_chosen 1
#       define      RecipientIdentifier_subjectKeyIdentifier_chosen 2
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                   * to
                          * RecipientIdentifier_issuerAndSerialNumber_chosen */
        SubjectKeyIdentifier subjectKeyIdentifier;  /* to choose, set choice to
                           * RecipientIdentifier_subjectKeyIdentifier_chosen */
    } u;
} RecipientIdentifier;

typedef AlgorithmIdentifier KeyEncryptionAlgorithmIdentifier;

typedef struct CryptographicMessageSyntax_EncryptedKey {
    unsigned int    length;
    unsigned char   *value;
} CryptographicMessageSyntax_EncryptedKey;

typedef struct KeyTransRecipientInfo {
    CMSVersion      version;
    RecipientIdentifier rid;
    KeyEncryptionAlgorithmIdentifier keyEncryptionAlgorithm;
    CryptographicMessageSyntax_EncryptedKey encryptedKey;
} KeyTransRecipientInfo;

typedef struct OriginatorPublicKey {
    AlgorithmIdentifier algorithm;
    _bit1           publicKey;
} OriginatorPublicKey;

typedef struct OriginatorIdentifierOrKey {
    unsigned short  choice;
#       define      OriginatorIdentifierOrKey_issuerAndSerialNumber_chosen 1
#       define      OriginatorIdentifierOrKey_subjectKeyIdentifier_chosen 2
#       define      originatorKey_chosen 3
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                   * to
                    * OriginatorIdentifierOrKey_issuerAndSerialNumber_chosen */
        SubjectKeyIdentifier subjectKeyIdentifier;  /* to choose, set choice to
                     * OriginatorIdentifierOrKey_subjectKeyIdentifier_chosen */
        OriginatorPublicKey originatorKey;  /* to choose, set choice to
                                             * originatorKey_chosen */
    } u;
} OriginatorIdentifierOrKey;

typedef struct UserKeyingMaterial {
    unsigned int    length;
    unsigned char   *value;
} UserKeyingMaterial;

typedef struct KeyAgreeRecipientInfo {
    unsigned char   bit_mask;
#       define      ukm_present 0x80
    CMSVersion      version;
    OriginatorIdentifierOrKey originator;
    UserKeyingMaterial ukm;  /* optional; set in bit_mask ukm_present if
                              * present */
    KeyEncryptionAlgorithmIdentifier keyEncryptionAlgorithm;
    struct RecipientEncryptedKeys_ *recipientEncryptedKeys;
} KeyAgreeRecipientInfo;

typedef struct OtherKeyAttribute {
    unsigned char   bit_mask;
#       define      keyAttr_present 0x80
    ObjectID        keyAttrId;
    Any             keyAttr;  /* optional; set in bit_mask keyAttr_present if
                               * present */
} OtherKeyAttribute;

typedef struct KEKIdentifier {
    unsigned char   bit_mask;
#       define      KEKIdentifier_date_present 0x80
#       define      KEKIdentifier_other_present 0x40
    _octet1         keyIdentifier;
    GeneralizedTime date;  /* optional; set in bit_mask
                            * KEKIdentifier_date_present if present */
    OtherKeyAttribute other;  /* optional; set in bit_mask
                               * KEKIdentifier_other_present if present */
} KEKIdentifier;

typedef struct KEKRecipientInfo {
    CMSVersion      version;
    KEKIdentifier   kekid;
    KeyEncryptionAlgorithmIdentifier keyEncryptionAlgorithm;
    CryptographicMessageSyntax_EncryptedKey encryptedKey;
} KEKRecipientInfo;

typedef struct RecipientInfo {
    unsigned short  choice;
#       define      ktri_chosen 1
#       define      kari_chosen 2
#       define      kekri_chosen 3
    union _union {
        KeyTransRecipientInfo ktri;  /* to choose, set choice to ktri_chosen */
        KeyAgreeRecipientInfo kari;  /* to choose, set choice to kari_chosen */
        KEKRecipientInfo kekri;  /* to choose, set choice to kekri_chosen */
    } u;
} RecipientInfo;

typedef struct RecipientInfos_ {
    struct RecipientInfos_ *next;
    RecipientInfo   value;
} *RecipientInfos;

typedef struct UnprotectedAttributes_ {
    struct UnprotectedAttributes_ *next;
    Attribute       value;
} *UnprotectedAttributes;

typedef struct RecipientKeyIdentifier {
    unsigned char   bit_mask;
#       define      RecipientKeyIdentifier_date_present 0x80
#       define      RecipientKeyIdentifier_other_present 0x40
    SubjectKeyIdentifier subjectKeyIdentifier;
    GeneralizedTime date;  /* optional; set in bit_mask
                            * RecipientKeyIdentifier_date_present if present */
    OtherKeyAttribute other;  /* optional; set in bit_mask
                               * RecipientKeyIdentifier_other_present if
                               * present */
} RecipientKeyIdentifier;

typedef struct KeyAgreeRecipientIdentifier {
    unsigned short  choice;
#       define      KeyAgreeRecipientIdentifier_issuerAndSerialNumber_chosen 1
#       define      rKeyId_chosen 2
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                   * to
                  * KeyAgreeRecipientIdentifier_issuerAndSerialNumber_chosen */
        RecipientKeyIdentifier rKeyId;  /* to choose, set choice to
                                         * rKeyId_chosen */
    } u;
} KeyAgreeRecipientIdentifier;

typedef struct RecipientEncryptedKey {
    KeyAgreeRecipientIdentifier rid;
    CryptographicMessageSyntax_EncryptedKey encryptedKey;
} RecipientEncryptedKey;

typedef struct RecipientEncryptedKeys_ {
    struct RecipientEncryptedKeys_ *next;
    RecipientEncryptedKey value;
} *RecipientEncryptedKeys;

typedef struct Digest {
    unsigned int    length;
    unsigned char   *value;
} Digest;

typedef struct DigestInfo {
    DigestAlgorithmIdentifier digestAlgorithm;
    Digest          digest;
} DigestInfo;

typedef struct DigestedData {
    CMSVersion      version;
    DigestAlgorithmIdentifier digestAlgorithm;
    EncapsulatedContentInfo encapContentInfo;
    Digest          digest;
} DigestedData;

typedef struct EncryptedData {
    unsigned char   bit_mask;
#       define      EncryptedData_unprotectedAttrs_present 0x80
    CMSVersion      version;
    EncryptedContentInfo encryptedContentInfo;
    struct UnprotectedAttributes_ *unprotectedAttrs;  /* optional; set in
                                   * bit_mask
                                   * EncryptedData_unprotectedAttrs_present if
                                   * present */
} EncryptedData;

typedef AlgorithmIdentifier MessageAuthenticationCodeAlgorithm;

typedef struct MessageAuthenticationCode {
    unsigned int    length;
    unsigned char   *value;
} MessageAuthenticationCode;

typedef struct AuthenticatedData {
    unsigned char   bit_mask;
#       define      AuthenticatedData_originatorInfo_present 0x80
#       define      digestAlgorithm_present 0x40
#       define      authenticatedAttributes_present 0x20
#       define      unauthenticatedAttributes_present 0x10
    CMSVersion      version;
    OriginatorInfo  originatorInfo;  /* optional; set in bit_mask
                                      * AuthenticatedData_originatorInfo_present
                                      * if present */
    struct RecipientInfos_ *recipientInfos;
    MessageAuthenticationCodeAlgorithm macAlgorithm;
    DigestAlgorithmIdentifier digestAlgorithm;  /* optional; set in bit_mask
                                                 * digestAlgorithm_present if
                                                 * present */
    EncapsulatedContentInfo encapContentInfo;
    struct AuthAttributes_ *authenticatedAttributes;  /* optional; set in
                                   * bit_mask authenticatedAttributes_present if
                                   * present */
    MessageAuthenticationCode mac;
    struct UnauthAttributes_ *unauthenticatedAttributes;  /* optional; set in
                                   * bit_mask unauthenticatedAttributes_present
                                   * if present */
} AuthenticatedData;

typedef struct SignedAndEnvelopedData {
    unsigned char   bit_mask;
#       define      SignedAndEnvelopedData_certificates_present 0x80
#       define      SignedAndEnvelopedData_crls_present 0x40
    CMSVersion      version;
    struct RecipientInfos_ *recipientInfos;
    struct DigestAlgorithmIdentifiers_ *digestAlgorithms;
    EncryptedContentInfo encryptedContentInfo;
    struct CertificateSet_ *certificates;  /* optional; set in bit_mask
                               * SignedAndEnvelopedData_certificates_present if
                               * present */
    struct CertificateRevocationLists_ *crls;  /* optional; set in bit_mask
                                       * SignedAndEnvelopedData_crls_present if
                                       * present */
    struct SignerInfos_ *signerInfos;
} SignedAndEnvelopedData;

typedef struct AuthAttributes_ {
    struct AuthAttributes_ *next;
    Attribute       value;
} *AuthAttributes;

typedef struct UnauthAttributes_ {
    struct UnauthAttributes_ *next;
    Attribute       value;
} *UnauthAttributes;

typedef struct CertificateRevocationLists_ {
    struct CertificateRevocationLists_ *next;
    CertificateList value;
} *CertificateRevocationLists;

typedef struct ExtendedCertificateInfo {
    Version         version;
    Certificate     certificate;
    struct Attributes_ *attributes;
} ExtendedCertificateInfo;

typedef struct ExtendedCertificate {
    ExtendedCertificateInfo extendedCertificateInfo;
    SignatureAlgorithmIdentifier signatureAlgorithm;
    Signature       signature;
} ExtendedCertificate;

typedef struct CertificateChoices {
    unsigned short  choice;
#       define      CertificateChoices_certificate_chosen 1
#       define      CertificateChoices_extendedCertificate_chosen 2
#       define      attrCert_chosen 3
    union _union {
        Certificate     certificate;  /* to choose, set choice to
                                     * CertificateChoices_certificate_chosen */
        ExtendedCertificate extendedCertificate;  /* to choose, set choice to
                             * CertificateChoices_extendedCertificate_chosen */
        AttributeCertificate attrCert;  /* to choose, set choice to
                                         * attrCert_chosen */
    } u;
} CertificateChoices;

typedef struct CertificateSet_ {
    struct CertificateSet_ *next;
    CertificateChoices value;
} *CertificateSet;

typedef struct MessageDigest {
    unsigned int    length;
    unsigned char   *value;
} MessageDigest;

typedef Time            SigningTime;

typedef SignerInfo      Countersignature;

typedef struct RC2CBCParameter {
    int             rc2ParameterVersion;
    _octet1         iv;
} RC2CBCParameter;

typedef struct OctetString {
    unsigned int    length;
    unsigned char   *value;
} OctetString;

typedef struct ContentInfo_P7 {
    unsigned char   bit_mask;
#       define      content_present 0x80
    ContentType     contentType;
    Any             content;  /* optional; set in bit_mask content_present if
                               * present */
} ContentInfo_P7;

typedef struct SignedData_P7 {
    unsigned char   bit_mask;
#       define      certificates_present 0x80
#       define      crls_present 0x40
    CMSVersion      version;
    struct DigestAlgorithmIdentifiers_ *digestAlgorithms;
    ContentInfo_P7  contentInfo;
    struct CertificateSet_ *certificates;  /* optional; set in bit_mask
                                            * certificates_present if present */
    struct CertificateRevocationLists_ *crls;  /* optional; set in bit_mask
                                                * crls_present if present */
    struct SignerInfos_ *signerInfos;
} SignedData_P7;

typedef struct DigestedData_P7 {
    CMSVersion      version;
    DigestAlgorithmIdentifier digestAlgorithm;
    ContentInfo_P7  contentInfo;
    Digest          digest;
} DigestedData_P7;

typedef int             CMSDummy1;

typedef int             CMSDummy2;

typedef struct CertRequest {
    unsigned char   bit_mask;
#       define      controls_present 0x80
    int             certReqId;
    CertTemplate    certTemplate;
    struct Controls_ *controls;  /* optional; set in bit_mask controls_present
                                  * if present */
} CertRequest;

typedef struct PKMACValue {
    AlgorithmIdentifier algId;
    _bit1           value;
} PKMACValue;

typedef struct _choice3 {
    unsigned short  choice;
#       define      sender_chosen 1
#       define      publicKeyMAC_chosen 2
    union _union {
        GeneralName     sender;  /* to choose, set choice to sender_chosen */
        PKMACValue      publicKeyMAC;  /* to choose, set choice to
                                        * publicKeyMAC_chosen */
    } u;
} _choice3;

typedef struct POPOSigningKeyInput {
    _choice3        authInfo;
    SubjectPublicKeyInfo publicKey;
} POPOSigningKeyInput;

typedef struct POPOSigningKey {
    unsigned char   bit_mask;
#       define      poposkInput_present 0x80
    POPOSigningKeyInput poposkInput;  /* optional; set in bit_mask
                                       * poposkInput_present if present */
    AlgorithmIdentifier algorithmIdentifier;
    _bit1           signature;
} POPOSigningKey;

typedef int             SubsequentMessage;
#define                     encrCert 0
#define                     challengeResp 1

typedef struct POPOPrivKey {
    unsigned short  choice;
#       define      thisMessage_chosen 1
#       define      subsequentMessage_chosen 2
#       define      dhMAC_chosen 3
    union _union {
        _bit1           thisMessage;  /* to choose, set choice to
                                       * thisMessage_chosen */
        SubsequentMessage subsequentMessage;  /* to choose, set choice to
                                               * subsequentMessage_chosen */
        _bit1           dhMAC;  /* to choose, set choice to dhMAC_chosen */
    } u;
} POPOPrivKey;

typedef struct ProofOfPossession {
    unsigned short  choice;
#       define      raVerified_chosen 1
#       define      signature_chosen 2
#       define      ProofOfPossession_keyEncipherment_chosen 3
#       define      ProofOfPossession_keyAgreement_chosen 4
    union _union {
        Nulltype        raVerified;  /* to choose, set choice to
                                      * raVerified_chosen */
        POPOSigningKey  signature;  /* to choose, set choice to
                                     * signature_chosen */
        POPOPrivKey     keyEncipherment;  /* to choose, set choice to
                                  * ProofOfPossession_keyEncipherment_chosen */
        POPOPrivKey     keyAgreement;  /* to choose, set choice to
                                     * ProofOfPossession_keyAgreement_chosen */
    } u;
} ProofOfPossession;

typedef struct AttributeTypeAndValue {
    AttributeType   type;
    AttributeValue  value;
} AttributeTypeAndValue;

typedef struct CertReqMsg {
    unsigned char   bit_mask;
#       define      pop_present 0x80
#       define      regInfo_present 0x40
    CertRequest     certReq;
    ProofOfPossession pop;  /* optional; set in bit_mask pop_present if
                             * present */
    struct _seqof10 {
        struct _seqof10 *next;
        AttributeTypeAndValue value;
    } *regInfo;  /* optional; set in bit_mask regInfo_present if present */
} CertReqMsg;

typedef struct CertReqMessages_ {
    struct CertReqMessages_ *next;
    CertReqMsg      value;
} *CertReqMessages;

typedef struct Controls_ {
    struct Controls_ *next;
    AttributeTypeAndValue value;
} *Controls;

typedef struct PBMParameter {
    _octet1         salt;
    AlgorithmIdentifier owf;
    int             iterationCount;
    AlgorithmIdentifier mac;
} PBMParameter;

typedef unsigned char   *RegToken;

typedef unsigned char   *Authenticator;

typedef struct PKIXCRMF_EncryptedKey {
    unsigned short  choice;
#       define      encryptedValue_chosen 1
    union _union {
        EncryptedValue  encryptedValue;  /* to choose, set choice to
                                          * encryptedValue_chosen */
    } u;
} PKIXCRMF_EncryptedKey;

typedef struct KeyGenParameters {
    unsigned int    length;
    unsigned char   *value;
} KeyGenParameters;

typedef struct PKIArchiveOptions {
    unsigned short  choice;
#       define      encryptedPrivKey_chosen 1
#       define      keyGenParameters_chosen 2
#       define      archiveRemGenPrivKey_chosen 3
    union _union {
        PKIXCRMF_EncryptedKey encryptedPrivKey;  /* to choose, set choice to
                                                  * encryptedPrivKey_chosen */
        KeyGenParameters keyGenParameters;  /* to choose, set choice to
                                             * keyGenParameters_chosen */
        ossBoolean      archiveRemGenPrivKey;  /* to choose, set choice to
                                               * archiveRemGenPrivKey_chosen */
    } u;
} PKIArchiveOptions;

typedef CertId          OldCertId;

typedef SubjectPublicKeyInfo ProtocolEncrKey;

typedef unsigned char   *UTF8Pairs;

typedef CertRequest     CertReq;

typedef int             CTL_Version;
#define                     CTL_Version_v1 0

typedef struct ListIdentifier {
    unsigned int    length;
    unsigned char   *value;
} ListIdentifier;

typedef struct CertificateTrustList {
    unsigned char   bit_mask;
#       define      CertificateTrustList_version_present 0x80
#       define      listIdentifier_present 0x40
#       define      CertificateTrustList_extensions_present 0x20
    CTL_Version     version;  /* CertificateTrustList_version_present not set in
                               * bit_mask implies value is v1 */
    struct SubjectUsage_ *subjectUsage;
    ListIdentifier  listIdentifier;  /* optional; set in bit_mask
                                      * listIdentifier_present if present */
    int             sequenceNumber;
    Time            thisUpdate;
    Time            nextUpdate;
    AlgorithmIdentifier subjectAlgorithm;
    struct TrustedSubjects_ *trustedSubjects;
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * CertificateTrustList_extensions_present
                                      * if present */
} CertificateTrustList;

typedef ObjectID        CTLPurposeId;

typedef struct SubjectUsage_ {
    struct SubjectUsage_ *next;
    CTLPurposeId    value;
} *SubjectUsage;

typedef struct HashValue {
    unsigned int    length;
    unsigned char   *value;
} HashValue;

typedef struct TrustedCertificate {
    unsigned char   bit_mask;
#       define      trustedCertificateAttributes_present 0x80
    HashValue       trustedCertificateHash;
    struct TrustedCertificateAttributes_ *trustedCertificateAttributes;  
                                  /* optional; set in bit_mask
                                   * trustedCertificateAttributes_present if
                                   * present */
} TrustedCertificate;

typedef struct TrustedSubjects_ {
    struct TrustedSubjects_ *next;
    TrustedCertificate value;
} *TrustedSubjects;

typedef struct TrustedCertificateAttributes_ {
    struct TrustedCertificateAttributes_ *next;
    AttributeTypeAndValue value;
} *TrustedCertificateAttributes;

typedef int             CTLDummy1;

typedef int             CTLDummy2;

typedef struct DhSigStatic {
    unsigned char   bit_mask;
#       define      issuerAndSerial_present 0x80
    IssuerAndSerialNumber issuerAndSerial;  /* optional; set in bit_mask
                                             * issuerAndSerial_present if
                                             * present */
    MessageDigest   hashValue;
} DhSigStatic;

typedef int             Type;
#define                     usb 0
#define                     smartcard 1

typedef struct TokenDistURLDriverInfo {
    char            *supportedOSVersion;
    char            *version;
    GeneralName     name;
    Type            type;
    GeneralName     cp;
    char            *info;  /* NULL for not present */
} TokenDistURLDriverInfo;

typedef struct TokenDistributionURL {
    char            *tokenID;
    struct TokenDistURLDriverInfo_ {
        struct TokenDistURLDriverInfo_ *next;
        TokenDistURLDriverInfo value;
    } *driverInfo;
} TokenDistributionURL;

typedef struct TokenDistURLToBeSigned_ {
    struct TokenDistURLToBeSigned_ *next;
    TokenDistributionURL value;
} *TokenDistURLToBeSigned;

typedef struct SignerAndSerialNumber {
    Name            issuer;
    CertificateSerialNumber serialNumber;
} SignerAndSerialNumber;

typedef struct TokenDistURLSignatureValue {
    struct TokenDistURLToBeSigned_ *toBeSigned;
    AlgorithmIdentifier signatureAlgorithm;
    SignerAndSerialNumber signerAndSerialNumber;
    _bit1_2         signature;
} TokenDistURLSignatureValue;

typedef int             KISA_DISTRIBUTION_TOKEN_TokenDistURLDummy1;

typedef struct PKIXDVCS_Digest {
    unsigned int    length;
    unsigned char   *value;
} PKIXDVCS_Digest;

typedef struct PKIXDVCS_DigestInfo {
    DigestAlgorithmIdentifier digestAlgorithm;
    PKIXDVCS_Digest digest;
} PKIXDVCS_DigestInfo;

typedef int             Nonce;

typedef struct DVCSTime {
    unsigned short  choice;
#       define      genTime_chosen 1
#       define      timeStampToken_chosen 2
    union _union {
        GeneralizedTime genTime;  /* to choose, set choice to genTime_chosen */
        ContentInfo     timeStampToken;  /* to choose, set choice to
                                          * timeStampToken_chosen */
    } u;
} DVCSTime;

typedef struct Hash {
    unsigned int    length;
    unsigned char   *value;
} Hash;

typedef struct ESS_IssuerSerial {
    struct GeneralNames_ *issuer;
    CertificateSerialNumber serialNumber;
} ESS_IssuerSerial;

typedef struct ESSCertID {
    unsigned char   bit_mask;
#       define      issuerSerial_present 0x80
    Hash            certHash;
    ESS_IssuerSerial issuerSerial;  /* optional; set in bit_mask
                                     * issuerSerial_present if present */
} ESSCertID;

typedef enum CRLReason {
    unspecified = 0,
    CRLReason_keyCompromise = 1,
    CRLReason_cACompromise = 2,
    CRLReason_affiliationChanged = 3,
    CRLReason_superseded = 4,
    CRLReason_cessationOfOperation = 5,
    CRLReason_certificateHold = 6,
    removeFromCRL = 8
} CRLReason;

typedef struct RevokedInfo {
    unsigned char   bit_mask;
#       define      RevokedInfo_revocationReason_present 0x80
    GeneralizedTime revocationTime;
    CRLReason       revocationReason;  /* optional; set in bit_mask
                                        * RevokedInfo_revocationReason_present
                                        * if present */
} RevokedInfo;

typedef Nulltype        UnknownInfo;

typedef struct CertStatus {
    unsigned short  choice;
#       define      good_chosen 1
#       define      revoked_chosen 2
#       define      unknown_chosen 3
    union _union {
        Nulltype        good;  /* to choose, set choice to good_chosen */
        RevokedInfo     revoked;  /* to choose, set choice to revoked_chosen */
        UnknownInfo     unknown;  /* to choose, set choice to unknown_chosen */
    } u;
} CertStatus;

typedef struct CertID {
    AlgorithmIdentifier hashAlgorithm;
    _octet1         issuerNameHash;
    _octet1         issuerKeyHash;
    CertificateSerialNumber serialNumber;
} CertID;

typedef enum OCSPResponseStatus {
    successful = 0,
    malformedRequest = 1,
    internalError = 2,
    tryLater = 3,
    sigRequired = 5,
    unauthorized = 6
} OCSPResponseStatus;

typedef struct ResponseBytes {
    ObjectID        responseType;
    _octet1         response;
} ResponseBytes;

typedef struct OCSPResponse {
    unsigned char   bit_mask;
#       define      responseBytes_present 0x80
    OCSPResponseStatus responseStatus;
    ResponseBytes   responseBytes;  /* optional; set in bit_mask
                                     * responseBytes_present if present */
} OCSPResponse;

typedef struct Extension {
    unsigned char   bit_mask;
#       define      critical_present 0x80
    ObjectID        extnID;
    ossBoolean      critical;  /* critical_present not set in bit_mask implies
                                * value is FALSE */
    _octet1         extnValue;
} Extension;

typedef struct CertEtcToken {
    unsigned short  choice;
#       define      certificate_chosen 1
#       define      esscertid_chosen 2
#       define      pkistatus_chosen 3
#       define      assertion_chosen 4
#       define      crl_chosen 5
#       define      ocspcertstatus_chosen 6
#       define      oscpcertid_chosen 7
#       define      oscpresponse_chosen 8
#       define      capabilities_chosen 9
#       define      extension_chosen 10
    union _union {
        Certificate     certificate;  /* to choose, set choice to
                                       * certificate_chosen */
        ESSCertID       esscertid;  /* to choose, set choice to
                                     * esscertid_chosen */
        PKIStatusInfo   pkistatus;  /* to choose, set choice to
                                     * pkistatus_chosen */
        ContentInfo     assertion;  /* to choose, set choice to
                                     * assertion_chosen */
        CertificateList crl;  /* to choose, set choice to crl_chosen */
        CertStatus      ocspcertstatus;  /* to choose, set choice to
                                          * ocspcertstatus_chosen */
        CertID          oscpcertid;  /* to choose, set choice to
                                      * oscpcertid_chosen */
        OCSPResponse    oscpresponse;  /* to choose, set choice to
                                        * oscpresponse_chosen */
        struct SMIMECapabilities_ *capabilities;  /* to choose, set choice to
                                                   * capabilities_chosen */
        Extension       extension;  /* to choose, set choice to
                                     * extension_chosen */
    } u;
} CertEtcToken;

typedef struct PathProcInput {
    unsigned char   bit_mask;
#       define      PathProcInput_inhibitPolicyMapping_present 0x80
#       define      explicitPolicyReqd_present 0x40
    struct _seqof1_2 {
        struct _seqof1_2 *next;
        PolicyInformation value;
    } *acceptablePolicySet;
    ossBoolean      inhibitPolicyMapping;  
                               /* PathProcInput_inhibitPolicyMapping_present not
                                * set in bit_mask implies value is FALSE */
    ossBoolean      explicitPolicyReqd;  /* explicitPolicyReqd_present not set
                                          * in bit_mask implies value is
                                          * FALSE */
} PathProcInput;

typedef struct TargetEtcChain {
    unsigned char   bit_mask;
#       define      chain_present 0x80
#       define      pathProcInput_present 0x40
    CertEtcToken    target;
    struct _seqof2_2 {
        struct _seqof2_2 *next;
        CertEtcToken    value;
    } *chain;  /* optional; set in bit_mask chain_present if present */
    PathProcInput   pathProcInput;  /* optional; set in bit_mask
                                     * pathProcInput_present if present */
} TargetEtcChain;

typedef enum ServiceType {
    cpd = 1,
    vsd = 2,
    cpkc = 3,
    ccpd = 4
} ServiceType;

typedef struct DVCSRequestInformation {
    unsigned char   bit_mask;
#       define      DVCSRequestInformation_version_present 0x80
#       define      nonce_present 0x40
#       define      requestTime_present 0x20
#       define      requester_present 0x10
#       define      requestPolicy_present 0x08
#       define      dvcs_present 0x04
#       define      dataLocations_present 0x02
#       define      DVCSRequestInformation_extensions_present 0x01
    int             version;  /* DVCSRequestInformation_version_present not set
                               * in bit_mask implies value is 1 */
    ServiceType     service;
    Nonce           nonce;  /* optional; set in bit_mask nonce_present if
                             * present */
    DVCSTime        requestTime;  /* optional; set in bit_mask
                                   * requestTime_present if present */
    struct GeneralNames_ *requester;  /* optional; set in bit_mask
                                       * requester_present if present */
    PolicyInformation requestPolicy;  /* optional; set in bit_mask
                                       * requestPolicy_present if present */
    struct GeneralNames_ *dvcs;  /* optional; set in bit_mask dvcs_present if
                                  * present */
    struct GeneralNames_ *dataLocations;  /* optional; set in bit_mask
                                           * dataLocations_present if present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                 * DVCSRequestInformation_extensions_present if
                                 * present */
} DVCSRequestInformation;

typedef struct _seqof3_2_ {
    struct _seqof3_2_ *next;
    TargetEtcChain  value;
} *_seqof3_2;

typedef struct Data {
    unsigned short  choice;
#       define      message_chosen 1
#       define      messageImprint_chosen 2
#       define      certs_chosen 3
    union _union {
        _octet1         message;  /* to choose, set choice to message_chosen */
        PKIXDVCS_DigestInfo messageImprint;  /* to choose, set choice to
                                              * messageImprint_chosen */
        struct _seqof3_2_ *certs;  /* to choose, set choice to certs_chosen */
    } u;
} Data;

typedef struct DVCSRequest {
    unsigned char   bit_mask;
#       define      DVCSRequest_transactionIdentifier_present 0x80
    DVCSRequestInformation requestInformation;
    Data            data;
    GeneralName     transactionIdentifier;  /* optional; set in bit_mask
                                 * DVCSRequest_transactionIdentifier_present if
                                 * present */
} DVCSRequest;

typedef struct DVCSCertInfo {
    unsigned char   bit_mask;
#       define      DVCSCertInfo_version_present 0x80
#       define      dvStatus_present 0x40
#       define      policy_present 0x20
#       define      reqSignature_present 0x10
#       define      certs_present 0x08
#       define      DVCSCertInfo_extensions_present 0x04
    int             version;  /* DVCSCertInfo_version_present not set in
                               * bit_mask implies value is 1 */
    DVCSRequestInformation dvReqInfo;
    PKIXDVCS_DigestInfo messageImprint;
    CertificateSerialNumber serialNumber;
    DVCSTime        responseTime;
    PKIStatusInfo   dvStatus;  /* optional; set in bit_mask dvStatus_present if
                                * present */
    PolicyInformation policy;  /* optional; set in bit_mask policy_present if
                                * present */
    struct SignerInfos_ *reqSignature;  /* optional; set in bit_mask
                                         * reqSignature_present if present */
    struct _seqof3_2_ *certs;  /* optional; set in bit_mask certs_present if
                                * present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * DVCSCertInfo_extensions_present if
                                      * present */
} DVCSCertInfo;

typedef struct DVCSErrorNotice {
    unsigned char   bit_mask;
#       define      DVCSErrorNotice_transactionIdentifier_present 0x80
    PKIStatusInfo   transactionStatus;
    GeneralName     transactionIdentifier;  /* optional; set in bit_mask
                             * DVCSErrorNotice_transactionIdentifier_present if
                             * present */
} DVCSErrorNotice;

typedef struct DVCSResponse {
    unsigned short  choice;
#       define      dvCertInfo_chosen 1
#       define      dvErrorNote_chosen 2
    union _union {
        DVCSCertInfo    dvCertInfo;  /* to choose, set choice to
                                      * dvCertInfo_chosen */
        DVCSErrorNotice dvErrorNote;  /* to choose, set choice to
                                       * dvErrorNote_chosen */
    } u;
} DVCSResponse;

typedef int             DVCSDummy1;

typedef int             DVCSDummy2;

typedef int             DVCSDummy3;

typedef struct ContentIdentifier {
    unsigned int    length;
    unsigned char   *value;
} ContentIdentifier;

typedef int             AllOrFirstTier;
#define                     allReceipts 0
#define                     firstTierRecipients 1

typedef struct _seqof6_ {
    struct _seqof6_ *next;
    struct GeneralNames_ *value;
} *_seqof6;

typedef struct ReceiptsFrom {
    unsigned short  choice;
#       define      allOrFirstTier_chosen 1
#       define      receiptList_chosen 2
    union _union {
        AllOrFirstTier  allOrFirstTier;  /* to choose, set choice to
                                          * allOrFirstTier_chosen */
        struct _seqof6_ *receiptList;  /* to choose, set choice to
                                        * receiptList_chosen */
    } u;
} ReceiptsFrom;

typedef struct ReceiptRequest {
    ContentIdentifier signedContentIdentifier;
    ReceiptsFrom    receiptsFrom;
    struct _seqof6_ *receiptsTo;
} ReceiptRequest;

typedef int             ESSVersion;
#define                     ESSVersion_v1 1

typedef struct Receipt {
    ESSVersion      version;
    ContentType     contentType;
    ContentIdentifier signedContentIdentifier;
    _octet1         originatorSignatureValue;
} Receipt;

typedef struct ContentHints {
    unsigned char   *contentDescription;  /* NULL for not present */
    ContentType     contentType;
} ContentHints;

typedef struct MsgSigDigest {
    unsigned int    length;
    unsigned char   *value;
} MsgSigDigest;

typedef struct ContentReference {
    ContentType     contentType;
    ContentIdentifier signedContentIdentifier;
    _octet1         originatorSignatureValue;
} ContentReference;

typedef ObjectID        SecurityPolicyIdentifier;

typedef unsigned short  SecurityClassification;
#define                     SecurityClassification_unmarked 0U
#define                     SecurityClassification_unclassified 1U
#define                     SecurityClassification_restricted 2U
#define                     SecurityClassification_confidential 3U
#define                     SecurityClassification_secret 4U
#define                     top_secret 5U

typedef struct ESSPrivacyMark {
    unsigned short  choice;
#       define      pString_chosen 1
#       define      ESSPrivacyMark_utf8String_chosen 2
    union _union {
        char            pString[129];  /* to choose, set choice to
                                        * pString_chosen */
        unsigned char   *utf8String;  /* to choose, set choice to
                                       * ESSPrivacyMark_utf8String_chosen */
    } u;
} ESSPrivacyMark;

typedef struct ESSSecurityLabel {
    unsigned char   bit_mask;
#       define      security_classification_present 0x80
#       define      privacy_mark_present 0x40
#       define      security_categories_present 0x20
    SecurityPolicyIdentifier security_policy_identifier;
    SecurityClassification security_classification;  /* optional; set in
                                   * bit_mask security_classification_present if
                                   * present */
    ESSPrivacyMark  privacy_mark;  /* optional; set in bit_mask
                                    * privacy_mark_present if present */
    struct SecurityCategories_ *security_categories;  /* optional; set in
                                   * bit_mask security_categories_present if
                                   * present */
} ESSSecurityLabel;

typedef struct ExtendedSecurityServices_SecurityCategory {
    ObjectID        type;
    Any             value;
} ExtendedSecurityServices_SecurityCategory;

typedef struct SecurityCategories_ {
    struct SecurityCategories_ *next;
    ExtendedSecurityServices_SecurityCategory value;
} *SecurityCategories;

typedef struct EquivalentLabels_ {
    struct EquivalentLabels_ *next;
    ESSSecurityLabel value;
} *EquivalentLabels;

typedef struct EntityIdentifier {
    unsigned short  choice;
#       define      EntityIdentifier_issuerAndSerialNumber_chosen 1
#       define      EntityIdentifier_subjectKeyIdentifier_chosen 2
    union _union {
        IssuerAndSerialNumber issuerAndSerialNumber;  /* to choose, set choice
                                   * to
                             * EntityIdentifier_issuerAndSerialNumber_chosen */
        SubjectKeyIdentifier subjectKeyIdentifier;  /* to choose, set choice to
                              * EntityIdentifier_subjectKeyIdentifier_chosen */
    } u;
} EntityIdentifier;

typedef struct MLReceiptPolicy {
    unsigned short  choice;
#       define      none_chosen 1
#       define      insteadOf_chosen 2
#       define      inAdditionTo_chosen 3
    union _union {
        Nulltype        none;  /* to choose, set choice to none_chosen */
        struct _seqof6_ *insteadOf;  /* to choose, set choice to
                                      * insteadOf_chosen */
        struct _seqof6_ *inAdditionTo;  /* to choose, set choice to
                                         * inAdditionTo_chosen */
    } u;
} MLReceiptPolicy;

typedef struct MLData {
    unsigned char   bit_mask;
#       define      mlReceiptPolicy_present 0x80
    EntityIdentifier mailListIdentifier;
    GeneralizedTime expansionTime;
    MLReceiptPolicy mlReceiptPolicy;  /* optional; set in bit_mask
                                       * mlReceiptPolicy_present if present */
} MLData;

typedef struct MLExpansionHistory_ {
    struct MLExpansionHistory_ *next;
    MLData          value;
} *MLExpansionHistory;

typedef struct _seqof9_ {
    struct _seqof9_ *next;
    PolicyInformation value;
} *_seqof9;

typedef struct SigningCertificate {
    unsigned char   bit_mask;
#       define      policies_present 0x80
    struct _seqof8 {
        struct _seqof8  *next;
        ESSCertID       value;
    } *certs;
    struct _seqof9_ *policies;  /* optional; set in bit_mask policies_present if
                                 * present */
} SigningCertificate;

typedef struct SignatureToken {
    char            *driverName;
    AlgorithmIdentifier hashID;
    _octet1_2       hashValue;
} SignatureToken;

typedef struct SignTokenToBeSigned_ {
    struct SignTokenToBeSigned_ *next;
    SignatureToken  value;
} *SignTokenToBeSigned;

typedef struct SignTokenSignatureValue {
    struct SignTokenToBeSigned_ *toBeSigned;
    AlgorithmIdentifier signatureAlgorithm;
    SignerAndSerialNumber signerAndSerialNumber;
    _octet1_2       signature;
} SignTokenSignatureValue;

typedef struct PublicKeyAndChallenge {
    SubjectPublicKeyInfo spki;
    char            *challenge;
} PublicKeyAndChallenge;

typedef struct SignedPublicKeyAndChallenge {
    PublicKeyAndChallenge publicKeyAndChallenge;
    AlgorithmIdentifier signatureAlgorithm;
    _bit1_2         signature;
} SignedPublicKeyAndChallenge;

typedef struct Request {
    unsigned char   bit_mask;
#       define      singleRequestExtensions_present 0x80
    CertID          reqCert;
    struct Extensions_ *singleRequestExtensions;  /* optional; set in bit_mask
                                           * singleRequestExtensions_present if
                                           * present */
} Request;

typedef struct TBSRequest {
    unsigned char   bit_mask;
#       define      TBSRequest_version_present 0x80
#       define      requestorName_present 0x40
#       define      requestExtensions_present 0x20
    Version         version;  /* TBSRequest_version_present not set in bit_mask
                               * implies value is v1 */
    GeneralName     requestorName;  /* optional; set in bit_mask
                                     * requestorName_present if present */
    struct _seqof3 {
        struct _seqof3  *next;
        Request         value;
    } *requestList;
    struct Extensions_ *requestExtensions;  /* optional; set in bit_mask
                                             * requestExtensions_present if
                                             * present */
} TBSRequest;

typedef struct OCSP_Signature {
    unsigned char   bit_mask;
#       define      OCSP_Signature_certs_present 0x80
    AlgorithmIdentifier signatureAlgorithm;
    _bit1           signature;
    struct _seqof4_ *certs;  /* optional; set in bit_mask
                              * OCSP_Signature_certs_present if present */
} OCSP_Signature;

typedef struct OCSPRequest {
    unsigned char   bit_mask;
#       define      optionalSignature_present 0x80
    TBSRequest      tbsRequest;
    OCSP_Signature  optionalSignature;  /* optional; set in bit_mask
                                         * optionalSignature_present if
                                         * present */
} OCSPRequest;

typedef struct KeyHash {
    unsigned int    length;
    unsigned char   *value;
} KeyHash;

typedef struct ResponderID {
    unsigned short  choice;
#       define      byName_chosen 1
#       define      byKey_chosen 2
    union _union {
        Name            byName;  /* to choose, set choice to byName_chosen */
        KeyHash         byKey;  /* to choose, set choice to byKey_chosen */
    } u;
} ResponderID;

typedef struct SingleResponse {
    unsigned char   bit_mask;
#       define      SingleResponse_nextUpdate_present 0x80
#       define      singleExtensions_present 0x40
    CertID          certID;
    CertStatus      certStatus;
    GeneralizedTime thisUpdate;
    GeneralizedTime nextUpdate;  /* optional; set in bit_mask
                                  * SingleResponse_nextUpdate_present if
                                  * present */
    struct Extensions_ *singleExtensions;  /* optional; set in bit_mask
                                            * singleExtensions_present if
                                            * present */
} SingleResponse;

typedef struct ResponseData {
    unsigned char   bit_mask;
#       define      ResponseData_version_present 0x80
#       define      responseExtensions_present 0x40
    Version         version;  /* ResponseData_version_present not set in
                               * bit_mask implies value is v1 */
    ResponderID     responderID;
    GeneralizedTime producedAt;
    struct _seqof5 {
        struct _seqof5  *next;
        SingleResponse  value;
    } *responses;
    struct Extensions_ *responseExtensions;  /* optional; set in bit_mask
                                              * responseExtensions_present if
                                              * present */
} ResponseData;

typedef struct BasicOCSPResponse {
    unsigned char   bit_mask;
#       define      BasicOCSPResponse_certs_present 0x80
    ResponseData    tbsResponseData;
    AlgorithmIdentifier signatureAlgorithm;
    _bit1           signature;
    struct _seqof4_ *certs;  /* optional; set in bit_mask
                              * BasicOCSPResponse_certs_present if present */
} BasicOCSPResponse;

typedef GeneralizedTime ArchiveCutoff;

typedef struct AcceptableResponses_ {
    struct AcceptableResponses_ *next;
    ObjectID        value;
} *AcceptableResponses;

typedef struct ServiceLocator {
    unsigned char   bit_mask;
#       define      locator_present 0x80
    Name            issuer;
    struct AuthorityInfoAccessSyntax_ *locator;  /* optional; set in bit_mask
                                                  * locator_present if
                                                  * present */
} ServiceLocator;

typedef Certificate     OPP2ConnReq;

typedef struct OPP2ConnResp {
    unsigned int    length;
    unsigned char   *value;
} OPP2ConnResp;

typedef struct OPP2BindReq {
    AlgorithmIdentifier algorithmIdentifier;
    _bit1           signature;
} OPP2BindReq;

typedef struct EncKeyValue {
    _bit1           encSymmKey;
    _octet1         hashedKey;
} EncKeyValue;

typedef struct OPP2BindResp {
    unsigned char   bit_mask;
#       define      encKey_present 0x80
#       define      OPP2BindResp_symmAlg_present 0x40
#       define      OPP2BindResp_asymmAlg_present 0x20
    int             status;
#       define      OPP2BindResp_status_granted 0
#       define      OPP2BindResp_status_badSignature 1
#       define      OPP2BindResp_status_badCertificate 2
#       define      OPP2BindResp_status_illegalOperator 3
    EncKeyValue     encKey;  /* optional; set in bit_mask encKey_present if
                              * present */
    AlgorithmIdentifier symmAlg;  /* optional; set in bit_mask
                                   * OPP2BindResp_symmAlg_present if present */
    AlgorithmIdentifier asymmAlg;  /* optional; set in bit_mask
                                    * OPP2BindResp_asymmAlg_present if
                                    * present */
} OPP2BindResp;

typedef struct BindReqInput {
    Certificate     certificate;
} BindReqInput;

typedef struct BindReq {
    BindReqInput    bindReqInput;
    AlgorithmIdentifier algorithmIdentifier;
    _bit1           signature;
} BindReq;

typedef struct BindRep {
    unsigned char   bit_mask;
#       define      symmAlg_present 0x80
#       define      asymmAlg_present 0x40
    int             status;
#       define      status_granted 0
#       define      badSignature 1
#       define      badCertificate 2
#       define      deactivatedOperator 3
    unsigned char   *BindRep_operator;  /* NULL for not present */
    _bit1           encSymmKey;
    AlgorithmIdentifier symmAlg;  /* optional; set in bit_mask symmAlg_present
                                   * if present */
    AlgorithmIdentifier asymmAlg;  /* optional; set in bit_mask asymmAlg_present
                                    * if present */
} BindRep;

typedef struct BindReq_XW {
    unsigned char   bit_mask;
#       define      bindReqInput_present 0x80
    unsigned char   serial[241];
    BindReqInput    bindReqInput;  /* optional; set in bit_mask
                                    * bindReqInput_present if present */
    AlgorithmIdentifier algorithmIdentifier;
    _bit1           signature;
} BindReq_XW;

typedef struct ALGORITHM_IDENTIFIER {
    unsigned char   bit_mask;
#       define      ALGORITHM_IDENTIFIER_Type_present 0x80
    ObjectID        id;
    unsigned short  Type;  /* optional; set in bit_mask
                            * ALGORITHM_IDENTIFIER_Type_present if present */
} ALGORITHM_IDENTIFIER;

typedef struct PKCS1AlgorithmIdentifier {
    unsigned char   bit_mask;
#       define      PKCS1AlgorithmIdentifier_parameters_present 0x80
    ObjectID        algorithm;
    OpenType        parameters;  /* optional; set in bit_mask
                                  * PKCS1AlgorithmIdentifier_parameters_present
                                  * if present */
} PKCS1AlgorithmIdentifier;

typedef PKCS1AlgorithmIdentifier PKCS1_V21_HashAlgorithm;

typedef Nulltype        SHA1Parameters;

typedef PKCS1AlgorithmIdentifier MaskGenAlgorithm;

typedef struct EncodingParameters {
    unsigned int    length;
    unsigned char   *value;
} EncodingParameters;

typedef PKCS1AlgorithmIdentifier PSourceAlgorithm;

typedef struct RSAES_OAEP_params {
    unsigned char   bit_mask;
#       define      RSAES_OAEP_params_hashAlgorithm_present 0x80
#       define      RSAES_OAEP_params_maskGenAlgorithm_present 0x40
#       define      pSourceAlgorithm_present 0x20
    PKCS1_V21_HashAlgorithm hashAlgorithm;  /* default assumed if omitted; set
                                   * in bit_mask
                                   * RSAES_OAEP_params_hashAlgorithm_present if
                                   * present */
    MaskGenAlgorithm maskGenAlgorithm;  /* default assumed if omitted; set in
                                   * bit_mask
                                   * RSAES_OAEP_params_maskGenAlgorithm_present
                                   * if present */
    PSourceAlgorithm pSourceAlgorithm;  /* default assumed if omitted; set in
                                   * bit_mask pSourceAlgorithm_present if
                                   * present */
} RSAES_OAEP_params;

typedef PKCS1AlgorithmIdentifier RSAES_AlgorithmIdentifier;

typedef int             TrailerField;
#define                     trailerFieldBC 1

typedef struct RSASSA_PSS_params {
    unsigned char   bit_mask;
#       define      RSASSA_PSS_params_hashAlgorithm_present 0x80
#       define      RSASSA_PSS_params_maskGenAlgorithm_present 0x40
#       define      saltLength_present 0x20
#       define      trailerField_present 0x10
    PKCS1_V21_HashAlgorithm hashAlgorithm;  /* default assumed if omitted; set
                                   * in bit_mask
                                   * RSASSA_PSS_params_hashAlgorithm_present if
                                   * present */
    MaskGenAlgorithm maskGenAlgorithm;  /* default assumed if omitted; set in
                                   * bit_mask
                                   * RSASSA_PSS_params_maskGenAlgorithm_present
                                   * if present */
    int             saltLength;  /* saltLength_present not set in bit_mask
                                  * implies value is 20 */
    TrailerField    trailerField;  /* trailerField_present not set in bit_mask
                                    * implies value is trailerFieldBC */
} RSASSA_PSS_params;

typedef PKCS1AlgorithmIdentifier RSASSA_AlgorithmIdentifier;

typedef int             PKCS1_V21_TokenDistURLDummy1;

typedef struct _choice2 {
    unsigned short  choice;
#       define      specified_chosen 1
#       define      otherSource_chosen 2
    union _union {
        _octet1         specified;  /* to choose, set choice to
                                     * specified_chosen */
        AlgorithmIdentifier otherSource;  /* to choose, set choice to
                                           * otherSource_chosen */
    } u;
} _choice2;

typedef struct PBKDF2_params {
    unsigned char   bit_mask;
#       define      keyLength_present 0x80
#       define      prf_present 0x40
    _choice2        salt;
    unsigned int    iterationCount;
    unsigned int    keyLength;  /* optional; set in bit_mask keyLength_present
                                 * if present */
    AlgorithmIdentifier prf;  /* optional; set in bit_mask prf_present if
                               * present */
} PBKDF2_params;

typedef struct _octet2 {
    unsigned short  length;
    unsigned char   value[8];
} _octet2;

typedef struct PBEParameter {
    _octet2         salt;
    int             iterationCount;
} PBEParameter;

typedef struct PBES2_params {
    AlgorithmIdentifier keyDerivationFunc;
    AlgorithmIdentifier encryptionScheme;
} PBES2_params;

typedef struct PBMAC1_params {
    AlgorithmIdentifier keyDerivationFunc;
    AlgorithmIdentifier messageAuthScheme;
} PBMAC1_params;

typedef struct RC2_CBC_Parameter {
    unsigned char   bit_mask;
#       define      rc2ParameterVersion_present 0x80
    int             rc2ParameterVersion;  /* optional; set in bit_mask
                                           * rc2ParameterVersion_present if
                                           * present */
    _octet2         iv;
} RC2_CBC_Parameter;

typedef struct RC5_CBC_Parameters {
    unsigned char   bit_mask;
#       define      iv_present 0x80
    unsigned short  version;
#       define      v1_0 16U
    unsigned short  rounds;
    unsigned short  blockSizeInBits;
    _octet1         iv;  /* optional; set in bit_mask iv_present if present */
} RC5_CBC_Parameters;

typedef char            *MyPrintableString;

typedef struct ExtendedCertificateOrCertificate {
    unsigned short  choice;
#       define      ExtendedCertificateOrCertificate_certificate_chosen 1
#       define      ExtendedCertificateOrCertificate_extendedCertificate_chosen 2
    union _union {
        Certificate     certificate;  /* to choose, set choice to
                       * ExtendedCertificateOrCertificate_certificate_chosen */
        ExtendedCertificate extendedCertificate;  /* to choose, set choice to
               * ExtendedCertificateOrCertificate_extendedCertificate_chosen */
    } u;
} ExtendedCertificateOrCertificate;

typedef AlgorithmIdentifier PrivateKeyAlgorithmIdentifier;

typedef struct PrivateKey {
    unsigned int    length;
    unsigned char   *value;
} PrivateKey;

typedef struct PrivateKeyInfo {
    unsigned char   bit_mask;
#       define      attributes_present 0x80
    Version         version;
    PrivateKeyAlgorithmIdentifier privateKeyAlgorithm;
    PrivateKey      privateKey;
    struct Attributes_ *attributes;  /* optional; set in bit_mask
                                      * attributes_present if present */
} PrivateKeyInfo;

typedef AlgorithmIdentifier EncryptionAlgorithmIdentifier;

typedef struct PKCS8EncryptedData {
    unsigned int    length;
    unsigned char   *value;
} PKCS8EncryptedData;

typedef struct EncryptedPrivateKeyInfo {
    EncryptionAlgorithmIdentifier encryptionAlgorithm;
    PKCS8EncryptedData encryptedData;
} EncryptedPrivateKeyInfo;

typedef char            PKCS9EmailAddress[256];

typedef struct _char4 {
    unsigned short  length;
    char            *value;
} _char4;

typedef struct _char3 {
    unsigned short  length;
    int             *value;
} _char3;

typedef struct PKCS_9_DirectoryString {
    unsigned short  choice;
#       define      directoryString_DirectoryString_teletexString_chosen 1
#       define      directoryString_DirectoryString_printableString_chosen 2
#       define      directoryString_DirectoryString_universalString_chosen 3
    union _union {
        _char4          teletexString;  /* to choose, set choice to
                      * directoryString_DirectoryString_teletexString_chosen */
        _char4          printableString;  /* to choose, set choice to
                    * directoryString_DirectoryString_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                    * directoryString_DirectoryString_universalString_chosen */
    } u;
} PKCS_9_DirectoryString;

typedef struct PKCS9String {
    unsigned short  choice;
#       define      ia5String_chosen 1
#       define      directoryString_chosen 2
    union _union {
        _char4          ia5String;  /* to choose, set choice to
                                     * ia5String_chosen */
        PKCS_9_DirectoryString directoryString;  /* to choose, set choice to
                                                  * directoryString_chosen */
    } u;
} PKCS9String;

typedef PKCS9String PKCS9UnstructuredName;

typedef struct PKCS9UnstructuredAddress {
    unsigned short  choice;
#       define      directoryString_DirectoryString_teletexString_chosen 1
#       define      directoryString_DirectoryString_printableString_chosen 2
#       define      directoryString_DirectoryString_universalString_chosen 3
    union _union {
        _char4          teletexString;  /* to choose, set choice to
                      * directoryString_DirectoryString_teletexString_chosen */
        _char4          printableString;  /* to choose, set choice to
                    * directoryString_DirectoryString_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                    * directoryString_DirectoryString_universalString_chosen */
    } u;
} PKCS9UnstructuredAddress;

typedef ObjectID        PKCS9ContentType;

typedef struct PKCS9MessageDigest {
    unsigned int    length;
    unsigned char   *value;
} PKCS9MessageDigest;

typedef Time            PKCS9SigningTime;

typedef struct PKCS9SigningDescription {
    unsigned short  choice;
#       define      directoryString_DirectoryString_teletexString_chosen 1
#       define      directoryString_DirectoryString_printableString_chosen 2
#       define      directoryString_DirectoryString_universalString_chosen 3
    union _union {
        _char4          teletexString;  /* to choose, set choice to
                      * directoryString_DirectoryString_teletexString_chosen */
        _char4          printableString;  /* to choose, set choice to
                    * directoryString_DirectoryString_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                    * directoryString_DirectoryString_universalString_chosen */
    } u;
} PKCS9SigningDescription;

typedef struct SMIMECapabilities_ *PKCS9SMIMECapabilities;

typedef struct SMIMECapability {
    unsigned char   bit_mask;
#       define      parameters_present 0x80
    ObjectID        algorithm;
    Any             parameters;  /* optional; set in bit_mask parameters_present
                                  * if present */
} SMIMECapability;

typedef struct SMIMECapabilities_ {
    struct SMIMECapabilities_ *next;
    SMIMECapability value;
} *SMIMECapabilities;

typedef struct MATCHING_RULE {
    unsigned char   bit_mask;
#       define      AssertionType_present 0x80
    unsigned short  AssertionType;  /* optional; set in bit_mask
                                     * AssertionType_present if present */
    ObjectID        id;
} MATCHING_RULE;

typedef enum AttributeUsage {
    userApplications = 0,
    directoryOperation = 1,
    distributedOperation = 2,
    dSAOperation = 3
} AttributeUsage;

typedef struct ATTRIBUTE {
    unsigned char   bit_mask;
#       define      Type_present 0x80
#       define      single_valued_present 0x40
#       define      collective_present 0x20
#       define      no_user_modification_present 0x10
#       define      usage_present 0x08
    struct ATTRIBUTE *derivation;  /* NULL for not present */
    unsigned short  Type;  /* optional; set in bit_mask Type_present if
                            * present */
    struct MATCHING_RULE *equality_match;  /* NULL for not present */
    struct MATCHING_RULE *ordering_match;  /* NULL for not present */
    struct MATCHING_RULE *substrings_match;  /* NULL for not present */
    ossBoolean      single_valued;  /* single_valued_present not set in bit_mask
                                     * implies value is FALSE */
    ossBoolean      collective;  /* collective_present not set in bit_mask
                                  * implies value is FALSE */
    ossBoolean      no_user_modification;  /* no_user_modification_present not
                                    * set in bit_mask implies value is FALSE */
    AttributeUsage  usage;  /* usage_present not set in bit_mask implies value
                             * is userApplications */
    ObjectID        id;
} ATTRIBUTE;

typedef struct MacData {
    unsigned char   bit_mask;
#       define      iterations_present 0x80
    DigestInfo      mac;
    _octet1         macSalt;
    int             iterations;  /* iterations_present not set in bit_mask
                                  * implies value is 1 */
} MacData;

typedef struct PFX {
    unsigned char   bit_mask;
#       define      macData_present 0x80
    LONG_LONG       version;
#       define      version_v3 3LL
    ContentInfo     authSafe;
    MacData         macData;  /* optional; set in bit_mask macData_present if
                               * present */
} PFX;

typedef struct AuthenticatedSafe_ {
    struct AuthenticatedSafe_ *next;
    ContentInfo     value;
} *AuthenticatedSafe;

typedef struct PKCS12Attribute {
    ObjectID        attrId;
    struct _setof1_2 {
        struct _setof1_2 *next;
        OpenType        value;
    } *attrValues;
} PKCS12Attribute;

typedef struct SafeBag {
    unsigned char   bit_mask;
#       define      bagAttributes_present 0x80
    ObjectID        bagId;
    OpenType        bagValue;
    struct _setof2_2 {
        struct _setof2_2 *next;
        PKCS12Attribute value;
    } *bagAttributes;  /* optional; set in bit_mask bagAttributes_present if
                        * present */
} SafeBag;

typedef struct SafeContents_ {
    struct SafeContents_ *next;
    SafeBag         value;
} *SafeContents;

typedef TYPE_IDENTIFIER BAG_TYPE;

typedef PrivateKeyInfo  KeyBag;

typedef EncryptedPrivateKeyInfo PKCS8ShroudedKeyBag;

typedef struct CertBag {
    ObjectID        certId;
    OpenType        certValue;
} CertBag;

typedef struct X509CertificateBag {
    unsigned int    length;
    unsigned char   *value;
} X509CertificateBag;

typedef char            *SdsiCertificateBag;

typedef struct CRLBag {
    ObjectID        crlId;
    OpenType        crltValue;
} CRLBag;

typedef struct X509CRLBag {
    unsigned int    length;
    unsigned char   *value;
} X509CRLBag;

typedef struct SecretBag {
    ObjectID        secretTypeId;
    OpenType        secretValue;
} SecretBag;

typedef struct FriendlyNameBMPString {
    unsigned short  length;
    unsigned short  *value;
} FriendlyNameBMPString;

typedef struct LocalKeyIdOctetString {
    unsigned int    length;
    unsigned char   *value;
} LocalKeyIdOctetString;

typedef int             PKCS12Dummy1;

typedef int             PKCS12Dummy2;

typedef int             PKCS12Dummy3;

typedef int             PKCS12Dummy4;

typedef int             PKCS12Dummy5;

typedef int             PKCS12Dummy6;

typedef int             PKCS12Dummy7;

typedef struct Attributes_ {
    struct Attributes_ *next;
    Attribute       value;
} *Attributes;

typedef ObjectID        AlgorithmID;

typedef struct _char5 {
    unsigned short  length;
    char            *value;
} _char5;

typedef struct _char5_ {
    unsigned short  length;
    unsigned char   *value;
} _char5_;

typedef struct _char6 {
    unsigned short  length;
    unsigned short  *value;
} _char6;

typedef struct X520name {
    unsigned short  choice;
#       define      X520name_teletexString_chosen 1
#       define      X520name_printableString_chosen 2
#       define      X520name_universalString_chosen 3
#       define      X520name_utf8String_chosen 4
#       define      X520name_bmpString_chosen 5
    union _union {
        _char5          teletexString;  /* to choose, set choice to
                                         * X520name_teletexString_chosen */
        _char5          printableString;  /* to choose, set choice to
                                           * X520name_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                                           * X520name_universalString_chosen */
        _char5_         utf8String;  /* to choose, set choice to
                                      * X520name_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * X520name_bmpString_chosen */
    } u;
} X520name;

typedef struct X520CommonName {
    unsigned short  choice;
#       define      X520CommonName_teletexString_chosen 1
#       define      X520CommonName_printableString_chosen 2
#       define      X520CommonName_universalString_chosen 3
#       define      X520CommonName_utf8String_chosen 4
#       define      X520CommonName_bmpString_chosen 5
    union _union {
        char            teletexString[65];  /* to choose, set choice to
                                       * X520CommonName_teletexString_chosen */
        char            printableString[65];  /* to choose, set choice to
                                     * X520CommonName_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                                     * X520CommonName_universalString_chosen */
        unsigned char   utf8String[385];  /* to choose, set choice to
                                          * X520CommonName_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * X520CommonName_bmpString_chosen */
    } u;
} X520CommonName;

typedef struct X520LocalityName {
    unsigned short  choice;
#       define      X520LocalityName_teletexString_chosen 1
#       define      X520LocalityName_printableString_chosen 2
#       define      X520LocalityName_universalString_chosen 3
#       define      X520LocalityName_utf8String_chosen 4
#       define      X520LocalityName_bmpString_chosen 5
    union _union {
        char            teletexString[129];  /* to choose, set choice to
                                     * X520LocalityName_teletexString_chosen */
        char            printableString[129];  /* to choose, set choice to
                                   * X520LocalityName_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                                   * X520LocalityName_universalString_chosen */
        unsigned char   utf8String[769];  /* to choose, set choice to
                                        * X520LocalityName_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * X520LocalityName_bmpString_chosen */
    } u;
} X520LocalityName;

typedef struct X520StateOrProvinceName {
    unsigned short  choice;
#       define      X520StateOrProvinceName_teletexString_chosen 1
#       define      X520StateOrProvinceName_printableString_chosen 2
#       define      X520StateOrProvinceName_universalString_chosen 3
#       define      X520StateOrProvinceName_utf8String_chosen 4
#       define      X520StateOrProvinceName_bmpString_chosen 5
    union _union {
        char            teletexString[129];  /* to choose, set choice to
                              * X520StateOrProvinceName_teletexString_chosen */
        char            printableString[129];  /* to choose, set choice to
                            * X520StateOrProvinceName_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                            * X520StateOrProvinceName_universalString_chosen */
        unsigned char   utf8String[769];  /* to choose, set choice to
                                 * X520StateOrProvinceName_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                  * X520StateOrProvinceName_bmpString_chosen */
    } u;
} X520StateOrProvinceName;

typedef struct X520OrganizationName {
    unsigned short  choice;
#       define      X520OrganizationName_teletexString_chosen 1
#       define      X520OrganizationName_printableString_chosen 2
#       define      X520OrganizationName_universalString_chosen 3
#       define      X520OrganizationName_utf8String_chosen 4
#       define      X520OrganizationName_bmpString_chosen 5
    union _union {
        char            teletexString[65];  /* to choose, set choice to
                                 * X520OrganizationName_teletexString_chosen */
        char            printableString[65];  /* to choose, set choice to
                               * X520OrganizationName_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                               * X520OrganizationName_universalString_chosen */
        unsigned char   utf8String[385];  /* to choose, set choice to
                                    * X520OrganizationName_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * X520OrganizationName_bmpString_chosen */
    } u;
} X520OrganizationName;

typedef struct X520OrganizationalUnitName {
    unsigned short  choice;
#       define      X520OrganizationalUnitName_teletexString_chosen 1
#       define      X520OrganizationalUnitName_printableString_chosen 2
#       define      X520OrganizationalUnitName_universalString_chosen 3
#       define      X520OrganizationalUnitName_utf8String_chosen 4
#       define      X520OrganizationalUnitName_bmpString_chosen 5
    union _union {
        char            teletexString[65];  /* to choose, set choice to
                           * X520OrganizationalUnitName_teletexString_chosen */
        char            printableString[65];  /* to choose, set choice to
                         * X520OrganizationalUnitName_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                         * X520OrganizationalUnitName_universalString_chosen */
        unsigned char   utf8String[385];  /* to choose, set choice to
                              * X520OrganizationalUnitName_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                               * X520OrganizationalUnitName_bmpString_chosen */
    } u;
} X520OrganizationalUnitName;

typedef struct X520Title {
    unsigned short  choice;
#       define      X520Title_teletexString_chosen 1
#       define      X520Title_printableString_chosen 2
#       define      X520Title_universalString_chosen 3
#       define      X520Title_utf8String_chosen 4
#       define      X520Title_bmpString_chosen 5
    union _union {
        char            teletexString[65];  /* to choose, set choice to
                                            * X520Title_teletexString_chosen */
        char            printableString[65];  /* to choose, set choice to
                                          * X520Title_printableString_chosen */
        _char3          universalString;  /* to choose, set choice to
                                          * X520Title_universalString_chosen */
        unsigned char   utf8String[385];  /* to choose, set choice to
                                           * X520Title_utf8String_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * X520Title_bmpString_chosen */
    } u;
} X520Title;

typedef char            *X520dnQualifier;

typedef char            X520countryName[3];

typedef char            Pkcs9email[129];

typedef struct RDNSequence_ {
    struct RDNSequence_ *next;
    struct RelativeDistinguishedName_ *value;
} *RDNSequence;

typedef struct RDNSequence_ *DistinguishedName;

typedef struct RelativeDistinguishedName_ {
    struct RelativeDistinguishedName_ *next;
    AttributeTypeAndValue value;
} *RelativeDistinguishedName;

typedef struct Extensions_ {
    struct Extensions_ *next;
    Extension       value;
} *Extensions;

typedef struct Certificates {
    struct Certificate *userCertificate;
    struct PCaPubs_ *certificationPath;
} Certificates;

typedef struct PCaPubs_ {
    struct PCaPubs_ *next;
    Certificate     value;
} *PCaPubs;

typedef struct X509_Certificates {
    unsigned char   bit_mask;
#       define      certificationPath_present 0x80
    Certificate     userCertificate;
    struct ForwardCertificationPath_ *certificationPath;  /* optional; set in
                                   * bit_mask certificationPath_present if
                                   * present */
} X509_Certificates;

typedef struct ForwardCertificationPath_ {
    struct ForwardCertificationPath_ *next;
    struct CrossCertificates_ *value;
} *ForwardCertificationPath;

typedef struct CertificatePair {
    unsigned char   bit_mask;
#       define      forward_present 0x80
#       define      reverse_present 0x40
    Certificate     forward;  /* optional; set in bit_mask forward_present if
                               * present */
    Certificate     reverse;  /* optional; set in bit_mask reverse_present if
                               * present */
} CertificatePair;

typedef struct CertificationPath {
    unsigned char   bit_mask;
#       define      theCACertificates_present 0x80
    Certificate     userCertificate;
    struct _seqof19 {
        struct _seqof19 *next;
        CertificatePair value;
    } *theCACertificates;  /* optional; set in bit_mask
                            * theCACertificates_present if present */
} CertificationPath;

typedef struct CrossCertificates_ {
    struct CrossCertificates_ *next;
    Certificate     value;
} *CrossCertificates;

typedef struct _struct1 {
    unsigned short  length;
    unsigned char   *value;
} _struct1;

typedef struct RSAPrivateKey {
    Version         version;
    _struct1        modulus;
    _struct1        publicExponent;
    _struct1        privateExponent;
    _struct1        prime1;
    _struct1        prime2;
    _struct1        exponent1;
    _struct1        exponent2;
    _struct1        coefficient;
} RSAPrivateKey;

typedef struct RSAPublicKey {
    _struct1        modulus;
    int             publicExponent;
} RSAPublicKey;

typedef struct PlainText_ {
    struct PlainText_ *next;
    _octet1         value;
} *PlainText;

typedef struct Dss_Sig_Value {
    int             r;
    int             s;
} Dss_Sig_Value;

typedef struct ValidationParms {
    _bit1           seed;
    int             pgenCounter;
} ValidationParms;

typedef struct DomainParameters {
    unsigned char   bit_mask;
#       define      j_present 0x80
#       define      validationParms_present 0x40
    int             p;
    int             g;
    int             q;
    int             j;  /* optional; set in bit_mask j_present if present */
    ValidationParms validationParms;  /* optional; set in bit_mask
                                       * validationParms_present if present */
} DomainParameters;

typedef struct Dss_Parms {
    int             p;
    int             q;
    int             g;
} Dss_Parms;

typedef char            OrganizationalUnitName[33];

typedef struct OrganizationalUnitNames_ {
    struct OrganizationalUnitNames_ *next;
    OrganizationalUnitName value;
} *OrganizationalUnitNames;

typedef struct BuiltInDomainDefinedAttribute {
    char            type[9];
    char            value[129];
} BuiltInDomainDefinedAttribute;

typedef struct BuiltInDomainDefinedAttributes_ {
    struct BuiltInDomainDefinedAttributes_ *next;
    BuiltInDomainDefinedAttribute value;
} *BuiltInDomainDefinedAttributes;

typedef struct ExtensionAttribute {
    unsigned short  extension_attribute_type;
    Any             extension_attribute_value;
} ExtensionAttribute;

typedef struct ExtensionAttributes_ {
    struct ExtensionAttributes_ *next;
    ExtensionAttribute value;
} *ExtensionAttributes;

typedef char            CommonName[65];

typedef char            TeletexCommonName[65];

typedef char            TeletexOrganizationName[65];

typedef struct TeletexPersonalName {
    unsigned char   bit_mask;
#       define      TeletexPersonalName_given_name_present 0x80
#       define      TeletexPersonalName_initials_present 0x40
#       define      TeletexPersonalName_generation_qualifier_present 0x20
    char            surname[41];
    char            given_name[17];  /* optional; set in bit_mask
                                      * TeletexPersonalName_given_name_present
                                      * if present */
    char            initials[6];  /* optional; set in bit_mask
                                   * TeletexPersonalName_initials_present if
                                   * present */
    char            generation_qualifier[4];  /* optional; set in bit_mask
                          * TeletexPersonalName_generation_qualifier_present if
                          * present */
} TeletexPersonalName;

typedef char            TeletexOrganizationalUnitName[33];

typedef struct TeletexOrganizationalUnitNames_ {
    struct TeletexOrganizationalUnitNames_ *next;
    TeletexOrganizationalUnitName value;
} *TeletexOrganizationalUnitNames;

typedef char            PDSName[17];

typedef struct PhysicalDeliveryCountryName {
    unsigned short  choice;
#       define      PhysicalDeliveryCountryName_x121_dcc_code_chosen 1
#       define      PhysicalDeliveryCountryName_iso_3166_alpha2_code_chosen 2
    union _union {
        char            x121_dcc_code[4];  /* to choose, set choice to
                          * PhysicalDeliveryCountryName_x121_dcc_code_chosen */
        char            iso_3166_alpha2_code[3];  /* to choose, set choice to
                   * PhysicalDeliveryCountryName_iso_3166_alpha2_code_chosen */
    } u;
} PhysicalDeliveryCountryName;

typedef struct PostalCode {
    unsigned short  choice;
#       define      numeric_code_chosen 1
#       define      printable_code_chosen 2
    union _union {
        char            numeric_code[17];  /* to choose, set choice to
                                            * numeric_code_chosen */
        char            printable_code[17];  /* to choose, set choice to
                                              * printable_code_chosen */
    } u;
} PostalCode;

typedef struct PDSParameter {
    unsigned char   bit_mask;
#       define      printable_string_present 0x80
#       define      PDSParameter_teletex_string_present 0x40
    char            printable_string[31];  /* optional; set in bit_mask
                                            * printable_string_present if
                                            * present */
    char            teletex_string[31];  /* optional; set in bit_mask
                                          * PDSParameter_teletex_string_present
                                          * if present */
} PDSParameter;

typedef PDSParameter    PhysicalDeliveryOfficeName;

typedef PDSParameter    PhysicalDeliveryOfficeNumber;

typedef PDSParameter    ExtensionORAddressComponents;

typedef PDSParameter    PhysicalDeliveryPersonalName;

typedef PDSParameter    PhysicalDeliveryOrganizationName;

typedef PDSParameter    ExtensionPhysicalDeliveryAddressComponents;

typedef struct UnformattedPostalAddress {
    unsigned char   bit_mask;
#       define      printable_address_present 0x80
#       define      UnformattedPostalAddress_teletex_string_present 0x40
    struct _seqof20 {
        struct _seqof20 *next;
        char            value[31];
    } *printable_address;  /* optional; set in bit_mask
                            * printable_address_present if present */
    char            teletex_string[181];  /* optional; set in bit_mask
                           * UnformattedPostalAddress_teletex_string_present if
                           * present */
} UnformattedPostalAddress;

typedef PDSParameter    StreetAddress;

typedef PDSParameter    PostOfficeBoxAddress;

typedef PDSParameter    PosteRestanteAddress;

typedef PDSParameter    UniquePostalName;

typedef PDSParameter    LocalPostalAttributes;

typedef struct PresentationAddress {
    unsigned char   bit_mask;
#       define      pSelector_present 0x80
#       define      sSelector_present 0x40
#       define      tSelector_present 0x20
    _octet1         pSelector;  /* optional; set in bit_mask pSelector_present
                                 * if present */
    _octet1         sSelector;  /* optional; set in bit_mask sSelector_present
                                 * if present */
    _octet1         tSelector;  /* optional; set in bit_mask tSelector_present
                                 * if present */
    struct _setof3 {
        struct _setof3  *next;
        _octet1         value;
    } *nAddresses;
} PresentationAddress;

typedef struct ExtendedNetworkAddress {
    unsigned short  choice;
#       define      e163_4_address_chosen 1
#       define      psap_address_chosen 2
    union _union {
        struct _seq2 {
            unsigned char   bit_mask;
#               define      sub_address_present 0x80
            char            number[16];
            char            sub_address[41];  /* optional; set in bit_mask
                                               * sub_address_present if
                                               * present */
        } e163_4_address;  /* to choose, set choice to e163_4_address_chosen */
        PresentationAddress psap_address;  /* to choose, set choice to
                                            * psap_address_chosen */
    } u;
} ExtendedNetworkAddress;

typedef unsigned short  TerminalType;
#define                     telex 3U
#define                     teletex 4U
#define                     g3_facsimile 5U
#define                     g4_facsimile 6U
#define                     ia5_terminal 7U
#define                     videotex 8U

typedef struct TeletexDomainDefinedAttribute {
    char            type[9];
    char            value[129];
} TeletexDomainDefinedAttribute;

typedef struct TeletexDomainDefinedAttributes_ {
    struct TeletexDomainDefinedAttributes_ *next;
    TeletexDomainDefinedAttribute value;
} *TeletexDomainDefinedAttributes;

typedef struct AuthorityKeyIdentifier {
    unsigned char   bit_mask;
#       define      keyIdentifier_present 0x80
#       define      authorityCertIssuer_present 0x40
#       define      authorityCertSerialNumber_present 0x20
    KeyIdentifier   keyIdentifier;  /* optional; set in bit_mask
                                     * keyIdentifier_present if present */
    struct GeneralNames_ *authorityCertIssuer;  /* optional; set in bit_mask
                                                 * authorityCertIssuer_present
                                                 * if present */
    CertificateSerialNumber authorityCertSerialNumber;  /* optional; set in
                                   * bit_mask authorityCertSerialNumber_present
                                   * if present */
} AuthorityKeyIdentifier;

typedef unsigned short  KeyUsage;
#define                     digitalSignature 0x8000
#define                     nonRepudiation 0x4000
#define                     KeyUsage_keyEncipherment 0x2000
#define                     dataEncipherment 0x1000
#define                     KeyUsage_keyAgreement 0x0800
#define                     keyCertSign 0x0400
#define                     cRLSign 0x0200
#define                     encipherOnly 0x0100
#define                     decipherOnly 0x0080

typedef struct PrivateKeyUsagePeriod {
    unsigned char   bit_mask;
#       define      PrivateKeyUsagePeriod_notBefore_present 0x80
#       define      PrivateKeyUsagePeriod_notAfter_present 0x40
    GeneralizedTime notBefore;  /* optional; set in bit_mask
                                 * PrivateKeyUsagePeriod_notBefore_present if
                                 * present */
    GeneralizedTime notAfter;  /* optional; set in bit_mask
                                * PrivateKeyUsagePeriod_notAfter_present if
                                * present */
} PrivateKeyUsagePeriod;

typedef struct CertificatePolicies_ {
    struct CertificatePolicies_ *next;
    PolicyInformation value;
} *CertificatePolicies;

typedef char            *CPSuri;

typedef struct DisplayText {
    unsigned short  choice;
#       define      visibleString_chosen 1
#       define      DisplayText_bmpString_chosen 2
#       define      DisplayText_utf8String_chosen 3
    union _union {
        char            visibleString[201];  /* to choose, set choice to
                                              * visibleString_chosen */
        _char6          bmpString;  /* to choose, set choice to
                                     * DisplayText_bmpString_chosen */
        unsigned char   utf8String[1201];  /* to choose, set choice to
                                            * DisplayText_utf8String_chosen */
    } u;
} DisplayText;

typedef struct _seqof21_ {
    struct _seqof21_ *next;
    int             value;
} *_seqof21;

typedef struct NoticeReference {
    DisplayText     organization;
    struct _seqof21_ *noticeNumbers;
} NoticeReference;

typedef struct UserNotice {
    unsigned char   bit_mask;
#       define      noticeRef_present 0x80
#       define      explicitText_present 0x40
    NoticeReference noticeRef;  /* optional; set in bit_mask noticeRef_present
                                 * if present */
    DisplayText     explicitText;  /* optional; set in bit_mask
                                    * explicitText_present if present */
} UserNotice;

typedef struct PolicyMappings_ {
    struct PolicyMappings_ *next;
    struct _seq3 {
        CertPolicyId    issuerDomainPolicy;
        CertPolicyId    subjectDomainPolicy;
    } value;
} *PolicyMappings;

typedef struct GeneralNames_ *SubjectAltName;

typedef struct GeneralNames_ {
    struct GeneralNames_ *next;
    GeneralName     value;
} *GeneralNames;

typedef struct GeneralNames_ *IssuerAltName;

typedef struct SubjectDirectoryAttributes_ {
    struct SubjectDirectoryAttributes_ *next;
    Attribute       value;
} *SubjectDirectoryAttributes;

typedef struct BasicConstraints {
    unsigned char   bit_mask;
#       define      cA_present 0x80
#       define      BasicConstraints_pathLenConstraint_present 0x40
    ossBoolean      cA;  /* cA_present not set in bit_mask implies value is
                          * FALSE */
    unsigned int    pathLenConstraint;  /* optional; set in bit_mask
                                * BasicConstraints_pathLenConstraint_present if
                                * present */
} BasicConstraints;

typedef struct NameConstraints {
    unsigned char   bit_mask;
#       define      permittedSubtrees_present 0x80
#       define      excludedSubtrees_present 0x40
    struct GeneralSubtrees_ *permittedSubtrees;  /* optional; set in bit_mask
                                                  * permittedSubtrees_present if
                                                  * present */
    struct GeneralSubtrees_ *excludedSubtrees;  /* optional; set in bit_mask
                                                 * excludedSubtrees_present if
                                                 * present */
} NameConstraints;

typedef unsigned int    BaseDistance;

typedef struct GeneralSubtree {
    unsigned char   bit_mask;
#       define      minimum_present 0x80
#       define      maximum_present 0x40
    GeneralName     base;
    BaseDistance    minimum;  /* minimum_present not set in bit_mask implies
                               * value is 0 */
    BaseDistance    maximum;  /* optional; set in bit_mask maximum_present if
                               * present */
} GeneralSubtree;

typedef struct GeneralSubtrees_ {
    struct GeneralSubtrees_ *next;
    GeneralSubtree  value;
} *GeneralSubtrees;

typedef unsigned int    SkipCerts;

typedef struct PolicyConstraints {
    unsigned char   bit_mask;
#       define      requireExplicitPolicy_present 0x80
#       define      inhibitPolicyMapping_present 0x40
    SkipCerts       requireExplicitPolicy;  /* optional; set in bit_mask
                                             * requireExplicitPolicy_present if
                                             * present */
    SkipCerts       inhibitPolicyMapping;  /* optional; set in bit_mask
                                            * inhibitPolicyMapping_present if
                                            * present */
} PolicyConstraints;

typedef struct DistributionPointName {
    unsigned short  choice;
#       define      fullName_chosen 1
#       define      nameRelativeToCRLIssuer_chosen 2
    union _union {
        struct GeneralNames_ *fullName;  /* to choose, set choice to
                                          * fullName_chosen */
        struct RelativeDistinguishedName_ *nameRelativeToCRLIssuer;  /* to
                                   * choose, set choice to
                                   * nameRelativeToCRLIssuer_chosen */
    } u;
} DistributionPointName;

typedef struct DistributionPoint {
    unsigned char   bit_mask;
#       define      DistributionPoint_distributionPoint_present 0x80
#       define      reasons_present 0x40
#       define      cRLIssuer_present 0x20
    DistributionPointName distributionPoint;  /* optional; set in bit_mask
                               * DistributionPoint_distributionPoint_present if
                               * present */
    ReasonFlags     reasons;  /* optional; set in bit_mask reasons_present if
                               * present */
    struct GeneralNames_ *cRLIssuer;  /* optional; set in bit_mask
                                       * cRLIssuer_present if present */
} DistributionPoint;

typedef struct CRLDistPointsSyntax_ {
    struct CRLDistPointsSyntax_ *next;
    DistributionPoint value;
} *CRLDistPointsSyntax;

typedef ObjectID        KeyPurposeId;

typedef struct ExtKeyUsageSyntax_ {
    struct ExtKeyUsageSyntax_ *next;
    KeyPurposeId    value;
} *ExtKeyUsageSyntax;

typedef struct AccessDescription {
    ObjectID        accessMethod;
    GeneralName     accessLocation;
} AccessDescription;

typedef struct AuthorityInfoAccessSyntax_ {
    struct AuthorityInfoAccessSyntax_ *next;
    AccessDescription value;
} *AuthorityInfoAccessSyntax;

typedef unsigned int    CRLNumber;

typedef struct IssuingDistributionPoint {
    unsigned char   bit_mask;
#       define      IssuingDistributionPoint_distributionPoint_present 0x80
#       define      onlyContainsUserCerts_present 0x40
#       define      onlyContainsCACerts_present 0x20
#       define      onlySomeReasons_present 0x10
#       define      indirectCRL_present 0x08
    DistributionPointName distributionPoint;  /* optional; set in bit_mask
                        * IssuingDistributionPoint_distributionPoint_present if
                        * present */
    ossBoolean      onlyContainsUserCerts;  /* onlyContainsUserCerts_present not
                                    * set in bit_mask implies value is FALSE */
    ossBoolean      onlyContainsCACerts;  /* onlyContainsCACerts_present not set
                                           * in bit_mask implies value is
                                           * FALSE */
    ReasonFlags     onlySomeReasons;  /* optional; set in bit_mask
                                       * onlySomeReasons_present if present */
    ossBoolean      indirectCRL;  /* indirectCRL_present not set in bit_mask
                                   * implies value is FALSE */
} IssuingDistributionPoint;

typedef CRLNumber       BaseCRLNumber;

typedef struct GeneralNames_ *CertificateIssuer;

typedef ObjectID        HoldInstructionCode;

typedef GeneralizedTime InvalidityDate;

typedef unsigned char   NetscapeCertType;
#define                     sslClient 0x80
#define                     sslServer 0x40
#define                     NetscapeCertType_smime 0x20
#define                     objectSigning 0x10
#define                     provision 0x08
#define                     sslCA 0x04
#define                     smimeCA 0x02
#define                     objectSigningCA 0x01

typedef char            *NetscapeBaseUrl;

typedef char            *NetscapeRevocationUrl;

typedef char            *NetscapeCaRevocationUrl;

typedef char            *NetscapeCertRenewalUrl;

typedef char            *NetscapeCaPolicyUrl;

typedef char            *NetscapeSSLServerName;

typedef char            *NetscapeComment;

typedef struct HashContent {
    char            *idn;
    _bit1           randomNum;
} HashContent;

typedef AlgorithmIdentifier VIDHashAlgorithm;

typedef AlgorithmIdentifier VIDEncryptionAlgorithm;

typedef struct IDNumber88_IssuerAndSerialNumber {
    Name            issuer;
    CertificateSerialNumber serialNumber;
} IDNumber88_IssuerAndSerialNumber;

typedef struct EncryptedVID {
    unsigned char   bit_mask;
#       define      EncryptedVID_version_present 0x80
#       define      vidHashAlg_present 0x40
    int             version;  /* EncryptedVID_version_present not set in
                               * bit_mask implies value is 0 */
    VIDHashAlgorithm vidHashAlg;  /* optional; set in bit_mask
                                   * vidHashAlg_present if present */
    VIDEncryptionAlgorithm vidEncAlg;
    IDNumber88_IssuerAndSerialNumber certID;
    _octet1         encryptedVID;
} EncryptedVID;

typedef AlgorithmIdentifier HashAlgorithm;

typedef struct VID {
    HashAlgorithm   hashAlg;
    _octet1         virtualID;
} VID;

typedef struct EncryptContent {
    VID             vid;
    _bit1           randomNum;
} EncryptContent;

typedef struct IdentifyData {
    unsigned char   bit_mask;
#       define      userInfo_present 0x80
    unsigned char   *realName;
    struct _seqof4_2 {
        struct _seqof4_2 *next;
        AttributeTypeAndValue value;
    } *userInfo;  /* optional; set in bit_mask userInfo_present if present */
} IdentifyData;

typedef int             SIVIDDummy1;

typedef struct RAOperatorCertificate {
    unsigned short  choice;
#       define      raOperCert_chosen 1
    union _union {
        Certificate     raOperCert;  /* to choose, set choice to
                                      * raOperCert_chosen */
    } u;
} RAOperatorCertificate;

typedef struct RandomChallenge {
    unsigned int    length;
    unsigned char   *value;
} RandomChallenge;

typedef struct GWConnReq {
    RAOperatorCertificate operCert;
    RandomChallenge randomChallenge;
} GWConnReq;

typedef struct GWConnRespData {
    int             status;
#       define      GWConnRespData_status_granted 0
#       define      GWConnRespData_status_badSignature 1
#       define      GWConnRespData_status_badCertificate 2
#       define      GWConnRespData_status_illegalOperator 3
    Certificate     certficate;
    RandomChallenge randomChallenge;
} GWConnRespData;

typedef struct GWConnResp_ {
    struct GWConnResp_ *next;
    GWConnRespData  value;
} *GWConnResp;

typedef struct GWEnvelopedData_ {
    struct GWEnvelopedData_ *next;
    EnvelopedData   value;
} *GWEnvelopedData;

typedef struct GWEncryptedData_ {
    struct GWEncryptedData_ *next;
    EncryptedData   value;
} *GWEncryptedData;

typedef int             GWDummy1;

typedef int             GWDummy2;

typedef struct Random_Integer {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} Random_Integer;

typedef struct ChannelId {
    unsigned int    length;
    unsigned char   *value;
} ChannelId;

typedef unsigned char   Options;
#define                     delegation_state 0x80
#define                     mutual_state 0x40
#define                     replay_det_state 0x20
#define                     sequence_state 0x10
#define                     conf_avail 0x08
#define                     integ_avail 0x04
#define                     target_certif_data_required 0x02

typedef struct Conf_Algs {
    unsigned short  choice;
#       define      algs_chosen 1
#       define      Conf_Algs_null_chosen 2
    union _union {
        struct _seqof3_4 {
            struct _seqof3_4 *next;
            AlgorithmIdentifier value;
        } *algs;  /* to choose, set choice to algs_chosen */
        Nulltype        null;  /* to choose, set choice to
                                * Conf_Algs_null_chosen */
    } u;
} Conf_Algs;

typedef struct Context_Data {
    unsigned char   bit_mask;
#       define      channelId_present 0x80
#       define      seq_number_present 0x40
    ChannelId       channelId;  /* optional; set in bit_mask channelId_present
                                 * if present */
    int             seq_number;  /* optional; set in bit_mask seq_number_present
                                  * if present */
    Options         options;
    Conf_Algs       conf_alg;
    struct Intg_Algs_ *intg_alg;
    struct OWF_Algs_ *owf_alg;
} Context_Data;

typedef struct Req_contents {
    unsigned char   bit_mask;
#       define      Req_contents_timestamp_present 0x80
#       define      Req_contents_src_name_present 0x40
#       define      Req_contents_validity_present 0x20
#       define      key_estb_req_present 0x10
#       define      key_src_bind_present 0x08
    unsigned short  tok_id;
    Random_Integer  context_id;
    _bit1_2         pvno;
    UTCTime         timestamp;  /* optional; set in bit_mask
                                 * Req_contents_timestamp_present if present */
    Random_Integer  randSrc;
    Name            targ_name;
    Name            src_name;  /* optional; set in bit_mask
                                * Req_contents_src_name_present if present */
    Context_Data    req_data;
    Validity        validity;  /* optional; set in bit_mask
                                * Req_contents_validity_present if present */
    struct Key_Estb_Algs_ *key_estb_set;
    _bit1_2         key_estb_req;  /* optional; set in bit_mask
                                    * key_estb_req_present if present */
    _octet1_2       key_src_bind;  /* optional; set in bit_mask
                                    * key_src_bind_present if present */
} Req_contents;

typedef struct Integrity {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} Integrity;

typedef struct REQ_TOKEN {
    Req_contents    req_contents;
    AlgorithmIdentifier algId;
    Integrity       req_integrity;
} REQ_TOKEN;

typedef struct SpkmGssTokens_CertificationPath {
    unsigned char   bit_mask;
#       define      userKeyId_present 0x80
#       define      userCertif_present 0x40
#       define      verifKeyId_present 0x20
#       define      userVerifCertif_present 0x10
#       define      SpkmGssTokens_CertificationPath_theCACertificates_present 0x08
    _octet1_2       userKeyId;  /* optional; set in bit_mask userKeyId_present
                                 * if present */
    Certificate     userCertif;  /* optional; set in bit_mask userCertif_present
                                  * if present */
    _octet1_2       verifKeyId;  /* optional; set in bit_mask verifKeyId_present
                                  * if present */
    Certificate     userVerifCertif;  /* optional; set in bit_mask
                                       * userVerifCertif_present if present */
    struct _seqof4_4 {
        struct _seqof4_4 *next;
        CertificatePair value;
    } *theCACertificates;  /* optional; set in bit_mask
                 * SpkmGssTokens_CertificationPath_theCACertificates_present if
                 * present */
} SpkmGssTokens_CertificationPath;

typedef struct CertificationData {
    unsigned char   bit_mask;
#       define      CertificationData_certificationPath_present 0x80
#       define      certificateRevocationList_present 0x40
    SpkmGssTokens_CertificationPath certificationPath;  /* optional; set in
                                   * bit_mask
                                   * CertificationData_certificationPath_present
                                   * if present */
    CertificateList certificateRevocationList;  /* optional; set in bit_mask
                                         * certificateRevocationList_present if
                                         * present */
} CertificationData;

typedef struct SPKM_REQ {
    unsigned char   bit_mask;
#       define      SPKM_REQ_certif_data_present 0x80
#       define      auth_data_present 0x40
    REQ_TOKEN       requestToken;
    CertificationData certif_data;  /* optional; set in bit_mask
                                     * SPKM_REQ_certif_data_present if
                                     * present */
    struct AuthorizationData_ *auth_data;  /* optional; set in bit_mask
                                            * auth_data_present if present */
} SPKM_REQ;

typedef struct Intg_Algs_ {
    struct Intg_Algs_ *next;
    AlgorithmIdentifier value;
} *Intg_Algs;

typedef struct OWF_Algs_ {
    struct OWF_Algs_ *next;
    AlgorithmIdentifier value;
} *OWF_Algs;

typedef struct Key_Estb_Algs_ {
    struct Key_Estb_Algs_ *next;
    AlgorithmIdentifier value;
} *Key_Estb_Algs;

typedef struct Rep_ti_contents {
    unsigned char   bit_mask;
#       define      pvno_present 0x80
#       define      Rep_ti_contents_timestamp_present 0x40
#       define      Rep_ti_contents_src_name_present 0x20
#       define      Rep_ti_contents_validity_present 0x10
#       define      key_estb_id_present 0x08
#       define      key_estb_str_present 0x04
    unsigned short  tok_id;
    Random_Integer  context_id;
    _bit1_2         pvno;  /* optional; set in bit_mask pvno_present if
                            * present */
    UTCTime         timestamp;  /* optional; set in bit_mask
                                 * Rep_ti_contents_timestamp_present if
                                 * present */
    Random_Integer  randTarg;
    Name            src_name;  /* optional; set in bit_mask
                                * Rep_ti_contents_src_name_present if present */
    Name            targ_name;
    Random_Integer  randSrc;
    Context_Data    rep_data;
    Validity        validity;  /* optional; set in bit_mask
                                * Rep_ti_contents_validity_present if present */
    AlgorithmIdentifier key_estb_id;  /* optional; set in bit_mask
                                       * key_estb_id_present if present */
    _bit1_2         key_estb_str;  /* optional; set in bit_mask
                                    * key_estb_str_present if present */
} Rep_ti_contents;

typedef struct REP_TI_TOKEN {
    Rep_ti_contents rep_ti_contents;
    AlgorithmIdentifier algId;
    Integrity       rep_ti_integ;
} REP_TI_TOKEN;

typedef struct SPKM_REP_TI {
    unsigned char   bit_mask;
#       define      SPKM_REP_TI_certif_data_present 0x80
    REP_TI_TOKEN    responseToken;
    CertificationData certif_data;  /* optional; set in bit_mask
                                     * SPKM_REP_TI_certif_data_present if
                                     * present */
} SPKM_REP_TI;

typedef struct REP_IT_TOKEN {
    unsigned char   bit_mask;
#       define      REP_IT_TOKEN_src_name_present 0x80
#       define      key_estb_rep_present 0x40
    unsigned short  tok_id;
    Random_Integer  context_id;
    Random_Integer  randSrc;
    Random_Integer  randTarg;
    Name            targ_name;
    Name            src_name;  /* optional; set in bit_mask
                                * REP_IT_TOKEN_src_name_present if present */
    _bit1_2         key_estb_rep;  /* optional; set in bit_mask
                                    * key_estb_rep_present if present */
} REP_IT_TOKEN;

typedef struct SPKM_REP_IT {
    REP_IT_TOKEN    responseToken;
    AlgorithmIdentifier algId;
    Integrity       rep_it_integ;
} SPKM_REP_IT;

typedef struct ERROR_TOKEN {
    unsigned short  tok_id;
    Random_Integer  context_id;
} ERROR_TOKEN;

typedef struct SPKM_ERROR {
    ERROR_TOKEN     errorToken;
    AlgorithmIdentifier algId;
    Integrity       integrity;
} SPKM_ERROR;

typedef struct SeqNum {
    int             num;
    ossBoolean      dir_ind;
} SeqNum;

typedef struct Mic_Header {
    unsigned char   bit_mask;
#       define      Mic_Header_int_alg_present 0x80
#       define      Mic_Header_snd_seq_present 0x40
    unsigned short  tok_id;
    Random_Integer  context_id;
    AlgorithmIdentifier int_alg;  /* optional; set in bit_mask
                                   * Mic_Header_int_alg_present if present */
    SeqNum          snd_seq;  /* optional; set in bit_mask
                               * Mic_Header_snd_seq_present if present */
} Mic_Header;

typedef struct SPKM_MIC {
    Mic_Header      mic_header;
    _bit1_2         int_cksum;
} SPKM_MIC;

typedef struct Conf_Alg {
    unsigned short  choice;
#       define      algId_chosen 1
#       define      Conf_Alg_null_chosen 2
    union _union {
        AlgorithmIdentifier algId;  /* to choose, set choice to algId_chosen */
        Nulltype        null;  /* to choose, set choice to
                                * Conf_Alg_null_chosen */
    } u;
} Conf_Alg;

typedef struct Wrap_Header {
    unsigned char   bit_mask;
#       define      Wrap_Header_int_alg_present 0x80
#       define      conf_alg_present 0x40
#       define      Wrap_Header_snd_seq_present 0x20
    unsigned short  tok_id;
    Random_Integer  context_id;
    AlgorithmIdentifier int_alg;  /* optional; set in bit_mask
                                   * Wrap_Header_int_alg_present if present */
    Conf_Alg        conf_alg;  /* optional; set in bit_mask conf_alg_present if
                                * present */
    SeqNum          snd_seq;  /* optional; set in bit_mask
                               * Wrap_Header_snd_seq_present if present */
} Wrap_Header;

typedef struct Wrap_Body {
    _bit1_2         int_cksum;
    _bit1_2         data;
} Wrap_Body;

typedef struct SPKM_WRAP {
    Wrap_Header     wrap_header;
    Wrap_Body       wrap_body;
} SPKM_WRAP;

typedef struct Del_Header {
    unsigned char   bit_mask;
#       define      Del_Header_int_alg_present 0x80
#       define      Del_Header_snd_seq_present 0x40
    unsigned short  tok_id;
    Random_Integer  context_id;
    AlgorithmIdentifier int_alg;  /* optional; set in bit_mask
                                   * Del_Header_int_alg_present if present */
    SeqNum          snd_seq;  /* optional; set in bit_mask
                               * Del_Header_snd_seq_present if present */
} Del_Header;

typedef struct SPKM_DEL {
    Del_Header      del_header;
    _bit1_2         int_cksum;
} SPKM_DEL;

typedef ObjectID        MechType;

typedef struct SPKMInnerContextToken {
    unsigned short  choice;
#       define      req_chosen 1
#       define      rep_ti_chosen 2
#       define      rep_it_chosen 3
#       define      SPKMInnerContextToken_error_chosen 4
#       define      mic_chosen 5
#       define      wrap_chosen 6
#       define      del_chosen 7
    union _union {
        SPKM_REQ        req;  /* to choose, set choice to req_chosen */
        SPKM_REP_TI     rep_ti;  /* to choose, set choice to rep_ti_chosen */
        SPKM_REP_IT     rep_it;  /* to choose, set choice to rep_it_chosen */
        SPKM_ERROR      error;  /* to choose, set choice to
                                 * SPKMInnerContextToken_error_chosen */
        SPKM_MIC        mic;  /* to choose, set choice to mic_chosen */
        SPKM_WRAP       wrap;  /* to choose, set choice to wrap_chosen */
        SPKM_DEL        del;  /* to choose, set choice to del_chosen */
    } u;
} SPKMInnerContextToken;

typedef struct InitialContextToken {
    MechType        thisMech;
    SPKMInnerContextToken innerContextToken;
} InitialContextToken;

typedef struct AuthorizationData_ {
    struct AuthorizationData_ *next;
    struct _seq1_2 {
        int             ad_type;
        _octet1_2       ad_data;
    } value;
} *AuthorizationData;

typedef struct DHParameter {
    unsigned char   bit_mask;
#       define      privateValueLength_present 0x80
    int             prime;
    int             base;
    int             privateValueLength;  /* optional; set in bit_mask
                                          * privateValueLength_present if
                                          * present */
} DHParameter;

typedef int             Int32;

typedef struct Bin {
    unsigned int    length;
    unsigned char   *value;
} Bin;

typedef struct SpkmKe {
    Bin             dhPG;
    Bin             dhPrivKey;
    Bin             dhPubKey;
    Bin             param;
    Int32           rint1;
    Bin             rbin1;
} SpkmKe;

typedef struct SpkmMy {
    unsigned char   bit_mask;
#       define      SpkmMy_cert_present 0x80
#       define      SpkmMy_certV_present 0x40
#       define      SpkmMy_cacert_present 0x20
#       define      SpkmMy_crl_present 0x10
    Int32           mech;
    Int32           pvno;
    Int32           options;
    Int32           validity;
    Name            name;
    Int32           algSet;
    Int32           algConf;
    Int32           algIntg;
    Int32           algOWF;
    Int32           algKE;
    Int32           seqNo;
    Bin             dhPG;
    Bin             dhPrivKey;
    Bin             dhPubKey;
    Bin             privKey;
    Bin             pubKey;
    Certificate     cert;  /* optional; set in bit_mask SpkmMy_cert_present if
                            * present */
    Bin             certId;
    Bin             privKeyS;
    Bin             pubKeyV;
    Certificate     certV;  /* optional; set in bit_mask SpkmMy_certV_present if
                             * present */
    Bin             certVId;
    Certificate     cacert;  /* optional; set in bit_mask SpkmMy_cacert_present
                              * if present */
    CertificateList crl;  /* optional; set in bit_mask SpkmMy_crl_present if
                           * present */
    Int32           rint1;
    Int32           rint2;
    Bin             rbin1;
    Bin             rbin2;
} SpkmMy;

typedef struct SpkmPeer {
    unsigned char   bit_mask;
#       define      SpkmPeer_cert_present 0x80
#       define      SpkmPeer_certV_present 0x40
#       define      SpkmPeer_cacert_present 0x20
#       define      SpkmPeer_crl_present 0x10
    Int32           options;
    Int32           timeStamp;
    Bin             channelId;
    Int32           algSet;
    Int32           seqNo;
    Certificate     cert;  /* optional; set in bit_mask SpkmPeer_cert_present if
                            * present */
    Bin             certId;
    Bin             pubKey;
    Certificate     certV;  /* optional; set in bit_mask SpkmPeer_certV_present
                             * if present */
    Bin             certVId;
    Bin             pubKeyV;
    Certificate     cacert;  /* optional; set in bit_mask
                              * SpkmPeer_cacert_present if present */
    CertificateList crl;  /* optional; set in bit_mask SpkmPeer_crl_present if
                           * present */
    Int32           rint1;
    Int32           rint2;
    Bin             rbin1;
    Bin             rbin2;
} SpkmPeer;

typedef struct SpkmCtx {
    unsigned char   bit_mask;
#       define      targName_present 0x80
    Int32           role;
    Int32           mech;
    Options         options;
    Bin             channelId;
    Name            srcName;
    Name            targName;  /* optional; set in bit_mask targName_present if
                                * present */
    Int32           tokId;
    Bin             contextId;
    Bin             sessKeyI;
    Bin             sessKeyC;
    Bin             randSrc;
    Bin             randTarg;
    Int32           validT1;
    Int32           validT2;
    Int32           algSetUse;
    Int32           algConf;
    Int32           algIntg;
    Int32           algOWF;
    Int32           algKE;
    SpkmKe          ke;
    SpkmMy          my;
    SpkmPeer        peer;
    Int32           rint1;
    Int32           rint2;
    Bin             rbin1;
    Bin             rbin2;
} SpkmCtx;

typedef struct MessageImprint {
    AlgorithmIdentifier hashAlgorithm;
    _octet1         hashedMessage;
} MessageImprint;

typedef ObjectID        TSAPolicyId;

typedef struct TimeStampReq {
    unsigned char   bit_mask;
#       define      reqPolicy_present 0x80
#       define      TimeStampReq_nonce_present 0x40
#       define      certReq_present 0x20
#       define      TimeStampReq_extensions_present 0x10
    int             version;
#       define      TimeStampReq_version_v1 1
    MessageImprint  messageImprint;
    TSAPolicyId     reqPolicy;  /* optional; set in bit_mask reqPolicy_present
                                 * if present */
    int             nonce;  /* optional; set in bit_mask
                             * TimeStampReq_nonce_present if present */
    ossBoolean      certReq;  /* certReq_present not set in bit_mask implies
                               * value is FALSE */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * TimeStampReq_extensions_present if
                                      * present */
} TimeStampReq;

typedef ContentInfo     TimeStampToken;

typedef struct TimeStampResp {
    unsigned char   bit_mask;
#       define      timeStampToken_present 0x80
    PKIStatusInfo   status;
    TimeStampToken  timeStampToken;  /* optional; set in bit_mask
                                      * timeStampToken_present if present */
} TimeStampResp;

typedef struct Accuracy {
    unsigned char   bit_mask;
#       define      seconds_present 0x80
#       define      millis_present 0x40
#       define      micros_present 0x20
    int             seconds;  /* optional; set in bit_mask seconds_present if
                               * present */
    unsigned short  millis;  /* optional; set in bit_mask millis_present if
                              * present */
    unsigned short  micros;  /* optional; set in bit_mask micros_present if
                              * present */
} Accuracy;

typedef struct TSTInfo {
    unsigned char   bit_mask;
#       define      accuracy_present 0x80
#       define      ordering_present 0x40
#       define      TSTInfo_nonce_present 0x20
#       define      tsa_present 0x10
#       define      TSTInfo_extensions_present 0x08
    int             version;
#       define      TSTInfo_version_v1 1
    TSAPolicyId     policy;
    MessageImprint  messageImprint;
    _struct1        serialNumber;
    GeneralizedTime genTime;
    Accuracy        accuracy;  /* optional; set in bit_mask accuracy_present if
                                * present */
    ossBoolean      ordering;  /* ordering_present not set in bit_mask implies
                                * value is FALSE */
    int             nonce;  /* optional; set in bit_mask TSTInfo_nonce_present
                             * if present */
    GeneralName     tsa;  /* optional; set in bit_mask tsa_present if present */
    struct Extensions_ *extensions;  /* optional; set in bit_mask
                                      * TSTInfo_extensions_present if present */
} TSTInfo;

typedef Nulltype        PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_1;

typedef Nulltype        PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_2;

typedef Nulltype        PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_3;

typedef Nulltype        PKCS1_V21_OAEP_PSSDigestAlgorithms_PARAMETERS_4;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_1;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_2;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_3;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_4;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_5;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_6;

typedef Nulltype        PKCS1_V21_PKCS1Algorithms_PARAMETERS_7;

#ifndef _OSSNOVALUES

extern ObjectID id_pe_ac_auditIdentity;

extern ObjectID id_pe_aaControls;

extern ObjectID id_pe_ac_proxying;

extern ObjectID id_ce_targetInformation;

extern ObjectID id_aca;

extern ObjectID id_aca_authenticationInfo;

extern ObjectID id_aca_accessIdentity;

extern ObjectID id_aca_chargingIdentity;

extern ObjectID id_aca_group;

extern ObjectID id_aca_encAttrs;

extern ObjectID id_at_role;

extern ObjectID id_at_clearance;

extern ObjectID id_kiec_arcCertRequest;

extern ObjectID id_kiec_HashedIDNInfo;

extern ObjectID id_kiec_qualifications;

extern ObjectID id_kiec_usageType;

extern ObjectID id_kiec_dateOfExpiration;

extern ObjectID id_kiec_certifiedTime;

extern ObjectID id_kiec_arcCertReseponse;

extern ObjectID id_passwordBasedMac;

extern ObjectID id_DHBasedMac;

extern ObjectID id_it;

extern ObjectID id_CAProtEncCert;

extern ObjectID id_SignKeyPairTypes;

extern ObjectID id_EncKeyPairTypes;

extern ObjectID id_PreferredSymmAlg;

extern ObjectID id_CAKeyUpdateInfo;

extern ObjectID id_CurrentCRL;

extern ObjectID dh_public_number;

extern ObjectID id_alg_ESDH;

extern ObjectID id_alg_CMS3DESwrap;

extern ObjectID id_alg_CMSRC2wrap;

extern ObjectID des_ecb;

extern ObjectID des_cbc;

extern ObjectID des_ofb;

extern ObjectID des_cfb;

extern ObjectID des_ede3_cbc;

extern ObjectID rc2_cbc;

extern ObjectID hMAC_SHA1;

extern ObjectID id_ct_contentInfo;

extern ObjectID id_data;

extern ObjectID id_signedData;

extern ObjectID id_envelopedData;

extern ObjectID id_signedAndEnvelopedData;

extern ObjectID id_digestedData;

extern ObjectID id_encryptedData;

extern ObjectID id_ct_authData;

extern ObjectID id_contentType;

extern ObjectID id_messageDigest;

extern ObjectID id_signingTime;

extern ObjectID id_countersignature;

extern ObjectID id_aa_timeStampToken;

extern ObjectID id_pkip;

extern ObjectID id_regCtrl;

extern ObjectID id_regCtrl_regToken;

extern ObjectID id_regCtrl_authenticator;

extern ObjectID id_regCtrl_pkiPublicationInfo;

extern ObjectID id_regCtrl_pkiArchiveOptions;

extern ObjectID id_regCtrl_oldCertID;

extern ObjectID id_regCtrl_protocolEncrKey;

extern ObjectID id_regInfo;

extern ObjectID id_regInfo_utf8Pairs;

extern ObjectID id_regInfo_certReq;

extern ObjectID electronic_civil_application;

extern ObjectID pkiCTL;

extern ObjectID certificateTrustList;

extern ObjectID cTL;

extern ObjectID id_dh_sig_hmac_sha1;

extern ObjectID id_alg_dh_pop;

extern ObjectID id_ad_dvcs;

extern ObjectID id_kp_dvcs;

extern ObjectID id_ct_DVCSRequestData;

extern ObjectID id_ct_DVCSResponseData;

extern ObjectID id_aa_dvcs_dvc;

extern ObjectID id_aa_signatureTimeStampToken;

extern ObjectID id_aa_ets_otherSigCert;

extern ObjectID id_aa_ets_certificateRefs;

extern ObjectID id_aa_ets_revocationRefs;

extern const int ub_receiptsTo;

extern ObjectID id_aa_receiptRequest;

extern ObjectID id_aa_contentIdentifier;

extern ObjectID id_ct_receipt;

extern ObjectID id_aa_contentHint;

extern ObjectID id_aa_msgSigDigest;

extern ObjectID id_aa_contentReference;

extern ObjectID id_aa_securityLabel;

extern const int ExtendedSecurityServices_ub_integer_options;

extern const int ub_privacy_mark_length;

extern const int ub_security_categories;

extern ObjectID id_aa_equivalentLabels;

extern ObjectID id_aa_mlExpandHistory;

extern const int ub_ml_expansion_history;

extern ObjectID id_aa_signingCertificate;

extern ObjectID id_kisa_HSM;

extern ObjectID id_kp_OCSPSigning;

extern ObjectID id_pkix_ocsp;

extern ObjectID id_pkix_ocsp_basic;

extern ObjectID id_pkix_ocsp_nonce;

extern ObjectID id_pkix_ocsp_crl;

extern ObjectID id_pkix_ocsp_response;

extern ObjectID id_pkix_ocsp_nocheck;

extern ObjectID id_pkix_ocsp_archive_cutoff;

extern ObjectID id_pkix_ocsp_service_locator;

extern ObjectID id_RSAES_OAEP;

extern ObjectID id_mgf1;

extern ObjectID id_pSpecified;

extern ObjectID id_RSASSA_PSS;

extern ObjectID sha_1;

extern ObjectID md5;

extern ObjectID sha_256;

extern ObjectID sha_384;

extern ObjectID sha_512;

extern PKCS1_V21_HashAlgorithm sha1;

extern MaskGenAlgorithm mgf1SHA1;

extern PSourceAlgorithm pSpecifiedEmpty;

extern EncodingParameters emptyString;

extern RSAES_AlgorithmIdentifier rSAES_OAEP_Defult_Identifier;

extern RSASSA_AlgorithmIdentifier rSASSA_PSS_Default_Identifier;

extern ObjectID sha256WithRSAEncryption;

extern ObjectID sha384WithRSAEncryption;

extern ObjectID sha512WithRSAEncryption;

extern ObjectID PKCS5v2_0_rsadsi;

extern ObjectID PKCS5v2_0_pkcs;

extern ObjectID pkcs_5;

extern ObjectID id_PBKDF2;

extern ObjectID pbeWithMD2AndDES_CBC;

extern ObjectID pbeWithMD2AndRC2_CBC;

extern ObjectID pbeWithMD5AndDES_CBC;

extern ObjectID pbeWithMD5AndRC2_CBC;

extern ObjectID pbeWithSHA1AndDES_CBC;

extern ObjectID pbeWithSHA1AndRC2_CBC;

extern ObjectID id_PBES2;

extern ObjectID id_PBMAC1;

extern ObjectID digestAlgorithm;

extern ObjectID encryptionAlgorithm;

extern ObjectID id_hmacWithSHA1;

extern ObjectID desCBC;

extern ObjectID des_EDE3_CBC;

extern ObjectID rc2CBC;

extern ObjectID rc5_CBC_PAD;

extern const int pkcs_9_ub_pkcs9String;

extern const int pkcs_9_ub_emailAddress;

extern const int pkcs_9_ub_unstructuredName;

extern const int pkcs_9_ub_unstructuredAddress;

extern const int pkcs_9_ub_challengePassword;

extern const int pkcs_9_ub_friendlyName;

extern const int pkcs_9_ub_signingDescription;

extern const int pkcs_9_ub_match;

extern ObjectID pkcs_9;

extern ObjectID pkcs_9_mo;

extern ObjectID pkcs_9_oc;

extern ObjectID pkcs_9_at;

extern ObjectID pkcs_9_sx;

extern ObjectID pkcs_9_mr;

extern ObjectID pkcs_9_oc_pkcsEntity;

extern ObjectID pkcs_9_oc_naturalPerson;

extern ObjectID pkcs_9_at_emailAddress;

extern ObjectID emailAddress;

extern ObjectID pkcs_9_at_unstructuredName;

extern ObjectID pkcs_9_at_contentType;

extern ObjectID pkcs_9_at_messageDigest;

extern ObjectID pkcs_9_at_signingTime;

extern ObjectID pkcs_9_at_counterSignature;

extern ObjectID pkcs_9_at_challengePassword;

extern ObjectID pkcs_9_at_unstructuredAddress;

extern ObjectID pkcs_9_at_extendedCertificateAttributes;

extern ObjectID pkcs_9_at_signingDescription;

extern ObjectID pkcs_9_at_extensionRequest;

extern ObjectID pkcs_9_at_smimeCapabilities;

extern ObjectID pkcs_9_at_friendlyName;

extern ObjectID pkcs_9_at_localKeyId;

extern ObjectID pkcs_9_at_userPKCS12;

extern ObjectID pkcs_9_at_pkcs15Token;

extern ObjectID pkcs_9_at_encryptedPrivateKeyInfo;

extern ObjectID pkcs_9_at_randomNonce;

extern ObjectID pkcs_9_at_sequenceNumber;

extern ObjectID pkcs_9_at_pkcs7PDU;

extern ObjectID ietf_at;

extern ObjectID pkcs_9_at_dateOfBirth;

extern ObjectID pkcs_9_at_placeOfBirth;

extern ObjectID pkcs_9_at_gender;

extern ObjectID pkcs_9_at_countryOfCitizenship;

extern ObjectID pkcs_9_at_countryOfResidence;

extern ObjectID pkcs_9_sx_pkcs9String;

extern ObjectID pkcs_9_sx_signingTime;

extern ObjectID pkcs_9_mr_caseIgnoreMatch;

extern ObjectID pkcs_9_mr_signingTimeMatch;

extern ObjectID smime;

extern ObjectID certTypes;

extern ObjectID crlTypes;

extern ObjectID PKCS_12_rsadsi;

extern ObjectID PKCS_12_pkcs;

extern ObjectID pkcs_12;

extern ObjectID pkcs_12PbeIds;

extern ObjectID pbeWithSHAAnd128BitRC4;

extern ObjectID pbeWithSHAAnd40BitRC4;

extern ObjectID pbeWithSHAAnd3_KeyTripleDES_CBC;

extern ObjectID pbeWithSHAAnd2_KeyTripleDES_CBC;

extern ObjectID pbeWithSHAAnd128BitRC2_CBC;

extern ObjectID pbewithSHAAnd40BitRC2_CBC;

extern ObjectID bagtypes;

extern BAG_TYPE keyBag;

extern BAG_TYPE pkcs8ShroudedKeyBag;

extern BAG_TYPE certBag;

extern BAG_TYPE crlBag;

extern BAG_TYPE secretBag;

extern BAG_TYPE safeContentsBag;

extern BAG_TYPE x509Certificate;

extern BAG_TYPE sdsiCertificate;

extern BAG_TYPE x509CRL;

extern ObjectID id_pkix;

extern ObjectID id_pe;

extern ObjectID id_qt;

extern ObjectID id_kp;

extern ObjectID id_ad;

extern ObjectID id_qt_cps;

extern ObjectID id_qt_unotice;

extern ObjectID id_ad_ocsp;

extern ObjectID id_ad_caIssuers;

extern ObjectID id_at;

extern AttributeType id_at_name;

extern AttributeType id_at_surname;

extern AttributeType id_at_givenName;

extern AttributeType id_at_initials;

extern AttributeType id_at_generationQualifier;

extern AttributeType id_at_commonName;

extern AttributeType id_at_localityName;

extern AttributeType id_at_stateOrProvinceName;

extern AttributeType id_at_organizationName;

extern AttributeType id_at_organizationalUnitName;

extern AttributeType id_at_title;

extern AttributeType id_at_dnQualifier;

extern AttributeType id_at_countryName;

extern ObjectID pkcs_1;

extern ObjectID rsaEncryption;

extern ObjectID md2;

extern ObjectID md2WithRSAEncryption;

extern ObjectID md5WithRSAEncryption;

extern ObjectID sha1WithRSAEncryption;

extern ObjectID id_dsa_with_sha1;

extern ObjectID dhpublicnumber;

extern ObjectID id_dsa;

extern const int common_name;

extern const int teletex_common_name;

extern const int teletex_organization_name;

extern const int teletex_personal_name;

extern const int teletex_organizational_unit_names;

extern const int pds_name;

extern const int physical_delivery_country_name;

extern const int postal_code;

extern const int physical_delivery_office_name;

extern const int physical_delivery_office_number;

extern const int extension_OR_address_components;

extern const int physical_delivery_personal_name;

extern const int physical_delivery_organization_name;

extern const int extension_physical_delivery_address_components;

extern const int unformatted_postal_address;

extern const int street_address;

extern const int post_office_box_address;

extern const int poste_restante_address;

extern const int unique_postal_name;

extern const int local_postal_attributes;

extern const int extended_network_address;

extern const int terminal_type;

extern const int teletex_domain_defined_attributes;

extern const int ub_name;

extern const int ub_common_name;

extern const int ub_locality_name;

extern const int ub_state_name;

extern const int ub_organization_name;

extern const int ub_organizational_unit_name;

extern const int ub_title;

extern const int ub_match;

extern const int ub_emailaddress_length;

extern const int ub_common_name_length;

extern const int ub_country_name_alpha_length;

extern const int ub_country_name_numeric_length;

extern const int ub_domain_defined_attributes;

extern const int ub_domain_defined_attribute_type_length;

extern const int ub_domain_defined_attribute_value_length;

extern const int ub_domain_name_length;

extern const int ub_extension_attributes;

extern const int ub_e163_4_number_length;

extern const int ub_e163_4_sub_address_length;

extern const int ub_generation_qualifier_length;

extern const int ub_given_name_length;

extern const int ub_initials_length;

extern const int PKIX1Explicit88_ub_integer_options;

extern const int ub_numeric_user_id_length;

extern const int ub_organization_name_length;

extern const int ub_organizational_unit_name_length;

extern const int ub_organizational_units;

extern const int ub_pds_name_length;

extern const int ub_pds_parameter_length;

extern const int ub_pds_physical_address_lines;

extern const int ub_postal_code_length;

extern const int ub_surname_length;

extern const int ub_terminal_id_length;

extern const int ub_unformatted_address_length;

extern const int ub_x121_address_length;

extern ObjectID id_ce;

extern ObjectID id_ce_authorityKeyIdentifier;

extern ObjectID id_ce_subjectKeyIdentifier;

extern ObjectID id_ce_keyUsage;

extern ObjectID id_ce_privateKeyUsagePeriod;

extern ObjectID id_ce_certificatePolicies;

extern ObjectID id_ce_policyMappings;

extern ObjectID id_ce_subjectAltName;

extern ObjectID id_ce_issuerAltName;

extern ObjectID id_ce_subjectDirectoryAttributes;

extern ObjectID id_ce_basicConstraints;

extern ObjectID id_ce_nameConstraints;

extern ObjectID id_ce_policyConstraints;

extern ObjectID id_ce_cRLDistributionPoints;

extern ObjectID id_ce_extKeyUsage;

extern ObjectID id_kp_serverAuth;

extern ObjectID id_kp_clientAuth;

extern ObjectID id_kp_codeSigning;

extern ObjectID id_kp_emailProtection;

extern ObjectID id_kp_ipsecEndSystem;

extern ObjectID id_kp_ipsecTunnel;

extern ObjectID id_kp_ipsecUser;

extern ObjectID id_kp_timeStamping;

extern ObjectID id_pe_authorityInfoAccess;

extern ObjectID id_ce_cRLNumber;

extern ObjectID id_ce_issuingDistributionPoint;

extern ObjectID id_ce_deltaCRLIndicator;

extern ObjectID id_ce_cRLReasons;

extern ObjectID id_ce_certificateIssuer;

extern ObjectID id_ce_holdInstructionCode;

extern ObjectID holdInstruction;

extern ObjectID id_holdinstruction_none;

extern ObjectID id_holdinstruction_callissuer;

extern ObjectID id_holdinstruction_reject;

extern ObjectID id_ce_invalidityDate;

extern ObjectID netscape;

extern ObjectID netscape_cert_extension;

extern ObjectID netscape_cert_type;

extern ObjectID netscape_base_url;

extern ObjectID netscape_revocation_url;

extern ObjectID netscape_ca_revocation_url;

extern ObjectID netscape_cert_renewal_url;

extern ObjectID netscape_ca_policy_url;

extern ObjectID netscape_ssl_server_name;

extern ObjectID netscape_comment;

extern ObjectID id_KISA;

extern ObjectID id_npki;

extern ObjectID id_attribute;

extern ObjectID id_kisa_identifyData;

extern ObjectID id_VID;

extern ObjectID id_EncryptedVID;

extern ObjectID id_randomNum;

extern ObjectID id_korea;

extern ObjectID id_gcma;

extern ObjectID id_gcma_gpki_alg;

extern ObjectID neat;

extern ObjectID neatECB;

extern ObjectID neatCBC;

extern ObjectID neatOFB;

extern ObjectID neatCFB;

extern ObjectID neatMAC;

extern ObjectID pbeWithSHA1AndNEAT_CBC;

extern ObjectID pbeWithHAS160AndNEAT_CBC;

extern ObjectID aria;

extern ObjectID ariaECB;

extern ObjectID ariaCBC;

extern ObjectID ariaOFB;

extern ObjectID ariaCFB;

extern ObjectID ariaMAC;

extern ObjectID pbewithSHA1andARIA_CBC;

extern ObjectID pbewithSHA256andARIA_CBC;

extern ObjectID pbewithHAS160andARIA_CBC;

extern ObjectID id_softforum;

extern ObjectID id_miso_pkix;

extern ObjectID id_miso_algorithm;

extern ObjectID id_miso_usage;

extern ObjectID id_miso_policy;

extern ObjectID id_arc_record;

extern ObjectID id_arc_arccert;

extern ObjectID id_arc_register_pol;

extern ObjectID id_arc_issue_pol;

extern ObjectID id_arc_transfer_pol;

extern ObjectID id_arc_delete_pol;

extern ObjectID id_arc_original_pol;

extern ObjectID id_miso_tsa_pol;

extern ObjectID id_miso_ca_pol;

extern ObjectID id_nsforum;

extern ObjectID id_kisa;

extern ObjectID id_kisa_npki_alg;

extern ObjectID id_kisa_npki_cp;

extern ObjectID id_kisa_npki_kp;

extern ObjectID id_kisa_npki_at;

extern ObjectID id_kisa_npki_lca;

extern ObjectID id_kisa_npki_on;

extern ObjectID kcdsa;

extern ObjectID hash160;

extern ObjectID seedECB;

extern ObjectID seedCBC;

extern ObjectID seedOFB;

extern ObjectID seedCFB;

extern ObjectID seedMAC;

extern ObjectID kcdsaWithHAS160;

extern ObjectID kcdsaWithSHA1;

extern ObjectID seedECBWithHAS160;

extern ObjectID seedCBCWithHAS160;

extern ObjectID seedOFBWithHAS160;

extern ObjectID seedCFBWithHAS160;

extern ObjectID seedECBWithSHA1;

extern ObjectID seedCBCWithSHA1;

extern ObjectID seedOFBWithSHA1;

extern ObjectID seedCFBWithSHA1;

extern ObjectID rsaWithHAS160;

extern ObjectID kcdsa1;

extern ObjectID kcdsa1WithHAS160;

extern ObjectID kcdsa1WithSHA1;

extern ObjectID ecdsaWithHAS160;

extern ObjectID kcdsaWithSHA256;

extern ObjectID kcdsa1WithSHA256;

extern ObjectID ecc;

extern ObjectID npki_cp_sign;

extern ObjectID signkorea;

extern ObjectID signkorea_cp;

extern ObjectID signGATE;

extern ObjectID signGATE_CP;

extern ObjectID id_kftc;

extern ObjectID yessignCA;

extern ObjectID yessign_CP;

extern ObjectID personal_certificates;

extern ObjectID corporation_certificates;

extern ObjectID server_certificates;

extern ObjectID id_registeredNumber;

extern ObjectID id_representativeName;

extern ObjectID id_representativeTitle;

extern ObjectID md5_DES_CBC;

extern ObjectID sum64_DES_CBC;

extern ObjectID spkm_1;

extern ObjectID spkm_2;

extern ObjectID pkcs_3;

extern ObjectID id_dhKeyAgreement;

extern ObjectID des_mac;

extern ObjectID id_rsa_key_transport;

extern ObjectID sha;

extern ObjectID id_ct_TSTInfo;

#endif  /* #ifndef _OSSNOVALUES */


extern void *suite_pkix_asn1;    /* encoder-decoder control table */
#ifdef __cplusplus
}	/* extern "C" */
#endif /* __cplusplus */
#endif /* OSS_suite_pkix_asn1 */
