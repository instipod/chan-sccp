/*!
 * \file        sccp_config.h
 * \brief       SCCP Config Header
 * \author      Marcello Ceschia <marcelloceschia [at] users.sourceforge.net>
 * \note        Reworked, but based on chan_sccp code.
 *              The original chan_sccp driver that was made by Zozo which itself was derived from the chan_skinny driver.
 *              Modified by Jan Czmok and Julien Goodwin
 * \note        This program is free software and may be modified and distributed under the terms of the GNU Public License.
 *              See the LICENSE file at the top of the source tree.
 * 
 * $Date: 2010-11-17 12:03:44 +0100 (Wed, 17 Nov 2010) $
 * $Revision: 2130 $  
 */
#ifndef __SCCP_CONFIG_H
#define __SCCP_CONFIG_H

/*!
 * \brief Enum for Config Value Change Status
 */
typedef enum {
	SCCP_CONFIG_CHANGE_NOCHANGE,
	SCCP_CONFIG_CHANGE_CHANGED,
	SCCP_CONFIG_CHANGE_INVALIDVALUE,
} sccp_value_changed_t;

/*!
 * \brief Enum for Config Option Blocks
 */
typedef enum {
	SCCP_CONFIG_GLOBAL_SEGMENT,
	SCCP_CONFIG_DEVICE_SEGMENT,
	SCCP_CONFIG_LINE_SEGMENT,
	SCCP_CONFIG_SOFTKEY_SEGMENT,
} sccp_config_segment_t;

void sccp_copy_defaultValue(const char *name, void *obj, const sccp_device_t * device, const sccp_config_segment_t segment);
int sccp_manager_config_metadata(struct mansession *s, const struct message *m);

/*!
 * \brief Soft Key Configuration Template Structure
 */
typedef struct {
	const char configVar[50];										/*!< Config Variable as Character */
	const int softkey;											/*!< Softkey as Int */
} softkeyConfigurationTemplate;											/*!< Soft Key Configuration Template Structure */

static const softkeyConfigurationTemplate softKeyTemplate[] = {
	/* *INDENT-OFF* */
	{"redial", 			SKINNY_LBL_REDIAL},
	{"newcall", 			SKINNY_LBL_NEWCALL},
	{"cfwdall", 			SKINNY_LBL_CFWDALL},
	{"cfwdbusy", 			SKINNY_LBL_CFWDBUSY},
	{"cfwdnoanswer",		SKINNY_LBL_CFWDNOANSWER},
	{"pickup", 			SKINNY_LBL_PICKUP},
	{"gpickup", 			SKINNY_LBL_GPICKUP},
	{"conflist", 			SKINNY_LBL_CONFLIST},
	{"dnd", 			SKINNY_LBL_DND},
	{"hold", 			SKINNY_LBL_HOLD},
	{"endcall", 			SKINNY_LBL_ENDCALL},
	{"park", 			SKINNY_LBL_PARK},
	{"select", 			SKINNY_LBL_SELECT},
	{"idivert", 			SKINNY_LBL_IDIVERT},
	{"resume", 			SKINNY_LBL_RESUME},
	{"newcall", 			SKINNY_LBL_NEWCALL},
	{"transfer", 			SKINNY_LBL_TRANSFER},
	{"dirtrfr", 			SKINNY_LBL_DIRTRFR},
	{"answer", 			SKINNY_LBL_ANSWER},
	{"transvm", 			SKINNY_LBL_TRNSFVM},
	{"private", 			SKINNY_LBL_PRIVATE},
	{"meetme", 			SKINNY_LBL_MEETME},
	{"barge", 			SKINNY_LBL_BARGE},
	{"cbarge", 			SKINNY_LBL_CBARGE},
	{"conf", 			SKINNY_LBL_CONFRN},
	{"confrn",			SKINNY_LBL_CONFRN},
	{"back", 			SKINNY_LBL_BACKSPACE},
	{"join", 			SKINNY_LBL_JOIN},
	{"intrcpt", 			SKINNY_LBL_INTRCPT},
	{"monitor", 			SKINNY_LBL_MONITOR},  
	{"dial", 			SKINNY_LBL_DIAL},
	{"vidmode", 			SKINNY_LBL_VIDEO_MODE},
	{"empty", 			SKINNY_LBL_EMPTY},
	{"callback", 			SKINNY_LBL_CALLBACK},
	/* *INDENT-ON* */
};

void sccp_config_cleanup_dynamically_allocated_memory(void *obj, const sccp_config_segment_t segment);
sccp_value_changed_t sccp_config_addButton(void *buttonconfig_head, int index, sccp_config_buttontype_t type, const char *name, const char *options, const char *args);
boolean_t sccp_config_general(sccp_readingtype_t readingtype);
void cleanup_stale_contexts(char *newContext, char *oldContext);
void sccp_config_readDevicesLines(sccp_readingtype_t readingtype);
int sccp_manager_config_metadata(struct mansession *s, const struct message *m);

/*!
 * \brief Enum for Config File Status (Return Values)
 */
typedef enum {
	/* *INDENT-OFF* */
	CONFIG_STATUS_FILE_NOT_CHANGED 	= -1,
	CONFIG_STATUS_FILE_OK 		= 0,
	CONFIG_STATUS_FILE_OLD 		= 1,
	CONFIG_STATUS_FILE_NOT_SCCP 	= 2,
	CONFIG_STATUS_FILE_NOT_FOUND 	= 3,
	CONFIG_STATUS_FILE_INVALID 	= 5,
	/* *INDENT-ON* */
} sccp_config_file_status_t;

sccp_config_file_status_t sccp_config_getConfig(boolean_t force);
sccp_configurationchange_t sccp_config_applyGlobalConfiguration(PBX_VARIABLE_TYPE * v);
sccp_configurationchange_t sccp_config_applyLineConfiguration(sccp_line_t * l, PBX_VARIABLE_TYPE * v);
sccp_configurationchange_t sccp_config_applyDeviceConfiguration(sccp_device_t * d, PBX_VARIABLE_TYPE * v);
sccp_configurationchange_t sccp_config_applyDeviceDefaults(sccp_device_t * device, PBX_VARIABLE_TYPE * variable);

void sccp_config_softKeySet(PBX_VARIABLE_TYPE * variable, const char *name);
uint8_t sccp_config_readSoftSet(uint8_t * softkeyset, const char *data);
int sccp_config_getSoftkeyLbl(char *key);
void sccp_config_restoreDeviceFeatureStatus(sccp_device_t * device);

int sccp_config_generate(char *filename, int configType);

#endif	       /*__SCCP_CONFIG_H */
// kate: indent-width 8; replace-tabs off; indent-mode cstyle; auto-insert-doxygen on; line-numbers on; tab-indents on; keep-extra-spaces off; auto-brackets off;
