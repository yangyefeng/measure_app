#include "rawdb_recorder.h"
static void display_list(TABLEINFO *tinfo)
{
    GSList *iterator = NULL;
    FIELDINFO* p;
    p=(FIELDINFO*)malloc(100);
    for (iterator = tinfo->list_fields; iterator; iterator = iterator->next) {
        printf("%s,%s,%s ",tinfo->DBNamePrefix,((FIELDINFO*)iterator->data)->fieldName,((FIELDINFO*)iterator->data)->fieldOriginalName);
    }
 //   printf("Tom's shoe size is '%d'\n", ((Person*)list->data)->shoe_size);
    printf("\n");
}

void RawDBRecorder_RecordRawHeader()
{

    TABLEINFO tinfo;

	tinfo.DBNamePrefix = STR_RAW_BD_NAME;

    FIELDINFO* tom = (FIELDINFO*)malloc(sizeof(FIELDINFO));
    tom->fieldName = STR_PACKET_ID;
    tom->fieldOriginalName = "包号";
	tom->dataType = DATATYPE_INTEGER;
    tinfo.list_fields = g_slist_append(tinfo.list_fields, tom);

	FIELDINFO* cinfo = g_new(FIELDINFO, 1);
    cinfo->fieldName = STR_PACKET_ID;
    cinfo->fieldOriginalName = "包号";
	cinfo->dataType = DATATYPE_INTEGER;
    tinfo.list_fields = g_slist_append(tinfo.list_fields, cinfo);



    FIELDINFO* c1info = g_new(FIELDINFO, 2);
	c1info->fieldName = STR_RECORD_TIME;
	c1info->fieldOriginalName ="包号包号";
	c1info->dataType = DATATYPE_REAL;
    tinfo.list_fields = g_slist_append(tinfo.list_fields, c1info);

    display_list(&tinfo);


}
void RawDBRecorder_initialize(void)
{

   RawDBRecorder_RecordRawHeader();

}
