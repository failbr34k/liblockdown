/*
 
liblockdown.h ... Header for liblockdown.

Copyright (c) 2009  KennyTM~ <kennytm@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the KennyTM~ nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef LIBLOCKDOWN_H
#define LIBLOCKDOWN_H

#if __cplusplus
extern "C" {
#endif
    
#include <CoreFoundation/CoreFoundation.h>
#include <Security/Security.h>
//#include <Availability2.h>
    
#pragma mark -
#pragma mark Error messages
extern CFStringRef _Nonnull kLDErrorCheckinTimeout;
extern CFStringRef _Nonnull kLDErrorGetProhibited;
extern CFStringRef _Nonnull kLDErrorImmutableValue;
extern CFStringRef _Nonnull kLDErrorInvalidActivationRecord;
extern CFStringRef _Nonnull kLDErrorInvalidCheckin;
extern CFStringRef _Nonnull kLDErrorInvalidHostID;
extern CFStringRef _Nonnull kLDErrorInvalidPairRecord;
extern CFStringRef _Nonnull kLDErrorInvalidResponse;
extern CFStringRef _Nonnull kLDErrorInvalidService;
extern CFStringRef _Nonnull kLDErrorInvalidSessionID;
extern CFStringRef _Nonnull kLDErrorMissingActivationRecord;
extern CFStringRef _Nonnull kLDErrorMissingHostID;
extern CFStringRef _Nonnull kLDErrorMissingKey;
    extern CFStringRef _Nonnull kLDErrorMissingPairRecord;
extern CFStringRef _Nonnull kLDErrorMissingService;
    extern CFStringRef _Nonnull kLDErrorMissingSessionID;
extern CFStringRef _Nonnull kLDErrorMissingValue;
    extern CFStringRef _Nonnull kLDErrorPasswordProtected;
    extern CFStringRef _Nonnull kLDErrorRemoveProhibited;
    extern CFStringRef _Nonnull kLDErrorServiceLimit;
    extern CFStringRef _Nonnull kLDErrorServiceProhibited;
extern CFStringRef _Nonnull kLDErrorSessionActive;
    extern CFStringRef _Nonnull kLDErrorSessionInactive;
    extern CFStringRef _Nonnull kLDErrorSetProhibited;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
    extern CFStringRef _Nonnull kLDErrorCheckinConnectionFailed;
    extern CFStringRef _Nonnull kLDErrorCheckinOutOfMemory;
extern CFStringRef _Nonnull kLDErrorCheckinReceiveFailed;
extern CFStringRef _Nonnull kLDErrorCheckinResponseFailed;
extern CFStringRef _Nonnull kLDErrorCheckinSendFailed;
extern CFStringRef _Nonnull kLDErrorCheckinSetupFailed;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
extern CFStringRef _Nonnull kLDErrorSavePairRecordFailed;
#elif __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLLDErrorSavePairRecordFailed;
#endif
    
#pragma mark -
#pragma mark Notifications
extern CFStringRef _Nonnull kLockdownNotificationActivationStateChanged;
    extern CFStringRef _Nonnull kLockdownNotificationBrickStateChanged;
    extern CFStringRef _Nonnull kLockdownNotificationDataSyncDomainChanged;
    extern CFStringRef _Nonnull kLockdownNotificationDeveloperImageMounted;
    extern CFStringRef _Nonnull kLockdownNotificationDeviceNameChanged;
    extern CFStringRef _Nonnull kLockdownNotificationHostAttached;
    extern CFStringRef _Nonnull kLockdownNotificationHostDetached;
    extern CFStringRef _Nonnull kLockdownNotificationPhoneNumberChanged;
    extern CFStringRef _Nonnull kLockdownNotificationRegistrationFailed;
    extern CFStringRef _Nonnull kLockdownNotificationTrustedHostAttached;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownNotificationApplicationInstalled;
extern CFStringRef _Nonnull kLockdownNotificationApplicationUninstalled;
    extern CFStringRef _Nonnull kLockdownNotificationThirdPartyApplicationQuit;
    extern CFStringRef _Nonnull kLockdownNotificationTimezoneChanged;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownNotificationBackupDomainChanged;
extern CFStringRef _Nonnull kLockdownNotificationIQAgentAllowedChanged;
    extern CFStringRef _Nonnull kLockdownNotificationiTunesAccountChanged;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
extern CFStringRef _Nonnull kLockdownNotificationPowerChange;
    extern CFStringRef _Nonnull kLockdownNotificationSBLockChange;
extern CFStringRef _Nonnull kLockdownNotificationSyncAllowChanged;
#endif
    
#pragma mark -
#pragma mark Domains
extern CFStringRef _Nonnull kLockdownWirelessLockdownDomainKey;    // ???
extern CFStringRef _Nonnull kLockdownMobileiPodDomainKey;          //???
extern CFStringRef _Nonnull kLockdownMobileSystemServicesDomainKey;// ???
extern CFStringRef _Nonnull kLockdownDemoDomainKey;                // ???
extern CFStringRef _Nonnull kLockdownFMiPDomain;                   //  ??
extern CFStringRef _Nonnull kLockdownPurpleBuddyDomainKey;         // com.apple.PurpleBuddy
extern CFStringRef _Nonnull kLockdownDiskUsageDomainKey;           // com.apple.disk_usage
extern CFStringRef _Nonnull kLockdownCheckpointDomainKey;          // com.apple.mobile.iTunes
extern CFStringRef _Nonnull kLockdownDataSyncDomainKey;            // com.apple.data_sync
extern CFStringRef _Nonnull kLockdownDebugDomainKey;               // com.apple.mobile.debug
static CFStringRef _Nonnull kLockdownFairPlayDomainKey = CFSTR("com.apple.fairplay");     
extern CFStringRef _Nonnull kLockdownInternalDomainKey;            // com.apple.mobile.internal
extern CFStringRef _Nonnull kLockdownInternationalDomainKey;       // com.apple.international
extern CFStringRef _Nonnull kLockdownRestrictionDomainKey;         // com.apple.mobile.restriction
extern CFStringRef _Nonnull kLockdownSoftwareBehaviorDomainKey;    // com.apple.mobile.software_behavior
extern CFStringRef _Nonnull kLockdownStoreDomainKey;               // com.apple.mobile.iTunes.store
extern CFStringRef _Nonnull kLockdownSyncDataClassDomainKey;       // com.apple.mobile.sync_data_class
extern CFStringRef _Nonnull kLockownSQLMusicLibraryPostProcessCommandsDomainKey;    // com.apple.mobile.iTunes.SQLMusicLibraryPostProcessCommands
static const CFStringRef _Nonnull kLockdowniTunesDomainKey = CFSTR("com.apple.iTunes");
static const CFStringRef _Nonnull kLockdowniTunesStoredDomainKey = CFSTR("com.apple.itunesstored");
extern CFStringRef _Nonnull kLockdownXcodeDomainKey;               // com.apple.xcode ????
static const CFStringRef _Nonnull kLockdownXcodeDeveloperDomainKey = CFSTR("com.apple.xcode.developerdomain");
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownUserPreferencesDomainKey;    // com.apple.mobile.user_preferences
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
    extern CFStringRef _Nonnull kLockdownProtocolVersion;    // "2"
    extern CFStringRef _Nonnull kLockdownPrefApplicationID;    // com.apple.mobile.lockdownd
    extern CFStringRef _Nonnull kLockdownMobileApplicationUsageMapDomain;    // com.apple.mobile.mobile_application_usage
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0
    extern CFStringRef _Nonnull kLockdownThirdPartyTerminationMapDomain;    // com.apple.mobile.third_party_termination
#else
    extern CFStringRef _Nonnull kLockdownHostPairingsDomainKey;
#endif
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownBackupDomainKey;    // com.apple.mobile.backup
    extern CFStringRef _Nonnull kLockdownIQAgentApplicationID;    // com.apple.iqagent
#endif
    
#pragma mark -
#pragma mark : (nil-Domain Keys)
    extern CFStringRef _Nullable kLockdownSysCfgDataKey;
    extern CFStringRef _Nullable kLockdownActivationInfoKey;
    extern CFStringRef _Nullable kLockdownActivationRandomnessKey;
    extern CFStringRef _Nullable kLockdownActivationStateKey;
    extern CFStringRef _Nullable kLockdownBuildVersionKey;
    extern CFStringRef _Nullable kLockdownBoardIdKey;
    extern CFStringRef _Nullable kLockdownBrickStateKey;
    extern CFStringRef _Nullable kLockdownChipIDKey;
    extern CFStringRef _Nullable kLockdownDeviceCertificateKey;
    extern CFStringRef _Nullable kLockdownDeviceClassKey;
    extern CFStringRef _Nullable kLockdownDeviceNameKey;
    extern CFStringRef _Nullable kLockdownDevicePrivateKey;
    extern CFStringRef _Nullable kLockdownDevicePublicKey;
    extern CFStringRef _Nullable kLockdownFirmwareVersionKey;
    extern CFStringRef _Nullable kLockdownHostAttachedKey;
    extern CFStringRef _Nullable kLockdownInverseDeviceIDKey;
    extern CFStringRef _Nullable kLockdownModelNumberKey;
    extern CFStringRef _Nullable kLockdownPasswordProtectedKey;
    extern CFStringRef _Nullable kLockdownProductTypeKey;
    extern CFStringRef _Nullable kLockdownProductVersionKey;
    extern CFStringRef _Nullable kLockdownProtocolVersionKey;
    extern CFStringRef _Nullable kLockdownRegionInfoKey;
    extern CFStringRef _Nullable kLockdownSIMGID1Key;    // ?
    extern CFStringRef _Nullable kLockdownSIMGID2Key;    // ?
    extern CFStringRef _Nonnull kLockdownSIMStatusKey;
    extern CFStringRef _Nonnull kLockdownSerialNumberKey;
    extern CFStringRef _Nonnull kLockdownSoftwareBehaviorKey;
    extern CFStringRef _Nonnull kLockdownSomebodySetTimeZoneKey;
    extern CFStringRef _Nonnull kLockdownTimeIntervalSince1970Key;
    extern CFStringRef _Nonnull kLockdownTimeZoneKey;
    extern CFStringRef _Nonnull kLockdownTimeZoneOffsetFromUTCKey;
    extern CFStringRef _Nonnull kLockdownTrustedHostAttachedKey;
    extern CFStringRef _Nonnull kLockdownUniqueChipIDKey;
    extern CFStringRef _Nonnull kLockdownUniqueDeviceIDKey;
    extern CFStringRef _Nonnull kLockdownUses24HourClockKey;
    extern CFStringRef _Nonnull kLockdownWifiAddressKey;
    extern CFStringRef _Nonnull kLockdowniTunesHasConnectedKey;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownActivationStateAcknowledgedKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownActivationPrivateKey;
    extern CFStringRef _Nonnull kLockdownActivationPublicKey;
    extern CFStringRef _Nonnull kLockdownCPUArchitectureKey;
    extern CFStringRef _Nonnull kLockdownHardwareModelKey;
    extern CFStringRef _Nonnull kLockdownMLBSerialNumberKey;
    extern CFStringRef _Nonnull kLockdownProductionSOCKey;
#endif
    
#pragma mark : (Unknown domain Keys)
    extern CFStringRef _Nullable kLockdownGetAR;
    extern CFStringRef _Nonnull kLockdownActivationInfoCompleteKey;
    extern CFStringRef _Nonnull kLockdownActivationInfoErrorsKey;
    extern CFStringRef _Nonnull kLockdownActivationTicketKey;
    extern CFStringRef _Nonnull kLockdownBasebandBootloaderVersionKey;
    extern CFStringRef _Nonnull kLockdownBasebandMasterKeyHashKey;
    extern CFStringRef _Nonnull kLockdownBasebandThumbprintKey;
    extern CFStringRef _Nullable kLockdownBasebandVersionKey;
    extern CFStringRef _Nonnull kLockdownBluetoothAddressKey;
    extern CFStringRef _Nonnull kLockdownCarrierBundleInfoKey;
    extern CFStringRef _Nonnull kLockdownICCIDKey;    // IntegratedCircuitCardIdentity
    extern CFStringRef _Nonnull kLockdownIMEIKey;    // InternationalMobileEquipmentIdentity
    extern CFStringRef _Nonnull kLockdownIMSIKey;    // InternationalMobileSubscriberIdentity
    extern CFStringRef _Nonnull kLockdownIsInternalKey;
    extern CFStringRef _Nonnull kLockdownPhoneNumberKey;
    extern CFStringRef _Nullable kLockdownDeviceHasExistingTicket;
    extern CFStringRef _Nonnull kLockdownProposedTicketKey;
    extern CFStringRef _Nonnull kLockdownReleaseTypeKey;
    extern CFStringRef _Nonnull kLockdownReservedBytesKey;
    extern CFStringRef _Nonnull kLockdownShutterClickKey;
    extern CFStringRef _Nonnull kLockdownUnlockCodeKey;
    extern CFStringRef _Nonnull kLockdownVolumeLimitKey;
    extern CFStringRef _Nonnull kLockdownWildcardTicketKey;
    extern CFStringRef _Nonnull kLockdownBatteryCurrentCapacity;
    extern CFStringRef _Nonnull kLockdownBatteryIsCharging;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownSupportsCarrierBundleInstallKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
    extern CFStringRef _Nonnull kLockdownExtendedLoggingPrefKey;
    extern CFStringRef _Nonnull kLockdownLogToDiskPrefKey;
#else
    extern CFStringRef _Nonnull kLockdownCaptureSyslogKey;
    extern CFStringRef _Nonnull kLockdownLogToDiskKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownAccessibilityLanguagesKey;
    extern CFStringRef _Nonnull kLockdownChinaBrickKey;
    extern CFStringRef _Nonnull kLockdownGoogleMailKey;
    extern CFStringRef _Nonnull kLockdownNTSCKey;
    extern CFStringRef _Nonnull kLockdownNVRAMKey;
    extern CFStringRef _Nonnull kLockdownNoWiFiKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
    extern CFStringRef _Nonnull kLockdownAMRKey;
    extern CFStringRef _Nonnull kLockdownH263Key;
    extern CFStringRef _Nonnull kLockdownH264HKey;
    extern CFStringRef _Nonnull kLockdownH264MKey;
    extern CFStringRef _Nonnull kLockdownSNUMKey;
    extern CFStringRef _Nonnull kLockdownServiceToken;
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0
    extern CFStringRef _Nonnull kLockdownEnableLockdownNetworkConnectKey;
#else
    extern CFStringRef _Nonnull kLockdownBackupVersionKey;
    extern CFStringRef _Nonnull kLockdownBuddyHostNameKey;
    extern CFStringRef _Nonnull kLockdownBuddyServiceNameKey;
    extern CFStringRef _Nonnull kLockdownBuddyServicePortKey;
    extern CFStringRef _Nonnull kLockdownCallsInProgressKey;
    extern CFStringRef _Nonnull kLockdownChapterImageSpecs;
    extern CFStringRef _Nonnull kLockdownCheckinHostIDkey;
    extern CFStringRef _Nonnull kLockdownCheckinVersionKey;
    extern CFStringRef _Nonnull kLockdownCurrentlyBrowsingKey;
    extern CFStringRef _Nonnull kLockdownDevToolsAvailableKey;
    extern CFStringRef _Nonnull kLockdownEscrowBagKey;
    extern CFStringRef _Nonnull kLockdownExternalChargeCapableKey;
    extern CFStringRef _Nonnull kLockdownExternalConnectedKey;
    extern CFStringRef _Nonnull kLockdownFullyChargedKey;
    extern CFStringRef _Nonnull kLockdownInternalKey;
    extern CFStringRef _Nonnull kLockdownMCCKey;
    extern CFStringRef _Nonnull kLockdownMNCKey;
    extern CFStringRef _Nonnull kLockdownMachineHackKey;
    extern CFStringRef _Nonnull kLockdownNoneKey;
    extern CFStringRef _Nonnull kLockdownPartitionTypeKey;
    extern CFStringRef _Nonnull kLockdownPluggedInKey;
    extern CFStringRef _Nonnull kLockdownSBLockedKey;
    extern CFStringRef _Nonnull kLockdownSortSectionsKey;
    extern CFStringRef _Nonnull kLockdownStandardKey;
    extern CFStringRef _Nonnull kLockdownSyncAllowedKey;
    extern CFStringRef _Nonnull kLockdownWakingBuddyKey;
    extern CFStringRef _Nonnull kLockdownWirelessBuddyFriendlyNameKey;
    extern CFStringRef _Nonnull kLockdownWirelessBuddyIDKey;
    extern CFStringRef _Nonnull kLockdownWirelessEchoServicePortNumberKey;
    extern CFStringRef _Nonnull kLockdownWirelessEnableWifiConnections;
    extern CFStringRef _Nonnull kLockdownWirelessSupportsWifi;
    extern CFStringRef _Nonnull kLockdownWokeBuddySincePluggedKey;
#endif
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED == __IPHONE_3_2
    extern CFStringRef _Nonnull kLockdownPlaylistFoldersSupportedKey;
#endif
    
    
#pragma mark : Disk Usage Domain Keys
    extern CFStringRef _Nonnull kLockdownAmountCameraAvailableKey;
    extern CFStringRef _Nonnull kLockdownAmountDataAvailableKey;
    extern CFStringRef _Nonnull kLockdownAmountDataReservedKey;
    extern CFStringRef _Nonnull kLockdownCalendarUsageKey;
    extern CFStringRef _Nonnull kLockdownCameraUsageKey;
    extern CFStringRef _Nonnull kLockdownMediaCacheUsageKey;
    extern CFStringRef _Nonnull kLockdownNANDInfoKey;
    extern CFStringRef _Nonnull kLockdownNotesUsageKey;
    extern CFStringRef _Nonnull kLockdownPhotoUsageKey;
    extern CFStringRef _Nonnull kLockdownTotalDataAvailableKey;
    extern CFStringRef _Nonnull kLockdownTotalDataCapacityKey;
    extern CFStringRef _Nonnull kLockdownTotalDiskCapacityKey;
    extern CFStringRef _Nonnull kLockdownTotalSystemAvailableKey;
    extern CFStringRef _Nonnull kLockdownTotalSystemCapacityKey;
    extern CFStringRef _Nonnull kLockdownVoicemailUsageKey;
    extern CFStringRef _Nonnull kLockdownWebAppCacheUsageKey;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownMobileApplicationUsageKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownAmountCameraUsageChangedKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_1
    extern CFStringRef _Nonnull kLockdownAmountCameraReservedKey;
    extern CFStringRef _Nonnull kLockdownAmountSongsReservedKey;
#endif

#pragma mark : Checkpoint Domain Keys

    extern CFStringRef _Nullable kLockdownCheckinClientNameKey;
    extern CFStringRef _Nullable kLockdownCheckinConnectionInfoKey;
    extern CFStringRef _Nullable kLockdownCheckinHostConnectionTypeKey;
    extern CFStringRef _Nullable kLockdownCheckinHostNameKey;
    extern CFStringRef _Nullable kLockdownCheckinPath;
    extern CFStringRef _Nullable kLockdownCheckinTimestamp;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownDBVersionKey;
    extern CFStringRef _Nonnull kLockdownFamilyIDKey;
    extern CFStringRef _Nonnull kLockdownMinimumiTunesVersionKey;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
    extern CFStringRef _Nonnull kLockdownAudioCodecsKey;
    extern CFStringRef _Nonnull kLockdownVideoCodecsKey;
#endif
    
#pragma mark : Debug Domain Keys
    extern CFStringRef _Nonnull kLockdownDebugDockPresentKey;
    extern CFStringRef _Nonnull kLockdownEnableVPNLogsKey;
    extern CFStringRef _Nonnull kLockdownRemoveWiFiManagerLogs;
    extern CFStringRef _Nonnull kLockdownEnable8021XLogsKey;
static const CFStringRef _Nonnull kLockdownStoreIdentityCookieKey = CFSTR("StoreIdentityCookie");
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_2
    extern CFStringRef _Nonnull kLockdownRemoveVPNLogs;
    extern CFStringRef _Nonnull kLockdownRemove8021XLogs;
    extern CFStringRef _Nonnull kLockdownEnableLockdownLogToDiskKey;
    extern CFStringRef _Nonnull kLockdownEnableLockdownExtendedLoggingKey;
    extern CFStringRef _Nonnull kLockdownRemoveLockdownLog;
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownEnableWiFiManagerLogsKey;
#endif
    

#pragma mark : FairPlay Domain Keys
    extern CFStringRef _Nonnull kLockdownFairPlayCBMaxVersionKey;
    extern CFStringRef _Nonnull kLockdownFairPlayCBMinVersionKey;
    extern CFStringRef _Nonnull kLockdownFairPlayCertificateKey;
    extern CFStringRef _Nonnull kLockdownFairPlayDeviceTypeKey;
    extern CFStringRef _Nonnull kLockdownColorSyncProfileKey;
    extern CFStringRef _Nonnull kLockdownFairPlayCertificateKey;
    extern CFStringRef _Nonnull kLockdownFairPlayGUIDKey;
    extern CFStringRef _Nonnull kLockdownFairPlayIDKey;
    extern CFStringRef _Nonnull kLockdownFairPlayContextIDKey;
    extern CFStringRef _Nonnull kLockdownFairPlayKeyDataKey;    // ?
    extern CFStringRef _Nonnull kLockdownRentalBagRequestKey;
    extern CFStringRef _Nonnull kLockdownRentalBagRequestVersionKey;
    extern CFStringRef _Nonnull kLockdownRentalBagResponseKey;
    extern CFStringRef _Nonnull kLockdownRentalCheckinAckRequestKey;
    extern CFStringRef _Nonnull kLockdownRentalCheckinAckResponseKey;    // ?
    extern CFStringRef _Nonnull kLockdownFairPlayRentalClockBias;

#pragma mark : International Domain Keys
    extern CFStringRef _Nonnull kLockdownKeyboardKey;    // CFString.
    extern CFStringRef _Nonnull kLockdownLanguageKey;    // CFString.
    extern CFStringRef _Nonnull kLockdownLocaleKey;    // CFString.
    extern CFStringRef _Nonnull kLockdownSupportedKeyboardsKey;
    extern CFStringRef _Nonnull kLockdownSupportedLanguagesKey;
    extern CFStringRef _Nonnull kLockdownSupportedLocalesKey;
    extern CFStringRef _Nonnull kLockdownSupportsAccessibilityKey;

#pragma mark : Restriction Domain Keys
    extern CFStringRef _Nonnull kLockdownProhibitAppInstallKey;
    
#pragma mark : Data Sync Domain Keys
    extern CFStringRef _Nonnull kLockdownSyncSupportsCalDAV;
    extern CFStringRef _Nonnull kLockdownDeviceHandlesDefaultCalendar;
    extern CFStringRef _Nonnull kLockdownSupportsEncryptedBackups;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
    extern CFStringRef _Nonnull kLockdownDeviceSupportsClearingDataKey;
#endif

#pragma mark : iTunes Keys
static const CFStringRef _Nonnull kLockdownLibraryApplicationsKey = CFSTR("LibraryApplications");
static const CFStringRef _Nonnull kLockdownSyncedApplicationsKey = CFSTR("SyncedApplications");

#pragma mark : itunesstored Keys
static const CFStringRef _Nonnull kLockdownSoftwareCUIDKey = CFSTR("SoftwareCUID");
    
    
#pragma mark : User Preferences Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_2_1
    extern CFStringRef _Nonnull kLockdownUserSetLanguageKey;
    extern CFStringRef _Nonnull kLockdownUserSetLocaleKey;    // ?
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownDiagnosticsAllowedKey;
#endif
    
#pragma mark : Backup Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownBackupWillEncrypt;    // ?
#endif
    
#pragma mark : Software Behavior Domain Keys
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownBehaviorsValidKey;
#endif
    
#pragma mark : Store Domain Keys
    static const CFStringRef _Nonnull kLockdownAccountKindKey = CFSTR("AccountKind");
    static const CFStringRef _Nonnull kLockdownAppleIDKey = CFSTR("AppleID");
    static const CFStringRef _Nonnull kLockdownCreditDisplayStringKey = CFSTR("CreditDisplayString");
    static const CFStringRef _Nonnull kLockdownKnownAccountsKey = CFSTR("KnownAccounts");
    static const CFStringRef _Nonnull kLockdownPreferHQTracksKey = CFSTR("PreferHQTracks");
    static const CFStringRef _Nonnull kLockdownPurchaseTypesKey = CFSTR("PurchaseTypes");
    static const CFStringRef _Nonnull kLockdownStorefrontKey = CFSTR("Storefront");
    static const CFStringRef _Nonnull kLockdownUserNameKey = CFSTR("UserName");
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_0
    extern CFStringRef _Nonnull kLockdownDSPersonIDKey;
#endif
    
#pragma mark : Internal Domain Keys
    extern CFStringRef _Nonnull kLockdownVoidWarrantyKey;
    
#pragma mark : Xcode Developer Domain Keys
    static const CFStringRef _Nonnull kLockdownDeveloperStatusKey = CFSTR("DeveloperStatus");
    
#pragma mark -
#pragma mark Functions
    typedef void* LockdownConnectionRef;
    
    typedef enum {
        kLockdownErrorSuccess,
        kLockdownErrorInvalidResponse,
        kLockdownErrorMissingKey,
        kLockdownErrorMissingValue,
        kLockdownErrorGetProhibited,
        kLockdownErrorSetProhibited,
        kLockdownErrorRemoveProhibited,
        kLockdownErrorImmutableValue,
        kLockdownErrorInvalidCheckin,
        kLockdownErrorCheckinTimeout
    } LockdownError;
        
extern CFSocketNativeHandle lockdown_checkin(void);
        
extern LockdownConnectionRef _Nonnull lockdown_connect(void);
extern void lockdown_disconnect(LockdownConnectionRef _Nonnull connection);
    
extern SecIdentityRef _Nullable lockdown_copy_identity(LockdownConnectionRef _Nonnull connection);
extern CFPropertyListRef _Nullable lockdown_copy_value(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable domain, CFStringRef _Nullable key);
extern LockdownError lockdown_remove_value(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable domain, CFStringRef _Nullable key);
extern LockdownError lockdown_set_value(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable domain, CFStringRef _Nullable key, CFPropertyListRef _Nullable newValue);

extern int lockdown_checkin_xpc(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable domain, CFTypeRef _Nullable arg2, CFTypeRef _Nullable arg3);
extern char lockdown_connection_is_proxy(void);
extern char lockdown_connection_is_usb(void);
extern char lockdown_connection_is_wifi(void);
extern CFDataRef _Nullable lockdown_copy_DPK(void);
extern CFStringRef _Nullable lockdown_copy_activationState(void);
extern CFStringRef _Nullable lockdown_copy_brickState(void);

extern CFStringRef _Nullable lockdown_copy_checkin_info(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable key);

extern CFDataRef _Nullable lockdown_copy_deviceCertificate(void);
extern SecIdentityRef _Nullable lockdown_copy_deviceIdentity(void);
extern CFDataRef _Nullable lockdown_copy_raptor(void);
extern CFStringRef _Nullable lockdown_copy_regulatoryvariant(void);
extern CFDataRef _Nullable lockdown_copy_ticket(void);
extern CFStringRef _Nullable lockdown_copy_ticket_status(void);
extern CFStringRef _Nullable lockdown_copy_trustedHostAttached(void);
extern CFTypeRef _Nullable lockdown_copy_wireless_connections_list(void);
extern LockdownError lockdown_delete_pair_records(void);
extern BOOL lockdown_enable_wireless_pairing(void);
extern size_t lockdown_get_buffered_read_size(LockdownConnectionRef _Nonnull connection, CFTypeRef _Nullable arg1);
extern int lockdown_get_securecontext(void);
extern CFSocketRef _Nullable lockdown_get_socket(void);

extern BOOL lockdown_is_host_trusted(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable domain, _Nullable CFTypeRef arg2);
extern LockdownError lockdown_kill_wireless_connections(void);
extern int lockdown_receive_message(LockdownConnectionRef _Nonnull connection);
extern void* _Nullable lockdown_recv(LockdownConnectionRef _Nonnull  connection, CFStringRef _Nullable domain, uint64_t key);
extern LockdownError lockdown_reset_pairing(void);
extern LockdownError lockdown_reset_pairing_internal(LockdownConnectionRef _Nonnull connection);
extern LockdownError lockdown_save_value(LockdownConnectionRef _Nonnull connection, CFStringRef _Nullable omain, CFStringRef _Nullable value, CFSocketRef  _Nullable * _Nullable socket); // value and socket might be in wrong order, need to test this command
extern uint64_t lockdown_send(LockdownConnectionRef _Nonnull connection);
extern LockdownError lockdown_send_message(LockdownConnectionRef _Nonnull connection);
extern LockdownError lockdown_set_fmipticket(LockdownConnectionRef _Nonnull connection);
extern int secure_lockdown_checkin(LockdownConnectionRef _Nonnull connection, _Nullable CFStringRef domain, CFStringRef _Nullable key);

//lockdown_wifi_debug_enabled
//lockdown_wifi_sync_enabled


#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
   
#endif
    
    /*
     dlfun("lockdown_connect", "^v");
     dlfun("lockdown_disconnect", "v^v");
     dlfun("lockdown_copy_value", "@^v@@");
     dlfun("lockdown_remove_value", "i^v@@");
     dlfun("lockdown_set_value", "i^v@@@");
     */
    
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_1
#pragma mark -
#pragma mark Lockdown Service functions
    typedef struct __LockdownService* LockdownServiceRef;
    
typedef void(*LockdownServiceCallback)(LockdownServiceRef _Nonnull service, CFSocketCallBackType cbType, void* _Nullable info);

    CFTypeID LockdownServiceGetTypeID(void);
    
CFSocketRef _Nullable LockdownServiceGetSocket(LockdownServiceRef _Nonnull service);
CFErrorRef _Nullable LockdownServiceGetError(LockdownServiceRef _Nonnull service);
void LockdownServiceSetError(LockdownServiceRef _Nonnull service, CFErrorRef _Nullable error);
bool LockdownServiceIsValid(LockdownServiceRef _Nonnull service);
void LockdownServiceInvalidate(LockdownServiceRef _Nonnull service);
bool _NullableLockdownServiceScheduleWithRunLoop(LockdownServiceRef _Nonnull service, CFRunLoopRef _Nullable runloop, CFStringRef _Nullable mode, CFErrorRef _Nullable * _Nullable pError);
LockdownServiceRef _Nonnull LockdownServiceCreate(CFAllocatorRef _Nullable allocator, LockdownServiceCallback _Nonnull callback, void * _Nullable  info, CFErrorRef _Nullable * _Nullable  pError);
void LockdownServiceSendMessage(LockdownServiceRef _Nonnull service, CFPropertyListRef _Nullable message, CFErrorRef _Nullable * _Nullable
                                pError);
#endif
    
#if __cplusplus
}
#endif

#endif
