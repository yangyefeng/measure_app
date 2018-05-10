#ifndef RAWDB_RECORDER_H
#define RAWDB_RECORDER_H
#include <glib.h>

#define STR_RAW_BD_NAME "raw_record"   //原始数据数据库名
#define STR_PRODUCT_BD_NAME "product"  //生产数据数据库名
#define STR_DETAIL_BD_NAME "detail"    //过程数据数据库名
#define STR_PACKET_ID  "packet_id"     //包号的列名称
#define STR_MIX_ID  "mix_id"           //盘号的列名称
#define STR_REAL_SENSOR_ID "real_sonsorid"     //秤对应sensorid的列名称
#define STR_START_TIME "start_time"    //过程数据开始时间的列名称
#define STR_END_TIME "end_time"        //过程数据结束时间的列名称

#define STR_ILLEGAL "illegall"         //违规标识的列名称
#define STR_DRY_MIX_TIME "drytime"     //干拌时长
#define STR_WET_MIX_TIME "wettime"     //湿拌时长
#define STR_MIX_TIME "mixtime"         //拌合时长
#define STR_RECORD_TIME "timestamp"    //记录时间
typedef enum
{
	DATATYPE_UNKNOWN,
	DATATYPE_INTEGER,
	DATATYPE_NUMERIC,
	DATATYPE_FLOAT,
	DATATYPE_REAL,
	DATATYPE_CHAR,
	DATATYPE_TEXT,
	DATATYPE_BOOLEAN,
	DATATYPE_DATETIME,
	DATATYPE_TIMESTAMP,
	DATATYPE_BLOB
}FieldDataType;
typedef struct FieldInfo
{
	char* fieldName;
	FieldDataType dataType;
	char *fieldOriginalName;

}FIELDINFO, *PFIELDINFO;

typedef struct ConfigInfo
{
	char * DBConfigPath;
	GString * ConfigTimeStamp;
}CONFIGINFO, *PCONFIGINFO;
typedef struct DBInfo
{
	char* DBNamePrefix;
	CONFIGINFO configInfo;
	GSList *list_fields;
}TABLEINFO, *PTABLEINF;
void RawDBRecorder_initialize(void);
#endif
