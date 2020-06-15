#ifndef ROQMEDDSTOPICSSPLDCPS_H
#define ROQMEDDSTOPICSSPLDCPS_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "RoqmeDDSTopics.h"


extern c_metaObject __RoqmeDDSTopics_RoqmeDDSTopics__load (c_base base);

extern c_metaObject __RoqmeDDSTopics_intseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_intseq;

extern const char *RoqmeDDSTopics_RoqmeIntContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeIntContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeIntContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeIntContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeIntContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeIntContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeIntContext *from, struct _RoqmeDDSTopics_RoqmeIntContext *to);
extern  void __RoqmeDDSTopics_RoqmeIntContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeIntContext {
    c_string name;
    _RoqmeDDSTopics_intseq value;
};

extern c_metaObject __RoqmeDDSTopics_uintseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_uintseq;

extern const char *RoqmeDDSTopics_RoqmeUIntContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeUIntContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeUIntContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeUIntContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeUIntContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeUIntContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeUIntContext *from, struct _RoqmeDDSTopics_RoqmeUIntContext *to);
extern  void __RoqmeDDSTopics_RoqmeUIntContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeUIntContext {
    c_string name;
    _RoqmeDDSTopics_uintseq value;
};

extern c_metaObject __RoqmeDDSTopics_doubleseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_doubleseq;

extern const char *RoqmeDDSTopics_RoqmeDoubleContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeDoubleContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeDoubleContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeDoubleContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeDoubleContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeDoubleContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeDoubleContext *from, struct _RoqmeDDSTopics_RoqmeDoubleContext *to);
extern  void __RoqmeDDSTopics_RoqmeDoubleContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeDoubleContext {
    c_string name;
    _RoqmeDDSTopics_doubleseq value;
};

extern c_metaObject __RoqmeDDSTopics_boolseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_boolseq;

extern const char *RoqmeDDSTopics_RoqmeBoolContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeBoolContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeBoolContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeBoolContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeBoolContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeBoolContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeBoolContext *from, struct _RoqmeDDSTopics_RoqmeBoolContext *to);
extern  void __RoqmeDDSTopics_RoqmeBoolContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeBoolContext {
    c_string name;
    _RoqmeDDSTopics_boolseq value;
};

extern c_metaObject __RoqmeDDSTopics_eventseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_eventseq;

extern const char *RoqmeDDSTopics_RoqmeEventContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeEventContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeEventContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeEventContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeEventContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeEventContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeEventContext *from, struct _RoqmeDDSTopics_RoqmeEventContext *to);
extern  void __RoqmeDDSTopics_RoqmeEventContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeEventContext {
    c_string name;
    _RoqmeDDSTopics_eventseq value;
};

extern c_metaObject __RoqmeDDSTopics_enumseq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_enumseq;

extern const char *RoqmeDDSTopics_RoqmeEnumContext_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeEnumContext_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeEnumContext_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeEnumContext__load (c_base base);
struct _RoqmeDDSTopics_RoqmeEnumContext ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeEnumContext__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeEnumContext *from, struct _RoqmeDDSTopics_RoqmeEnumContext *to);
extern  void __RoqmeDDSTopics_RoqmeEnumContext__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeEnumContext {
    c_string name;
    _RoqmeDDSTopics_enumseq value;
};

extern const char *RoqmeDDSTopics_RoqmeObservation_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeObservation_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeObservation_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeObservation__load (c_base base);
struct _RoqmeDDSTopics_RoqmeObservation ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeObservation__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeObservation *from, struct _RoqmeDDSTopics_RoqmeObservation *to);
extern  void __RoqmeDDSTopics_RoqmeObservation__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeObservation {
    c_string name;
};

extern const char *RoqmeDDSTopics_RoqmeEstimate_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeEstimate_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeEstimate_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeEstimate__load (c_base base);
struct _RoqmeDDSTopics_RoqmeEstimate ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeEstimate__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeEstimate *from, struct _RoqmeDDSTopics_RoqmeEstimate *to);
extern  void __RoqmeDDSTopics_RoqmeEstimate__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeEstimate {
    c_string name;
    c_double value;
};

extern c_metaObject __RoqmeDDSTopics_id_seq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_id_seq;

extern c_metaObject __RoqmeDDSTopics_value_seq__load (c_base base);
typedef c_sequence _RoqmeDDSTopics_value_seq;

extern const char *RoqmeDDSTopics_RoqmeRanking_metaDescriptor[];
extern const c_ulong RoqmeDDSTopics_RoqmeRanking_metaDescriptorArrLength;
extern const c_ulong RoqmeDDSTopics_RoqmeRanking_metaDescriptorLength;
extern c_metaObject __RoqmeDDSTopics_RoqmeRanking__load (c_base base);
struct _RoqmeDDSTopics_RoqmeRanking ;
extern  v_copyin_result __RoqmeDDSTopics_RoqmeRanking__copyIn(c_type dbType, const class RoqmeDDSTopics::RoqmeRanking *from, struct _RoqmeDDSTopics_RoqmeRanking *to);
extern  void __RoqmeDDSTopics_RoqmeRanking__copyOut(const void *_from, void *_to);
struct _RoqmeDDSTopics_RoqmeRanking {
    c_string metricName;
    _RoqmeDDSTopics_id_seq ids;
    _RoqmeDDSTopics_value_seq values;
};

#undef OS_API
#endif
